class CfgPatches
{
	class 41st_Vehicles_MSE
	{
		author="Gold";
		requiredAddons[]={"A3_Soft_F"};
		units[]=
		{
			"FST_MSE_Gweem"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class JLTS_UGV_MSE6;
	class FST_MSE_Gweem: JLTS_UGV_MSE6
	{
		author="Gold";
		displayName="[41st] MSE-6 (Gweem)";
		faction="FST_Faction";
		scope=2;
		side=1;
		model="\MRC\JLTS\drones\mse6\mse6.p3d";
		hiddenSelections[]=
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\MSE\Data\FST_MSE_Body.paa",
			"41st_Vehicles\MSE\Data\FST_MSE_Parts.paa"
		};
		class TextureSources{};
	};
};