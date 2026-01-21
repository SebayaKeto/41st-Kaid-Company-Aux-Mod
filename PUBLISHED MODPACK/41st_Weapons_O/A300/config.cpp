class CfgPatches
{
	class FST_A300
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
	class JMSLLTE_a300;
	class FST_A300: JMSLLTE_a300
	{
		author="Gold";
		displayName="[41st] A300 blaster rifle";
		baseWeapon="FST_A300";
		scope=2;
		model="JMSLLTE_weapons\a300\a300.p3d";
		magazines[]=
		{
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red"
		};
		class Single: Mode_SemiAuto
		{
			dispersion=0.00034999999;
			soundContinuous=0;
			reloadTime=0.80000001;
			recoil="recoil_single_mx";
			recoilProne="recoil_single_prone_mx";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"JMSLLTE_A300_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			minRange=75;
			minRangeProbab=0.6;
			midRange=200;
			midRangeProbab=0.5;
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
					"JMSLLTE_A300_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_auto_mk20";
			recoilProne="recoil_auto_prone_mk20";
			reloadTime=0.12;
			dispersion=0.0012000001;
			minRange=1;
			minRangeProbab=0.7;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.30000001;
		};
	};
	class JMSLLTE_a300c;
	class FST_A300C: JMSLLTE_a300c
	{
		author="Gold";
		displayName="[41st] A300C blaster rifle";
		baseWeapon="FST_A300C";
		scope=2;
		model="\JMSLLTE_weapons\a300\a300c.p3d";
		modes[]=
		{
			"Single"
		};
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Blue",
			"FST_blaster_scatter_cell_SBB3_Green",
			"FST_blaster_scatter_cell_SBB3_Yellow",
			"FST_blaster_scatter_cell_SBB3_Red",
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
					"JMSLLTE_A300_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_single_mx";
			recoilProne="recoil_single_prone_mx";
			reloadTime=0.5;
			dispersion=0.0011;
			minRange=1;
			minRangeProbab=1;
			midRange=50;
			midRangeProbab=0.7;
			maxRange=10000;
			maxRangeProbab=0.001;
		};
	};	
};
