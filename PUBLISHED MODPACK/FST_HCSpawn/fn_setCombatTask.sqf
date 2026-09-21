// Public, arguments local: [group, "hunt"|"assault"|"stop", objectiveATL, radius].
// Stores intent on the group so the new owner can resume after an HC transfer.
params ["_group", ["_mode", "stop"], ["_pos", []], ["_radius", 500]];
if (isNull _group || {!local _group}) exitWith {false};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
if (_mode == "stop") exitWith {
    {
        if (local _x && {_x getVariable ["BURNS_ownsPath",false]} && {([_x] call FST_HCSpawn_fnc_burnsRole)!="webknight"}) then {
            _x enableAI "PATH";
            _x setVariable ["BURNS_ownsPath",nil,true];
            _x doFollow leader _group;
        };
    } forEach units _group;
    {_group setVariable [_x,nil,true]} forEach ["BURNS_stationSlots","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_holdReleased"];
    _group setVariable ["FST_HC_combatTask", nil, true];
    if (_group getVariable ["BURNS_ownsKeepActive", false]) then {
        _group setVariable ["FST_HC_keepActive", nil, true];
        _group setVariable ["BURNS_ownsKeepActive", nil, true];
    };
    private _index = _group getVariable ["FST_HC_taskWaypoint", -1];
    if (_index >= 0 && {_index < count waypoints _group} && {waypointDescription [_group,_index] == "FST HC combat"}) then {
        deleteWaypoint [_group,_index];
    };
    _group setVariable ["FST_HC_taskWaypoint", nil, true];
    _group setVariable ["FST_HC_taskLastOrder", nil, true];
    true
};
if !(_mode in ["hunt", "assault", "rush", "creep", "retreat", "garrison", "camp", "defend", "cqb"]) exitWith {false};
// Public calls can replace tasks too. Release old holds and routes exactly as
// the Zeus broker does, including when only the task's destination changes.
if (count (_group getVariable ["FST_HC_combatTask",[]])>0) then {
    [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
};
if (count _pos < 2) then { _pos = getPosATL leader _group; };
_radius = (_radius max 50) min 3000;
if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled", true]) exitWith {false};
if !(_group getVariable ["FST_HC_keepActive", false]) then {
    _group setVariable ["BURNS_ownsKeepActive", true, true];
};
// B2/BX receive ordinary mission movement; their combat remains WebKnight's.
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) >= 0) exitWith {
    private _index = _group getVariable ["FST_HC_taskWaypoint", -1];
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
    _group setVariable ["FST_HC_taskWaypoint", _wp select 1, true];
    _group setVariable ["FST_HC_keepActive", true, true];
    true
};
_group setVariable ["FST_HC_combatTask", [_mode, +_pos, _radius], true];
_group setVariable ["FST_HC_keepActive", true, true];
_group setVariable ["FST_HC_taskNext", time + random 2];
_group setVariable ["FST_HC_taskLastOrder", [], true];
if (_mode in ["garrison","camp","defend","cqb"]) then {
    private _wp=_group addWaypoint [_pos,0];
    _wp setWaypointDescription "FST HC combat";
    _wp setWaypointType "MOVE";
    _group setCurrentWaypoint _wp;
    _group setVariable ["FST_HC_taskWaypoint",_wp select 1,true];
};
true
