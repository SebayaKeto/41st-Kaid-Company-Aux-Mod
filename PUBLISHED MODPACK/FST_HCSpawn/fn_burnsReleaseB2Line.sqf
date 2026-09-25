// Release only our formation, rules of engagement, and outstanding leader goal.
params ["_g"];
if (isNull _g || {!local _g}) exitWith {};
private _saved=_g getVariable ["BURNS_b2Line",[]];
if (count _saved==0) exitWith {};
_saved params ["_formation","_mode","_direction","_writtenDir","_orders","_lead"];
if (formation _g=="LINE") then {_g setFormation _formation};
if (combatMode _g=="YELLOW") then {_g setCombatMode _mode};
if (!isNull _lead && {local _lead} && {alive _lead} && {!([_lead] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {
    if (abs(((formationDirection _lead)-_writtenDir+540)%360-180)<5) then {_lead setFormDir _direction};
};
{
    _x params ["_u","_goal"];
    if (!isNull _u && {local _u} && {alive _u} && {!([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)} && {
        currentCommand _u=="MOVE"
    } && {((expectedDestination _u) select 0) distance2D _goal<2} && {_u checkAIFeature "PATH"}) then {_u doMove getPosATL _u};
} forEach _orders;
_g setVariable ["BURNS_b2Line",nil,true];
_g setVariable ["BURNS_b2BoundNext",nil];
_g setVariable ["BURNS_b2Frame",nil,true];
