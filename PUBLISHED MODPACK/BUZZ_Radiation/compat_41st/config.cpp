// Radiation medical crate for the 41st modpack: the [41st] Medical Crate's contents plus radiation
// gear, on the green 3AS large supply crate. Skipped automatically if 41st_Armor isn't loaded.
class CfgPatches {
    class BUZZ_Radiation_Compat_41st {
        name = "BUZZ_Radiation 41st Crates";
        author = "Connor";
        units[] = {"FST_RadiationMedicalCrate"};
        weapons[] = {};
        requiredVersion = 2.14;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {"BUZZ_Radiation_main", "41st_Addon"};
    };
};

class CfgVehicles {
    class FST_AmmoCrate;
    class FST_MedicalCrate;
    class FST_RadiationMedicalCrate: FST_MedicalCrate {
        displayName = "[41st] Radiation Medical Crate";
        model = "3as\3as_props\crates\models\supply_Large.p3d";
        hiddenSelections[] = {"camo1"};
        hiddenSelectionsTextures[] = {"3AS\3AS_Props\Crates\Data\Supply_Large_Green\Supply_Large_green_co.paa"};
        // Written out in full: the game doesn't fill a crate from inherited item entries.
        // Keep the first nine lines in step with FST_MedicalCrate (41st_Armor).
        class TransportItems {
            class _xx_IDA_BactaBandage { name = "IDA_BactaBandage"; count = 200; };
            class _xx_ACE_PlasmaIV { name = "ACE_PlasmaIV"; count = 20; };
            class _xx_ACE_PlasmaIV_500 { name = "ACE_PlasmaIV_500"; count = 20; };
            class _xx_IDA_BattleStim { name = "IDA_BattleStim"; count = 50; };
            class _xx_ACE_Adenosine { name = "ACE_Adenosine"; count = 50; };
            class _xx_ACE_Splint { name = "ACE_Splint"; count = 30; };
            class _xx_ACE_tourniquet { name = "ACE_tourniquet"; count = 40; };
            class _xx_IDA_Cauterizer { name = "IDA_Cauterizer"; count = 5; };
            class _xx_FST_Bacta_Tank { name = "FST_Bacta_Tank"; count = 5; };
            class _xx_BUZZ_Radiation_Monitor { name = "BUZZ_Radiation_Monitor"; count = 3; };
            class _xx_BUZZ_Radiation_Iodine { name = "BUZZ_Radiation_Iodine"; count = 60; };
            class _xx_BUZZ_Radiation_FlushIV { name = "BUZZ_Radiation_FlushIV"; count = 15; };
        };
    };
};
