// Owner decides; all peers receive the same coefficient. Never multiply a
// coefficient owned by WebKnight (notably its temporary 1.35 dodge recovery).
params ["_u",["_release",false],["_state",""]];
if (isNull _u || {!local _u}) exitWith {};
private _owned=_u getVariable ["BURNS_bxSpeedOwned",[]];
private _coef=getAnimSpeedCoef _u;
// AnimStateChanged can fire before animationState reflects the new state.
private _anim=toLower (if (_state=="") then {animationState _u} else {_state});
private _wanted=(missionNamespace getVariable ["BURNS_BXRunSpeed",1.15]) max 1 min 1.3;
private _running=(_anim find "amov"==0) && {(_anim find "mruns" >=0) || {_anim find "mevas" >=0}} && {_anim find "ppne"<0};
private _eligible=!_release && {alive _u} && {vehicle _u==_u} && {_running} && {_wanted>1.001} && {
    missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]
} && {!(_u getVariable ["BURNS_exempt",false])} && {!((group _u) getVariable ["BURNS_exempt",false])} && {
    !([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)
} && {!([_u] call FST_HCSpawn_fnc_burnsIsDown)};
if (count _owned>0 && {abs(_coef-(_owned select 0))>0.005 || {!_eligible} || {abs(_wanted-(_owned select 0))>0.005}}) then {
    _owned params ["_written","_jip"];
    if (abs(_coef-_written)<0.005) then {
        _u setAnimSpeedCoef 1;
        [_u,1] remoteExecCall ["setAnimSpeedCoef",0];
    };
    remoteExec ["",_jip];
    _u setVariable ["BURNS_bxSpeedOwned",nil,true];
    _owned=[];
    _coef=getAnimSpeedCoef _u;
};
if (_eligible && {count _owned==0} && {abs(_coef-1)<0.005}) then {
    private _jip="BURNS_BX_SPEED_"+netId _u;
    _u setVariable ["BURNS_bxSpeedOwned",[_wanted,_jip],true];
    _u setAnimSpeedCoef _wanted;
    [_u,_wanted] remoteExecCall ["setAnimSpeedCoef",0,_jip];
};
