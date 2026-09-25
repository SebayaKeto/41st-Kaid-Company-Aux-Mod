// Server broker for an explicit Zeus-selected section; never recruits idle tanks.
params ["_groups","_goal",["_caller",2]];
if (!isServer || {!([_caller,"AAT section"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {false};
private _decline={params ["_reason"];if (_caller>2) then {("[BURNS] AAT section: "+_reason) remoteExec ["systemChat",_caller]};false};
if (count _groups<2 || {count _groups>3} || {count _goal<2}) exitWith {["select 2–3 nearby AAT crew groups, one tank per group."] call _decline};
if (!(missionNamespace getVariable ["BURNS_ArmorSectionsEnabled",true]) || {!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true])}) exitWith {false};
private _first=vehicle leader (_groups select 0);private _side=side (_groups select 0);
private _valid=(_groups findIf {
    private _g=_x;private _v=vehicle leader _g;private _d=driver _v;
    isNull _g || {side _g!=_side} || {!(_v isKindOf "FST_AAT")} || {!alive _v} || {!canMove _v} || {isNull _d} || {!simulationEnabled _v} || {
        _v distance2D _first>250
    } || {[_g] call FST_HCSpawn_fnc_isProtectedVehicleGroup} || {_g getVariable ["BURNS_exempt",false]} || {
        (_g getVariable ["FST_HC_heldBy",-1])!=-1
    } || {!(_d checkAIFeature "PATH")} || {!(_d checkAIFeature "MOVE")} || {
        (units _g findIf {alive _x && {vehicle _x!=_v}})>=0
    }
})<0;
if (!_valid) exitWith {["use movable AI AATs on the same side within 250 m; release external holds first."] call _decline};
if (isNil "BURNS_ArmorSections") then {BURNS_ArmorSections=[]};
if (count BURNS_ArmorSections>=8) exitWith {["eight sections are already active."] call _decline};
// Front-to-back ordering stays fixed for the life of this order.
private _rank=_groups apply {[vehicle leader _x distance2D _goal,str _x,_x]};_rank sort true;
_groups=_rank apply {_x select 2};
private _origin=getPosATL vehicle leader (_groups select 0);
private _heading=_origin getDir _goal;
private _token=format ["section:%1:%2",diag_tickTime,random 1e6];
// token, roster, objective, axis, origin, phase, plans, last plan, created, caller
BURNS_ArmorSections pushBack [_token,+_groups,+_goal,_heading,+_origin,"COLUMN",[],time-30,time,_caller];
{
    private _driver=driver vehicle leader _x;
    private _old=_driver getVariable ["BURNS_sectionDriver",[]];
    // Preserve the pre-section baseline across HC hops and section replacement.
    private _auto=if (count _old==4) then {_old select 1} else {_driver checkAIFeature "AUTOCOMBAT"};
    private _behaviour=if (count _old==4) then {_old select 2} else {combatBehaviour _driver};
    private _oldAttack=_x getVariable ["BURNS_sectionAttack",[]];
    private _attack=if (count _oldAttack==2) then {_oldAttack select 1} else {attackEnabled _x};
    _x setVariable ["BURNS_sectionOriginal",[_token,_driver,_auto,_behaviour,_attack],true];
    private _revision=(_x getVariable ["BURNS_orderRevision",0])+1;
    _x setVariable ["BURNS_orderRevision",_revision,true];
    ["BURNS_order",["assault",_x,_goal,500,[false,true,false,[],[],_token],_caller,0,_revision],groupOwner _x] call CBA_fnc_ownerEvent;
} forEach _groups;
if (isNil "BURNS_ArmorSectionPFH") then {
    BURNS_ArmorSectionPFH=[{[] call FST_HCSpawn_fnc_burnsArmorSectionsTick},2,[]] call CBA_fnc_addPerFrameHandler;
};
if (_caller>2) then {format ["[BURNS] %1 AATs: column advance, then a spaced firing line. Reset or a new task removes a tank from the section.",count _groups] remoteExec ["systemChat",_caller]};
true
