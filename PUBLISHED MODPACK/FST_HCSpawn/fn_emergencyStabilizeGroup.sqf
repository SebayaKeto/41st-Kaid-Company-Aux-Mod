// FST_HCSpawn_fnc_emergencyStabilizeGroup
// Stabilizes all local droid units in a group or array of units.

params ["_target"];

private _units = [];
if (_target isEqualType grpNull) then {
    if (!isNull _target) then { _units = units _target; };
} else {
    if (_target isEqualType []) then { _units = _target; };
};

private _count = 0;
{
    if (!isNull _x && {local _x}) then {
        if ([_x] call FST_HCSpawn_fnc_emergencyStabilizeDroid) then {
            _count = _count + 1;
        };
    };
} forEach _units;

_count
