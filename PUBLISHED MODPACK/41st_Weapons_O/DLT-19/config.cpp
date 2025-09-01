class CfgPatches
{
	class FST_DLT19_Rifle
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
	class JMSLLTE_DLT19dRifle;
	class FST_DLT19_Rifle: JMSLLTE_DLT19dRifle
	{
		author="Gold";
		displayName="[41st] DLT-19 heavy blaster rifle";
		baseWeapon="FST_DLT19_Rifle";
		scope=2;
		model="JMSLLTE_weapons\DLT19\DLT19d.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Overcharged_Blue",
			"FST_blaster_cell_Overcharged_Green",
			"FST_blaster_cell_Overcharged_Yellow",
			"FST_blaster_cell_Overcharged_Red"
		};
		class Single: Mode_SemiAuto
		{
			dispersion=0.00034999999;
			soundContinuous=0;
			reloadTime=1.2;
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
					"JMSLLTE_DLT19D_Shot_SoundSet",
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
