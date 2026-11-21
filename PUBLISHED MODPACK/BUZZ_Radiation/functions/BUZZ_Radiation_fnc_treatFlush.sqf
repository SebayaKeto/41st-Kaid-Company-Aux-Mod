/*
 * ACE "Give Radiation Flush IV" callback (runs on the medic's machine).
 */
params ["_medic", "_patient"];
["BUZZ_Radiation_flushLocal", [_patient, _medic], _patient] call CBA_fnc_targetEvent;
