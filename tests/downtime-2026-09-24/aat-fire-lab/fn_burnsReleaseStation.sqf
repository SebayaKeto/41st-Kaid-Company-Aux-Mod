// Releasing PATH alone leaves doStop active. Let pending engine destinations
// settle before cancelling that stop, so a newer external doMove wins.
params ["_unit","_slot","_token",["_attempt",0]];
if (isNull _unit || {!local _unit} || {(_unit getVariable ["BURNS_moveCleanupToken",-1])!=_token}) exitWith {};
if (!alive _unit || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _unit!=_unit} || {!(_unit checkAIFeature "PATH")} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"} || {[group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup}) exitWith {_unit setVariable ["BURNS_moveCleanupToken",nil]};
private _expected=expectedDestination _unit;
// Returning followers before their stopped leader can leave the leader's STOP
// active. CBA callbacks are not ordered by unit index. Let the leader finish
// its pending cleanup first; never issue a new command on its behalf.
private _leader=leader group _unit;
if (_unit!=_leader && {(_leader getVariable ["BURNS_moveCleanupToken",-1])>=0} && {_attempt<10}) exitWith {
    [FST_HCSpawn_fnc_burnsReleaseStation,[_unit,_slot,_token,_attempt+1],0.1] call CBA_fnc_waitAndExecute;
};
if ((_expected select 1)=="DoNotPlan" && {_attempt<3}) exitWith {
    [FST_HCSpawn_fnc_burnsReleaseStation,[_unit,_slot,_token,_attempt+1],0.1] call CBA_fnc_waitAndExecute;
};
if (((_expected select 1)=="DoNotPlan" && {currentCommand _unit!="MOVE"}) || {count _slot>=2 && {(_expected select 0) distance2D _slot<3}}) then {
    _unit doFollow leader group _unit
};
_unit setVariable ["BURNS_moveCleanupToken",nil];
