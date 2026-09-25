params ["_group",["_b1Only",false],["_releaseStation",true]];
if (isNull _group || {!local _group} || {[_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup}) exitWith {};
{
    if (!_b1Only || {([_x] call FST_HCSpawn_fnc_burnsRole)=="b1"}) then {
        [_x,_releaseStation] call FST_HCSpawn_fnc_burnsRestoreRole;
    };
} forEach units _group;
// A group may have gained a WebKnight unit since its B1-only baseline was
// recorded. Do not apply group-wide behaviour/formation commands to that unit.
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight"})>=0) exitWith {
    {_group setVariable [_x,nil,true]} forEach ["BURNS_originalGroupRole","BURNS_originalFormation","BURNS_lastRoleFormation","BURNS_lastRoleSpeed","BURNS_b1GroupOwner"];
};
private _saved=_group getVariable ["BURNS_originalGroupRole",[]];
if (count _saved==3) then {
    if (speedMode _group==(_group getVariable ["BURNS_lastRoleSpeed","LIMITED"])) then {_group setSpeedMode (_saved select 0)};
    if (!attackEnabled _group) then {_group enableAttack (_saved select 1)};
    if (behaviour leader _group=="AWARE") then {_group setBehaviourStrong (_saved select 2)};
};
private _formation=_group getVariable ["BURNS_originalFormation",""];
if (_formation!="" && {formation _group==(_group getVariable ["BURNS_lastRoleFormation",""])}) then {_group setFormation _formation};
{if (!isNil {_group getVariable _x}) then {_group setVariable [_x,nil,true]}} forEach ["BURNS_originalGroupRole","BURNS_originalFormation","BURNS_lastRoleFormation","BURNS_lastRoleSpeed","BURNS_b1GroupOwner"];
