class CfgPatches
{
	class FST_ATAP
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta"
		};
		units[]=
		{
			"FST_ATAP_Base",
		};
		weapons[]={};
		author="Daara Adapted from 3AS";
	};
};
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		ATAP_Commander="ATAP_Commander";
		ATAP_Gunner="ATAP_Gunner";
		ATAP_Gunner2="ATAP_Gunner2";
		ATAP_Driver="ATAP_Driver";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	skeletonName="OFP2_ManSkeleton";
	gestures="CfgGesturesMale";
	class States
	{
		class Crew;
		class ATAP_Commander: Crew
		{
			file="3AS\3AS_Anims\anims\ATAP_Commander.rtm";
			leftHandIKCurve[]={1};
			rightHandIKCurve[]={1};
		};
		class ATAP_Gunner: Crew
		{
			file="3AS\3AS_Anims\anims\ATAP_Gunner.rtm";
			leftHandIKCurve[]={1};
			rightHandIKCurve[]={1};
		};
		class ATAP_Gunner2: Crew
		{
			file="3AS\3AS_Anims\anims\ATAP_Gunner2.rtm";
			leftHandIKCurve[]={1};
			rightHandIKCurve[]={1};
		};
		class ATAP_Driver: Crew
		{
			file="3AS\3AS_Anims\anims\ATAP_Driver.rtm";
			leftHandIKCurve[]={1};
			rightHandIKCurve[]={1};
		};
	};
};
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics
{
	initAngleX=0;
	minAngleX=-30;
	maxAngleX=30;
	initAngleY=0;
	minAngleY=-100;
	maxAngleY=100;
	initFov=0.4375;
	minFov=0.034820002;
	maxFov=0.4375;
	visionMode[]=
	{
		"Normal",
		"NVG",
		"Ti"
	};
	thermalMode[]={0,1};
	minMoveX=0;
	maxMoveX=0;
	minMoveY=0;
	maxMoveY=0;
	minMoveZ=0;
	maxMoveZ=0;
};
class Optics_Armored;
class Optics_Commander_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Commander_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_MBT_03: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Mode_SemiAuto;
class CfgWeapons
{
	class CannonCore;
	class mortar_155mm_AMOS: CannonCore{};
	class FST_ATAP_mortar: mortar_155mm_AMOS
	{
		scope=2;
		displayName="Mass-Driver Mortar Cannon";
		nameSound="cannon";
		cursor="mortar";
		cursorAim="EmptyCursor";
			reloadTime=10;
		magazines[]=
		{
			"FST_32Rnd_155mm_ATAP_Mortar_shells",
/* 			"3AS_32Rnd_300mm_Mo_shells",
			"3AS_12Rnd_300mm_Mo_smoke",
			"3AS_4Rnd_300mm_Mo_guided",
			"3AS_4Rnd_300mm_Mo_LG",
			"3AS_12Rnd_300mm_Mo_mine",
			"3AS_4Rnd_300mm_Mo_Cluster",
			"3AS_12Rnd_300mm_Mo_AT_mine",
			"3AS_32Rnd_155mm_ATAP_Mortar_shells_AT" */
		};
		modes[] = {"Single1", "Single2", "Single3"};
		class Single1: Mode_SemiAuto {
			artilleryCharge = 0.19;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single10";
			maxRange = 500;
			minRange = 200;
			reloadTime=2;
			magazineReloadTime=10;
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_HeavyTurboLaser_SoundSet"
				};
			};
		};
		class Single2: Single1 {
			artilleryCharge = 0.3;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single20";
			maxRange = 2450;
		};
		class Single3: Single1 {
			artilleryCharge = 0.48;
			displayName = "$STR_A3_mortar_120mm_AMOS_Single30";
			maxRange = 3760;
		};
		class GunParticles
		{
		};
	};
	class 3AS_Mass_Driver_Cannon;
	class FST_ATAP_SIEGE_Cannon: 3AS_Mass_Driver_Cannon
	{
		scope=1;
		displayName="[41st] AT-AP Siege Cannon";
		cursor="EmptyCursor";
		cursorAim="cannon";
		showAimCursorInternal=0;
		nameSound="cannon";
		reloadSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		reloadMagazineSound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\cannon_120mm\Cannon_120mm_Reload_01",
			2.5118864,
			1,
			10
		};
		magazines[]=
		{
			"FST_10Rnd_SIEGE_Cannon_HHE_shells"
		};
		reloadTime=25;
		magazineReloadTime=30;
		autoReload=1;
		canLock=0;
		ballisticsComputer="2 + 8 + 16";
		FCSMaxLeadSpeed=250;
		FCSZeroingDelay=1;
		aiDispersionCoefY=2;
		aiDispersionCoefX=2;
		autoFire=0;
		class player: Mode_SemiAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType;
			class StandardSound: BaseSoundModeType
			{
				soundSetShot[]=
				{
					"3AS_HeavyTurboLaser_SoundSet"
				};
			};
			soundContinuous=0;
			reloadTime=20;
			magazineReloadTime=25;
			autoReload=1;
			autoFire=0;
			dispersion=0.00056999997;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_10Rnd_Siege_Cannon_HHE_shells: VehicleMagazine
	{
		author="Daara";
		scope=2;
		displayName="10 Round SIEGE Cannon Shells";
		displayNameShort="Mass Driver HHE Shells";
		ammo="FST_Siege_Cannon_HHE_Shell";
		count=10;
		displayNameMFDFormat="HHE";
		initSpeed=1680;
		maxLeadSpeed=250;
		tracersEvery=1;
		nameSound="cannon";
		muzzleImpulseFactor[]={0.5,3};
	};
	class 32Rnd_155mm_Mo_shells;
	class FST_32Rnd_155mm_ATAP_Mortar_shells: 32Rnd_155mm_Mo_shells
	{
		scope=2;
		displayName="155mm Depleted Durasteel";
		displayNameShort="HESH";
		displayNameMFDFormat="HESH";
		ammo="FST_ATAP_155mm_AMOS_Mortar_Ammo";
		count=32;
		initSpeed=400;
		nameSound="heat";
		muzzleImpulseFactor[]={0.5,0.5};
	};
};
class CfgAmmo
{
	class ShellBase;
	class FST_Siege_Cannon_HHE_Shell: ShellBase
	{
		aiAmmoUsageFlags="64 + 128 + 256 + 512";
		allowAgainstInfantry=1;
		hit=2500;
		indirectHit=200;
		indirectHitRange=30;
		warheadName="AP";
		dangerRadiusHit=160;
		suppressionRadiusHit=32;
		explosive=0.80000001;
		cost=300;
		artilleryLock=1;
		CraterEffects="HeavyBombCrater";
		explosionEffects="HeavyBombExplosion";
		typicalSpeed=1550;
		caliber=10;
		deflecting=0;
		timeToLive=15;
		whistleOnFire=1;
		whistleDist=14;
		model="\3AS\3AS_Weapons\Data\tracer_shell_blue";
		tracerScale=3;
		tracerStartTime=0;
		tracerEndTime=15;
		muzzleEffect="";
		effectFly="3AS_PlasmaBolt_Large_Blue_Fly";
		soundSetSonicCrack[]=
		{
			"3AS_Cannon_Flyby_SoundSet"
		};
		class CamShakeExplode
		{
			power=24;
			duration=2.5999999;
			frequency=20;
			distance=143.636;
		};
		class CamShakeHit
		{
			power=180;
			duration=0.80000001;
			frequency=20;
			distance=1;
		};
		class CamShakeFire
		{
			power=3.3097501;
			duration=2.2;
			frequency=20;
			distance=87.635597;
		};
		class CamShakePlayerFire
		{
			power=0.02;
			duration=0.1;
			frequency=20;
			distance=1;
		};
		ace_frag_enabled=1;
		ace_frag_metal=23000;
		ace_frag_charge=3148;
		ace_frag_gurney_c=2830;
		ace_frag_gurney_k="1/2";
		ace_frag_classes[]=
		{
			"ACE_frag_medium",
			"ACE_frag_medium_HD"
		};
	};
	class Sh_155mm_AMOS;
	class FST_ATAP_155mm_AMOS_Mortar_Ammo: Sh_155mm_AMOS
	{
		model="3as\3as_weapons\data\tracer_shell_blue";
		effectFly="3AS_PlasmaBolt_Medium_Blue_Fly";
		hit=640;
		indirectHit=95;
		indirectHitRange=6.25;
		warheadName="HESH";
		caliber=22;
		deflecting=5;
		cost=300;
		timeToLive=180;
		aiAmmoUsageFlags="64 + 128 + 256 + 512";
		CraterEffects="ArtyShellCrater";
		ExplosionEffects="MortarExplosion";
		suppressionRadiusHit=75;
		explosive=0.80000001;
		submunitionAmmo="3AS_ATAP_HE_Submunition";
		submunitionConeType[]=
		{
			"randomcenter",
			1
		};
		submunitionInitialOffset[]={0,0,0.2};
		submunitionInitSpeed=5;
	};
};
class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class Sounds;
		class Eventhandlers;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitHull;
			class HitLFWheel;
			class HitLBWheel;
			class HitLMWheel;
			class HitLF2Wheel;
			class HitRFWheel;
			class HitRBWheel;
			class HitRMWheel;
			class HitRF2Wheel;
		};
	};
	class Wheeled_APC_F: Car_F
	{
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
		class NewTurret;
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
	};
	class APC_Wheeled_01_base_F: Wheeled_APC_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class Turrets: Turrets
				{
					class CommanderOptics: CommanderOptics
					{
					};
				};
			};
		};
	};
	class FST_ATAP_Base: APC_Wheeled_01_base_F
	{
		destrType="DestructWreck";
		attenuationEffectType="TankAttenuation";
		soundGetIn[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1
		};
		soundGetOut[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234097,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234097,
			1
		};
		soundEngineOnInt[]=
		{
			"3AS\3as_ATTE\Sounds\attestart.ogg",
			2,
			1
		};
		soundEngineOnExt[]=
		{
			"3AS\3as_ATTE\Sounds\attestart.ogg",
			4,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"a3\sounds_f\vehicles\armor\apc\apc1\int_engine_stop.wss",
			2,
			1
		};
		soundEngineOffExt[]=
		{
			"a3\sounds_f\vehicles\armor\apc\apc1\int_engine_stop.wss",
			4,
			1,
			200
		};
		buildCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		soundBuildingCrash[]=
		{
			"buildCrash0",
			0.25,
			"buildCrash1",
			0.25,
			"buildCrash2",
			0.25,
			"buildCrash3",
			0.25
		};
		WoodCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		WoodCrash4[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_01",
			1,
			1,
			200
		};
		WoodCrash5[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.16599999,
			"woodCrash1",
			0.16599999,
			"woodCrash2",
			0.16599999,
			"woodCrash3",
			0.16599999,
			"woodCrash4",
			0.16599999,
			"woodCrash5",
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_08",
			1,
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_09",
			1,
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_10",
			1,
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\sounds_f\Vehicles\crashes\crash_11",
			1,
			1,
			200
		};
		soundArmorCrash[]=
		{
			"ArmorCrash0",
			0.25,
			"ArmorCrash1",
			0.25,
			"ArmorCrash2",
			0.25,
			"ArmorCrash3",
			0.25
		};
		class Sounds
		{
			class Idle_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					240
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					280
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					320
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					360
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					440
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					230
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					290
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1,
					450
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.41589,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(400/ 2640),(900/ 2640)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(100/ 2640),(200/ 2640)]) * ((rpm/ 2640) factor[(900/ 2640),(700/ 2640)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					1.58866,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(700/ 2640),(1100/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(705/ 2640),(850/ 2640)]) * ((rpm/ 2640) factor[(1100 / 2640),(950/ 2640)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(950/ 2640),(1400/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(900/ 2640),(1050/ 2640)]) * ((rpm/ 2640) factor[(1400/ 2640),(1200/ 2640)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					1.7825,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1200/ 2640),(1700/ 2640)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1170/ 2640),(1380/ 2640)]) * ((rpm/ 2640) factor[(1700/ 2640),(1500/ 2640)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1500/ 2640),(2100/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1500/ 2640),(1670/ 2640)]) * ((rpm/ 2640) factor[(2100/ 2640),(1800/ 2640)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2.24404,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(1800/ 2640),(2300/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2640) factor[(1780/ 2640),(2060/ 2640)]) * ((rpm/ 2640) factor[(2450/ 2640),(2200/ 2640)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"3AS\3as_ATAP\sounds\ATAPWalking.ogg",
					2.5178499,
					1
				};
				frequency="0.8 + ((rpm/ 2640) factor[(2100/ 2640),(2640/ 2640)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2640) factor[(2150/ 2640),(2500/ 2640)])";
			};
			class NoiseInt
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					0.50118703,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[]=
				{
					"3AS\3as_ATTE\Sounds\atteidle.ogg",
					0.89125103,
					1,
					50
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(speed factor[4, 15])";
			};
			class ThreadsOutH0
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					140
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutH1
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					160
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutH2
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					180
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutH3
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					200
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutH4
			{
				sound[]=
				{
					"",
					0.56234097,
					1,
					220
				};
				frequency="1";
				volume="engineOn*camPos*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsOutS0
			{
				sound[]=
				{
					"",
					0.316228,
					1,
					120
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsOutS1
			{
				sound[]=
				{
					"",
					0.35481301,
					1,
					140
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsOutS2
			{
				sound[]=
				{
					"",
					0.39810699,
					1,
					160
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsOutS3
			{
				sound[]=
				{
					"",
					0.446684,
					1,
					180
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsOutS4
			{
				sound[]=
				{
					"",
					0.50118703,
					1,
					200
				};
				frequency="1";
				volume="engineOn*(camPos)*(grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInH0
			{
				sound[]=
				{
					"",
					0.25118899,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInH1
			{
				sound[]=
				{
					"",
					0.281838,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInH2
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInH3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInH4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*(1-grass)*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
			class ThreadsInS0
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-0) max 0)/ 60),(((-5) max 5)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-15) max 15)/ 60),(((-10) max 10)/ 60)]))";
			};
			class ThreadsInS1
			{
				sound[]=
				{
					"",
					0.316228,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-10) max 10)/ 60),(((-15) max 15)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-30) max 30)/ 60),(((-25) max 25)/ 60)]))";
			};
			class ThreadsInS2
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-25) max 25)/ 60),(((-30) max 30)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-45) max 45)/ 60),(((-40) max 40)/ 60)]))";
			};
			class ThreadsInS3
			{
				sound[]=
				{
					"",
					0.35481301,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*(((((-speed*3.6) max speed*3.6)/ 60) factor[(((-40) max 40)/ 60),(((-45) max 45)/ 60)]) * ((((-speed*3.6) max speed*3.6)/ 60) factor[(((-55) max 55)/ 60),(((-50) max 50)/ 60)]))";
			};
			class ThreadsInS4
			{
				sound[]=
				{
					"",
					0.39810699,
					1
				};
				frequency="1";
				volume="engineOn*(1-camPos)*grass*((((-speed*3.6) max speed*3.6)/ 60) factor[(((-49) max 49)/ 60),(((-53) max 53)/ 60)])";
			};
		};
		simulation="carx";
		fuelCapacity=80;
		brakeIdleSpeed=1.78;
		maxSpeed=32;
		normalSpeedForwardCoef=1;
		slowSpeedForwardCoef=0.75;
		antiRollbarForceCoef=24;
		antiRollbarForceLimit=30;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=70;
		enginePower=13000;
		maxOmega=90;
		minOmega=50;
		idleRpm=700;
		redRpm=2640;
		peakTorque=400000;
		torqueCurve[]=
		{
			{0,1},
			{0.33000001,1},
			{1,0.80000001}
		};
		thrustDelay=0.0099999998;
		engineMOI=12;
		dampingRateFullThrottle=0.050000001;
		dampingRateZeroThrottleClutchEngaged=20;
		dampingRateZeroThrottleClutchDisengaged=10;
		maxFordingDepth=5;
		canFloat=0;
		waterPPInVehicle=0;
		waterResistanceCoef=0.07;
		waterLeakiness=25;
		waterSpeedFactor=0.5;
		waterAngularDampingCoef=5;
		waterLinearDampingCoefY=2;
		waterLinearDampingCoefX=0.5;
		waterResistance=1;
		clutchStrength=350;
		latency=0.1;
		switchTime=0;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-5,-14.5]]], [0], [0]]";
		changeGearType="rpmratio";
		changeGearOmegaRatios[]={1,0.33333334,0.33333334,0,0.99333334,0.33333334,0.98333335,0.69999999,0.98333335,0.73333335,0.98333335,0.73333335};
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-0.5,
				"N",
				0,
				"D1",
				8,
				"D2",
				7.75,
				"D3",
				6.5,
				"D4",
				4,
				"D5",
				3.5,
				"D6",
				2.75,
				"D7",
				2
			};
			transmissionRatios[]=
			{
				"High",
				1
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		damperSize=0.2;
		damperForce=1;
		damperDamping=0.0099999998;
		dampersBumpCoef=6;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=1.5;
		numberPhysicalWheels=8;
		class Wheels
		{
			class L1
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				weight=150;
				mass=150;
				MOI=1500;
				latStiffX=25;
				latStiffY=1800;
				longitudinalStiffnessPerUnitGravity=100000;
				maxBrakeTorque=20000;
				sprungMass=2500;
				springStrength=62500;
				springDamperRate=22000;
				dampingRate=175;
				dampingRateInAir=8000;
				dampingRateDamaged=10;
				dampingRateDestroyed=10000;
				maxDroop=0.5;
				maxCompression=0.5;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class L2: L1
			{
				boneName="wheel_1_2_damper";
				steering=1;
				side="left";
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
			};
			class R1: L1
			{
				boneName="Wheel_2_1";
				steering=1;
				side="right";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
			};
			class L3: L1
			{
				boneName="wheel_1_3_damper";
				steering=0;
				center="wheel_1_3_axis";
				boundary="wheel_1_3_bound";
				suspForceAppPointOffset="wheel_1_3_axis";
				tireForceAppPointOffset="wheel_1_3_axis";
			};
			class L4: L1
			{
				boneName="wheel_1_4_damper";
				steering=0;
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
				maxHandBrakeTorque=4000;
				suspForceAppPointOffset="wheel_1_4_axis";
				tireForceAppPointOffset="wheel_1_4_axis";
			};
			class R2: R1
			{
				boneName="wheel_2_2_damper";
				steering=1;
				center="wheel_2_2_axis";
				boundary="wheel_2_2_bound";
				suspForceAppPointOffset="wheel_2_2_axis";
				tireForceAppPointOffset="wheel_2_2_axis";
			};
			class R4: R1
			{
				boneName="wheel_2_4_damper";
				steering=0;
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
				maxHandBrakeTorque=4000;
				suspForceAppPointOffset="wheel_2_4_axis";
				tireForceAppPointOffset="wheel_2_4_axis";
			};
			class RL0: R1
			{
				steering=0;
				boneName="RightLeg0";
				center="wheel_1_4_axis";
				boundary="wheel_1_4_bound";
				suspForceAppPointOffset="wheel_1_4_axis";
				tireForceAppPointOffset="wheel_1_4_axis";
				side="right";
				weight=150;
				mass=150;
			};
			class LL0: L1
			{
				boneName="FrontLeftLeg0";
				steering=0;
				side="right";
				center="wheel_2_4_axis";
				boundary="wheel_2_4_bound";
				maxHandBrakeTorque=40000;
				suspForceAppPointOffset="wheel_2_4_axis";
				tireForceAppPointOffset="wheel_2_4_axis";
			};
			class LL1: LL0
			{
				boneName="FrontLeftLeg1";
			};
			class LL2: LL0
			{
				boneName="FrontLeftLeg2";
			};
			class LL3: LL0
			{
				boneName="FrontLeftLeg3";
			};
			class RL1: RL0
			{
				boneName="RightLeg1";
			};
			class RL2: RL0
			{
				boneName="RightLeg2";
			};
			class RL3: RL0
			{
				boneName="RightLeg3";
			};
			class Torso: RL0
			{
				boneName="TorsoBody";
			};
		};
		dustbackLeftPos="Wheel_1_4_bound";
		dustbackRightPos="Wheel_2_4_bound";
		dustfrontLeftPos="Wheel_1_3_bound";
		dustfrontRightPos="Wheel_2_3_bound";
		editorSubcategory="FST_Ground_Vehicle";
		editorPreview="\3AS\3AS_ATAP\3AS_ATAP_base.jpg";
		scope=2;
		scopeCurator=2;
		displayname="[41st] AT-AP Siege Walker";
		artilleryScanner=1;
		faction="FST_Faction";
		side=1;
		class RenderTargets
		{
			class PIPGunner
			{
				renderTarget="rendertarget0";
				class CameraView1
				{
					pointPosition="gunner_optics";
					pointDirection="gunner_optics_dir";
					renderQuality=2;
					renderVisionMode=0;
					turret[]={0};
					fov=0.20345201;
				};
				BBoxes[]=
				{
					"PIP_GUN_TL",
					"PIP_GUN_TR",
					"PIP_GUN_BL",
					"PIP_GUN_BR"
				};
			};
			class PIPBelly
			{
				renderTarget="rendertarget1";
				class CameraView1
				{
					pointPosition="low_optics";
					pointDirection="low_optics_dir";
					renderVisionMode=0;
					renderQuality=2;
					fov=0.305731;
					turret[]={2};
				};
				BBoxes[]=
				{
					"PIP_BEL_TL",
					"PIP_BEL_TR",
					"PIP_BEL_BL",
					"PIP_BEL_BR"
				};
			};
			class PIPCommander
			{
				renderTarget="rendertarget2";
				class CameraView1
				{
					pointPosition="commander_optics";
					pointDirection="commander_optics_dir";
					renderQuality=2;
					renderVisionMode=0;
					turret[]={1};
					fov=0.20345201;
				};
				BBoxes[]=
				{
					"PIP_COM_TL",
					"PIP_COM_TR",
					"PIP_COM_BL",
					"PIP_COM_BR"
				};
			};
		};
		icon="3AS\3AS_ATAP\data\UI\ATAP_top_ca.paa";
		picture="3AS\3AS_ATAP\data\UI\ATAP_side_ca.paa";
		transportSoldier=0;
		crew="FST_Trooper_P2_DC15S";
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		memoryPointDriverOptics[]=
		{
			"driverview"
		};
		driverOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Driver_F.p3d";
		driveraction="mbt1_slot2_out";
		driverInAction="ATAP_Gunner2";
		forcehidedriver=1;
		armor=300;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		armorStructural=5;
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor=4;
				material=-1;
				name="HitHull";
				visual="zbytek";
				passThrough=0.80000001;
				minimalHit=0.23999999;
				explosionShielding=0.5;
				radius=0.15000001;
			};
			class HitEngine
			{
				armor=2.5;
				material=-1;
				name="HitEngine";
				passThrough=0.80000001;
				minimalHit=0.23999999;
				explosionShielding=1;
				radius=0.33000001;
			};
			class HitLTrack
			{
				armor=3;
				material=-1;
				name="track_l_hit";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=0.89999998;
				radius=0.30000001;
			};
			class HitRTrack
			{
				armor=3;
				material=-1;
				name="track_r_hit";
				passThrough=0;
				minimalHit=0.079999998;
				explosionShielding=0.89999998;
				radius=0.30000001;
			};
			class HitFuel
			{
				armor=2.5;
				material=-1;
				name="HitFuel";
				passThrough=1;
				minimalHit=0.1;
				explosionShielding=0.40000001;
				radius=0.25;
			};
			class HitLFWheel: HitLFWheel
			{
				explosionShielding=0.25;
			};
			class HitLF2Wheel: HitLF2Wheel
			{
				explosionShielding=0.25;
			};
			class HitLMWheel: HitLMWheel
			{
				explosionShielding=0.25;
			};
			class HitLBWheel: HitLBWheel
			{
				explosionShielding=0.25;
			};
			class HitRFWheel: HitRFWheel
			{
				explosionShielding=0.25;
			};
			class HitRF2Wheel: HitRF2Wheel
			{
				explosionShielding=0.25;
			};
			class HitRMWheel: HitRMWheel
			{
				explosionShielding=0.25;
			};
			class HitRBWheel: HitRBWheel
			{
				explosionShielding=0.25;
			};
		};
		forceDriveroptics=0;
		extCameraPosition[]={0,8,-18};
		autocenter=0;
		availableForSupportTypes[]=
		{
			"Artillery"
		};
		model="3AS\3AS_ATAP\model\3AS_ATAP.p3d";
		memoryPointsGetInDriver="pos_gunner";
		memoryPointsGetInDriverDir="pos_gunner_dir";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_atap\data\hull.rvmat",
				"3as\3AS_ATAP\data\damage\ATAP_Hull_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_atap\data\weapons.rvmat",
				"3as\3AS_ATAP\data\damage\ATAP_Weapons_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat",
				"3as\3as_atap\data\legs.rvmat",
				"3as\3AS_ATAP\data\damage\ATAP_Legs_damage.rvmat",
				"A3\armor_f_gamma\MBT_01\Data\MBT_01_body_destruct.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\ATAP\Data\Hull_CO_41.paa",
			"41st_Vehicles\ATAP\Data\weapons and decals_co_41.paa",
			"41st_Vehicles\ATAP\Data\legs_co_41.paa"
		};
		class MFD
		{
			class MFD_Gunner_Display_Damage
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class Bones
				{
				};
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Damage_Hull
					{
						type="text";
						source="static";
						text="HULL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.18000001},
							1
						};
						right[]=
						{
							{0.064999998,0.18000001},
							1
						};
						down[]=
						{
							{0.039999999,0.44},
							1
						};
					};
					class Damage_Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.18000001},
							1
						};
						right[]=
						{
							{0.13500001,0.18000001},
							1
						};
						down[]=
						{
							{0.11,0.44},
							1
						};
					};
					class Damage_Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.18000001},
							1
						};
						right[]=
						{
							{0.20299999,0.18000001},
							1
						};
						down[]=
						{
							{0.178,0.44},
							1
						};
					};
					class Damage_Wheels
					{
						type="text";
						source="static";
						text="TRKS";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.55000001},
							1
						};
						right[]=
						{
							{0.064999998,0.55000001},
							1
						};
						down[]=
						{
							{0.039999999,0.81},
							1
						};
					};
					class Damage_Gun
					{
						type="text";
						source="static";
						text="GUN";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.55000001},
							1
						};
						right[]=
						{
							{0.13500001,0.55000001},
							1
						};
						down[]=
						{
							{0.11,0.81},
							1
						};
					};
					class Damage_Turret
					{
						type="text";
						source="static";
						text="TRT";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.55000001},
							1
						};
						right[]=
						{
							{0.20299999,0.55000001},
							1
						};
						down[]=
						{
							{0.178,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
					class FuelScale
					{
						type="linear";
						source="fuel";
						sourceIndex=1;
						sourceScale=1;
						min=0;
						max=1;
						minPos[]={0,0};
						maxPos[]={-0.090000004,0};
					};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Main_Gun
					{
						type="text";
						source="static";
						text="MAIN GUN";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.18000001},
							1
						};
						right[]=
						{
							{0.29800001,0.18000001},
							1
						};
						down[]=
						{
							{0.273,0.44},
							1
						};
					};
					class Main_Gun_Ammo_count
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=2;
						sourceIndex=0;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.55000001},
							1
						};
						right[]=
						{
							{0.29800001,0.55000001},
							1
						};
						down[]=
						{
							{0.273,0.81},
							1
						};
					};
					class Main_Gun_Ammo_Type_text
					{
						type="text";
						source="static";
						text="TYPE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.18000001},
							1
						};
						right[]=
						{
							{0.41,0.18000001},
							1
						};
						down[]=
						{
							{0.38499999,0.44},
							1
						};
					};
					class Main_Gun_Ammo_Type
					{
						type="text";
						source="ammoFormat";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.55000001},
							1
						};
						right[]=
						{
							{0.41,0.55000001},
							1
						};
						down[]=
						{
							{0.38499999,0.81},
							1
						};
					};
					class Azimuth
					{
						type="text";
						source="static";
						text="GUN AZIM";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.60500002,0.18000001},
							1
						};
						right[]=
						{
							{0.63,0.18000001},
							1
						};
						down[]=
						{
							{0.60500002,0.44},
							1
						};
					};
					class Smoke
					{
						type="text";
						source="static";
						text="SMOKE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.71700001,0.18000001},
							1
						};
						right[]=
						{
							{0.74199998,0.18000001},
							1
						};
						down[]=
						{
							{0.71700001,0.44},
							1
						};
					};
					class Fuel_background_white
					{
						color[]={0.2,0.2,0.2};
						alpha=0.1;
						condition="1";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										{0.87699997,0.69999999},
										1
									},
									
									{
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_green
					{
						color[]={0,0.69999999,0};
						condition="fuel>=0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_yellow
					{
						color[]={0.89999998,0.69999999,0};
						condition="fuel<0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_red
					{
						color[]={0.69999999,0,0};
						condition="fuel<0.3";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82999998,0.18000001},
							1
						};
						right[]=
						{
							{0.85500002,0.18000001},
							1
						};
						down[]=
						{
							{0.82999998,0.44},
							1
						};
					};
					class Fuel_number
					{
						type="text";
						source="fuel";
						sourceScale=100;
						sourceLength=1;
						scale=1;
						align="left";
						refreshRate=0.1;
						pos[]=
						{
							{0.83499998,0.40000001},
							1
						};
						right[]=
						{
							{0.86000001,0.40000001},
							1
						};
						down[]=
						{
							{0.83499998,0.66000003},
							1
						};
					};
					class Fuel_percent_sign
					{
						type="text";
						source="static";
						text="%";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="right";
						refreshRate=0.1;
						pos[]=
						{
							{0.84500003,0.40000001},
							1
						};
						right[]=
						{
							{0.87,0.40000001},
							1
						};
						down[]=
						{
							{0.84500003,0.66000003},
							1
						};
					};
				};
			};
			class MFD_Gunner_OnScreen
			{
				topLeft="PIP_GUN_TL";
				topRight="PIP_GUN_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="EtelkaMonospaceProBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={0.15000001,1,0.050000001};
					alpha=1;
					condition="1";
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.235},
							1
						};
						right[]=
						{
							{0.52499998,0.235},
							1
						};
						down[]=
						{
							{0.5,0.27200001},
							1
						};
					};
					class Elevation_Text
					{
						type="text";
						source="static";
						text="E: ";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.23,0.30000001},
							1
						};
						right[]=
						{
							{0.255,0.30000001},
							1
						};
						down[]=
						{
							{0.23,0.33700001},
							1
						};
					};
					class Elevation_Number
					{
						type="text";
						source="[y]turretworld";
						sourceScale=1;
						sourceLength=4;
						sourcePrecision=1;
						refreshRate=0;
						align="center";
						scale=1;
						pos[]=
						{
							{0.25999999,0.30000001},
							1
						};
						right[]=
						{
							{0.285,0.30000001},
							1
						};
						down[]=
						{
							{0.25999999,0.33700001},
							1
						};
					};
					class Lased_Range
					{
						type="text";
						source="laserDist";
						sourceScale=1;
						sourceLength=4;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.64999998},
							1
						};
						right[]=
						{
							{0.52499998,0.64999998},
							1
						};
						down[]=
						{
							{0.5,0.68699998},
							1
						};
					};
					class VisionMode_Text
					{
						type="text";
						source="static";
						text="WFOV";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.75,0.64999998},
							1
						};
						right[]=
						{
							{0.77499998,0.64999998},
							1
						};
						down[]=
						{
							{0.75,0.68699998},
							1
						};
					};
					class VisionMode_String
					{
						type="text";
						source="visionMode";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82499999,0.64999998},
							1
						};
						right[]=
						{
							{0.85000002,0.64999998},
							1
						};
						down[]=
						{
							{0.82499999,0.68699998},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_MainTurret
			{
				topLeft="mfd_gun_TL";
				topRight="mfd_gun_TR";
				bottomLeft="mfd_gun_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={0};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Smoke_ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=3;
						sourceIndex=2;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.72000003,0.55000001},
							1
						};
						right[]=
						{
							{0.745,0.55000001},
							1
						};
						down[]=
						{
							{0.72000003,0.81},
							1
						};
					};
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.61000001,0.55000001},
							1
						};
						right[]=
						{
							{0.63499999,0.55000001},
							1
						};
						down[]=
						{
							{0.61000001,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_Damage2
			{
				topLeft="mfd_BEL_TL";
				topRight="mfd_BEL_TR";
				bottomLeft="mfd_BEL_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class Bones
				{
				};
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Damage_Hull
					{
						type="text";
						source="static";
						text="HULL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.18000001},
							1
						};
						right[]=
						{
							{0.064999998,0.18000001},
							1
						};
						down[]=
						{
							{0.039999999,0.44},
							1
						};
					};
					class Damage_Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.18000001},
							1
						};
						right[]=
						{
							{0.13500001,0.18000001},
							1
						};
						down[]=
						{
							{0.11,0.44},
							1
						};
					};
					class Damage_Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.18000001},
							1
						};
						right[]=
						{
							{0.20299999,0.18000001},
							1
						};
						down[]=
						{
							{0.178,0.44},
							1
						};
					};
					class Damage_Wheels
					{
						type="text";
						source="static";
						text="TRKS";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.55000001},
							1
						};
						right[]=
						{
							{0.064999998,0.55000001},
							1
						};
						down[]=
						{
							{0.039999999,0.81},
							1
						};
					};
					class Damage_Gun
					{
						type="text";
						source="static";
						text="GUN";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.55000001},
							1
						};
						right[]=
						{
							{0.13500001,0.55000001},
							1
						};
						down[]=
						{
							{0.11,0.81},
							1
						};
					};
					class Damage_Turret
					{
						type="text";
						source="static";
						text="TRT";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.55000001},
							1
						};
						right[]=
						{
							{0.20299999,0.55000001},
							1
						};
						down[]=
						{
							{0.178,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display2
			{
				topLeft="mfd_BEL_TL";
				topRight="mfd_BEL_TR";
				bottomLeft="mfd_BEL_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
					class FuelScale
					{
						type="linear";
						source="fuel";
						sourceIndex=1;
						sourceScale=1;
						min=0;
						max=1;
						minPos[]={0,0};
						maxPos[]={-0.090000004,0};
					};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Main_Gun
					{
						type="text";
						source="static";
						text="MAIN GUN";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.18000001},
							1
						};
						right[]=
						{
							{0.29800001,0.18000001},
							1
						};
						down[]=
						{
							{0.273,0.44},
							1
						};
					};
					class Main_Gun_Ammo_count
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=2;
						sourceIndex=0;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.55000001},
							1
						};
						right[]=
						{
							{0.29800001,0.55000001},
							1
						};
						down[]=
						{
							{0.273,0.81},
							1
						};
					};
					class Main_Gun_Ammo_Type_text
					{
						type="text";
						source="static";
						text="TYPE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.18000001},
							1
						};
						right[]=
						{
							{0.41,0.18000001},
							1
						};
						down[]=
						{
							{0.38499999,0.44},
							1
						};
					};
					class Main_Gun_Ammo_Type
					{
						type="text";
						source="ammoFormat";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.55000001},
							1
						};
						right[]=
						{
							{0.41,0.55000001},
							1
						};
						down[]=
						{
							{0.38499999,0.81},
							1
						};
					};
					class Azimuth
					{
						type="text";
						source="static";
						text="GUN AZIM";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.60500002,0.18000001},
							1
						};
						right[]=
						{
							{0.63,0.18000001},
							1
						};
						down[]=
						{
							{0.60500002,0.44},
							1
						};
					};
					class Smoke
					{
						type="text";
						source="static";
						text="SMOKE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.71700001,0.18000001},
							1
						};
						right[]=
						{
							{0.74199998,0.18000001},
							1
						};
						down[]=
						{
							{0.71700001,0.44},
							1
						};
					};
					class Fuel_background_white
					{
						color[]={0.2,0.2,0.2};
						alpha=0.1;
						condition="1";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										{0.87699997,0.69999999},
										1
									},
									
									{
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_green
					{
						color[]={0,0.69999999,0};
						condition="fuel>=0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_yellow
					{
						color[]={0.89999998,0.69999999,0};
						condition="fuel<0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_red
					{
						color[]={0.69999999,0,0};
						condition="fuel<0.3";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82999998,0.18000001},
							1
						};
						right[]=
						{
							{0.85500002,0.18000001},
							1
						};
						down[]=
						{
							{0.82999998,0.44},
							1
						};
					};
					class Fuel_number
					{
						type="text";
						source="fuel";
						sourceScale=100;
						sourceLength=1;
						scale=1;
						align="left";
						refreshRate=0.1;
						pos[]=
						{
							{0.83499998,0.40000001},
							1
						};
						right[]=
						{
							{0.86000001,0.40000001},
							1
						};
						down[]=
						{
							{0.83499998,0.66000003},
							1
						};
					};
					class Fuel_percent_sign
					{
						type="text";
						source="static";
						text="%";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="right";
						refreshRate=0.1;
						pos[]=
						{
							{0.84500003,0.40000001},
							1
						};
						right[]=
						{
							{0.87,0.40000001},
							1
						};
						down[]=
						{
							{0.84500003,0.66000003},
							1
						};
					};
				};
			};
			class MFD_Gunner_OnScreen2
			{
				topLeft="PIP_BEL_TL";
				topRight="PIP_BEL_TR";
				bottomLeft="mfd_BEL_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="EtelkaMonospaceProBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={0.15000001,1,0.050000001};
					alpha=1;
					condition="1";
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.235},
							1
						};
						right[]=
						{
							{0.52499998,0.235},
							1
						};
						down[]=
						{
							{0.5,0.27200001},
							1
						};
					};
					class Elevation_Text
					{
						type="text";
						source="static";
						text="E: ";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.23,0.30000001},
							1
						};
						right[]=
						{
							{0.255,0.30000001},
							1
						};
						down[]=
						{
							{0.23,0.33700001},
							1
						};
					};
					class Elevation_Number
					{
						type="text";
						source="[y]turretworld";
						sourceScale=1;
						sourceLength=4;
						sourcePrecision=1;
						refreshRate=0;
						align="center";
						scale=1;
						pos[]=
						{
							{0.25999999,0.30000001},
							1
						};
						right[]=
						{
							{0.285,0.30000001},
							1
						};
						down[]=
						{
							{0.25999999,0.33700001},
							1
						};
					};
					class Lased_Range
					{
						type="text";
						source="laserDist";
						sourceScale=1;
						sourceLength=4;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.64999998},
							1
						};
						right[]=
						{
							{0.52499998,0.64999998},
							1
						};
						down[]=
						{
							{0.5,0.68699998},
							1
						};
					};
					class VisionMode_Text
					{
						type="text";
						source="static";
						text="WFOV";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.75,0.64999998},
							1
						};
						right[]=
						{
							{0.77499998,0.64999998},
							1
						};
						down[]=
						{
							{0.75,0.68699998},
							1
						};
					};
					class VisionMode_String
					{
						type="text";
						source="visionMode";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82499999,0.64999998},
							1
						};
						right[]=
						{
							{0.85000002,0.64999998},
							1
						};
						down[]=
						{
							{0.82499999,0.68699998},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_MainTurret2
			{
				topLeft="mfd_BEL_TL";
				topRight="mfd_BEL_TR";
				bottomLeft="mfd_BEL_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={2};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Smoke_ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=3;
						sourceIndex=2;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.72000003,0.55000001},
							1
						};
						right[]=
						{
							{0.745,0.55000001},
							1
						};
						down[]=
						{
							{0.72000003,0.81},
							1
						};
					};
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.61000001,0.55000001},
							1
						};
						right[]=
						{
							{0.63499999,0.55000001},
							1
						};
						down[]=
						{
							{0.61000001,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_Damage3
			{
				topLeft="mfd_COM_TL";
				topRight="mfd_COM_TR";
				bottomLeft="mfd_COM_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={1};
				font="PuristaBold";
				class Bones
				{
				};
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Damage_Hull
					{
						type="text";
						source="static";
						text="HULL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.18000001},
							1
						};
						right[]=
						{
							{0.064999998,0.18000001},
							1
						};
						down[]=
						{
							{0.039999999,0.44},
							1
						};
					};
					class Damage_Engine
					{
						type="text";
						source="static";
						text="ENG";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.18000001},
							1
						};
						right[]=
						{
							{0.13500001,0.18000001},
							1
						};
						down[]=
						{
							{0.11,0.44},
							1
						};
					};
					class Damage_Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.18000001},
							1
						};
						right[]=
						{
							{0.20299999,0.18000001},
							1
						};
						down[]=
						{
							{0.178,0.44},
							1
						};
					};
					class Damage_Wheels
					{
						type="text";
						source="static";
						text="TRKS";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.039999999,0.55000001},
							1
						};
						right[]=
						{
							{0.064999998,0.55000001},
							1
						};
						down[]=
						{
							{0.039999999,0.81},
							1
						};
					};
					class Damage_Gun
					{
						type="text";
						source="static";
						text="GUN";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.11,0.55000001},
							1
						};
						right[]=
						{
							{0.13500001,0.55000001},
							1
						};
						down[]=
						{
							{0.11,0.81},
							1
						};
					};
					class Damage_Turret
					{
						type="text";
						source="static";
						text="TRT";
						scale=1;
						sourceScale=1;
						align="center";
						pos[]=
						{
							{0.178,0.55000001},
							1
						};
						right[]=
						{
							{0.20299999,0.55000001},
							1
						};
						down[]=
						{
							{0.178,0.81},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display3
			{
				topLeft="mfd_COM_TL";
				topRight="mfd_COM_TR";
				bottomLeft="mfd_COM_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={1};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
					class FuelScale
					{
						type="linear";
						source="fuel";
						sourceIndex=1;
						sourceScale=1;
						min=0;
						max=1;
						minPos[]={0,0};
						maxPos[]={-0.090000004,0};
					};
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Main_Gun
					{
						type="text";
						source="static";
						text="MAIN GUN";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.18000001},
							1
						};
						right[]=
						{
							{0.29800001,0.18000001},
							1
						};
						down[]=
						{
							{0.273,0.44},
							1
						};
					};
					class Main_Gun_Ammo_count
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=2;
						sourceIndex=0;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.273,0.55000001},
							1
						};
						right[]=
						{
							{0.29800001,0.55000001},
							1
						};
						down[]=
						{
							{0.273,0.81},
							1
						};
					};
					class Main_Gun_Ammo_Type_text
					{
						type="text";
						source="static";
						text="TYPE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.18000001},
							1
						};
						right[]=
						{
							{0.41,0.18000001},
							1
						};
						down[]=
						{
							{0.38499999,0.44},
							1
						};
					};
					class Main_Gun_Ammo_Type
					{
						type="text";
						source="ammoFormat";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.38499999,0.55000001},
							1
						};
						right[]=
						{
							{0.41,0.55000001},
							1
						};
						down[]=
						{
							{0.38499999,0.81},
							1
						};
					};
					class Azimuth
					{
						type="text";
						source="static";
						text="GUN AZIM";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.60500002,0.18000001},
							1
						};
						right[]=
						{
							{0.63,0.18000001},
							1
						};
						down[]=
						{
							{0.60500002,0.44},
							1
						};
					};
					class Smoke
					{
						type="text";
						source="static";
						text="SMOKE";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.71700001,0.18000001},
							1
						};
						right[]=
						{
							{0.74199998,0.18000001},
							1
						};
						down[]=
						{
							{0.71700001,0.44},
							1
						};
					};
					class Fuel_background_white
					{
						color[]={0.2,0.2,0.2};
						alpha=0.1;
						condition="1";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										{0.87699997,0.69999999},
										1
									},
									
									{
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_green
					{
						color[]={0,0.69999999,0};
						condition="fuel>=0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_yellow
					{
						color[]={0.89999998,0.69999999,0};
						condition="fuel<0.5";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel_background_red
					{
						color[]={0.69999999,0,0};
						condition="fuel<0.3";
						class Background
						{
							type="polygon";
							points[]=
							{
								
								{
									
									{
										{0.787,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.69999999},
										1
									},
									
									{
										"FuelScale",
										{0.87699997,0.89999998},
										1
									},
									
									{
										{0.787,0.89999998},
										1
									}
								}
							};
						};
					};
					class Fuel
					{
						type="text";
						source="static";
						text="FUEL";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82999998,0.18000001},
							1
						};
						right[]=
						{
							{0.85500002,0.18000001},
							1
						};
						down[]=
						{
							{0.82999998,0.44},
							1
						};
					};
					class Fuel_number
					{
						type="text";
						source="fuel";
						sourceScale=100;
						sourceLength=1;
						scale=1;
						align="left";
						refreshRate=0.1;
						pos[]=
						{
							{0.83499998,0.40000001},
							1
						};
						right[]=
						{
							{0.86000001,0.40000001},
							1
						};
						down[]=
						{
							{0.83499998,0.66000003},
							1
						};
					};
					class Fuel_percent_sign
					{
						type="text";
						source="static";
						text="%";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="right";
						refreshRate=0.1;
						pos[]=
						{
							{0.84500003,0.40000001},
							1
						};
						right[]=
						{
							{0.87,0.40000001},
							1
						};
						down[]=
						{
							{0.84500003,0.66000003},
							1
						};
					};
				};
			};
			class MFD_Gunner_OnScreen3
			{
				topLeft="PIP_COM_TL";
				topRight="PIP_COM_TR";
				bottomLeft="mfd_COM_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={1};
				font="EtelkaMonospaceProBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={0.15000001,1,0.050000001};
					alpha=1;
					condition="1";
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.235},
							1
						};
						right[]=
						{
							{0.52499998,0.235},
							1
						};
						down[]=
						{
							{0.5,0.27200001},
							1
						};
					};
					class Elevation_Text
					{
						type="text";
						source="static";
						text="E: ";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.23,0.30000001},
							1
						};
						right[]=
						{
							{0.255,0.30000001},
							1
						};
						down[]=
						{
							{0.23,0.33700001},
							1
						};
					};
					class Elevation_Number
					{
						type="text";
						source="[y]turretworld";
						sourceScale=1;
						sourceLength=4;
						sourcePrecision=1;
						refreshRate=0;
						align="center";
						scale=1;
						pos[]=
						{
							{0.25999999,0.30000001},
							1
						};
						right[]=
						{
							{0.285,0.30000001},
							1
						};
						down[]=
						{
							{0.25999999,0.33700001},
							1
						};
					};
					class Lased_Range
					{
						type="text";
						source="laserDist";
						sourceScale=1;
						sourceLength=4;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.5,0.64999998},
							1
						};
						right[]=
						{
							{0.52499998,0.64999998},
							1
						};
						down[]=
						{
							{0.5,0.68699998},
							1
						};
					};
					class VisionMode_Text
					{
						type="text";
						source="static";
						text="WFOV";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.75,0.64999998},
							1
						};
						right[]=
						{
							{0.77499998,0.64999998},
							1
						};
						down[]=
						{
							{0.75,0.68699998},
							1
						};
					};
					class VisionMode_String
					{
						type="text";
						source="visionMode";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.82499999,0.64999998},
							1
						};
						right[]=
						{
							{0.85000002,0.64999998},
							1
						};
						down[]=
						{
							{0.82499999,0.68699998},
							1
						};
					};
				};
			};
			class MFD_Gunner_Display_MainTurret3
			{
				topLeft="mfd_COM_TL";
				topRight="mfd_COM_TR";
				bottomLeft="mfd_COM_BL";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={1,1,1};
				alpha=0.5;
				enableParallax=0;
				turret[]={1};
				font="PuristaBold";
				class material
				{
					ambient[]={1,1,1,1};
					diffuse[]={1,1,1,1};
					emissive[]={1000,1000,1000,1};
				};
				class Bones
				{
				};
				class Draw
				{
					color[]={1,1,1};
					alpha=1;
					condition="1";
					class Smoke_ammo
					{
						type="text";
						source="ammo";
						sourceScale=1;
						sourceLength=3;
						sourceIndex=2;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.72000003,0.55000001},
							1
						};
						right[]=
						{
							{0.745,0.55000001},
							1
						};
						down[]=
						{
							{0.72000003,0.81},
							1
						};
					};
					class Azimuth_number
					{
						type="text";
						source="[x]turretworld";
						sourceScale=1;
						sourceLength=3;
						scale=1;
						align="center";
						refreshRate=0.1;
						pos[]=
						{
							{0.61000001,0.55000001},
							1
						};
						right[]=
						{
							{0.63499999,0.55000001},
							1
						};
						down[]=
						{
							{0.61000001,0.81},
							1
						};
					};
				};
			};
		};
		class DestructionEffects
		{
			class Light1
			{
				simulation="light";
				type="ObjectDestructionLightSmall";
				position="destructionEffect1";
				intensity=0.001;
				interval=1;
				lifeTime=3;
				enabled="distToWater";
			};
			class Sound
			{
				simulation="sound";
				position="destructionEffect1";
				intensity=0.5;
				interval=1;
				lifeTime=1;
				type="Fire";
			};
			class Fire1
			{
				simulation="particles";
				type="ObjectDestructionFire1Tiny";
				position="destructionEffect1";
				intensity=0.25;
				interval=1;
				lifeTime=3;
			};
			class Refract1
			{
				simulation="particles";
				type="SmallFireFRefract";
				position="destructionEffect1";
				intensity=0.5;
				interval=1;
				lifeTime=3;
			};
		};
		class Eventhandlers: Eventhandlers
		{
		};
		class AnimationSources: AnimationSources
		{
			class Deploy
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="3AS_ATAP_PD_Turret";
			};
			class Muzzle_Flash2
			{
				source="ammorandom";
				weapon="3AS_ATAP_Siege_Cannon";
			};
			class Muzzle_Flash3
			{
				source="ammorandom";
				weapon="3AS_ATAP_AT_Turret";
			};
			class recoil_source1
			{
				source="reload";
				weapon="3AS_ATAP_Siege_Cannon";
			};
			class recoil_source2
			{
				source="reload";
				weapon="3AS_ATAP_AT_Turret";
			};
		};
		class UserActions
		{
			class Deploy
			{
				displayName="Deploy Stabalizing Leg";
				position="action";
				radius=10;
				onlyForPlayer=0;
				condition="(this animationSourcePhase ""Deploy"" == 0) AND  (alive this) AND (currentPilot this isEqualTo player) AND (this animationSourcePhase ""Wheel"" >= 0.95 OR this animationSourcePhase ""Wheel"" <= 0.05) ;";
				statement="this animateSource [""wheel"",1,1];this setFuel 0; this animateSource [""Deploy"",1,0.15];";
			};
			class unDeploy: Deploy
			{
				displayName="Fold Stabalizing Leg";
				condition="(this animationSourcePhase ""Deploy"" == 1) AND  (alive this) AND (currentPilot this isEqualTo player)";
				statement="this animateSource [""Deploy"",0,0.15];this setFuel 1;this animateSource [""wheel"",1,1];";
			};
		};
		class TextureSources
		{
			class Republic
			{
				displayName="Republic";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"41st_Vehicles\ATAP\Data\Hull_CO_41.paa",
					"41st_Vehicles\ATAP\Data\weapons and decals_co_41.paa",
					"41st_Vehicles\ATAP\Data\legs_co_41.paa"
				};
				factions[]=
				{
					"FST_Faction"
				};
			};
		};
		smokeLauncherGrenadeCount=8;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=0;
		smokeLauncherAngle=120;
		class Turrets: Turrets
		{
			class MainTurret1: MainTurret
			{
				startEngine=0;
				body="MainTurret";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				gun="MainGun";
				proxyIndex=1;
				viewGunnerInExternal=1;
				proxytype="CPGunner";
				gunnername="Gunner";
				showgunneroptics=1;
				enableManualFire=0;
				animationSourceBody="Mainturret";
				animationSourceGun="Maingun";
				gunBeg="Konec hlavne";
				gunEnd="Usti hlavne";
				memoryPointGun="usti hlavne";
				commanding=1;
				artilleryScanner = 1;
				class OpticsIn: Optics_Gunner_MBT_03
				{
					class Wide: Wide
					{
					};
					class Medium: Medium
					{
					};
					class Narrow: Narrow
					{
					};
				};
				memoryPointGunnerOptics="gunner_optics";
				weapons[]=
				{
					"FST_ATAP_SIEGE_Cannon",
					"FST_ATAP_mortar"
				};
				magazines[]=
				{
					"FST_10Rnd_Siege_Cannon_HHE_shells",
					"FST_10Rnd_Siege_Cannon_HHE_shells",
					"FST_32Rnd_155mm_ATAP_Mortar_shells",
					"FST_32Rnd_155mm_ATAP_Mortar_shells",				
				};
				gunnerAction="mbt1_slot2_out";
				gunnerInAction="ATAP_Gunner2";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				selectionFireAnim="zasleh2";
				turretInfoType="RscOptics_MBT_03_gunner";
				primarygunner=1;
				showCrewAim=2;
				isPersonTurret=0;
				elevationMode=0;
				minElev=-12;
				initElev=0;
				maxElev=70;
				maxTurn=30;
				minTurn=-30;
				minOutElev=-10;
				maxOutElev=15;
				initOutElev=0;
				minOutTurn=-15;
				maxOutTurn=175;
				initOutTurn=0;
				forceHideGunner=1;
				outGunnerMayFire=0;
				inGunnerMayFire=1;
				gunnerForceOptics=0;
				LODTurnedIn=1000;
				LODOpticsIn=1;
				usepip=1;
				class Turrets
				{
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.60000002;
						material=-1;
						name="gun1_hit";
						visual="commander_turret_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.30000001;
					};
					class HitGun
					{
						armor=0.60000001;
						material=-1;
						name="gun1_hit";
						visual="commander_gun_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.5;
					};
				};
				class ViewGunner: ViewGunner
				{
					initAngleX=7.5;
					initAngleY=0;
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={800,400,200,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay="SensorDisplay";
						class Components: components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={800,400,200,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
			class MainTurretTop: MainTurret1
			{
				startEngine=0;
				primarygunner=0;
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				selectionFireAnim="zasleh3";
				body="MainTurret2";
				gun="MainGun2";
				proxyIndex=2;
				viewGunnerInExternal=1;
				showgunneroptics=1;
				commanding=5;
				enableManualFire=0;
				proxytype="CPGunner";
				gunnername="Commander";
				ejectDeadGunner=1;
				animationSourceBody="Mainturret2";
				animationSourceGun="Maingun2";
				forceHideGunner=1;
				gunBeg="Konec hlavne2";
				gunEnd="Usti hlavne2";
				gunnerInAction="ATAP_Commander";
				memoryPointGun="usti hlavne2";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.56234097,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.56234097,
					1,
					30
				};
				weapons[]=
				{
					"FST_Mass_Driver_Cannon",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"FST_thermal_coil_HP_Blue",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
				};
				minElev=-15;
				maxElev=25;
				maxTurn=360;
				minTurn=-360;
				initElev=0;
				elevationMode=0;
				memoryPointGunnerOptics="commander_optics";
				cameraDir="look";
				turretInfoType="RscOptics_crows";
				gunnerForceOptics=0;
				LODTurnedIn=1000;
				LODOpticsIn=1000;
				usepip=0;
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
				class HitPoints
				{
					class HitTurret
					{
						armor=0.60000002;
						material=-1;
						name="turret2_hit";
						visual="main_turret_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.60000001;
						material=-1;
						name="gun2_hit";
						visual="main_gun_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.25;
					};
				};
			};
			class MainTurretBottom: MainTurret1
			{
				startEngine=0;
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				selectionFireAnim="zasleh1";
				body="MainTurret3";
				gun="MainGun3";
				proxyIndex=3;
				usepip=1;
				proxytype="CPGunner";
				gunnername="Belly Gunner";
				animationSourceBody="Mainturret3";
				animationSourceGun="Maingun3";
				gunBeg="Konec hlavne3";
				gunEnd="Usti hlavne3";
				memoryPointGun="usti hlavne3";
				weapons[]=
				{
					"FST_ATTE_Turret",
					"FST_EWEB_RemoteTurret",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_thermal_coil_blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"FST_EWEB_cell_Blue",
					"SmokeLauncherMag"
				};
				minElev=-35;
				maxElev=5;
				maxTurn=90;
				minTurn=-90;
				initElev=0;
				elevationMode=0;
				memoryPointGunnerOptics="low_optics";
				LodTurnedIn=1000;
				LOdOpticsIn=1;
				gunnerForceOptics=0;
				gunnerInAction="ATAP_Gunner";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
				turretInfoType="RscOptics_MBT_01_commander_RCWS";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex=2;
				class ViewGunner: ViewGunner
				{
					initAngleX=5;
					initAngleY=0;
				};
				class OpticsIn: Optics_Commander_01
				{
					class Wide: Wide
					{
					};
					class Medium: Medium
					{
					};
					class Narrow: Narrow
					{
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.60000002;
						material=-1;
						name="turret3_hit";
						visual="main_turret_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.2;
						radius=0.25;
					};
					class HitGun
					{
						armor=0.60000001;
						material=-1;
						name="gun_3_hit";
						visual="main_gun_hit";
						passThrough=0;
						minimalHit=0.1;
						explosionShielding=0.40000001;
						radius=0.25;
					};
				};
			};
		};
		class Components
		{
			class TransportCountermeasuresComponent {};
			class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
			{
				class Components: components
				{
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={800,400,200,1600};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
			{
				defaultDisplay="SensorDisplay";
				class Components: components
				{
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={800,400,200,1600};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class SensorsManagerComponent
			{
				class Components
				{
					class LaserSensorComponent: SensorTemplateLaser
					{
						animDirection="mainTurret";
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
					class ManSensorComponent: SensorTemplateMan
					{
						maxTrackableSpeed=15;
						angleRangeHorizontal=51;
						angleRangeVertical=37;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=0;
							maxRange=500;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=250;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=35;
						angleRangeHorizontal=51;
						angleRangeVertical=37;
						animDirection="mainGun";
						aimDown=-0.5;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=0;
							maxRange=1000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=35;
						angleRangeHorizontal=90;
						angleRangeVertical=90;
						animDirection="mainGun";
						aimDown=-0.5;
					};
				};
			};
		};
	};
};
