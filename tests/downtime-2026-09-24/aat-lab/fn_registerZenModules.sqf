// FST_HCSpawn_fnc_registerZenModules
// Client-side. Registers ZEN custom modules under "41st Kaid Modules".
// Default behavior: BURNS Assault

if (!hasInterface) exitWith {};
if (missionNamespace getVariable ["FST_HC_modulesRegistered",false]) exitWith {};
FST_HC_modulesRegistered=true;

private _icon = "\a3\Modules_F_Curator\Data\iconCurator_ca.paa";

// ============================================================
// TEMPLATE MODULES
// ============================================================
// The module code is built with format: %1 = description (dialog title),
// %2 = template key. Both are known here, so they are baked into the string;
// only the behavior is a runtime value. (The old code used "%%1" inside the
// inner format, but SQF format has no %% escape, so the chat line came out as
// "Spawning %B1 Squad STD (12) (%b1_squad)".)
{
    private _key = _x;
    private _data = _y;
    _data params ["_side", "_unitClasses", "_desc"];

    private _code = compile format [
        '
        params ["_pos"];
        _pos=ASLToATL _pos;
        ["%1",
        [
            ["COMBO", "Behavior", [[0,1,2,3,4,5], ["Assault","Hunt","Garrison","Patrol","Static","No Behavior"], 0]]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos", "_key"];
            private _behavior = ["assault","hunt","garrison","patrol","static","none"] select (_values select 0);
            ["FST_HC_evt_quickSpawn", [_pos, _key, _behavior, -1, clientOwner]] call CBA_fnc_serverEvent;
            systemChat ("[FST] Spawning %2 (" + _behavior + ")");
        },
        {},
        [_pos, "%2"]
        ] call zen_dialog_fnc_create;
        ',
        _desc, _key
    ];

    ["41st Kaid Modules", _desc, _code, _icon] call FST_HCSpawn_fnc_registerNativeModule;

} forEach FST_HC_Templates;

