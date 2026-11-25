// Bacta Tank radiation limit
class CfgPatches {
    class BUZZ_Radiation_Compat_FSTMedical {
        name = "BUZZ_Radiation FST Medical";
        author = "Connor";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.14;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"BUZZ_Radiation_main", "FST_Medical"};
    };
};

class ACE_Medical_Treatment_Actions {
    class BasicBandage;
    class PersonalAidKit: BasicBandage {};
    class FST_Bacta_Tank: PersonalAidKit {
        condition = "([_this select 1] call ace_medical_status_fnc_isInStableCondition) && {speed (_this select 0) < 1} && {((_this select 1) getVariable ['BUZZ_Radiation_dose', 0]) < (missionNamespace getVariable ['BUZZ_Radiation_pakMaxDose', 25])}";
    };
};
