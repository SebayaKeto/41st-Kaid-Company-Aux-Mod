/*
    FST_fnc_RRR_checkCondition
    Shows the service action only to a pilot inside a service zone.
*/
params ["_unit"];

private _vehicle = vehicle _unit;
if (_vehicle == _unit)         exitWith { false };
if !(driver _vehicle == _unit) exitWith { false };
if (_unit getVariable ["VR_RepairActive", false]) exitWith { false };

[getPosATL _vehicle] call FST_fnc_RRR_isInZone
