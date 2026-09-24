// Issue after this tick has finished creating/updating the native waypoint.
// A newer task or Zeus move always invalidates this delayed order.
params ["_v","_driver","_goal","_revision","_owner"];
if (isNull _v || {!local _v} || {!local _driver} || {clientOwner!=_owner} || {driver _v!=_driver} || {!alive _driver} || {!canMove _v}) exitWith {};
private _g=group _driver;
if (!([_g] call FST_HCSpawn_fnc_burnsEngagementAllowed) || {!(_driver checkAIFeature "PATH")} || {!(_driver checkAIFeature "MOVE")}) exitWith {};
if (([_g,["BURNS_movementRevision",-1]] call FST_HCSpawn_fnc_burnsStateGet)!=_revision) exitWith {};
private _last=[_g,["FST_HC_taskLastOrder",[]]] call FST_HCSpawn_fnc_burnsStateGet;
private _wp=[_g,["FST_HC_taskWaypoint",-1]] call FST_HCSpawn_fnc_burnsStateGet;
if (count _last<2 || {_last distance2D _goal>2} || {_wp<0} || {currentWaypoint _g!=_wp} || {waypointDescription [_g,_wp]!="FST HC combat"}) exitWith {};
_driver doMove _goal;
diag_log format ["[BURNS_N99_SETTLED_MOVE] vehicle=%1 owner=%2 revision=%3 destination=%4",netId _v,clientOwner,_revision,_goal];
