// FST_HCSpawn_fnc_registerZenModules
// Client-side. Registers ZEN custom modules for all templates + fill garrison.
// Called from postInit if ZEN is loaded.

if (!hasInterface) exitWith {};

// ============================================================
// TEMPLATE MODULES — one per template under "FST Spawn"
// ============================================================
{
    private _key = _x;
    private _data = _y;
    _data params ["_side", "_unitClasses", "_desc"];

    // compile format bakes _key and _desc into the code string
    // so they survive the forEach scope into the deferred ZEN callback
    private _code = compile format [
        '
        params ["_pos"];
        ["%1",
        [
            ["COMBO", "Behavior", [[0,1,2,3], ["Garrison","Patrol","Static","No Behavior"], 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos", "_key"];
            private _behavior = ["garrison","patrol","static","none"] select (_values select 0);
            [_pos, _key, _behavior, -1] remoteExecCall ["FST_HCSpawn_fnc_quickSpawnAtPos", 2];
            systemChat format ["[FST] Spawning %%1 (%%2)", _key, _behavior];
        },
        {},
        [_pos, "%2"]
        ] call zen_dialog_fnc_create;
        ',
        _desc, _key
    ];

    ["41st Kaid Modules", _desc, _code, "\a3\Modules_F_Curator\Data\iconManual_ca.paa"]
        call zen_custom_modules_fnc_register;

} forEach FST_HC_Templates;

// ============================================================
// FILL GARRISON MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- Fill Garrison ---",
    {
        params ["_pos"];

        ["Fill Garrison",
        [
            ["SLIDER", "Scan Radius (m)", [25, 500, 150, 0]],
            ["SLIDER", "Density %", [10, 100, 75, 0]],
            ["SLIDER", "B2 Mix %", [0, 100, 20, 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            private _radius = _values select 0;
            private _density = (_values select 1) / 100;
            private _b2Ratio = (_values select 2) / 100;

            [_pos, _radius, _density, _b2Ratio] remoteExecCall ["FST_HCSpawn_fnc_requestFillGarrison", 2];
            systemChat format ["[FST] Filling — %1m, %2%3 density, %4%5 B2",
                round _radius, round (_density*100), "%", round (_b2Ratio*100), "%"];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    "\a3\Modules_F_Curator\Data\iconManual_ca.paa"
] call zen_custom_modules_fnc_register;

diag_log format ["[FST_HCSpawn] ZEN modules registered: %1 templates + Fill Garrison", count FST_HC_Templates];
