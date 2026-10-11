// FST_medOps_fnc_cardioStim
// callbackSuccess of "Cardio-stim (shock)" (medic's machine). Fires the shock: zap for everyone nearby, flash + jolt
// for the patient, then ACE's own CPR success rule on the patient's machine (ace_medical_treatment_cprLocal: same
// chance as CPR, same SpO2 handling). 20 s recharge on the medic. The revive is credited through the patient's
// CPRSucceeded handler (FST_medOps_lastStimBy).
// Arguments (ACE): 0: medic, 1: patient

params ["_medic", "_patient"];
_medic setVariable ["FST_medOps_stimReady", CBA_missionTime + 20, true];
_patient setVariable ["FST_medOps_lastStimBy", [_medic, CBA_missionTime], true];
playSound3D ["A3\Sounds_F\weapons\mines\electron_trigger_1.wss", _patient, false, getPosASL _patient, 4, 0.8, 40];
["FST_medOps_stimFx", [_patient, _medic]] call CBA_fnc_globalEvent;
["ace_medical_treatment_cprLocal", [_medic, _patient], _patient] call CBA_fnc_targetEvent;
