class CfgPatches
{
	class FST_K16_Pistol
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
	class JMSLLTE_K16pistol;
	class FST_K16_Pistol: JMSLLTE_K16pistol
	{
		author="Gold";
		scope=2;
		displayName="[41st] K-16 Bryar pistol";
		baseWeapon="FST_K16_Pistol";
		model="\JMSLLTE_weapons\bryar\bryarpistol.p3d";
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
					"JMSLLTE_K16_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.15000001;
			dispersion=0.0011;
			minRange=0;
			minRangeProbab=1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=250;
			maxRangeProbab=0.5;
		};
	};
};
