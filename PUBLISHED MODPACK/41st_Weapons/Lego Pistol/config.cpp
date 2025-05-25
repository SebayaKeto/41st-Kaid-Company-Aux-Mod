class CfgPatches
{
	class FST_Weapons_Lego
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Lego_Pistol"
		};
	};
};
class Mode_SemiAuto;
class CfgWeapons
{
	class IDA_LegoGun;
	class FST_Lego_Pistol: IDA_LegoGun
	{
		author="Gold";
		displayName="[41st] Lego Pistol";
		baseWeapon="FST_Lego_Pistol";
		descriptionShort="High Powered Sidearm";
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_green",
			"FST_blaster_cell_low_yellow",
			"FST_blaster_cell_low_Red"
		};
		recoil="FST_recoil_dc17";
		magazineWell[]={};
		muzzles[]=
		{
			"this"
		};
		class Single: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType
			{
				weaponSoundEffect="";
				begin1[]=
				{
					"\Indecisive_Armoury_Sounds\DEVGUNS\LegoGun.ogg",
					1.5,
					1,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				beginwater1[]=
				{
					"\Indecisive_Armoury_Sounds\DEVGUNS\LegoGun.ogg",
					1.5,
					1,
					1800
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0.0011;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
	};
};
