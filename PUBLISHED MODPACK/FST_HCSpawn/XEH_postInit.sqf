// FST_HCSpawn — postInit
// Server: init HC system
// HC: register with server
// Client: hook Zeus, register keybinds

if (!isMultiplayer) exitWith {
    diag_log "[FST_HCSpawn] Singleplayer — HC system disabled";
};

if (!FST_HC_Enabled) exitWith {
    diag_log "[FST_HCSpawn] HC system disabled via CBA setting";
};

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
    [{
        [player, clientOwner] remoteExecCall ["FST_HCSpawn_fnc_registerHC", 2];
        // FPS monitor started by server via setHCIndex after registration
        diag_log format ["[FST_HCSpawn] HC registering — owner %1", clientOwner];
    }, [], 1 + random 2] call CBA_fnc_waitAndExecute;
};

// ============================================================
// CLIENT (Zeus)
// ============================================================
if (hasInterface) then {

    // Hook CuratorGroupPlaced for Zeus intercept
    {
        _x addEventHandler ["CuratorGroupPlaced", {
            params ["_curator", "_group"];
            [_curator, _group] call FST_HCSpawn_fnc_interceptZeusPlace;
        }];
    } forEach allCurators;

    // Catch curators assigned mid-mission (periodic check — CuratorAssigned isn't a standard event)
    [{
        {
            if !(_x getVariable ["FST_HC_hooked", false]) then {
                _x addEventHandler ["CuratorGroupPlaced", {
                    params ["_curator", "_group"];
                    [_curator, _group] call FST_HCSpawn_fnc_interceptZeusPlace;
                }];
                _x setVariable ["FST_HC_hooked", true];
            };
        } forEach allCurators;
    }, 30, []] call CBA_fnc_addPerFrameHandler;

    // Register ZEN modules (requires ZEN — Zeus Enhanced)
    if (!isNil "zen_custom_modules_fnc_register") then {
        [] call FST_HCSpawn_fnc_registerZenModules;
    } else {
        diag_log "[FST_HCSpawn] ZEN not detected — spawn modules not registered";
        systemChat "[FST] ZEN not loaded — spawn modules unavailable";
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
            [] call FST_HCSpawn_fnc_debugToggle;
        }, {}, [0x3D, [true, false, false]]
    ] call CBA_fnc_addKeybind;

    // Keybind: HC Status Report (Shift+F4)
    ["FST_HCSpawn", "StatusReport", ["HC Status Report", "Print HC unit counts and status to chat"],
        {
            [] call FST_HCSpawn_fnc_statusReport;
        }, {}, [0x3E, [true, false, false]]
    ] call CBA_fnc_addKeybind;
};
