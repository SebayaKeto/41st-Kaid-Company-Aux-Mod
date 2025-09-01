class CfgPatches
{
	class FST_Maalras_SMG
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
	class DBA_MaalrasSMG_F;
	class FST_Maalras_SMG: DBA_MaalrasSMG_F
	{
		author="Gold";
		displayName="[41st] Maalras";
		baseWeapon="FST_Maalras_SMG";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\MaalrasSMG.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		class Single: Mode_SemiAuto
		{
			multiplier=1;
			burst=1;
			reloadTime=0.059999999;
			soundContinuous=0;
			autoFire=0;
			aiRateOfFire=0.1;
			aiRateOfFireDistance=0;
			dispersion=0.0020300001;
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
					"DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\SMG.ogg",
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
		};
		class FullAuto: Mode_FullAuto
		{
			multiplier=1;
			burst=1;
			soundContinuous=0;
			autoFire=1;
			aiRateOfFire=0.079999998;
			aiRateOfFireDistance=0;
			dispersion=0.0020300001;
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
					"DBA_Republic\Addons\DBA_Weapons\DBA_Maalras\SMG.ogg",
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
			reloadTime=0.059999999;
		};
	};	
};
