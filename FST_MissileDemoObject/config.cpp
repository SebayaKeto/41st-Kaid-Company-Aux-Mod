class CfgPatches
{
	class FST_Barricades_SecurityBarrier
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian"
		};
		requiredVersion=0.1;
		units[]=
		{
			"DemoMissile"
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
	class DemoMissile_F: House_F
	{
		editorCategory = "";
		editorSubcategory = "";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "Demo Missile Object";
		model = "FST\FST_MissileDemoObject\DemoMissileObject.p3d";
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class DemoMissile: DemoMissile_F
	{
		scope = 2;
		scopecurator = 2;
		displayName = "Demo Missile Object Overwrite"; // Name you want displayed in game
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"FST\FST_MissileDemoObject\Data\Textures\YOURTEXTUREHERE.paa"};
		hiddenSelctionsMaterials[] = {"FST\FST_MissileDemoObject\Data\Textures\YOURRVMATHERE.rvmat"};
	};
};