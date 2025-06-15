class CfgPatches
{
	class Dreadnaught
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_Data_F",
			"A3_Weapons_F_Gamma"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
		magazines[]={};
		ammo[]={};
	};
};
class CfgVehicles
{
	class House_F;
	class FST_DHC_Cardinal: House_F
	{
		author="Gold";
		scope=2;
		scopeCurator=2;
		displayname="[41st] Dreadnaught-class-Heavy-Cruiser (Cardinal)";
		model="victoryIISD\DHC.p3d";
		editorCategory="basedship";
		editorSubCategory="EdSubCat_HeavyCruisers";
		editorPreview="";
		hiddenSelections[]=
		{
			"camo_Hull",
			"camo_Base"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Dreadnaught\Data\FST_Dreadnought_Cardi.paa",
			"41st_Vehicles\Dreadnaught\Data\FST_Dreadnought_Cardi.paa"
		};
	};
};