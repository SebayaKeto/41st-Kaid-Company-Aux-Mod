params ["_unit"];
if (isNull _unit || {!local _unit}) exitWith {};
private _group=group _unit;
// Cheap group throttle before the whole-squad eligibility check. Friendly
// nearby shots are filtered by the caller; no scan or per-bullet broadcast.
if (time<(_group getVariable ["BURNS_nextDangerEvent",-1])) exitWith {};
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {};
_group setVariable ["BURNS_nextDangerEvent",time+1];
// At most one danger renewal per second per group, not per bullet/unit/tick.
if (time>=(_group getVariable ["BURNS_b1DangerUntil",-1])-19) then {
    _group setVariable ["BURNS_b1DangerUntil",time+20,true];
};
[_group] call FST_HCSpawn_fnc_burnsB1Formation;
_group setVariable ["FST_HC_taskNext",-1];
