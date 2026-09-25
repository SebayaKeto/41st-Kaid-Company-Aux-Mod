// Old owner only. Remote checkAIFeature reads must not supply this snapshot.
params ["_group","_serial","_owner"];
if (isNull _group || {!local _group} || {clientOwner!=_owner}) exitWith {};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
private _rows=units _group apply {[_x,_x checkAIFeature "PATH",_x checkAIFeature "MOVE",_x getVariable ["BURNS_ownsPath",false],([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet)]};
["FST_HC_evt_receiveTransferState",[_group,_serial,_owner,_rows]] call CBA_fnc_serverEvent;
