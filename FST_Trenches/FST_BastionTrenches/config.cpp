class CfgPatches
{
	class FST_Trenches_Engineered
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
			"FST_Trench_Bastion_Small"
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
	class FST_Trench_BastionBase: House_F
	{
		editorCategory = "FST_CatagoryTrenches";
		editorSubcategory = "FST_Subcategory_TrenchesBastion";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "Bastion Small Trench";
		model = "FST\FST_Trenches\FST_BastionTrenches\FST_Trench_BastionSmall.p3d";
		HiddenSelections[] = {"Camo","Camo1","Camo2"};
		HiddenSelectionsTextures[] = {"FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo_co.paa","FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo1_co.paa","FST\FST_Common\Data\Textures\SteelPlates\SteelPlates_co.paa"};
		HiddenSelectionsMaterials[] = {"FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo.rvmat","FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo1.rvmat","FST\FST_Common\Data\Textures\SteelPlates\SteelPlates.rvmat"};
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Trench_Bastion_Small: FST_Trench_BastionBase
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Bastion Small Trench";
		HiddenSelectionsTextures[] = {"FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo_co.paa","FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo1_co.paa","FST\FST_Common\Data\Textures\SteelPlates\SteelPlates_co.paa"};
		HiddenSelectionsMaterials[] = {"FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo.rvmat","FST\FST_Trenches\FST_BastionTrenches\Data\Textures\Camo1.rvmat","FST\FST_Common\Data\Textures\SteelPlates\SteelPlates.rvmat"};
	};
};
