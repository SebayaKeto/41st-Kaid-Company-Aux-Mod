// FST_HCSpawn_fnc_emergencyStabilizeDroid
// Local-only emergency stabilizer for droid infantry. Safe to call repeatedly.

params ["_unit"];

if !(missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", true]) exitWith { false };
if (isNull _unit) exitWith { false };
if !(local _unit) exitWith { false };
if (isPlayer _unit) exitWith { false };
if !(_unit isKindOf "CAManBase") exitWith { false };

private _class = typeOf _unit;
private _type = toLower _class;
private _display = toLower getText (configFile >> "CfgVehicles" >> _class >> "displayName");
private _faction = toLower getText (configFile >> "CfgVehicles" >> _class >> "faction");

private _typeHits = {(_type find _x) >= 0} count ["droid", "fst_b1", "fst_b2", "b1_", "b2_", "_b1", "_b2", "bx_droid", "commando_droid"];
private _displayHits = {(_display find _x) >= 0} count ["droid", "b1", "b2", "commando droid", "battle droid", "super battle"];
private _isDroid = (_typeHits > 0) || {_displayHits > 0} || {((_faction find "cis") >= 0 || {(_faction find "separatist") >= 0}) && {(_type find "droid") >= 0}};

if (!_isDroid) exitWith { false };

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
