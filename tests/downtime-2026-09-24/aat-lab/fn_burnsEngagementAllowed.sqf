// Shared ownership/control gate, checked again immediately before every action.
params ["_group"];
if (isNull _group) exitWith {false};
private _wp=currentWaypoint _group;
if (_wp>0 && {_wp<count waypoints _group} && {waypointType [_group,_wp] in ["MOVE","SAD"]} && {
    !(waypointDescription [_group,_wp] in ["FST HC combat","BURNS patrol"])
} && {leader _group distance2D waypointPosition [_group,_wp]>20}) exitWith {false};
!isNull _group && {local _group} && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]} && {
    !(_group getVariable ["BURNS_exempt",false])
} && {(_group getVariable ["FST_HC_heldBy",-1])==-1} && {
    !([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup)
} && {(units _group findIf {[_x] call FST_HCSpawn_fnc_isPlayerControlledUnit})<0} && {
    !((([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""]) in ["retreat","creep"])
} && {combatMode _group in ["YELLOW","RED"]}
