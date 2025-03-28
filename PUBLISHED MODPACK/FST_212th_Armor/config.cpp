class CfgPatches
{
	class 41st_212th_Custom_Helms
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
			"JLTS_characters_CloneArmor",
			"3AS_Characters_Commando",
			"3AS_Characters_Clones_Headgear"
		};
		units[]=
		{
			"FST_212th_P2_AB",
			"41st_212th_Republic_Commando",
			"FST_212th_laati_Turret",
			"FST_212th_laati_mk2",
			"FST_212th_laati_mk1Lights",
			"FST_212th_laati_mk2Lights",
		};
		weapons[]={};
	}; 
};
class CfgFactionClasses 
{ 
	class FST_212th_Faction
	{ 
		displayName="41st/212th Elite Corps";
		priority=1;
		side=1;
		icon="";  	
	};
};
class CfgEditorSubcategories
{
	class FST_212th_Subfaction
	{
		displayName="41st/212th Clone Troopers";
	};
	class FST_212th_Air_Vehicle
	{
		displayName="41st/212th Air Vehicles";
	};
};
class CfgWeapons
{
	class UniformItem;
	class ItemCore;
	class HeadgearItem;
	class H_HelmetSpecB;
	class JLTS_CloneHelmetP2;
	class JLTS_CloneHelmetBARC;
	class JLTS_CloneHelmetAB;
	class ls_gar_phase1Pilot_helmet;
	class V_PlateCarrier1_rgr;
	class VestItem;
	class FST_P2_ARC_Helmet_212: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st/212th] P2 ARC Trooper Helmet";
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
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARC\P2_ARC_CO.paa"
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
	class FST_P2_ARC_Helmet_212_Duster: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st/212th] P2 ARC Trooper Helmet (Duster)";
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
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARC\ARCHelmet_Duster_CO.paa"
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
	class FST_P2_ARC_Helmet_212_Jungle: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st/212th] P2 ARC Trooper Helmet (Jungle)";
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
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARC\P2_ARC_Camo_Jungle_CO.paa"
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
	class FST_P2_ARC_Helmet_212_Woodland: JLTS_CloneHelmetP2
	{
		author="Daara";
		displayName="[41st/212th] P2 ARC Trooper Helmet (Woodland)";
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
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARC\P2_ARC_Camo_Woodland_CO.paa"
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
	class FST_CloneVestARC212: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st/212th] ARC Trooper Vest Standard";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestARC_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Vest\ARC_Standard_CO.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
			containerClass="Supply120";
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
	class FST_CloneVestARC212_Veteran: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st/212th] ARC Trooper Vest Veteran";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestARC_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Vest\ARC_Vet_CO.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
			containerClass="Supply120";
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
	class FST_CloneVestARC212_Lead: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st/212th] ARC Trooper Vest Lead";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestARC_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Vest\ARC_Lead_CO.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
			containerClass="Supply120";
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
	class FST_CloneVestARC212_Medic: V_PlateCarrier1_rgr
	{
		author="Daara";
		scope=2;
		displayName="[41st/212th] ARC Trooper Vest Medic";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneVestARC_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Vest\ARC_Medic_CO.paa"
		};
		class ItemInfo: VestItem
		{
			uniformModel="\MRC\JLTS\characters\CloneArmor\CloneVestARC.p3d";
			containerClass="Supply120";
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
	class FST_212th_P2_Helmet: JLTS_CloneHelmetP2
	{
		author="Gold";
		displayName="[41st/212th] P2 Trooper Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		model="\MRC\JLTS\characters\CloneArmor\CloneHelmetP2.p3d";
		hiddenSelectionsMaterials[]=
		{
			"\41st_Armor\Data\Other\Clone_Helmet_P2.rvmat";
		};
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\P2 Helmet (base helmets)\P2_Standard_CO.paa"
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
	class FST_212th_P2_Helmet_Ace: FST_212th_P2_Helmet
	{
		author="Gold";
		displayName="[41st/212th] P2 Helmet [Ace]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ace_CO.paa"
		};
	};	
	class FST_212th_P2_Helmet_Aden: FST_212th_P2_Helmet
	{
		author="Gold";
		displayName="[41st/212th] P2 Helmet [Aden]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Aden_CO.paa"
		};
	};	
	class FST_212th_P2_Helmet_Aegir: FST_212th_P2_Helmet
	{
		author="Gold";
		displayName="[41st/212th] P2 Helmet [Aegir]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Aegir_CO.paa"
		};
	};
	class FST_212th_P2_Helmet_Ajax: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Ajax]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ajax_CO.paa"
		};
	};	
	class FST_212th_P2_Helmet_Alaska: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Alaska]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Alaska_CO.paa"
		};
	};
	class FST_212th_P2_Helmet_Alt: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Alt]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Alt_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Apache: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Apache]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Apache_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Argyle: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Argyle]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Argyle_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Atom: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Atom]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Atom_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Azul: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Azul]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Azul_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Baboon: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Baboon]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Baboon_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Badger: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Badger]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Badger_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Baller: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Baller]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Baller_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Banter: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Banter]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Banter_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Baru: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Baru]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Baru_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Batch: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Batch]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Batch_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Bean: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Bean]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Bean_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Bear: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Bear]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Bear_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Beegs: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Beegs]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Beegs_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Benny: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Benny]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Benny_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Berry: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Berry]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Berry_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Blackout: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Blackout]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Blackout_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Blood: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Blood]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Blood_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Blue: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Blue]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Blue_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_BMyint: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [BMyint]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_BMyint_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Bones: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Bones]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Bones_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Border: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Border]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Border_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Brown: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Brown]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Brown_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Brutus: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Brutus]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Brutus_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Bulleck: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
	displayName="[41st/212th] P2 Helmet [Bulleck]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Bulleck_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Cable: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Cable]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Cable_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Calore: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Calore]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Calore_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Carp: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Carp]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Carp_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Carrots: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Carrots]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Carrots_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Cat: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Cat]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Cat_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Charlie: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
	displayName="[41st/212th] P2 Helmet [Charlie]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Charlie_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Chelts: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Chelts]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Chelts_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Chicken: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Chicken]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Chicken_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Chromz: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Chromz]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Chromz_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Chronos: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Chronos]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Chronos_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Cliff: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Cliff]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Cliff_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Climber: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Climber]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Climber_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Clocks: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Clocks]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Clocks_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Clover: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Clover]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Clover_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Coffee: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Coffee]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Coffee_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Colossus: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Colossus]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Colossus_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Cordy: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Cordy]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Cordy_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Crazy: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Crazy]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Crazy_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dark: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dark]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dark_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dead: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dead]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dead_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Digital: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Digital]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Digital_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dirty: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dirty]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dirty_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Divine: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Divine]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Divine_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dodo: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dodo]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dodo_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dongle: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dongle]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dongle_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Donovan: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Donovan]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Donovan_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dreki: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dreki]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dreki_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Drunk: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Drunk]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Drunk_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dumber: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dumber]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dumber_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dunhaw: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dunhaw]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dunhaw_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Duster: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Duster]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Duster_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Dynna: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Dynna]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Dynna_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Elbows: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Elbows]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Elbows_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Electric: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Electric]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Electric_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Elliot: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Elliot]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Elliot_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Ensign: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Ensign]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ensign_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Epitaph: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Epitaph]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Epitaph_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Fang: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Fang]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Fang_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Faolan: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Faolan]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Faolan_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Fetch: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Fetch]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Fetch_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Firehazard: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Firehazard]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Firehazard_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Fisher: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Fisher]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Fisher_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Florence: FST_212th_P2_Helmet
	{
		author="Gold, Claw";
		displayName="[41st/212th] P2 Helmet [Florence]";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Florence_CO.paa"
		};
	};		
	class FST_212th_P2_Helmet_Flux: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Flux]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Flux_CO.paa"
        };
    };
	class FST_212th_P2_Helmet_Fly: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Fly]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Fly_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Forge: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Forge]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Forge_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Freelance: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Freelance]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Freelance_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Frodo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Frodo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Frodo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Frostbite: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Frostbite]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Frostbite_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Frumpus: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Frumpus]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Frumpus_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Gatoraid: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Gatoraid]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Gatoraid_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Gaz: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Gaz]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Gaz_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Ghoul: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Ghoul]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ghoul_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Glass: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Glass]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Glass_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Goldfinger: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Goldfinger]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Goldfinger_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Goldfish: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Goldfish]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Goldfish_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Gramps: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Gramps]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Gramps_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Graves: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Graves]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Graves_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Gremlin: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Gremlin]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Gremlin_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Griffin: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Griffin]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Griffin_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Haddock: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Haddock]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Haddock_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Havoc: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Havoc]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Havoc_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hawk: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hawk]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hawk_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hazza: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hazza]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hazza_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hecate: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hecate]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hecate_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hoosier: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hoosier]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hoosier_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hotpocket: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hotpocket]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hotpocket_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Houdini: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Houdini]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Houdini_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Hugs: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Hugs]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Hugs_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Human: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Human]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Human_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Husk: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Husk]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Husk_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Impossible: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Impossible]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Impossible_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Inferno: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Inferno]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Inferno_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jaeger: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jaeger]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jaeger_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jek: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jek]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jek_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jem: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jem]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jem_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jenny: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jenny]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jenny_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jesus: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jesus]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jesus_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jinx: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jinx]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jinx_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Joker: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Joker]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Joker_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Joz: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Joz]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Joz_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Junior: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Junior]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Junior_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Jupiter: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Jupiter]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Jupiter_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Kalma: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Kalma]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Kalma_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Kano: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Kano]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Kano_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Karuma: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Karuma]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Karuma_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Kessel: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Kessel]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Kessel_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Khai: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Khai]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Khai_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_King: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [King]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_King_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Kira: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Kira]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Kira_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Klutz: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Klutz]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Klutz_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Kobey: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Kobey]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Kobey_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Korg: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Korg]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Korg_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lark: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lark]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lark_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Law: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Law]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Law_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Legacy: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Legacy]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Legacy_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Leo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Leo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Leo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lindow: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lindow]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lindow_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lionheart: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lionheart]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lionheart_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Loki: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Loki]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Loki_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lucky: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lucky]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lucky_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lunair: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lunair]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lunair_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Lurburk: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Lurburk]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Lurburk_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mackiy: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mackiy]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mackiy_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mage: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mage]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mage_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Maldova: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Maldova]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Maldova_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mango: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mango]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mango_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_McCoy: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [McCoy]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_McCoy_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_McKnight: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [McKnight]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_McKnight_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mereel: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mereel]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mereel_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Meta: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Meta]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Meta_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Method: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Method]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Method_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mimo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mimo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mimo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mincer: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mincer]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mincer_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Minister: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Minister]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Minister_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Mogu: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Mogu]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Mogu_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Monty: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Monty]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Monty_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Moo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Moo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Moo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Moose: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Moose]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Moose_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Morrigan: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Morrigan]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Morrigan_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Nebel: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Nebel]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Nebel_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Nickex: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Nickex]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Nickex_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Nightmare: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Nightmare]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Nightmare_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Nor: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Nor]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Nor_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Nova: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Nova]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Nova_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Novon: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Novon]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Novon_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Omni: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Omni]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Omni_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Optic: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Optic]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Optic_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Ordo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Ordo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ordo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Ox: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Ox]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ox_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Oz: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Oz]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Oz_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Pac: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Pac]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Pac_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Paddy: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Paddy]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Paddy_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Parry: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Parry]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Parry_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Pat: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Pat]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Pat_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Pepper: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Pepper]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Pepper_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Planet: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Planet]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Planet_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Porg: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Porg]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Porg_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Porter: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Porter]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Porter_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Poseidon: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Poseidon]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Poseidon_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Primus: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Primus]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Primus_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Prongs: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Prongs]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Prongs_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Prowl: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Prowl]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Prowl_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Psyduck: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Psyduck]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Psyduck_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Pupa: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Pupa]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Pupa_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Pyro: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Pyro]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Pyro_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Raiding: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Raiding]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Raiding_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Ranch: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Ranch]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ranch_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Raptor: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Raptor]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Raptor_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rav: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rav]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rav_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Raven: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Raven]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Raven_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Raze: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Raze]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Raze_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Recos: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Recos]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Recos_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Redfox: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Redfox]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Redfox_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Remus: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Remus]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Remus_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Retry: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Retry]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Retry_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rev: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rev]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rev_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rez: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rez]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rez_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rias: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rias]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rias_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Ricebowl: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Ricebowl]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Ricebowl_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Robin: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Robin]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Robin_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rolland: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rolland]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rolland_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rook: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rook]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rook_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rookie: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rookie]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rookie_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Rucker: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Rucker]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Rucker_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sabre: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sabre]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sabre_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sadyn: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sadyn]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sadyn_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Saint: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Saint]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Saint_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Salvo: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Salvo]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Salvo_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sanco: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sanco]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sanco_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sandman: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
	displayName="[41st/212th] P2 Helmet [Sandman]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sandman_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Scarletta: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Scarletta]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Scarletta_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Scorpio: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Scorpio]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Scorpio_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Scrut: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Scrut]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Scrut_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sense: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sense]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sense_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Shepard: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Shepard]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Shepard_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Shift: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Shift]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Shift_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Shooter: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Shooter]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Shooter_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sierra: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sierra]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sierra_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_SirAndrew: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [SirAndrew]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_SirAndrew_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_SirHenrik: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [SirHenrik]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_SirHenrik_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Skan: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Skan]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Skan_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Skeggold: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Skeggold]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Skeggold_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Slaylen: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Slaylen]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Slaylen_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sloth: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sloth]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sloth_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Smolder: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Smolder]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Smolder_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Smurf: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Smurf]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Smurf_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Soonteer: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Soonteer]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Soonteer_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_South: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [South]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_South_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Spacer: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Spacer]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Spacer_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Spade: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Spade]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Spade_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sparky: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sparky]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sparky_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Spartan: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Spartan]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Spartan_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Sponge: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Sponge]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Sponge_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Stitch: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Stitch]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Stitch_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Stripes: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Stripes]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Stripes_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Swasher: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Swasher]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Swasher_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Talisker: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Talisker]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Talisker_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Thermite: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Thermite]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Thermite_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Timer: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Timer]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Timer_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_TopDog: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [TopDog]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_TopDog_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Topsides: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Topsides]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Topsides_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Trash: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Trash]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Trash_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Tricky: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Tricky]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Tricky_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Tugs: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Tugs]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Tugs_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Tux: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Tux]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Tux_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Umbra: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Umbra]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Umbra_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Unbe: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Unbe]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Unbe_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Unlucky: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Unlucky]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Unlucky_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Vex: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Vex]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Vex_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Vortex: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Vortex]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Vortex_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Voxel: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Voxel]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Voxel_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Walrus: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Walrus]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Walrus_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Wardog: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Wardog]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Wardog_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Wasp: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Wasp]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Wasp_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Waxer: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Waxer]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Waxer_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Widow: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Widow]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Widow_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Winters: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Winters]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Winters_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Wrangler: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Wrangler]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Wrangler_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Wrench: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Wrench]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Wrench_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Yuu: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Yuu]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Yuu_CO.paa"
        };
    };	
	class FST_212th_P2_Helmet_Zealous: FST_212th_P2_Helmet
    {
        author="Gold, Claw";
        displayName="[41st/212th] P2 Helmet [Zealous]";
        hiddenSelectionsTextures[]=
        {
            "FST_212th_Armor\Data\Helmets\Clone_Helmet_P2\p2Helmet_Zealous_CO.paa"
        };
    };	
	class FST_212th_ARF_Helmet: H_HelmetSpecB
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet";
		picture="FST_212th_Armor\Data\Helmets\IconARF.paa";
		model="FST_212th_Armor\Data\Helmets\ARF_Helmet.p3d";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
		ace_hearing_lowerVolume=0;
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF Helmet (base helmets)\ARF_Helmet_CO.paa"
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
			uniformModel="FST_212th_Armor\Data\Helmets\ARF_Helmet.p3d";
			mass=15;
			hiddenSelections[]=
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
	class FST_212th_ARF_Helm_Alt: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Alt)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Alt_CO.paa"
		};
	};
	class FST_212th_ARF_Helm_Baru: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Baru)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Baru_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Beetle: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Beetle)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Beetle_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Bolt: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Bolt)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Bolt_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Buck: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Buck)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Buck_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Enfield: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Enfield)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Enfield_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Havoc: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Havoc)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Havoc_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Mincer: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Mincer)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Mincer_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Mudkip: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Mudkip)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Mudkip_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Omni: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Omni)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Omni_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Pandalorian: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Pandalorian)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Pandalorian_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Rang: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Rang)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Rang_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Robert: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Robert)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Robert_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Sloth: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Sloth)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Sloth_CO.paa"
		};
	};	
	class FST_212th_ARF_Helm_Wayfinder: FST_212th_ARF_Helmet
	{
		author="Gold";
		displayName="[41st/212th] ARF Helmet (Wayfinder)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_ARF\ARF_Helm_Wayfinder_CO.paa"
		};
	};
	class FST_212th_Crewman_Helmet: JLTS_CloneHelmetBARC
	{
		author="Gold";
		displayName="[41st/212th] Crewman Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
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
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\ATRT Helmet (base helmets)\ATRT_Helmet_CO.paa"
		};
		subItems[]=
		{
			"Integrated_NVG_TI_1_F"
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
	class FST_212th_Crewman_Helmet_Apollo: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Apollo)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Apollo_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Count: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Count)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Count_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Dunhaw: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Dunhaw)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Dunhaw_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Primus: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Primus)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Primus_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Prowl: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Prowl)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Prowl_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Pyro: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Pyro)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Pyro_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Scorpio: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Scorpio)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Scorpio_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Shooter: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Shooter)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Shooter_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Soonteer: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Soonteer)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Soonteer_CO.paa"
		};
	};	
	class FST_212th_Crewman_Helmet_Voxel: FST_212th_Crewman_Helmet
	{
		displayName="[41st/212th] Crewman Helmet (Voxel)";
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Crewman\p2Crewman_Voxel_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet: JLTS_CloneHelmetAB
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneHelmetAB_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneHelmetAB.p3d";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\AB Helmet (base helmets)\AB_Standard_CO.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Armor\Data\Other\Clone_Helmet_AB.rvmat";
		};
		subItems[]=
		{
			"k_nvg"
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
	class FST_212th_Airborne_Helmet_Adil: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Adil)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Adil_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Aedalus: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Aedalus)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Aedalus_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Atom: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Atom)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Atom_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Bicycle: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Bicycle)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Bicycle_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Biscut: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Biscut)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Biscuit_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Blue: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Blue)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Blue_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Bobandie: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Bobandie)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Bobandie_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Bolt: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Bolt)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Bolt_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Buck: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Buck)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Buck_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Chaos: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Chaos)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Chaos_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_charger: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (charger)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_charger_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Charlie: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Charlie)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Charlie_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Drac: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Drac)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Drac_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Drifter: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Drifter)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Drifter_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Dubya: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Dubya)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Dubya_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Duffy: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Duffy)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Duffy_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Error: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Error)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Error_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Fenrir: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Fenrir)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Fenrir_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Firehawk: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Firehawk)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Firehawk_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Flak: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Flak)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Flak_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Flames: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Flames)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Flames_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Foxxo: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Foxxo)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Foxxo_CO.paa"
		};
	};
	class FST_212th_Airborne_Helmet_Gatoraid: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Gatoraid)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Gatoraid_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Gramps: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Gramps)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Gramps_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_GuyFox: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (GuyFox)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_GuyFox_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Helheim: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Helheim)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Helheim_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Hitman: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Hitman)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Hitman_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Hugs: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Hugs)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Hugs_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Humbucker: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Humbucker)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Humbucker_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Jumper: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Jumper)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Jumper_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Khova: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Khova)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Khova_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Levi: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Levi)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Levi_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Lindow: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Lindow)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Lindow_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Lodurr: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Lodurr)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Lodurr_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Maverick: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Maverick)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Maverick_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Morrigan: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Morrigan)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Morrigan_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Nagero: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Nagero)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Nagero_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Nova: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Nova)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Nova_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Null: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Null)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Null_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Nyx: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Nyx)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Nyx_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Odin: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Odin)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Odin_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Pac: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Pac)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Pac_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Queue: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Queue)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Queue_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Rat: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Rat)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Rat_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Regular: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Regular)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Regular_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Rei: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Rei)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Rei_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Ross: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Ross)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Ross_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Savager: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Savager)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Savager_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Scav: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Scav)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Scav_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Scooter: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Scooter)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Scooter_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Scrut: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Scrut)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Scrut_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sharps: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sharps)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sharps_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Shepard: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Shepard)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Shepard_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Shift: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Shift)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Shift_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sleepy: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sleepy)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sleepy_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Smudgers: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Smudgers)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Smudgers_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Smurf: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Smurf)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Smurf_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sota: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sota)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sota_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sour: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sour)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sour_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sparky: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sparky)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sparky_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Spartan: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Spartan)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Spartan_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Sylvester: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Sylvester)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Sylvester_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Tex: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Tex)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Tex_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Tooby: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Tooby)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Tooby_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Toxik: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Toxik)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Toxik_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Trash: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Trash)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Trash_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Treize: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Treize)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Treize_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Truckie: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Truckie)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Truckie_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Valentine: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Valentine)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Valentine_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Vanquish: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Vanquish)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Vanquish_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_White: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (White)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_White_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Wong: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Wong)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Wong_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Wragle: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Wragle)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Wragle_CO.paa"
		};
	};	
	class FST_212th_Airborne_Helmet_Zarghan: FST_212th_Airborne_Helmet
	{
		author="Gold";
		displayName="[41st/212th] Airborne Helmet (Zarghan)";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_AB\p2Airborne_Zarghan_CO.paa"
		};
	};
	class H_HelmetO_ViperSP_hex_F;
	class FST_212th_Pilot_P2_Helmet: H_HelmetO_ViperSP_hex_F
	{
		author="Gold";
		displayName="[41st/212th] P2 Pilot Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		model="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Pilot_P2.p3d";
		picture="FST_212th_Armor\Data\Helmets\IconPilot.paa";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelections[]=
		{
				"Camo",
				"Camo1",
				"Camo2",
				"Camo3",
				"Camo4",
				"Camo5"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Characters\Clones\Headgear\Textures\PilotP2\Phase2_Pilot_212th_CO.paa",
			"3AS\3AS_Characters\Clones\Headgear\Textures\PilotP2\Phase2_Pilot_212th_CO.paa",
			"",
			"3AS\3AS_Characters\Clones\Headgear\Textures\PilotP2\Phase_2_Pilot_Tubes_co.paa",
			"3AS\3AS_Characters\Clones\Headgear\Textures\PilotP2\Phase2_Pilot_212th_CO.paa",
			""
		};
		subItems[]=
		{
			"Integrated_NVG_TI_0_F"
		};
		class ItemInfo: HeadgearItem
		{
			mass=10;
			uniformModel="\3AS\3AS_Characters\Clones\Headgear\3AS_Clone_Pilot_P2.p3d";
			allowedSlots[]={801,901,701,605};
			modelSides[]={6};
			hiddenSelections[]=
			{
				"Camo",
				"Camo1",
				"Camo2",
				"Camo3",
				"Camo4",
				"Camo5"
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
	class FST_212th_Pilot_P1_Helmet_Ace: FST_212th_Pilot_P2_Helmet
	{
		author="Gold";
		displayName="[41st/212th] P2 Pilot Helmet (Ace)";
		hiddenSelections[]=
		{
			"Camo",
			"Camo1",
			"Camo2",
			"Camo3",
			"Camo4",
			"Camo5"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_PILOT\PilotHelmet_Ace_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_PILOT\PilotHelmet_Ace_CO.paa",
			"",
			"3AS\3AS_Characters\Clones\Headgear\Textures\PilotP2\Phase_2_Pilot_Tubes_co.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_PILOT\PilotHelmet_Ace_CO.paa",
			""
		};
	};
	class 3AS_Katarn_Helmet_Base: ItemCore
	{
		class ItemInfo;
	};
	class 41st_212th_3AS_Katarn_Helmet_Base: 3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Republic Katarn Helmet";
		picture="\A3\characters_f\Data\UI\icon_H_helmet_plain_ca.paa";
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		class ItemInfo: ItemInfo
		{
			mass=80;
			class HitpointsProtectionInfo
			{
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
	class 41st_212th_H_Katarn_Helmet: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Camo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Camo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Camo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Camo_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Demo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Demo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Demo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Demo_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Demo_Camo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Demo/Camo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Demo_Camo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Demo_Camo_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Medic: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Medic)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Medic_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Medic_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Medic_Camo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Medic/Camo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Medic_Camo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Medic_Camo_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Marksman: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Marksman)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Marksman_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Marksman_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Marksman_Camo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Marksman/Camo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Marksman_Camo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Marksman_Camo_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Lead: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Lead)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Lead_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Lead_CO.paa"
		};
	};
	class 41st_212th_H_Katarn_Helmet_Lead_Camo: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Lead/Camo)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		ace_hearing_protection=1;
        ace_hearing_lowerVolume=0;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Lead_Camo_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\Helmet_Commando (Base Helmet)\Katarn_Helmet_Foxtrot_Lead_Camo_CO.paa"
		};
	};
	class 212th_Foxtrot_Helmet_Beetle: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Beetle)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Beetle_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Beetle_CO.paa",
		};
	};
	class 212th_Foxtrot_Helmet_Charlie: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Charlie)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Charlie_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Charlie_CO.paa",
		};
	};
	class 212th_Foxtrot_Helmet_Griffin: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Griffin)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Griffin_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Griffin_CO.paa",
		};
	};
	class 212th_Foxtrot_Helmet_Mage: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Mage)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Mage_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Mage_CO.paa",
		};
	};
	class 212th_Foxtrot_Helmet_Sean: 41st_212th_3AS_Katarn_Helmet_Base
	{
		author="Gold";
		displayName="[41st/212th] Katarn Foxtrot Commando Helmet (Sean)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Sean_CO.paa",
			"FST_212th_Armor\Data\Helmets\Clone_Helmet_Foxtrot\p2Foxtrot_Sean_CO.paa",
		};
	};
	///////////////////
	//////UNIFORM//////
	///////////////////
	class JLTS_CloneArmor;
	class FST_212th_P2_Uniform: JLTS_CloneArmor
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st/212th] P2 Armor";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_212th_P2_DC15S";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	class FST_212th_AB_Uniform: JLTS_CloneArmor
	{
		author="Gold";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\CloneArmor_ui_ca.paa";
		displayName="[41st/212th] P2 Armor Airborne";
		class ItemInfo: UniformItem
		{
			uniformModel="";
			uniformClass="FST_212th_P2_AB_DC15S";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=15;
		};
	}; 
	class Uniform_Base;
	class FST_U_Rep_Katarn_Armor: Uniform_Base
	{
		author="$STR_3as_Studio";
		scope=2;
		displayName="[41st] Republic Katarn Armor";
		tas_is_commando=1;
		picture="3AS\3AS_Characters\Commando\data\UI\Katarn_Uniform_Unmarked_UI_ca.paa";
		model="\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"\A3\Characters_F\Common\Suitpacks\data\suitpack_soldier_blufor_co.paa"
		};
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="3AS_Rep_Commando_F";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_3AS_U_Rep_Katarn_Armor: FST_U_Rep_Katarn_Armor
	{
		author="Gold";
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Lead)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Lead_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_3AS_U_Rep_Katarn_Armor_Camo: FST_U_Rep_Katarn_Armor
	{
		author="Gold";
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Lead/Camo)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Lead_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Camo";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Medic: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Medic)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Medic_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Medic";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Medic_Camo: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Medic/Camo)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Medic_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Medic_Camo";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Demo: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Demo)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Demo_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Demo";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Demo_Camo: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Demo/Camo)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Demo_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Demo_Camo";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Marksman: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Marksman)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Marksman_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Marksman";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
	class 41st_212th_U_Rep_Katarn_Armor_Foxtrot_Marksman_Camo: 41st_212th_3AS_U_Rep_Katarn_Armor
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Armor (Foxtrot Marksman/Camo)";
		Picture="FST_212th_Armor\Data\Uniform\UI\Katarn_Uniform_Foxtrot_Marksman_UI_ca.paa"
		class ItemInfo: ItemInfo
		{
			uniformClass="41st_212th_Republic_Commando_Foxtrot_Marksman_Camo";
			uniformType="Neopren";
			containerClass="Supply150";
			mass=40;
		};
	};
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
			class ACE_HDBracket
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
			};
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
			class ACE_HDBracket: ACE_HDBracket{};
			class HitFace: HitFace{};
			class HitNeck: HitNeck{};
			class HitHead: HitHead{};
			class HitPelvis: HitPelvis{};
			class HitAbdomen: HitAbdomen{};
			class HitDiaphragm: HitDiaphragm{};
			class HitChest: HitChest{};
			class HitBody: HitBody{};
			class HitArms: HitArms{};
			class HitHands: HitHands{};
			class HitLegs: HitLegs{};
		};
	};
	class B_Soldier_F: B_soldier_base_F
	{
		class HitPoints: HitPoints
		{
			class ACE_HDBracket: ACE_HDBracket{};
			class HitFace: HitFace{};
			class HitNeck: HitNeck{};
			class HitHead: HitHead{};
			class HitPelvis: HitPelvis{};
			class HitAbdomen: HitAbdomen{};
			class HitDiaphragm: HitDiaphragm{};
			class HitChest: HitChest{};
			class HitBody: HitBody{};
			class HitArms: HitArms{};
			class HitHands: HitHands{};
			class HitLegs: HitLegs{};
		};
	};
	class JLTS_Clone_Backpack;
	class FST_Clone_Backpack212: JLTS_Clone_Backpack
	{
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		displayName="[41st] Clone Backpack (212th)";
		maximumload=250;
		model="\MRC\JLTS\characters\CloneArmor\CloneBackpack.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Equipment\FST_Clone_backpack_co"
		};
	};
	class FST_Backpack_Medic212: FST_Clone_Backpack212
	{
		author="Daara";
		displayName="[41st] Medic Backpack (212th)";
		maximumload=250;
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Equipment\FST_Clone_Medic_backpack_co"
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
	class FST_Clone_backpack_EOD212: FST_Clone_Backpack212
	{
		displayName="[41st] Clone EOD Backpack (212th)";
		maximumload=400;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Equipment\FST_Clone_EOD_backpack_co"
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
	class FST_Trooper_P2_DC15S;
	class FST_212th_P2_DC15S: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st/212th] Clone Trooper (DC-15S)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Subfaction";
		uniformclass="FST_212th_P2_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_212thTrooper_armor1_co.paa",
			"\MRC\JLTS\characters\CloneLegions\data\Clone_212thTrooper_armor2_co.paa"
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
			"FST_212th_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_212th_P2_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class FST_212th_P2_AB_DC15S: FST_Trooper_P2_DC15S
	{
		author="Gold";
		displayName="[41st/212th] Airborne Clone Trooper (DC-15S)";
		scope=2;
		Backpack="";
		side=1;
		role="Rifleman";
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Subfaction";
		uniformclass="FST_212th_AB_Uniform";
		model="\MRC\JLTS\characters\CloneArmor\CloneArmor.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneLegions\data\Clone_212thAirborne_armor1_co.paa",
			"\MRC\JLTS\characters\CloneLegions\data\Clone_212thAirborne_armor2_co.paa"
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
			"FST_212th_Airborne_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"FST_212th_Airborne_Helmet",
			"FST_base_Vest",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
	};
	class 41st_212th_3AS_Rep_Commando_base_F: B_Soldier_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando";
		scope=0;
		identityTypes[]=
		{
			"LanguageENG_F",
			"Head_NATO"
		};
		role="Rifleman";
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Subfaction";
		uniformClass="3AS_U_Rep_Katarn_Armor";
		nakedUniform="";
		backpack="3AS_B_Katarn_Backpack";
		model="\3AS\3AS_Characters\Commando\3AS_Katarn_Armor.p3d";
		modelSides[]={3,1};
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
		linkedItems[]=
		{
			"3AS_H_Katarn_Helmet",
			"ItemMap",
			"ItemGPS",
			"ItemCompass",
			"ItemWatch",
			"JLTS_clone_comlink"
		};
		respawnLinkedItems[]=
		{
			"3AS_H_Katarn_Helmet",
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
			class ACE_HDBracket: ACE_HDBracket{};
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
			hiddenSelections[]=
		{
			"Camo",
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\3AS\3AS_Characters\Commando\data\Katarn_Armor_Standard_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
	};	
	class 41st_212th_Republic_Commando: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Lead)";
		uniformClass="41st_212th_3AS_U_Rep_Katarn_Armor";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Lead_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Camo: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Lead)";
		uniformClass="41st_212th_3AS_U_Rep_Katarn_Armor_Camo";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Lead_Camo_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Medic: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Medic)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Medic";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Medic_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Medic_Camo: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Medic)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Medic_Camo";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Medic_Camo_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Demo: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Demo)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Demo";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Demo_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Demo_Camo: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Demo)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Demo_Camo";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Demo_Camo_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Marksman: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Marksman)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Marksman";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Marksman_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 41st_212th_Republic_Commando_Foxtrot_Marksman_Camo: 41st_212th_3AS_Rep_Commando_base_F
	{
		author="Gold";
		displayName="[41st/212th] Republic Commando (Foxtrot Marksman)";
		uniformClass="41st_212th_U_Rep_Katarn_Armor_Foxtrot_Marksman_Camo";
		backpack="41st_212th_B_Katarn_Backpack_Foxtrot";
		side=1;
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Uniform\Katarn_Armor_Foxtrot_Marksman_Camo_CO.paa",
			"\3AS\3AS_Characters\Commando\data\Katarn_Undersuit_CO.paa"
		};
		linkedItems[]=
		{
			"41st_212th_H_Katarn_Helmet",
			"ItemMap",
			"ItemCompass",
			"ItemWatch",
			"ItemRadio"
		};
	};
	class 3AS_Katarn_Backpack_Base;
	class 41st_212th_B_Katarn_Backpack_Foxtrot: 3AS_Katarn_Backpack_Base
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Backpack";
		Picture="FST_212th_Armor\Data\Backpack\UI\Katarn_Backpack_Unmarked_UI_ca.paa"
		maximumLoad=280;
		mass=50;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Backpack\Katarn_Backpack_Foxtrot_CO.paa"
		};
	};
	class 41st_212th_B_Katarn_Backpack_Foxtrot_Camo: 3AS_Katarn_Backpack_Base
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Backpack";
		Picture="FST_212th_Armor\Data\Backpack\UI\Katarn_Backpack_Unmarked_UI_ca.paa"
		maximumLoad=280;
		mass=50;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Backpack\Katarn_Backpack_Foxtrot_Camo_CO.paa"
		};
	};
	class 41st_212th_B_Katarn_Backpack_Foxtrot_Medic: 3AS_Katarn_Backpack_Base
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Medic Backpack";
		Picture="FST_212th_Armor\Data\Backpack\UI\Katarn_Backpack_Unmarked_UI_ca.paa"
		maximumLoad=280;
		mass=50;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Backpack\Katarn_Backpack_Foxtrot_Medic_CO.paa"
		};
	};
	class 41st_212th_B_Katarn_Backpack_Foxtrot_Medic_Camo: 3AS_Katarn_Backpack_Base
	{
		scope=2;
		displayName="[41st/212th] Republic Katarn Medic Backpack (Camo)";
		Picture="FST_212th_Armor\Data\Backpack\UI\Katarn_Backpack_Unmarked_UI_ca.paa"
		maximumLoad=280;
		mass=50;
		hiddenSelectionsTextures[]=
		{
			"FST_212th_Armor\Data\Backpack\Katarn_Backpack_Foxtrot_Medic_Camo_CO.paa"
		};
	};
	///////////////////
	///////LAATS///////
	///////////////////
	class FST_laati_Turret;
	class FST_laati_mk2;
	class FST_laati_mk1Lights;
	class FST_laati_mk2Lights;
	class FST_212th_laati_Turret: FST_laati_Turret
	{
		author="Gold";
		displayname="[41st/212th] LAAT/i Mk I Gunship";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Air_Vehicle";
		crew="FST_Pilot_P1";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_Laat\LAATI\data\Hull_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Wings_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_212th_laati_mk2: FST_laati_mk2
	{
		author="Gold";
		displayname="[41st/212th] LAAT/i Mk II Gunship";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Air_Vehicle";
		crew="FST_Pilot_P1";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_Laat\LAATI\data\Hull_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Wings_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_212th_laati_mk1Lights: FST_laati_mk1Lights
	{
		author="Gold";
		displayname="[41st/212th] LAAT/i Mk I Gunship (Lamps)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Air_Vehicle";
		crew="FST_Pilot_P1";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_Laat\LAATI\data\Hull_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Wings_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_212th_laati_mk2Lights: FST_laati_mk2Lights
	{
		author="Daara";
		displayname="[41st/212th] LAAT/i Mk II Gunship (Lamps)";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		faction="FST_212th_Faction";
		editorSubcategory="FST_212th_Air_Vehicle";
		crew="FST_Pilot_P1";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_Laat\LAATI\data\Hull_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Wings_212_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
};