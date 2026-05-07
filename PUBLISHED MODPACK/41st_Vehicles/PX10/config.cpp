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
		units[] = { "FST_PX10_Tukata", "FST_PX10_CIS", "FST_PX10_Gray", "FST_PX10_PDF" };
		weapons[] = {};
	};
};

class CfgVehicles
{
	class 3AS_PX10_Base_F
    {
        class HitPoints
        {
            class HitHull;
            class HitFuel;
            class HitEngine;
            class HitLTrack;
            class HitRTrack;
        };
    };
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
		armor=94;
		armorStructural=1;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.12;
			};
			class HitEngine: HitEngine
			{
				armor=0.75;
				material=-1;
				name="motor";
				convexComponent="Hit_engine";
				passThrough=0.2;
				minimalHit=0.23999999;
				explosionShielding=0.2;
				radius=0.33000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=3;
				material=-1;
				name="pas_L";
				passThrough=1;
				minimalHit=0;
				explosionShielding=1.4400001;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=3;
				material=-1;
				name="pas_P";
				convexComponent="Hit_Fuel";
				passThrough=1;
				minimalHit=0;
				explosionShielding=1.4400001;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=1.5;
				material=-1;
				name="palivo";
				passThrough=0.1;
				minimalHit=0.1;
				explosionShielding=0.60000002;
				radius=0.25;
			};
		};
	};
	class FST_PX10_CIS : FST_PX10_Tukata
	{
		displayName = "PX-10 CIS";
		author = "Steel";
		faction = "FST_BattleDroids_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 0;

		crew="FST_Droid_B1_OOM";
		typicalCargo[] = { "FST_Droid_B1_OOM" };

		hiddenSelections[] = 
		{
		"Camo", "camo2", "camo3", "camo_Fuel", "camo_repair"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\PX10\Data\FST_PX10CAV_CIS_CO.paa",                    // main hull
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintback_co.paa", // interior back
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintfront_co.paa",// interior front
		"3as\3as_rebel_armor\px10_cav\textures\px10fuel_co.paa",       // fuel module
		"3as\3as_rebel_armor\px10_cav\textures\px10crane_co.paa"       // repair module
		};
	};
	class FST_PX10_Gray : FST_PX10_Tukata
	{
		displayName = "PX-10 Gray";
		author = "Steel";
		faction = "FST_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 1;

		crew="FST_P2_Recruit";
		typicalCargo[] = { "FST_P2_Recruit" };

		hiddenSelections[] = 
		{
		"Camo", "camo2", "camo3", "camo_Fuel", "camo_repair"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\PX10\Data\FST_PX10CAV_plain_CO.paa",                    // main hull
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintback_co.paa", // interior back
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintfront_co.paa",// interior front
		"3as\3as_rebel_armor\px10_cav\textures\px10fuel_co.paa",       // fuel module
		"3as\3as_rebel_armor\px10_cav\textures\px10crane_co.paa"       // repair module
		};
	};
	class FST_PX10_PDF : FST_PX10_Tukata
	{
		displayName = "PX-10 PDF";
		author = "Steel";
		faction = "FST_BattleDroids_Faction";
		editorSubcategory = "FST_Ground_Vehicle";
		side = 0;

		crew="JLTS_Droid_B1_Prototype";
		typicalCargo[] = { "JLTS_Droid_B1_Prototype" };

		hiddenSelections[] = 
		{
		"Camo", "camo2", "camo3", "camo_Fuel", "camo_repair"
		};
		hiddenSelectionsTextures[] = {
		"\41st_Vehicles\PX10\Data\FST_PX10CAV_pdf_CO.paa",                    // main hull
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintback_co.paa", // interior back
		"3as\3as_rebel_armor\px10_cav\textures\px10cavintfront_co.paa",// interior front
		"3as\3as_rebel_armor\px10_cav\textures\px10fuel_co.paa",       // fuel module
		"3as\3as_rebel_armor\px10_cav\textures\px10crane_co.paa"       // repair module
		};
	};
};
