class CfgPatches
{
	class FST_ATRT
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Characters_F"
		};
		requiredVersion=0.1;
		units[]=	
		{
			"FST_ATRT"
		};
		weapons[]=
		{
			"FST_ATRT_Weapon_F"
		};
		worlds[]={};
	};
};
class CfgVehicles
{
	class 3AS_ATRT_Base;
	class FST_ATRT: 3AS_ATRT_Base
	{
		author="Daara";
		model="\3AS\ATRT\3AS_ATRT.p3d";
		scope=2;
		scopeCurator=2;
		displayName="[41st] AT-RT Recon Walker";
		armor=500;
		armorStructural=20;
		explosionShielding=999;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		hiddenSelections[]=
		{
			"Camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\AT-RT\textures\ATRT_CO_41st.paa"
		};
		weapons[]=
		{
			"FST_ATRT_Weapon_F"
		};
		magazines[]=
		{
			"FST_9999Rnd_ATRT_Mag"
		};
		uniformClass="FST_ATRT_Uniform";
		nakedUniform="FST_ATRT_Uniform";
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
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class FST_ATRT_Weapon_Base_F: Rifle_Base_F
	{
		author="The Clone Wars Mod Team";
		magazines[]=
		{
			"FST_9999Rnd_ATRT_Mag"
		};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="3AS_recoil_DC15L";
		maxRecoilSway=0;
		swayDecaySpeed=1.25;
		inertia=0;
		dexterity=1;
		initSpeed=-1;
		maxZeroing=100;
		cursorAim="gl";
		cursor="EmptyCursor";
		cursorAimOn="CursorAimOn";
		class GunParticles: GunParticles
		{
			class SecondEffect
			{
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[]=
				{
					"3AS_optic_ATRT"
				};
			};
			class PointerSlot: PointerSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[]=
				{
					"acc_flashlight",
					"acc_pointer_IR"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]={};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="DC-15L, The Clone Wars Mod";
		handAnim[]=
		{
			""
		};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[]=
		{
			"FullAuto"
		};
		class FullAuto: Mode_FullAuto
		{
			reloadTime=0.4;
			dispersion=0.00145;
			minRange=0;
			minRangeProbab=0.89999998;
			midRange=15;
			midRangeProbab=0.69999999;
			maxRange=30;
			maxRangeProbab=0.1;
			soundContinuous=0;
			soundBurst=0;
			sounds[]=
			{
				"StandardSound",
				"SilencedSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_ATRT_Shot_SoundSet"
				};
			};
			class SilencedSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					""
				};
			};
		};
		aiDispersionCoefY=6;
		aiDispersionCoefX=4;
		caseless[]=
		{
			"",
			1,
			1,
			1
		};
		soundBullet[]=
		{
			"caseless",
			1
		};
		drySound[]=
		{
			"\3AS\3AS_Main\Sounds\Blaster_empty",
			2,
			1,
			20
		};
		reloadMagazineSound[]=
		{
			"\3AS\3AS_Main\Sounds\Old\Blaster_reload.wss",
			1,
			1,
			30
		};
	};
	class FST_ATRT_Weapon_F: FST_ATRT_Weapon_Base_F
	{
		scope=1;
		displayName="[41st] Light Laser Cannon";
		model="3AS\ATRT\Weapon\3AS_ATRT_Weapon_f.p3d";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		weaponInfoType="RscWeaponZeroing";
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=0;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=1;
		ace_overheating_dispersion=0.75;
	};
	class ItemCore;
	class UniformItem;
	class HeadgearItem;
	class VestItem;
	class FST_ATRT_Base: ItemCore
	{
		scope=0;
		allowedSlots[]={901};
		model="\A3\Characters_F\Common\Suitpacks\suitpack_universal_F.p3d";
		picture="";
		class ItemInfo: UniformItem
		{
			uniformModel="-";
			uniformClass="FST_ATRT_Base";
			containerClass="Supply10";
			mass=5;
		};
	};
	class FST_ATRT_Uniform: FST_ATRT_Base
	{
		author="Jek";
		scope=1;
		displayName="[41st] ATRT Uniform";
		picture="";
		subItems[]=
		{
			"Integrated_NVG_F"
		};
		class ItemInfo: ItemInfo
		{
			uniformClass="FST_ATRT";
		};
	};
};
class CfgMagazines
{
	class Default;
	class CA_Magazine: Default
	{
	};
	class CA_LauncherMagazine: CA_Magazine
	{
	};
	class FST_9999Rnd_ATRT_Mag: CA_Magazine
	{
		author="The Clone Wars Mod Team";
		scope=1;
		displayName="[41st] ATRT Battery Pack";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		ammo="FST_ATRT_bluePlasma";
		count=360;
		mass=10;
		initSpeed=400;
		tracersEvery=1;
		lastRoundsTracer=9999;
		descriptionShort="Standard Battery Packs used by ATRT";
	};
};
class CfgAmmo
{
	class 3AS_PlasmaBase;
	class FST_ATRT_bluePlasma: 3AS_PlasmaBase
	{
		hit=100;
		indirectHit=15;
		indirectHitRange=3;
		caliber=4.1999998;
		visibleFire=32;
		audibleFire=200;
		visibleFireTime=8;
		dangerRadiusBulletClose=16;
		dangerRadiusHit=40;
		suppressionRadiusBulletClose=10;
		suppressionRadiusHit=14;
		cost=35;
		model="Indecisive_Armoury_SW\Ammos\Data\Tracers\IDA_Blasterbolt_Blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		tracerScale=2.5;
		tracerStartTime=0;
		tracerEndTime=10;
		muzzleEffect="";
		typicalSpeed=400;
		airlock=1;
		aiAmmoUsageFlags="128 + 512";
		allowAgainstInfantry=1;
	};
};
class cfgFunctions
{
	class FST
	{
		tag="FST";
		class FST_ATRT
		{
			file="\41st_Vehicles\AT-RT\functions\ATRT";
			class initATRT
			{
			};
			class mountATRT
			{
			};
			class dismountATRT
			{
			};
			class spawnATRTSmoke
			{
			};
		};
	};
};
class Extended_Init_EventHandlers
{
	class FST_ATRT
	{
		class FST_ATRT_Init
		{
			init="(_this select 0) call FST_fnc_initATRT";
		};
	};
};