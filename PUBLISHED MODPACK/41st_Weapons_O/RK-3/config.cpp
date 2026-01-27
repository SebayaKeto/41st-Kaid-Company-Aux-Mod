class CfgPatches
{
	class FST_RK3_Pistol
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
	class JMSLLTE_rk3pistol;
	class FST_RK3_Pistol: JMSLLTE_rk3pistol
	{
		author="Gold";
		displayName="[41st] RK-3 blaster";
		baseWeapon="FST_RK3_Pistol";
		scope=2;
		model="\JMSLLTE_weapons\RK3\rk3.p3d";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_Green",
			"FST_blaster_cell_low_Yellow",
			"FST_blaster_cell_low_Red"
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
					"JMSLLTE_RK3_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.12;
			dispersion=0.00115;
			minRange=0;
			minRangeProbab=1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=250;
			maxRangeProbab=0.5;
		};
	};
};
