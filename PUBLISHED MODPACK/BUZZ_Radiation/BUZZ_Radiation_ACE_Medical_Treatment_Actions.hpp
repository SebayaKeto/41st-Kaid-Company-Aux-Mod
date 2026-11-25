// Custom ACE treatments
class ACE_Medical_Treatment_Actions {
    class Morphine;
    class SalineIV;
    class BUZZ_Radiation_Iodine: Morphine {
        displayName = "Give Iodine Tablet";
        displayNameProgress = "Giving iodine tablet...";
        items[] = {"BUZZ_Radiation_Iodine"};
        allowedSelections[] = {"Head"};
        treatmentTime = 4;
        medicRequired = 0;
        allowSelfTreatment = 1;
        condition = "true";
        callbackSuccess = "BUZZ_Radiation_fnc_treatIodine";
        sounds[] = {};
        litter[] = {};
    };

    class CheckPulse;
    class BUZZ_Radiation_CheckDose: CheckPulse {
        displayName = "Scan For Radiation";
        displayNameProgress = "Scanning for radiation...";
        items[] = {};
        treatmentTime = 3;
        medicRequired = 0;
        allowSelfTreatment = 1;
        // Scan for radiation
        condition = "[_this select 0, BUZZ_Radiation_monitorList] call BUZZ_Radiation_fnc_hasItem";
        callbackSuccess = "BUZZ_Radiation_fnc_checkDose";
    };

    // Radiation Flush IV
    class BUZZ_Radiation_FlushIV: SalineIV {
        displayName = "Give Radiation Flush IV";
        displayNameProgress = "Administering radiation flush...";
        items[] = {"BUZZ_Radiation_FlushIV"};
        treatmentTime = "BUZZ_Radiation_flushTime";
        treatmentTimeTrained = "BUZZ_Radiation_flushTime";
        medicRequired = "BUZZ_Radiation_flushMedic";
        treatmentLocations = "BUZZ_Radiation_flushLocation";
        allowSelfTreatment = "BUZZ_Radiation_flushSelf";
        condition = "true";
        callbackSuccess = "BUZZ_Radiation_fnc_treatFlush";
        litter[] = {};
    };
};
