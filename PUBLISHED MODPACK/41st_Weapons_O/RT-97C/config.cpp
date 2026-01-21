class CfgPatches
{
	class FST_RT97C_BlasterRifle
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
	class JMSLLTE_rt97cBlasterRifle;
	class FST_RT97C_BlasterRifle: JMSLLTE_rt97cBlasterRifle
	{
		author="Gold";
		displayName="[41st] RT-97C heavy blaster rifle";
		baseWeapon="FST_RT97C_BlasterRifle";
		scope=2;
		model="JMSLLTE_weapons\rt97c\rt97c.p3d";
		magazines[]= 
		{
			"FST_blaster_battery_DC15L_Blue",
			"FST_blaster_battery_DC15L_Green",
			"FST_blaster_battery_DC15L_Yellow",
			"FST_blaster_battery_DC15L_Red"
		};
		class Single: Mode_SemiAuto
		{
			reloadTime=0.12;
			dispersion=0.00229;
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
					"JMSLLTE_RT97c_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			autoFire=0;
			soundContinuous=0;
			soundBurst=0;
			showToPlayer=1;
			minRange=2;
			minRangeProbab=0;
			midRange=100;
			midRangeProbab=0;
			maxRange=10000;
			maxRangeProbab=0;
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
					"JMSLLTE_RT97c_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			soundContinuous=0;
			ffCount=1;
			reloadTime=0.1;
			recoil="recoil_auto_mk200";
			recoilProne="recoil_auto_prone_mk200";
			dispersion=0.00229;
			soundBurst=0;
			showToPlayer=1;
			minRange=1;
			minRangeProbab=1;
			midRange=50;
			midRangeProbab=1;
			maxRange=10000;
			maxRangeProbab=0.1;
			aiRateOfFire=0.05;
			aiRateOfFireDistance=1000;
		};
	};
};
