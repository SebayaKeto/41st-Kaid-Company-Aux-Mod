params ["_group","_contacts"];
if !(missionNamespace getVariable ["BURNS_ArmorAssistEnabled",true]) exitWith {};
private _v=vehicle leader _group;
if (!(_v isKindOf "FST_AAT") || {!local _v} || {!alive _v} || {!canFire _v}) exitWith {};
if ((units _group findIf {alive _x && {vehicle _x!=_v}})>=0) exitWith {};
private _driver=driver _v;
private _gunner=gunner _v;
if (isNull _gunner || {!local _gunner} || {!alive _gunner} || {_gunner getVariable ["BURNS_exempt",false]}) exitWith {};
// Inherited on-foot role writes must not disable a newly boarded crew's AI.
private _target=objNull;
private _best=1e12;
{
    _x params ["_pos","_type","_side","_cost","_object"];
    if (isNull _object || {!alive _object} || {captive _object} || {isObjectHidden _object} || {_side in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _side>=0.6}) then {continue};
    private _platform=vehicle _object;
    if (_platform isKindOf "Air" || {[_object] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_v distance2D _pos;
    if (_d<_best) then {_target=_platform;_best=_d};
} forEach _contacts;
if (isNull _target) exitWith {};
private _point=aimPos _target;
if (([_v,"VIEW",_target] checkVisibility [eyePos _gunner,_point])<=0.5) exitWith {};
if (_gunner checkAIFeature "TARGET" && {_gunner checkAIFeature "AUTOTARGET"} && {_gunner checkAIFeature "FIREWEAPON"}) then {
    if (assignedTarget _gunner!=_target) then {_gunner doTarget _target};
    _gunner doFire _target;
};
