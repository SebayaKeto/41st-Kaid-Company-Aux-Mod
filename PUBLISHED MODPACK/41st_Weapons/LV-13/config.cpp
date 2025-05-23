class CfgPatches
{
	class FST_Weapons_LV13
	{
		requiredAddons[]=
		{
			"OPTRE_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_LV_13"
		};
	};
};
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;
class CfgWeapons
{
	class NVGoggles;
	class Pistol_Base_F;
	class WeaponSlotsInfo;
	class hgun_Pistol_heavy_01_F: Pistol_Base_F
	{
        class WeaponSlotsInfo;
	};
	class FST_LV_13: hgun_Pistol_heavy_01_F
	{
		author="Gold";
		displayName="[41st] LV-13 'Baihe' Heavy Blaster";
		descriptionShort="High Powered Sidearm";
		baseWeapon="FST_LV_13";
		picture="\MRC\JLTS\weapons\DC17SA\data\ui\DC17SA_ui_ca.paa";
		model="\OPTRE_Weapons_Pistols\comet\optre_comet";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		inertia=0;
		canShootInWater=1;
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Weapons\LV-13\Data\optre_comet_Base_co_Blossom.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"41st_Weapons\LV-13\Data\optre_comet_Blank_Details.rvmat",
		};
		magazines[]=
		{
			"FST_blaster_cell_LV13_Blue",
			"FST_blaster_cell_LV13_green",
			"FST_blaster_cell_LV13_yellow",
			"FST_blaster_cell_LV13_Red"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadPistolHeavy02";
		recoil="FST_recoil_LV13";
		magazineWell[]={};
		fireLightDiffuse[]={0,0,1};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
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
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.2,
					"begin2",
					0.2,
					"begin3",
					0.2,
					"begin4",
					0.2,
					"begin5",
					0.2
				};
				beginwater1[]=
				{
					"\41st_Weapons\DC17\Data\dc17v2 2-117.ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1
				};
			};
			reloadTime=0.1;
			dispersion=0;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=20;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Attachment_Optic_Holo_DC15"
				};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]=
				{
					"JLTS_DC17SA_flashlight"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]={};
				iconPosition[]={0.23999999,0.34999999};
				iconScale=0.2;
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
};
