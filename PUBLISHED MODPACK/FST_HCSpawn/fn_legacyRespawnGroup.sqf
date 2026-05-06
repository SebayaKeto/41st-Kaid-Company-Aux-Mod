// FST_HCSpawn_fnc_legacyRespawnGroup
// Server-side emergency fallback. This is the old delete-and-respawn approach,
// kept disabled by default. It is useful only if setGroupOwner cannot move a
// Zeus-created group in a specific mission/mod/locality edge case.
// Arguments:
//   0: GROUP
// Returns: BOOL

if (!isServer) exitWith { false };

params ["_group"];

if (isNull _group) exitWith { false };
if (count units _group == 0) exitWith { false };
if (isPlayer leader _group) exitWith { false };
if (count FST_HC_Array == 0) exitWith { false };

private _units = units _group;
private _side = side _group;
private _leader = leader _group;
private _leaderVeh = vehicle _leader;
private _unitClasses = [];
private _vehData = [];

if (!isNull _leaderVeh && {_leaderVeh != _leader}) then {
    _vehData = [typeOf _leaderVeh, getPosATL _leaderVeh];
} else {
    { _unitClasses pushBack (typeOf _x); } forEach _units;
};

private _pos = if (count _vehData > 0) then { _vehData select 1 } else { getPosATL _leader };

if (count _vehData > 0) then {
    { _x setVariable ["FST_skipSpawnDamage", true, true]; } forEach crew _leaderVeh;
    { _leaderVeh deleteVehicleCrew _x; } forEach crew _leaderVeh;
    deleteVehicle _leaderVeh;
} else {
    { _x setVariable ["FST_skipSpawnDamage", true, true]; deleteVehicle _x; } forEach _units;
};
_group deleteGroupWhenEmpty true;

[_side, _unitClasses, _pos, "none", 0, _vehData] call FST_HCSpawn_fnc_spawnGroupOnTarget;

FST_HC_ZeusLegacyFallbacksUsed = (missionNamespace getVariable ["FST_HC_ZeusLegacyFallbacksUsed", 0]) + 1;
if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Legacy clone fallback used for Zeus group at %1", _pos];
};

true
