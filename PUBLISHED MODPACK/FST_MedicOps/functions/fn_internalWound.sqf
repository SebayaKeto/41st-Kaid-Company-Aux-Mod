// FST_medOps_fnc_internalWound
// ACE event "ace_medical_woundReceived", on the hit unit's machine. A heavy torso hit (>= 0.3) on a player may start
// hidden internal bleeding (setting FST_medOps_internalChance, 0 = off): a slow blood drain that survives bacta and
// is only found by checking vitals or with a medscanner. A medic seals it ("Seal Internal Bleeding").
// Arguments (ACE): 0: unit, 1: damages [[damage, bodyPart, ...], ...]

params ["_unit", "_allDamages"];
if (!local _unit || {!alive _unit}) exitWith {};
if (!isPlayer _unit && {!(missionNamespace getVariable ["FST_medOps_internalAI", false])}) exitWith {};   // test hook
private _chance = (missionNamespace getVariable ["FST_medOps_internalChance", 25]) / 100;
if (_chance <= 0 || {(_unit getVariable ["FST_medOps_internal", 0]) > 0}) exitWith {};
private _torso = 0;
{ if ((toLowerANSI (_x select 1)) == "body") then { _torso = _torso max (_x select 0); }; } forEach _allDamages;
if (_torso < 0.3 || {random 1 >= _chance}) exitWith {};
// 2-4 ml/s: about 4-7 minutes to drop a full trooper under bacta's 5.1 L
_unit setVariable ["FST_medOps_internal", 0.002 + random 0.002, true];
diag_log text format ["FST_medOps: internal bleeding started | %1 | torso hit %2", name _unit, _torso toFixed 2];
