class CfgPatches
{
	class FST_Aegis
	{
		author="Gold";
		units[]={};
		weapons[]={};
		requiredVersion=;
		requiredAddons[]=
		{
			"A3_Characters_F"
		};
	};
};
class CfgVehicles
{
	class 3AS_Aegis_Shuttle_Pirate_F;
	class FST_Aegis_Shuttle_Tukata: 3AS_Aegis_Shuttle_Pirate_F
	{
		author = "Gold";
		crew="FST_Pilot_P1";
		displayname = "[FST] Aegis Shuttle (Gweem)";
		faction = "FST_Faction";
		editorSubcategory = "FST_Air_Vehicle";
		scope = 2;
		scopecurator = 2;
		scopearsenal = 2;
		side=1;
		textureList[]={};
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Aegis\Data\FST_Aegis_Tukata_Exterior.paa",
			"3as\3as_rebel_heli\aegis\data\camo_aegis_interior_co.paa",
			"3as\3as_rebel_heli\aegis\data\camo_aegis_extra_co.paa"
		};
	};
};