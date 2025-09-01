class CfgPatches
{
	class FST_E17D_Rifle
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
class WeaponSlotsInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class JMSLLTE_E17DRifle;
	class FST_E17D_Rifle: JMSLLTE_E17DRifle
	{
		author="Gold";
		displayName="[41st] E-17d sniper rifle";
		baseWeapon="FST_E17D_Rifle";
		scope=2;
		model="JMSLLTE_weapons\E17D\E17D.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Overcharged_Blue",
			"FST_blaster_cell_Overcharged_Green",
			"FST_blaster_cell_Overcharged_Yellow",
			"FST_blaster_cell_Overcharged_Red"
		};
		class Single: Mode_SemiAuto
		{
			dispersion=0.00024999998;
			soundContinuous=0;
			reloadTime=1.9;
			recoil="recoil_single_gm6";
			recoilProne="recoil_single_prone_gm6";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_E17D_Shot_SoundSet",
					"DMR06_tail_SoundSet",
					"DMR06_InteriorTail_SoundSet"
				};
			};
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=3;
			aiRateOfFireDistance=500;
		};
	};	
};
