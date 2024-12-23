class CfgPatches {
    class FST_Clacker_41st {
        author = "Viz";
        name = "41st Custom M152 Clacker";
        requiredAddons[] = {
            "A3_data_F",
            "A3_anims_F",
            "A3_weapons_F"
        };
        weapons[] = {"FST_M152_Clacker"};
    };
};

class CfgWeapons {
    class ACE_ItemCore;
    class ACE_M26_Clacker: ACE_ItemCore {};

    class FST_M152_Clacker: ACE_M26_Clacker {
        displayName = "[41st] M152 Clacker";
        descriptionShort = "41st customized clacker with extended range.";
        scope = 2;
        model = "\z\ace\addons\explosives\data\ace_m57.p3d";
        picture = "\z\ace\addons\explosives\data\UI\MK26_Transmitter_ca.paa";
        ace_explosives_range = 6000;
        ace_explosives_wireLength = 500;
        ace_explosives_detTime = 0.5;

        ace_explosives_requiredSpecialist = 0;
        ace_explosives_setSafety = 1;
    };
};
