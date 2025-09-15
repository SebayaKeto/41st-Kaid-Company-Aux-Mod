class CfgPatches
{
	class FST_Trenches_EntrenchingTool
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian",
			"FST_Core"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Trench_Short"
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
	class FST_Trench_Base: House_F
	{
		editorCategory = "FST_CatagoryTrenches";
		editorSubcategory = "FST_Subcategory_TrenchesEntrenchingTool";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "[41st] Security Barrier";
		model = "FST\FST_Trenches\FST_Trench_Short.p3d";
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Trench_Short: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
};
