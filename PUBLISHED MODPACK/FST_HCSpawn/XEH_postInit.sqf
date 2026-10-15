// FST_HCSpawn -- postInit
// Server: init HC system
// HC: register with server
// Client: hook Zeus, register keybinds

[] call FST_HCSpawn_fnc_initPerformance;
[] call FST_HCSpawn_fnc_registerBurnsEvents;
[] call FST_HCSpawn_fnc_initCombatTasks;
[] call FST_HCSpawn_fnc_burnsInitBXEnhancements;
// B2s always walk, never run (Miran 3 Oct). Applied where the unit is local, and again
// whenever it changes owner (HC transfer / Zeus clone).
["WBK_LS_B2","InitPost",{
    params ["_u"];
    if (local _u) then {_u forceWalk true};
    // New owner: walk, and undo any move-fire state the old owner left on (its rhythm PFH died with it).
    _u addEventHandler ["Local",{params ["_u","_isLocal"];if (_isLocal) then {_u forceWalk true;if (isNil {group _u getVariable "BURNS_b2MovePFH"}) then {_u enableAI "TARGET";_u enableAI "AUTOTARGET";_u enableAI "AUTOCOMBAT"}}}];
},true,[],true] call CBA_fnc_addClassEventHandler;
if (hasInterface) then {
    [] call FST_HCSpawn_fnc_registerBurnsModules;
    // ACE UI re-apply (Miran 11 Oct RS op: LAAT / LAAT-C / Saber pilots lost the radar and the current-mag ammo count). ACE UI sets its
    // elements only when a HUD display loads, and treats the player as on foot while CBA_fnc_canUseWeapon is true; the get-in animation can
    // still count as on foot at that moment and nothing re-applies once the seat animation takes over. Re-run ACE's own steps 1, 3 and 6 s
    // after every vehicle / seat change. Kill switch: missionNamespace FST_aceUiReapply = false.
    if (isClass (configFile >> "CfgPatches" >> "ace_ui")) then {
        FST_HCSpawn_fnc_aceUiReapply = {
            if (!(missionNamespace getVariable ["FST_aceUiReapply", true]) || {isNil "ace_ui_configCache"} || {isNil "ace_ui_fnc_setAdvancedElement"}) exitWith {};
            private _force = !(missionNamespace getVariable ["ace_ui_allowSelectiveUI", true]);
            { [_x, missionNamespace getVariable [format ["ace_ui_%1", _x], true], false, _force] call ace_ui_fnc_setAdvancedElement } forEach (keys ace_ui_configCache);
            [false] call ace_ui_fnc_setElements;
        };
        private _reapply = { [] spawn { { sleep _x; call FST_HCSpawn_fnc_aceUiReapply } forEach [1, 2, 3] } };
        ["vehicle", _reapply] call CBA_fnc_addPlayerEventHandler;
        ["turret", _reapply] call CBA_fnc_addPlayerEventHandler;
    };
    // Zeus camera as an observer (Miran 10 Oct: squads Zeused far from any player body walked in "jerking a lot and not
    // firing in volleys" - the drill/pace range gate counted player bodies only). Every 2 s while the curator screen is
    // open the camera position rides on the player object (sent only after it moves 25 m); servers/HCs add it to
    // BURNS_PlayerPositions (fn_initCombatTasks).
    [{
        if (isNull player) exitWith {};
        if (!isNull (findDisplay 312) && {!isNull curatorCamera}) then {
            private _p=getPosWorld curatorCamera;
            private _old=player getVariable ["BURNS_zeusCam",[]];
            if (count _old!=3 || {_old distance2D _p>25}) then {player setVariable ["BURNS_zeusCam",_p,true]};
        } else {
            if (!isNil {player getVariable "BURNS_zeusCam"}) then {player setVariable ["BURNS_zeusCam",nil,true]};
        };
    },2] call CBA_fnc_addPerFrameHandler;
    // Keep native right-click waypoint placement when AI is selected.
    // BURNS actions stay registered in ZEN; do not make its menu consume move orders.
    private _enableSquadMenu={
        if (!isNil "zen_context_menu_fnc_open") then {
            zen_context_menu_enabled=2;
            zen_context_menu_overrideWaypoints=false;
        };
    };
    call _enableSquadMenu;
    ["CBA_settingsInitialized",_enableSquadMenu] call CBA_fnc_addEventHandler;
};

