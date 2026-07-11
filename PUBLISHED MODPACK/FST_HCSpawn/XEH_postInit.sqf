// FST_HCSpawn -- postInit
// Server: init HC system
// HC: register with server
// Client: hook Zeus, register keybinds

if (!isMultiplayer) exitWith {
    diag_log "[FST_HCSpawn] Singleplayer -- HC system disabled";
};

if (!FST_HC_Enabled) exitWith {
    diag_log "[FST_HCSpawn] HC system disabled via CBA setting";
};

diag_log "[FST_HCSpawn] postInit starting - HANDOFF_V26R2_STABILITY_MERGE_DYNSIM_OFF_STANCE_FIX_FG_SOFTCAP_2026-07-04";

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
    [{
        ["FST_HC_evt_registerHC", [player, clientOwner]] call CBA_fnc_serverEvent;
        diag_log format ["[FST_HCSpawn] HC registering -- owner %1", clientOwner];
    }, [], 1 + random 2] call CBA_fnc_waitAndExecute;
};

// ============================================================
// SERVER / HEADLESS CLIENT DIAGNOSTICS
// ============================================================
if (isServer || {!hasInterface}) then {
    [] call FST_HCSpawn_fnc_initExplosionDiag;
    [] call FST_HCSpawn_fnc_initEmergencyDroidBandaid;

    // Droid stance keeper. Must run on the server AND every HC: setUnitPos is an
    // arguments-local command, so it only affects units local to the executing
    // machine. A server-only stance script (standalone FST_DroidStance.pbo)
    // silently stops covering droids once their groups move to an HC -- which is
    // why B1s stopped standing upright whenever HCs were connected. The function
    // itself filters on local/alive/side/class, so double coverage with the
    // standalone PBO on server-local units is harmless (setUnitPos is idempotent).
    if (missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) then {
        [{
            [] call FST_HCSpawn_fnc_enforceDroidStance;
        }, missionNamespace getVariable ["FST_HC_DroidStanceInterval", 10], []] call CBA_fnc_addPerFrameHandler;
    };
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
    [{
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
    }, 30, []] call CBA_fnc_addPerFrameHandler;

    // Register ZEN modules (requires ZEN -- Zeus Enhanced)
    if (!isNil "zen_custom_modules_fnc_register") then {
        [] call FST_HCSpawn_fnc_registerZenModules;
    } else {
        diag_log "[FST_HCSpawn] ZEN not detected -- spawn modules not registered";
        systemChat "[FST] ZEN not loaded -- spawn modules unavailable";
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

    // Keybind: HC Status Report (Shift+F4)
    ["FST_HCSpawn", "StatusReport", ["HC Status Report", "Print HC unit counts and status to chat"],
        {
            [] call FST_HCSpawn_fnc_statusReport;
        }, {}, [0x3E, [true, false, false]]
    ] call CBA_fnc_addKeybind;
};
