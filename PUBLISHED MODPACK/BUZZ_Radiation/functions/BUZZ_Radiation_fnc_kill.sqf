// Kills a unit from radiation poisoning
params ["_unit"];
if (!alive _unit) exitWith {};
// Damage disabled and Zeus protection
if (!isDamageAllowed _unit) exitWith {};
if (!isNull (_unit getVariable ["bis_fnc_moduleRemoteControl_owner", objNull])) exitWith {};
if (hasInterface && {_unit == player} && {!isNull findDisplay 312 || {!isNull (missionNamespace getVariable ["bis_fnc_moduleRemoteControl_unit", objNull])}}) exitWith {};
_unit setVariable ["ace_medical_causeOfDeath", "Radiation poisoning", true];
_unit setDamage 1;
