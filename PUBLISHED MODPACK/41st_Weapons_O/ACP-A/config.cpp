class CfgPatches
{
	class ACP-A
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
	class FST_ACP-A: 3AS_ScatterGun_F
	{
		author="Gold";
		displayName="[41st] ACP-A";
		baseWeapon="FST_ACP";
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
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			soundContinuous=0;
			soundBurst=0;
			
		};
	};
};
