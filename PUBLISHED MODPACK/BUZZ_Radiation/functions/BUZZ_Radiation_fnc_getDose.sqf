/*
 * Returns a unit's absorbed dose, 0-100 (100 = death).
 * Example: [player] call BUZZ_Radiation_fnc_getDose;
 */
params [["_unit", objNull, [objNull]]];
_unit getVariable ["BUZZ_Radiation_dose", 0]
