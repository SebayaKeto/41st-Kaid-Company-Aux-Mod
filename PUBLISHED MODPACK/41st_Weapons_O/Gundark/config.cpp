class CfgPatches
{
	class FST_Gundark
	{
		requiredAddons[]=
		{
			"A3_Weapons_F",
			"DBA_Gundark"
		};
		units[]={};
		weapons[]={};
	};
};
class Mode_SemiAuto;
class CfgWeapons
{
	class DBA_Gundarkm_F;
	class FST_Gundark: DBA_Gundarkm_F
	{
		author="Gold";
		displayName="[41st] Gundark";
		baseWeapon="FST_Gundark";
		scope=2;
		model="DBA_Republic\Addons\DBA_Weapons\DBA_Gundark\gundark.p3d";
		magazines[]=
		{
			"FST_blaster_cell_LE_Blue",
			"FST_blaster_cell_LE_Green",
			"FST_blaster_cell_LE_Yellow",
			"FST_blaster_cell_LE_Red"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="DefaultRifle";
				closure1[]=
				{
					"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_06_Mk14\DMR_06_Closure_1",
					0.39810699,
					1,
					30
				};
				closure2[]=
				{
					"A3\Sounds_F_Mark\arsenal\weapons\LongRangeRifles\DMR_06_Mk14\DMR_06_Closure_2",
					0.39810699,
					1,
					30
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
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
			recoil="recoil_single_ebr";
			recoilProne="recoil_single_prone_ebr";
			reloadTime=0.75;
			dispersion=0.00029088801;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=1;
			aiRateOfFireDistance=500;
		};
	};
};
