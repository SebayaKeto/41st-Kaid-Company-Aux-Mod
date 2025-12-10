class CfgPatches
{
	class FST_SE14R
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
class CfgWeapons
{
	class 3AS_SE14R;
	class FST_SE14R: 3AS_SE14R
	{
		author="Gold";
		scope=2;
		displayName="[41st] SE-14r Light Rpeating Blaster";
		baseWeapon="FST_SE14R";
		model="\3AS\3AS_Weapons\Imperial\3AS_SE14R.p3d";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_Green",
			"FST_blaster_cell_low_Yellow",
			"FST_blaster_cell_low_Red"
		};
		magazineWell[]={};
		class Single: Mode_SemiAuto
		{
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
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.1;
			dispersion=0.0039900001;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=2;
			aiRateOfFireDistance=25;
		};
		class Burst: Mode_Burst
		{
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
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_SE14R_Shot_SoundSet"
				};
			};
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.1;
			dispersion=0.0035;
			minRange=1;
			minRangeProbab=1;
			midRange=75;
			midRangeProbab=0.65;
			maxRange=100;
			maxRangeProbab=0.05;
			aiRateOfFire=1;
			aiRateOfFireDistance=20;
			aiRateOfFireDispersion=1;
			soundContinuous=0;
			soundBurst=0;
			
		};
	};
};
