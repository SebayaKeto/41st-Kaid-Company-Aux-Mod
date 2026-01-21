class CfgPatches
{
	class FST_EE4
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
	class JMSLLTE_ee4;
	class FST_EE4: JMSLLTE_ee4
	{
		author="Gold";
		displayName="[41st] EE-4 blaster rifle";
		baseWeapon="FST_EE4";
		scope=2;
		model="\JMSLLTE_weapons\ee3\ee4.p3d";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue_smg",
			"FST_blaster_cell_low_Green_smg",
			"FST_blaster_cell_low_Yellow_smg",
			"FST_blaster_cell_low_Red_smg"
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
					"JMSLLTE_EE4_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_single_sdar";
			recoilProne="recoil_single_prone_sdar";
			reloadTime=0.19;
			dispersion=0.0020000001;
			minRange=20;
			minRangeProbab=0.89;
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
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_EE4_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_single_sdar";
			recoilProne="recoil_single_prone_sdar";
			reloadTime=0.11;
			dispersion=0.0022;
			minRange=1;
			minRangeProbab=0.99;
			midRange=50;
			midRangeProbab=0.75;
			maxRange=100;
			maxRangeProbab=0.2;
		};
	};
};
