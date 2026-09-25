// Delayed destination comparison: doMove may expose the old goal until the
// engine planner runs. A later BURNS order invalidates this cleanup token.
params ["_unit","_goal","_token",["_attempt",0]];
if (isNull _unit || {!local _unit} || {(_unit getVariable ["BURNS_moveCleanupToken",-1])!=_token}) exitWith {};
if (!alive _unit || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _unit!=_unit} || {!(_unit checkAIFeature "PATH")} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"} || {[group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup}) exitWith {_unit setVariable ["BURNS_moveCleanupToken",nil]};
private _expected=expectedDestination _unit;
if ((_expected select 1)=="DoNotPlan" && {_attempt<3}) exitWith {
    [FST_HCSpawn_fnc_burnsCancelAdvanceMove,[_unit,_goal,_token,_attempt+1],0.1] call CBA_fnc_waitAndExecute;
};
if (currentCommand _unit=="MOVE" && {(_expected select 1)!="DoNotPlan"} && {(_expected select 0) distance2D _goal<2}) then {
    if (_unit==leader group _unit) then {_unit doMove getPosATL _unit} else {_unit doFollow leader group _unit};
};
_unit setVariable ["BURNS_moveCleanupToken",nil];
