// FST_HCSpawn_fnc_getFSTOpforUnitOptions
// Builds ZEN combo values/labels for Fill Garrison's B1 replacement dropdown.
// First entry is always the original weighted B1 mix.

private _cached = missionNamespace getVariable ["FST_HC_FSTOpforUnitOptions", []];
if (count _cached == 2) exitWith { _cached };

private _pairs = [];

{
    private _class = configName _x;
    if ([_class] call FST_HCSpawn_fnc_isValidFSTOpforUnit) then {
        private _displayName = getText (_x >> "displayName");
        if (_displayName isEqualTo "") then { _displayName = _class; };
        _pairs pushBack [format ["%1 — %2", _displayName, _class], _class];
    };
} forEach ("true" configClasses (configFile >> "CfgVehicles"));

_pairs sort true;

private _values = [""];
private _labels = ["Default B1/B2 Droid Mix"];
{
    _labels pushBack (_x select 0);
    _values pushBack (_x select 1);
} forEach _pairs;

private _result = [_values, _labels];
missionNamespace setVariable ["FST_HC_FSTOpforUnitOptions", _result];
_result
