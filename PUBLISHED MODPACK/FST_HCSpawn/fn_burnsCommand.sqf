// Original BURNS owner-local command handler shared by Zeus modules and menus.
params ["_mode","_group","_pos",["_radius",150],["_options",[]],["_caller",-1]];
if (isNull _group || {!local _group} || {(units _group findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)})>=0}) exitWith {false};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
if (_mode in ["rush","hunt","ambush","creep","assault","retreat","cqb","garrison","camp","defend","patrol","target"] && {!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) || {_group getVariable ["BURNS_exempt",false]}}) exitWith {false};
private _held=_group getVariable ["FST_HC_heldBy",-1];
if (_held!=-1 && {_caller!=_held || {_caller<3}}) exitWith {false};
if (_held!=-1) then {_group setVariable ["BURNS_manualHeldOwner",_caller,true]};
private _wbk=(units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight"})>=0;
if (_mode=="enable_group") exitWith {
    _group setVariable ["BURNS_exempt",false,true];
    if (!_wbk) then {[_group] call FST_HCSpawn_fnc_burnsApplyRole};
    true
};
if (_mode in ["radio_on","radio_off","reinforce_on","reinforce_off"]) exitWith {
    private _key=if (_mode in ["radio_on","radio_off"]) then {"BURNS_hasRadio"} else {"BURNS_reinforcement"};
    _group setVariable [_key,_mode in ["radio_on","reinforce_on"],true];
    true
};
if (_mode=="target") exitWith {
    _group setVariable ["BURNS_taskCaller",_caller,true];
    private _patrol=([_group,["BURNS_patrol",[]]] call FST_HCSpawn_fnc_burnsStateGet);
    if (count _patrol==2) exitWith {[_group,_pos,_patrol select 1] call FST_HCSpawn_fnc_burnsPatrol};
    private _task=([_group,["FST_HC_combatTask",["assault",_pos,_radius]]] call FST_HCSpawn_fnc_burnsStateGet);
    _group setVariable ["BURNS_taskOptions",(_group getVariable ["BURNS_taskOptions",[false,true,false]]) select [0,3],true];
    [_group,_task select 0,_pos,_task select 2] call FST_HCSpawn_fnc_setCombatTask
};
if (_mode=="ambush" && {(units _group findIf {alive _x && {!(_x isKindOf "WBK_LS_BX")}})>=0}) exitWith {false};
// Native Zeus waypoints cancel our intent without replacing the new order.
if (_mode=="stop") exitWith {[_group,"stop"] call FST_HCSpawn_fnc_setCombatTask};
// Cancel only BURNS-owned movement and position holds when replacing a task.
[_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
for "_i" from (count waypoints _group-1) to 0 step -1 do {
    if ((waypointDescription [_group,_i]) find "BURNS "==0 || {_mode=="reset"}) then {deleteWaypoint [_group,_i]};
};
{
    if (([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight") then {continue};
    if (_x getVariable ["BURNS_ownsPath",false] || {_mode in ["reset","rush","hunt","ambush","creep","assault","retreat","cqb","garrison","camp","defend","patrol"] && {_x getVariable ["FST_HC_ownsPath",false] || {!isNil {_x getVariable "FST_HC_assignedPos"}}}}) then {
        _x enableAI "PATH";
        _x setVariable ["BURNS_ownsPath",nil,true];
        _x setVariable ["FST_HC_assignedPos",nil,true];
        _x setVariable ["FST_HC_ownsPath",nil,true];
    };
    if (!isNil {_x getVariable "BURNS_scanWatch"}) then {_x doWatch objNull;_x setVariable ["BURNS_scanWatch",nil]};
    _x doFollow leader _group;
} forEach units _group;
{_group setVariable [_x,nil,true]} forEach ["BURNS_stationSlots","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_holdReleased"];
if (_mode in ["enable_group","disable_group"]) exitWith {
    _group setVariable ["BURNS_exempt",_mode=="disable_group",true];
    if (!_wbk && {_mode=="disable_group"}) then {
        [_group] call FST_HCSpawn_fnc_burnsRestoreGroupRole;
    };
    if (!_wbk && {_mode=="enable_group"}) then {[_group] call FST_HCSpawn_fnc_burnsApplyRole};
    true
};
if (_mode=="reset") exitWith {
    _group setCombatMode "YELLOW";
    _group setBehaviourStrong "AWARE";
    if (!_wbk) then {[_group] call FST_HCSpawn_fnc_burnsApplyRole};
    true
};
if (_mode=="patrol") exitWith {[_group,_pos,_radius] call FST_HCSpawn_fnc_burnsPatrol};
// WebKnight receives native mission movement only; no garrison, stance or CQB
// scripts are attached to B2/BX, including when mixed into another squad.
// Preserve the requested BX task instead of silently converting it to Assault.
_group setVariable ["BURNS_taskCaller",_caller,true];
_group setVariable ["BURNS_taskOptions",_options,true];
private _ok=[_group,_mode,_pos,_radius] call FST_HCSpawn_fnc_setCombatTask;
if (_ok && {_mode=="assault"} && {(_options param [5,""])!=""}) then {_group setVariable ["BURNS_sectionToken",_options select 5,true];_group setVariable ["FST_HC_taskNext",-1]};
_ok
