// FST_medOps_fnc_sealInternal
// callbackSuccess of "Seal / Cauterize Internal Bleeding" (medic's machine). Clears the patient's internal bleed.
// Arguments (ACE): 0: medic, 1: patient

params ["_medic", "_patient"];
_patient setVariable ["FST_medOps_internal", 0, true];
if (hasInterface && {_medic == player}) then { hint format ["Internal bleeding sealed: %1", name _patient]; };
diag_log text format ["FST_medOps: internal bleeding sealed | %1 by %2", name _patient, ["?", name _medic] select !isNull _medic];
