class CfgPatches
{
	class 41st_Addon
	{
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_anims_F",
			"A3_Weapons_F",
			"A3_Characters_F",
			"IDA_Ammo",
			"IDA_Republic",
			"A3_Characters_F_Proxies",
			"TCGM_Girls"
		};
		units[]=
		{
			//////////CLONES//////////
			"FST_P2_NCO_Jorge",
			"FST_P2_JARC",
			"FST_Commando",
			"FST_Commando_Jorge",
			"FST_Trooper_Blank",
			"FST_Trooper_P2_DC15S",
			"FST_Trooper_P2_DC15A",
			"FST_Trooper_P2_SL",
			"FST_Trooper_P2_Grenadier",
			"FST_Trooper_P2_EOD",
			"FST_Trooper_P2_HeavyGunner",
			"FST_Trooper_P2_AT",
			"FST_Trooper_P2_ATLite",
			"FST_Trooper_P2_SCT",
			"FST_Trooper_P2_VCT",
			"FST_Trooper_P2_SCT_Medic",
			"FST_Trooper_P2_VCT_Medic",
			"FST_Trooper_P2_CLC",
			"FST_Trooper_P2_CPL",
			"FST_Trooper_P2_CS",		
			"FST_Trooper_P2_CSS",	
			"FST_Trooper_P2_CL",				
			"FST_Trooper_ARF",
			"FST_Trooper_ARF_Urban",
			"FST_Trooper_ARF_WhiteGreen",
			"FST_Trooper_SERE",
			"FST_GM_Base_Plastic_Sarlacc",
			"FST_GM_Base_Plastic_Wampa",
			"FST_GM_Base_Plastic_Krayt",
			"FST_GM_Base_Plastic_Nexu",
			"FST_GM_Base_Plastic_Radark",
			"FST_GM_Base_Plastic_Zillo",
			"FST_GM_Base_Plastic_Kadoshi",
			"FST_GM_Base_Plastic_Rancor",
			"FST_GM_Base_Plastic_Sanval",
			"FST_GM_Base_Plastic_Hydra",
			"FST_GM_Base_Plastic_Uvak",
			"FST_GM_Base_Plastic_Howler",
			"FST_GM_Base_Plastic_Voxyn",
			"FST_GM_Base_Plastic_Raxshir",
			"FST_GM_Base_Plastic_Gharzr",
			"FST_GM_Base_Plastic_Varactyl",
			// "FST_Trooper_ARF_Medic",
			"FST_Trooper_Crewman",
			"FST_Trooper_Medic",
			"FST_Pilot_P1",
			"FST_Airborne",
			"FST_Arc_Trooper_P2",
			"FST_bodyGlove",
			"FST_Trooper_P1",
			"FST_Trooper_P1_CMDR",	
			"FST_Trooper_P1_CPT",
			"FST_Trooper_P1_LT",
			"FST_Trooper_P1_SGT",	
			"FST_Trooper_P1_41st",		
			"FST_ARF_Desert",
			// "FST_ARF_Woodland", 
			"FST_Jedi",
			"FST_DarkJedi",
			"FST_Zombie_Bloody",
			"FST_clone_scout_Desert",
			"FST_clone_scout_Midnight",
			"FST_clone_scout_Woodland",
			"FST_clone_scout_Urban",
			"FST_P2_Officer",
			"FST_P2_NCO",
			"FST_P2_Recruit",
			//////////CUSTOM//////////
			// "FST_P2_Shockcap",
			//"FST_P2_Jaws",
			//////////OTHERS//////////
			"FST_ReinsertTerminal",
			"FST_AmmoCrate",
			"FST_MedicalCrate",
			"FST_ExplosiveCrate",
			"FST_ExplodeFuelBarrel_1",
			"FST_ExplodeFuelBarrel_2"
		};
		weapons[]={};
	};
	author="Daara";
};
class CfgEditorSubcategories
{
	class FST_Subfaction
	{
		displayName="41st Clone Troopers";
	};
	class FST_Customs_Subfaction
	{
		displayName="41st Characters";
	};
	class FST_Spec_Subfaction
	{
		displayName="41st Clone Specialists";
	};
	class FST_Air_Vehicle
	{
		displayName="41st Air Vehicles";
	};
	class FST_Ground_Vehicle
	{
		displayName="41st Ground Vehicles";
	};
	class FST_Supplies
	{
		displayName="41st Supplies";
	};
	class FST_Venator_Category_P
	{
		displayName="41st Venator Parts";
	};
	class FST_Venator_Category_S
	{
		displayName="41st Venator Ships";
	};
	class FST_Acclamator_Category_P
	{
		displayName="41st Acclamator Parts";
	};
	class FST_Acclamator_Category_S
	{
		displayName="41st Acclamator Ships";
	};
	class FST_BattleDroids_Subfaction
	{
		displayName="41st Battledroids";
	};
	class FST_HumanDivision_Subfaction
	{
		displayName="41st CIS Human Division";
	};
	class FST_Tukata_Subfaction
	{
		displayName="41st Tukata PMC";
	};
	class FST_Zombies_Subfaction
	{
		displayName="41st Zombies";
	};
	class FST_Creatures_Subfaction
	{
		displayName="41st Creatures";
	};
};
class CfgFactionClasses 
{ 
	class FST_Faction
	{ 
		displayName="41st Elite Corps";
		priority=1;
		side=1;
		icon="";  	
	};
	class FST_BattleDroids_Faction
	{
		displayName="41st Battledroids";
		priority=1;
		side=2;
		icon="";
	};
	class FST_Tukata_Faction
	{
		displayName="41st Tukata";
		priority=2;
		side=2;
		icon="";
	};
	class FST_Zombies_Faction
	{
		displayName="41st Zombies";
		priority=2;
		side=2;
		icon="";
	};
	class FST_Independent_Faction
	{
		displayName="41st Elite Corps (Indep)";
		priority=1;
		side=3;
		icon="";
	};
};
class CfgEditorCategories
{
	class FST_Crates
	{
		displayname="[41st] Ammo + Medical Crates";
		priority=8;
		side=7;
	};
	class FST_Venator_Category
	{
		displayname="[41st] Venator";
		priority=8;
		side=7;
	};
	class FST_Acclamator_Category
	{
		displayname="[41st] Acclamator";
		priority=8;
		side=7;
	};
};
class CfgFunctions
{
    class FST
    {
        class Functions
        {
            class lowlight
            {
                file="41st_Armor\functions\fn_lowlight.sqf";
            };
            class changelowlightaperture
            {
                file="41st_Armor\functions\fn_changelowlightaperture.sqf";
            };
        };
    };
};
class CfgItems
{
	class JLTS_CloneBinocular;
	class FST_CloneBinocular_Regular: JLTS_CloneBinocular
	{ 
		scope = 2;
		scopeArsenal = 2; 
		displayName = "[41st] Clone Trooper Electrobinocular";
		hiddenSelectionsTextures[] = {"\Sawtes_Sight_test\FST_Clone_binocular_co.paa"};
		visionMode[] = {"Normal","NVG"};
	};
	class FST_CloneBinocular_Thermal: FST_CloneBinocular_Regular
	{ 
		displayName = "[41st] Clone Trooper Electrobinocular (Thermal)";

		visionMode[] = {"Normal","NVG","TI"};
		thermalMode[] = {0,1,4,5,6,7};
	};
};
class Extended_PostInit_EventHandlers
{
    class FST_Munificent_QRF_postInit
    {
        init="call compile preprocessFileLineNumbers '\41st_Armor\Data\Modules.sqf'";
    };
    class FST_postinit
    {
        init="call compile preprocessFileLineNumbers '41st_Armor\xeh_postInit.sqf'";
    };
};
class Extended_PreInit_EventHandlers
{
    class FST_preinit
    {
        init="call compileScript ['\41st_Armor\xeh_preInit.sqf']";
    };
};
class CfgWeapons
{
	/////////////////////////
	//////////NVGS///////////
	/////////////////////////
	class JLTS_CloneNVG;
	class JLTS_CloneNVG_spec;
	class JLTS_CloneNVGCC;
	class JLTS_CloneNVGMC;
	class JLTS_CloneNVGRange;
	/////////////////////////
	////////HELMETS//////////
	/////////////////////////
	class JLTS_CloneHelmetP2;
	class JLTS_CloneHelmetBARC;
	class JLTS_CloneHelmetAB;
	class 3as_P1_Base;
	class 3as_P2_Pilot_helmet;
	class 3as_ATRT_Helmet;
	class SWLB_clone_ARF_P1_helmet;
	class ls_cloneHelmet_scout;
	class ls_gar_phase1Pilot_helmet;
	class ls_cloneHelmet_atrtDriver;
	/////////////////////////
	//////////VESTS/////////
	////////////////////////
	class VestItem;
	class JLTS_CloneVestSuspender;
	class JLTS_CloneVestLieutenant;
	class JLTS_CloneVestRecon;
	class JLTS_CloneVestKama;
	class ls_cloneVest_scout;
	class JLTS_CloneVestOfficer;
	class JLTS_CloneVestOfficer2;
	class JLTS_CloneVestAirborne;
	class V_rebreatherB;
	class V_PlateCarrier1_rgr;
	//////////////Vests//////////////
	class 3AS_Katarn_Vest_Team_Leader;
	class FST_Commando_Vest: 3AS_Katarn_Vest_Team_Leader
	{
		author="Gold";
		scope=2;
		displayname="[41st] Commando Team Leader Pauldron";
		weaponPoolAvailable=1;
		allowedSlots[]={901};
		model="\3AS\3AS_Characters\Commando\3AS_Katarn_Vest_Team_Leader.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Commando_Vest.paa"
		};
		descriptionShort="$STR_A3_SP_NOARMOR";
		class ItemInfo: VestItem
		{
			uniformModel="\3AS\3AS_Characters\Commando\3AS_Katarn_Vest_Team_Leader.p3d";
			hiddenSelections[]=
			{
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"41st_Armor\Data\Vests\FST_Commando_Vest.paa"
			};
			containerClass="Supply200";
			mass=15;
		};
	};
	class FST_Vest_Base: V_rebreatherB
	{
		author="Daara";
		displayname="[41st] Phase 2 Plastoid Armor";
		model="";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		allowedSlots[]={901};
		picture="\41st_Armor\Logo.paa";
		class ItemInfo: VestItem
		{
			uniformmodel="";
			containerclass="Supply200";
			mass=15;
			vesttype="Rebreather";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestARC: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARC Trooper Vest";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestARC_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestARC_Camo: FST_CloneVestARC
	{
		author="Viz";
		scope=2;
		displayName="[41st] ARC Trooper Vest [Camo]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_Camo.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Vest_ARC.rvmat";
		};
	};
	class FST_CloneVestARC_Midnight: FST_CloneVestARC
	{
		author="Viz";
		scope=2;
		displayName="[41st] ARC Trooper Vest [Midnight]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Vest_ARC.rvmat";
		};
	};
	class FST_CloneVestARC_Urban: FST_CloneVestARC
	{
		author="Viz";
		scope=2;
		displayName="[41st] ARC Trooper Vest [Urban]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Vest_ARC.rvmat";
		};
	};
	class FST_CloneVestARC_Desert: FST_CloneVestARC
	{
		author="Viz";
		scope=2;
		displayName="[41st] ARC Trooper Vest [Desert]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Vest_ARC.rvmat";
		};
	};
	/* ArcVest Example
	class FST_CloneVestARC_Tally: FST_CloneVestARC
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARC Trooper Vest [Tally]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_ARC_Tally.paa"
		};
	}; */
	class FST_Vest_GM_Base: JLTS_CloneVestOfficer
	{
		displayName="[41st] Clonetrooper Cold Weather Vest";
		author="Schlabbie And Maxim";
		scope=2;
		model="\JLTS_AE_GM\SEA_Vest_GM_Base.p3d";
		allowedSlots[]={901};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Vests\FST_vest_gm.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="JLTS_AE_GM\SEA_Vest_GM_Base.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=15;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_vest_gm_FTL : FST_Vest_GM_Base
	{
		displayName="[41st] Fire Team Leader Cold Weather Vest";
		author="Schlabbie And Maxim";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Vests\FST_vest_gm_FTL.paa"
		};
	}
	class FST_vest_gm_SL : FST_Vest_GM_Base
	{
		displayName="[41st] Squad Leader Cold Weather Vest";
		author="Schlabbie And Maxim";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Vests\FST_vest_gm_SL.paa"
		};
	}
	class FST_cloneVest_Scout_Woodland: ls_cloneVest_scout
	{
		author = "Ruby";
		scope = 2;
		displayname = "[41st] Clone Scout Pouches (Woodland)";
		model="ls\core\addons\characters_clone\vests\scout\ls_vest_clone_scout.p3d";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Scout_Pouches_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Scout_Pouches.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformmodel="ls\core\addons\characters_clone\vests\scout\ls_vest_clone_scout.p3d";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=15;
			containerclass="Supply200";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_cloneVest_Scout_Midnight: FST_cloneVest_Scout_Woodland
	{
		author = "Ruby";
		scope = 2;
		displayname = "[41st] Clone Scout Pouches (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Scout_Pouches_Midnight.paa"
		};
	};
	class FST_cloneVest_Scout_Desert: FST_cloneVest_Scout_Woodland
	{
		author = "Ruby";
		scope = 2;
		displayname = "[41st] Clone Scout Pouches (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Scout_Pouches_Desert.paa"
		};
	};
	class FST_cloneVest_Scout_Urban: FST_cloneVest_Scout_Woodland
	{
		author = "Ruby";
		scope = 2;
		displayname = "[41st] Clone Scout Pouches (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Scout_Pouches_Urban.paa"
		};
	};
	class FST_vest_holster: FST_vest_base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Holster";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneVestHolster_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_vest_Woodland_holster: FST_vest_base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Holster (Woodland)";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneVestHolster_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_vest_Midnight_holster: FST_vest_base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Holster (Midnight)";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneVestHolster_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_vest_Urban_holster: FST_vest_base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Holster (Urban)";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneVestHolster_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_vest_Desert_holster: FST_vest_base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Holster (Desert)";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneVestHolster_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO: JLTS_CloneVestRecon
	{
		displayName="[41st] Fire Team Leader Sash";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Woodland: JLTS_CloneVestRecon
	{
		displayName="[41st] Fire Team Leader Sash (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_sash.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Midnight: FST_Vest_NCO_Woodland
	{
		displayName="[41st] Fire Team Leader Sash (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Midnight.paa"
		};
	};
	class FST_Vest_NCO_Urban: FST_Vest_NCO_Woodland
	{
		displayName="[41st] Fire Team Leader Sash (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Urban.paa"
		};
	};
	class FST_Vest_NCO_Desert: FST_Vest_NCO_Woodland
	{
		displayName="[41st] Fire Team Leader Sash (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Desert.paa"
		};
	};
