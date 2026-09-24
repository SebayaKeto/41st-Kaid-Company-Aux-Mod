// Public, arguments local: [group, "hunt"|"assault"|"stop", objectiveATL, radius].
// Stores intent on the group so the new owner can resume after an HC transfer.
params ["_group", ["_mode", "stop"], ["_pos", []], ["_radius", 500]];
if (isNull _group || {!local _group}) exitWith {false};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
[_group] call FST_HCSpawn_fnc_burnsReleaseBX;
// Clear our temporary aiming before accepting a newer task.
[_group] call FST_HCSpawn_fnc_burnsReleasePointFire;
// Used only to prevent a delayed locality restore reviving an older BURNS hold.
if (_mode=="stop" || {_mode in ["hunt","assault","rush","ambush","creep","retreat","garrison","camp","defend","cqb"] && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]} && {!(_group getVariable ["BURNS_exempt",false])}}) then {
    ([_group,["BURNS_movementRevision",(([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet))+1,true]] call FST_HCSpawn_fnc_burnsStateSet);
};
if (_mode == "stop") exitWith {
    for "_i" from (count waypoints _group-1) to 0 step -1 do {
        if (waypointDescription [_group,_i]=="BURNS patrol") then {deleteWaypoint [_group,_i]};
    };
    ([_group,["BURNS_patrol",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_rushState",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_rushTarget",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_huntLeg",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    [_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;
    {
        _x setVariable ["BURNS_stationProgress",nil];
        private _stationUnit=_x;
        {if (!isNil {_stationUnit getVariable _x}) then {_stationUnit setVariable [_x,nil,true]}} forEach ["BURNS_stationFallback","BURNS_stationOriginal"];
        if (local _x && {_x getVariable ["BURNS_ownsPath",false]} && {([_x] call FST_HCSpawn_fnc_burnsRole)!="webknight"}) then {
            _x enableAI "PATH";
            _x setVariable ["BURNS_ownsPath",nil,true];
            private _slots=_group getVariable ["BURNS_stationSlots",[]];
            private _stationIndex=_slots findIf {(_x select 0)==_stationUnit};
            private _slot=if (_stationIndex>=0) then {(_slots select _stationIndex) select 1} else {getPosATL _stationUnit};
            private _token=(_stationUnit getVariable ["BURNS_cleanupSerial",0])+1;
            _stationUnit setVariable ["BURNS_cleanupSerial",_token];
            _stationUnit setVariable ["BURNS_moveCleanupToken",_token];
            [FST_HCSpawn_fnc_burnsReleaseStation,[_stationUnit,+_slot,_token],0.1] call CBA_fnc_waitAndExecute;
        };
    } forEach units _group;
    {_group setVariable [_x,nil,true]} forEach ["BURNS_stationSlots","BURNS_stationStatus","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_cqbSkipped","BURNS_cqbStatus","BURNS_holdReleased"];
    ([_group,["FST_HC_combatTask", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    if (_group getVariable ["BURNS_ownsKeepActive", false]) then {
        _group setVariable ["FST_HC_keepActive", nil, true];
        _group setVariable ["BURNS_ownsKeepActive", nil, true];
    };
    [_group,false] call FST_HCSpawn_fnc_burnsSimulation;
    private _index = ([_group,["FST_HC_taskWaypoint", -1]] call FST_HCSpawn_fnc_burnsStateGet);
    if (_index >= 0 && {_index < count waypoints _group} && {waypointDescription [_group,_index] == "FST HC combat"}) then {
        deleteWaypoint [_group,_index];
    };
    ([_group,["FST_HC_taskWaypoint", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["FST_HC_taskLastOrder", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    true
};
if !(_mode in ["hunt", "assault", "rush", "ambush","ambush", "creep", "retreat", "garrison", "camp", "defend", "cqb"]) exitWith {false};
if (!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) || {_group getVariable ["BURNS_exempt",false]}) exitWith {false};
// Public calls can replace tasks too. Release old holds and routes exactly as
// the Zeus broker does, including when only the task's destination changes.
if (count (([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))>0 || {!isNil {([_group,"BURNS_patrol"] call FST_HCSpawn_fnc_burnsStateGet)}}) then {
    [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
};
{_x setVariable ["BURNS_moveCleanupToken",nil]} forEach units _group;
if (count _pos < 2) then { _pos = getPosATL leader _group; };
_radius = (_radius max 15) min 3000;
if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled", true]) exitWith {false};
if !(_group getVariable ["FST_HC_keepActive", false]) then {
    _group setVariable ["BURNS_ownsKeepActive", true, true];
};
{
    if (local _x && {([_x] call FST_HCSpawn_fnc_burnsRole)!="webknight"} && {_x getVariable ["FST_HC_ownsPath",false] || {!isNil {_x getVariable "FST_HC_assignedPos"}}}) then {
        _x enableAI "PATH";
        _x setVariable ["FST_HC_ownsPath",nil,true];
        _x setVariable ["FST_HC_assignedPos",nil,true];
        _x doFollow leader _group;
    };
} forEach units _group;
[_group,true] call FST_HCSpawn_fnc_burnsSimulation;
// B2/BX receive ordinary mission movement; their combat remains WebKnight's.
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) >= 0 && {!(_mode in ["ambush","creep","cqb"] && {(units _group findIf {alive _x && {!(_x isKindOf "WBK_LS_BX")}})<0})}) exitWith {
    private _index = ([_group,["FST_HC_taskWaypoint", -1]] call FST_HCSpawn_fnc_burnsStateGet);
    private _wp = if (_index >= 0 && {_index < count waypoints _group} && {waypointDescription [_group,_index] == "FST HC combat"}) then {
        [_group,_index]
    } else {
        _group addWaypoint [_pos, 20]
    };
    _wp setWaypointPosition [_pos,20];
    _wp setWaypointDescription "FST HC combat";
    _wp setWaypointType "MOVE";
    _wp setWaypointSpeed "NORMAL";
    _group setCurrentWaypoint _wp;
    ([_group,["FST_HC_taskWaypoint", _wp select 1, true]] call FST_HCSpawn_fnc_burnsStateSet);
    _group setVariable ["FST_HC_keepActive", true, true];
    true
};
([_group,["FST_HC_combatTask", [_mode, +_pos, _radius], true]] call FST_HCSpawn_fnc_burnsStateSet);
if (isNil "FST_HC_CombatGroups") then {[true] call FST_HCSpawn_fnc_initCombatTasks};
FST_HC_CombatGroups pushBackUnique _group;
BURNS_ActiveGroups pushBackUnique _group;
if (_mode in ["rush","hunt","creep"]) then {
    BURNS_Players=allPlayers select {alive _x && {!(_x isKindOf "HeadlessClient_F")}};
    BURNS_PlayerPositions=BURNS_Players apply {getPosWorld (vehicle _x)};
};
_group setVariable ["FST_HC_keepActive", true, true];
_group setVariable ["FST_HC_taskNext", time + random 2];
([_group,["FST_HC_taskLastOrder", [], true]] call FST_HCSpawn_fnc_burnsStateSet);
if (_mode in ["garrison","camp","defend","cqb"]) then {
    private _wp=_group addWaypoint [_pos,0];
    _wp setWaypointDescription "FST HC combat";
    _wp setWaypointType "MOVE";
    _group setCurrentWaypoint _wp;
    ([_group,["FST_HC_taskWaypoint",_wp select 1,true]] call FST_HCSpawn_fnc_burnsStateSet);
};
[_group] call FST_HCSpawn_fnc_burnsApplyRole;
[_group] call FST_HCSpawn_fnc_combatTaskTick;
true
