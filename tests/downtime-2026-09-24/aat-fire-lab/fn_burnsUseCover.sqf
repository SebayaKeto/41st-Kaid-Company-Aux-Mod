// Supplement native human cover AI only after a perceived combat contact.
// Shared area cache, one request per group per 45 seconds, at most two orders.
// No concealment/terrain sweep per soldier and no changes to B1/B2/BX tactics.
params ["_group","_contactPos"];
if !(missionNamespace getVariable ["BURNS_HumanBuildingCover",true]) exitWith {};
if (time<(_group getVariable ["BURNS_nextCover",-1])) exitWith {};
private _leader=leader _group;
if (_leader distance2D _contactPos>300 || {vehicle _leader!=_leader}) exitWith {};
private _scan=[getPosATL _leader,75] call FST_HCSpawn_fnc_burnsPositions;
if !(_scan select 0) exitWith {}; // Retry on next bounded group update.
_group setVariable ["BURNS_nextCover",time+45,true];
private _positions=(_scan select 1) select {_x distance2D _contactPos>20 && {_x distance _leader<60}};
if (count _positions==0) exitWith {}; // Native cover movement continues.
private _riflemen=(units _group) select {
    _x!=_leader && {local _x} && {alive _x} && {vehicle _x==_x} &&
    {!(_x getVariable ["BURNS_exempt",false])} && {_x checkAIFeature "PATH"} &&
    {([_x] call FST_HCSpawn_fnc_burnsRole)=="human"}
};
{
    if (count _positions==0) exitWith {};
    private _unit=_x;
    private _nearest=_positions select 0;
    {if (_unit distance _x<_unit distance _nearest) then {_nearest=_x}} forEach _positions;
    _unit doMove _nearest;
    _positions=_positions-[_nearest];
} forEach (_riflemen select [0,2]);
