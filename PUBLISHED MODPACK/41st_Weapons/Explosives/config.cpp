class CfgPatches {
    class FST_Clacker_41st 
	{
        author = "Viz";
        name = "41st Custom M152 Clacker";
        requiredAddons[] = 
		{
			"ace_interaction",
			"ace_explosives"
		};
        weapons[] = {
			"FST_M152_Clacker"
		};
        units[] = {};
    };
};

class CfgWeapons {
	class ACE_ItemCore;
	class ACE_Clacker: ACE_ItemCore{};
    class FST_M152_Clacker: ACE_Clacker {
		author="Viz";
		picture="\z\ace\addons\explosives\Data\UI\MK26_Transmitter_ca.paa";
        displayName = "[41st] M152 Clacker";
        descriptionShort = "41st customized clacker with extended range.";
		scope=2;
		scopeCurator=2;
		scopearsenal=2;
		ace_explosives_triggerType="MK16_Transmitter";
        ace_explosives_range = 6000;
        ace_explosives_wireLength = 500;
        ace_explosives_detTime = 0.5;
    };
};
