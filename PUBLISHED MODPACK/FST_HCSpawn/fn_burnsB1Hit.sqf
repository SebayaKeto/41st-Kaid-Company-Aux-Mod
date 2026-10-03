params ["_unit"];
if (isNull _unit || {!local _unit}) exitWith {};
private _group=group _unit;
// Cheap group throttle before the whole-squad eligibility check. Friendly
// nearby shots are filtered by the caller; no scan or per-bullet broadcast.
if (time<(_group getVariable ["BURNS_nextDangerEvent",-1])) exitWith {};
if !([_group] call FST_HCSpawn_fnc_burnsB1Eligible) exitWith {};
_group setVariable ["BURNS_nextDangerEvent",time+1];
// Public renewal only in the last 5 s of the 20 s window (~1 broadcast per 15 s
// per group in contact, was ~1/s). LINE stays held; the window never lapses.
if (time>=(_group getVariable ["BURNS_b1DangerUntil",-1])-5) then {
    _group setVariable ["BURNS_b1DangerUntil",time+20,true];
};
[_group] call FST_HCSpawn_fnc_burnsB1Formation;
_group setVariable ["FST_HC_taskNext",-1];
