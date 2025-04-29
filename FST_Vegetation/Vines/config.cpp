#define _ARMA_

class CfgPatches
{
	class FST_Vegetation_Vines
	{
		units[] = {"FST_Vine_KashyyykOne"};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F"};
		version = 1.14;
		author = "Maldova";
	};
};
class CfgVehicles
{
	class Strategic;
	class 3AS_Light_Coral: Strategic
	{
		scope = 2;
		eden = 1;
		model = "3as\Prop_Rugosa\Rugosa_light\Corral 1.p3d";
		placement = "vertical";
		mapSize = 3;
		displayName = "Kashyyyk Vines 1";
		faction = "prop";
		texture = "3as\Prop_Rugosa\data\Coral123_co.paa";
		editorcategory = "FST_CatagoryVegetationKashyyyk";
		editorsubcategory = "FST_Subcategory_KashyyykVines";
	};
};
