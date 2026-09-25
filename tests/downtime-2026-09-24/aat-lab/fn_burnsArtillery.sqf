// Native artillery execution on the gun's owner; no invented shells or rearming.
params ["_group","_target",["_options",[]],["_caller",2]];
if (isNull _group || {!local _group}) exitWith {0};
private _held=_group getVariable ["FST_HC_heldBy",-1];
if (_group getVariable ["BURNS_exempt",false] || {_held!=-1 && {_held!=_caller || {_caller<3}}}) exitWith {
    "[BURNS] Fire order declined: group AI disabled or held by another Zeus." remoteExec ["systemChat",_caller];0
};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {0};
private _rounds=round (((_options param [0,4]) max 1) min 12);
private _dispersion=((_options param [1,50]) max 0) min 300;
private _guns=[];
{private _v=vehicle _x; if (_v!=_x && {alive _v} && {local _v} && {count getArtilleryAmmo [_v]>0}) then {_guns pushBackUnique _v}} forEach units _group;
private _fired=0;
{
    if (_fired>=4) exitWith {};
    private _gun=_x;
    private _ammo=getArtilleryAmmo [_gun];
    private _index=_ammo findIf {_target inRangeOfArtillery [[_gun],_x]};
    if (_index<0) then {continue};
    private _aim=_target getPos [random _dispersion,random 360];
    if !(_aim inRangeOfArtillery [[_gun],_ammo select _index]) then {_aim=+_target};
    _gun doArtilleryFire [_aim,_ammo select _index,_rounds];
    _fired=_fired+1;
} forEach _guns;
format ["[BURNS] Fire orders: %1 in-range local gun(s), %2 rounds each.",_fired,_rounds] remoteExec ["systemChat",_caller];
diag_log format ["[BURNS] artillery owner=%1 guns=%2 rounds=%3",clientOwner,_fired,_rounds];
_fired
