class CfgPatches
{
	class 41st_Other_Clones
	{
		requiredAddons[]={};
		units[]=
		{

			"FST_OC_Trooper_501",
			"FST_OC_Auto_501",
			"FST_OC_Mark_501",
			"FST_OC_AT_501",
			"FST_OC_CQB_501",
			"FST_OC_RTO_501",
			"FST_OC_Medic_501",
			"FST_OC_EOD_501",
			"FST_OC_Tanker_501",
			"FST_OC_SL_501",
			"FST_OC_FTL_501",
			"FST_OC_Commander_501",
			"FST_OC_Trooper_104",
			"FST_OC_Auto_104",
			"FST_OC_Mark_104",
			"FST_OC_AT_104",
			"FST_OC_CQB_104",
			"FST_OC_RTO_104",
			"FST_OC_Medic_104",
			"FST_OC_EOD_104",
			"FST_OC_Tanker_104",
			"FST_OC_SL_104",
			"FST_OC_FTL_104",
			"FST_OC_Commander_104",
			"FST_OC_Trooper_327",
			"FST_OC_Auto_327",
			"FST_OC_Mark_327",
			"FST_OC_AT_327",
			"FST_OC_CQB_327",
			"FST_OC_RTO_327",
			"FST_OC_Medic_327",
			"FST_OC_EOD_327",
			"FST_OC_Tanker_327",
			"FST_OC_SL_327",
			"FST_OC_FTL_327",
			"FST_OC_Commander_327"

		};
		weapons[]={};
	};
	author="Tooka";
};
class CfgEditorSubcategories
{
	class FST_OtherClones
	{
		displayName = "Other Clone Units"; 
	};
};
class CfgFunctions
{
	class FST_OCRandomizers
	{
		class FST_RandomOCScripts
		{
			file="41st_Other_Clones\Scripts";
			class clonecommander {};
			class clonesl {};
			class cloneftl {};
			class clonetrooper {};
			class cloneauto {};
			class clonemark {};
			class cloneat {};
			class clonecqb {};
			class clonerto {};
			class clonemedic {};
			class cloneeod {};
			class clonetank {};
		};
	};
};
class CfgWeapons
{
	class Uniform_Base;
	class UniformItem;
	class ItemCore;
	class ItemInfo;
	class HeadgearItem;
	class FST_P2_Helmet_Base;
	class JLTS_CloneArmor;
 	class FST_501_Uniform: JLTS_CloneArmor
	{
		author="Tooka";
		scope=1;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [501st]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_501";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	}; 
 	class FST_104_Uniform: JLTS_CloneArmor
	{
		author="Tooka";
		scope=1;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [104th]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_104";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	}; 
 	class FST_327_Uniform: JLTS_CloneArmor
	{
		author="Tooka";
		scope=1;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [327th]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_327";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	};
 	class FST_69_Uniform: JLTS_CloneArmor
	{
		author="Tooka";
		scope=1;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st] P2 Armor [69th]";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_P2_69";
			uniformType="Neopren";
			containerClass="Supply180";
			mass=15;
		};
	};
	class FST_P2_Helmet_501: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Helmet [501st]";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_501stTrooper_helmet_co.paa"
		};
	}; 
	class FST_P2_Helmet_104: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Helmet [104th]";
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_104thTrooper_helmet_co.paa"
		};
	};
	class FST_P2_Helmet_327: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Helmet [327th]";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_327thTrooper_helmet_co.paa"
		};
	}; 
	class FST_P2_Helmet_69: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Helmet [69th]";
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_P2_Helmet_69th.paa"
		};
	};
	class FST_P2_Helmet_501_RTO: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 RTO Helmet [501st]";
		hiddenSelections[] = 
		{
			"camo1",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_clone_legions\units\501st\data\helmets\trooper_phase2SpecOp_camo1_co.paa",
			"\ls\core\addons\characters_clone_legacy\helmets\phase2SpecOp\data\visor_co.paa"
		};
		hiddenSelectionsMaterials[] = {};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\ls\core\addons\characters_clone_legacy\helmets\phase2SpecOp\ls_sob_phase2SpecOp_helmet.p3d";
			mass=15;
			hiddenselections[]=
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
	class FST_P2_Helmet_104_RTO: FST_P2_Helmet_501_RTO
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 RTO Helmet [104th]";
		hiddenSelections[] = 
		{
			"camo1",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_clone_legions\units\41st\data\helmets\trooper_phase2SpecOp_camo1_co.paa",
			"\ls\core\addons\characters_clone_legacy\helmets\phase2SpecOp\data\visor_co.paa"
		};
	};
	class FST_P2_Helmet_327_RTO: FST_P2_Helmet_501_RTO
	{
		author="Tooka";
		scope=2;
		displayName="[41st] P2 RTO Helmet [327th]";
		hiddenSelections[] = 
		{
			"camo1",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_RTOHelmet_327_co.paa",
			"\ls\core\addons\characters_clone_legacy\helmets\phase2SpecOp\data\visor_co.paa"
		};
	};
	class FST_P2_Helmet_501_EOD: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 EOD Helmet [501st]";
		hiddenSelections[] = 
		{
			"Helmet",
			"Visor"
		};
		hiddenSelectionsMaterials[] = 
		{
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet.rvmat",
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet_Visor.rvmat"
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet_501st_CO.paa",
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet_501st_CO.paa"
		};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\3AS\3AS_Republic_Characters\Headgear\3AS_Clonetrooper_Engineer_Helmet.p3d";
			mass=15;
			hiddenselections[]=
			{
				"Helmet",
				"Visor"
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
	class FST_P2_Helmet_104_EOD: FST_P2_Helmet_501_EOD
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 EOD Helmet [104th]";
		hiddenSelections[] = 
		{
			"Helmet",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet_104th_CO.paa",
			"\3AS\3AS_Republic_Characters\Headgear\data\Clonetrooper_Engineer_Helmet\Clonetrooper_Engineer_Helmet_104th_CO.paa"
		};
	};
	class FST_P2_Helmet_327_EOD: FST_P2_Helmet_501_EOD
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 EOD Helmet [327th]";
		hiddenSelections[] = 
		{
			"Helmet",
			"Visor"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_Engineer_Helmet_327th_CO.paa",
			"41st_Other_Clones\Data\FST_Engineer_Helmet_327th_CO.paa"
		};
	};
	class FST_P2_Helmet_501_Tank: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Tanker Helmet [501st]";
		hiddenSelections[] = 
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\Tanker\501st_co.paa"
		};
		hiddenSelectionsMaterials[] = {};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\3AS\3AS_Characters\Clones\Headgear\3AS_P2_Clone_Helm_Tanker.p3d";
			mass=15;
			hiddenselections[]=
			{
				"camo"
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
	class FST_P2_Helmet_104_Tank: FST_P2_Helmet_501_Tank
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Tanker Helmet [104th]";
		hiddenSelections[] = 
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_104thTrooper_tankerhelmet_co.paa"
		};
	};
	class FST_P2_Helmet_327_Tank: FST_P2_Helmet_501_Tank
	{
		author="Tooka";
		scope=1;
		displayName="[41st] P2 Tanker Helmet [327th]";
		hiddenSelections[] = 
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_327thTrooper_tankerhelmet_co.paa"
		};
	};
	class FST_P2_Helmet_501_ARF: FST_P2_Helmet_Base
	{
		author="Tooka";
		scope=1;
		displayName="[41st] ARF Helmet [501st]";
		hiddenSelections[] = 
		{
			"camo1",
			"camo2",
			"visor"
		};
		hiddenSelectionsTextures[]=
		{
			"\ls\core\addons\characters_clone_legions\units\501st\data\helmets\trooper_arf_camo1_co.paa",
			"",
			"\ls\core\addons\characters_clone_legacy\helmets\arf\data\helmet_co.paa"
		};
		hiddenSelectionsMaterials[] = {};
		class Iteminfo: HeadgearItem
		{
			uniformModel="\ls\core\addons\characters_clone_legacy\helmets\arf\ls_gar_arf_helmet.p3d";
			mass=15;
			hiddenselections[]=
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
};
class CfgVehicles
{
	class JLTS_Clone_backpack;
	class JLTS_Clone_backpack_eod;
	class JLTS_Clone_backpack_medic;
	class JLTS_Clone_backpack_RTO;
	class FST_Clone_Backpack_Plain: JLTS_Clone_backpack
	{
		author="Tooka";
		scope=1;
		displayname="[41st] Clone Backpack (Plain)";
		maximumLoad=200;
		mass=50;
	};
	class FST_Clone_Backpack_Plain_EOD: JLTS_Clone_backpack_eod
	{
		author="Tooka";
		scope=1;
		displayname="[41st] Clone Backpack (Plain EOD)";
		maximumLoad=200;
		mass=50;
	};
	class FST_Clone_Backpack_Plain_Medic: JLTS_Clone_backpack_medic
	{
		author="Tooka";
		scope=1;
		displayname="[41st] Clone Backpack (Plain Medic)";
		maximumLoad=200;
		mass=50;
	};
	class FST_Clone_Backpack_Plain_RTO: JLTS_Clone_backpack_RTO
	{
		author="Tooka";
		scope=1;
		displayname="[41st] Clone Backpack (Plain RTO)";
		maximumLoad=200;
		mass=50;
	};
	class FST_Trooper_P2_DC15S;
 	class FST_P2_501: FST_Trooper_P2_DC15S
	{
		author="Tooka";
		displayName="[41st] Clone Armor (501st)";
		scope=1;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		uniformclass="FST_501_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_501stTrooper_armor1_co.paa",
			"\MRC\JLTS\characters\CloneLegions\data\Clone_501stTrooper_armor2_co.paa"
		};
		weapons[]={};
		respawnWeapons[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
	};
 	class FST_P2_104: FST_Trooper_P2_DC15S
	{
		author="Tooka";
		displayName="[41st] Clone Armor (104th)";
		scope=1;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		uniformclass="FST_104_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_104thTrooper_armor1_co.paa",
			"41st_Other_Clones\Data\FST_104thTrooper_armor2_co.paa"
		};
		weapons[]={};
		respawnWeapons[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
	};
 	class FST_P2_327: FST_Trooper_P2_DC15S
	{
		author="Tooka";
		displayName="[41st] Clone Armor (327th)";
		scope=1;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		uniformclass="FST_327_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_327thTrooper_armor1_co.paa",
			"\MRC\JLTS\characters\CloneLegions\data\Clone_327thTrooper_armor2_co.paa"
		};
		weapons[]={};
		respawnWeapons[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
	};
 	class FST_P2_69: FST_Trooper_P2_DC15S
	{
		author="Tooka";
		displayName="[41st] Clone Armor (69th)";
		scope=1;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		uniformclass="FST_69_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Other_Clones\Data\FST_P2_BodyUpper_69th.paa",
			"41st_Armor\Data\Uniforms\FST_P2_BodyLower_Tooka.Paa"
		};
		weapons[]={};
		respawnWeapons[]={};
		linkedItems[]={};
		respawnLinkedItems[]={};
	};
	class FST_bodyGlove;
	class FST_OC_Trooper_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonetrooper;";
		};
	};
	class FST_OC_Auto_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Autorifleman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_cloneauto;";
		};
	};
	class FST_OC_Mark_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Marksman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonemark;";
		};
	};
	class FST_OC_AT_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Antitank";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_cloneat;";
		};
	};
	class FST_OC_CQB_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Close Combat Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonecqb;";
		};
	};
	class FST_OC_RTO_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Radio Operator";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonerto;";
		};
	};
	class FST_OC_Medic_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Medic";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonemedic;";
		};
		attendant=1;
	};
	class FST_OC_EOD_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Combat Engineer";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_cloneeod;";
		};
		engineer=1;
		canDecativateMines=1;
	};
	class FST_OC_Tanker_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Tanker";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonetank;";
		};
		engineer=1;
	};
	class FST_OC_FTL_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Fire Team Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_cloneftl;";
		};
	};
	class FST_OC_SL_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Squad Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonesl;";
		};
	};
	class FST_OC_Commander_501: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 501st Clone Commander";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_501_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),501] spawn FST_OCRandomizers_fnc_clonecommander;";
		};
	};
	class FST_OC_Trooper_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonetrooper;";
		};
	};
	class FST_OC_Auto_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Autorifleman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_cloneauto;";
		};
	};
	class FST_OC_Mark_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Marksman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonemark;";
		};
	};
	class FST_OC_AT_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Antitank";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_cloneat;";
		};
	};
	class FST_OC_CQB_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Close Combat Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonecqb;";
		};
	};
	class FST_OC_RTO_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Radio Operator";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonerto;";
		};
	};
	class FST_OC_Medic_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Medic";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonemedic;";
		};
		attendant=1;
	};
	class FST_OC_EOD_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Combat Engineer";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_cloneeod;";
		};
		engineer=1;
		canDecativateMines=1;
	};
	class FST_OC_Tanker_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Tanker";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonetank;";
		};
		engineer=1;
	};
	class FST_OC_FTL_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Fire Team Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_cloneftl;";
		};
	};
	class FST_OC_SL_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Squad Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonesl;";
		};
	};
	class FST_OC_Commander_104: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 104th Clone Commander";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_104_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),104] spawn FST_OCRandomizers_fnc_clonecommander;";
		};
	};
	class FST_OC_Trooper_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonetrooper;";
		};
	};
	class FST_OC_Auto_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Autorifleman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_cloneauto;";
		};
	};
	class FST_OC_Mark_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Marksman";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonemark;";
		};
	};
	class FST_OC_AT_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Antitank";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_cloneat;";
		};
	};
	class FST_OC_CQB_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Close Combat Trooper";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonecqb;";
		};
	};
	class FST_OC_RTO_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Radio Operator";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonerto;";
		};
	};
	class FST_OC_Medic_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Medic";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonemedic;";
		};
		attendant=1;
	};
	class FST_OC_EOD_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Combat Engineer";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_cloneeod;";
		};
		engineer=1;
		canDecativateMines=1;
	};
	class FST_OC_Tanker_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Tanker";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonetank;";
		};
		engineer=1;
	};
	class FST_OC_FTL_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Fire Team Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_cloneftl;";
		};
	};
	class FST_OC_SL_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Squad Lead";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonesl;";
		};
	};
	class FST_OC_Commander_327: FST_bodyGlove
	{
		scope=2;
		scopeCurator=2;
        side=1;
		displayName="[41st] 327th Clone Commander";
		author="Tooka";
		uniformAccessories[]={};
		nakedUniform="FST_Uniform_Bodyglove";
		uniformClass="FST_327_Uniform";
		role="Rifleman";
		faction="FST_Faction";
		editorSubcategory="FST_OtherClones";
		weapons[]={};
		Items[]={};
		linkedItems[]={};
		magazines[]={};
		class EventHandlers
		{
			init= "[(_this select 0),327] spawn FST_OCRandomizers_fnc_clonecommander;";
		};
	};
};
class cfgGroups
{
	class WEST
	{
		name="BLUFOR";
		
