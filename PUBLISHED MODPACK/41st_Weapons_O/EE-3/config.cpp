class CfgPatches
{
	class FST_A280
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
class Mode_Burst;
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class JMSLLTE_ee3;
	class FST_EE3: JMSLLTE_ee3
	{
		author="Gold";
		displayName="[41st] EE-3 blaster carbine";
		baseWeapon="FST_EE3";
		scope=2;
		model="\JMSLLTE_weapons\ee3\ee3.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
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
					"JMSLLTE_EE3_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_single_sdar";
			recoilProne="recoil_single_prone_sdar";
			reloadTime=0.25;
			dispersion=0.00030000001;
			minRange=100;
			minRangeProbab=0.6;
			midRange=200;
			midRangeProbab=0.5;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class Burst: Mode_Burst
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
					"JMSLLTE_EE3_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			soundBurst=0;
			burst=3;
			reloadTime=0.11;
			recoil="recoil_burst_sdar";
			recoilProne="recoil_burst_prone_sdar";
			dispersion=0.00030000001;
			minRange=1;
			minRangeProbab=0.99;
			midRange=50;
			midRangeProbab=0.75;
			maxRange=100;
			maxRangeProbab=0.2;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
		};
	};
};
