// One E5 rifle per squad, real ammunition, bounded single-shot requests.
params ["_group"];
private _j=_group getVariable ["BURNS_pointFire",[]];
if (count _j==0) exitWith {};
_j params ["_unit","_target","_kind","_deadline","_revision","_wp","_wpPos","_originalSpeed","_owner"];
private _lease=_unit getVariable ["BURNS_pointFireLease",[]];
private _targetSide=if (_target isKindOf "CAManBase") then {side group _target} else {side _target};
private _abort=_owner!=clientOwner || {count _lease!=4} || {(_lease select 0)!=_owner} || {(_lease select 3)!=_deadline} || {!(missionNamespace getVariable ["BURNS_RifleAssistEnabled",true])} || {
    !([_group] call FST_HCSpawn_fnc_burnsEngagementAllowed)
} || {diag_tickTime>=_deadline} || {isNull _unit} || {!local _unit} || {!alive _unit} || {
    group _unit!=_group || {!alive _target} || {isObjectHidden _target}
} || {vehicle _unit!=_unit} || {[_unit] call FST_HCSpawn_fnc_burnsIsDown} || {
    _unit getVariable ["BURNS_exempt",false]
} || {currentWeapon _unit!="FST_E5"} || {currentMuzzle _unit!="FST_E5"} || {
    !(_unit checkAIFeature "PATH") || {!(_unit checkAIFeature "FIREWEAPON")} || {!(_unit checkAIFeature "WEAPONAIM")}
} || {currentWaypoint _group!=_wp} || {waypointPosition [_group,_wp] distance2D _wpPos>1} || {
    ([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet)!=_revision
} || {_targetSide in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _targetSide>=0.6};
if (_kind=="casualty") then {
    private _claim=_target getVariable ["BURNS_casualtyClaim",[]];
    _abort=_abort || {!([_target] call FST_HCSpawn_fnc_burnsIsDown)} || {vehicle _target!=_target} || {
        _target getVariable ["ace_captives_isHandcuffed",false]
    } || {_target getVariable ["ace_captives_isSurrendering",false]} || {
        count _claim!=3 || {(_claim select 0)!=_group} || {(_claim select 2)!=clientOwner}
    } || {_unit distance _target<4} || {_unit distance _target>30};
} else {
    private _range=if (fog>=0.4 && {missionNamespace getVariable ["BURNS_LowVisibilityAssist",false]}) then {missionNamespace getVariable ["BURNS_VisibleContactRange",125]} else {250};
    _abort=_abort || {captive _target} || {count crew _target==0} || {_unit distance _target<15} || {_unit distance _target>_range};
};
if (_abort) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleasePointFire};
// A newly assigned conscious infantry threat takes precedence immediately.
private _assigned=assignedTarget _unit;
private _nearEnemy=_unit findNearestEnemy _unit;
if (!isNull _nearEnemy && {_nearEnemy isKindOf "CAManBase"} && {vehicle _nearEnemy==_nearEnemy} && {
    !([_nearEnemy] call FST_HCSpawn_fnc_burnsIsDown)
} && {_unit distance _nearEnemy<60}) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleasePointFire};
if (!isNull _assigned && {_assigned!=_target} && {_assigned isKindOf "CAManBase"} && {
    !([_assigned] call FST_HCSpawn_fnc_burnsIsDown)
}) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleasePointFire};
private _point=aimPos _target;
if (([_unit,"VIEW",_target] checkVisibility [eyePos _unit,_point])<=0.5 || {
    ([_unit,"FIRE",_target] checkVisibility [eyePos _unit,_point])<=0.5
}) exitWith {[_group] call FST_HCSpawn_fnc_burnsReleasePointFire};
private _watch=ASLToAGL _point;
private _oldAim=_group getVariable ["BURNS_fireAim",[]];
if (count _oldAim==0 || {diag_tickTime-(_oldAim select 1)>=0.5 && {_watch distance (_oldAim select 0)>0.25}}) then {
    _unit doWatch _watch;
    _group setVariable ["BURNS_fireAim",[_watch,diag_tickTime]];
};
private _direction=vectorNormalized (_point vectorDiff eyePos _unit);
private _alignment=(vectorNormalized (_unit weaponDirection "FST_E5")) vectorDotProduct _direction;
private _last=_unit getVariable ["BURNS_lastAssistShot",-100];
private _requested=_group getVariable ["BURNS_pointFireRequest",-100];
if (diag_tickTime-_last>=1 && {diag_tickTime-_requested>=1} && {_alignment>cos (if (_kind=="casualty") then {3} else {1.5})} && {_unit ammo "FST_E5">0}) then {
    _group setVariable ["BURNS_pointFireRequest",diag_tickTime];
    BURNS_AssistShotRequests=(missionNamespace getVariable ["BURNS_AssistShotRequests",0])+1;
    _unit forceWeaponFire ["FST_E5","Single"];
};
