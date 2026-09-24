// Explicit Zeus Rush is a seek order, independent of native target knowledge.
// Shared across Rush groups on this owner; no prop/building/LOS searches and no
// per-unit handlers. Re-check life, allegiance and position on every query.
params ["_group"];
if (isNull _group || {!local _group}) exitWith {objNull};
if (diag_tickTime >= (missionNamespace getVariable ["BURNS_rushCacheUntil",-1])) then {
    BURNS_rushCandidates=allUnits select {_x isKindOf "CAManBase" && {!(_x isKindOf "HeadlessClient_F")}};
    BURNS_rushCacheUntil=diag_tickTime+2;
};
private _origin=getPosWorld leader _group;
private _side=side _group;
private _nearest=objNull;
private _distance=1e30;
private _anchor=(_group getVariable ["BURNS_taskOptions",[]]) param [4,[]];
private _radius=(([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet)) param [2,500];
{
    if (isNull _x || {!alive _x} || {isObjectHidden _x}) then {continue};
    private _down=[_x] call FST_HCSpawn_fnc_burnsIsDown;
    if ((captive _x && {!_down}) || {_x getVariable ["ace_captives_isHandcuffed",false]} || {_x getVariable ["ace_captives_isSurrendering",false]}) then {continue};
    if (_down) then {
        private _claim=_x getVariable ["BURNS_casualtyClaim",[]];
        if (count _claim==3 && {(_claim select 0)!=_group} && {!isNull (_claim select 0)} && {(_claim select 1)>time} && {groupOwner (_claim select 0)==(_claim select 2)}) then {continue};
    };
    private _targetSide=side group _x;
    if (_targetSide in [civilian,sideUnknown,sideLogic] || {_side getFriend _targetSide>=0.6}) then {continue};
    if (count _anchor>=2 && {_x distance2D _anchor>_radius}) then {continue};
    private _d=_origin distanceSqr (getPosWorld vehicle _x);
    if (_d<_distance) then {_distance=_d;_nearest=_x};
} forEach (missionNamespace getVariable ["BURNS_rushCandidates",[]]);
if ((([_group,["BURNS_rushTarget",objNull]] call FST_HCSpawn_fnc_burnsStateGet))!=_nearest) then {([_group,["BURNS_rushTarget",_nearest,true]] call FST_HCSpawn_fnc_burnsStateSet)};
_nearest
