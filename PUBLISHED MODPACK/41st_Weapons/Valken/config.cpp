class CfgPatches
{
	class FST_Weapons_Valken
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Valken38x",
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
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class WeaponSlotsInfo;
	class FST_Scope_VK38X: ItemCore
	{
		scope=2;
		displayName="[41st] VK-38X Scope";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="3AS\3AS_Weapons\Valken38X\3AS_VK38X_Scope_f.p3d";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=7;
			modelOptics="\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
			class OpticsModes
			{
				class 3AS_VK38X_Optic
				{
					opticsID=1;
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera1",
						"OpticsBlur1"
					};
					opticsZoomMin=0.125;
					opticsZoomMax=0.125;
					opticsZoomInit=0.125;
					discreteDistance[]={100,300,400,500,600,700,800,900,1000};
					discreteDistanceInitIndex=1;
					distanceZoomMin=100;
					distanceZoomMax=1000;
					discreteFov[]={0.125,0.125};
					discreteInitIndex=0;
					modelOptics[]=
					{
						"\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d"
					};
					memoryPointCamera="opticView";
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={1,2};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					cameraDir="";
				};
				class IronOnTopOfMyOptics: 3AS_VK38X_Optic
				{
					opticsID=2;
					useModelOptics=0;
					opticsFlare=0;
					opticsDisablePeripherialVision=0;
					opticsZoomMin=0.375;
					opticsZoomMax=1.1;
					opticsZoomInit=0.75;
					memoryPointCamera="eye";
					visionMode[]={};
					discretefov[]={};
				};
			};
		};
	};
	class 3AS_Valken38X_F;
	class FST_Valken38x: 3AS_Valken38X_F
	{
		author="Gold";
		displayName="[41st] Valken-38X rifle";
		baseWeapon="FST_Valken38x";
		descriptionShort="Multi-Role Elite Rifle.";
		model="3AS\3AS_Weapons\Valken38X\3AS_Valken38X.p3d";
		picture="\3AS\3AS_Weapons\Valken38X\Data\UI\3as_valken.paa";
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		scope=2;
		inertia=0;
		canShootInWater=1;
		ace_clearJamAction="";
		reloadAction="3AS_GestureReload_DC17M";
		recoil="FST_recoil_DC15A";
		magazines[]=
		{
			"FST_blaster_cell_Valken_Blue",
			"FST_blaster_cell_Valken_Green",
			"FST_blaster_cell_Valken_Yellow",
			"FST_blaster_cell_Valken_Red",
			"FST_blaster_cell_High_Blue",		//"IDA_blaster_cell_High",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
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
					"\41st_Weapons\Valken\Data\Valken_Sound_New_1.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_2.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_3.ogg",
					1.25,
					0.98500001,
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
				};
				beginwater1[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_1.ogg",
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
			reloadTime=0.075000003;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class FullAuto: Mode_FullAuto
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
					"\41st_Weapons\Valken\Data\Valken_Sound_New_1.ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_2.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_3.ogg",
					1.25,
					0.98500001,
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
				};
				beginwater1[]=
				{
					"\41st_Weapons\Valken\Data\Valken_Sound_New_1.ogg",
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
			reloadTime=0.085714288;
			dispersion=0.0024000001;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Scope_VK38X"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]={};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[]=
				{
					"3AS_Bipod_VK38X_f"
				};
			};
		};
		class GunParticles
		{
			class FirstEffect
			{
				directionName="Konec hlavne";
				effectName="RifleAssaultCloud";
				positionName="Usti hlavne";
			};
		};
	};
};
