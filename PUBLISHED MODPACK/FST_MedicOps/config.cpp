// FST_MedicOps -- make medics' work visible and rewarded, on stock ACE.
// 1. Casualty beacons: downed players call a medic automatically; anyone can "Call Medic" from the ACE self menu.
// 2. Medic HUD: medics see casualty markers (severity colour, name, distance) on screen and on the map.
// 3. Medic report: per-medic patients, treatments, bacta heals, bleeds stopped, CPR revives, treatments under fire;
//    "Medic of the Op". Zeus module (Zen) shows it to everyone; logged to the server RPT at mission end.
// 4. Bacta Mist grenade (below). Nothing here changes damage or wounds. Every part has an Addon Options switch.

class CfgPatches {
    class FST_MedicOps {
        name = "FST Medic Ops";
        author = "41st Elite Corps";
        url = "";
        units[] = {"FST_MedicResupplyCrate"};
        weapons[] = {"FST_BactaCartridge", "FST_Medscanner", "FST_CardioStim", "FST_AdrenalStim"};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_settings", "ace_medical", "ace_medical_treatment", "ace_interact_menu", "A3_Weapons_F", "FST_Medical"};
        version = "1.2.0";
        magazines[] = {"FST_BactaMist"};
        ammo[] = {"FST_BactaMist_Ammo"};
    };
};

// 5. Consumable bacta (setting "Bacta charges per tank", default 0 = unlimited = today). When on, each use of the
//    41st bacta tank spends a charge; Bacta Cartridges reload it. The action keeps 41st_Medical's own condition and
//    adds only the charge check; the callback wraps ACE's normal full heal.
class ACE_medical_treatment_actions {
    class PersonalAidKit;
    class FST_Bacta_Tank: PersonalAidKit {
        condition = "([_this select 1] call ace_medical_status_fnc_isInStableCondition) && (speed (_this select 0) < 1) && {[_this select 0, 'has'] call FST_medOps_fnc_bactaCharge}";
        callbackSuccess = "FST_medOps_fnc_bactaUse";
    };
    // 6. Internal bleeding (setting chance, default 25% on heavy torso hits; 0 = off): hidden blood drain that survives
    //    bacta. Medic-only torso treatment; shows only while the patient actually has it.
    class BasicBandage;
    class FST_SealInternal: BasicBandage {
        displayName = "Seal Internal Bleeding (Coagulant Foam)";
        displayNameProgress = "Sealing internal bleeding...";
        icon = "\FST_MedicOps\ui\medscanner_ca.paa";
        category = "advanced";
        items[] = {"FST_CoagulantFoam"};
        consumeItem = 1;
        medicRequired = 1;
        allowSelfTreatment = 0;
        allowedSelections[] = {"Body"};
        condition = "(_patient getVariable ['FST_medOps_internal', 0]) > 0";
        treatmentTime = 8;
        callbackSuccess = "FST_medOps_fnc_sealInternal";
        litter[] = {};
    };
    class FST_CauterizeInternal: FST_SealInternal {
        displayName = "Cauterize Internal Bleeding";
        displayNameProgress = "Cauterizing internal bleeding...";
        items[] = {"IDA_Cauterizer"};
        consumeItem = 0;
        treatmentTime = 14;
    };
    // 8. Cardio-stim: medic-only 5 s shock for cardiac arrest (ACE's CPR success rule), 20 s recharge.
    class FST_CardioStimShock: FST_SealInternal {
        displayName = "Cardio-stim: Shock";
        displayNameProgress = "Charging... CLEAR!";
        icon = "\FST_MedicOps\ui\cardioStim_ca.paa";
        items[] = {"FST_CardioStim"};
        consumeItem = 0;
        condition = "(missionNamespace getVariable ['FST_medOps_cardioStimOn', true]) && {_patient getVariable ['ace_medical_inCardiacArrest', false]} && {(_medic getVariable ['FST_medOps_stimReady', -1]) < CBA_missionTime}";
        treatmentTime = 5;
        callbackSuccess = "FST_medOps_fnc_cardioStim";
    };
    // 9. Adrenal jolt: medic-only injector; unconscious (not in arrest, blood >= 3.8 L) -> up for 90 s, then crash
    //    unless stabilised. Once per patient per 10 minutes.
    class FST_AdrenalJolt: FST_SealInternal {
        displayName = "Adrenal Jolt";
        displayNameProgress = "Injecting adrenal stim...";
        icon = "\FST_MedicOps\ui\adrenalStim_ca.paa";
        items[] = {"FST_AdrenalStim"};
        consumeItem = 1;
        allowedSelections[] = {"Body", "LeftArm", "RightArm", "LeftLeg", "RightLeg"};
        condition = "(missionNamespace getVariable ['FST_medOps_joltOn', true]) && {_patient getVariable ['ACE_isUnconscious', false]} && {!(_patient getVariable ['ace_medical_inCardiacArrest', false])} && {(_patient getVariable ['ace_medical_bloodVolume', 6]) >= 3.8} && {(_patient getVariable ['FST_medOps_joltNext', -1]) < CBA_missionTime}";
        treatmentTime = 3;
        callbackSuccess = "FST_medOps_fnc_adrenalJolt";
    };
    // 10. Clone transfusion: any trooper gives 500 ml of their own blood (one blood type for every clone).
    class FST_CloneTransfusion: FST_SealInternal {
        displayName = "Clone Transfusion (give 500 ml)";
        displayNameProgress = "Transfusing your blood...";
        icon = "\FST_MedicOps\ui\cloneTransfusion_ca.paa";
        items[] = {};
        consumeItem = 0;
        medicRequired = 0;
        allowSelfTreatment = 0;
        allowedSelections[] = {"LeftArm", "RightArm"};
        condition = "(missionNamespace getVariable ['FST_medOps_transfusionOn', true]) && {_medic != _patient} && {(_medic getVariable ['ace_medical_bloodVolume', 6]) >= 5.5} && {!(_medic getVariable ['ACE_isUnconscious', false])} && {(_patient getVariable ['ace_medical_bloodVolume', 6]) < 5.9} && {(side group _medic) isEqualTo (side group _patient)}";
        treatmentTime = 12;
        callbackSuccess = "FST_medOps_fnc_cloneTransfusion";
    };
};

