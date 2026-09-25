// Task intent only; WebKnight retains animation and damage handlers.
params ["_group","_mode","_centre","_radius"];
private _units=units _group select {alive _x};
if (count _units==0 || {(_units findIf {!(_x isKindOf "WBK_LS_BX") || {vehicle _x!=_x} || {!local _x} || {_x getVariable ["BURNS_exempt",false]}})>=0}) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleaseBX;false};
if !(_mode in ["creep","ambush","cqb"]) exitWith {false};
private _lead=leader _group;
private _target=objNull;
private _best=1e9;
private _range=if (_mode=="ambush") then {(_radius min 100) max 15} else {_radius min 300};
{
    _x params ["_pos","","_side","","_obj"];
    if (isNull _obj || {!alive _obj} || {!(_obj isKindOf "CAManBase")} || {vehicle _obj!=_obj} || {captive _obj} || {isObjectHidden _obj} || {(side _group) getFriend _side>=0.6} || {_side in [civilian,sideUnknown,sideLogic]} || {[_obj] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_lead distance2D _pos;
    if (_d<_best && {_lead knowsAbout _obj>=1} && {(_units findIf {_x distance2D _obj<=_range && {([_x,"VIEW",_obj] checkVisibility [eyePos _x,aimPos _obj])>0.5}})>=0}) then {_best=_d;_target=_obj};
} forEach (_lead nearTargets _range);
private _triggered=_group getVariable ["BURNS_ambushTriggered",false];
if (_mode=="ambush" && {!_triggered} && {!isNull _target}) then {
    _triggered=true;_group setVariable ["BURNS_ambushTriggered",true,true];
    diag_log format ["[BURNS_BX_AMBUSH] group=%1 target=%2 owner=%3",_group,netId _target,clientOwner];
};
private _holdFire=(_mode=="ambush" && {!_triggered}) || {_mode=="cqb" && {!isNull _target}};
private _wantedMode=if (_holdFire) then {"BLUE"} else {"RED"};
private _savedMode=_group getVariable ["BURNS_bxMode",[combatMode _group,_wantedMode]];
if (combatMode _group!=_wantedMode) then {_group setCombatMode _wantedMode};
if !((_group getVariable ["BURNS_bxMode",[]]) isEqualTo [_savedMode select 0,_wantedMode]) then {_group setVariable ["BURNS_bxMode",[_savedMode select 0,_wantedMode],true]};
{
    private _u=_x;
    private _stance=if (_mode=="creep" || {_mode=="ambush" && {!_triggered}}) then {"DOWN"} else {"UP"};
    if (!isNil {_u getVariable "BURNS_bxReleaseToken"}) then {_u setVariable ["BURNS_bxReleaseToken",nil,true]};
    private _saved=+(_u getVariable ["BURNS_bxOwned",[]]);
    if (count _saved==0) then {
        private _original=unitPos _u;
        private _released=_u getVariable ["BURNS_bxReleasedStance",[]];
        // A returning owner can retain its last local DOWN preference even
        // though the intervening owner restored AUTO. Keep the recorded baseline.
        if (count _released==2 && {_original==(_released select 1)}) then {_original=_released select 0};
        _saved=[_original,_u checkAIFeature "FIREWEAPON",_u checkAIFeature "PATH",_stance];
    };
    _saved set [3,_stance];if !((_u getVariable ["BURNS_bxOwned",[]]) isEqualTo _saved) then {_u setVariable ["BURNS_bxOwned",_saved,true]};
    // Never interrupt WebKnight's committed melee, roll or death animations.
    private _anim=toLower animationState _u;
    if (_anim in ["bx_droid_kick","bx_droid_sword","bx_droid_roll_1","bx_droid_roll_2"] || {!(_u checkAIFeature "ANIM")}) then {continue};
    if (unitPos _u!=_stance) then {_u setUnitPos _stance};
    if (_saved select 1) then {if (_holdFire) then {_u disableAI "FIREWEAPON"} else {_u enableAI "FIREWEAPON"}};
    private _hold=_mode=="ambush";
    if (_hold) then {
        if (_u checkAIFeature "PATH") then {doStop _u;_u disableAI "PATH";_u setVariable ["BURNS_bxPath",true,true]};
    } else {
        if (_u getVariable ["BURNS_bxPath",false]) then {_u enableAI "PATH";_u setVariable ["BURNS_bxPath",nil,true]};
        private _goal=+_centre;
        if (!isNull _target) then {_goal=getPosATL _target};
        if (_mode=="creep" && {!isNull _target} && {_best>60}) then {_goal=_goal getPos [45,_goal getDir getPosATL _u]};
        private _last=_u getVariable ["BURNS_bxGoal",[]];
        if (_u checkAIFeature "PATH" && {count _last==0 || {_last distance2D _goal>4} || {unitReady _u && {_u distance2D _goal>5}}}) then {_u doMove _goal;_u setVariable ["BURNS_bxGoal",_goal,true]};
    };
    if (!isNull _target) then {
        if (assignedTarget _u!=_target) then {_u doTarget _target};
        if (!_holdFire) then {_u doFire _target};
        if (_mode=="cqb" && {_u distance _target<3} && {time>=(_u getVariable ["BURNS_bxMeleeNext",-1])} && {((_u worldToModel getPosATL _target) select 1)>0} && {([_u,"FIRE",_target] checkVisibility [eyePos _u,aimPos _target])>0.7}) then {
            _u setVariable ["BURNS_bxMeleeNext",time+3];
            // Trigger the installed animation's existing hit handler exactly once.
            [_u,if (handgunWeapon _u!="") then {"bx_droid_sword"} else {"bx_droid_kick"}] remoteExec ["switchMove",0];
        };
    };
} forEach _units;
true
