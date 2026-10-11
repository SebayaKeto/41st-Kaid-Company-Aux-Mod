// FST_medOps_fnc_adrenalJolt
// callbackSuccess of "Adrenal Jolt" (medic's machine; ACE has already consumed the injector). Sends the jolt to the
// patient's machine (joltLocal) and credits the medic.
// Arguments (ACE): 0: medic, 1: patient

params ["_medic", "_patient"];
["FST_medOps_jolt", [_patient, _medic], _patient] call CBA_fnc_targetEvent;
if (isPlayer _medic) then {
    ["FST_medOps_stat", [getPlayerUID _medic, name _medic, ["jolt"], getPlayerUID _patient]] call CBA_fnc_serverEvent;
};