class FST_Vest_NCO_Veteran: FST_Vest_NCO
	{
		displayName="[41st] Fire Team Leader Sash (Veteran)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co_Veteran.paa"
		};
	};
	class FST_Vest_HeavyBag: JLTS_CloneVestAirborne
	{
		scope=2;
		displayName="[41st] Airborne Fire Team Leader Sash";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_HeavyBag_Veteran: FST_Vest_HeavyBag
	{
		scope=2;
		displayName="[41st] Airborne Fire Team Leader Sash (Veteran)";
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co_Veteran.paa"
		};
	};
	class FST_Vest_NCO_SL: FST_Vest_NCO
	{
		displayName="[41st] Squad Leader Sash";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconNCO.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconNCO.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Woodland: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_woodland.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat",
			"41st_Armor\Data\Other\Clone_vest_sash.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Midnight: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Midnight)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_midnight.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat",
			"41st_Armor\Data\Other\Clone_vest_sash.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Urban: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Urban)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_urban.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat",
			"41st_Armor\Data\Other\Clone_vest_sash.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Desert: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Desert)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_desert.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat",
			"41st_Armor\Data\Other\Clone_vest_sash.rvmat"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Khaki: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Khaki)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Vest_NCO_Kama_Veteran: FST_Vest_NCO_SL
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Veteran)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_Woodland: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Woodland)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_Midnight: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Midnight)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_Urban: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Urban)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_Desert: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Desert)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_khaki: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Khaki)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_veteran: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Veteran)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran_Officer.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
/* 	class FST_pauldron_kama_Daara: JLTS_CloneVestOfficer
	{
		author="Daara";
		scope=2;
		displayName="[41st] Aviation Officer's Pauldron w/ Kama";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_CXL.paa",
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
	class FST_Commander_pauldron_kama: JLTS_CloneVestOfficer
	{
		displayName="[41st] Commander's Pauldron w/ Kama";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Commander_pauldron_kama_khaki: JLTS_CloneVestOfficer
	{
		displayName="[41st] Commander's Pauldron w/ Kama (Khaki)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Commander_pauldron_kama_veteran: JLTS_CloneVestOfficer
	{
		displayName="[41st] Commander's Pauldron w/ Kama (Veteran)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			hiddenSelectionsTextures[]=
			{
				"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_reversed: JLTS_CloneVestOfficer2
	{
		author="Daara";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Reversed.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_reversed_khaki: JLTS_CloneVestOfficer2
	{
		author="Daara";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama (Khaki)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_pauldron_kama_reversed_veteran: JLTS_CloneVestOfficer2
	{
		author="Daara";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama (Veteran)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestLieutenant: JLTS_CloneVestOfficer
	{
		displayName="[41st] Pauldron";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestLieutenant_Woodland: JLTS_CloneVestOfficer
	{
		displayName="[41st] Pauldron (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestLieutenant_Urban: JLTS_CloneVestOfficer
	{
		displayName="[41st] Pauldron (Urban)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestLieutenant_Midnight: JLTS_CloneVestOfficer
	{
		displayName="[41st] Pauldron (Midnight)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestLieutenant_Desert: JLTS_CloneVestOfficer
	{
		displayName="[41st] Pauldron (Desert)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestKama: JLTS_CloneVestOfficer
	{
		displayName="[41st] Kama";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FTS_CloneVestKama_Khaki: JLTS_CloneVestOfficer
	{
		displayName="[41st] Kama (Khaki)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FTS_CloneVestKama_Veteran: JLTS_CloneVestOfficer
	{
		displayName="[41st] Kama (Veteran)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestOfficer2: JLTS_CloneVestOfficer
	{
		displayName=" Reversed Pauldron w/ Kama";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
/* 	class FTS_CloneVestRecon: JLTS_CloneVestOfficer
	{
		displayName="[41st] Recon Vest";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
/* 	class FTS_CloneVestReconNCO: JLTS_CloneVestOfficer
	{
		displayName="[41st] Recon NCO Vest";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconNCO.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconNCO.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
/* 	class FTS_CloneVestReconOfficer: JLTS_CloneVestOfficer
	{
		displayName="[41st] Recon Officer Vest";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_officer_co.paa",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
 	/* 
	class FST_CloneVestMerrik: JLTS_CloneVestOfficer
	{
		displayName="[41st] Merrik's Vest and Kama";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_Merrik.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			""
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1",
				"camo2"
			};
			mass=80;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
	class FST_CloneVestAirborneNCO: JLTS_CloneVestAirborne
	{
		displayName="[41st] Airborne Squad Leader Sash";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborneNCO.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[] =
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[] =
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestAirborneNCO.p3d";
			containerClass="Supply200";
			hiddenSelections[] =
			{
				"camo1",
				"camo2"
			};
			hiddenSelectionsTextures[] =
			{
				"camo1",
				"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
			};
			mass=80;
			class HitpointsProtectionInfo
			{		
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestAirborneNCO_Veteran: FST_CloneVestAirborneNCO
	{
		displayName="[41st] Airborne Squad Leader Sash (Veteran)";
		hiddenSelectionsTextures[] =
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
	};
	class FST_CloneVestSuspenders: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st] Suspenders";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_vest_suspender_co.paa"
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_Woodland: V_rebreatherB
	{
		author="Gold";
		scope=2;
		displayName="[41st] Suspenders (Woodland)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_Midnight: V_rebreatherB
	{
		author="Gold";
		scope=2;
		displayName="[41st] Suspenders (Midnight)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_Urban: V_rebreatherB
	{
		author="Gold";
		scope=2;
		displayName="[41st] Suspenders (Urban)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	/* class FST_CloneVestSuspenders_ARF: V_rebreatherB
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Suspenders";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Vest_Suspenders.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_ARF_Dirty: V_rebreatherB
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Suspenders [Dirty]";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Vest_Suspenders_Dirty.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
	/* class FST_CloneVestSuspenders_ARF_Woodland: V_rebreatherB
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Suspenders (Woodland)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Suspenders_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
	class FST_CloneVestSuspenders_Ranger_Desert: V_rebreatherB
	{
		author="Daara";
		scope=2;
		displayName="[41st] Ranger Suspenders (Desert)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Suspenders_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_Ranger_Urban: V_rebreatherB
	{
		author="Gold";
		scope=2;
		displayName="[41st] Ranger Suspenders (Urban)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_ARF_Suspenders_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_CloneVestSuspenders_Rangers_Black: V_rebreatherB
	{
		author="Gold";
		scope=2;
		displayName="[41st] Ranger Suspenders (Black)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestSuspender_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Suspenders_Black.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		class ItemInfo: VestItem
		{
			vesttype="Rebreather";
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
			containerClass="Supply200";
			hiddenSelections[]=
			{
				"camo1"
			};
			mass=40;
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.08975;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.08975;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.08975;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.08975;
				};
				class Arms
				{
					hitpointName="HitArms";
					armor=6;
					PassThrough=0.08975;
				};
				class Legs
				{
					hitpointName="Hitlegs";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	//////////////////////////
	////////UNIFORMS/////////
	/////////////////////////
	class JLTS_CloneArmor;
	class JLTS_CloneArmorRecon;
	class JLTS_CloneArmorGrenadier;
	class JLTS_CloneArmorSupport;
	class UniformItem;
	class ls_cloneUniform_scout;
	class HeadgearItem;
	class lsd_gar_bodyGlove_uniform
	{
		class ItemInfo{};
	};
	//////////////HELMETS//////////////
	class ItemCore;
	class 3AS_Katarn_Helmet_Base: ItemCore
	{
		class ItemInfo;
	};
	class FST_cloneUniform_scout_Woodland: ls_cloneUniform_scout
	{
		scope = 2;
		author = "Ruby";
		displayname = "[41st] Scout Trooper Armor (Woodland)";
		model="ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_clone_scout_woodland";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_cloneUniform_scout_Desert: ls_cloneUniform_scout
	{
		scope = 2;
		author = "Ruby";
		displayname = "[41st] Scout Trooper Armor (Desert)";
		model="ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_clone_scout_Desert";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_cloneUniform_scout_Midnight: ls_cloneUniform_scout
	{
		scope = 2;
		author = "Ruby";
		displayname = "[41st] Scout Trooper Armor (Midnight)";
		model="ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_clone_scout_Midnight";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_cloneUniform_scout_Urban: ls_cloneUniform_scout
	{
		scope = 2;
		author = "Ruby";
		displayname = "[41st] Scout Trooper Armor (Urban)";
		model="ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		class ItemInfo: UniformItem
		{
			uniformClass="FST_clone_scout_Urban";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_cloneUniform_scout_undersuit_woodland: FST_cloneUniform_scout_Woodland
	{
		displayname = "[41st] Scout Undersuit (Woodland)";
		class ItemInfo: UniformItem
		{
			uniformclass = "FST_clone_scout_undersuit_woodland";
		};
	};
	class FST_cloneUniform_scout_undersuit_Midnight: FST_cloneUniform_scout_Midnight
	{
		displayname = "[41st] Scout Undersuit (Midnight)";
		class ItemInfo: UniformItem
		{
			uniformclass = "FST_clone_scout_undersuit_midnight";
		};
	};
	class FST_cloneUniform_scout_undersuit_Urban: FST_cloneUniform_scout_Urban
	{
		displayname = "[41st] Scout Undersuit (Urban)";
		class ItemInfo: UniformItem
		{
			uniformclass = "FST_clone_scout_undersuit_urban";
		};
	};
	class FST_cloneUniform_scout_undersuit_Desert: FST_cloneUniform_scout_Desert
	{
		displayname = "[41st] Scout Undersuit (Desert)";
		class ItemInfo: UniformItem
		{
			uniformclass = "FST_clone_scout_undersuit_Desert";
		};
	};
	class FST_Commando_Helmet_Base: 3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="";
		picture="\A3\characters_f\Data\UI\icon_H_helmet_plain_ca.paa";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=15;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Commando_Helmet: FST_Commando_Helmet_Base
	{
		author="Gold";
		displayName="[41st] Commando Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Commando_Helmet.paa",
			"41st_Armor\Data\Helmets\FST_Commando_Helmet.paa"
		};
	};
	class FST_P2_Helmet_Base: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st] P2 Trooper Helmet";
		scope=0;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		model="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Helmet_P2.rvmat";
		};
		hiddenselections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_Helmet: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P2 Helmet";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet.paa",
		};
	};
	class FST_P2_Invisible_Helmet: FST_P2_Helmet_Base
	{
		author="Viz";
		scope=2;
		displayName="[41st] P2 Invisible Helmet";
		hiddenSelectionsTextures[]=
		{
			""
		};
		hiddenSelectionsMaterials[]=
		{
			"";
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_Helmet_EOD: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [EOD]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_EOD.paa",
		};
	};	
	class FST_P2_Helmet_Woodland: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Woodland]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Helmet_P2.rvmat";
		};
	};	
	class FST_P2_Helmet_Urban: FST_P2_Helmet_Base	
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Urban]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Helmet_P2.rvmat";
		};
	};
	class FST_P2_Helmet_Midnight: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Midnight]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Helmet_P2.rvmat";
		};
	};	
	class FST_P2_Helmet_Desert: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Desert]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Helmet_P2.rvmat";
		};
	};
	class FST_Pilot_P1_Helmet: ls_gar_phase1Pilot_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Pilot Helmet";
		model="ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\ls_cloneHelmet_phase1_pilot.p3d";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		subItems[] = {};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P1_Pilot_Helmet_CO.paa",
			"ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\data\lifesupport_co.paa",
			"ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\data\visor_co.paa"
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\ls_cloneHelmet_phase1_pilot.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			modelSides[]={3,1};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_HELMET_GM_Base: JLTS_CloneHelmetP2
	{
		author="Schlabbie And Maxim";
		scope=2;
		model="JLTS_AE_GM\SEA_Helmet_GM_Base.p3d";
		displayName="[41st] Clonetrooper Cold Weather Helmet";
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\data\Helmets\FST_GM_Helmet.paa",
			"\41st_Armor\data\Helmets\FST_GM_Helmet.paa"
		};
		ace_hearing_lowerVolume=0.60000002;
		ace_hearing_protection=0.85000002;
		class ItemInfo: HeadgearItem
		{
			mass=10;
			uniformModel="JLTS_AE_GM\SEA_Helmet_GM_Base.p3d";
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			hiddenSelections[]=
			{
				"Camo1",
				"Visor"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_HELMET_GM_NCO: JLTS_CloneHelmetP2
	{
		author="Schlabbie And Maxim";
		scope=2;
		model="JLTS_AE_GM\SEA_Helmet_GM_Base.p3d";
		displayName="[41st] Clonetrooper Cold Weather Leadership Helmet";
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\data\Helmets\FST_GM_Helmet_NCO.paa",
			"\41st_Armor\data\Helmets\FST_GM_Helmet_NCO.paa"
		};
		ace_hearing_lowerVolume=0.60000002;
		ace_hearing_protection=0.85000002;
		class ItemInfo: HeadgearItem
		{
			mass=10;
			uniformModel="JLTS_AE_GM\SEA_Helmet_GM_Base.p3d";
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			hiddenSelections[]=
			{
				"Camo1",
				"Visor"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_cloneHelmet_Scout_Woodland: ls_cloneHelmet_scout
	{
		author="Daara";
		scope=2;
		displayName="[41st] Scout Trooper Helmet (Woodland)";
		model="ls\core\addons\characters_clone\helmets\scout\ls_helmet_clone_scout.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Woodland.paa",
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Helmet_Scout.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Helmet_Scout_visor.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone\helmets\scout\ls_helmet_clone_scout.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_cloneHelmet_Scout_Midnight: FST_cloneHelmet_Scout_Woodland
	{
		author="Daara";
		scope=2;
		displayName="[41st] Scout Trooper Helmet (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Midnight.paa",
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Midnight.paa"
		};
	};
	class FST_cloneHelmet_Scout_Desert: FST_cloneHelmet_Scout_Woodland
	{
		author="Daara";
		scope=2;
		displayName="[41st] Scout Trooper Helmet (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Desert.paa",
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Desert.paa"
		};
	};
	class FST_cloneHelmet_Scout_Urban: FST_cloneHelmet_Scout_Woodland
	{
		author="Daara";
		scope=2;
		displayName="[41st] Scout Trooper Helmet (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Urban.paa",
			"41st_Armor\Data\Helmets\FST_Scout_Helmet_Urban.paa"
		};
	};
	class FST_ARF_Helmet_Blank: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet (Blank)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Blank.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Blank.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_ARF_Helmet_WhiteGreen: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet (White/Green)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_GreenWhite.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_GreenWhite.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_ARF_Helmet_Desert: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet (Desert)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Desert.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};	
	class FST_ARF_Helmet_Woodland: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet (Woodland)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Woodland.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_ARF_Helmet_Midnight: SWLB_clone_ARF_P1_helmet
	{
		author="Gold";
		scope=2;
		displayName="[41st] ARF Helmet (Midnight)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Midnight.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_ARF_Helmet_Urban: SWLB_clone_ARF_P1_helmet
	{
		author="Gold";
		scope=2;
		displayName="[41st] ARF Helmet (Urban)";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Urban.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	//class H_HelmetO_ViperSP_hex_F;
	class FST_ScoutHelmet_Base: FST_ARF_Helmet_WhiteGreen
	{
		author="Maldova";
		displayName="[41st] Scout Helmet";
		scope=2;
		scopeCurator=2;
		picture="";
		model="41st_Armor\Data\Helmets\FST_ScoutHelmet.p3d"
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\ScoutUnmarked_co.paa",
			"41st_Armor\Data\Helmets\GreenVisor_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Helmets\ScoutHelmet.rvmat",
			"41st_Armor\Data\Helmets\visor.rvmat"
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="41st_Armor\Data\Helmets\FST_ScoutHelmet.p3d";
			hiddenSelections[]=
			{
				"Camo1",
				"Visor"
			};
			hiddenSelectionsTextures[]=
			{
				"41st_Armor\Data\Helmets\ScoutUnmarked_co.paa",
				"41st_Armor\Data\Helmets\GreenVisor_co.paa"
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=7;
					passThrough=0.5;
				};
			};
		};
	};
	class FST_ScoutHelmet_MarkedOne: FST_ScoutHelmet_Base
	{
		displayName="[41st] Scout Helmet (CT)";
		model="41st_Armor\Data\Helmets\FST_ScoutHelmet.p3d"
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\ScoutMarkedOne_co.paa",
			"41st_Armor\Data\Helmets\GreenVisor_co.paa"
		};
	};
	class FST_ScoutHelmet_Woodland_Unmarked: FST_ScoutHelmet_Base
	{
		displayName="[41st] Scout Helmet (Woodland)";
		model="41st_Armor\Data\Helmets\FST_ScoutHelmet.p3d"
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\ScoutWoodlandUnmarked_co.paa",
			"41st_Armor\Data\Helmets\GreenVisor_co.paa"
		};
	};
	class FST_ScoutHelmet_Woodland_MarkedOne: FST_ScoutHelmet_Base
	{
		displayName="[41st] Scout Helmet (CT Woodland)";
		model="41st_Armor\Data\Helmets\FST_ScoutHelmet.p3d"
		hiddenSelections[]=
		{
			"Camo1",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\ScoutWoodlandMarkedOne_co.paa",
			"41st_Armor\Data\Helmets\GreenVisor_co.paa"
		};
	};
	/* class TAC_W_ghillie_GR1;
	class FST_W_ghillie_O1: TAC_W_ghillie_GR1
	{
		scope=2;
		author="Gold";
		displayName="[41st] TAC Ghillie";
		model="\winter\data\ghillie_pod.p3d";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_wookie_ghillie.paa"
		};
		class ItemInfo: HeadgearItem
		{
			mass=5;
			uniformModel="\winter\data\Wghillie1.p3d";
			hiddenSelections[]=
			{
			"Camo"
			};
			modelSides[]={6};
			armor=0;
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointName="HitHead";
					armor=0;
					passThrough=0.5;
				};
			};
		};
	}; */
	class FST_P2_Helmet_Sere: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] SERE Helmet";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_SERE.paa",
		};
	};
