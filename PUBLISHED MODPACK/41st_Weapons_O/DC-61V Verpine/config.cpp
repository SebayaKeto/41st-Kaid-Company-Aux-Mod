class CfgPatches
{
	class FST_Verpine
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
	class DBA_XM61V_F;
	class FST_Verpine: DBA_XM61V_F
	{
		author="Gold";
		displayName="[41st] DC-61V 'Verpine'";
		baseWeapon="FST_Verpine";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_Verpine\verpine.p3d";
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				weaponSoundEffect="DefaultRifle";
				begin1[]=
				{
					"MRC\JLTS\weapons\DC15X\sounds\dc15x_fire",
					2.5,
					1,
					1800
				};
				closure2[]=
				{
					"A3\sounds_f\weapons\closure\zafir_closure_2",
					0.5,
					1,
					10
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				soundClosure[]=
				{
					"closure2",
					1
				};
			};
			recoil="recoil_single_mx";
			recoilProne="recoil_single_prone_mx";
			reloadTime=0.1875;
			dispersion=0.00029088801;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=300;
		};
	};
};