// Droid stance keeper. Must run on the server AND every HC: setUnitPos is an
// arguments-local command, so it only affects units local to the executing
// machine. This is the only stance system in the modpack (FST_DroidStance
// was retired and folded into this addon), so it also has to run in
// singleplayer / editor preview, where the rest of the HC system stays off.
// The function filters on local/alive/side/class itself.
// V54 B2 guard (Miran 12 Oct: "BURNS should never allow B2s to go prone"). Runs on EVERY machine: server, HCs and clients
// (Zeus-placed AI stay local to the Zeus client until transferred). B2 prone sources: WebKnight's B1/BX grenade warning sets every
// man within 15 m to "DOWN" for 7 s; B2 classes WebKnight does not load sit at unitPos AUTO and the engine drops them prone.
// Spawn/transfer: CBA class EH InitPost + Local. Each frame: the local B2 list goes back to "UP" before a prone animation starts.
// Backstops: AnimChanged hook + the keeper below. Kill switch: FST_HC_B2NoProne = false. BX commandos are not B2: untouched.
if (isNil "BURNS_fnc_isB2") then {
    BURNS_fnc_isB2 = {
        params ["_u"];
        if (isNull _u || {!(_u isKindOf "CAManBase")}) exitWith {false};
        private _cache = missionNamespace getVariable "BURNS_b2Cache";
        if (isNil "_cache") then {_cache = createHashMap; missionNamespace setVariable ["BURNS_b2Cache", _cache]};
        private _class = typeOf _u;
        private _r = _cache getOrDefault [_class, 0];
        if (_r isEqualType true) exitWith {_r};
        _r = _u isKindOf "WBK_LS_B2_Baseclass";
        private _cfg = configOf _u;
        while {!_r && {isClass _cfg}} do {
            if ((((toLowerANSI configName _cfg) splitString "_") findIf {(_x find "b2") == 0}) >= 0) then {_r = true};
            _cfg = inheritsFrom _cfg;
        };
        _cache set [_class, _r];
        _r
    };
    BURNS_fnc_b2Up = {
        params ["_u"];
        if (!local _u || {!alive _u} || {vehicle _u != _u} || {lifeState _u == "INCAPACITATED"} || {isPlayer _u}) exitWith {false};
        if (toUpper unitPos _u == "UP") exitWith {false};
        _u setUnitPos "UP";
        _u setUnitPosWeak "UP";
        true
    };
    BURNS_fnc_b2Track = {
        params ["_u"];
        if (!(missionNamespace getVariable ["FST_HC_B2NoProne", true]) || {!local _u} || {!([_u] call BURNS_fnc_isB2)}) exitWith {};
        [_u] call BURNS_fnc_b2Up;
        private _list = missionNamespace getVariable ["BURNS_b2Local", []];
        if !(_u in _list) then {_list pushBack _u; missionNamespace setVariable ["BURNS_b2Local", _list]};
    };
};
if !(missionNamespace getVariable ["BURNS_b2GuardStarted", false]) then {
    missionNamespace setVariable ["BURNS_b2GuardStarted", true];
    ["CAManBase", "InitPost", {[_this select 0] call BURNS_fnc_b2Track}, true, [], true] call CBA_fnc_addClassEventHandler;
    ["CAManBase", "Local", {params ["_u", "_isLocal"]; if (_isLocal) then {[_u] call BURNS_fnc_b2Track}}] call CBA_fnc_addClassEventHandler;
    [{
        if !(missionNamespace getVariable ["FST_HC_B2NoProne", true]) exitWith {};
        {
            if (toUpper unitPos _x != "UP") then {[_x] call BURNS_fnc_b2Up};
        } forEach (missionNamespace getVariable ["BURNS_b2Local", []]);
    }, 0, []] call CBA_fnc_addPerFrameHandler;
};

