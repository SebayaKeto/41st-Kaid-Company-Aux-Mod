// FST_HCSpawn_fnc_emergencyStabilizeDroid
// Local-only emergency stabilizer for droid infantry. Safe to call repeatedly.

params ["_unit"];

if !(missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", false]) exitWith { false };
if (isNull _unit) exitWith { false };
if !(local _unit) exitWith { false };

// Classification moved to fn_isDroidUnit (cached per classname) so the 1.5s
// periodic scan and Killed handlers pay one hash lookup per unit instead of
// config reads + substring scans. Same detection logic as before.
if !([_unit] call FST_HCSpawn_fnc_isDroidUnit) exitWith { false };

_unit setVariable ["FST_HC_EmergencyDroidStabilized", true, false];
_unit setVariable ["FST_HC_DroidEmergencyLocality", clientOwner, false];

_unit setSpeaker "NoVoice";
_unit disableConversation true;
_unit setUnitTrait ["Medic", false];
_unit allowFleeing 0;

_unit setVariable ["ace_medical_medicalActivity", false, false];
_unit setVariable ["ace_medical_ai_lastFired", -999999, false];
_unit setVariable ["ace_medical_ai_lastHit", -999999, false];
_unit setVariable ["ace_medical_ai_treatmentStarted", false, false];
_unit setVariable ["ace_medical_isBeingCarried", false, false];
_unit setVariable ["ace_medical_isBeingDragged", false, false];

true
