params ["_u",["_pause",false]];
if (isNull _u || {!local _u}) exitWith {};
private _owned=_u getVariable ["BURNS_bxCharge",[]];
if (count _owned>0) then {
    _owned params ["_target","_goal","_until","_fire","_autoCombat","_behaviour","_mode","_groupMode"];
    if (unitCombatMode _u=="BLUE") then {_u setUnitCombatMode (if (combatMode group _u==_groupMode) then {_mode} else {combatMode group _u})};
    if (_fire && {!(_u checkAIFeature "FIREWEAPON")}) then {_u enableAI "FIREWEAPON"};
    if (behaviour _u=="AWARE") then {_u setCombatBehaviour _behaviour};
    if (_autoCombat && {!(_u checkAIFeature "AUTOCOMBAT")}) then {_u enableAI "AUTOCOMBAT"};
    if (alive _u && {_u checkAIFeature "PATH"} && {currentCommand _u=="MOVE"} && {
        ((expectedDestination _u) select 0) distance2D _goal<2
    } && {!([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {_u doMove getPosATL _u};
    _u setVariable ["BURNS_bxCharge",nil,true];
};
if (_pause) then {_u setVariable ["BURNS_bxChargeRest",time+3]};
