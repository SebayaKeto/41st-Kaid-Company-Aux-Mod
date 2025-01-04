class CfgPatches
{
	class FST_AR_2
	{
		requiredAddons[]=
		{
			"A3_Drones_F",
			"A3_Weapons_F_Beta_Ammoboxes"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_AR2",
			"FST_AR2_Backpack"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class B_UAV_01_F;
	class FST_AR2:B_UAV_01_F
	{
		author="Viz";
		scope=2;
		scopecurator=2;
		side=1;
		displayName="[41st] ARF AR-2 Drone";
		faction="FST_Faction";
		model="3as\3as_Drones\UAS2\UAS2.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenselectionsTextures[]=
		{
			"3as\3as_Drones\UAS2\data\recondrone_CO.paa"
		};
		class assembleInfo
		{
			primary=1;
			base="";
			assembleTo="";
			displayName="";
			dissasembleTo[]=
			{
				"FST_AR2_Backpack"
			};
		};
	};
	class Bag_Base;
	class Weapon_Bag_Base: Bag_Base
	{
		class assembleInfo;
	};
    class B_UAV_01_backpack_F: Weapon_Bag_Base{};
    class FST_AR2_Backpack: B_UAV_01_backpack_F
	{
		author="Viz";
		faction="FST_Faction";
        displayName="[41st] AR-2 Drone (Backpack)";
		scope=2;
		scopeCurator=2;
		editorCategory="FST_Crates";
        editorSubcategory="FST_Supplies";
		picture="\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UI\icon_B_C_UAV_rgr_ca";
		model="\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
        hiddenSelectionsTextures[]=
        {
			"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UAV_backpack_rgr_co.paa"
        };
		class assembleInfo: assembleInfo
		{
			base="";
			displayName="ARF AR-2 Drone";
			assembleTo="FST_AR2";
		};
	};
};