		class FST_Faction
		{
			name="41st Elite Corps";
			
			class FST_OtherClones
			{
				name = "Other Clone Units";
				
				class FST_S_501_Squad
				{
					name="[41st] 501st Clone Squad";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_SL_501";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_RTO_501";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_FTL_501";
						rank="CORPORAL";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_FTL_501";
						rank="CORPORAL";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_Auto_501";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_Auto_501";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Mark_501";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=1;
						vehicle="FST_OC_CQB_501";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=1;
						vehicle="FST_OC_AT_501";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=1;
						vehicle="FST_OC_EOD_501";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=1;
						vehicle="FST_OC_Trooper_501";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=1;
						vehicle="FST_OC_Trooper_501";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=1;
						vehicle="FST_OC_Medic_501";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=1;
						vehicle="FST_OC_Medic_501";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
				class FST_S_501_Fireteam
				{
					name="[41st] 501st Clone Fireteam";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_FTL_501";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Trooper_501";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Auto_501";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_AT_501";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_CQB_501";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_EOD_501";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Medic_501";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_501_Tankers
				{
					name="[41st] 501st Vehicle Crew";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_Tanker_501";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Tanker_501";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Tanker_501";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_Tanker_501";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
				class FST_S_104_Squad
				{
					name="[41st] 104th Clone Squad";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_SL_104";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_RTO_104";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_FTL_104";
						rank="CORPORAL";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_FTL_104";
						rank="CORPORAL";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_Auto_104";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_Auto_104";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Mark_104";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=1;
						vehicle="FST_OC_CQB_104";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=1;
						vehicle="FST_OC_AT_104";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=1;
						vehicle="FST_OC_EOD_104";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=1;
						vehicle="FST_OC_Trooper_104";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=1;
						vehicle="FST_OC_Trooper_104";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=1;
						vehicle="FST_OC_Medic_104";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=1;
						vehicle="FST_OC_Medic_104";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
				class FST_S_104_Fireteam
				{
					name="[41st] 104th Clone Fireteam";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_FTL_104";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Trooper_104";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Auto_104";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_AT_104";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_CQB_104";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_EOD_104";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Medic_104";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_104_Tankers
				{
					name="[41st] 104th Vehicle Crew";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_Tanker_104";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Tanker_104";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Tanker_104";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_Tanker_104";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
				class FST_S_327_Squad
				{
					name="[41st] 327th Clone Squad";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_SL_327";
						rank="SERGEANT";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_RTO_327";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_FTL_327";
						rank="CORPORAL";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_FTL_327";
						rank="CORPORAL";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_Auto_327";
						rank="PRIVATE";
						position[]={1,-4,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_Auto_327";
						rank="PRIVATE";
						position[]={1,-5,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Mark_327";
						rank="PRIVATE";
						position[]={1,-6,0};
					};
					class Unit7
					{
						side=1;
						vehicle="FST_OC_CQB_327";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit8
					{
						side=1;
						vehicle="FST_OC_AT_327";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit9
					{
						side=1;
						vehicle="FST_OC_EOD_327";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
					class Unit10
					{
						side=1;
						vehicle="FST_OC_Trooper_327";
						rank="PRIVATE";
						position[]={0,-3,0};
					};
					class Unit11
					{
						side=1;
						vehicle="FST_OC_Trooper_327";
						rank="PRIVATE";
						position[]={0,-4,0};
					};
					class Unit12
					{
						side=1;
						vehicle="FST_OC_Medic_327";
						rank="PRIVATE";
						position[]={0,-5,0};
					};
					class Unit13
					{
						side=1;
						vehicle="FST_OC_Medic_327";
						rank="PRIVATE";
						position[]={0,-6,0};
					};
				};
				class FST_S_327_Fireteam
				{
					name="[41st] 327th Clone Fireteam";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_FTL_327";
						rank="CORPORAL";
						position[]={1,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Trooper_327";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Auto_327";
						rank="PRIVATE";
						position[]={1,-2,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_AT_327";
						rank="PRIVATE";
						position[]={1,-3,0};
					};
					class Unit4
					{
						side=1;
						vehicle="FST_OC_CQB_327";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit5
					{
						side=1;
						vehicle="FST_OC_EOD_327";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit6
					{
						side=1;
						vehicle="FST_OC_Medic_327";
						rank="PRIVATE";
						position[]={0,-2,0};
					};
				};
				class FST_S_327_Tankers
				{
					name="[41st] 327th Vehicle Crew";
					faction="FST_Faction";
					side=1;
					class Unit0
					{
						side=1;
						vehicle="FST_OC_Tanker_327";
						rank="PRIVATE";
						position[]={0,-0,0};
					};
					class Unit1
					{
						side=1;
						vehicle="FST_OC_Tanker_327";
						rank="PRIVATE";
						position[]={0,-1,0};
					};
					class Unit2
					{
						side=1;
						vehicle="FST_OC_Tanker_327";
						rank="PRIVATE";
						position[]={1,-0,0};
					};
					class Unit3
					{
						side=1;
						vehicle="FST_OC_Tanker_327";
						rank="PRIVATE";
						position[]={1,-1,0};
					};
				};
			};
		};
	};
};