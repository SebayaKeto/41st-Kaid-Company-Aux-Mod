// ACE "Give Radiation Flush IV" callback
params ["_medic", "_patient"];
["BUZZ_Radiation_flushLocal", [_patient, _medic], _patient] call CBA_fnc_targetEvent;
