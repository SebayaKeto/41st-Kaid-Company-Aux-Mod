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
			"FST_E5S",
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
	class IDA_stun_muzzle;
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
	class FST_E5: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		baseWeapon="FST_E5";
		displayName="[41st] E-5 carbine";
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
		ace_clearJamAction="";
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
			"FST_blaster_cell_Red",
			"FST_blaster_cell_Blue",
			"FST_blaster_cell_Green",
			"FST_blaster_cell_Yellow"
		};
		magazineWell[]={};
		modes[]=
		{
			"Single",
			"FullAuto"
		};
		fireLightDiffuse[]={1,0,0};
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
			reloadTime=0.2;
			dispersion=0.00120000003;
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
			reloadTime=0.2;
			dispersion=0.00120000003;
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
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
	class FST_E5C_Stock: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Adapted from the Indecisive Armoury Team";
		scope=2;
		baseWeapon="FST_E5C_stock";
		canShootInWater=1;
		displayName="[41st] E-5C Rifle";
		descriptionShort="Long range, slow rate of fire.";
		picture="\MRC\JLTS\weapons\e5c\data\ui\e5c_ui_ca.paa";
		model="\MRC\JLTS\weapons\e5c\e5c_stock.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\e5c\anims\e5c_stock_handanim.rtm"
		};
		inertia=0.69999999;
		hiddenSelections[]=
		{
			"camo1",
			"illum"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\e5c\data\e5c_co.paa"
		};
		hiddenSelectionsMaterials[]=
		{
			"",
			"\a3\characters_f_bootcamp\common\data\vrarmoremmisive.rvmat"
		};
		ace_clearJamAction="";
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
			"FST_blaster_battery_Red",
			"FST_blaster_battery_Blue",
			"FST_blaster_battery_Green",
			"FST_blaster_battery_Yellow"
		};
		magazineWell[]={};
		modes[]=
		{
			"FullAuto"
		};
		fireLightDiffuse[]={1,0,0};
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
	class FST_E5S: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		displayName="[41st] E-5S sniper rifle";
		descriptionShort="Extreme range, high power.";
		picture="\MRC\JLTS\weapons\E5S\data\ui\E5S_ui_ca.paa";
		model="\MRC\JLTS\weapons\E5S\E5S.p3d";
		baseWeapon="FST_E5S";
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"\MRC\JLTS\weapons\E5S\data\E5S_co.paa"
		};
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"\MRC\JLTS\weapons\E5S\anims\E5S_handanim.rtm"
		};
		magazines[]=
		{
			"FST_blaster_cell_overcharged_Red",
			"FST_blaster_cell_Overcharged_Blue",
			"FST_blaster_cell_Overcharged_Green",
			"FST_blaster_cell_Overcharged_Yellow"
		};
		magazineWell[]={};
		ace_clearJamAction="";
		reloadAction="";
		reloadMagazineSound[]=
		{
			"\Indecisive_Armoury_Sounds\blaster_reload_3.ogg",
			1.5,
			1,
			100
		};
		recoil="FST_recoil_DC15X";
		muzzles[]=
		{
			"this"
		};
		modes[]=
		{
			"Single"
		};
		fireLightDiffuse[]={1,0,0};
		drySound[]=
		{
			"\Indecisive_Armoury_Sounds\weapon_dry.ogg",
			5,
			1,
			10
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
					2.5,
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
			minRange=2;
			minRangeProbab=0.5;
			midRange=100;
			midRangeProbab=0.69999999;
			maxRange=10000;
			maxRangeProbab=0.30000001;
		};
		modelOptics="\MRC\JLTS\weapons\E5S\E5S_reticle.p3d";
		class OpticsModes
		{
			class Snip
			{
				cameraDir="";
				discreteDistance[]={100};
				discreteDistanceInitIndex=0;
				discretefov[]={0.045000002,0.011};
				discreteInitIndex=0;
				distanceZoomMax=2400;
				distanceZoomMin=300;
				memoryPointCamera="opticView";
				modelOptics[]=
				{
					"\MRC\JLTS\weapons\E5S\E5S_reticle.p3d"
				};
				opticsDisablePeripherialVision=1;
				opticsDisplayName="WFOV";
				opticsFlare=1;
				opticsID=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera1",
					"OpticsBlur1"
				};
				opticsZoomInit=0.045000002;
				opticsZoomMax=0.045000002;
				opticsZoomMin=0.011;
				useModelOptics=1;
				visionMode[]=
				{
					"Normal",
					"NVG",
					"TI"
				};
			};
			class Iron: Snip
			{
				opticsID=2;
				useModelOptics=0;
				opticsPPEffects[]=
				{
					"",
					""
				};
				opticsFlare=0;
				opticsDisablePeripherialVision=0;
				discreteDistance[]={200};
				discreteDistanceInitIndex=0;
				opticsZoomMin=0.25;
				opticsZoomMax=1.25;
				opticsZoomInit=0.75;
				memoryPointCamera="eye";
				visionMode[]={};
			};
		};
		class WeaponSlotsInfo: WeaponSlotsInfo
		{
			mass=120;
			class CowsSlot: CowsSlot
			{
				compatibleItems[]={};
				iconPicture="";
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
	class FST_WristBlaster: arifle_MX_Base_F
	{
		ace_overheating_mrbs=40000;
		ace_overheating_slowdownFactor=0;
		ace_overheating_allowSwapBarrel=0;
		ace_overheating_dispersion=1;
		ace_overheating_closedBolt=0;
		ace_overheating_barrelMass=1;
		author="Indecisive Armoury Team";
		scope=2;
		inertia=0;
		canShootInWater=1;
		baseWeapon="FST_WristBlaster";
		displayName="[41st] Dual Wrist Blaster";
		descriptionShort="B2 Super Battledroid's Wrist Blaster.";
		picture="\MRC\JLTS\weapons\DC15A\data\ui\DC15A_plastic_ui_ca.paa";
		model="3AS\3AS_Weapons\DWBlaster\3AS_DWBlaster_F.p3d";
		handAnim[]=
		{
			"OFP2_ManSkeleton",
			"3AS\3AS_Weapons\DWBlaster\Data\Anim\DualWrist_handanim.rtm"
		};
		ace_clearJamAction="";
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
			"FST_blaster_battery_Red",
			"FST_blaster_battery_Blue",
			"FST_blaster_battery_Green",
			"FST_blaster_battery_Yellow"
		};
		magazineWell[]={};
		modes[]=
		{
			"FullAuto"
		};
		fireLightDiffuse[]={1,0,0};
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
				"IDA_wrist_rocket"
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
				dispersion=0;
				minRange=2;
				minRangeProbab=0.5;
				midRange=100;
				midRangeProbab=0.69999999;
				maxRange=10000;
				maxRangeProbab=0.30000001;
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
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
					1,
					1,
					1800
				};
				begin2[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
					1,
					1.015,
					1800
				};
				begin3[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
					1,
					0.98500001,
					1800
				};
				begin4[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
					1,
					1.01,
					1800
				};
				begin5[]=
				{
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
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
					"\Indecisive_Armoury_Sounds\CIS\WristBlaster\WristBlaster.wss",
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
};
