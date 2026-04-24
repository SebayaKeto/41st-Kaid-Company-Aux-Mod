// FST_HCSpawn_fnc_interceptZeusPlace
// Client-side. CuratorGroupPlaced EH. Serializes, deletes, respawns on HC.

params ["_curator", "_group"];

if (!FST_HC_InterceptEnabled) exitWith {};
if (isPlayer leader _group) exitWith {};

private _units = units _group;
if (count _units == 0) exitWith {};

private _side = side _group;
private _leader = leader _group;
private _leaderVeh = vehicle _leader;
private _unitClasses = [];
private _vehData = [];

if (_leaderVeh != _leader) then {
    _vehData = [typeOf _leaderVeh, position _leaderVeh];
} else {
    { _unitClasses pushBack (typeOf _x); } forEach _units;
};

private _pos = if (count _vehData > 0) then { _vehData select 1 } else { position _leader };

if (count _vehData > 0) then {
    { _leaderVeh deleteVehicleCrew _x } forEach crew _leaderVeh;
    deleteVehicle _leaderVeh;
} else {
    { deleteVehicle _x } forEach _units;
};
_group deleteGroupWhenEmpty true;

[_side, _unitClasses, _pos, "none", 0, _vehData] remoteExecCall ["FST_HCSpawn_fnc_spawnGroupOnTarget", 2];
