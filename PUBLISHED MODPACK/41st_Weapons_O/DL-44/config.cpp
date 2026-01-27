class CfgPatches
{
	class FST_DL44_Pistol
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
	class JMSLLTE_dl44pistol;
	class FST_DL44_Pistol: JMSLLTE_dl44pistol
	{
		author="Gold";
		scope=2;
		displayName="[41st] DL-44 heavy blaster pistol";
		baseWeapon="FST_DL44_Pistol";
		model="\JMSLLTE_weapons\dl44\dl44.p3d";
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
					"JMSLLTE_DL44_Shot_SoundSet",
					"SDAR_Tail_SoundSet",
					"SDAR_InteriorTail_SoundSet"
				};
			};
			recoil="recoil_pistol_heavy";
			recoilProne="recoil_prone_pistol_heavy";
			reloadTime=0.15000001;
			dispersion=0.00135;
			minRange=0;
			minRangeProbab=1;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=250;
			maxRangeProbab=0.5;
		};
	};
};
