class CfgPatches
{
	class FST_DT12_Pistol
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
class CfgWeapons
{
	class JMSLLTE_dt12pistol;
	class FST_DT12_Pistol: JMSLLTE_dt12pistol
	{
		author="Gold";
		scope=2;
		displayName="[41st] DT-12 heavy blaster pistol";
		baseWeapon="FST_DT12_Pistol";
		model="\JMSLLTE_weapons\dt12\dt12.p3d";
		magazines[]=
		{
			"FST_blaster_cell_SSP_Blue",
			"FST_blaster_cell_SSP_Green",
			"FST_blaster_cell_SSP_Yellow",
			"FST_blaster_cell_SSP_Red"
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
					"JMSLLTE_dt12_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.13;
			dispersion=0.000165;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
	};
};
