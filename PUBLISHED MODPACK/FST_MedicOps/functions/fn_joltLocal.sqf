// FST_medOps_fnc_joltLocal
// Adrenal jolt, on the PATIENT's machine (CBA target event "FST_medOps_jolt"). Forces the unconscious patient awake
// for 90 s the way ACE moves states itself (manual statemachine transition Unconscious -> Injured with ACE's own
// wake-up step), with a strong pain suppression / heart-rate boost. joltTick decides at the end: stabilised = fine,
// not stabilised = crash (knocked out 60 s+, extra pain).
// Arguments: 0: patient, 1: medic

params ["_patient", "_medic"];
if (!local _patient || {!alive _patient}) exitWith {};
if !(_patient getVariable ["ACE_isUnconscious", false]) exitWith {};
_patient setVariable ["FST_medOps_jolt", CBA_missionTime + 90, true];
_patient setVariable ["FST_medOps_joltNext", CBA_missionTime + 600, true];
[_patient, "FST_AdrenalJolt", 2, 90, 25, 0.8, 0, 0] call ace_medical_status_fnc_addMedicationAdjustment;
private _state = [_patient, ace_medical_STATE_MACHINE] call CBA_statemachine_fnc_getCurrentState;
if (_state == "Unconscious") then {
    [_patient, ace_medical_STATE_MACHINE, "Unconscious", "Injured",
        { [_this, false] call ace_medical_status_fnc_setUnconsciousState }, "FST_AdrenalJolt"] call CBA_statemachine_fnc_manualTransition;
};
if (hasInterface && {_patient == player}) then {
    titleText ["<t color='#ffd060' size='1.4'>ADRENAL JOLT</t><br/><t color='#ffd060'>You have about 90 seconds. Get treated or you will crash.</t>", "PLAIN", 0.5, true, true];
    addCamShake [6, 1.2, 20];
};
diag_log text format ["FST_medOps: adrenal jolt | %1 by %2 | state was %3", name _patient, name _medic, _state];
