class CfgPatches
{
	class FST_AV7
	{
		addonRootClass="a3_data_f";
		requiredAddons[]=
		{
			"a3_data_f"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_AV7",
			"FST_AV7_EdenOnly"
		};
		weapons[]={};
	};
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgVehicles
{
	class 3AS_01_arty_base_F
	{
		class AnimationSources;
	};
	class FST_AV7: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		displayName="[41st] AV-7 Field Cannon Artillery";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
	};
	class FST_AV7_EdenOnly: 3AS_01_arty_base_F
	{
		author="Adapted from 3AS";
		forceingarage=0;
		displayName="[41st] AV-7 (Eden ONLY // Legs Deployed)";
		scope=2;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		generalMacro="B_MBT_01_arty_base_F";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
		hiddenSelections[]=
		{
			"Camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AV-7\Data\av7_co.paa"
		};
		side=1;
		class AnimationSources: AnimationSources
		{
			class Legs
			{
				source="user";
				animPeriod=0;
				initPhase=1;
				mass=1;
				author="$STR_3AS_Studio";
				displayName="Toggle Legs";
				onPhaseChanged="_this call TAS_fnc_toggleLegs;";
			};
		};
	};
};
class CfgFunctions
{
	class TAS
	{
		class AV7Fncs
		{
			file="\3as\3AS_AV7\functions";
			class toggleLegs
			{
			};
		};
	};
};
