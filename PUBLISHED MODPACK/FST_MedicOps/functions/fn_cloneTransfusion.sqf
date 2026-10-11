// FST_medOps_fnc_cloneTransfusion
// callbackSuccess of "Clone Transfusion (give 500 ml)" (donor's machine; the donor is whoever performs it). Every
// clone shares one blood type: the donor loses 0.5 L (it does not come back on its own: only fluids or bacta), the
// patient gains 0.5 L on their own machine. Credited in the medic report.
// Arguments (ACE): 0: donor, 1: patient

params ["_donor", "_patient"];
private _v = _donor getVariable ["ace_medical_bloodVolume", 6];
_donor setVariable ["ace_medical_bloodVolume", (_v - 0.5) max 3.0, true];
["FST_medOps_addBlood", [_patient, 0.5], _patient] call CBA_fnc_targetEvent;
if (isPlayer _donor) then {
    ["FST_medOps_stat", [getPlayerUID _donor, name _donor, ["transfusion"], getPlayerUID _patient]] call CBA_fnc_serverEvent;
};
if (hasInterface && {_donor == player}) then {
    hint format ["You gave 500 ml to %1. Your blood: %2 L (it will not come back until fluids or bacta).", name _patient, ((_v - 0.5) max 3.0) toFixed 1];
};
