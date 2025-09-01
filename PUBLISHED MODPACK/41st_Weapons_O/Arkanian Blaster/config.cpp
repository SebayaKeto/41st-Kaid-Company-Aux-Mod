class CfgPatches
{
	class FST_Arkanian_F
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
	class 3AS_Arkanian_F;
	class FST_Arkanian_F: 3AS_Arkanian_F
	{
		author="Gold";
		displayName="[41st] Arkanian Blaster";
		baseWeapon="FST_Arkanian_F";
		scope=2;
		model="3as\3AS_Weapons\Greenfor\model\3AS_ArkanianBlasterRifle.p3d";
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
					"3AS_Arkanian_SoundSet"
				};
			};
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
		};
		class FullAuto: Mode_FullAuto
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
					"3AS_Arkanian_SoundSet"
				};
			};
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
		};
	};
	class 3AS_Arkanian_Stock_F;
	class FST_Arkanian_Stock_F: 3AS_Arkanian_Stock_F
	{
		author="Gold";
		displayName="[41st] Arkanian Blaster (Stock)";
		baseWeapon="FST_Arkanian_Stock_F";
		scope=2;
		model="3as\3AS_Weapons\Greenfor\model\3AS_ArkanianBlasterRifleStock.p3d";
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
					"3AS_Arkanian_SoundSet"
				};
			};
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
		};
		class FullAuto: Mode_FullAuto
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
					"3AS_Arkanian_SoundSet"
				};
			};
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
		};
	};
};
