// Release only overrides we still own. A later external speed/order wins.
params ["_unit",["_cancelMove",true],["_controller",grpNull]];
if (isNull _unit || {!local _unit} || {[_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit}) exitWith {};
if (!isNull _controller && {(_unit getVariable ["BURNS_advanceController",_controller])!=_controller}) exitWith {};
private _speed=_unit getVariable ["BURNS_advanceSpeed",[]];
if (count _speed==2) then {
    if (abs (getForcedSpeed _unit-(_speed select 1))<0.05) then {_unit forceSpeed (_speed select 0)};
    _unit setVariable ["BURNS_advanceSpeed",nil,true];
};
private _goal=_unit getVariable ["BURNS_formationGoal",[]];
if (_cancelMove && {count _goal>0} && {alive _unit} && {!([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} && {vehicle _unit==_unit} && {_unit checkAIFeature "PATH"} && {([_unit] call FST_HCSpawn_fnc_burnsRole)!="webknight"} && {!([group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup)}) then {
    private _token=(_unit getVariable ["BURNS_cleanupSerial",0])+1;
    _unit setVariable ["BURNS_cleanupSerial",_token];
    _unit setVariable ["BURNS_moveCleanupToken",_token];
    [FST_HCSpawn_fnc_burnsCancelAdvanceMove,[_unit,+_goal,_token],0.1] call CBA_fnc_waitAndExecute;
};
_unit setVariable ["BURNS_formationGoal",nil];
if (!isNil {_unit getVariable "BURNS_advanceController"}) then {_unit setVariable ["BURNS_advanceController",nil,true]};
