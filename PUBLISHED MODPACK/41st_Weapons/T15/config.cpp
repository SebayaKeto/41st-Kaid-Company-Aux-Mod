class CfgPatches
{
	class FST_T15_AT
	{
		author="Daara";
		requiredAddons[]=
		{
			"A3_weapons_F",
		};
		units[]={};
		weapons[]=
		{
			"FST_T15"
		};
	};
};	
class Mode_SemiAuto;
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class CfgWeapons
{
	class WeaponSlotsInfo;
	class Rifle_Base_F;
	class arifle_MX_Base_F: Rifle_Base_F
	{
		class GunParticles;
		class GunClouds;
		class WeaponSlotsInfo;
	};
	class UGL_F;
	class IDA_T15;
	class FST_T15: IDA_T15
	{
		author="Gold";
		displayName="[41st] T-15 Heavy Blaster";
		descriptionShort="Long range dedicated anti-material blaster.";
		picture="\MRC\JLTS\weapons\EPL2\data\ui\EPL2_ui_ca.paa";
		model="\MRC\JLTS\weapons\EPL2\EPL2.p3d";
		hiddenSelections[]= 
		{
			"camo1",
			"camo2"
		};
		hiddenSelectionsTextures[]= 
		{
			"\MRC\JLTS\weapons\EPL2\data\EPL2_co.paa",
			"\MRC\JLTS\weapons\EPL2\data\EPL2_mag_co.paa"
		};
		reloadAction="GestureReloadSPARUGL";
		reloadMagazineSound[]= 
		{
			"\41st_Weapons\DC-15AS\Data\reload.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_T15";
		magazines[]= 
		{
			"FST_thermal_coil_LP_Blue",
			"FST_thermal_coil_LP_Green",
			"FST_thermal_coil_LP_Yellow",
			"FST_thermal_coil_LP_Red"
		};
		magazineWell[]={};
		muzzles[]= 
		{
			"this",
			"FST_T15_UGL"
		};
		modes[]= 
		{
			"Single"
		};
		class Single: Mode_SemiAuto 
		{
			displayName = "Low Power";
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
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1,
					1,
					1800
				};
				begin2[]= 
				{
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					1.015,
					1800
				};
				begin3[]= 
				{
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					0.98500001,
					1800
				};
				begin4[]= 
				{
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
					1.25,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
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
					"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
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
			reloadTime=0.3;
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.7;
			maxRange=10000;
			maxRangeProbab=0.3;
		};
		class FST_T15_UGL: UGL_F 
		{
			displayName="High Power UGL";
			useModelOptics = false;
			useExternalOptic = true;
			magazines[] =
			{
				"FST_thermal_coil_T15_Blue",
				"FST_thermal_coil_T15_Green",
				"FST_thermal_coil_T15_Yellow",
				"FST_thermal_coil_T15_Red",
			/*	"FST_thermal_coil_Nexu_Blue",
				"FST_thermal_coil_Nexu_Green",
				"FST_thermal_coil_Nexu_Yellow",
				"FST_thermal_coil_Nexu_Red"		*/
			};
			cameraDir = "OP_look";
			discreteDistance[] = {100, 200, 300};
			discreteDistanceCameraPoint[] = {"OP_eye", "OP_eye2", "OP_eye3"}; // Position of the camera
			discreteDistanceInitIndex = 0;
			
			class Single: Mode_SemiAuto 
			{
				sounds[]= 
				{
					"StandardSound"
				};
				class BaseSoundModeType
				{
					weaponSoundEffect = "";
					closure1[] = {};
					closure2[] = {};
					soundClosure[] = {};
				};
				class StandardSound: BaseSoundModeType 
				{
					weaponSoundEffect = "";
					begin1[] = 
					{
						"\41st_Weapons\T15\Data\t15v1 2-177.ogg",
						1.25,
						1,
						1800
					};
					soundBegin[] = {"begin1", 1};
				};
				reloadTime = 0.5;
				dispersion = 0.002;
				minRange = 2;
				minRangeProbab = 0.5;
				midRange = 100;
				midRangeProbab = 0.7;
				maxRange = 300;
				maxRangeProbab = 0.3;
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo 
		{
            mass=80;
            class CowsSlot: CowsSlot 
			{
                compatibleItems[]= 
				{
                    "3AS_optic_holo_DC15S",
                    "Optic_MRCO",
                    "3AS_optic_reflex_DC15C"
                };
            };
            class MuzzleSlot: MuzzleSlot 
			{
                compatibleItems[]={};
            };
            class PointerSlot: PointerSlot 
			{
                compatibleItems[]= 
				{
                    "FST_Attachment_Light_Normal_White",
                    "FST_Attachment_Light_Beam_White",
                    "FST_Attachment_Module_Light_Normal_White",
                    "FST_Attachment_Module_Light_Beam_White",
                    "acc_pointer_IR"
                };
            };
            class UnderBarrelSlot: UnderBarrelSlot 
			{
                compatibleItems[]= 
				{
                    "3AS_Bipod_VK38X_F"
                };
            };
        };
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