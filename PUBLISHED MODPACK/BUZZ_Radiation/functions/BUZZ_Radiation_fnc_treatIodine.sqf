/*
 * ACE treatment callback (runs on the medic's machine).
 */
params ["_medic", "_patient"];
["BUZZ_Radiation_iodineLocal", [_patient, _medic], _patient] call CBA_fnc_targetEvent;
