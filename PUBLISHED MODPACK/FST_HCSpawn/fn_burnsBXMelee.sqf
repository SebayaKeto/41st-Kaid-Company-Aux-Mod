// Short, visible close-range commitments. WebKnight's installed animation
// handlers retain all hit timing, damage, sound, and death behavior.
params ["_u"];
if (isNull _u || {!local _u}) exitWith {};
private _g=group _u;
private _task=([_g,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
private _cqb=_task=="cqb";
private _owned=_u getVariable ["BURNS_bxCharge",[]];
private _allowed=alive _u && {vehicle _u==_u} && {_u isKindOf "FST_BX"} && {
    missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]
} && {missionNamespace getVariable ["BURNS_BXMeleeEnabled",true]} && {!(_u getVariable ["BURNS_exempt",false])} && {
    !(_g getVariable ["BURNS_exempt",false])
} && {(_g getVariable ["FST_HC_heldBy",-1])==-1} && {!([_u] call FST_HCSpawn_fnc_burnsIsDown)} && {
    (units _g findIf {[_x] call FST_HCSpawn_fnc_isPlayerControlledUnit})<0
} && {_u checkAIFeature "PATH"} && {_u checkAIFeature "ANIM"} && {_u checkAIFeature "TARGET"} && {
    _u checkAIFeature "AUTOTARGET"
} && {!(_task in ["ambush","creep","retreat","garrison","camp","defend"])} && {
    _cqb || {[_g] call FST_HCSpawn_fnc_burnsEngagementAllowed}
} && {_cqb || {count _owned>0} || {_u checkAIFeature "FIREWEAPON"}};
if (!_allowed) exitWith {[_u] call FST_HCSpawn_fnc_burnsReleaseBXCharge};
if (time<(_u getVariable ["BURNS_bxChargeRest",-1])) exitWith {};
if (count _owned>0 && {time>(_owned select 2)}) exitWith {[_u,true] call FST_HCSpawn_fnc_burnsReleaseBXCharge};
private _anim=toLower animationState _u;
// Includes wind-up, follow-through, hits, rolls, and future BX special states.
if (_anim find "bx_droid_"==0) exitWith {};
private _target=objNull;
private _best=12;
{
    _x params ["","","_side","","_obj"];
    if (isNull _obj || {!alive _obj} || {!(_obj isKindOf "CAManBase")} || {vehicle _obj!=_obj} || {captive _obj} || {isObjectHidden _obj} || {
        (side _g) getFriend _side>=0.6
    } || {(side _g) getFriend (side group _obj)>=0.6
    } || {_side in [civilian,sideUnknown,sideLogic]} || {[_obj] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_u distance _obj;
    if (_d<_best && {_u knowsAbout _obj>=1} && {([_u,"FIRE",_obj] checkVisibility [eyePos _u,aimPos _obj])>0.7}) then {
        _target=_obj;_best=_d;
    };
} forEach (_u nearTargets 12);
if (isNull _target) exitWith {[_u] call FST_HCSpawn_fnc_burnsReleaseBXCharge};
if (assignedTarget _u!=_target) then {_u doTarget _target};
if (!_cqb) then {
    private _goal=getPosATL _target;
    if (count _owned==0) then {
        _owned=[_target,_goal,time+8,_u checkAIFeature "FIREWEAPON",_u checkAIFeature "AUTOCOMBAT",behaviour _u,unitCombatMode _u,combatMode _g];
        _u disableAI "FIREWEAPON";
        _u disableAI "AUTOCOMBAT";
        _u setUnitCombatMode "BLUE";
        _u setCombatBehaviour "AWARE";
        _u doMove _goal;
    } else {
        if ((_owned select 1) distance2D _goal>1.5 || {unitReady _u && {_best>2.8}}) then {_u doMove _goal};
        _owned set [0,_target];_owned set [1,_goal];
    };
    if !((_u getVariable ["BURNS_bxCharge",[]]) isEqualTo _owned) then {_u setVariable ["BURNS_bxCharge",_owned,true]};
};
if (_best<3.2 && {time>=(_u getVariable ["BURNS_bxMeleeNext",-1])} && {((_u worldToModel getPosATL _target) select 1)>0}) then {
    _u setVariable ["BURNS_bxMeleeNext",time+2.2];
    // Keep pressure while actually landing attacks; abandon a stalled pursuit.
    if (count _owned>0) then {_owned set [2,time+8];_u setVariable ["BURNS_bxCharge",_owned,true]};
    [_u,true] call FST_HCSpawn_fnc_burnsBXMobility;
    [_u,if (handgunWeapon _u!="") then {"bx_droid_sword"} else {"bx_droid_kick"}] remoteExec ["switchMove",0];
};
