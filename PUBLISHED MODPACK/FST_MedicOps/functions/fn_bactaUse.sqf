// FST_medOps_fnc_bactaUse
// callbackSuccess of the 41st bacta tank action (replaces ace_medical_treatment_fnc_fullHeal): spend a charge when
// consumable bacta is on, then do ACE's normal full heal with the same arguments.
// Arguments (ACE): 0: medic, 1: patient, ...

params ["_medic"];
[_medic, "use"] call FST_medOps_fnc_bactaCharge;
_this call ace_medical_treatment_fnc_fullHeal;
