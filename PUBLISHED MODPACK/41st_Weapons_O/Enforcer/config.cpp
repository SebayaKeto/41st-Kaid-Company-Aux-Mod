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
class Mode_SemiAuto;
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
		modes[]=
		{
			"Single",
			"FullAuto"
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
				soundSetShot[]=
				{
					"3AS_DLT19_Shot_SoundSet"
				};
			};
			reloadTime=0.059999999;
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
				soundSetShot[]=
				{
					"3AS_DLT19_Shot_SoundSet"
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
