// Shared bounded reaction service. Uses native perceived contacts, never allUnits.
// Station scans change attention only: PATH and the assigned position stay intact.
params ["_group"];
if (!([_group] call FST_HCSpawn_fnc_burnsEngagementAllowed)) exitWith {};
private _units=units _group select {alive _x && {local _x} && {vehicle _x==_x} && {!(_x getVariable ["BURNS_exempt",false])}};
if (count _units==0) exitWith {};
private _cursor=(_group getVariable ["BURNS_reactionCursor",0]) mod count _units;
_group setVariable ["BURNS_reactionCursor",_cursor+1];
private _u=_units select _cursor;
private _role=[_u] call FST_HCSpawn_fnc_burnsRole;
if !(_role in ["b1","webknight"]) exitWith {};
if (_role=="webknight" && {!(_u isKindOf "WBK_LS_BX")}) exitWith {};
private _task=([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
if (_task in ["ambush","cqb"] && {_role=="webknight"}) exitWith {};
if (!(_u checkAIFeature "TARGET") || {!(_u checkAIFeature "AUTOTARGET")} || {!(_u checkAIFeature "FIREWEAPON")}) exitWith {};
private _contacts=_u nearTargets 250;
private _target=objNull;
private _best=1e9;
{
    _x params ["_pos","","_side","","_obj"];
    if (isNull _obj || {!alive _obj} || {captive _obj} || {isObjectHidden _obj} || {_side in [civilian,sideUnknown,sideLogic]} || {(side _group) getFriend _side>=0.6}) then {continue};
    private _platform=vehicle _obj;
    if (_platform isKindOf "Air" || {[_obj] call FST_HCSpawn_fnc_burnsIsDown}) then {continue};
    private _d=_u distance2D _pos;
    if (_d<_best && {_u knowsAbout _obj>=1} && {([_u,"VIEW",_platform] checkVisibility [eyePos _u,aimPos _platform])>0.5}) then {_best=_d;_target=_platform};
} forEach _contacts;
if (!isNull _target) exitWith {
    _u setVariable ["BURNS_scanNext",time+8];
    if (!isNil {_u getVariable "BURNS_scanWatch"}) then {_u doWatch objNull;_u setVariable ["BURNS_scanWatch",nil]};
    // Select a carried AT launcher at close armor contact; native AI still owns
    // ammunition choice, friendly-fire safety, aim and actual launch timing.
    if (_target isKindOf "LandVehicle" && {!(_target isKindOf "StaticWeapon")} && {_best>=15} && {_best<=150} && {secondaryWeapon _u!=""} && {_u ammo secondaryWeapon _u>0}) then {
        _u selectWeapon secondaryWeapon _u;
    };
    if (assignedTarget _u!=_target) then {_u doTarget _target;_u doFire _target};
};
private _station=(_u getVariable ["FST_HC_ownsPath",false]) || {_u getVariable ["BURNS_ownsPath",false]};
if (!_station || {_u checkAIFeature "PATH"} || {!isNull assignedTarget _u} || {time<(_u getVariable ["BURNS_scanNext",-1])}) exitWith {};
// Quarter-turns avoid asking a PATH-held rifleman to look directly behind his
// body, which can leave attention stuck at the neck's turning limit.
private _sector=(_u getVariable ["BURNS_scanSector",((round(getDir _u/90))+1) mod 4]);
_u setVariable ["BURNS_scanSector",(_sector+1) mod 4];
_u setVariable ["BURNS_scanNext",time+4];
private _look=(getPosATL _u) getPos [60,_sector*90];
_look set [2,(getPosATL _u select 2)+1.5];
_u setFormDir (_sector*90);
_u doWatch _look;
_u setVariable ["BURNS_scanWatch",_look];