/* 	class FST_ARF_Helmet_WhiteGreen_Jaws: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet (Jaws)";
		picture="\SWLB_clones\data\ui\icon_SWLB_clone_helmet_arf_p1_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet_GreenWhite_Jaws.paa",
			"41st_Armor\data\Helmets\FST_ARF_Helmet_GreenWhite_Jaws.paa",
			"",
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"camo3"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
	class FST_ARF_Helmet: SWLB_clone_ARF_P1_helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] ARF Helmet";
		picture="ls\core\addons\characters_clone_legacy\_ui\arf_phase1_helmet_ui_ca.paa";
		model="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_ARF_Helmet.paa",
			"",
			"41st_Armor\data\Helmets\FST_ARF_Helmet.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\helmet_arf.rvmat";
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
		};
		class ItemInfo: HeadgearItem
		{
			uniformModel="ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenSelections[]=
			{
				"camo1",
				"camo2",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_BARC_Helmet: JLTS_CloneHelmetBARC
	{
		scope=2;
		author="Daara";
		displayName="[41st] BARC Helmet";
		ace_hearing_protection=1;
		ace_hearing_lowerVolume=0;
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetBARC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetBARC_ui_ca.paa";
/* 		hiddenSelectionsMaterials[]=
		{
			"\MRC\JLTS\characters\CloneArmor2\Clone_helmet_BARC.rvmat";
		}; */
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor2\Data\Clone_helmet_BARC_co.paa";
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetBARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_ARC_Helmet: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st] P2 ARC Trooper Helmet";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"MRC\JLTS\characters\CloneArmor2\data\Clone_helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_ARC_Helmet_Woodland: JLTS_CloneHelmetP2
	{
		author="Gold";
		displayName="[41st] P2 ARC Trooper Helmet (Woodland)";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet_Woodland.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_ARC_Helmet_Midnight: JLTS_CloneHelmetP2
	{
		author="Gold";
		displayName="[41st] P2 ARC Trooper Helmet (Midnight)";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet_Midnight.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_ARC_Helmet_Urban: JLTS_CloneHelmetP2
	{
		author="Gold";
		displayName="[41st] P2 ARC Trooper Helmet (Urban)";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet_Urban.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P2_ARC_Helmet_Desert: JLTS_CloneHelmetP2
	{
		author="Gold";
		displayName="[41st] P2 ARC Trooper Helmet (Desert)";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet_Desert.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P1_Base: 3as_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Helmet";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		subItems[] = {};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo",
			};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_P1_SGT: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 SGT Helmet";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\Phase1\Phase1_Sergeant_CO.paa"
		};
	};
	class FST_P1_LT: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 LT Helmet";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\Phase1\Phase1_Lieutenant_CO.paa"
		};
	};
	class FST_P1_CPT: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 CPT Helmet";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\Phase1\Phase1_Captain_CO.paa"
		};
	};
	class FST_P1_CMDR: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 CMDR Helmet";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\Phase1\Phase1_Commander_CO.paa"
		};
	};
	class FST_P1_41st: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Helmet (41st)";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P1_Helmet.paa"
		};
	};
	class FST_P1_41st_NCO: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Helmet (41st NCO)";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P1_Helmet_Sergeant.paa"
		};
	};
	class FST_P1_41st_Officer: FST_P1_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Helmet (41st Officer)";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\phase1_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Standard_P1.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P1_Helmet_Officer.paa"
		};
	};
	// New crewman shit
	class FST_Crewman_Helmet_Mk2: ls_cloneHelmet_atrtDriver
	{
		scope=2;
		author="Steel";
		displayName="[41st] Crewman Helmet Mk2";
		ace_hearing_protection=1;
		ace_hearing_lowerVolume=0;
		model="\ls\core\addons\characters_clone\helmets\atrtDriver\ls_helmet_clone_atrtDriver.p3d";
		hiddenSelections[]=
		{
			"helmet",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet_Mk2.paa",
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet_Mk2.paa"
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\ls\core\addons\characters_clone\helmets\atrtDriver\ls_helmet_clone_atrtDriver.p3d";
			mass=15;
			hiddenselections[]=
			{
				"helmet",
				"visor"
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
/*  class FST_Crewman_Helmet_Mk2_Harlequin: FST_Crewman_Helmet_Mk2
	{
		scope=2;
		author="Steel";
		displayName="[41st] Crewman Helmet Mk2 (Harlequin)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet_Mk2_Harlequin.paa",
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet_Mk2_Harlequin.paa"
		};
	}; */
	// Old crewman shit
	class FST_Crewman_Helmet: JLTS_CloneHelmetBARC
	{
		scope=2;
		author="Daara";
		displayName="[41st] Crewman Helmet";
		ace_hearing_protection=1;
		ace_hearing_lowerVolume=0;
		picture="3AS\3AS_Characters\Clones\Headgear\ui\driver_ui_ca.paa";
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_ATRT.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet.paa"
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_ATRT.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
/*	class FST_Crewman_Helmet_Demon: FST_Crewman_Helmet
	{
		scope=2;
		author="Daara";
		displayName="[41st] Crewman Helmet (Demon)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_Crewman_Helmet_Demon.paa"
		};
	}; */
	class FST_Airborne_Helmet: JLTS_CloneHelmetAB
	{
		author="Daara";
		displayName="[41st] Airborne Helmet";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneHelmetAB_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneHelmetAB.p3d";
		subItems[] = {};
		hiddenselections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_AB_Helmet.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Helmet_AB.rvmat";
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneHelmetAB.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};
	class FST_Airborne_Helmet_NCO: FST_Airborne_Helmet
	{
		author="Daara";
		displayName="[41st] Airborne NCO Helmet";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_AB_Helmet_NCO.paa",
		};
	};
	//////////////Custom Helmets//////////////
    class FST_Pilot_P1_Helmet_Ghostly: FST_Pilot_P1_Helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] P1 Pilot Helmet [Ghostly]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_Pilot_P1_Helmet_Ghostly.paa",
			"ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\data\lifesupport_co.paa",
			"ls\core\addons\characters_clone_legacy\helmets\phase1Pilot\data\visor_co.paa"
		};
	}; 
	class JMSLLTE_EmpOfficerCap_black_helmet;
	class FST_EmpOfficerCap_green_helmet: JMSLLTE_EmpOfficerCap_black_helmet
	{
		scope=2;
		author="JMax";
		displayName="[41st] Navy Officer's Cap (Green)";
		picture="\JMSLLTE_empire\helmets\data\ico\ico_h_cap_green.paa";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\New_Gweem_Officer_Cap.paa"
		};
	};
	class FST_BARC_Helmet_Ghostly: FST_BARC_Helmet
	{
		author="Daara";
		scope=2;
		displayName="[41st] BARC Helmet [Ghostly]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_Barc_Helmet_Ghostly.paa",
		};
	}; 
/*	class FST_P2_ARC_Helmet_Tally: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st] P2 ARC Trooper Helmet (Tally)";
		scope=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor2\data\ui\CloneHelmetARC_ui_ca.paa";
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\data\Other\Clone_Helmet_ARC.rvmat"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_P2_ARC_Helmet_Tally.paa"
		};
		model="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor2\CloneHelmetARC.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	}; */
/* 	class FST_Airborne_Helmet_Annex: FST_Airborne_Helmet
	{
		author="Daara";
		displayName="[41st] Airborne Helmet (Annex)";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_AB_Helmet_Annex.paa",
		};
	}; */
	class FST_Airborne_Helmet_Woodland: FST_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st] Airborne Helmet (Woodland)";
		scope=2;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\data\Helmets\FST_AB_Helmet_Woodland.paa"
		};
	}; 
	class JLTS_CloneHelmetP2MC;
	class FST_BC_Helmet_Merrik: JLTS_CloneHelmetP2MC
	{
		author="Daara";
		scope=2; 
		displayName="[41st] BC Helmet [Merrik]";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_MC_Helmet_Merrik.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Helmet_P2.rvmat";
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo1",
			};
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			class HitpointsProtectionInfo
			{
				class Head
				{
					hitpointname="HitHead";
					armor=6;
					PassThrough=0.08975;
				};
				class Face
				{
					hitpointName="HitFace";
					armor=6;
					PassThrough=0.08975;
				};
			};
		};
	};	
	class FST_P2_Helmet_Recruit: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Recruit]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Recruit.paa",
		};
	};
/* 	class FST_P2_Helmet_Jaws: FST_P2_Helmet_Base
	{
		author="Daara";
		scope=2; 
		displayName="[41st] P2 Helmet [Jaws]";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Helmets\FST_P2_Helmet_Jaws.paa",
		};
	}; */
	//////////////UNIFORMS//////////////
	class FST_Uniform_Bodyglove: lsd_gar_bodyGlove_uniform
	{
		author="Daara";
		scope=2;
		displayName="[41st] Undersuit";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver.p3d";
		picture="\41st_Armor\Logo.paa";
		class ItemInfo: ItemInfo
		{
			uniformModel="-";
			uniformClass="FST_bodyGlove";
			containerClass="Supply10";
			mass=1;
		};
	};
	class FST_Trooper_Uniform: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Trooper Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_DC15S";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Trooper_Uniform_DC15A: JLTS_CloneArmor
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Trooper Armor (DC-15A)";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_DC15A";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Trooper_Medic: JLTS_CloneArmor
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Medic Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_Medic";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
 	class FST_ARF_Uniform: JLTS_CloneArmorRecon
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Recon Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_ARF";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
 	class FST_ARF_Uniform_WhiteGreen: JLTS_CloneArmorRecon
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Recon Armor (White/Green)";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_ARF_WhiteGreen";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_Urban: JLTS_CloneArmorRecon
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Recon Armor (Urban)";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_ARF_Urban";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Pilot_Uniform: JLTS_CloneArmor
	{
		author="Daara";
		scope=1;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P1 Pilot Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Pilot_P1";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_EOD: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 EOD Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_EOD";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_SCT: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Senior Clone Trooper Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_SCT";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_SCT_Medic: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Senior Clone Trooper Armor (Medic)";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_SCT_Medic";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_VCT: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Veteran Clone Trooper Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_VCT";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_VCT_Medic: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Veteran Clone Trooper Armor (Medic)";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_VCT_Medic";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_CLC: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Clone Lance Corporal Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_CLC";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_CPL: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Clone Corporal Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_CPL";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_CS: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Clone Sergeant Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_CS";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_CSS: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Clone Staff Sergeant Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_CSS";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_CL: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Clone Lieutenant Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_P2_CL";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
 	class FST_Uniform_Desert: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [ARF Desert]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_ARF_Desert";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	/* class FST_Arf_Uniform_Woodland: JLTS_CloneArmor
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [ARF Woodland]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_ARF_Woodland";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; */
	class FST_Uniform_Woodland: JLTS_CloneArmor
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [Woodland]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_Woodland";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_Midnight: JLTS_CloneArmor
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [Midnight]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_Midnight";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_SERE: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [SERE]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Trooper_SERE";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	class FST_Uniform_GM_Plastic: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_NCO: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather NCO Uniform";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_NCO";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Officer: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather NCO Uniform";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Officer";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Sarlacc: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Sarlacc)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Sarlacc";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Wampa: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Wampa)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Wampa";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Krayt: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Krayt)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Krayt";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Nexu: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Nexu)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Nexu";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Radark: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Radark)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Radark";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Zillo: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Zillo)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Zillo";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Rancor: JLTS_CloneArmor
	{
		author="Steel";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Rancor)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Rancor";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Kadoshi: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Kadoshi)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Kadoshi";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Sanval: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Sanval)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Sanval";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Hydra: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Hydra)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Hydra";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Uvak: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Uvak)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Uvak";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Howler: JLTS_CloneArmor
	{
		author="Schlabbie And Maxim";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Howler)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Howler";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Voxyn: JLTS_CloneArmor
	{
		author="Steel";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Voxyn)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Voxyn";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Raxshir: JLTS_CloneArmor
	{
		author="Steel";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Raxshir)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Raxshir";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Gharzr: JLTS_CloneArmor
	{
		author="Steel";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Gharzr)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Gharzr";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_GM_Plastic_Varactyl: JLTS_CloneArmor
	{
		author="Steel";
		scope=2;
		displayName="[41st] Clonetrooper Cold Weather Uniform (Varactyl)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="JLTS_AE_GM\SEA_Uniform_GM_plastic.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_GM_Base_Plastic_Varactyl";
			containerClass="Supply150";
			mass=15;
		};
	};
	class Uniform_Base;
	class FST_Commando_Uniform: Uniform_Base
	{
		author="Gold";
		scope=2;
		displayName="[41st] Commando Uniform";
		tas_is_commando=1;
		picture="3AS\3AS_Characters\Commando\data\UI\Katarn_Uniform_Unmarked_UI_ca.paa";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Commando_Uniform.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_Commando";
			containerClass="Supply150";
			mass=15;
		};
	};
	class 3as_JLTS_CloneArmor_Base;
	class FST_Uniform_P1: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_CMDR: 3as_JLTS_CloneArmor_Base
	{
		author="Daara"; 
		scope=2;
		displayName="[41st] Phase 1 Armor (CMDR)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_CMDR";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_CPT: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (CPT)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_CPT";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_LT: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (LT)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_LT";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_SGT: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (SGT)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_SGT";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (41st)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Sarlacc: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Sarlacc)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Sarlacc";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Wampa: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Wampa)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Wampa";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Krayt: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Krayt)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Krayt";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Nexu: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Nexu)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Nexu";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Radark: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Radark)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Radark";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Zillo: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Zillo)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Zillo";
			containerClass="Supply150";
			mass=15;
		};
	};
	class FST_Uniform_P1_41st_Kadoshi: 3as_JLTS_CloneArmor_Base
	{
		author="Daara";
		scope=2;
		displayName="[41st] Phase 1 Armor (Kadoshi)";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformType="Neopren";
			uniformClass="FST_Trooper_P1_41st_Kadoshi";
			containerClass="Supply150";
			mass=15;
		};
	};
 	class FST_Uniform_NCO: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [NCO]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_NCO";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
 	class FST_Uniform_Officer: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [Officer]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_Officer";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
 	class FST_Uniform_Wookiee: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Wookiee Freedom Fighter";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_blufor_diver";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Wookiee";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	///////////Custom Uniforms[Drip]///////////
