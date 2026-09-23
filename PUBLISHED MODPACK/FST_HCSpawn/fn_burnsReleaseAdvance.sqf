params ["_group",["_cancelMove",true]];
if (isNull _group || {!local _group}) exitWith {};
private _roster=_group getVariable ["BURNS_advanceRoster",[]];
{[_x,_cancelMove,_group] call FST_HCSpawn_fnc_burnsReleaseAdvanceUnit} forEach ((units _group)+(_roster-(units _group)));
_group setVariable ["BURNS_advanceRoster",nil];
_group setVariable ["BURNS_localDeployFrame",nil];
_group setVariable ["BURNS_localAdvanceFormation",nil];
{if (!isNil {_group getVariable _x}) then {_group setVariable [_x,nil,true]}} forEach ["BURNS_advanceFormation","BURNS_deployUntil","BURNS_advanceOrders"];
