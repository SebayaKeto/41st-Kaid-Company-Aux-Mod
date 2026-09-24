// Original human-only response to the engine's near-miss event. No world scan.
params ["_unit",["_distance",0],"_shooter","_instigator","_projectile","_ammo",["_ammoConfig",configNull]];
if (isNull _unit || {!local _unit} || {!alive _unit} || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) exitWith {false};
if ([group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
if !(missionNamespace getVariable ["BURNS_HumanSuppression",true]) exitWith {false};
if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) exitWith {false};
if (_unit getVariable ["BURNS_exempt",false] || {(group _unit) getVariable ["BURNS_exempt",false]}) exitWith {false};
if (!(_unit checkAIFeature "SUPPRESSION") || {([_unit] call FST_HCSpawn_fnc_burnsRole)!="human"}) exitWith {false};
if (time < (_unit getVariable ["BURNS_nextSuppressionEvent",-1])) exitWith {false};
_unit setVariable ["BURNS_nextSuppressionEvent",time+0.35];
if !(missionNamespace getVariable ["BURNS_suppressionStarted",false]) then {[] call FST_HCSpawn_fnc_initSuppression};
// Overflow keeps native suppression rather than adding unbounded work.
if (!(_unit in BURNS_SuppressedUnits) && {count BURNS_SuppressedUnits>=64}) exitWith {false};
private _strength=if (getNumber (_ammoConfig >> "indirectHit")>0) then {0.65} else {0.5-((_distance max 0 min 10)*0.025)};
_unit setVariable ["BURNS_suppressionPulse",[time,_strength]];
_unit setSuppression ((getSuppression _unit) max _strength);
BURNS_SuppressedUnits pushBackUnique _unit;
BURNS_SuppressionEvents=(missionNamespace getVariable ["BURNS_SuppressionEvents",0])+1;
true