/*  class FST_Uniform_Ghostly: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [Ghostly]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_Ghostly";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; */
	class JLTS_CloneArmorMC;
	class FST_Uniform_Merrik_BC: JLTS_CloneArmorMC
	{
		author="Daara";
		scope=2;
		displayName="[41st] Battalion Commander Armor (Merrik)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmorMC.p3d";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_P2_Merrik_BC";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	};
	class ls_blufor_unit_base;
	class ls_garUniform_jediCommander: ls_blufor_unit_base
	{
		class ItemInfo;
	};
	class FST_Jedi_uniform: ls_garUniform_jediCommander
	{
		scope=2;
		displayName="[41st] Jedi Armor";
		JLTS_hasStunProtection = 1;
		class ItemInfo: UniformItem
		{
			uniformClass="FST_Jedi";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Dark_Jedi_uniform: ls_garUniform_jediCommander
	{
		scope=2;
		displayName="[41st] Dark Jedi Armor";
		JLTS_hasStunProtection = 1;
		class ItemInfo: UniformItem
		{
			uniformClass="FST_DarkJedi";
			containerClass="Supply150";
			mass=40;
		};
	};
	class FST_Uniform_Bloddy_Zombie: JLTS_CloneArmor
	{
		author="Daara";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] Zombie Bloddy Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_Zombie_Bloody";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	//////////////NVGs/////////////

	class FST_NVG: JLTS_CloneNVG
	{
		author="Daara";
		displayName="[41st] NCO Macrobinoculars";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVG_off.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG.paa",
		};
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
		thermalMode[]={0,1};
	};
		class FST_NVG_Fixed: JLTS_CloneNVG_spec
	{
		author="Daara";
		displayName="[41st] NCO Macrobinoculars (Fixed On)";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVG_on.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG.paa",
		};
		visionMode[]=
		{
			"Normal",
			"NVG"
		};
		thermalMode[]={0,1};
	};
	class FST_NVG_Invisible : FST_NVG
	{
		displayName="[41st] Invisible NVGS";
		model="";
	}

	class FST_NVG_Woodland: JLTS_CloneNVG
	{
		author="Gold";
		displayName="[41st] NCO Macrobinoculars (Woodland)";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVG_off.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_nvg.rvmat"
		};
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,1};
	};
	class FST_NVG_Invisible_Thermals : FST_NVG_Woodland
	{
		displayName="[41st] Invisible NVGS special";
		model="";
	}
	class FST_NVG_Urban: FST_NVG_Woodland
	{
		author="Gold";
		displayName="[41st] NCO Macrobinoculars (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Urban.paa",
		};
	};
	class FST_NVG_Midnight: FST_NVG_Woodland
	{
		author="Gold";
		displayName="[41st] NCO Macrobinoculars (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Midnight.paa",
		};
	};
/*	class FST_NVG_Dobie: FST_NVG
	{
		author="Viz";
		displayName="[41st] NCO Macrobinoculars (Dobie)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Dobie.paa",
		};
	}; */
/*	class FST_NVG_Fixed_Nori: FST_NVG_Fixed
	{
		author="Gold";
		displayName="[41st] NCO Macrobinoculars (Nori/Fixed On)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Nori.paa",
		};
	}; */
	class FST_NVG_Desert: FST_NVG_Woodland
	{
		author="Daara";
		displayName="[41st] NCO Macrobinoculars (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_NVG_Desert.paa",
		};
	};
	class FST_Marshal_Commander_Visor: JLTS_CloneNVGMC
	{
		author="Daara";
		displayName="[41st] Battalion Commander Visor";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVGMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_mc_visor_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\Clone_visor_Merrik.paa",
		};
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,1};
	};
	class FST_Antenna: JLTS_CloneNVGRange
	{
		author="Daara";
		displayName="[41st] Officer Rangefinder";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Antenna.paa",
		};
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,1};
	};
	class FST_Antenna_Woodland: FST_Antenna
	{
		author="Daara";
		displayName="[41st] Officer Rangefinder (Woodland)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Antenna_Woodland.paa",
		};
	};
	class FST_Antenna_Midnight: FST_Antenna
	{
		author="Daara";
		displayName="[41st] Officer Rangefinder (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Antenna_Midnight.paa",
		};
	};
	class FST_Antenna_Urban: FST_Antenna
	{
		author="Daara";
		displayName="[41st] Officer Rangefinder (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Antenna_Urban.paa",
		};
	};
	class FST_Antenna_Desert: FST_Antenna
	{
		author="Daara";
		displayName="[41st] Officer Rangefinder (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Antenna_Desert.paa",
		};
	};
	class FST_Visor: JLTS_CloneNVGCC
	{
		author="Daara";
		displayName="[41st] Officer Visor";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVGMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_cc_visor_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor.paa",
		};
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,1};
	};
	class FST_Visor_Woodland: JLTS_CloneNVGCC
	{
		author="Daara";
		displayName="[41st] Officer Visor (Woodland)";
		modelOptics="\MRC\JLTS\Core_mod\nvg_optic_dummy.p3d";
		model="\MRC\JLTS\characters\CloneArmor\CloneNVGMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_nvg_cc_visor_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\clone_visor.rvmat"
		};
		visionMode[]=
		{
			"Normal",
			"NVG",
			"TI"
		};
		thermalMode[]={0,1};
	};
	class FST_Visor_Urban: FST_Visor_Woodland
	{
		author="Daara";
		displayName="[41st] Officer Visor (Urban)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor_Urban.paa",
		};
	};
	class FST_Visor_Midnight: FST_Visor_Woodland
	{
		author="Daara";
		displayName="[41st] Officer Visor (Midnight)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor_Midnight.paa",
		};
	};
	class FST_Visor_Desert: FST_Visor_Woodland
	{
		author="Daara";
		displayName="[41st] Officer Visor (Desert)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor_Desert.paa",
		};
	};
