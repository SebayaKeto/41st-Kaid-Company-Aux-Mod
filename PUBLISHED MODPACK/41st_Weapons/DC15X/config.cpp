class CfgPatches
{
	class FST_Weapons_DC15X
	{
		requiredAddons[]=
		{
			"3AS_Weapons",
			"IDA_Republic"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]=
		{
			"FST_DC15X"
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
	class WeaponSlotsInfo;
	class IDA_DC15X;
	class FST_DC15X: IDA_DC15X
	{
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Gold";
		displayName="[41st] DC-15X Sniper Rifle";
		scope=2;
		canShootInWater=1;
		model="Indecisive_Armoury_Weapons_REPUBLIC\Data\DC15X\Model\IDA_DC15X.p3d";
		baseWeapon="FST_DC15X";
		initSpeed=-1;
		magazines[]=
		{
			"FST_blaster_cell_Overcharged_Blue",
			"FST_blaster_cell_Overcharged_Green",
			"FST_blaster_cell_Overcharged_Yellow",
			"FST_blaster_cell_Overcharged_Red"
		};
		magazineWell[]={};
		recoil="FST_recoil_dc15x";
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Single"
		};
		maxZeroing = 2500;
		fireLightDiffuse[]={0,0,1};
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
					"\41st_Weapons\DC15X\Data\15x noecho.ogg",
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
					"\41st_Weapons\DC15X\Data\15x noecho.ogg",
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
			reloadTime=1;
			dispersion=9.9999997e-005;
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
		modelOptics="\A3\Weapons_F\acc\reticle_lrps_F";
		class OpticsModes
		{
			class FST_DC15X_Scope
			{
				opticsID=1;
				useModelOptics=1;
				opticsPPEffects[]=
				{
					"OpticsRadialBlur1",
					"OpticsBlur1"
				};
				opticsZoomMin=0.041999999;
				opticsZoomMax=0.125;
				opticsZoomInit=0.125;
				discreteDistance[]={200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500};
				discreteDistanceInitIndex=0;
				discreteInitIndex=0;
				discretefov[]={0.125,0.041999999};
				distanceZoomMin=100;
				distanceZoomMax=2500;
				memoryPointCamera="opticView";
				visionMode[]={};
				opticsFlare=1;
				opticsDisablePeripherialVision=1;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=120;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
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
                    "FST_Attachment_Module_Light_Beam_White"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]=
				{
					"bipod_01_F_blk"
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
