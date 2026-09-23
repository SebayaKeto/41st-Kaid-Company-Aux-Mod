// FST_HCSpawn -- postInit
// Server: init HC system
// HC: register with server
// Client: hook Zeus, register keybinds

[] call FST_HCSpawn_fnc_registerBurnsEvents;
[] call FST_HCSpawn_fnc_initCombatTasks;
if (hasInterface) then {
    [] call FST_HCSpawn_fnc_registerBurnsModules;
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
private _startStanceKeeper = {
    if (hasInterface && {!isServer}) exitWith {};
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
                [_curator, _group] call FST_HCSpawn_fnc_interceptZeusPlace;
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
