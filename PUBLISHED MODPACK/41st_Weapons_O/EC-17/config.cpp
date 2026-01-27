class CfgPatches
{
	class FST_EC17_Pistol
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
	class JMSLLTE_ec17pistol;
	class FST_EC17_Pistol: JMSLLTE_ec17pistol
	{
		author="Gold";
		scope=2;
		displayName="[41st] EC-17 hold-out blaster";
		baseWeapon="FST_EC17_Pistol";
		model="\JMSLLTE_weapons\RK3\ec17.p3d";
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
					"JMSLLTE_EC17_Shot_SoundSet",
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
