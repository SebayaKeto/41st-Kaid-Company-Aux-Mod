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
			"FST_OC_Commander_501"

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
			};
		};
	};
};