/*	class FST_Visor_Argo: FST_Visor
	{
		author="Daara";
		displayName="[41st] Officer Visor (Argo)";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Visor_Argo.paa",
		};
	}; */
};	
class UniformSlotInfo
{
	slotType=0;
	linkProxy="-";
};
class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class HitPoints;
	};
	class SoldierWB: CAManBase
	{
		class HitPoints: HitPoints
		{
			
			armor=1;
			depends="HitHead";
			explosionShielding=1;
			material=-1;
			minimalHit=0;
			name="head";
			passThrough=0;
			radius=1;
			visual="";
			class HitFace;
			class HitNeck;
			class HitHead;
			class HitPelvis;
			class HitAbdomen;
			class HitDiaphragm;
			class HitChest;
			class HitBody;
			class HitArms;
			class HitHands;
			class HitLegs;
		};
	};
	class B_soldier_base_F: SoldierWB
	{
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
			};
			class HitNeck: HitNeck
			{
			};
			class HitHead: HitHead
			{
			};
			class HitPelvis: HitPelvis
			{
			};
			class HitAbdomen: HitAbdomen
			{
			};
			class HitDiaphragm: HitDiaphragm
			{
			};
			class HitChest: HitChest
			{
			};
			class HitBody: HitBody
			{
			};
			class HitArms: HitArms
			{
			};
			class HitHands: HitHands
			{
			};
			class HitLegs: HitLegs
			{
			};
		};
	};
	class B_Soldier_F: B_soldier_base_F
	{
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
			};
			class HitNeck: HitNeck
			{
			};
			class HitHead: HitHead
			{
			};
			class HitPelvis: HitPelvis
			{
			};
			class HitAbdomen: HitAbdomen
			{
			};
			class HitDiaphragm: HitDiaphragm
			{
			};
			class HitChest: HitChest
			{
			};
			class HitBody: HitBody
			{
			};
			class HitArms: HitArms
			{
			};
			class HitHands: HitHands
			{
			};
			class HitLegs: HitLegs
			{
			};
		};
	};
	class ContainerSupply;
	class Box_NATO_Ammo_F;
	class B_Kitbag_rgr;
	class B_AssaultPack_blk;
	class JLTS_Clone_P2_DC15A;
	class JLTS_Droid_B1_E5;
	class JLTS_B1_Backpack;
	class JLTS_B1_antenna;
	class JLTS_Clone_RTO_pack;
	class JLTS_Clone_Backpack;
	class JLTS_Clone_Backpack_rto;
	class JLTS_Clone_jumppack_mc;
	class JLTS_Clone_LR_attachment;
	class WBK_B2_Mod_Standart;
	class WBK_BX_Assasin_1;
	class ls_reinsertTerminal;
	class lsd_gar_bodyGlove_base;
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
	
	class FST_ReinsertTerminal: ls_reinsertTerminal 
	{
        scope = 2;
        scopeCurator = 2;
        author = "Ruby";
        displayName = "[41st] Reinsert Terminal";
		model="3AS\3AS_Props\Terminals\Terminal_Console.p3d";
		hiddenSelections[]=
		{
			"camo1";
		};
		hiddenselectionstextures[]=
		{
			"3AS\3AS_Props\Terminals\data\base_co.paa";
		};	
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Terminals\data\base_co.paa";
		};
		editorCategory="FST_Crates";
		editorSubcategory="FST_Supplies";
		vehicleClass = "Structures";
        simulation = "thingx";
	};
	class FST_AmmoCrate: Box_NATO_Ammo_F
	{
		author="Daara";
		displayName="[41st] Ammo Crate";
		editorCategory="FST_Crates";
		editorSubcategory="FST_Supplies";
		editorPreview="\MRC\JLTS\weapons\Crates\data\ui\editorPreviews\JLTS_Ammobox_weapons_GAR.jpg";
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Ammo\Supply_Large_Ammo_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Ammo\Supply_Large_Ammo.rvmat"
		};
		icon="iconCrateWpns";
		armor=1000;
		maximumLoad=50000;
		Scope=2;
		ScopeCurator=2;
		class TransportWeapons
		{
			class _xx_FST_RPS6_Disposable
			{
				weapon="FST_RPS6_Disposable";
				count=4;
			};
		};
		class TransportMagazines
		{
			class _xx_Laserbatteries
			{
				magazine="Laserbatteries";
				count=2;
			};
			class _xx_FST_blaster_cell_High
			{
				count=80;
				magazine="FST_blaster_cell_High_Blue";
			};
			class _xx_FST_blaster_cell
			{
				count=80;
				magazine="FST_blaster_cell_Blue";
			};
			class _xx_FST_blaster_cell_low
			{
				count=10;
				magazine="FST_blaster_cell_low_Blue";
			};
			class _xx_FST_blaster_scatter_cell
			{
				count=20;
				magazine="FST_blaster_scatter_cell_DP23_Blue";
			};
			class _xx_FST_thermal_slugmag_DP23
			{
				count=20
				magazine="FST_thermal_slug_mag_Blue";
			};
			class _xx_FST_blaster_cell_LE
			{
				count=15;
				magazine="FST_blaster_cell_LE_Blue";
			};
			class _xx_FST_blaster_battery
			{
				count=20;
				magazine="FST_blaster_battery_Blue";
			};
			class _xx_FST_thermal_coil_LP
			{
				count=20;
				magazine="FST_thermal_coil_LP_Blue";
			};
			class _xx_FST_thermal_coil_T15
			{
				count=10;
				magazine="FST_thermal_coil_T15_Blue";
			};
			class _xx_FST_blaster_cell_Valken
			{
				count=20;
				magazine="FST_blaster_cell_Valken_Blue";
			};
			class _xx_FST_blaster_cell_Overcharged
			{
				count=10;
				magazine="FST_blaster_cell_Overcharged_Blue";
			};
			class _xx_IDA_grenade_Smoke_mag
			{
				count=10;
				magazine="IDA_grenade_Smoke_mag";
			};
			class _xx_IDA_grenade_Smoke_Red_mag
			{
				count=10;
				magazine="IDA_grenade_Smoke_Red_mag";
			};
			class _xx_IDA_grenade_Smoke_Blue_mag
			{
				count=10;
				magazine="IDA_grenade_Smoke_Blue_mag";
			};
			class _xx_IDA_grenade_Smoke_Green_mag
			{
				count=10;
				magazine="IDA_grenade_Smoke_Green_mag";
			};
			class _xx_IDA_grenade_Smoke_Purple_mag
			{
				count=10;
				magazine="IDA_grenade_Smoke_Purple_mag";
			};
			class _xx_IDA_Smoke_LauncherGrenade
			{
				count=10;
				magazine="IDA_Smoke_LauncherGrenade";
			};
			class _xx_IDA_SmokeRed_LauncherGrenade
			{
				count=10;
				magazine="IDA_SmokeRed_LauncherGrenade";
			};
			class _xx_IDA_SmokeGreen_LauncherGrenade
			{
				count=10;
				magazine="IDA_SmokeGreen_LauncherGrenade";
			};
			class _xx_IDA_SmokeBlue_LauncherGrenade
			{
				count=10;
				magazine="IDA_SmokeBlue_LauncherGrenade";
			};
			class _xx_ACE_40mm_Flare_Red
			{
				count=6;
				magazine="ACE_40mm_Flare_Red";
			};
			class _xx_ACE_HuntIR_M203
			{
				count=5;
				magazine="ACE_HuntIR_M203";
			};
			class _xx_ACE_40mm_Flare_White
			{
				count=6;
				magazine="ACE_40mm_Flare_White";
			};
			class _xx_FST_blaster_battery_DC15L
			{
				count=20;
				magazine="FST_blaster_battery_DC15L_Blue";
			};
		};
		class TransportItems
		{
			class _xx_ACE_CableTie
			{
				name="ACE_CableTie";
				count=30;
			};
		};
	};
	class FST_ExplosiveCrate: Box_NATO_Ammo_F
	{
		author="Daara";
		displayName="[41st] Explosive Crate";
		editorCategory="FST_Crates";
		editorSubcategory="FST_Supplies";
		editorPreview="\MRC\JLTS\weapons\Crates\data\ui\editorPreviews\JLTS_Ammobox_weapons_GAR.jpg";
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Red\Supply_Large_Red_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Red\Supply_Large_Red.rvmat"
		};
		icon="iconCrateWpns";
		armor=1000;
		maximumLoad=50000;
		Scope=2;
		ScopeCurator=2;
		class TransportWeapons
		{
			class _xx_FST_RPS6_Disposable
			{
				weapon="FST_RPS6_Disposable";
				count=6;
			};
		};
		class TransportMagazines
		{
			class _xx_FST_HE_LauncherGrenade
			{
				count=20;
				magazine="FST_HE_LauncherGrenade";
			};
			class _xx_FST_RPS6_rocket
			{
				count=12;
				magazine="FST_RPS6_rocket";
			};
			class _xx_FST_RPS6_rocket_HE
			{
				count=12;
				magazine="FST_RPS6_rocket_HE";
			};
			class _xx_FST_FST_rocket_SR
			{
				count=6;
				magazine="FST_RPS6_rocket_SR";
			};	
			class _xx_FST_PLX1_Rocket
			{
				count=5;
				magazine="FST_PLX1_Rocket";
			};
			class _xx_FST_PLX1_AA_mag
			{
				count=5;
				magazine="FST_PLX1_AA_mag";
			};
			class _xx_FST_grenade_Detonator_mag
			{
				count=20;
				magazine="FST_grenade_Detonator_mag";
			};
			class _xx_FST_grenade_Penetrator_mag
			{
				count=8;
				magazine="FST_grenade_Penetrator_mag";
			};
			class _xx_IDA_explosive_Detpack_mag
			{
				count=8;
				magazine="IDA_explosive_Detpack_mag";
			};
			class _xx_FST_grenade_emp_mag
			{
				count=8;
				magazine="FST_grenade_emp_mag";
			};
		};
	};
	class FST_MedicalCrate: FST_AmmoCrate
	{
		displayName="[41st] Medical Crate";
		editorCategory="FST_Crates";
		editorSubcategory="FST_Supplies";
		editorPreview="\MRC\JLTS\weapons\Crates\data\ui\editorPreviews\JLTS_Ammobox_ammo_GAR.jpg";
		model="3as\3as_props\crates\models\supply_Large.p3d";
		Scope=2;
		ScopeCurator=2;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Medical\Supply_Large_Medical_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Medical\Supply_Large_Medical.rvmat"
		};
		icon="iconCrateAmmo";
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
		
		class TransportBackpacks
		{
			class _xx_FST_Backpack_Medic
			{ 
				Backpack="FST_Backpack_Medic";
				count=2;
			};
			class _xx_FST_Backpack_Jumppack_Medic
			{ 
				Backpack="FST_Backpack_Jumppack_Medic";
				count=2;
			};
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=200;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=20;
				name="ACE_PlasmaIV";
			};
			class _xx_ACE_PlasmaIV_500
			{
				count=20;
				name="ACE_PlasmaIV_500";
			};
			class _xx_IDA_BattleStim
			{
				count=50;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=50;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=30;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=40;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=5;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=5;
				name="FST_Bacta_Tank";
			};
		};	
	};
	class FST_ExplodeFuelBarrel_1: Box_NATO_Ammo_F 
{
	displayName="[41st] Fuel Barrel";
	editorCategory="FST_Crates";
	editorSubcategory="FST_Supplies";
	editorPreview="3as\3as_props\Crates\EditorPreviews\Land_3as_ExplodeBarrel_1.jpg";
	model="3as\3as_props\crates\models\3as_small_fuel_barrel.p3d";
	armor=1000;
	maximumLoad=2;
	Scope=2;
	ScopeCurator=2;	
	ace_refuel_fuelCargo=3200;
	ace_refuel_hooks[] = {{0, 0, 0.5}};
		ace_refuel_hoseLength=25;
		eden=1;
	};
	class FST_ExplodeFuelBarrel_2: Box_NATO_Ammo_F 
{
	displayName="[41st] Fuel Barrel (Logi ITT)";
	editorCategory="FST_Crates";
	editorSubcategory="FST_Supplies";
	editorPreview="3as\3as_props\Crates\EditorPreviews\Land_3as_ExplodeBarrel_1.jpg";
	model="3as\3as_props\crates\models\3as_small_fuel_barrel.p3d";
	armor=1000;
	maximumLoad=2;
	Scope=2;
	ScopeCurator=2;	
	ace_refuel_fuelCargo=900000;
	ace_refuel_hooks[] = {{0, 0, 0.5}};
		ace_refuel_hoseLength=25;
		eden=1;
	};
	
	//////////////Backpacks////////////////
	class 3AS_Katarn_Backpack_Base;
	class FST_Commando_Backpack: 3AS_Katarn_Backpack_Base
	{
		scope=2;
		displayName="[41st] Commando Backpack";
		Picture="FST_212th_Armor\Data\Backpack\UI\Katarn_Backpack_Unmarked_UI_ca.paa"
		maximumLoad=250;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Commando_Backpack.paa"
		};
	};
	class FST_blueforWeaponBag_base: Weapon_Bag_Base
	{
		author="Legion Studios";
		scope=0;
		picture="";
		editorCategory="ls_static";
		displayname="==BLUEFOR WEAPON BAG BASE==";
		model="";
		maximumload=250;
		hiddenselections[]={};
	};
	class FST_Clone_Backpack: JLTS_Clone_Backpack
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
	};
	class FST_Clone_Backpack_RPS: JLTS_Clone_Backpack
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (RPS)";
		maximumload=240;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
	};
	class FST_Clone_Backpack_RifleAT: JLTS_Clone_Backpack
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (RifleAT)";
		maximumload=350;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
	};
	class FST_Clone_Backpack_PLX: JLTS_Clone_Backpack
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (PLX)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
	};
	class FST_Clone_Backpack_Dirty: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Dirty)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_Backpack_Dirty.paa"
		};
	};
	class FST_Clone_Backpack_Invisible: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible)";
		maximumload=400;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_STD: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/STD)";
		maximumload=320;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_Z6: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/Z6)";
		maximumload=315;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_15L: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/15L)";
		maximumload=340;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_RPS: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/RPS)";
		maximumload=240;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_PLX: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/PLX)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_Backpack_Invisible_RifleAT: JLTS_Clone_Backpack
	{
		author="Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Invisible/RifleAT)";
		maximumload=280;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
	};
	class FST_Clone_backpack_s: FST_Clone_backpack
	{
		displayName="[41st] Clone Backpack (Straps)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackStraps.p3d";
	};
	/* class FST_Clone_Backpack_ARF: FST_Clone_backpack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] ARF Camo Backpack";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_ARF_backpack_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
	}; */
	class FST_Clone_Backpack_ARC: FST_Clone_backpack
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] ARC Backpack";
		maximumload=320;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackARC.p3d";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_backpack_arc_co.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	/* class FST_ARF_backpack_s: FST_Clone_Backpack_ARF
	{
		displayName="[41st] ARF Camo Backpack (Straps)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackStraps.p3d";
	}; */
	class FST_Clone_backpack_Woodland: FST_Clone_backpack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Woodland)";
		maximumload=400;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
	};
	class FST_Clone_backpack_Midnight: FST_Clone_backpack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Midnight)";
		maximumload=400;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
	};
	class FST_Clone_backpack_Urban: FST_Clone_backpack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Urban)";
		maximumload=400;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_Backpack_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
	};
	class FST_Clone_backpack_Desert: FST_Clone_backpack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (Desert)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
	};
	class FST_belt_bag: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=250;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
	};
	class FST_belt_bag_CQB: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=170;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag (CQB)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
	};
	class FST_belt_bag_GRN: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=208;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag (Grenadier)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
	};
	class FST_belt_bag_15L: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=224;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag (15L)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
	};
	class FST_belt_bag_Z6: B_AssaultPack_blk
	{
		author="Daara";
		scope=2;
		maximumload=180;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_belt_bag_ui_ca.paa";
		displayName="[41st] Belt Bag (Z6)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBeltBag.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa"
		};
	};
	class FST_Backpack_Medic: FST_Clone_backpack
	{
		author="Daara";
		displayName="[41st] Medic Backpack";
		maximumload=250;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_Medic_backpack_co.paa"
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=80;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=6;
				name="ACE_PlasmaIV";
			};
			class _xx_ACE_PlasmaIV_500
			{
				count=8;
				name="ACE_PlasmaIV_500";
			};
			class _xx_IDA_BattleStim
			{
				count=15;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=6;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=6;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=6;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=1;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=1;
				name="FST_Bacta_Tank";
			};			
		};
	};
	class FST_Backpack_CrewChief: FST_Clone_backpack
	{
		author="Daara";
		displayName="[41st] Crew Chief Backpack";
		maximumload=250;
		hiddenSelections[]=
		{
			"camo1"
		};
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=100;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=10;
				name="ACE_PlasmaIV";
			};
			class _xx_IDA_BattleStim
			{
				count=10;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=10;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=10;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=10;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=1;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=1;
				name="FST_Bacta_Tank";
			};			
		};
	};
	class FST_Clone_backpack_EOD: FST_Clone_backpack
	{
		displayName="[41st] Clone EOD Backpack";
		maximumload=390;
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_EOD_backpack_co.paa"
		};
		class TransportItems
		{
			class _xx_IDA_explosive_Detpack_mag
			{
				count=5;
				name="IDA_explosive_Detpack_mag";
			};
			class _xx_DBA_ImploderBlock_mag
			{
				count=2;
				name="DBA_ImploderBlock_mag";
			};
			class _xx_ACE_DefusalKit
			{
				count=1;
				name="ACE_DefusalKit";
			};
			class _xx_ACE_M26_Clacker
			{
				count=1;
				name="ACE_M26_Clacker";
			};
			class _xx_MineDetector
			{
				count=1;
				name="MineDetector";
			};
		};
	};
	class FST_Backpack_Jumppack_EOD: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=390;
		displayName="[41st] Jump Pack (Engineer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Engineer.paa"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
			class _xx_IDA_explosive_Detpack_mag
			{
				count=5;
				name="IDA_explosive_Detpack_mag";
			};
			class _xx_DBA_ImploderBlock_mag
			{
				count=2;
				name="DBA_ImploderBlock_mag";
			};
			class _xx_ACE_DefusalKit
			{
				count=1;
				name="ACE_DefusalKit";
			};
			class _xx_ACE_M26_Clacker
			{
				count=1;
				name="ACE_M26_Clacker";
			};
			class _xx_MineDetector
			{
				count=1;
				name="MineDetector";
			};
		};
	};
/* 	class FST_Backpack_Jumppack_EOD_Test: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=400;
		displayName="[41st] Jump Pack (Engineer/Test)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Engineer.paa"
		}; 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; 
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		NSM_jumppack_is_jumppack=1;
		NSM_jumppack_spam_delay=1;
		NSM_jumppack_energy_capacity=100;
		NSM_jumppack_recharge=7.6;
		NSM_jumppack_jump_effect_script="NSM_jumppack_effect_fnc_jt_21";
		NSM_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		NSM_jumppack_sound_ignite[]=
		{
			"NSM_Main\sounds\cdv21Start.ogg"
		};
		NSM_jumppack_sound_land[]=
		{
			"NSM_Main\sounds\cdv21End.ogg"
		};
		NSM_jumppack_sound_idle[]=
		{
			"NSM_Main\sounds\cdv21Idle.ogg"
		};
		NSM_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
			class _xx_IDA_explosive_Detpack_mag
			{
				count=5;
				name="IDA_explosive_Detpack_mag";
			};
			class _xx_DBA_ImploderBlock_mag
			{
				count=2;
				name="DBA_ImploderBlock_mag";
			};
			class _xx_ACE_DefusalKit
			{
				count=1;
				name="ACE_DefusalKit";
			};
			class _xx_ACE_M26_Clacker
			{
				count=1;
				name="ACE_M26_Clacker";
			};
			class _xx_MineDetector
			{
				count=1;
				name="MineDetector";
			};
		};
	}; */
	class FST_Clone_backpack_RTO: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTO Backpack";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		maximumload=170;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_RTO_UGL: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTOUGL Backpack";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		maximumload=300;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_RTO_Woodland: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTO Backpack (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
		maximumload=300;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_RTO_Desert: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTO Backpack (Desert)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
		maximumload=300;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_RTO_Urban: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTO Backpack (Urban)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
		maximumload=300;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_RTO_Midnight: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Clone RTO Backpack (Midnight)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_backpack.rvmat"
		};
		maximumload=300;
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
	class FST_Clone_backpack_s_RTO: FST_Clone_backpack_RTO
	{
        maximumload=300;
		displayName="[41st] Clone RTO Backpack (Straps)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTOStraps.p3d";
	};
	/* class FST_ARF_backpack_RTO: FST_Clone_Backpack_ARF
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] ARF Camo RTO Backpack";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_ARF_backpack_co.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	};
		class FST_ARF_backpack_s_RTO: FST_ARF_backpack_RTO
	{
		displayName="[41st] ARF Camo RTO Backpack (Straps)";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTOStraps.p3d";
	}; */
	class FST_Zeus_backpack: FST_Clone_backpack
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] Zeus RTO Backpack";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTOStraps.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Clone_backpack_co.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=100000;
		tf_subtype="digital_lr";
	};
	class FST_Zeus_LR_attachment: JLTS_Clone_LR_attachment
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_LR_attachment_ui_ca.paa";
		displayName="[41st] Zeus LR Attachment";
		model="\MRC\JLTS\characters\CloneArmor\CloneLRattachment.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_LR_attachment_co.paa"
		};
		maximumload=250;
		tf_dialog="JLTS_clone_lr_programmer_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=100000;
		tf_subtype="digital_lr";
		mass=11;
	};
	class FST_Backpack_RTO_Hidden: JLTS_Clone_backpack_RTO
	{
		displayName="[41st] Hidden RTO Pack";
		tf_dialog="JLTS_clone_lr_programmer_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=100000;
		tf_subtype="digital_lr";
		model="\a3\weapons_f\empty.p3d";
	};
	class FST_Clone_LR_attachment: JLTS_Clone_LR_attachment
	{
		author="Daara";
		scope=2;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_LR_attachment_ui_ca.paa";
		displayName="[41st] LR Attachment";
		model="\MRC\JLTS\characters\CloneArmor\CloneLRattachment.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_LR_attachment_co.paa"
		};
		maximumload=250;
		tf_dialog="JLTS_clone_lr_programmer_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
		mass=11;
	};
	class FST_Backpack_Antenna: JLTS_Clone_RTO_pack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini RTO Pack";
		maximumload=340;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack.paa",
		};
		tf_range=50000;
	};
	class FST_Backpack_Antenna_Woodland: JLTS_Clone_RTO_pack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini RTO Pack (Woodland)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Mini_RTO_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	};
	class FST_Backpack_Antenna_Desert: JLTS_Clone_RTO_pack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini RTO Pack (Desert)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Mini_RTO_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	};
	class FST_Backpack_Antenna_Midnight: JLTS_Clone_RTO_pack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini RTO Pack (Midnight)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Mini_RTO_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	};
	class FST_Backpack_Antenna_Urban: JLTS_Clone_RTO_pack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini RTO Pack (Urban)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Mini_RTO_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	};
	class FST_Backpack_Antenna_ARF_Dirty: JLTS_Clone_RTO_pack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini ARF RTO Pack [Dirty]";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Dirty.paa",
		};
		tf_range=50000;
	};
