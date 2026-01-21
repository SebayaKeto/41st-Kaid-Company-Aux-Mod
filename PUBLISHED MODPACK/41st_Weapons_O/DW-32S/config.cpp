class CfgPatches
{
	class FST_DW32S
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
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class JLTS_DW32S;
	class FST_DW32S: JLTS_DW32S
	{
		author="Gold";
		displayName="[41st] DW-32S";
		baseWeapon="FST_DW32S";
		scope=2;
		model="\MRC\JLTS\weapons\DW32S\DW32S.p3d";
		magazines[]=
		{
			"FST_DW32S_Mag_Blue",
			"FST_DW32S_Mag_Green",
			"FST_DW32S_Mag_Red",
			"FST_DW32S_Mag_Yellow",
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\DC15A\sounds\dc15a_fire",
					1,
					1.1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.6;
			recoil="recoil_single_mx";
			recoilProne="recoil_single_prone_mx";
			dispersion=0.00086999999;
			minRange=60;
			minRangeProbab=1;
			midRange=300;
			midRangeProbab=0.85;
			maxRange=10000;
			maxRangeProbab=0.05;
			aiRateOfFire=1.5;
			aiRateOfFireDistance=150;
			aiRateOfFireDispersion=2;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"MRC\JLTS\weapons\DC15A\sounds\dc15a_fire",
					1,
					1.1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.096000001;
			dispersion=0.00086999999;
			recoil="recoil_auto_mx";
			recoilProne="recoil_auto_prone_mx";
			minRange=1;
			minRangeProbab=0;
			midRange=50;
			midRangeProbab=0;
			maxRange=100;
			maxRangeProbab=0;
		};
	};
};
class CfgMagazines
{
	class JLTS_DW32S_mag;
	class FST_DW32S_Mag_Blue: JLTS_DW32S_mag
	{
		author="Gold";
		model="\MRC\JLTS\weapons\DW32S\DW32S_mag.p3d";
		count=20;
		displayName="DW32S 20Rnd Mag";
		ammo="FST_blasterbolt_DMR_Blue";
	};
	class FST_DW32S_Mag_Green: JLTS_DW32S_mag
	{
		author="Gold";
		model="\MRC\JLTS\weapons\DW32S\DW32S_mag.p3d";
		count=20;
		displayName="DW32S 20Rnd Mag";
		ammo="FST_blasterbolt_DMR_Green";
	};
	class FST_DW32S_Mag_Red: JLTS_DW32S_mag
	{
		author="Gold";
		model="\MRC\JLTS\weapons\DW32S\DW32S_mag.p3d";
		count=20;
		displayName="DW32S 20Rnd Mag";
		ammo="FST_blasterbolt_DMR_Red";
	};
	class FST_DW32S_Mag_Yellow: JLTS_DW32S_mag
	{
		author="Gold";
		model="\MRC\JLTS\weapons\DW32S\DW32S_mag.p3d";
		count=20;
		displayName="DW32S 20Rnd Mag";
		ammo="FST_blasterbolt_DMR_Yellow";
	};
};