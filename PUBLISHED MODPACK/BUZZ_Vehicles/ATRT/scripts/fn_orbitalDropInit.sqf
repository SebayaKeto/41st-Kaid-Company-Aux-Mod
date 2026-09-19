// =============================================================================
//  BUZZ AT-RT — fn_orbitalDropInit.sqf
//  postInit. Registers the Zeus module "[BUZZ] AT-RT Orbital Drop" (needs ZEN).
// =============================================================================
if (!hasInterface) exitWith {};

if (isNil "zen_custom_modules_fnc_register") exitWith {
    diag_log "[BUZZ] ZEN not loaded - AT-RT Orbital Drop module not registered.";
};

["[BUZZ] AT-RT Orbital Drop", "Deploy AT-RT Crates",
    {
        params [["_pos", [0, 0, 0], [[]], 3], ["_logic", objNull, [objNull]]];

        ["Deploy AT-RT Crates", [
            ["SLIDER", ["Crate Amount", "How many AT-RT crates will be dropped."], [1, 8, 4, 0]],
            ["SLIDER", ["Drop Height", "Height in metres above ground the crates are released from."], [500, 3000, 1000, 0]],
            ["SLIDER", ["Chute Height", "Height in metres above ground where the parachutes deploy."], [100, 1000, 100, 0]]
        ], {
            params ["_values", "_arguments"];
            _arguments params ["_pos"];

            [_pos, _values # 0, _values # 1, _values # 2] remoteExecCall ["BUZZ_fnc_orbitalDropServer", 2];
        }, {}, [_pos, _logic]] call zen_dialog_fnc_create;
    },
    ""
] call zen_custom_modules_fnc_register;