//OLD 	
/*	class FST_Backpack_Antenna_ARF_Desert: JLTS_Clone_RTO_pack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini ARF RTO Pack [Desert]";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	};*/
	/* class FST_Backpack_Antenna_ARF_Woodland: JLTS_Clone_RTO_pack
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Mini ARF RTO Pack [Woodland]";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneRTOPack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_RTO_pack.rvmat"
		};
		tf_range=50000;
	}; */
	class FST_Backpack_Jumppack: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Ammo Bearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_GRN: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=208;
		displayName="[41st] Jump Pack (GRN)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_CQB: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=170;
		displayName="[41st] Jump Pack (CQB)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Woodland: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=320;
		displayName="[41st] Jump Pack (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Desert: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=320;
		displayName="[41st] Jump Pack (Desert)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Urban: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=320;
		displayName="[41st] Jump Pack (Urban)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Midnight: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=320;
		displayName="[41st] Jump Pack (Midnight)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_STD_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=320;
		displayName="[41st] Jump Pack (STD AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_15L_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=340;
		displayName="[41st] Jump Pack (15L AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_RifleAT_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=280;
		displayName="[41st] Jump Pack (Rifle AT AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_15L: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=200;
		displayName="[41st] Jump Pack (15L)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_RifleAT: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=350;
		displayName="[41st] Jump Pack (RifleAT)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Z6: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=180;
		displayName="[41st] Jump Pack (Z6)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_Z6_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=315;
		displayName="[41st] Jump Pack (Z6 AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_PLX_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (PLX AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_RPS_Ammo: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=240;
		displayName="[41st] Jump Pack (RPS AmmoBearer)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_PLX: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (PLX)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_RPS: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=240;
		displayName="[41st] Jump Pack (RPS)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script=""; //DBA_jumppack_effect_fnc_jt_21
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
/* 	class FST_Backpack_Jumppack_Test: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Ammo Bearer/Test)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; 
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		NSM_jumppack_is_jumppack=1;
		NSM_jumppack_spam_delay=1;
		NSM_jumppack_energy_capacity=100;
		NSM_jumppack_recharge=7.6;
		NSM_jumppack_jump_effect_script="NSM_jumppack_effect_fnc_jt_21";
		NSM_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		NSM_jumppack_sound_ignite[]=
		{
			"NSM_Main\sounds\cdv21Start.ogg"
		};
		NSM_jumppack_sound_land[]=
		{
			"NSM_Main\sounds\cdv21End.ogg"
		};
		NSM_jumppack_sound_idle[]=
		{
			"NSM_Main\sounds\cdv21Idle.ogg"
		};
		NSM_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	}; */
	class FST_Backpack_Jumppack_Grinch: JLTS_Clone_jumppack_mc
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Grinch)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=0;
		DBA_jumppack_energy_capacity=150;
		DBA_jumppack_recharge=10;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Forward Jump",
				{12,20,50,0,0,0}
			},
			
			{
				"Short Jump",
				{12,5,30,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_JORGE_Jumppack_Boss: JLTS_Clone_jumppack_mc
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Jorge/Boss)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Jorge.paa"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=0;
		DBA_jumppack_energy_capacity=150;
		DBA_jumppack_recharge=10;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Forward Jump",
				{12,20,50,0,0,0}
			},
			
			{
				"Short Jump",
				{12,5,30,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	/* class FST_Backpack_Jumppack_ARF_Woodland: JLTS_Clone_jumppack_mc
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] ARF Jump Pack (Woodland)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_jumppack.rvmat"
		};
 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=0;
		DBA_jumppack_energy_capacity=150;
		DBA_jumppack_recharge=10;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Forward Jump",
				{12,20,50,0,0,0}
			},
			
			{
				"Short Jump",
				{12,5,30,0,1,0}
			}
		};
		class TransportItems
		{
		};
	}; */
	class FST_Backpack_Jumppack_Medic: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Medic)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_medic.paa"
		};
		hiddenSelectionsMaterials[]=	
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=80;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=6;
				name="ACE_PlasmaIV";
			};
			class _xx_ACE_PlasmaIV_500
			{
				count=8;
				name="ACE_PlasmaIV_500";
			};
			class _xx_IDA_BattleStim
			{
				count=15;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=6;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=6;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=6;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=1;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=1;
				name="FST_Bacta_Tank";
			};			
		};
	};
/* 	class FST_Backpack_Jumppack_Medic_Test: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (Medic/Test)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_medic.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		NSM_jumppack_is_jumppack=1;
		NSM_jumppack_spam_delay=1;
		NSM_jumppack_energy_capacity=100;
		NSM_jumppack_recharge=7.6;
		NSM_jumppack_jump_effect_script="NSM_jumppack_effect_fnc_jt_21";
		NSM_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		NSM_jumppack_sound_ignite[]=
		{
			"NSM_Main\sounds\cdv21Start.ogg"
		};
		NSM_jumppack_sound_land[]=
		{
			"NSM_Main\sounds\cdv21End.ogg"
		};
		NSM_jumppack_sound_idle[]=
		{
			"NSM_Main\sounds\cdv21Idle.ogg"
		};
		NSM_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=80;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=6;
				name="ACE_PlasmaIV";
			};
			class _xx_ACE_PlasmaIV_500
			{
				count=8;
				name="ACE_PlasmaIV_500";
			};
			class _xx_IDA_BattleStim
			{
				count=15;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=6;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=6;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=6;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=1;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=1;
				name="FST_Bacta_Tank";
			};			
		};
	}; */
	class FST_Backpack_Jumppack_Rifleman: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=10;
		displayName="[41st] Jump Pack (Rifleman)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
/* 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; */
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
/* 	class FST_Backpack_Jumppack_Rifleman_Test: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=10;
		displayName="[41st] Jump Pack (Rifleman/Test)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000; 
		tf_hasLRradio=0;
		JLTS_isJumppack=0;
		NSM_jumppack_is_jumppack=1;
		NSM_jumppack_spam_delay=1;
		NSM_jumppack_energy_capacity=100;
		NSM_jumppack_recharge=7.6;
		NSM_jumppack_jump_effect_script="NSM_jumppack_effect_fnc_jt_21";
		NSM_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		NSM_jumppack_sound_ignite[]=
		{
			"NSM_Main\sounds\cdv21Start.ogg"
		};
		NSM_jumppack_sound_land[]=
		{
			"NSM_Main\sounds\cdv21End.ogg"
		};
		NSM_jumppack_sound_idle[]=
		{
			"NSM_Main\sounds\cdv21Idle.ogg"
		};
		NSM_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	}; */
	class FST_Backpack_Invisible_Jumppack: JLTS_Clone_jumppack_mc
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=400;
		displayName="[41st] Jump Pack (Invisible)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
 		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_LR: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=340;
		displayName="[41st] Jump Pack (LR)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	class FST_Backpack_Jumppack_LR_UGL: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=300;
		displayName="[41st] Jump Pack (LR/UGL)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
