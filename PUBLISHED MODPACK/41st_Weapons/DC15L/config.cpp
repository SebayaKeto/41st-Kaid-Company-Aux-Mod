class CfgPatches
{
	class FST_Weapons_DC15L
	{
		requiredAddons[]=
		{
			"3AS_Weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15L_F",
			"FST_Optic_DC15L",
			"FST_Bipod_DC15L_f"
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
	class Rifle;
	class Rifle_Base_F: Rifle
	{
		class WeaponSlotsInfo;
		class GunParticles;
	};
	class FST_DC15L_Base_F: Rifle_Base_F {
		author="Daara";
		magazines[] = {
			"FST_blaster_battery_DC15L_Blue",
			"FST_blaster_battery_DC15L_Green",
			"FST_blaster_battery_DC15L_Yellow",
			"FST_blaster_battery_DC15L_Red",
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow",
			"FST_blaster_cell_Red",
		};
		magazineWell[]={};
		reloadAction="GestureReloadMX";
		magazineReloadSwitchPhase=0.40000001;
		discreteDistanceInitIndex=0;
		recoil="IDA_recoil_dc15a";
		initSpeed=-1;
		maxZeroing=100;
		class GunParticles: GunParticles {
			class SecondEffect {
				positionName="Nabojnicestart";
				directionName="Nabojniceend";
				effectName="CaselessAmmoCloud";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo {
			class CowsSlot: CowsSlot {
				linkProxy="\A3\data_f\proxies\weapon_slots\TOP";
				compatibleItems[] = {
					"FST_Optic_DC15L",
				};
			};
			class PointerSlot: PointerSlot {
				linkProxy="\A3\data_f\proxies\weapon_slots\SIDE";
				compatibleItems[] = {
					"FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White",
					"acc_pointer_IR"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot {
				linkProxy="\A3\data_f_mark\proxies\weapon_slots\UNDERBARREL";
				compatibleItems[] = {
					"FST_Bipod_DC15L_f"
				};
			};
		};
		opticsZoomMin=0.25;
		opticsZoomMax=1.25;
		opticsZoomInit=0.75;
		distanceZoomMin=400;
		distanceZoomMax=400;
		descriptionShort="DC-15L, 41st Variant";
		handAnim[] = {
			"OFP2_ManSkeleton",
			"\3AS\3AS_Weapons\DC15L\Data\Anim\DC15L_handanim.rtm"
		};
		selectionFireAnim="zasleh";
		flash="gunfire";
		flashSize=3;
		modes[] = {
			"FullAuto",
			"SlowAuto"
		};
		
		class FullAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType {
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType {
				weaponSoundEffect="";
				begin1[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin2[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin5[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				soundBegin[] = {
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
				beginwater1[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1,
					1,
					400
				};
				soundBeginWater[] = {
					"beginwater1",
					1
				};
			};
            reloadTime=0.1;  // 600 RPM
            textureType = "fastAuto"; //Faster Icon for fire type
            dispersion=0.0011;
            minRange=2;
            minRangeProbab=0.5;
            midRange=100;
            midRangeProbab=0.69999999;
            maxRange=10000;
            maxRangeProbab=0.30000001;
            displayNameShort = "Full Auto";
		};

		class SlowAuto: Mode_FullAuto {
			sounds[] = {
				"StandardSound"
			};
			class BaseSoundModeType {
				weaponSoundEffect="";
				closure1[]={};
				closure2[]={};
				soundClosure[]={};
			};
			class StandardSound: BaseSoundModeType {
				weaponSoundEffect="";
				begin1[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin2[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				begin3[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (2).ogg",
					1.5,
					1,
					1800
				};
				begin4[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1.5,
					1,
					1800
				};
				begin5[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326 (1).ogg",
					1.5,
					1,
					1800
				};
				soundBegin[] = {
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
				beginwater1[] = {
					"\41st_Weapons\DC15L\Data\dc15lv1 2-326.ogg",
					1,
					1,
					400
				};
				soundBeginWater[] = {
					"beginwater1",
					1
				};
			};
            reloadTime=0.171;  // 350 RPM
            textureType = "fullAuto"; //Faster Icon for fire type
            dispersion=0.0011;
            minRange=2;
            minRangeProbab=0.5;
            midRange=100;
            midRangeProbab=0.69999999;
            maxRange=10000;
            maxRangeProbab=0.30000001;
            displayNameShort = "Slow Auto";
		};

		aiDispersionCoefY=10;
		aiDispersionCoefX=8;
		caseless[] = {
			"",
			1,
			1,
			1
		};
		soundBullet[] = {
			"caseless",
			1
		};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
		};
		reloadMagazineSound[] = {
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
	};
	class FST_DC15L_F: FST_DC15L_Base_F
	{
		scope=2;
		displayName="[41st] DC-15L Rifle";
		model="3AS\3AS_Weapons\DC15L\3AS_DC15L_f.p3d";
		picture="\3AS\3AS_Weapons\DC15A\Data\Textures\DC15A_Arsenal.paa";
		weaponInfoType="RscWeaponZeroing";
		class OpticsModes
		{
			class Ironsights
			{
				opticsID=1;
				useModelOptics=0;
				opticsFlare="true";
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
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=60;
		};
		ace_overheating_mrbs=3000;
		ace_overheating_slowdownFactor=1;
		ace_overheating_allowSwapBarrel=1;
		ace_overheating_dispersion=0.75;
	};
	class ItemCore;
	class InventoryOpticsItem_Base_F;
	class FST_Optic_DC15L: ItemCore
	{
		scope=2;
		displayName="[41st] DC15L Optic";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="3AS\3AS_Weapons\DC15L\3AS_DC15L_Scope_f.p3d";
		weaponInfoType="RscWeaponZeroing";
		class ItemInfo: InventoryOpticsItem_Base_F
		{
			mass=7;
			modelOptics="\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d";
			class OpticsModes
			{
				class FST_DC15L_Optic
				{
					opticsID=1;
					useModelOptics=1;
					opticsPPEffects[]=
					{
						"OpticsCHAbera1",
						"OpticFSTlur1"
					};
					opticsZoomMin=0.055500001;
					opticsZoomMax=0.13;
					opticsZoomInit=0.13;
					discreteDistance[]={100,300,400,500,600,700,800,900,1000};
					discreteDistanceInitIndex=1;
					distanceZoomMin=100;
					distanceZoomMax=1000;
					nFovLimit=0.07;
					discreteFov[]={0.25,0.25};
					discreteInitIndex=0;
					modelOptics[]=
					{
						"\3AS\3AS_Weapons\Data\3AS_2D_Optic.p3d"
					};
					memoryPointCamera="opticView";
					visionMode[]=
					{
						"Normal",
						"NVG"
					};
					opticsFlare=1;
					opticsDisablePeripherialVision=1;
					cameraDir="";
				};
				class IronOnTopOfMyOptics: FST_DC15L_Optic
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
	class InventoryUnderItem_Base_F;
	class FST_Bipod_DC15L_f: ItemCore
	{
		scope=2;
		displayName="[41st] DC15L Bipod";
		picture="\3AS\3AS_Weapons\Data\Textures\Energy_Cell_Arsenal.paa";
		model="3AS\3AS_Weapons\DC15L\3AS_DC15L_Bipod.p3d";
		class ItemInfo: InventoryUnderItem_Base_F
		{
			deployedPivot="bipod";
			haFSTipod=1;
			mass=10;
			soundBipodDown[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_down",
				"db-3",
				1,
				20
			};
			soundBipodUp[]=
			{
				"A3\Sounds_F_Mark\arsenal\sfx\bipods\Bipod_AAF_up",
				"db-3",
				1,
				20
			};
		};
		inertia=0.2;
	};
	class acc_flashlight;
	class FST_Base_Flashlight: acc_flashlight
	{
		scope = 0; // Base class, not to be used directly
		class Iteminfo
		{
			allowedSlots[] = {801,701,901};
			mass = 4;
			mountAction = "MountSide";
			type = 301;
			unmountAction = "DismountSide";
			class Flashlight
			{
				ambient[] = {0.9,0.81,0.7};
				color[] = {180,160,130};
				dayLight = 0;
				direction = "flash";
				useFlare = 1;
				volumeShape = "a3\\data_f\\VolumeLightFlashlight.p3d";
			};
		};
	};
	class FST_Attachment_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
				class Attenuation
				{
					constant = 0.5;
					hardLimitEnd = 60;
					hardLimitStart = 27;
					linear = 0.1;
					quadratic = 0.2;
					start = 0;
				};
			};
		};
	};
	class FST_Attachment_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Beam)";
		scope = 2;
		scopeArsenal = 2;
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
				class Attenuation
				{
					constant = 0.2;
					hardLimitEnd = 540;
					hardLimitStart = 27;
					linear = 0.2;
					quadratic = 0.2;
					start = 20;
				};
			};
		};
	};
	class FST_Attachment_Module_Light_Normal_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light (Normal/Beam)";
		scope = 2;
		scopeArsenal = 2;
		MRT_switchItemHintText = "White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Beam_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Beam_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				ACE_Flashlight_Beam = "\\z\\ace\\addons\\map\\UI\\Flashlight_beam_white_ca.paa";
				ACE_Flashlight_Colour = "white";
				ACE_Flashlight_Size = 2.75;
				ACE_Flashlight_Sound = 1;
				coneFadeCoef = 8;
				flareMaxDistance = 150;
				flareSize = 1.6;
				innerAngle = 5;
				intensity = 140;
				outerAngle = 100;
				scale[] = {1,1,1};
				size = 1.2;
				class Attenuation
				{
					constant = 0.5;
					hardLimitEnd = 60;
					hardLimitStart = 27;
					linear = 0.1;
					quadratic = 0.2;
					start = 0;
				};
			};
		};
	};
	class FST_Attachment_Module_Light_Beam_White: FST_Base_Flashlight
	{
		displayName = "[41st] Light/Laser Module";
		scope = 1;
		scopeArsenal = 0;
		MRT_switchItemHintText = "Beam White Light";
		MRT_SwitchItemNextClass = "FST_Attachment_Module_Light_Normal_White";
		MRT_SwitchItemPrevClass = "FST_Attachment_Module_Light_Normal_White";
		class Iteminfo: Iteminfo
		{
			class Flashlight: Flashlight
			{
				coneFadeCoef = 30;
				flareMaxDistance = 500;
				flareSize = 4;
				innerAngle = 8;
				intensity = 140;
				outerAngle = 25;
				scale[] = {1,1,1};
				size = 1;
				class Attenuation
				{
					constant = 0.2;
					hardLimitEnd = 540;
					hardLimitStart = 27;
					linear = 0.2;
					quadratic = 0.2;
					start = 20;
				};
			};
		};
	};
};
