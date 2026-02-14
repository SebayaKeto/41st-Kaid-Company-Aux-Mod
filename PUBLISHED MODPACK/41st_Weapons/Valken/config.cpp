class CfgPatches
{
	class FST_Weapons_Valken
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"3AS_Weapons_Valken38X"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_Valken38x"
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
	class InventoryOpticsItem_Base_F;
	class WeaponSlotsInfo;
	class 3AS_optic_VK38X_F;
	class FST_optic_VK38X_1: 3AS_optic_VK38X_F
	{
		author="Gold";
		scope=2;
		displayName="[41st] Valken-38X scope (1-3)";
		model="\3AS\3AS_Weapons\Republic\ACC\3AS_acco_VK38X_Scope_F.p3d";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=14;
			opticType=2;
			weaponInfoType="RscWeaponRangeZeroingFOV";
			optics=1;
			modelOptics="\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_F";
			class OpticsModes
			{
				class Snip
				{
					opticsID=1;
					opticsDisplayName="WFOV";
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera3",
						"OpticsBlur2"
					};
					opticsZoomMin="0.25/3";
					opticsZoomMax="0.25/1";
					opticsZoomInit="0.25/1";
					discreteDistance[]={100};
					discreteDistanceInitIndex=0;
					distanceZoomMin=100;
					distanceZoomMax=100;
					discretefov[]=
					{
						"0.25/1",
						"0.25/3"
					};
					discreteInitIndex=0;
					memoryPointCamera="opticView";
					modelOptics[]=
					{
						"\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_F",
						"\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_Z_F"
					};
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					cameraDir="";
				};
			};
		};
		inertia=0.2;
	};
	class FST_optic_VK38X_2: 3AS_optic_VK38X_F
	{
		author="Gold";
		scope=2;
		displayName="[41st] Valken-38X scope (4-12)";
		model="\3AS\3AS_Weapons\Republic\ACC\3AS_acco_VK38X_Scope_F.p3d";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=14;
			opticType=2;
			weaponInfoType="RscWeaponRangeZeroingFOV";
			optics=1;
			modelOptics="\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_F";
			class OpticsModes
			{
				class Snip
				{
					opticsID=1;
					opticsDisplayName="WFOV";
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera3",
						"OpticsBlur2"
					};
					opticsZoomMin="0.25/12";
					opticsZoomMax="0.25/4";
					opticsZoomInit="0.25/4";
					discreteDistance[]={100};
					discreteDistanceInitIndex=0;
					distanceZoomMin=100;
					distanceZoomMax=100;
					discretefov[]=
					{
						"0.25/4",
						"0.25/12"
					};
					discreteInitIndex=0;
					memoryPointCamera="opticView";
					modelOptics[]=
					{
						"\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_F",
						"\3AS\3AS_Weapons\Republic\ACC\3AS_reticle_VK38X_Z_F"
					};
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					cameraDir="";
				};
			};
		};
		inertia=0.2;
	};
	class 3AS_Valken38X_F;
	class FST_Valken38x: 3AS_Valken38X_F
	{
		author="Gold";
		displayName="[41st] Valken-38X rifle";
		baseWeapon="FST_Valken38x";
		descriptionShort="Multi-Role Elite Rifle.";
		model="\3AS\3AS_Weapons\Republic\Valken38X\3AS_Valken38X_F.p3d";
		picture="\3AS\3AS_Weapons\Republic\Valken38X\Data\UI\3as_valken38x.paa";
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
			dispersion=0.00145;
			minRange=60;
			minRangeProbab=1;
			midRange=300;
			midRangeProbab=0.85;
			maxRange=10000;
			maxRangeProbab=0.05;
			aiRateOfFire=4;
			aiRateOfFireDistance=1;
			aiRateOfFireDispersion=3;
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
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0;
			midRange=100;
			midRangeProbab=0;
			maxRange=10000;
			maxRangeProbab=0;
		};
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\Indecisive_Armoury_Weapons_REPUBLIC\Data\LowPower_Scope\IDA_LowPower_Scope_Blue.p3d";
		class OpticsModes
		{
			class FST_Valken_Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=3; //1.25
				opticsZoomInit=0.75;
				discreteDistance[]={};
				discreteDistanceInitIndex=0;
				discreteInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="";
			};
			class FST_Valken_Scope
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={};
				discreteDistanceInitIndex=0;
				discreteInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_optic_VK38X_1",
					"FST_optic_VK38X_2"
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
		class LinkedItems{};
	};
};
