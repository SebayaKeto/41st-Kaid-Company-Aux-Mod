class CfgPatches
{
	class FST_TL50
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
	class JMSLLTE_tl50;
	class FST_TL50: JMSLLTE_tl50
	{
		author="Gold";
		displayName="[41st] TL-50 heavy repeater";
		baseWeapon="FST_TL50";
		scope=2;
		model="\JMSLLTE_weapons\tl50\tl50.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
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
					"JMSLLTE_E11_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_auto_mk20";
			recoilProne="recoil_auto_prone_mk20";
			reloadTime=0.075000003;
			dispersion=0.007;
			minRange=1;
			minRangeProbab=0.99;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=10000;
			maxRangeProbab=0.2;
		};
	};
};
