class CfgPatches
{
	class FST_ACPA
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
	class 3AS_ScatterGun_F;
	class FST_ACPA: 3AS_ScatterGun_F
	{
		author="Gold";
		displayName="[41st] ACP-A";
		baseWeapon="FST_ACPA";
		scope=2;
		model="3as\3AS_Weapons\Scattergun\3AS_Scattergun_F.p3d";
		magazines[]=
		{
			"FST_blaster_scatter_cell_SBB3_Blue",
			"FST_blaster_scatter_cell_SBB3_Green",
			"FST_blaster_scatter_cell_SBB3_Yellow",
			"FST_blaster_scatter_cell_SBB3_Red",
		};
		magazineWell[]={};
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
					"3AS_Scattergun_SoundSet"
				};
			};
			reloadTime=1.5;
			dispersion=0.00066000002;
			minRange=1;
			minRangeProbab=1;
			midRange=25;
			midRangeProbab=0.075000003;
			maxRange=10000;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			
		};
	};
};
