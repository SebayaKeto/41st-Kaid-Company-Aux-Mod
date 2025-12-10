class CfgPatches
{
	class FST_IDA_CIS
	{
		author="Adapted from the Indecisive Armoury Team";
		name="41st IDA CIS Weapons";
		requiRedAddons[]=
		{
			"A3_data_F",
			"A3_anims_F",
			"A3_weapons_F",
			"A3_characters_F",
			"A3_Characters_F_Proxies"
		};
		units[]={};
		weapons[]=
		{
			"FST_E5",
			"FST_E5C_Stock",
			"FST_E5S"
		};
		magazines[]={};
	};
};
class CowsSlot;
class UnderBarrelSlot;
class MuzzleSlot;
class PointerSlot;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class CfgWeapons
{
	class UGL_F;
	class WeaponSlotsInfo;
	class IDA_E5;
	class FST_E5: IDA_E5
	{
		author="Gold";
		displayName="[41st] E-5 carbine";
		baseWeapon="FST_E5";
		descriptionShort="Close range, fast rate of fire.";
		picture="\MRC\JLTS\weapons\E5\data\ui\E5_ui_ca.paa";
		model="\MRC\JLTS\weapons\E5\E5.p3d";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\E5\data\E5_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\E5\anims\E5_handanim.rtm"
		};
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_3.ogg",
			1.5,
			1,
			100
		};
		recoil="recoil_spar";
		magazines[]=
		{
			"FST_Droid_blaster_cell_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
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
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1,
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
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
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
			reloadTime=0.5;
			dispersion=0.00095;
			minRange=75;
			minRangeProbab=0.6;
			midRange=200;
			midRangeProbab=0.5;
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
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1.75,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1.75,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1.75,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1.75,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
					1.75,
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
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
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
			reloadTime=0.15;
			dispersion=0.0055;
			minRange=1;
			minRangeProbab=0.7;
			midRange=50;
			midRangeProbab=0.69999999;
			maxRange=100;
			maxRangeProbab=0.30000001;
		};
		distanceZoomMin=400;
		distanceZoomMax=400;
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\Indecisive_Armoury_Weapons_Imperial\Data\LowPower_Scope\IDA_LowPower_Scope_Red.p3d";
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class E5_Scope
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
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=50;
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
					"acc_flashlight",
					"acc_pointer_IR"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
	class IDA_E5C;
	class FST_E5C_Stock: IDA_E5C
	{
		author="Gold";
		displayName="[41st] E-5C Rifle";
		baseWeapon="FST_E5C_stock";
		descriptionShort="Long range, slow rate of fire.";
		inertia=0.69999999;
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_3.ogg",
			1.5,
			1,
			100
		};
		recoil="recoil_spar";
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"FullAuto"
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
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
					1.75,
					1,
					1800
				};
				begin2[]=
				{
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
					1.75,
					1.015,
					1800
				};
				begin3[]=
				{
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
					1.75,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
					1.75,
					1.01,
					1800
				};
				begin5[]=
				{
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
					1.75,
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
					"\41st_Weapons\CIS\Data\E5c 1-008.ogg",
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
			reloadTime=0.2;
			dispersion=0.00170000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=0.2;
			aiRateOfFireDistance=300;
		};
		distanceZoomMin=400;
		distanceZoomMax=400;
		weaponInfoType="RscOptics_nightstalker";
		modelOptics="\Indecisive_Armoury_Weapons_Imperial\Data\LowPower_Scope\IDA_LowPower_Scope_Red.p3d";
		class OpticsModes
		{
			class Iron
			{
				opticsID=1;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
			};
			class E5_Scope
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
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				distanceZoomMin=200;
				distanceZoomMax=200;
				memoryPointCamera="eye";
				visionMode[]={};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				cameraDir="";
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=80;
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
					"acc_flashlight"
				};
			};
			class UnderBarrelSlot: UnderBarrelSlot
			{
				compatibleItems[]={};
			};
		};
	};
	class IDA_E5S;
	class FST_E5S: IDA_E5S
	{
		author="Gold";
		displayName="[41st] E-5S sniper rifle";
		baseWeapon="FST_E5S";
		descriptionShort="Extreme range, high power.";
		magazines[]=
		{
			"FST_Droid_blaster_cell_overcharged_Red"
		};
		magazineWell[]={};
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_3.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_DC15X";
		modes[]=
		{
			"Single"
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
					"MRC\JLTS\weapons\E5\sounds\E5_fire",
					1,
					0.89999998,
					1800
				};
				soundBegin[]=
				{
					"begin1",
					1
				};
				beginwater1[]=
				{
					"\41st_Weapons\CIS\Data\SW02_Weapons_Blasters_E5_Laser_Close_VAR_04 0 0 0.wav",
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
			reloadTime=0.2;
			dispersion=0.00010000003;
			minRange=1;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=4;
			aiRateOfFireDistance=1;
			aiRateOfFireDispersion=3;
		};
	};
	class IDA_WristBlaster;
	class FST_WristBlaster: IDA_WristBlaster
	{
		author="Gold";
		displayName="[41st] Dual Wrist Blaster";
		baseWeapon="FST_WristBlaster";
		descriptionShort="B2 Super Battledroid's Wrist Blaster.";
		recoil="recoil_spar";
		magazines[]=
		{
			"FST_Droid_blaster_battery_Red"
		};
		magazineWell[]={};
		modes[]=
		{
			"FullAuto"
		};
		muzzles[]=
		{
			"this",
			"EGLM"
		};
		class EGLM: UGL_F
		{
			displayName="[41st] Wrist Rocket";
			descriptionShort="Watch those wrist rockets!";
			useModelOptics=0;
			useExternalOptic=0;
			cameraDir="OP_look";
			fireLightDiffuse[]={1,0,0};
			discreteDistance[]={100,200,300,400};
			discreteDistanceCameraPoint[]=
			{
				"OP_eye",
				"OP_eye2",
				"OP_eye3",
				"OP_eye4"
			};
			discreteDistanceInitIndex=0;
			magazines[]=
			{
				"FST_HE_LauncherWristRocket"
			};
			modes[]=
			{
				"Fire"
			};
			magazineWell[]={};
			class Fire: Mode_SemiAuto
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
						"\Indecisive_Armoury_Sounds\CIS\Sounds\WristBlaster\WristRocket.wss",
						4,
						1,
						3000
					};
					soundBegin[]=
					{
						"begin1",
						1
					};
				};
				reloadTime=0.1;
				dispersion=0.00290;
				minRange=2;
				minRangeProbab=0.6;
				midRange=300;
				midRangeProbab=0.8;
				maxRange=600;
				maxRangeProbab=0.3;
				aiRateOfFire=5; 
			};
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
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
					1,
					1.015,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
					1,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
					1,
					1.01,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
					1,
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
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster.ogg",
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
			dispersion=0.00145;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
			aiRateOfFire=0.1; 
		};
	};
};