/* 	class FST_Backpack_Jumppack_LR_Test: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Jump Pack (LR/Test)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_jumppack.rvmat"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		NSM_jumppack_is_jumppack=1;
		NSM_jumppack_spam_delay=1;
		NSM_jumppack_energy_capacity=100;
		NSM_jumppack_recharge=7.6;
		NSM_jumppack_jump_effect_script="NSM_jumppack_effect_fnc_jt_21";
		NSM_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		NSM_jumppack_sound_ignite[]=
		{
			"NSM_Main\sounds\cdv21Start.ogg"
		};
		NSM_jumppack_sound_land[]=
		{
			"NSM_Main\sounds\cdv21End.ogg"
		};
		NSM_jumppack_sound_idle[]=
		{
			"NSM_Main\sounds\cdv21Idle.ogg"
		};
		NSM_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	}; */
	class FST_Backpack_Descentpack: JLTS_Clone_jumppack_mc
	{
		author="Daara";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=250;
		displayName="[41st] Fynock Descent Pack";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_jumppack_mc_co.paa"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=0.001;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			
			{
				"Break Fall",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems
		{
		};
	};
	/* class FST_ARF_backpack_RTO_Woodland: FST_Backpack_Antenna
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] ARF Camo RTO Backpack [Woodland]";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Woodland.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	}; */
	/* class FST_ARF_backpack_RTO_Desert: FST_Backpack_Antenna
	{
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_backpack_ui_ca.paa";
		displayName="[41st] ARF Camo RTO Backpack [Desert]";
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpackRTO.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Radio_Backpack_Desert.paa"
		};
		tf_dialog="JLTS_clone_rto_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
		tf_range=50000;
		tf_subtype="digital_lr";
	}; */
	class FST_Backpack_GM_Base: JLTS_Clone_backpack
	{
		author="Schlabbie And Maxim";
		scope=2;
		maximumload=320;
		displayName="[41st] Cold Weather Backpack";
		model="\JLTS_AE_GM\SEA_Backpack_GM_Base.p3d";
		hiddenSelectionsTextures[]=
		{
			"\JLTS_AE_GM\data\BaseTextures\Backpack\Backpack_ca.paa"
		};
	};
	class JLTS_Clone_backpack_eod;
	class FST_Backpack_GM_EOD: JLTS_Clone_backpack_eod
	{
		author="Schlabbie And Maxim";
		scope=2;
		scopecurator=2;
		displayName="[41st] Cold Weather EOD Backpack";
		model="\JLTS_AE_GM\SEA_Backpack_GM_Base.p3d";
		hiddenSelectionsTextures[]=
		{
			"\JLTS_AE_GM\data\BaseTextures\Backpack\Backpack_EOD.paa"
		};
		maximumload=400;
		class TransportItems
		{
			class _xx_IDA_explosive_Detpack_mag
			{
				count=5;
				name="IDA_explosive_Detpack_mag";
			};
			class _xx_DBA_ImploderBlock_mag
			{
				count=2;
				name="DBA_ImploderBlock_mag";
			};
			class _xx_ACE_DefusalKit
			{
				count=1;
				name="ACE_DefusalKit";
			};
			class _xx_ACE_M26_Clacker
			{
				count=1;
				name="ACE_M26_Clacker";
			};
			class _xx_MineDetector
			{
				count=1;
				name="MineDetector";
			};
		};
	};
	class JLTS_Clone_backpack_medic;
	class FST_Backpack_GM_Medic: JLTS_Clone_backpack_medic
	{
		author="Schlabbie And Maxim";
		scope=2;
		scopecurator=2;
		maximumload=250;
		displayName="[41st] Cold Weather Medic Backpack";
		model="\JLTS_AE_GM\SEA_Backpack_GM_Medic.p3d";
		hiddenSelectionsTextures[]=
		{
			"\JLTS_AE_GM\data\BaseTextures\Backpack\Medic\BackpackMedic_ca.paa"
		};
		class TransportItems
		{
			class _xx_IDA_BactaBandage
			{
				count=80;
				name="IDA_BactaBandage";
			};
			class _xx_ACE_PlasmaIV
			{
				count=6;
				name="ACE_PlasmaIV";
			};
			class _xx_ACE_PlasmaIV_500
			{
				count=8;
				name="ACE_PlasmaIV_500";
			};
			class _xx_IDA_BattleStim
			{
				count=15;
				name="IDA_BattleStim";
			};
			class _xx_ACE_Adenosine
			{
				count=6;
				name="ACE_Adenosine";
			};
			class _xx_ACE_Splint
			{
				count=6;
				name="ACE_Splint";
			};
			class _xx_ACE_tourniquet
			{
				count=6;
				name="ACE_tourniquet";
			};
			class _xx_IDA_Cauterizer
			{
				count=1;
				name="IDA_Cauterizer";
			};
			class _xx_FST_Bacta_Tank
			{
				count=1;
				name="FST_Bacta_Tank";
			};			
		};
	};
	class FST_Backpack_GM_RTO: JLTS_Clone_backpack_RTO
	{
		author="Schlabbie And Maxim";
		scope=2;
		scopecurator=2;
		maximumload=320;
		tf_range=50000;
		displayName="[41st] Cold Weather RTO Backpack";
		model="\JLTS_AE_GM\SEA_Backpack_GM_RTO.p3d";
		hiddenselections[]=
		{
			"Camo1",
			"Camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\JLTS_AE_GM\data\BaseTextures\Backpack\RTO\Backpack_Base_ca.paa",
			"\JLTS_AE_GM\data\BaseTextures\Backpack\RTO\Backpack_RTO_ca.paa"
		};
		tf_dialog="JLTS_clone_lr_programmer_radio_dialog";
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_hasLRradio=1;
	};
/*	class FST_Backpack_Jumppack_Ares: FST_Backpack_Jumppack
	{
		author="Gold";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		maximumload=340;
		displayName="[41st] Jump Pack (Ares)";
		model="\MRC\JLTS\characters\CloneArmor\CloneJumppackMC.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_jumppack_mc_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Ares.paa"
		};
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_encryptionCode="tf_west_radio_code";
		tf_dialog="anarc210_radio_dialog";
		tf_subtype="digital_lr";
		tf_range=50000;
		tf_hasLRradio=1;
		JLTS_isJumppack=0;
		DBA_jumppack_is_jumppack=1;
		DBA_jumppack_spam_delay=1;
		DBA_jumppack_energy_capacity=100;
		DBA_jumppack_recharge=7.6;
		DBA_jumppack_jump_effect_script="";
		DBA_jumppack_effect_points[]=
		{
			{
				"spine3",
				{0,-0.30000001,-0.1}
			}
		};
		DBA_jumppack_sound_ignite[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Start.ogg"
		};
		DBA_jumppack_sound_land[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21End.ogg"
		};
		DBA_jumppack_sound_idle[]=
		{
			"DBA_Core\Addons\DBA_JumpPack\jumppack\Sounds\cdv21Idle.ogg"
		};
		DBA_jumppack_jump_types[]=
		{
			{
				"Short Jump",
				{12,2,100,0,1,0}
			}
		};
		class TransportItems{};
	};
	class FST_Backpack_Jumppack_Ares_Dirty: FST_Backpack_Jumppack_Ares
	{
		author="Steel";
		displayname="[41st] Jump Pack (Ares/Dirty)"
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_AB_Jumppack_Ares_Dirty.paa"
		};
	} */
	//////////////Loadouts////////////////
	class FST_bodyGlove: lsd_gar_bodyGlove_base
	{
		author="Daara";
		displayName="[41st]";
		scope=2;
		scopeCurator=1;
		scopearsenal=1;
		Backpack="";
		side=1;
		identityTypes[]={};
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		uniformClass="FST_Uniform_Bodyglove";
		nakedUniform="FST_Uniform_Bodyglove";
		picture="\41st_Armor\Logo.paa";
		linkedItems[]=
		{
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		magazines[]={};
		respawnMagazines[]={};
		items[]={};
		respawnItems[]={};
	};
	class FST_Commando: B_Soldier_F
	{
		author="Gold";
		displayName="[41st] Republic Commando";
		scope=2;
		scopeCurator=2;
		scopearsenal=2;
		side=1;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO"
		};
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		uniformClass="FST_Commando_Uniform";
		nakedUniform="U_BasicBody";
		backpack="FST_Commando_Backpack";
		model="\3AS\3AS_Characters\Commando\3AS_Katarn_Armor.p3d";
		modelSides[]={3,1};
		hiddenSelections[]=
		{
			"Camo",
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Commando_Uniform.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		weapons[]=
		{
			"IDA_DC15S",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_DC15S",
			"Throw",
			"Put"
		};
		magazines[]={};
		respawnMagazines[]={};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		linkedItems[]=
		{
			"FST_Commando_Helmet",
			"FST_Commando_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_Commando_Helmet",
			"FST_Commando_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class UniformInfo
		{
			class SlotsInfo
			{
				class NVG: UniformSlotInfo
				{
					slotType=602;
				};
				class Scuba: UniformSlotInfo
				{
					slotType=604;
				};
				class Googles: UniformSlotInfo
				{
					slotType=603;
				};
				class Headgear: UniformSlotInfo
				{
					slotType=605;
				};
			};
		};
		class HitPoints: HitPoints
		{
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_Trooper_P2_DC15S: B_Soldier_F
	{
		author="Daara";
		displayName="[41st] Clone Trooper (DC-15S)";
		scope=2;
		scopeCurator=2;
		scopearsenal=2;
		Backpack="";
		side=1;
		identityTypes[]={};
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		uniformclass="FST_Trooper_Uniform";
		nakedUniform="";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower.paa",
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"IDA_Vest_DC15S",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"IDA_Vest_DC15S",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		weapons[]=
		{
			"IDA_DC15S",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_DC15S",
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_clone_scout_woodland: B_Soldier_F
	{
		author = "Ruby";
		scope = 2;
		scopeCurator=2;
		scopearsenal=2;
		displayname = "[41st] Clone Scout Trooper (Woodland)";
		model = "ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		uniformclass = "FST_cloneUniform_scout_woodland";
		nakeduniform = "FST_cloneUniform_scout_undersuit_woodland";
		hiddenselections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Woodland.paa",
			"41st_Armor\Data\Uniforms\FST_Scout_Armor_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ls\core\addons\characters_clone\uniforms\scout\data\camo1.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Scout_Armor.rvmat"
		};
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		linkedItems[]=
		{
			"FST_cloneHelmet_scout_woodland",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_cloneHelmet_scout_woodland",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_clone_scout_undersuit_woodland: FST_clone_scout_woodland
	{
		displayname = "[41st] Clone Scout Trooper Undersuit (Woodland)";
		hiddenSelectionsTextures[]= 
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Woodland.paa",
			""
		};
	};
	class FST_clone_scout_Midnight: B_Soldier_F
	{
		scope = 2;
		scopeCurator=2;
		scopearsenal=2;
		displayname = "[41st] Clone Scout Trooper (Midnight)";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		model = "ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		uniformclass = "FST_cloneUniform_scout_Midnight";
		nakedUniform = "FST_cloneUniform_scout_undersuit_Midnight";
		hiddenselections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Midnight.paa",
			"41st_Armor\Data\Uniforms\FST_Scout_Armor_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ls\core\addons\characters_clone\uniforms\scout\data\camo1.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Scout_Armor.rvmat"
		};
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		linkedItems[]=
		{
			"FST_cloneHelmet_scout_Midnight",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_cloneHelmet_scout_Midnight",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_clone_scout_undersuit_Midnight: FST_clone_scout_Midnight
	{
		displayname = "[41st] Clone Scout Trooper Undersuit (Midnight)";
		hiddenSelectionsTextures[]= 
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Midnight.paa",
			""
		};
	};
	class FST_clone_scout_Desert: B_Soldier_F
	{
		scope = 2;
		scopeCurator=2;
		scopearsenal=2;
		displayname = "[41st] Clone Scout Trooper (Desert)";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		model = "ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		uniformclass = "FST_cloneUniform_scout_Desert";
		nakeduniform = "FST_cloneUniform_scout_Desert";
		hiddenselections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Desert.paa",
			"41st_Armor\Data\Uniforms\FST_Scout_Armor_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"ls\core\addons\characters_clone\uniforms\scout\data\camo1.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Scout_Armor.rvmat"
		};
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		linkedItems[]=
		{
			"FST_cloneHelmet_scout_Desert",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_cloneHelmet_scout_Desert",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_clone_scout_undersuit_Desert: FST_clone_scout_Desert
	{
		displayname = "[41st] Clone Scout Trooper Undersuit (Desert)";
		hiddenSelectionsTextures[]= 
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Desert.paa",
			""
		};
	};
	class FST_clone_scout_Urban: B_Soldier_F
	{
		scope = 2;
		scopeCurator=2;
		scopearsenal=2;
		displayname = "[41st] Clone Scout Trooper (Urban)";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		model = "ls\core\addons\characters_clone\uniforms\scout\ls_uniform_clone_scout.p3d";
		uniformclass = "FST_cloneUniform_scout_Urban";
		nakeduniform = "FST_cloneUniform_scout_Urban";
		hiddenselections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsMaterials[]=
		{
			"ls\core\addons\characters_clone\uniforms\scout\data\camo1.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Scout_Armor.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Urban.paa",
			"41st_Armor\Data\Uniforms\FST_Scout_Armor_Urban.paa"
		};
		weapons[]=
		{
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		linkedItems[]=
		{
			"FST_cloneHelmet_scout_Urban",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_cloneHelmet_scout_Urban",
			"itemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_clone_scout_undersuit_Urban: FST_clone_scout_Urban
	{
		displayname = "[41st] Clone Scout Trooper Undersuit (Urban)";
		hiddenSelectionsTextures[]= 
		{
			"41st_Armor\Data\Uniforms\FST_Scout_Uniform_Urban.paa",
			""
		};
	};
	class FST_Trooper_P2_DC15A: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Trooper (DC-15A)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Subfaction";
		uniformclass="FST_Trooper_Uniform";
		nakedUniform="";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelectionsMaterials[]=
		{
			"Indecisive_Armoury_units\REPUBLIC\Data\Clone_Uniform\IDA_P2_BodyUpper.rvmat",
			"Indecisive_Armoury_units\REPUBLIC\Data\Clone_Uniform\IDA_P2_BodyLower.rvmat",
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Other\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Clone_Armor_P2_Lower.rvmat",
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"IDA_Vest_DC15A",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"IDA_Vest_DC15A",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		weapons[]=
		{
			"IDA_DC15A",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_DC15S",
			"Throw",
			"Put"
		};
		magazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		respawnMagazines[]=
		{
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Green_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Blue_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_Red_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"IDA_grenade_Smoke_mag",
			"FST_grenade_Detonator_mag",
			"IDA_blaster_cell",
		};
		items[]=
		{
			"ACE_EntrenchingTool",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
		respawnItems[]=
		{
			
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_tourniquet",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_Splint",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_PlasmaIV_500",
			"ACE_Spraypaintgreen",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"ACE_CableTie",
			"WBK_HeadLampItem",
			"acc_flashlight",
			"Laserbatteries",
		};
	};
	class FST_Pilot_P1: FST_Trooper_P2_DC15S
	{
		author="Daara";
		scope=2;
		displayName="[41st] Clone Pilot (Fynock Squadron)";
		Backpack="";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Spec_Subfaction";
		uniformclass="FST_Pilot_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower.paa",
		};
		weapons[]=
		{
			"IDA_DC15S",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"IDA_DC15S",
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_Pilot_P1_Helmet",
			"IDA_Vest_DC15S",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_Pilot_P1_Helmet",
			"IDA_Vest_DC15S",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_EOD: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] EOD P2 Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_EOD";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_EOD.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_EOD",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",	
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_EOD",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_ARF: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] ARF Trooper (Camo)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_ARF_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_ARF_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_ARF_BodyLower.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_ARF_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_ARF_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_ARF_Urban: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st] ARF Trooper (Urban)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Urban";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_ARF_BodyUpper_Urban.paa",
			"41st_Armor\Data\Uniforms\FST_ARF_BodyLower_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_ARF_Helmet_Urban",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_ARF_Helmet_Urban",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_SERE: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] SERE Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_SERE";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Sere",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Sere",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_ARF_WhiteGreen: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] ARF Trooper (White/Green)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_ARF_Uniform_WhiteGreen";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_ARF_BodyUpper_WhiteGreen.paa",
			"41st_Armor\Data\Uniforms\FST_ARF_BodyLower_WhiteGreen.paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_ARF_Helmet_WhiteGreen",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_ARF_Helmet_WhiteGreen",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_SCT: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Senior Clone Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_SCT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_SCT.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_SCT_Medic: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Senior Clone Trooper (Medic)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_SCT_Medic";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Medic.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_SCT.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_VCT: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Veteran Clone Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_VCT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_VCT.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_VCT_Medic: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Veteran Clone Trooper (Medic)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_VCT_Medic";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Medic.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_VCT.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_CLC: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Lance Corporal";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_CLC";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_CLC.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_CPL: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Corporal";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_CPL";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_CPL.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_CS: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Sergeant";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_CS";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_CS.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_CSS: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Staff Sergeant";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_CSS";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_CSS.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P2_CL: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Lieutenant";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_CL";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_CL.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_P2_Medic: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Medic Armor";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Trooper_Medic";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Medic.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
 /*	class FST_ARF_Woodland: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] ARF Trooper (Woodland)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Arf_Uniform_Woodland";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_ARF_BodyUpper_Woodland.Paa",
			"41st_Armor\Data\Uniforms\FST_ARF_BodyLower_Woodland.Paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_ARF_Helmet_Woodland",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_ARF_Helmet_Woodland",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	}; */
 	class FST_ARF_Desert: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] ARF Trooper (Desert)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Desert";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_ARF_BodyUpper_Desert.Paa",
			"41st_Armor\Data\Uniforms\FST_ARF_BodyLower_Desert.Paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_ARF_Helmet_Desert",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_ARF_Helmet_Desert",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class 3AS_Clone_Phase1;
	class 3as_Clone_P1;
	class FST_Trooper_P1: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3as_JLTS\Uniforms\data\P2_Armor_Upper.rvmat",
			"\3AS\3as_JLTS\Uniforms\data\P2_Armor_Lower.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_Base",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_Base",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_Trooper_P1_CMDR: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (CMDR)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_CMDR";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Phase1_Commander_upper_CO.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_CMDR",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_CMDR",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_CPT: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (CPT)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_CPT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Phase1_Captain_upper_CO.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_CPT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_CPT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_LT: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (LT)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_LT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Phase1_Lieutenant_upper_CO.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_LT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_LT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_SGT: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (SGT)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_SGT";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Phase1_Sergeant_upper_CO.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_SGT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_SGT",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (41st)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Sarlacc: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Sarlacc)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Sarlacc";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Sarlacc.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Sarlacc",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Sarlacc",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Wampa: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Wampa)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Wampa";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Wampa.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Wampa",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Wampa",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Krayt: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Krayt)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Krayt";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Krayt.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Krayt",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Krayt",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Nexu: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Nexu)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Nexu";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Nexu.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Nexu",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Nexu",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Radark: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Radark)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Radark";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Radark.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Radark",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Radark",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Zillo: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Zillo)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Zillo";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Zillo.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Zillo",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Zillo",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_Trooper_P1_41st_Kadoshi: FST_Trooper_P1
	{
		author="Daara";
		displayName="[41st] P1 Clone Trooper (Kadoshi)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_P1_41st_Kadoshi";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P1_BodyUpper_Kadoshi.paa",
			"\3AS\3as_JLTS\Uniforms\data\Phase1\Standard_Unmarked_Lower_CO.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P1_41st_Kadoshi",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P1_41st_Kadoshi",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic: FST_Trooper_P2_DC15S
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (DC15A)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		class HitPoints: HitPoints
		{
			
			class HitFace: HitFace
			{
				armor=1;
				material=-1;
				name="face_hub";
				passThrough=0.80000001;
				radius=0.079999998;
				explosionShielding=0.1;
				minimalHit=0.0099999998;
			};
			class HitNeck: HitNeck
			{
				armor=1;
				material=-1;
				name="neck";
				passThrough=0.80000001;
				radius=0.1;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
			};
			class HitHead: HitNeck
			{
				armor=1;
				material=-1;
				name="head";
				passThrough=0.80000001;
				radius=0.2;
				explosionShielding=0.5;
				minimalHit=0.0099999998;
				depends="HitFace max HitNeck";
			};
			class HitPelvis: HitHead
			{
				armor=8;
				material=-1;
				name="pelvis";
				passThrough=0.80000001;
				radius=0.23999999;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="";
			};
			class HitAbdomen: HitPelvis
			{
				armor=6;
				material=-1;
				name="spine1";
				passThrough=0.80000001;
				radius=0.16;
				explosionShielding=3;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitDiaphragm: HitAbdomen
			{
				armor=6;
				material=-1;
				name="spine2";
				passThrough=0.33000001;
				radius=0.18000001;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitChest: HitDiaphragm
			{
				armor=8;
				material=-1;
				name="spine3";
				passThrough="0.33000001radius = 0.18";
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
			};
			class HitBody: HitBody
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=6;
				visual="injury_body";
				minimalHit=0.0099999998;
				depends="HitPelvis max HitAbdomen max HitDiaphragm max HitChest";
			};
			class HitArms: HitBody
			{
				armor=6;
				material=-1;
				name="arms";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="0";
			};
			class HitHands: HitArms
			{
				armor=6;
				material=-1;
				name="hands";
				passThrough=1;
				radius=0.1;
				explosionShielding=1;
				visual="injury_hands";
				minimalHit=0.0099999998;
				depends="HitArms";
			};
			class HitLegs: HitHands
			{
				armor=6;
				material=-1;
				name="legs";
				passThrough=1;
				radius=0.14;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
				depends="0";
			};
			class Incapacitated: HitLegs
			{
				armor=1000;
				material=-1;
				name="body";
				passThrough=1;
				radius=0;
				explosionShielding=3;
				visual="";
				minimalHit=0;
				depends="(((Total - 0.25) max 0) + ((HitHead - 0.25) max 0) + ((HitBody - 0.25) max 0)) * 2";
			};
			class HitLeftArm: HitLegs
			{
				armor=6;
				material=-1;
				name="hand_l";
				passThrough=1;
				radius=0.079999998;
				explosionShielding=3;
				visual="injury_hands";
				minimalHit=0.0099999998;
			};
			class HitRightArm: HitLeftArm
			{
				name="hand_r";
			};
			class HitLeftLeg: HitLegs
			{
				armor=6;
				material=-1;
				name="leg_l";
				passThrough=1;
				radius=0.1;
				explosionShielding=3;
				visual="injury_legs";
				minimalHit=0.0099999998;
			};
			class HitRightLeg: HitLeftLeg
			{
				name="leg_r";
			};
		};
	};
	class FST_GM_Base_Plastic_NCO: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather NCO (DC15A)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_NCO";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_NCO.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet_NCO",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet_NCO",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Officer: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Officer (DC15A)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Officer";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Undersuit",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Officer.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet_Officer",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet_Officer",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Sarlacc: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Sarlacc)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Sarlacc";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Sarlacc.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Wampa: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Wampa)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Wampa";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Wampa.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Krayt: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Krayt)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Krayt";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Krayt.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Nexu: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Nexu)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Nexu";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Nexu.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Radark: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Radark)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Radark";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Radark.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Zillo: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Zillo)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Zillo";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Zillo.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Kadoshi: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Kadoshi)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Kadoshi";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Kadoshi.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Rancor: FST_GM_Base_Plastic
	{
		author="Steel";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Rancor)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Rancor";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Rancor.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Sanval: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Sanval)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Sanval";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Sanval.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Hydra: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Hydra)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Hydra";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Hydra.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Uvak: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Uvak)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Uvak";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Uvak.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Howler: FST_GM_Base_Plastic
	{
		author="Daara";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Howler)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Howler";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Howler.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Voxyn: FST_GM_Base_Plastic
	{
		author="Steel";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Voxyn)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Voxyn";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Voxyn.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Raxshir: FST_GM_Base_Plastic
	{
		author="Steel";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Raxshir)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Raxshir";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Raxshir.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Gharzr: FST_GM_Base_Plastic
	{
		author="Steel";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Gharzr)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Gharzr";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Gharzr.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_GM_Base_Plastic_Varactyl: FST_GM_Base_Plastic
	{
		author="Steel";
		scope=2;
		displayName="[41st] Cold Weather Trooper (Varactyl)";
		editorPreview="\MRC\JLTS\characters\CloneArmor\data\ui\editorPreviews\JLTS_Clone_P2_DC15A.jpg";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_GM_Plastic_Varactyl";
		backpack="";
		model="JLTS_AE_GM\SEA_Uniform_GM_Plastic.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"Uniform",
			"insignia"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Uniforms\FST_GM_BodyUpper_Varactyl.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_BodyLower.paa",
			"\41st_Armor\Data\Uniforms\FST_GM_Undersuit.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_GM_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	///////////////CUSTOM UNIFORMS///////////////
/*	class FST_P2_Ghostly: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] CT-6314 'Ghostly'";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Ghostly";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Ghostly.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Ghostly.Paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\clone_armor1_clean.rvmat",
			"\MRC\JLTS\characters\CloneArmor\data\clone_armor2_clean.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_Pilot_P1_Helmet_Ghostly",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_Pilot_P1_Helmet_Ghostly",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	}; */
	class FST_P2_Merrik: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] CT-4973 'Merrik'";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Merrik";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Merrik.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Merrik.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Merrik",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Merrik",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	}; 
	class FST_P2_Merrik_V3: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st] CT-4973 'Merrik (V3)'";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Merrik";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_MC_BodyUpper_Merrik3.paa",
			"41st_Armor\Data\Uniforms\FST_MC_BodyLower_Merrik3.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_MC_Helmet_Merrik_V3",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_MC_Helmet_Merrik_V3",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_P2_Woodland: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st] Woodland Clone Troopers";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Woodland";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Woodland.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Woodland.Paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Woodland",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Woodland",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_P2_Midnight: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st] Midnight Clone Troopers";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Midnight";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Midnight.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Midnight.Paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Upper.rvmat",
			"41st_Armor\Data\Other\Camos\Clone_Armor_P2_Lower.rvmat"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Midnight",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Midnight",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
 	class FST_P2_Recruit: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Clone Recruit Armor";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Recruit";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_Recruit.Paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Recruit.Paa",
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Recruit",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Recruit",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class ls_gar_jediCommander;
	class FST_Jedi: ls_gar_jediCommander
	{
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformClass="FST_Jedi_uniform";
		hiddenSelections[]=
		{
			"armor_camo",
			"robes_camo",
			"belt_camo",
			"under_camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\armor_co_J_Daara.paa",
			"41st_Armor\Data\Uniforms\robes_co_J_Daara.paa",
			"41st_Armor\Data\Uniforms\belt_co_J_Daara.paa",
			"\ls\core\addons\characters_clone\uniforms\JediCommander\data\undersuit_co.paa"
		};
	};
	class FST_DarkJedi: ls_gar_jediCommander
	{
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformClass="FST_Dark_Jedi_uniform";
		hiddenSelections[]=
		{
			"armor_camo",
			"robes_camo",
			"belt_camo",
			"under_camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\armor_co_DJ.paa",
			"41st_Armor\Data\Uniforms\robes_co_DJ.paa",
			"41st_Armor\Data\Uniforms\belt_co_DJ.paa",
			"\ls\core\addons\characters_clone\uniforms\JediCommander\data\undersuit_co.paa"
		};
	};
	class FST_Zombie_Bloody: FST_Trooper_P2_DC15S
	{
		author="Daara";
		displayName="[41st] Zombie Trooper";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_Customs_Subfaction";
		uniformclass="FST_Uniform_Bloddy_Zombie";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Uniforms\FST_P2_BodyUpper_SERE_Blood.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_SERE.paa"
		};
		weapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		respawnWeapons[]=
		{
			"JLTS_CloneBinocular",
			"Throw",
			"Put"
		};
		linkedItems[]=
		{
			"FST_P2_Helmet_Sere",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_P2_Helmet_Sere",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
};
class CfgGlasses
{
	class G_Combat;
	class FST_Base_Glasses: G_Combat
	{
		scope=1;
		author="nspin";
		displayName="===BASE CLASS===";
		model="\A3\Weapons_f\DummyNVG";
		mass=2;
		identityTypes[]={};
	};
	class FST_Fynock_LowLight: FST_Base_Glasses
	{
		scope=2;
		author="Ruby";
		displayName="[41st] Fynock's Low Light System";
		model="\A3\Weapons_f\DummyNVG";
		mass=2;
		FST_hasLowLight=1;
		identityTypes[]={};
	};
	class FST_HUD: FST_Base_Glasses
	{
		displayname="[41st] Helmet HUD";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			""
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Belt_Face: FST_Base_Glasses
	{
		displayname="[41st] Belt Bag (Face)";
		model="\MRC\JLTS\characters\CloneArmor\clonebeltbag.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_belt_bag_co.paa",
			""
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_FTL_Face: FST_Base_Glasses
	{
		displayname="[41st] Fire Team Leader Sash (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestRecon.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_FTL_Veteran_Face: FST_FTL_Face
	{
		displayname="[41st] Veteran Fire Team Leader Sash (Face)";
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co_Veteran.paa"
		};
	};
	class FST_Hoster_Face: FST_Base_Glasses
	{
		displayname="[41st] Holster (Face)";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Hoster_Woodland_Face: FST_Base_Glasses
	{
		displayname="[41st] Holster (Woodland/Face)";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Hoster_Midnight_Face: FST_Base_Glasses
	{
		displayname="[41st] Holster (Midnight/Face)";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Hoster_Urban_Face: FST_Base_Glasses
	{
		displayname="[41st] Holster (Urban/Face)";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Hoster_Desert_Face: FST_Base_Glasses
	{
		displayname="[41st] Holster (Desert/Face)";
		model="\MRC\JLTS\characters\CloneArmor2\CloneVestHolster.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_SL_Face: FST_Base_Glasses
	{
		displayname="[41st] Squad Leader Sash (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconNCO.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Heavy_Face: FST_Base_Glasses
	{
		displayname="[41st] Airborne Fire Team Leader Sash (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Heavy_Veteran_Face: FST_Heavy_Face
	{
		displayname="[41st] Veteran Airborne Fire Team Leader Sash (Face)";
		hiddenSelectionsTextures[]=
		{
			"",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co_Veteran.paa"
		};
	};
	class FST_AirborneSLSash: FST_Base_Glasses
	{
		displayname="[41st] Airborne Squad Leader Sash (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborneNCO.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};	
	class FST_VeteranAirborneSLSash: FST_AirborneSLSash
	{
		displayname="[41st] Veteran Airborne Squad Leader Sash (Face)";
		hiddenSelectionsTextures[] =
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
	};
	class FST_Vest_NCO_Kama_Face: FST_Base_Glasses
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Vest_NCO_Kama_Khaki_Face: FST_Base_Glasses
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Khaki/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Vest_NCO_Kama_Veteran_Face: FST_Base_Glasses
	{
		displayName="[41st] Squad Leader Sash w/ Kama (Veteran/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestReconOfficer.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran",
			"MRC\JLTS\characters\CloneArmor\data\Clone_vest_heavy_co.paa"
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Face)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_Woodland_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Face/Woodland)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Woodland.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_Desert_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Face/Desert)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Desert.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_Midnight_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Face/Midnight)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Midnight.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_Urban_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Face/Urban)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Urban.paa",
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_khaki_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Khaki/Face)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_veteran_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Officer's Pauldron w/ Kama (Veteran/Face)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran_Officer.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Commander_pauldron_kama_Face: FST_Base_Glasses
	{
		displayName="[41st] Commander's Pauldron w/ Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Commander_pauldron_kama_khaki_Face: FST_Base_Glasses
	{
		displayName="[41st] Commander's Pauldron w/ Kama (Khaki/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Commander_pauldron_kama_veteran_Face: FST_Base_Glasses
	{
		displayName="[41st] Commander's Pauldron w/ Kama (Veteran/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestCommander.p3d";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_reversed_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Reversed.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_reversed_khaki_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama (Khaki/Face)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_pauldron_kama_reversed_veteran_Face: FST_Base_Glasses
	{
		author="Viz";
		scope=2;
		displayName="[41st] Senior NCO Pauldron w/ Kama (Veteran/Face)";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestPauldron_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
		};
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_CloneVestKama_Face: FST_Base_Glasses
	{
		displayName="[41st] Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			""
		};
		hiddenSelectionsTextures[]=
		{
			"",
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FTS_CloneVestKama_Khaki_Face: FST_Base_Glasses
	{
		displayName="[41st] Kama (Khaki/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Khaki.paa",
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FTS_CloneVestKama_Veteran_Face: FST_Base_Glasses
	{
		displayName="[41st] Kama (Veteran/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestKama.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestKama_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Vest_Veteran.paa",
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_CloneVestMerrik_Face: FST_Base_Glasses
	{
		displayName="[41st] Merrik's Vest and Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborne.p3d";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestHeavy_ui_ca.paa";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_Clone_vest_Merrik.paa",
			"41st_Armor\Data\Vests\FST_Clone_vest_heavy_co.paa"
		};
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_CloneVestOfficer2_Face: FST_Base_Glasses
	{
		displayName="[41st] Reversed Pauldron w/ Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\clone_vest_officer_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Reversed_Face: FST_Base_Glasses
	{
		displayname="[41st] Senior NCO Pauldron + Kama (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestOfficer2.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Suspenders (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_vest_suspender_co.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Woodland_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Suspenders [Woodland] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Desert_Face: FST_Base_Glasses
	{
		author="Gold";
		displayname="[41st] Suspenders [Desert] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Midnight_Face: FST_Base_Glasses
	{
		author="Gold";
		displayname="[41st] Suspenders [Midnight] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Urban_Face: FST_Base_Glasses
	{
		author="Gold";
		displayname="[41st] Suspenders [Urban] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_Suspenders_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_ARF_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Ranger Suspenders (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Vest_Suspenders.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Ranger_Dirty_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Ranger Suspenders [Dirty] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Vest_Suspenders_Dirty.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_Ranger_Desert_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Ranger Suspenders [Desert] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Suspenders_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_ARF_Urban_Face: FST_Base_Glasses
	{
		author="Gold";
		displayname="[41st] Ranger Suspenders [Urban] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_ARF_Suspenders_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Suspenders_ARF_Black_Face: FST_Base_Glasses
	{
		author="Viz";
		displayname="[41st] Ranger Suspenders [Black] (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestSuspender.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Armor\Data\Equipment\FST_ARF_Suspenders_Black.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_suspender.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Single_Face: FST_Base_Glasses
	{
		displayname="[41st] Pauldron (Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa"
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Single_Face_Woodland: FST_Base_Glasses
	{
		displayname="[41st] Pauldron (Woodland/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Woodland.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Single_Face_Midnight: FST_Base_Glasses
	{
		displayname="[41st] Pauldron (Midnight/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_midnight.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Single_Face_Urban: FST_Base_Glasses
	{
		displayname="[41st] Pauldron (Urban/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Urban.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Pauldron_Single_Face_Desert: FST_Base_Glasses
	{
		displayname="[41st] Pauldron (Desert/Face)";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestLieutenant.p3d";
		hiddenSelections[]=
		{
			"camo1",
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest_Desert.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_vest_pauldron.rvmat";
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
	class FST_Argo_Face: FST_Base_Glasses
	{
		displayname="[41st] Argo's Vest";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestAirborneNCO.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Vests\FST_vest.paa",
			""
		};
		picture="\41st_Armor\Logo.paa";
		scope=2;
		ACE_Overlay="41st_Armor\Data\Equipment\FST_P2_HUD.paa";
		ACE_OverlayDirt="41st_Armor\Data\Equipment\FST_P2_HUD_Dirty.paa";
		ACE_OverlayCracked="41st_Armor\Data\Equipment\FST_P2_HUD_Cracked.paa";
		ACE_DustPath="\z\ace\addons\goggles\textures\fx\dust%1.paa";
		ACE_Resistance=1;
		ACE_Protection=1;
		ACE_TintAmount=0;
	};
};
class CfgHeads
{
	class Default_A3;
	class m_clone: Default_A3
	{
		model="ls\core\addons\identities\clones\ls_head_clone.p3d";
	};
	class m_clone_hair: Default_A3
	{
		model="ls\core\addons\identities\clones\ls_head_cloneHair.p3d";
	};
};
class CfgFaces
{
	class Default;
	class Man_A3: Default
	{
		class Default;
		class FST_clone_Default_head: Default
		{
			name="Clone Trooper";
			author="Adapted from Legion Studios by Viz";
			displayname="[41st] Clone Trooper";
			identityTypes[]=
			{
				"Head_LSD_CLONE"
			};
			head="m_clone_hair";
			material="ls\core\addons\identities\clones\data\cloneA.rvmat";
			texture="ls\core\addons\identities\clones\data\cloneA_co.paa";
			disabled=0;
			materialWounded1="\A3\Characters_F_EPA\Heads\Data\m_kerry_A_injury.rvmat";
			materialWounded2="\A3\Characters_F_EPA\Heads\Data\m_kerry_A_injury.rvmat";
			textureHL="\A3\Characters_F\Heads\Data\hl_White_hairy_1_co.paa";
			materialHL="\A3\Characters_F\Heads\Data\hl_White_hairy_muscular.rvmat";
			textureHL2="\A3\Characters_F\Heads\Data\hl_White_hairy_1_co.paa";
			materialHL2="\A3\Characters_F\Heads\Data\hl_White_hairy_muscular.rvmat";
		};
/*		class FST_Clone_Head_Burns: FST_clone_Default_head
		{
			author="Viz";
			name="Clone Trooper Burns";
			displayName="[41st] Clone Trooper - Burns";
			material="ls\core\addons\identities\clones\data\cloneB.rvmat";
			texture="41st_Armor\Data\Faces\FST_Clone_Burnz.paa";
		}; */
/*		class FST_Navy_Face_Mustang: Default
		{
			author="Gold adapted from TCGM"; //BE CAREFULL OF WHAT FACE YOU ARE DOING. THIS ISNT A CLONE FACE FROM LEGION STUDIO
			displayname="[41st] Navy Face - Mustang";
			texture="41st_Armor\Data\Faces\FST_Clone_Mustang.paa";
			material="TCGM_Girls\textures\TCGM_f_Eilish.rvmat";
			head="TCGM_FemHead_Eilish";
			identityTypes[]=
			{
				"Head_TCGM_Girls_WhitePony"
			};
			textureHL="\TCGM_Girls\textures\TCGM_hl_f_white_co.paa";
			materialHL="TCGM_Girls\textures\TCGM_hl_f_white.rvmat";
			textureHL2="\TCGM_Girls\textures\TCGM_hl_f_white_co.paa";
			materialHL2="TCGM_Girls\textures\TCGM_hl_f_white.rvmat";
			materialWounded1="TCGM_Girls\textures\TCGM_f_Eilish_injury.rvmat";
			materialWounded2="TCGM_Girls\textures\TCGM_f_Eilish_injury.rvmat";
			disabled=0;
		}; */
	};
};
class cfgGroups
{
	class WEST
	{
		name="BLUFOR";
		
		class FST_WOOK
		{
			name="41st Wookiees";
			
			class FST_Wookiee_Standard
			{
				name="Infantry";
				
				class FST_Wookiee_Squad
				{
					name="[41st] Wookiee Squad";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit7
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit8
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit9
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit10
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit11
					{
						side=1;
						vehicle="FST_Wookiee";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
				};
			};
		};
	};
};


