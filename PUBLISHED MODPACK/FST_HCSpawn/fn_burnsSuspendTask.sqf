// Keep task intent for a possible later resume; cancel only BURNS movement.
params ["_group"];
if (isNull _group || {!local _group}) exitWith {};
{_group setVariable [_x,nil,true]} forEach ["BURNS_sectionToken","BURNS_sectionPlan","BURNS_sectionContact"];
{[_x] call FST_HCSpawn_fnc_burnsArmorSectionDriver} forEach units _group;
[_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;
[_group] call FST_HCSpawn_fnc_burnsReleaseBX;
// Station holds also belong to the suspended task. Release only owned,
// local infantry holds; external PATH locks and protected assets stay untouched.
if !([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) then {
    {
        private _u=_x;
        if (!local _u || {([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {vehicle _u!=_u} || {([_u] call FST_HCSpawn_fnc_burnsRole)=="webknight"}) then {continue};
        if (_u getVariable ["BURNS_ownsPath",false]) then {
            _u enableAI "PATH";
            _u setVariable ["BURNS_ownsPath",nil,true];
            // Do not replace a newer external destination when releasing a hold.
            private _slots=_group getVariable ["BURNS_stationSlots",[]];
            private _index=_slots findIf {(_x select 0)==_u};
            private _slot=if (_index>=0) then {(_slots select _index) select 1} else {getPosATL _u};
            private _token=(_u getVariable ["BURNS_cleanupSerial",0])+1;
            _u setVariable ["BURNS_cleanupSerial",_token];
            _u setVariable ["BURNS_moveCleanupToken",_token];
            [FST_HCSpawn_fnc_burnsReleaseStation,[_u,+_slot,_token],0.1] call CBA_fnc_waitAndExecute;
        };
        _u setVariable ["BURNS_stationProgress",nil];
        {if (!isNil {_u getVariable _x}) then {_u setVariable [_x,nil,true]}} forEach ["BURNS_stationFallback","BURNS_stationOriginal"];
    } forEach units _group;
};
// Keep task intent, but rebuild stations/routes on the next eligible visit.
if (count (([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3) then {
    {if (!isNil {([_group,_x] call FST_HCSpawn_fnc_burnsStateGet)}) then {([_group,[_x,nil,true]] call FST_HCSpawn_fnc_burnsStateSet)}} forEach ["BURNS_stationSlots","BURNS_stationStatus","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_cqbSkipped","BURNS_cqbStatus","BURNS_holdReleased"];
};
private _wp=([_group,["FST_HC_taskWaypoint",-1]] call FST_HCSpawn_fnc_burnsStateGet);
if (_wp>=0 && {_wp<count waypoints _group} && {waypointDescription [_group,_wp]=="FST HC combat"}) then {deleteWaypoint [_group,_wp]};
{if (!isNil {([_group,_x] call FST_HCSpawn_fnc_burnsStateGet)}) then {([_group,[_x,nil,true]] call FST_HCSpawn_fnc_burnsStateSet)}} forEach ["FST_HC_taskWaypoint","FST_HC_taskLastOrder","BURNS_huntLeg"];
