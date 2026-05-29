// FST_HCSpawn_fnc_registerZenModules
// Client-side. Registers ZEN custom modules under "41st Kaid Modules".
// Default behavior: Assault (LAMBS rush)

if (!hasInterface) exitWith {};

// ============================================================
// TEMPLATE MODULES
// ============================================================
{
    private _key = _x;
    private _data = _y;
    _data params ["_side", "_unitClasses", "_desc"];

    private _code = compile format [
        '
        params ["_pos"];
        ["%1",
        [
            ["COMBO", "Behavior", [[0,1,2,3,4,5], ["Assault","Hunt","Garrison","Patrol","Static","No Behavior"], 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos", "_key"];
            private _behavior = ["assault","hunt","garrison","patrol","static","none"] select (_values select 0);
            ["FST_HC_evt_quickSpawn", [_pos, _key, _behavior, -1]] call CBA_fnc_serverEvent;
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

        private _replacementOptions = [] call FST_HCSpawn_fnc_getFSTOpforUnitOptions;
        _replacementOptions params ["_replacementValues", "_replacementLabels"];

        ["Fill Garrison",
        [
            ["SLIDER", "Scan Radius (m)", [25, 500, 150, 0]],
            ["SLIDER", "Density %", [10, 100, 75, 0]],
            ["SLIDER", "B2 Mix %", [0, 100, 20, 0]],
            ["COMBO", ["B1 Replacement Unit", "Default keeps the original weighted B1 pool. Selecting a unit replaces only the B1 portion; the B2 mix slider still controls B2s. Only FST_ OPFOR infantry are listed."], [_replacementValues, _replacementLabels, 0], true]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            private _radius = _values select 0;
            private _density = (_values select 1) / 100;
            private _b2Ratio = (_values select 2) / 100;
            private _b1Replacement = _values select 3;
            private _caller = clientOwner;

            ["FST_HC_evt_fillGarrison", [_pos, _radius, _density, _b2Ratio, _caller, _b1Replacement]] call CBA_fnc_serverEvent;

            private _replacementText = if (_b1Replacement isEqualTo "") then { "Default B1 mix" } else { _b1Replacement };
            systemChat format ["[FST] Filling — %1m, %2%3 density, %4%5 B2, B1: %6",
                round _radius, round (_density*100), "%", round (_b2Ratio*100), "%", _replacementText];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    "\a3\Modules_F_Curator\Data\iconManual_ca.paa"
] call zen_custom_modules_fnc_register;

// ============================================================
// FRONTLINE MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- Frontline Assault ---",
    {
        params ["_pos"];
        ["Frontline Assault",
        [
            ["COMBO", "Template", [
                keys FST_HC_Templates,
                values FST_HC_Templates apply { _x select 2 },
                0
            ]],
            ["SLIDER", "Number of Waves", [1, 20, 3, 0]],
            ["SLIDER", "Seconds Between Waves", [1, 30, 5, 0]],
            ["SLIDER", "Assault Radius", [100, 2000, 2000, 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            private _templateKey = _values select 0;
            private _waveCount = round (_values select 1);
            private _waveDelay = _values select 2;
            private _assaultRadius = _values select 3;
            private _caller = clientOwner;

            ["FST_HC_evt_frontline", [_pos, _templateKey, _waveCount, _waveDelay, _assaultRadius, _caller]]
                call CBA_fnc_serverEvent;

            systemChat format ["[FST] Frontline: %1x waves incoming", _waveCount];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    "\a3\Modules_F_Curator\Data\iconManual_ca.paa"
] call zen_custom_modules_fnc_register;

// ============================================================
// QRF MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- QRF Response ---",
    {
        params ["_pos"];
        ["QRF Response",
        [
            ["COMBO", "Infantry Template", [
                keys FST_HC_Templates,
                values FST_HC_Templates apply { _x select 2 },
                0
            ]],
            ["SLIDER", "Number of Squads", [1, 4, 1, 0]],
            ["COMBO", "Transport", [
                ["foot", "SAC", "PAC", "MTT", "HMP"],
                ["On Foot", "SAC (1 squad)", "PAC (2 squads)", "MTT (4 squads)", "HMP Gunship (air)"],
                0
            ]],
            ["COMBO", "Escort", [
                ["none", "AAT", "N99"],
                ["No Escort", "AAT Tank", "N99 Tank"],
                0
            ]],
            ["SLIDER", "Escort Count", [1, 4, 2, 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            private _templateKey = _values select 0;
            private _squadCount = round (_values select 1);
            private _transport = _values select 2;
            private _escort = _values select 3;
            private _escortCount = round (_values select 4);
            private _caller = clientOwner;

            ["FST_HC_evt_qrf", [_pos, _templateKey, _squadCount, _transport, _escort, _escortCount, _caller]]
                call CBA_fnc_serverEvent;

            systemChat format ["[FST] QRF: %1x squads via %2 inbound", _squadCount, _transport];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    "\a3\Modules_F_Curator\Data\iconManual_ca.paa"
] call zen_custom_modules_fnc_register;

diag_log format ["[FST_HCSpawn] ZEN modules registered: %1 templates + Fill Garrison + Frontline + QRF", count FST_HC_Templates];
