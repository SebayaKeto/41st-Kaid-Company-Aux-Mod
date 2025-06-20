class CfgPatches
{
	class FST_PX10_41st
	{
		author = "Laer";
		requiredAddons[] =
		{
			"A3_Armor_F_Beta",
			"3AS_Main",
			"3AS_VehicleWeapons",
			"3AS_APC_Jug",
			"3AS_Animations"
		};
		units[] = { "FST_PX10_Tukata" };
		weapons[] = {};
	};
};

class CfgVehicles
{
	class 3AS_PX10_Base_F;

	class FST_PX10_Tukata : 3AS_PX10_Base_F
	{
		animationList[] = {"HideAttachmentDozer",1,"HideAttachmentFuel",1,"HideAttachmentPlate",0,"HideAttachmentRepair",1};
		scope = 2;
		scopeArsenal = 2;
		scopeCurator = 2;

		displayName = "PX-10  Tukata";
		author = "Laer";
		faction = "FST_Tukata_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 0;

		crew="FST_JMSLLTE_JinTrooper_armor_F";
		typicalCargo[] = { "FST_JMSLLTE_JinTrooper_armor_F" };

		hiddenSelections[] = 
		{
		"Camo", "camo2", "camo3", "camo_Fuel", "camo_repair"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\PX10\Data\PX10CAV_co.paa",                    // main hull
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintback_co.paa", // interior back
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintfront_co.paa",// interior front
		"3as\3as_rebel_armor\px10_cav\textures\px10fuel_co.paa",       // fuel module
		"3as\3as_rebel_armor\px10_cav\textures\px10crane_co.paa"       // repair module
		};
	};
};