private _startStanceKeeper = {
    // Clients run only the B2 pass (their Zeus-local AI); B1 upkeep stays on the server and HCs.
    if (hasInterface && {!isServer}) exitWith {
        if !(missionNamespace getVariable ["BURNS_stanceKeeperStarted", false]) then {
            missionNamespace setVariable ["BURNS_stanceKeeperStarted", true];
            [{
                [true] call FST_HCSpawn_fnc_enforceDroidStance;
            }, missionNamespace getVariable ["FST_HC_DroidStanceInterval", 10], []] call CBA_fnc_addPerFrameHandler;
        };
    };
    if !(missionNamespace getVariable ["BURNS_stanceKeeperStarted", false]) then {
        missionNamespace setVariable ["BURNS_stanceKeeperStarted", true];
        [{
            [] call FST_HCSpawn_fnc_enforceDroidStance;
        }, missionNamespace getVariable ["FST_HC_DroidStanceInterval", 10], []] call CBA_fnc_addPerFrameHandler;
    };
};
call _startStanceKeeper;

if (!isMultiplayer) exitWith {
    diag_log "[FST_HCSpawn] Singleplayer -- HC system disabled (droid stance keeper still active)";
    call _startStanceKeeper;
};

if (!FST_HC_Enabled) exitWith {
    diag_log "[FST_HCSpawn] HC system disabled via CBA setting";
};

diag_log "[FST_HCSpawn] postInit starting - V30_3_MOVEMENT_PREVIEW_2026-09-22";

// Register CBA events on all machines before any other init
[] call FST_HCSpawn_fnc_registerEvents;

// ============================================================
// SERVER
// ============================================================
if (isServer) then {
    [] call FST_HCSpawn_fnc_initHCSystem;

    // Server FPS monitor marker
    ["Server", 10, 0] call FST_HCSpawn_fnc_fpsMonitor;
};

// ============================================================
// HEADLESS CLIENT
// ============================================================
if (!isServer && !hasInterface) then {
    missionNamespace setVariable ["FST_HC_LastDeadGroupCleanup", time];

    // V27: register once the HC's player entity actually exists instead of a
    // blind 1-3s delay. registerHC rejects a null object and never retried, so a
    // slow-loading HC could silently stay unregistered for the whole op.
    private _register = {
        ["FST_HC_evt_registerHC", [player, clientOwner]] call CBA_fnc_serverEvent;
        diag_log format ["[FST_HCSpawn] HC registering -- owner %1", clientOwner];
    };
    [
        { !isNull player },
        { params ["_fnc"]; call _fnc; },
        [_register],
        30,
        { diag_log "[FST_HCSpawn] HC player entity still null after 30s; registration will rely on the periodic re-register."; }
    ] call CBA_fnc_waitUntilAndExecute;

    // Periodic self-check: the server publishes FST_HC_Ids to every machine. If
    // this HC is not in it (lost registration, server-side reset, dropped event),
    // re-register. Cheap: one array lookup per minute.
    // A CBA PFH runs its first tick on the frame it is added, which raced the
    // primary registration above and double-registered the HC (smoke test
    // 2026-09-20). Arm the check 60s after postInit instead.
    [{
        [{
            if (isNull player) exitWith {};
            if (clientOwner in (missionNamespace getVariable ["FST_HC_Ids", []])) exitWith {};
            ["FST_HC_evt_registerHC", [player, clientOwner]] call CBA_fnc_serverEvent;
            diag_log format ["[FST_HCSpawn] HC re-registering -- owner %1 not present in FST_HC_Ids", clientOwner];
        }, 60, []] call CBA_fnc_addPerFrameHandler;
    }, [], 60] call CBA_fnc_waitAndExecute;
};

// ============================================================
// SERVER / HEADLESS CLIENT DIAGNOSTICS
// ============================================================
if (isServer || {!hasInterface}) then {
    [] call FST_HCSpawn_fnc_initExplosionDiag;
    [] call FST_HCSpawn_fnc_initEmergencyDroidBandaid;
    [] call FST_HCSpawn_fnc_initDroidCorpseCleanup;

    // Droid stance keeper (see _startStanceKeeper at the top of this file).
    call _startStanceKeeper;
};

