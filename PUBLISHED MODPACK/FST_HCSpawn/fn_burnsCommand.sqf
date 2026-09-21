// Original BURNS owner-local command handler shared by Zeus modules and menus.
params ["_mode","_group","_pos",["_radius",150],["_options",[]]];
if (isNull _group || {!local _group} || {(units _group findIf {isPlayer _x})>=0}) exitWith {false};
if ((_group getVariable ["FST_HC_heldBy",-1])!=-1) exitWith {false};
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
    private _task=_group getVariable ["FST_HC_combatTask",["assault",_pos,_radius]];
    [_group,_task select 0,_pos,_task select 2] call FST_HCSpawn_fnc_setCombatTask
};
// Cancel only BURNS-owned movement and position holds when replacing a task.
[_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
for "_i" from (count waypoints _group-1) to 0 step -1 do {
    if ((waypointDescription [_group,_i]) find "BURNS "==0 || {_mode=="reset"}) then {deleteWaypoint [_group,_i]};
};
{
    if (([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight") then {continue};
    if (_x getVariable ["BURNS_ownsPath",false] || {_mode=="reset" && {!isNil {_x getVariable "FST_HC_assignedPos"}}}) then {
        _x enableAI "PATH";
        _x setVariable ["BURNS_ownsPath",nil,true];
        _x setVariable ["FST_HC_assignedPos",nil];
    };
    _x doFollow leader _group;
} forEach units _group;
{_group setVariable [_x,nil,true]} forEach ["BURNS_stationSlots","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_holdReleased"];
if (_mode in ["enable_group","disable_group"]) exitWith {
    _group setVariable ["BURNS_exempt",_mode=="disable_group",true];
    if (!_wbk && {_mode=="disable_group"}) then {
        {[_x] call FST_HCSpawn_fnc_burnsRestoreRole} forEach units _group;
        _group enableAttack true;
        _group setSpeedMode "NORMAL";
        _group setVariable ["BURNS_b1GroupOwner",nil];
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
if (_wbk) exitWith {[_group,"assault",_pos,_radius] call FST_HCSpawn_fnc_setCombatTask};
_group setVariable ["BURNS_taskOptions",_options,true];
[_group,_mode,_pos,_radius] call FST_HCSpawn_fnc_setCombatTask
