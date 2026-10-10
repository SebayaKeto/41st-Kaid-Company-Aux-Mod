class CfgPatches
{
	class 41st_Hungergames
	{
		units[]=
		{
			"FST_HungerGamesLootSpawner",
			"FST_HungerGamesStartPoint"
		};
	};
	author="Tooka";
};
class CfgFunctions
{
    class FST_HungerGamesFunctions
    {
        class FST_HGStuff
        {
            file = "41st_Hungergames\Scripts";
            class spawncrates {postInit=1;};
        };
    };
};
class CfgWeapons
{
	
	class VestItem;
	class FST_Vest_Base;
	class FST_HGVest_Mini: FST_Vest_Base
	{
		author="Tooka";
		scope=2;
		displayName="Tiny Vest";
		class ItemInfo: VestItem
		{
			uniformmodel="";
			containerclass="Supply10";
			mass=15;
			vesttype="Rebreather";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.05;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.05;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.05;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.05;
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
	class FST_HGVest_Small: FST_Vest_Base
	{
		author="Tooka";
		scope=2;
		displayName="Small Vest";
		class ItemInfo: VestItem
		{
			uniformmodel="";
			containerclass="Supply40";
			mass=15;
			vesttype="Rebreather";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.05;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.05;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.05;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.05;
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
	class FST_HGVest_Med: FST_Vest_Base
	{
		author="Tooka";
		scope=2;
		displayName="Standard Vest";
		class ItemInfo: VestItem
		{
			uniformmodel="";
			containerclass="Supply80";
			mass=15;
			vesttype="Rebreather";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.05;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.05;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.05;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.05;
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
	class FST_HGVest_Large: FST_Vest_Base
	{
		author="Tooka";
		scope=2;
		displayName="Large Vest";
		class ItemInfo: VestItem
		{
			uniformmodel="";
			containerclass="Supply100";
			mass=15;
			vesttype="Rebreather";
			class HitpointsProtectionInfo
			{
				class Chest
				{
					HitpointName="HitChest";
					armor=6;
					PassThrough=0.05;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.05;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.05;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.05;
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
	class FST_HGVest_Huge: FST_Vest_Base
	{
		author="Tooka";
		scope=2;
		displayName="Huge Vest";
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
					PassThrough=0.05;
				};
				class Diaphragm
				{
					HitpointName="HitDiaphragm";
					armor=6;
					PassThrough=0.05;
				};
				class Abdomen
				{
					hitpointName="HitAbdomen";
					armor=6;
					PassThrough=0.05;
				};
				class Body
				{
					hitpointName="HitBody";
					armor=6;
					PassThrough=0.05;
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
};
class CfgVehicles
{
	class Strategic;
	class FST_HungerGamesLootSpawner: Strategic
	{
		author="Tooka";
		model="3as\3as_Structures2\MissionTools\Garrisonpoints.p3d";
		editorPreview="";
		placement="vertical";
		editorcategory="FST_Crates";
		editorsubcategory="FST_Supplies";
		mapSize=1;
		destrType="DestructNo";
		displayName="Loot Crate Spawn Point";
		vehicleClass="Prop";
		faction="Prop";
		scope=2;
		scopeCurator=2;
		eden=1;
	};
	class FST_HungerGamesStartPoint: Strategic
	{
		author="Tooka";
		model="3as\3as_Structures2\MissionTools\Garrisonpoints.p3d";
		editorPreview="";
		placement="vertical";
		editorcategory="FST_Crates";
		editorsubcategory="FST_Supplies";
		mapSize=1;
		destrType="DestructNo";
		displayName="Hunger Games Player Start Point";
		vehicleClass="Prop";
		faction="Prop";
		scope=2;
		scopeCurator=2;
		eden=1;
	};
	class FST_CIS_Officer_Legbag;
	class FST_CIS_Marksman_Satchel;
	class FST_Belt_Bag;
	class FST_Clone_Backpack;
	class FST_HGBag_Mini: FST_CIS_Officer_Legbag
	{
		author="Tooka";
		scope=2;
		displayName="Tiny Bag";
		maximumLoad=10;
		mass=5;
	};
	class FST_HGBag_Small: FST_CIS_Marksman_Satchel
	{
		author="Tooka";
		scope=2;
		displayName="Small Bag";
		maximumLoad=40;
		mass=5;
	};
	class FST_HGBag_Med: FST_Belt_Bag
	{
		author="Tooka";
		scope=2;
		displayName="Standard Bag";
		maximumLoad=80;
		mass=5;
	};
	class FST_HGBag_Large: FST_Clone_Backpack
	{
		author="Tooka";
		scope=2;
		displayName="Large Bag";
		maximumLoad=150;
		mass=5;
	};
	class FST_HGBag_Huge: FST_Clone_Backpack
	{
		author="Tooka";
		scope=2;
		displayName="Huge Bag";
		model="\3AS\3AS_Characters\Commando\3AS_Katarn_BackPack.p3d";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Armor\Data\Equipment\FST_Commando_Backpack.paa"
		};
		maximumLoad=250;
		mass=5;
	};
	class ReammoBox_F;
	class FST_HGCrate_Base: ReammoBox_F
	{
		author="Tooka";
		scope=0;
		displayName="[41st] Random Supply Container";
		vehicleClass="Ammo";
		destrType="DestructNo";
		maximumLoad=10000;
		ace_dragging_canCarry=0;
		ace_dragging_canDrag=0;
		ace_cargo_canLoad=0;
	};
	class FST_HGCrate_Ammo: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Ammo\Supply_Large_Ammo_co.paa"
		};
	};
	class FST_HGCrate_Med: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Medical\Supply_Large_Medical_co.paa"
		};
	};
	class FST_HGCrate_Explosive: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Red\Supply_Large_Red_co.paa"
		};
	};
	class FST_HGCrate_Grey: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
	};
	class FST_HGCrate_Black: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Black\Supply_Large_Black_co.paa"
		};
	};
	class FST_HGCrate_Blue: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Blue\Supply_Large_Blue_co.paa"
		};
	};
	class FST_HGCrate_Green: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Green\Supply_Large_green_co.paa"
		};
	};
	class FST_HGCrate_Orange: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_orange\Supply_Large_orange_co.paa"
		};
	};
	class FST_HGCrate_SmallGrey: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_small.p3d";
	};
	class FST_HGCrate_SmallBlack: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_small.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\supply_small_black\supply_small_black_co.paa"
		};
	};
	class FST_HGCrate_Misc1: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_2.p3d";
	};
	class FST_HGCrate_Misc2: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_4.p3d";
	};
	class FST_HGCrate_Misc3: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_5.p3d";
	};
	class FST_HGCrate_Misc4: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_3.p3d";
	};
	class FST_HGCrate_Misc5: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_6.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\box_co.paa",
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\lid_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\box.rvmat",
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\lid.rvmat"
		};
	};
	class FST_HGCrate_Misc6: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\crate5-3.p3d";
	};
	class FST_HGCrate_Misc7Orange: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
	};
	class FST_HGCrate_Misc7Black: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_black\small_box_9_black_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_black\small_box_9_black.rvmat"
		};
	};
	class FST_HGCrate_Misc7Blue: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_blue\small_box_9_blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_blue\small_box_9_blue.rvmat"
		};
	};
	class FST_HGCrate_Misc7Grey: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_grey\small_box_9_grey_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_grey\small_box_9_grey.rvmat"
		};
	};
	class FST_HGCrate_Misc8: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_10.p3d";
	};
	class FST_HGCrate_Misc9: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_11.p3d";
	};
	class FST_HGCrate_Misc10: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_12.p3d";
	};
	class FST_HGCrate_Misc11: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_13.p3d";
	};
	class FST_HGCrate_Misc12: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="FST\FST_Props\FST_Crates\RepublicStandardUnits\RSUStandardCECOne.p3d";
		hiddenselections[]=
		{
			"Camo",
			"Camo1"
		};
		hiddenselectionstextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_HGCrate_Misc13: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxSmall.p3d";
	};
	class FST_HGCrate_Misc14: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxSmall2.p3d";
	};
	class FST_HGCrate_Misc15: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxMedium2.p3d";
	};
	class FST_HGCrate_Misc16: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrate.p3d";
	};
	class FST_HGCrate_Misc17: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrate2.p3d";
	};
	class FST_HGCrate_Misc18: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrateSmall.p3d";
	};
	class FST_HGCrate_Misc19: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\OPTRE_Buildings\Containers\optre_milcrate_h2smallcrate";
	};
	class FST_HGCrate_Misc20: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\OPTRE_Buildings\Containers\optre_milcrate_h2agray";
	};
	class FST_HGCrate_Misc21: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa"
		};
	};
	class FST_HGCrate_WBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\barrel_small.p3d";
	};
	class FST_HGCrate_BBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\3as_barrel_closed.p3d";
	};
	class FST_HGCrate_GBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\barrel_3.p3d";
	};
	class FST_HGCrate_SmallBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="kobra\442_misc\barrel2\k_barrel1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"kobra\442_misc\barrel2\data\barrel1_co.paa"
		};
	};
	class FST_HGCrate_GSmallBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Bootcamp\Items\Food\FoodContainer_01_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\structures_f_bootcamp\items\food\data\foodcontainer_01_co.paa"
		};
	};
	class FST_HGCrate_WSmallBarrel: FST_HGCrate_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Bootcamp\Items\Food\FoodContainer_01_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\Props_F_Orange\Humanitarian\Supplies\Data\foodcontainer_01_white_co.paa"
		};
	};
	class ThingX;
	class FST_HGBomb_Base: ThingX
	{
		author="Tooka";
		scope=0;
		displayName="[41st] Random Supply Container";
		ace_dragging_canCarry=0;
		ace_dragging_canDrag=0;
		ace_cargo_canLoad=0;
	};
	class FST_HGBomb_Ammo: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Ammo\Supply_Large_Ammo_co.paa"
		};
	};
	class FST_HGBomb_Med: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Medical\Supply_Large_Medical_co.paa"
		};
	};
	class FST_HGBomb_Explosive: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Red\Supply_Large_Red_co.paa"
		};
	};
	class FST_HGBomb_Grey: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
	};
	class FST_HGBomb_Black: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Black\Supply_Large_Black_co.paa"
		};
	};
	class FST_HGBomb_Blue: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Blue\Supply_Large_Blue_co.paa"
		};
	};
	class FST_HGBomb_Green: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_Green\Supply_Large_green_co.paa"
		};
	};
	class FST_HGBomb_Orange: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_Large.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Supply_Large_orange\Supply_Large_orange_co.paa"
		};
	};
	class FST_HGBomb_SmallGrey: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_small.p3d";
	};
	class FST_HGBomb_SmallBlack: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\supply_small.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\supply_small_black\supply_small_black_co.paa"
		};
	};
	class FST_HGBomb_Misc1: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_2.p3d";
	};
	class FST_HGBomb_Misc2: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_4.p3d";
	};
	class FST_HGBomb_Misc3: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_5.p3d";
	};
	class FST_HGBomb_Misc4: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\Small_Box_3.p3d";
	};
	class FST_HGBomb_Misc5: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_6.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\box_co.paa",
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\lid_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\box.rvmat",
			"3AS\3AS_Props\Crates\Data\Small_Box_6_Civilian\lid.rvmat"
		};
	};
	class FST_HGBomb_Misc6: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\crate5-3.p3d";
	};
	class FST_HGBomb_Misc7Orange: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
	};
	class FST_HGBomb_Misc7Black: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_black\small_box_9_black_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_black\small_box_9_black.rvmat"
		};
	};
	class FST_HGBomb_Misc7Blue: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_blue\small_box_9_blue_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_blue\small_box_9_blue.rvmat"
		};
	};
	class FST_HGBomb_Misc7Grey: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_9.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_grey\small_box_9_grey_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"3AS\3AS_Props\Crates\Data\small_box_9_grey\small_box_9_grey.rvmat"
		};
	};
	class FST_HGBomb_Misc8: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_10.p3d";
	};
	class FST_HGBomb_Misc9: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_11.p3d";
	};
	class FST_HGBomb_Misc10: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_12.p3d";
	};
	class FST_HGBomb_Misc11: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\small_box_13.p3d";
	};
	class FST_HGBomb_Misc12: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="FST\FST_Props\FST_Crates\RepublicStandardUnits\RSUStandardCECOne.p3d";
		hiddenselections[]=
		{
			"Camo",
			"Camo1"
		};
		hiddenselectionstextures[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1_co.paa",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo_CEC1.rvmat",
			"FST\FST_Props\FST_Crates\RepublicStandardUnits\Data\Textures\Camo1_CEC1.rvmat"
		};
	};
	class FST_HGBomb_Misc13: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxSmall.p3d";
	};
	class FST_HGBomb_Misc14: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxSmall2.p3d";
	};
	class FST_HGBomb_Misc15: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\BoxMedium2.p3d";
	};
	class FST_HGBomb_Misc16: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrate.p3d";
	};
	class FST_HGBomb_Misc17: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrate2.p3d";
	};
	class FST_HGBomb_Misc18: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\JMSLLTE_props\Containers\EmpCrateSmall.p3d";
	};
	class FST_HGBomb_Misc19: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\OPTRE_Buildings\Containers\optre_milcrate_h2smallcrate";
	};
	class FST_HGBomb_Misc20: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\OPTRE_Buildings\Containers\optre_milcrate_h2agray";
	};
	class FST_HGBomb_Misc21: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Heli\Items\Luggage\PlasticCase_01_small_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\Props_F_Orange\Humanitarian\Supplies\Data\PlasticCase_01_gray_CO.paa"
		};
	};
	class FST_HGBomb_WBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\barrel_small.p3d";
	};
	class FST_HGBomb_BBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\3as_barrel_closed.p3d";
	};
	class FST_HGBomb_GBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="3as\3as_props\crates\models\barrel_3.p3d";
	};
	class FST_HGBomb_SmallBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="kobra\442_misc\barrel2\k_barrel1.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"kobra\442_misc\barrel2\data\barrel1_co.paa"
		};
	};
	class FST_HGBomb_GSmallBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Bootcamp\Items\Food\FoodContainer_01_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\structures_f_bootcamp\items\food\data\foodcontainer_01_co.paa"
		};
	};
	class FST_HGBomb_WSmallBarrel: FST_HGBomb_Base
	{
		author="Tooka";
		scope=1;
    	scopeCurator=0;
		model="\A3\Structures_F_Bootcamp\Items\Food\FoodContainer_01_F.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"a3\Props_F_Orange\Humanitarian\Supplies\Data\foodcontainer_01_white_co.paa"
		};
	};
};