// ============================================================
// CLIENT (Zeus)
// ============================================================
if (hasInterface) then {

    // Hook only the curator assigned to the local player. The old allCurators loop
    // was safe in many cases, but in multi-Zeus ops it risked duplicate local EHs
    // or clients trying to react to another Zeus's placement. Each Zeus client only
    // needs to intercept its own curator logic.
    private _hookLocalCurator = {
        private _curator = getAssignedCuratorLogic player;
        if (isNull _curator) exitWith {};
        if !(_curator getVariable ["FST_HC_hookedLocal", false]) then {
            _curator addEventHandler ["CuratorGroupPlaced", {
                params ["_curator", "_group"];
                private _heavy=(units _group) select {([typeOf _x] call FST_HCSpawn_fnc_heavyKind)>=0};
                if (_heavy isEqualTo []) then {
                    [_curator, _group] call FST_HCSpawn_fnc_interceptZeusPlace;
                } else {
                    ["FST_heavyZeus",[_heavy,clientOwner]] call CBA_fnc_serverEvent;
                    // Preserve heavy object identity: never clone a live creature
                    // with a scheduled controller. Catch-all transfers survivors.
                };
            }];
            _curator addEventHandler ["CuratorObjectPlaced", {
                params ["_curator","_object"];
                if (([typeOf _object] call FST_HCSpawn_fnc_heavyKind)>=0) then {
                    ["FST_heavyZeus",[[_object],clientOwner]] call CBA_fnc_serverEvent;
                };
            }];
            _curator setVariable ["FST_HC_hookedLocal", true];
            if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
                diag_log format ["[FST_HCSpawn] Hooked local curator %1 for player %2", _curator, player];
            };
        };
    };
    call _hookLocalCurator;

    // Catch curators assigned mid-mission (periodic check -- CuratorAssigned isn't a standard event)
    [_hookLocalCurator, 30, []] call CBA_fnc_addPerFrameHandler;

    // Register ZEN modules (requires ZEN -- Zeus Enhanced)
    if (!isNil "zen_dialog_fnc_create") then {
        [] call FST_HCSpawn_fnc_registerZenModules;
    } else {
        diag_log "[FST_HCSpawn] ZEN not detected -- spawn modules not registered";
        systemChat "[FST] ZEN not loaded -- spawn modules unavailable";
    };

    private _isAdminOrZeus = {
        (serverCommandAvailable "#kick") || {!isNull (getAssignedCuratorLogic player)}
    };

    // Keybind: Zeus Hold/Release (Shift+F2)
    ["FST_HCSpawn", "ZeusHold", ["Zeus Hold/Release", "Toggle selected groups between Zeus and HC"],
        {
            if (isNull (getAssignedCuratorLogic player)) exitWith {};
            [] call FST_HCSpawn_fnc_zeusHold;
        }, {}, [0x3C, [true, false, false]]
    ] call CBA_fnc_addKeybind;

    // Keybind: Debug Draw Toggle (Shift+F3)
    ["FST_HCSpawn", "DebugToggle", ["Debug Draw Toggle", "Show/hide HC ownership icons above AI"],
        {
            private _isAdmin = serverCommandAvailable "#kick";
            private _isZeus = !isNull (getAssignedCuratorLogic player);
            if (!_isAdmin && !_isZeus) exitWith { systemChat "[FST] Debug: admin or Zeus only."; };
            private _current = missionNamespace getVariable ["FST_HC_Debugging", false];
            [!_current] call FST_HCSpawn_fnc_debugDraw;
        }, {}, [0x3D, [true, false, false]]
    ] call CBA_fnc_addKeybind;

    // Keybind: HC Status Report (Shift+F4). V27: admin/Zeus only -- each report
    // costs the server a recount plus a full allGroups pass.
    ["FST_HCSpawn", "StatusReport", ["HC Status Report", "Print HC unit counts and status to chat"],
        {
            private _isAdmin = serverCommandAvailable "#kick";
            private _isZeus = !isNull (getAssignedCuratorLogic player);
            if (!_isAdmin && !_isZeus) exitWith { systemChat "[FST] Status report: admin or Zeus only."; };
            [] call FST_HCSpawn_fnc_statusReport;
        }, {}, [0x3E, [true, false, false]]
    ] call CBA_fnc_addKeybind;
};
