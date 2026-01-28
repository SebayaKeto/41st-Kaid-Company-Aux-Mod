class CfgPatches
{
	class FST_DC17M
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"A3_Data_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class UGL_F;
class CfgWeapons
{
	class 3AS_DC17M_F;
	class FST_DC17M: 3AS_DC17M_F
	{
		author="Gold";
		displayName="[41st] DC17M Carbine";
		baseWeapon="FST_DC17M";
		scope=2;
		model="3AS\3AS_Weapons\DC17M\3AS_DC17M_f";
		magazines[]=
		{
			"FST_DC17M_EC40_Cell_Blue",
			"FST_DC17M_EC40_Cell_Green",
			"FST_DC17M_EC40_Cell_Red",
			"FST_DC17M_EC40_Cell_Yellow",
			"FST_DC17M_EC80_Cell_Blue",
			"FST_DC17M_EC80_Cell_Green",
			"FST_DC17M_EC80_Cell_Red",
			"FST_DC17M_EC80_Cell_Yellow"
		};
		magazineWell[]={};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.16500001;
			dispersion=0.00092999998;
			minRange=0;
			minRangeProbab=0.99;
			midRange=50;
			midRangeProbab=0.75;
			maxRange=100;
			maxRangeProbab=0.2;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					""
				};
			};
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.1;
			dispersion=0.00025000001;
			minRange=20;
			minRangeProbab=0.89;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_DC17M_Shot_SoundSet"
				};
			};
		};
	};
};
class CfgMagazines
{
	class 3AS_100Rnd_EC40_mag;
	class FST_DC17M_EC40_Cell_Blue: 3AS_100Rnd_EC40_mag
	{
		author="Gold";
		displayName="DC17M 40Rnd Mag (Blue)";
		count=40;
		ammo="FST_blasterbolt";
	};
	class FST_DC17M_EC40_Cell_Green: FST_DC17M_EC40_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 40Rnd Mag (Green)";
		count=40;
		ammo="FST_blasterbolt_Green";
	};
	class FST_DC17M_EC40_Cell_Red: FST_DC17M_EC40_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 40Rnd Mag (Red)";
		count=40;
		ammo="FST_blasterbolt_Red";
	};
	class FST_DC17M_EC40_Cell_Yellow: FST_DC17M_EC40_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 40Rnd Mag (Yellow)";
		count=40;
		ammo="FST_blasterbolt_Yellow";
	};
	class 3AS_5Rnd_EC80_mag;
	class FST_DC17M_EC80_Cell_Blue: 3AS_5Rnd_EC80_mag
	{
		author="Gold";
		displayName="DC17M 5Rnd EC80 Overcharged Cell (Blue)";
		count=5;
		ammo="FST_blasterbolt_Overcharged_Blue";
	};
	class FST_DC17M_EC80_Cell_Green: FST_DC17M_EC80_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 5Rnd EC80 Overcharged Cell (Green)";
		count=5;
		ammo="FST_blasterbolt_Overcharged_Green";
	};
	class FST_DC17M_EC80_Cell_Red: FST_DC17M_EC80_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 5Rnd EC80 Overcharged Cell (Red)";
		count=5;
		ammo="FST_blasterbolt_Overcharged_Red";
	};
	class FST_DC17M_EC80_Cell_Yellow: FST_DC17M_EC80_Cell_Blue
	{
		author="Gold";
		displayName="DC17M 5Rnd EC80 Overcharged Cell (Yellow)";
		count=5;
		ammo="FST_blasterbolt_Overcharged_Yellow";
	};
};