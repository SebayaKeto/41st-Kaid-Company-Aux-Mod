#define _ARMA_

class CfgPatches
{
	class FST_Vegetation_Vines
	{
		units[] = {"FST_Vine_KashyyykOne","FST_Vine_KashyyykWoodlandOne","FST_Vine_KashyyykSwampOne"};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F"};
		version = 1.14;
		author = "Maldova";
	};
};
class CfgVehicles
{
	class Strategic;
	class FST_Vine_KashyyykBase: Strategic
	{
		scope = 1;
		eden = 1;
		model = "FST\FST_Vegetation\Vines\KashyyykVinesOne.p3d";
		placement = "vertical";
		mapSize = 3;
		displayName = "Kashyyyk Vines Base";
		faction = "prop";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_Common\Data\Textures\JungleWood\JungleWoodOne_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Common\Data\Textures\JungleWood\FST_KashyyykVineOne.rvmat"};
		editorcategory = "FST_CatagoryVegetationKashyyyk";
		editorsubcategory = "FST_Subcategory_KashyyykVines";
	};
	class FST_Vine_KashyyykJungleOne: FST_Vine_KashyyykBase
	{
		scope = 2;
		displayName = "Kashyyyk Vines (Jungle 1)";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_Common\Data\Textures\JungleWood\JungleWoodOne_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Common\Data\Textures\JungleWood\FST_KashyyykVineOne.rvmat"};
	};
	class FST_Vine_KashyyykWoodlandOne: FST_Vine_KashyyykBase
	{
		scope = 2;
		displayName = "Kashyyyk Vines (Woodland 1)";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_Common\Data\Textures\JungleWood\JungleWoodTwo_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Common\Data\Textures\JungleWood\FST_KashyyykVineTwo.rvmat"};
	};
	class FST_Vine_KashyyykSwampOne: FST_Vine_KashyyykBase
	{
		scope = 2;
		displayName = "Kashyyyk Vines (Swamp 1)";
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_Common\Data\Textures\JungleWood\JungleWoodSwamp_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Common\Data\Textures\JungleWood\FST_KashyyykVineSwamp.rvmat"};
	};
};
