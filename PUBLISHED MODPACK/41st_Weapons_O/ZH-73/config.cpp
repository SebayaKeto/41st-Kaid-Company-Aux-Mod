class CfgPatches
{
	class FST_ZH73
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
	class ls_weapon_zh73_base;
	class FST_ZH73: ls_weapon_zh73_base
	{
		author="Gold";
		displayName="[41st] ZH-73 Mk-I";
		baseWeapon="FST_ZH73";
		scope=2;
		model="\ls\core\addons\weapons_zh73\ls_weapon_zh73.p3d";
		magazines[]=
		{
			"FST_ZH73_Mag_Blue",
			"FST_ZH73_Mag_Green",
			"FST_ZH73_Mag_Red",
			"FST_ZH73_Mag_Yellow"
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
				weaponSoundEffect="";
				begin1[]=
				{
					"\ls\core\addons\sounds\weapons\zh73\shot1.wss",
					1,
					1,
					1800
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
				weaponSoundEffect="";
				begin1[]=
				{
					"\ls\core\addons\sounds\weapons\zh73\shot1.wss",
					1,
					1,
					2000
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.13;
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
	class ls_magazine_zh73;
	class FST_ZH73_Mag_Blue: ls_magazine_zh73
	{
		author="Gold";
		displayName="High-Power Energy Cell ZH73 (Blue)";
		model="\ls\core\addons\weapons_dcseries\dc15a\ls_magazine_dc15a.p3d";
		count=40;
		ammo="FST_blasterbolt_High_Blue";
	};
	class FST_ZH73_Mag_Green: FST_ZH73_Mag_Blue
	{
		author="Gold";
		displayName="High-Power Energy Cell ZH73 (Green)";
		ammo="FST_blasterbolt_High_Green";
	};
	class FST_ZH73_Mag_Red: FST_ZH73_Mag_Blue
	{
		author="Gold";
		displayName="High-Power Energy Cell ZH73 (Red)";
		ammo="FST_blasterbolt_High_Red";
	};
	class FST_ZH73_Mag_Yellow: FST_ZH73_Mag_Blue
	{
		author="Gold";
		displayName="High-Power Energy Cell ZH73 (Yellow)";
		ammo="FST_blasterbolt_High_Yellow";
	};
};
