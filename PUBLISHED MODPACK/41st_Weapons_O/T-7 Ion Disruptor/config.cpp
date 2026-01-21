class CfgPatches
{
	class FST_T7_BlasterRifle
	{
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_SemiAuto;
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class UGL_F;
	class JMSLLTE_t7BlasterRifle;
	class FST_T7_BlasterRifle: JMSLLTE_t7BlasterRifle
	{
		author="Gold";
		displayName="[41st] T-7 ion disruptor rifle";
		baseWeapon="FST_T7_BlasterRifle";
		scope=2;
		model="\JMSLLTE_weapons\disruptor\t7.p3d";
		magazines[]= 
		{
			"FST_thermal_coil_LP_Blue",
			"FST_thermal_coil_LP_Green",
			"FST_thermal_coil_LP_Yellow",
			"FST_thermal_coil_LP_Red",
			"FST_thermal_coil_T15_Blue",
			"FST_thermal_coil_T15_Green",
			"FST_thermal_coil_T15_Yellow",
			"FST_thermal_coil_T15_Red"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_T7_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_single_gm6";
			recoilProne="recoil_single_prone_gm6";
			reloadTime=2.5;
			dispersion=0.00021899999;
			minRange=1;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=4;
			aiRateOfFireDistance=1;
			aiRateOfFireDispersion=3;
		};
	};
};
