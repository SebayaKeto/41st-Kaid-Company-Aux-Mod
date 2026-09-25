// A renewable driver-only lease. Gunners keep their native combat behavior.
params ["_u",["_token",""],["_goal",[]],["_issue",false]];
if (isNull _u || {!local _u}) exitWith {};
if (_issue) exitWith {
    private _g=group _u;private _p=_g getVariable ["BURNS_sectionPlan",[]];
    if (count _p==4 && {(_p select 0)==_token} && {(_g getVariable ["BURNS_sectionToken",""])==_token} && {
        (_p select 1) distance2D _goal<1
    } && {time<=(_p select 3)} && {driver vehicle _u==_u} && {_u checkAIFeature "PATH"} && {_u checkAIFeature "MOVE"} && {
        [_g] call FST_HCSpawn_fnc_burnsEngagementAllowed
    } && {missionNamespace getVariable ["BURNS_ArmorSectionsEnabled",true]}) then {_u doMove _goal};
};
private _lease=_u getVariable ["BURNS_sectionDriver",[]];
private _localLease=_u getVariable ["BURNS_sectionDriverLocal",[]];
if (count _localLease==5 && {(_localLease select 4)==clientOwner}) then {_lease=_localLease select [0,4]};
if (_token=="") exitWith {
    if (count _lease==4) then {
        if ((_lease select 1) && {!(_u checkAIFeature "AUTOCOMBAT")}) then {_u enableAI "AUTOCOMBAT"};
        if (combatBehaviour _u=="AWARE") then {_u setCombatBehaviour (_lease select 2)};
        _u setVariable ["BURNS_sectionDriver",nil,true];
    };
    _u setVariable ["BURNS_sectionDriverLocal",nil];
    _u setVariable ["BURNS_sectionMove",nil];
    private _g=group _u;private _attack=_g getVariable ["BURNS_sectionAttack",[]];
    if (local _g && {count _attack==2}) then {
        if (!attackEnabled _g && {_attack select 1}) then {_g enableAttack true};
        _g setVariable ["BURNS_sectionAttack",nil,true];
    };
};
if (count _lease==4 && {(_lease select 0)!=_token}) then {[_u] call FST_HCSpawn_fnc_burnsArmorSectionDriver;_lease=[]};
if (count _lease==0) then {
    private _original=(group _u) getVariable ["BURNS_sectionOriginal",[]];
    private _hasOriginal=count _original>=4 && {(_original select 0)==_token} && {(_original select 1)==_u};
    _lease=[_token,if (_hasOriginal) then {_original select 2} else {_u checkAIFeature "AUTOCOMBAT"},if (_hasOriginal) then {_original select 3} else {combatBehaviour _u},time+6];
    _u disableAI "AUTOCOMBAT";_u setCombatBehaviour "AWARE";
};
_lease set [3,time+6];_u setVariable ["BURNS_sectionDriver",_lease,true];
_u setVariable ["BURNS_sectionDriverLocal",_lease+[clientOwner]];
private _g=group _u;
if (local _g && {count (_g getVariable ["BURNS_sectionAttack",[]])==0}) then {
    private _original=_g getVariable ["BURNS_sectionOriginal",[]];
    private _attack=if (count _original==5 && {(_original select 0)==_token}) then {_original select 4} else {attackEnabled _g};
    _g setVariable ["BURNS_sectionAttack",[_token,_attack],true];
    _g enableAttack false;
};
private _key=[clientOwner,_token,+_goal];
if (count _goal>=2 && {!((_u getVariable ["BURNS_sectionMove",[]]) isEqualTo _key)}) then {
    _u setVariable ["BURNS_sectionMove",_key];
    // Waypoint edits in this task tick must finish before the driver receives
    // the new leg. Otherwise it can retain its earlier commander destination.
    [{params ["_u","_token","_goal"];[_u,_token,_goal,true] call FST_HCSpawn_fnc_burnsArmorSectionDriver},[_u,_token,+_goal]] call CBA_fnc_execNextFrame;
};
