// Radiation medical crate for the 41st modpack: the [41st] Medical Crate with radiation gear
// added, on the green 3AS large supply crate. Skipped automatically if 41st_Armor isn't loaded.
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
    class FST_MedicalCrate: FST_AmmoCrate {
        class TransportItems;
    };
    class FST_RadiationMedicalCrate: FST_MedicalCrate {
        displayName = "[41st] Radiation Medical Crate";
        model = "3as\3as_props\crates\models\supply_Large.p3d";
        hiddenSelections[] = {"camo1"};
        hiddenSelectionsTextures[] = {"3AS\3AS_Props\Crates\Data\Supply_Large_Green\Supply_Large_green_co.paa"};
        class TransportItems: TransportItems {
            class _xx_BUZZ_Radiation_Monitor { name = "BUZZ_Radiation_Monitor"; count = 3; };
            class _xx_BUZZ_Radiation_Iodine { name = "BUZZ_Radiation_Iodine"; count = 60; };
            class _xx_BUZZ_Radiation_FlushIV { name = "BUZZ_Radiation_FlushIV"; count = 15; };
        };
    };
};
