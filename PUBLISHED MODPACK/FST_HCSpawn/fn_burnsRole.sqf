// Original cached classification, including inherited modded classes.
params ["_unit"];
if (isNull _unit || {!(_unit isKindOf "CAManBase")}) exitWith {"other"};
private _class = typeOf _unit;
private _cache = missionNamespace getVariable ["BURNS_roleCache", createHashMap];
missionNamespace setVariable ["BURNS_roleCache", _cache];
private _role = _cache getOrDefault [_class, ""];
if (_role != "") exitWith {_role};
private _cfg = configFile >> "CfgVehicles" >> _class;
_role = "human";
while {isClass _cfg} do {
    private _parts = (toLowerANSI configName _cfg) splitString "_";
    if (("b2" in _parts) || {"bx" in _parts}) exitWith {_role = "webknight"};
    if ("b1" in _parts) exitWith {_role = "b1"};
    _cfg = inheritsFrom _cfg;
};
if (_role == "human" && {[_unit] call FST_HCSpawn_fnc_isDroidUnit}) then {_role = "other"};
_cache set [_class, _role];
_role