class CfgVehicles {
    class ACE_medicalSupplyCrate;
    class FST_MedicResupplyCrate: ACE_medicalSupplyCrate {
        scope = 2;
        scopeCurator = 2;
        displayName = "[41st] Medic Resupply Crate";
        author = "41st Elite Corps";
        class TransportMagazines {
            class _xx_FST_BactaMist { magazine = "FST_BactaMist"; count = 6; };
        };
        class TransportWeapons {};
        class TransportBackpacks {};
        class TransportItems {
            class _xx_FST_BactaCartridge { name = "FST_BactaCartridge"; count = 10; };
        };
    };
};

// 4. Bacta Mist grenade: teal smoke; for 30 s everyone in the cloud gets less pain and slower bleeding through an
//    ACE medication adjustment (pain suppression, peripheral resistance up). Trauma untouched, so durability is too.
class CfgAmmo {
    class SmokeShellGreen;
    class FST_BactaMist_Ammo: SmokeShellGreen {
        smokeColor[] = {0.3, 0.85, 0.85, 1};
    };
};

class CfgMagazines {
    class SmokeShellGreen;
    class FST_BactaMist: SmokeShellGreen {
        author = "41st Elite Corps";
        displayName = "Bacta Mist Grenade";
        displayNameShort = "Bacta Mist";
        descriptionShort = "Bacta aerosol. For 30 s everyone in the cloud has less pain and bleeds more slowly. Buys time; does not heal.";
        picture = "\FST_MedicOps\ui\bactaMist_ca.paa";
        ammo = "FST_BactaMist_Ammo";
        mass = 12;
    };
};

class CfgWeapons {
    class ACE_ItemCore;
    class CBA_MiscItem_ItemInfo;
    class FST_BactaCartridge: ACE_ItemCore {
        scope = 2;
        author = "41st Elite Corps";
        displayName = "Bacta Cartridge";
        picture = "\FST_MedicOps\ui\bactaCartridge_ca.paa";
        model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
        descriptionShort = "Refill for the bacta tank (when bacta charges are on). Self-interact: Reload Bacta Tank.";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 2;
        };
    };
    class FST_Medscanner: ACE_ItemCore {
        scope = 2;
        author = "41st Elite Corps";
        displayName = "Medscanner";
        picture = "\FST_MedicOps\ui\medscanner_ca.paa";
        model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
        descriptionShort = "Medic's handheld scanner. Interact with a casualty: Medscan. Shows vitals, wounds per body part, hidden internal bleeding and the right item for each wound.";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 3;
        };
    };
    class FST_CardioStim: ACE_ItemCore {
        scope = 2;
        author = "41st Elite Corps";
        displayName = "Cardio-stim";
        picture = "\FST_MedicOps\ui\cardioStim_ca.paa";
        model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
        descriptionShort = "Medic's defibrillator. Torso action on a patient in cardiac arrest: 5 s shock. Recharges in 20 s.";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 6;
        };
    };
    class FST_AdrenalStim: ACE_ItemCore {
        scope = 2;
        author = "41st Elite Corps";
        displayName = "Adrenal Stim";
        picture = "\FST_MedicOps\ui\adrenalStim_ca.paa";
        model = "\A3\Structures_F_EPA\Items\Medical\Bandage_F.p3d";
        descriptionShort = "Medic's one-use injector. Gets an unconscious trooper up for about 90 s. Patch them up before it wears off or they crash.";
        ACE_isMedicalItem = 1;
        class ItemInfo: CBA_MiscItem_ItemInfo {
            mass = 0.5;
        };
    };
    class GrenadeLauncher;
    class Throw: GrenadeLauncher {
        muzzles[] += {"FST_BactaMistMuzzle"};
        class SmokeShellGreenMuzzle;
        class FST_BactaMistMuzzle: SmokeShellGreenMuzzle {
            magazines[] = {"FST_BactaMist"};
        };
    };
};

class CfgFunctions {
    class FST_medOps {
        tag = "FST_medOps";
        class main {
            file = "FST_MedicOps\functions";
            class severity {};
            class setCall {};
            class casualtyTick {};
            class medicTick {};
            class onTreatment {};
            class serverStat {};
            class buildReport {};
            class mistTick {};
            class bactaCharge {};
            class bactaUse {};
            class internalWound {};
            class internalTick {};
            class sealInternal {};
            class medscan {};
            class cardioStim {};
            class adrenalJolt {};
            class joltLocal {};
            class joltTick {};
            class cloneTransfusion {};
        };
    };
};

class Extended_PreInit_EventHandlers {
    class FST_MedicOps {
        init = "call compile preprocessFileLineNumbers 'FST_MedicOps\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class FST_MedicOps {
        init = "call compile preprocessFileLineNumbers 'FST_MedicOps\XEH_postInit.sqf'";
    };
};
