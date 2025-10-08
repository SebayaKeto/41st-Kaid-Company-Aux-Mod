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
	class UGL_F;
	class ls_weapon_zh73_base;
	class FST_ZH73_MK2: ls_weapon_zh73_base
	{
		author="Gold";
		displayName="[41st] ZH-73 Mk-II";
		baseWeapon="FST_ZH73_MK2";
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
		muzzles[]=
		{
			"This",
			"UGL_ZH73"
		};
		class UGL_ZH73: UGL_F
		{
			displayName="[41st] ZH-73";
			useModelOptics=0;
			useExternalOptic=0;
			optics = 0;
			opticsZoomMin = 0.375;
			opticsZoomMax = 1.1;
			opticsZoomInit = 0.75;
			muzzlePos = "usti hlavne";
			muzzleEnd = "konec hlavne";
			magazines[]=
			{
				"FST_HE_LauncherGrenade",
				"FST_HE_LauncherGrenade_Delayed_5",
				"FST_Smoke_LauncherGrenade",
				"FST_SmokeRed_LauncherGrenade",
				"FST_SmokeGreen_LauncherGrenade",
				"FST_SmokeBlue_LauncherGrenade",
				"FST_SmokePurple_LauncherGrenade",
				"FST_Droid_Popper_Launcher",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_green",
				"ACE_40mm_Flare_White",
				"ACE_40mm_Flare_ir",
				"ACE_HuntIR_M203",
				"FST_thermal_slug_mag_Blue",
				"FST_thermal_slug_mag_Green",
				"FST_thermal_slug_mag_Red",
				"FST_thermal_slug_mag_Yellow"
			};
			cameraDir="eye";
			discreteDistance[]={50};
			discreteDistanceCameraPoint[]=
			{
				"eye"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
			magazineWell[]={};
		};
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
