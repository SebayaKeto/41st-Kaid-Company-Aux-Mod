class CfgPatches
{
	class FST_Cinnagaran_Carbine
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
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class 3AS_Cinnagaran_Carbine_F;
	class FST_Cinnagaran_Carbine: 3AS_Cinnagaran_Carbine_F
	{
		author="Gold";
		displayName="[41st] Cinnagaran Carbine";
		baseWeapon="FST_Cinnagaran_Carbine";
		scope=2;
		model="3as\3AS_Weapons\Greenfor\model\3AS_CinnagaranCarbine.p3d";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue_smg",
			"FST_blaster_cell_low_Green_smg",
			"FST_blaster_cell_low_Yellow_smg",
			"FST_blaster_cell_low_Red_smg"
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.050000001;
			dispersion=0.00066000002;
			minRange=20;
			minRangeProbab=0.89;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=55;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Arkanian_SoundSet"
				};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.079999998;
			dispersion=0.00206;
			minRange=1;
			minRangeProbab=0.99;
			midRange=50;
			midRangeProbab=0.75;
			maxRange=100;
			maxRangeProbab=0.2;
			aiRateOfFire=2;
			aiRateOfFireDistance=1000;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_Arkanian_SoundSet"
				};
			};
		};
	};
};
