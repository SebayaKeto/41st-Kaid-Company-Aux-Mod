class CfgPatches
{
	class FST_FV41_Striker
	{
		addonRootClass="A3_Armor_F_EPB";
		requiredAddons[]=
		{
			"A3_Armor_F_EPB"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_FV41_Striker"
		};
		weapons[]={};
	};
};
class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
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
class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink;
class DefaultEventHandlers;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
class Optics_Commander_02: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class Optics_Gunner_AAA_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgVehicles
{
	class LandVehicle;
	class Tank: LandVehicle
	{
		class NewTurret;
		class Sounds;
		class HitPoints;
		class CommanderOptics;
		class SensorTemplateActiveRadar;
		class SensorTemplateDataLink;
		class VehicleSystemsTemplateLeftGunner;
		class VehicleSystemsTemplateRightGunner;
		class components;
	};
	class Tank_F: Tank
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewGunner;
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class ViewCargo;
		class HeadLimits;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitLTrack;
			class HitRTrack;
		};
		class Sounds: Sounds
		{
			class Engine;
			class Movement;
		};
	};
	class APC_Tracked_03_base_F: Tank_F
	{
	};
	class B_APC_Tracked_01_rcws_F: Tank_F
	{
	};
	class FST_FV41_Striker: B_APC_Tracked_01_rcws_F
	{
		scope=2;
		scopecurator=2;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-4,-6.5]]], [-0.001], [-0.4]]";
		side=1;
		maximumLoad=5000;
		displayName="[41st] FV41 Striker";
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		author="Daara";
		incomingMissileDetectionSystem=16;
		weaponLockSystem="2+4+8";
		supplyRadius=10;
		ace_cargo_space=100;
		ace_cargo_hasCargo=1;
		ace_refuel_fuelCargo=999999999999;
		ace_rearm_defaultSupply=999999999999;
		ace_repair_canRepair=1;
		ace_refuel_hooks[]=
		{
			{0.38,-3.1700001,-0.69999999},
			{-0.41,-3.1700001,-0.69999999}
		};
		armor=825;
		armorStructural=20;
		insideSoundCoef=0.025;
		irScanGround=0;
		irScanRangeMax=10000;
		irScanRangeMin=2000;
		irScanToEyeFactor=2;
		radarType=4;
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"CamoNet"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\FV41_Striker\Data\FST_Striker_01_body_CO.paa",
			"41st_Vehicles\FV41_Striker\Data\FST_Striker_01_MBT_body_CO.paa",
			"41st_Vehicles\FV41_Striker\Data\FST_Striker_Turret_CO.paa",
			"a3\Armor_F\Data\camonet_NATO_Desert_CO.paa"
		};
		simulation="tankX";
		thrustDelay=1;
		brakeDistance=1;
		brakeIdleSpeed=1.78;
		maxSpeed=250;
		accelAidForceCoef=15;
		accelAidForceSpd=10;
		accelAidForceYOffset=-2;
		fuelCapacity=100;
		wheelCircumference=3.924;
		antiRollbarForceCoef=12;
		antiRollbarForceLimit=10;
		antiRollbarSpeedMin=10;
		antiRollbarSpeedMax=80;
		idleRpm=1000;
		redRpm=2000;
		slowSpeedForwardCoef=0.34999999;
		normalSpeedForwardCoef=0.64999998;
		enginePower=600;
		peakTorque=4000;
		maxOmega=500;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-3,
				"N",
				0,
				"D1",
				4.6500001,
				"D2",
				3.2,
				"D3",
				2.4000001,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97000003,
				"D9",
				0.87,
				"D10",
				0.77999997
			};
			AmphibiousRatios[]=
			{
				"R1",
				-3,
				"N",
				0,
				"D1",
				4.6500001,
				"D2",
				3.2,
				"D3",
				2.4000001,
				"D4",
				1.87,
				"D5",
				1.54,
				"D6",
				1.29,
				"D7",
				1.11,
				"D8",
				0.97000003,
				"D9",
				0.87,
				"D10",
				0.77999997
			};
			TransmissionRatios[]=
			{
				"High",
				5.4499998
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		tankTurnForce=950000;
		tankTurnForceAngMinSpd=0.69999999;
		tankTurnForceAngSpd=0.75999999;
		smokeLauncherGrenadeCount=10;
		smokeLauncherVelocity=14;
		smokeLauncherOnTurret=1;
		smokeLauncherAngle=120;
		crewExplosionProtection=0.05;
		crewCrashProtection=0.05;
		damageResistance=0.0054700002;
		crewVulnerable=0;
		armorLights=1;
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=3.5999999;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.30000001;
			};
			class HitEngine: HitEngine
			{
				armor=4;
				material=-1;
				name="motor";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitLTrack: HitLTrack
			{
				armor=4;
				material=-1;
				name="track_l_hit";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitRTrack: HitRTrack
			{
				armor=4;
				material=-1;
				name="track_r_hit";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=4;
				material=-1;
				name="palivo";
				passThrough=1;
				minimalHit=0.001;
				explosionShielding=1;
				radius=0.30000001;
			};
		};
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=300;
							maxRange=7500;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=200;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=6000;
						angleRangeHorizontal=360;
						angleRangeVertical=100;
						aimDown=-45;
						maxTrackableSpeed=694.44397;
					};
					class DataLinkSensorComponent
					{
						componentType="DataLinkSensorComponent";
						class AirTarget
						{
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=0;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						color[]={1,1,1,0};
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
						allowsMarking=1;
					};
				};
			};
		};
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\vehicles\air\noises\alarm_locked_by_missile_2",
			0.31622776,
			1
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class CommanderOptics: CommanderOptics
				{
					memoryPointGunnerOutOptics="commanderview";
					memoryPointGunnerOptics="commanderview";
					maxHorizontalRotSpeed=1.8;
					maxVerticalRotSpeed=1.8;
					minElev=-10;
					maxElev=30;
					initElev=0;
					minTurn=-360;
					maxTurn=360;
					initTurn=0;
					minCamElev=-90;
					maxCamElev=90;
					outGunnerMayFire=0;
					inGunnerMayFire=1;
					gunnerAction="Commander_APC_tracked_01_crv_out";
					gunnerInAction="Commander_APC_tracked_01_crv_in";
					gunnerGetInAction="GetInAMV_cargo";
					gunnerGetOutAction="GetOutLow";
					turretInfoType="RscWeaponRangeFinder";
					gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Commander_02_F";
					gunnerforceoptics=0;
					usePip=1;
					animationSourceStickX="com_turret_control_x";
					animationSourceStickY="com_turret_control_y";
					gunnerLeftHandAnimName="com_turret_control";
					turretFollowFreeLook=2;
					LODOpticsIn=0;
					viewGunnerShadowAmb=0.5;
					viewGunnerShadowDiff=0.050000001;
					gunnerOutOpticsModel="";
					gunnerOpticsEffect[]={};
					weapons[]=
					{
						"Laserdesignator_pilotCamera",
						"SmokeLauncher"
					};
					magazines[]=
					{
						"Laserbatteries",
						"SmokeLauncherMag",
						"SmokeLauncherMag"
					};
					class ViewGunner: ViewCargo
					{
						initAngleX=-6;
						initAngleY=0;
						initFov=0.89999998;
						minFov=0.25;
						maxFov=1.25;
						minAngleX=-65;
						maxAngleX=85;
						minAngleY=-150;
						maxAngleY=150;
						minMoveX=-0.075000003;
						maxMoveX=0.075000003;
						minMoveY=-0.075000003;
						maxMoveY=0.075000003;
						minMoveZ=-0.075000003;
						maxMoveZ=0.1;
					};
					class ViewOptics: ViewOptics
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.31;
						minFov=0.034000002;
						maxFov=0.31;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"TI"
						};
						thermalMode[]={2,3};
					};
					startEngine=0;
					stabilizedInAxes=3;
					viewGunnerInExternal=1;
					showCrewAim=1;
					soundServo[]=
					{
						"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",
						0.31622776,
						1,
						30
					};
					soundServoVertical[]=
					{
						"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner_vertical",
						0.31622776,
						1,
						30
					};
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
					{
						class Components: Components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000};
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
					{
						defaultDisplay="SensorDisplay";
						class Components: Components
						{
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
				memoryPointGun="usti hlavne2";
				maxHorizontalRotSpeed=1.8;
				maxVerticalRotSpeed=1.8;
				body="mainTurret";
				gun="mainGun";
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				reloadTime=0.60000002;
				weapons[]=
				{
					"FST_30m_Autocannon",
					"FST_Rotary_Blaster_Coax",
					"OPTRE_M670_ATGM_Launcher",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_200Rnd_30mm_shells",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"FST_500Rnd_High_Capacity_Plasma_Cell",
					"OPTRE_2Rnd_GAT_missiles",
					"SmokeLauncherMag",
					"SmokeLauncherMag",
					"SmokeLauncherMag"
				};
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner",
					0.31622776,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\noises\servo_APC_gunner_vertical",
					0.31622776,
					1,
					30
				};
				commanding=1;
				minElev=-15;
				initElev=0;
				maxElev=80;
				minCamElev=-90;
				maxCamElev=90;
				gunnerAction="crew_tank01_out";
				gunnerInAction="Gunner_APC_tracked_01_crv_in";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				viewGunnerInExternal=1;
				castGunnerShadow=1;
				forceHideGunner=1;
				startEngine=0;
				stabilizedInAxes=3;
				gunnerForceOptics=0;
				usePip=1;
				inGunnerMayFire=1;
				outGunnerMayFire=0;
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				gunnerOutOpticsModel="";
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				memoryPointGunnerOptics="gunnerview";
				selectionFireAnim="zasleh2";
				showCrewAim=2;
				animationSourceStickX="turret_control_x";
				animationSourceStickY="turret_control_y";
				gunnerRightHandAnimName="turret_control";
				LODOpticsIn=0;
				viewGunnerShadowAmb=0.5;
				viewGunnerShadowDiff=0.050000001;
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				class OpticsIn: Optics_Gunner_APC_01
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
				class ViewGunner: ViewGunner
				{
					initAngleX=0;
					minAngleX=-90;
					maxAngleX=90;
					initFov=0.89999998;
					minFov=0.41999999;
					maxFov=0.89999998;
					visionMode[]={};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=-500;
						material=-1;
						armorComponent="hit_main_turret";
						name="hit_main_turret_point";
						visual="otocvez";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.40000001;
						radius=0.25;
						isTurret=1;
					};
					class HitGun
					{
						armor=-500;
						material=-1;
						armorComponent="hit_main_gun";
						name="hit_main_gun_point";
						visual="otochlaven";
						passThrough=0;
						minimalHit=0.029999999;
						explosionShielding=0.2;
						radius=0.2;
						isGun=1;
					};
				};
				class Reflectors
				{
					class Main
					{
						color[]={7000,7500,10000};
						ambient[]={70,75,100};
						intensity=50;
						size=5;
						innerAngle=15;
						outerAngle=65;
						coneFadeCoef=10;
						position="laser_l_muzzle";
						direction="laser_l_chamber";
						hitpoint="Light_b_hitpoint";
						selection="Light_L";
						useFlare=1;
						flareSize=15;
						flareMaxDistance=250;
						dayLight=0;
						class Attenuation
						{
							start=0;
							constant=0;
							linear=1;
							quadratic=1;
							hardLimitStart=100;
							hardLimitEnd=200;
						};
					};
				};
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_body.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_body_damage.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_body_destruct.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_Tower.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_Tower_damage.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_AA_Tower_destruct.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_body.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_body_damage.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_body_destruct.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_CRV.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_CRV_damage.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_CRV_destruct.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body_damage.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body_destruct.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body_CRV_noTI.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body_damage.rvmat",
				"a3\armor_f_beta\apc_tracked_01\data\MBT_01_body_destruct.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_Interier.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_Interier_damage.rvmat",
				"A3\armor_f_beta\APC_Tracked_01\Data\APC_Tracked_01_Interier_destruct.rvmat",
				"A3\Data_F\Vehicles\Turret.rvmat",
				"A3\Data_F\Vehicles\Turret_damage.rvmat",
				"A3\Data_F\Vehicles\Turret_destruct.rvmat"
			};
		};
	};
};
class Mode_SemiAuto;
class CfgAmmo
{
	class B_30mm_HE;
	class JLTS_bullet_rifle_blue;
	class FST_FV41_autocannon_ammo: B_30mm_HE
	{
		hit=10;
		indirectHit=30;
		indirectHitRange=4;
		explosive=0.80000001;
		dangerRadiusBulletClose=20;
		dangerRadiusHit=60;
		suppressionRadiusBulletClose=12;
		suppressionRadiusHit=24;
		cost=20;
		airFriction=-0.00036000001;
		fuseDistance=3;
		typicalSpeed=900;
		caliber=2;
		airlock=1;
		model="ls_weapons_core\Effects\laser_blue.p3d";
		effectfly="IDA_BlasterBoltGlow_Large_Blue_Fly";
		aiAmmoUsageFlags="64 + 128";
		tracerScale=4.5;
		tracerStartTime=0.001;
		tracerEndTime=4.6999998;
	};
};
class CfgMagazines
{
	class VehicleMagazine;
	class FST_500Rnd_High_Capacity_Plasma_Cell: VehicleMagazine
	{
		displayname="500Rnd High Capacity plasma cell";
		displaynameshort="HC Plasma Cell";
		scope=2;
		count=500;
		ammo="IDA_blasterbolt";
		initSpeed=910;
		maxLeadSpeed=36.111099;
		tracersEvery=1;
		nameSound="mgun";
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
	class FST_200Rnd_30mm_shells: VehicleMagazine
	{
		scope=2;
		displayName="[41st] 250 Medium HE Shells";
		displayNameShort="MHES";
		ammo="FST_FV41_autocannon_ammo";
		count=200;
		initSpeed=1430;
		maxLeadSpeed=83.333298;
		nameSound="cannon";
		tracersEvery=1;
		muzzleImpulseFactor[]={0.050000001,0.050000001};
	};
};
class Mode_FullAuto;
class CfgWeapons
{
	class CannonCore;
	class MGun;
	class LMG_RCWS: MGun
	{
		class manual: MGun
		{
		};
		class close: manual
		{
		};
		class short: close
		{
		};
		class medium: close
		{
		};
		class far: close
		{
		};
	};
	class LMG_M200: LMG_RCWS
	{
	};
	class FST_Rotary_Blaster_Coax: LMG_RCWS
	{
		displayName="[41st] Rotary Blaster Coax";
		author="Daara";
		descriptionShort="RBC";
		magazines[]=
		{
			"FST_500Rnd_High_Capacity_Plasma_Cell"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundsetshot[]=
				{
					"3AS_Z6_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.0695;
			aiRateOfFire=1;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class GunParticles
		{
			class effect1
			{
				positionName="konec hlavne3";
				directionName="Usti hlavne3";
				effectName="MachineGunCloud";
			};
		};
	};
	class FST_30m_Autocannon: CannonCore
	{
		displayName="[41st] FV41 Autocannon";
		author="Daara";
		descriptionShort="MG";
		magazines[]=
		{
			"FST_200Rnd_30mm_shells"
		};
		muzzleEnd="konec hlavne3";
		muzzlePos="usti hlavne3";
		selectionFireAnim="zasleh3";
		modes[]=
		{
			"FullAuto",
		};
		cursor="EmptyCursor";
		class FullAuto: Mode_FullAuto
		{
			sounds[]=
			{
				"StandardSound"
			};
			class StandardSound
			{
				soundsetshot[]=
				{
					"3AS_lightwalkercanon_Shot_SoundSet",
					"Autocannon30mmBody_tail_SoundSet"
				};
			};
			soundContinuous=0;
			soundBurst=0;
			reloadTime=0.3;
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