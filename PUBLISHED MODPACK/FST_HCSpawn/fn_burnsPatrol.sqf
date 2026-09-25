// Original native patrol route. Waypoints survive locality changes naturally.
params ["_group", "_centre", ["_radius",150]];
if (isNull _group || {!local _group}) exitWith {false};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
if (!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) || {_group getVariable ["BURNS_exempt",false]}) exitWith {false};
[_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
_group setVariable ["BURNS_b2TaskIntent","",true];
if !(_group getVariable ["FST_HC_keepActive",false]) then {_group setVariable ["BURNS_ownsKeepActive",true,true]};
_group setVariable ["FST_HC_keepActive",true,true];
[_group,true] call FST_HCSpawn_fnc_burnsSimulation;
for "_i" from (count waypoints _group-1) to 0 step -1 do {
    if (waypointDescription [_group,_i]=="BURNS patrol") then {deleteWaypoint [_group,_i]};
};
private _angle = random 360;
private _first = -1;
for "_i" from 0 to 3 do {
    private _p = _centre getPos [(_radius max 25) * 0.65, _angle + 90 * _i];
    if (surfaceIsWater _p) then {_p = +_centre};
    private _wp = _group addWaypoint [_p, 10];
    _wp setWaypointDescription "BURNS patrol";
    if (_first < 0) then {_first = _wp select 1};
    _wp setWaypointType "MOVE";
    _wp setWaypointBehaviour "AWARE";
    _wp setWaypointSpeed "LIMITED";
    _wp setWaypointCompletionRadius 15;
};
private _cycle = _group addWaypoint [waypointPosition [_group,_first], 0];
_cycle setWaypointDescription "BURNS patrol";
_cycle setWaypointType "CYCLE";
_group setCurrentWaypoint [_group,_first];
([_group,["BURNS_patrol",[+_centre,_radius],true]] call FST_HCSpawn_fnc_burnsStateSet);
true
