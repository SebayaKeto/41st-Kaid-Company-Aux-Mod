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
			"FST_Trench_Short",
			"FST_Trench_Long",
			"FST_Trench_High",
			"FST_Trench_Vehicle",
			"FST_Trench_Varactyl",
			"FST_Trench_Foxhole",
			"FST_Trench_Big",
			"FST_Trench_Giant"
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
		displayName = "Short Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Short.p3d";
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"FST\FST_Common\Data\Textures\DarkBrownStone\DarkBrownStone_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Common\Data\Textures\DarkBrownStone\DarkBrownStone.rvmat"};
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Trench_Short: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Short Trench";
	};
	class FST_Trench_Long: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Long Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Long.p3d";
	};
	class FST_Trench_High: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "High Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_High.p3d";
	};
	class FST_Trench_Vehicle: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Vehicle Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Vehicle.p3d";
	};
	class FST_Trench_Varactyl: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Varactyl Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Dorito.p3d";
	};
	class FST_Trench_Foxhole: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Foxhole Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Foxhole.p3d";
	};
	class FST_Trench_Big: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Big Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Big.p3d";
	};
	class FST_Trench_Giant: FST_Trench_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Giant Trench";
		model = "FST\FST_Trenches\FST_DugTrenches\FST_Trench_Giant.p3d";
	};
};
