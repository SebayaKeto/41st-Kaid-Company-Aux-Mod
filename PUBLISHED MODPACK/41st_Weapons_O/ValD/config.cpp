class CfgPatches
{
	class FST_ValD
	{
		requiredAddons[]=
		{
			"A3_Weapons_F"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_FullAuto;
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class DBA_Val_C3;
	class FST_ValD: DBA_Val_C3
	{
		author="Gold";
		displayName="[41st] Val-D";
		baseWeapon="FST_ValD";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_ValD\DBA_ValD.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		class fullAuto: Mode_FullAuto
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
					"DBA_Republic\Addons\DBA_Weapons\DBA_ValD\Data\vad.ogg",
					1.55,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0.00145;
			recoil="M240Recoil";
			recoilProne="M240RecoilProne";
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
	};
};
