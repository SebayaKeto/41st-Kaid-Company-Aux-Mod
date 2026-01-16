class CfgPatches
{
	class FST_Enforcer
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
	class DBA_Enforcer_F;
	class FST_Enforcer: DBA_Enforcer_F
	{
		author="Gold";
		displayName="[41st] Enforcer SMG";
		baseWeapon="FST_Enforcer";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_Enforcer\Enforcer.p3d";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue_smg",
			"FST_blaster_cell_low_Green_smg",
			"FST_blaster_cell_low_Yellow_smg",
			"FST_blaster_cell_low_Red_smg"
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
