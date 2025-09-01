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
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		class Burst: Mode_Burst
		{
			reloadTime=0.050000001;
			dispersion=0.00066000002;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
					"3AS_Cinnagaran_SoundSet"
				};
			};
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.079999998;
			dispersion=0.00106;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
					"3AS_Cinnagaran_SoundSet"
				};
			};
		};
	};
};
