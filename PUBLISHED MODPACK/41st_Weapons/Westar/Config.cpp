class CfgPatches
{
	class FST_Westar
	{
		author="Khaotic";
		name="41st Westar";
		requiredAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies",
			"JLTS_weapons_Grenades",
			"JLTS_weapons_Core",
			"JLTS_weapons_Reloads"
		};
		units[]={};
		weapons[]=
		{
			"FST_Scope_WM5",
			"FST_Westar_M5",
			"FST_Westar_M5_A",
			"FST_Westar_M5_S",
			"FST_Westar_M5_UGL",
		};
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class Single;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class InventoryMuzzleItem_Base_F;
class CfgWeapons
{
	class 3AS_Scope_Optics;
	class 41st_stun_muzzle;
	class NVGoggles;
	class InventoryOpticsItem_Base_F;
	class optic_lrps;
	class UGL_F;
	class ItemCore;
	class WeaponSlotsInfo;
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};

//Westar-M5 Rifle----------------------------------------------------------------------
	class FST_Scope_Westar_M5: ItemCore
	{
		scope=2;
		displayName="[41st] Westar-M5 Scope";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="\3AS\3AS_Weapons\WestarM5\3AS_Westar_Scope_F.p3d";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=7;
			modelOptics="\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
			class OpticsModes
			{
				class FST_Optic_Scope_WestarM5
				{
					opticsID=1;
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera1",
						"OpticFSTlur1"
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
				class FST_OverSights_Optic: 3AS_Scope_Optics
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
	class FST_Westar_M5 : arifle_MX_Base_F
	{
		JLTS_hasElectronics=1;
		JLTS_hasEMPProtection=0;
		JLTS_repairTime=5;
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		JLTS_canHaveShield=0;
		author="Khaotic";
		scope=2;
		intertia=0;
		canShootInWater=1;
		baseWeapon="FST_Westar-M5";
		displayName="[41st] Westar-M5 Rifle";	
		descriptionShort="Daara Only No Tallys or Majors Allowed";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		model="3AS\3AS_Weapons\WestarM5\3AS_Westar_M5_F.p3d";	
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\WestarM5\Data\Anim\WestarM5_handanim.rtm"
		};
		ace_clearJamAction="";
		reloadAction="3AS_GestureReload_DC17M";
		reloadMagazineSound[]=
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_DC15S";
		magazines[]=
		{
			"FST_blaster_cell_High_Blue",
			"FST_blaster_cell_High_Green",
			"FST_blaster_cell_High_Yellow",
			"FST_blaster_cell_High_Red",
			"FST_blaster_cell_Westar_Blue",
			"FST_blaster_cell_Westar_Green",
			"FST_blaster_cell_Westar_Yellow",
			"FST_blaster_cell_Westar_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"Burst",
			"FullAuto"
		};
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
			"this",
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
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (3).ogg",
					1.25,
					0.985,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.20,
					"begin2",
					0.20,
					"begin3",
					0.20,
					"begin4",
					0.20,
					"begin5",
					0.20,
				};
				beginwater1[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1,
				};
			};
			reloadTime=0.1;
			dispersion=0.00073000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class Burst: Mode_Burst
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
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (3).ogg",
					1.25,
					0.985,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.20,
					"begin2",
					0.20,
					"begin3",
					0.20,
					"begin4",
					0.20,
					"begin5",
					0.20,
				};
				beginwater1[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1,
				};
			};
			burst=3;
			reloadTime=0.0853;
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
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (3).ogg",
					1.25,
					0.985,
					1800
				};
				begin4[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (1).ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1.25,
					0.995,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					0.20,
					"begin2",
					0.20,
					"begin3",
					0.20,
					"begin4",
					0.20,
					"begin5",
					0.20,
				};
				beginwater1[]=
				{
					"\41st_weapons\Westar\Sounds\westar 2-177 (2).ogg",
					1,
					1,
					400
				};
				soundBeginWater[]=
				{
					"beginwater1",
					1,
				};
			};
			reloadTime = 0.1143;
			dispersion=0.0024;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		class FST_WestarM5_GL_F: UGL_F
		{
			displayName="[41st] WestarM5-GL";
			descriptionShort="GL for the WestarM5 Platform";
			useModelOptics=0;
			useExternalOptic=0;
			magazines[]=
			{
				"FST_HE_LauncherGrenade",
				"IDA_Smoke_LauncherGrenade",
				"IDA_SmokeRed_LauncherGrenade",
				"IDA_SmokeGreen_LauncherGrenade",
				"IDA_SmokeBlue_LauncherGrenade",
				"IDA_SmokePurple_LauncherGrenade",
				"ACE_40mm_Flare_Red",
				"ACE_40mm_Flare_White",
				"ACE_HuntIR_M203",
			};
			magazineWell[]={};
			cameraDir="OP_look";
			discreteDistance[]={50,75,100,150,200,250,300,350,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye_50",
				"OP_eye_75",
				"OP_eye_100",
				"OP_eye_150",
				"OP_eye_200",
				"OP_eye_250",
				"OP_eye_300",
				"OP_eye_350",
				"OP_eye_400"
			};
			discreteDistanceInitIndex=1;
			reloadAction="GestureReloadMXUGL";
			reloadMagazineSound[]=
			{
				"A3\Sounds_F\arsenal\weapons\Rifles\MX\Mx_UGL_reload",
				1,
				1,
				10
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Scope_Westar_M5",
					"3AS_optic_holo_DC15S",
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"41st_bayonet",
				};
			};
			class PointerSlot: PointerSlot
			{
				compatibleItems[]={};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
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
	class FST_Westar_M5_A: FST_Westar_M5
	{
		author="Gold";
		scope=2;
		displayName="[41st] Westar-M5A Rifle";
		model="SWLW_merc_mando\rifles\westar35S\westar35s.p3d";
		baseWeapon="FST_Westar_M5_A";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_epa\LongRangeRifles\DMR_01\Data\Anim\dmr_01.rtm"
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=130;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"SWLW_Westar35S_scope"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"SWLW_Westar35S_suppressor"
				};
			};
		};
	};	
	class FST_Westar_M5_S : FST_Westar_M5
	{
		author="Gold";
		scope=2;
		displayName="[41st] Westar-M5S Rifle";
		model="SWLW_merc_mando\rifles\westar35S\westar35s.p3d";
		baseWeapon="FST_Westar_M5_S";
		muzzles[]=
		{
			"this",
			"Scatter"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\A3\Weapons_F_epa\LongRangeRifles\DMR_01\Data\Anim\dmr_01.rtm"
		};
		class Scatter: UGL_F
		{
			displayName="Scattergun mode";
			descriptionShort="41st MASS";
			cursor="";
			scope=2;
			useModelOptics=0;
			useExternalOptic=1;
			cameraDir="eye";
			memoryPointCamera="";
			discreteDistance[]={100};
			discreteDistanceCameraPoint[]=
			{
				"eye"
			};
			discreteDistanceInitIndex=0;
			initSpeed=-1;
			muzzleEnd="shotgun pos";
			muzzlePos="shotgun dir";
			magazines[]=
			{
				"FST_underbarrel_scatter_cell_Blue",
				"FST_underbarrel_scatter_cell_Green",
				"FST_underbarrel_scatter_cell_Yellow",
				"FST_underbarrel_scatter_cell_Red"
			};
			reloadMagazineSound[]=
			{
				"\SWLW_main\sounds\scatter_reload",
				0.56234133,
				1,
				30
			};
			recoil="FST_recoil_DP23";
			reloadAction="GestureReloadMk20UGL";
			magazineWell[]={};
			class Single: Mode_SemiAuto
			{
				sounds[]=
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					closure1[]=
					{
						"A3\Sounds_F\arsenal\weapons\UGL\Closure_UGL",
						1,
						1,
						10
					};
					soundClosure[]=
					{
						"closure1",
						1
					};
				};
				class StandardSound: BaseSoundModeType
				{
					begin1[]=
					{
						"\SWLW_main\sounds\scatter",
						0.70794576,
						1,
						200
					};
					begin2[]=
					{
						"\SWLW_main\sounds\scatter",
						0.70794576,
						1,
						200
					};
					soundBegin[]=
					{
						"begin1",
						0.5,
						"begin2",
						0.5
					};
				};
				minRange=30;
				minRangeProbab=0.1;
				midRange=200;
				midRangeProbab=0.69999999;
				maxRange=400;
				maxRangeProbab=0.050000001;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=130;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"SWLW_Westar35S_scope"
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"SWLW_Westar35S_suppressor"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";  //\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL
				compatibleItems[]=
				{
				    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White"
				};	
			};
		};
	};	
	class FST_Westar_M5_UGL: FST_Westar_M5
	{
		scope=2;
		displayName="[41st] Westar-M5 Rifle UGL";
		model="3AS\3AS_Weapons\WestarM5\3AS_Westar_M5_GL.p3d";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		weaponInfoType="RscWeaponZeroing";
		modelOptics="3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
		muzzles[]=
		{
			"this",
			"FST_WestarM5_GL_F"
		};
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticFSTlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.375;
				opticsZoomMax=1.1;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
				distanceZoomMin=100;
				distanceZoomMax=100;
			};
			class Scope: Ironsights
			{
				opticsID=2;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera5",
					"OpticFSTlur5"
				};
				opticsDisablePeripherialVision=0.67000002;
				opticsZoomMin=0.122173;
				opticsZoomMax=0.122173;
				opticsZoomInit=0.122173;
				memoryPointCamera="opticView";
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				opticsFlare=1;
				distanceZoomMin=100;
				distanceZoomMax=100;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			class CowsSlot: CowsSlot
			{
				compatibleItems[]=
				{
					"FST_Scope_Westar_M5",
					"3AS_optic_holo_DC15S",
				};
			};
			class MuzzleSlot: MuzzleSlot
			{
				compatibleItems[]=
				{
					"41st_bayonet",
				};
			};
			mass=80;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=0.75;
	};
	class SWLW_Westar35S_suppressor: ItemCore
	{
		scope=1;
		author="SW Legion Studios";
		displayName="Westar-35S flash suppressor";
		picture="\SWLW_merc_mando\rifles\westar35s\data\ui\swlw_westar35s_suppressor_ui.paa";
		model="SWLW_merc_mando\rifles\westar35s\westar35s_suppressor.p3d";
		class ItemInfo: InventoryMuzzleItem_Base_F
		{
			mass=8;
			muzzleEnd="zaslehPoint";
			alternativeFire="Zasleh2";
		};
	};
};