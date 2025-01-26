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
			"FST_Lego_Pistol",
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
	class Pistol_Base_F;
	class WeaponSlotsInfo;
	class hgun_Pistol_heavy_01_F: Pistol_Base_F
	{
        class WeaponSlotsInfo;
	};
	class FST_Lego_Pistol: hgun_Pistol_heavy_01_F
	{
		author="Adapted from the Indecisive Armoury Team";
		displayName="[41st] Lego Pistol";
		baseWeapon="FST_Lego_Pistol";
		descriptionShort="High Powered Sidearm";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		scopearsenal=2;
		inertia=0;
		canShootInWater=1;
		picture="Indecisive_Armoury_Weapons_DEVGUNS\Data\LegoGun\LegoGun_ui.paa";
		model="Indecisive_Armoury_Weapons_DEVGUNS\Data\LegoGun\model\IDA_LegoGun.p3d";
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"Indecisive_Armoury_Weapons_DEVGUNS\Data\LegoGun\textures\LegoGun_co.paa"
		};
		magazines[]=
		{
			"FST_blaster_cell_low_Blue",
			"FST_blaster_cell_low_green",
			"FST_blaster_cell_low_yellow",
			"FST_blaster_cell_low_Red"
		};
		ace_clearJamAction="";
		reloadAction="GestureReloadPistol";
		recoil="FST_recoil_dc17";
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
		modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Scope\2dScope\IDA_DMR_Scope.p3d";
		class OpticsModes
		{
			class optic
			{
				cameraDir="";
				distanceZoomMax=200;
				distanceZoomMin=200;
				discreteDistance[]={100,200,300,400,500};
				discretefov[]={0.25};
				discreteDistanceInitIndex=0;
				discreteInitIndex=0;
				memoryPointCamera="eye";
				modelOptics[]=
				{
					"\Indecisive_Armoury_Weapons_REPUBLIC\Data\773Scope\2dScope\IDA_DMR_Scope.p3d"
				};
				opticsDisablePeripherialVision=1;
				opticsDisplayName="WFOV";
				opticsFlare=1;
				opticsID=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera2",
					"OpticsBlur3"
				};
				opticsZoomInit=0.25;
				opticsZoomMax=0.25;
				opticsZoomMin=0.25;
				useModelOptics=1;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
			};
			class Iron
			{
				distanceZoomMax=200;
				distanceZoomMin=200;
				memoryPointCamera="eye";
				opticsDisablePeripherialVision=0;
				opticsFlare=0;
				opticsID=2;
				opticsPPEffects="[""Default""]";
				opticsZoomInit=0.75;
				opticsZoomMax=1.25;
				opticsZoomMin=0.25;
				useModelOptics=0;
				visionMode="[]";
			};
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
			dispersion=0.0011;
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
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]={};
			};
			class MuzzleSlot: MuzzleSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\MUZZLE";
				compatibleItems[]=
				{
					//"muzzle_snds_L"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
	};
	class optic_Holosight;
	class IDA_Lasgun_Holo: optic_Holosight
	{
		author="Indecisive Armoury Team";
		scope=2;
		displayname="Kantrael-Pattern Holo Optic";
		picture="\Indecisive_Armoury_Weapons_DEVGUNS\Data\Lasgun\Lasgun_Sight_UI.paa";
		model="Indecisive_Armoury_Weapons_DEVGUNS\Data\Lasgun\model\IDA_Lasgun_Holo.p3d";
		memoryPointCamera="eye";
	};
};
