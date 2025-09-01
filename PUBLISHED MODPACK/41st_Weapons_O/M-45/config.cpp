class CfgPatches
{
	class FST_M45_BlasterRifle
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
	class JMSLLTE_M45BlasterRifle;
	class FST_M45_BlasterRifle: JMSLLTE_M45BlasterRifle
	{
		author="Gold";
		displayName="[41st] M-45 ion blaster";
		baseWeapon="FST_M45_BlasterRifle";
		scope=2;
		model="JMSLLTE_weapons\M45\M45.p3d";
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.11;
			dispersion=0.0021899999;
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_M45_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			autoFire=0;
			soundContinuous=0;
			soundBurst=0;
			showToPlayer=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=0.001;
			aiRateOfFireDistance=25;
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
					"JMSLLTE_M45_Shot_SoundSet",
					"DMR06_tail_SoundSet",
					"DMR06_InteriorTail_SoundSet"
				};
			};
			soundContinuous=0;
			ffCount=1;
			reloadTime=0.1;
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			dispersion="0.00219";
			soundBurst=0;
			showToPlayer=1;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=5;
			aiRateOfFireDistance=25;
		};
	};
};
