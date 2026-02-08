class CfgPatches
{
	class FST_Outpost_MediumWalls
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian",
			"FST_Core",
			"FST_Common"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Outpost_MediumWallShort_Unmarked"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class Ruins_F;
	class FST_Outpost_MediumWall_Base: House_F
	{
		editorCategory = "FST_CatagoryMajorOutpost";
		editorSubcategory = "FST_Subcategory_OutpostWallsNeutral";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "Medium Outpost Wall (Unmarked)";
		model = "FST\FST_Outpost\MediumWalls\FST_OutpostWall_MediumShort.p3d";
		hiddenSelections[]={"Camo"};
		hiddenSelectionsTextures[]=
		{
			"FST\FST_Outpost\MediumWalls\Data\Textures\Walls\Camo_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"FST\FST_Outpost\MediumWalls\Data\Textures\Walls\Camo.rvmat"
		};
		eden = 1;
	};
	class FST_Outpost_MediumWallShort_Unmarked: FST_Outpost_MediumWall_Base
	{
		scope = 2;
		scopecurator = 2;
	};
};

