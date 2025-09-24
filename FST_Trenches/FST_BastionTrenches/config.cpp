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
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Trench_Bastion_Small: FST_Trench_BastionBase
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Bastion Small Trench";
	};
};
