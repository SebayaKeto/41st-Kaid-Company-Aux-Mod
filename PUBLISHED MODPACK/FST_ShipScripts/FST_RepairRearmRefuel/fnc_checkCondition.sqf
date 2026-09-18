/*
    FST_fnc_RRR_checkCondition
    Condition for the repair/rearm/refuel addAction. Re-evaluated by the
    engine every time the action menu is built, so unlike a cached position
    this works correctly for a unit no matter when it entered the zone,
    including immediately after a respawn.
    params ["_unit"]
*/
params ["_unit"];

private _vehicle = vehicle _unit;
if (_vehicle == _unit)         exitWith { false };
if !(driver _vehicle == _unit) exitWith { false };
if (_unit getVariable ["VR_RepairActive", false]) exitWith { false };

[getPosATL _vehicle] call FST_fnc_RRR_isInZone
