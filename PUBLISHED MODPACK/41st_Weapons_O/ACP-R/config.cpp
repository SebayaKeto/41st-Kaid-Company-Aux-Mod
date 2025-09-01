class CfgPatches
{
	class FST_ACPR
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
	class ls_weapon_acpr_base;
	class FST_ACPR: ls_weapon_acpr_base
	{
		author="Gold";
		displayName="[41st] ACP-R";
		baseWeapon="FST_ACPR";
		scope=2;
		model="\ls\core\addons\weapons_repeaters\acpr\ls_weapon_acpr.p3d";
		magazines[]=
		{
			"FST_ACPR_Mag_Blue",
			"FST_ACPR_Mag_Green",
			"FST_ACPR_Mag_Red",
			"FST_ACPR_Mag_Yellow"
		};
		magazineWell[]={};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"\ls\core\addons\sounds\weapons\ls150\shot1.wss",
					1,
					1,
					800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.15000001;
			dispersion=0.0030149999;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=25;
		};
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				begin1[]=
				{
					"\ls\core\addons\sounds\weapons\ls150\shot1.wss",
					1,
					1,
					800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0.0014545;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=25;
		};
	};
};
class CfgMagazines
{
	class ls_magazine_acpr;
	class FST_ACPR_Mag_Blue: ls_magazine_acpr
	{
		author="Gold";
		displayName="ACPR 60Rnd Mag (Blue)";
		model="\ls\core\addons\weapons_repeaters\acpr\ls_magazine_acpr.p3d";
		count=60;
		ammo="FST_blasterbolt";
	};
	class FST_ACPR_Mag_Green: FST_ACPR_Mag_Blue
	{
		author="Gold";
		displayName="ACPR 60Rnd Mag (Green)";
		model="\ls\core\addons\weapons_repeaters\acpr\ls_magazine_acpr.p3d";
		count=60;
		ammo="FST_blasterbolt_Green";
	};
	class FST_ACPR_Mag_Red: FST_ACPR_Mag_Blue
	{
		author="Gold";
		displayName="ACPR 60Rnd Mag (Red)";
		model="\ls\core\addons\weapons_repeaters\acpr\ls_magazine_acpr.p3d";
		count=60;
		ammo="FST_blasterbolt_Red";
	};
	class FST_ACPR_Mag_Yellow: FST_ACPR_Mag_Blue
	{
		author="Gold";
		displayName="ACPR 60Rnd Mag (Yellow)";
		model="\ls\core\addons\weapons_repeaters\acpr\ls_magazine_acpr.p3d";
		count=60;
		ammo="FST_blasterbolt_Yellow";
	};
};
