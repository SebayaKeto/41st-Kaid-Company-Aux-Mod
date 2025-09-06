class CfgPatches
{
	class FST_Electrobinoculars
	{
		author="Viz";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]={};
		magazines[]={};
	};
};
class CfgWeapons
{
	class Laserdesignator;
	class FST_Electrobinoculars: Laserdesignator
	{
		author="Adapted from JLTS Team by Viz";
		scope=2;
		scopecurator=2;
		displayName="[41st] Kaid Company Electrobinoculars";
		descriptionShort="Republic Electrobinoculars";
		picture="\MRC\JLTS\characters\CloneArmor\data\ui\Clone_binocular_ui_ca.paa";
		model="\MRC\JLTS\characters\CloneArmor\CloneBinocular.p3d";
		modelOptics="\MRC\JLTS\characters\CloneArmor\CloneBinocular_optics.p3d";
		opticsPPEffects[]=
		{
			"OpticsCHAbera1",
			"OpticsBlur1"
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_binocular_co.paa"
		};
	};
	class FST_Black_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] Kaid Company Electrobinoculars (Black)";
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\characters\CloneArmor\data\Clone_binocular_black_co.paa"
		};
	};
	class FST_Woodland_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] Kaid Company Electrobinoculars (Woodland)";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Electrobinoculars\Data\FST_Electro_Binos_Woodland.paa",
		};
	};
	class FST_Midnight_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] Kaid Company Electrobinoculars (Midnight)";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Electrobinoculars\Data\FST_Electro_Binos_Midnight.paa",
		};
	};
	class FST_Urban_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] Kaid Company Electrobinoculars (Urban)";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Electrobinoculars\Data\FST_Electro_Binos_Urban.paa",
		};
	};
	class FST_Desert_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] Kaid Company Electrobinoculars (Desert)";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Electrobinoculars\Data\FST_Electro_Binos_Desert.paa",
		};
	};
	class FST_ARF_Electrobinoculars: FST_Electrobinoculars
	{
		displayName="[41st] ARF Electrobinoculars";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\Electrobinoculars\Data\FST_Electro_Binos_Woodland.paa",
		};
		visionMode[] = 
		{
			"Normal",
			"NVG",
			"Ti"
		};
		thermalMode[] = {0, 1};
		//opticsZoomMin = 0.1;
		//opticsZoomMax = 1.2;
		//opticsZoomInit = 0.5;
	};
};