// ============================================================
// FILL GARRISON MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- Fill Garrison ---",
    {
        params ["_pos"];
        _pos=ASLToATL _pos;

        private _replacementOptions = [] call FST_HCSpawn_fnc_getFSTOpforUnitOptions;
        _replacementOptions params ["_replacementValues", "_replacementLabels"];

        ["Fill Garrison",
        [
            ["SLIDER", "Scan Radius (m)", [25, 500, 150, 0]],
            ["SLIDER", "Density %", [10, 100, 75, 0]],
            ["COMBO", ["B1 Replacement Unit", "Default keeps the original weighted B1 pool. Selecting a unit replaces the B1 pool entirely. Only FST_ OPFOR infantry are listed."], [_replacementValues, _replacementLabels, 0], true]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            private _radius = _values select 0;
            private _density = (_values select 1) / 100;
            private _b1Replacement = _values select 2;
            private _caller = clientOwner;

            ["FST_HC_evt_fillGarrison", [_pos, _radius, _density, _caller, _b1Replacement]] call CBA_fnc_serverEvent;

            private _replacementText = if (_b1Replacement isEqualTo "") then { "Default B1 mix" } else { _b1Replacement };
            systemChat format ["[FST] Filling -- %1m, %2%3 density, B1: %4",
                round _radius, round (_density*100), "%", _replacementText];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

// ============================================================
// FRONTLINE MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- Frontline Assault ---",
    {
        params ["_pos"];
        _pos=ASLToATL _pos;
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
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

// ============================================================
// QRF MODULE
// ============================================================
[
    "41st Kaid Modules",
    "--- QRF Response ---",
    {
        params ["_pos"];
        _pos=ASLToATL _pos;
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
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

// ============================================================
// VEHICLE SPAWN MODULE (V28)
// ============================================================
// Crewed AI vehicles are created on the dedicated vehicle HC (or the
// least-loaded HC) by fn_spawnVehicleOnTarget, so they never change owner.
[
    "41st Kaid Modules",
    "--- Vehicle Spawn ---",
    {
        params ["_pos"];
        _pos=ASLToATL _pos;
        private _keys = keys FST_HC_VehicleTemplates;
        private _labels = _keys apply { (FST_HC_VehicleTemplates get _x) select 2 };
        ["Vehicle Spawn (vehicle HC)",
        [
            ["COMBO", "Vehicle", [_keys, _labels, 0]],
            ["SLIDER", "Count", [1, 8, 1, 0]],
            ["COMBO", ["Behaviour", "Template default: tanks hunt, transports move to the module position, vultures seek and destroy around it."], [
                ["default", "none", "hold", "patrol", "hunt", "assault", "move", "sad", "loiter"],
                ["Template default", "No orders", "Hold", "Patrol", "Hunt", "Assault", "Move here", "Seek & Destroy here", "Loiter here"],
                0
            ]],
            ["SLIDER", ["Radius (m)", "Patrol/hunt/loiter radius. 0 = behaviour default."], [0, 2000, 0, 0]],
            ["COMBO", "Crew Skill", [[-1, 0.5, 0.8, 1], ["Default", "Regular", "Veteran", "Maximum"], 0]],
            ["CHECKBOX", ["Spawn Aircraft Airborne", "Aircraft start flying at 150m; ground vehicles ignore this."], true]
        ],
        {
            params ["_values", "_args"];
            _args params ["_pos"];
            _values params ["_key", "_count", "_behaviorSel", "_radius", "_skill", "_airborne"];
            private _tpl = FST_HC_VehicleTemplates getOrDefault [_key, []];
            if (count _tpl == 0) exitWith { systemChat "[FST] Unknown vehicle template."; };
            _tpl params ["_side", "_class", "_desc", "_defaultBehavior", "_isAir"];
            private _behavior = if (_behaviorSel == "default") then { _defaultBehavior } else { _behaviorSel };
            if (_radius <= 0) then { _radius = -1; };
            _count = round _count;
            for "_i" from 0 to (_count - 1) do {
                private _spawnPos = _pos vectorAdd [(_i mod 4) * 30, floor (_i / 4) * 30, 0];
                if (_isAir) then { _spawnPos set [2, 150 + _i * 20]; };
                ["FST_HC_evt_spawnVehicle", [_side, _class, _spawnPos, 0, _behavior, _radius, clientOwner,
                    [["skill", _skill], ["flying", _airborne && _isAir], ["target", _pos], ["tag", "zeus_vehicle_spawn"]]]] call CBA_fnc_serverEvent;
            };
            systemChat format ["[FST] Spawning %1x %2 (%3) on the vehicle HC", _count, _desc, _behavior];
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

// ============================================================
// SEND TO VEHICLE HC MODULE (V28)
// ============================================================
// Acts on the current Zeus selection (Ctrl+click groups or vehicles). The
// server only moves a group whose vehicles are stopped, landed and fully
// crewed by that group, and tells the Zeus otherwise.
[
    "41st Kaid Modules",
    "--- Send To Vehicle HC ---",
    {
        private _groups = +(curatorSelected select 1);
        { _groups pushBackUnique (group _x); } forEach ((curatorSelected select 0) select { !isNull group _x });
        _groups = _groups select { !isNull _x && {count units _x > 0} && {!isPlayer leader _x} };
        if (count _groups == 0) exitWith { systemChat "[FST] Select the vehicle or its group first (Ctrl+click), then place this module."; };
        { ["FST_HC_evt_sendToVehicleHC", [_x, clientOwner]] call CBA_fnc_serverEvent; } forEach _groups;
        systemChat format ["[FST] Requested vehicle HC transfer for %1 group(s).", count _groups];
    },
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

// ============================================================
// DEAD GROUP CLEANUP MODULE (V27)
// ============================================================
// Manual maintenance for controlled lulls. This event existed since V19 but had
// no UI entry point; it was only reachable from the debug console.
[
    "41st Kaid Modules",
    "--- Cleanup Dead Groups ---",
    {
        params ["_pos"];
        _pos=ASLToATL _pos;
        ["Cleanup Dead Groups",
        [
            ["SLIDER", ["Max Groups To Delete", "Per machine (server and each HC)."], [10, 300, 150, 0]],
            ["SLIDER", ["Tracked Group Min Dead Age (s)", "Extra caution for HC-tracked groups: only delete if every member has been dead at least this long."], [0, 600, 60, 0]]
        ],
        {
            params ["_values", "_args"];
            private _max = round (_values select 0);
            private _trackedAge = round (_values select 1);
            ["FST_HC_evt_manualDeadGroupCleanup", [_max, 0, _trackedAge, clientOwner]] call CBA_fnc_serverEvent;
            systemChat "[FST] Dead group cleanup requested on server and all HCs.";
        },
        {},
        [_pos]
        ] call zen_dialog_fnc_create;
    },
    _icon
] call FST_HCSpawn_fnc_registerNativeModule;

diag_log format ["[FST_HCSpawn] Native module callbacks registered: %1 templates + Fill Garrison + Frontline + QRF + Vehicle Spawn + Send To Vehicle HC + Dead Group Cleanup", count FST_HC_Templates];
