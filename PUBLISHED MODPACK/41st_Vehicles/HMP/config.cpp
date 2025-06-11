class cfgpatches
{
	class FST_HMP
	{
		units[]=
		{
			"FST_HMP_Transport",
			"FST_HMP_Gunship"
		};
		weapons[]={};
		requiredAddons[]=
		{
			"A3_Data_F",
			"A3_Air_F_Beta_Heli_Attack_01"
		};
		magazines[]={};
		ammo[]=
		{
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
	class components
	{
		class MinimapDisplay;
	};
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components
	{
		class MinimapDisplay;
	};
};
class CfgSounds
{
	class TAS_Clamps
	{
		name="$STR_A3_FIRING_DRILLS_SFX_FINISH";
		sound[]=
		{
			"3AS\3AS_LAATC\data\SFX\clamp.wss",
			1,
			1
		};
		titles[]={};
	};
};
class ls_impulsor_base;
class CfgFunctions
{
	class TAS
	{
		class CargoLift
		{
			file="3AS\3AS_LAATC\fnc";
			class MagLift
			{
			};
			class MagDrop
			{
			};
		};
	};
};
class CfgVehicles
{
	class Wreck_base_F;
	class Air;
	class Helicopter: Air
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_F: Helicopter
	{
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitAvionics;
			class HitMissiles;
			class HitEngine;
			class HitHRotor;
			class HitVRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
			class HitGlass6;
			class HitWinch;
		};
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class EventHandlers;
		class ViewOptics;
		class ViewPilot;
		class Components;
	};
	class Heli_Attack_01_base_F: Helicopter_Base_F
	{
		class Turrets: Turrets
		{
			class CopilotTurret;
			class MainTurret;
		};
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitAvionics;
			class HitVRotor;
			class HitHRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;
		};
		class AnimationSources;
		class ViewPilot;
		class ViewOptics;
		class components;
		class RotorLibHelicopterProperties;
	};
	class B_Heli_Attack_01_base_F: Heli_Attack_01_base_F
	{
	};
	class FST_HMP_Base: Heli_Attack_01_base_F
	{
		ace_fastroping_enabled=0;
		ace_cargo_hasCargo=0;
		startDuration=4.5;
		gearretracting=0;
		weapons[]=
		{
			"FST_AAT_Side",
			"CMFlareLauncher",
		};
		magazines[]=
		{
			"FST_500Rnd_127x99_mag_red",
			"FST_500Rnd_127x99_mag_red",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
		};
		fuelCapacity=8000;
		fuelConsumptionRate=0.138;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Droid_B1_OOM";
		icon="3AS\3AS_HMP\data\ui\hmp_top_ca.paa";
		availableForSupportTypes[]=
		{
			"CAS_Heli",
			"Drop",
			"Transport",
			"CAS_Bombing"
		};
		cost=2000000;
		armor=300;
		tas_can_impulse=0;
		altFullForce=10000;
		altNoForce=15000;
		maxSpeed=800;
		maxFordingDepth=5;
		incomingMissileDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		LockDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		getInRadius=5;
		hideWeaponsCargo=1;
		cargoCanEject=0;
		isUav=0;
		unloadInCombat=0;
		driverOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
		mainBladeRadius=0;
		liftForceCoef=3;
		bodyFrictionCoef=11;
		cyclicAsideForceCoef=5;
		cyclicForwardForceCoef=3;
		backRotorForceCoef=2;
		draconicForceXCoef=11;
		draconicForceYCoef=2;
		draconicForceZCoef=2;
		draconicTorqueXCoef=0.050000001;
		draconicTorqueYCoef=0;
		unitInfoTypeLite="RscUnitInfoAirRTDBasic";
		unitInfoTypeRTD="RscOptics_AV_pilot";
		accuracy=0.5;
		displayname="[41st] HMP Gunship Base";
		model="3AS\3AS_HMP\3AS_HMP.p3d";
		driverAction="MTT_Cargo";
		driverInAction="MTT_Cargo";
		precisegetinout=1;
		usePreciseGetInAction=1;
		GetInAction="GetInLow";
		GetOutAction="GetOutLow";
		radarType=8;
		extCameraPosition[]={0,3,-23};
		driverforceoptics=1;
		driveOnComponent[]=
		{
			"Skids"
		};
		class Eventhandlers
		{
			init="_this # 0 confirmSensorTarget [west, true];";
		};
		class ViewPilot: ViewPilot
		{
			minFov=0.25;
			maxFov=1.25;
			initFov=0.75;
			initAngleX=0;
			minAngleX=-65;
			maxAngleX=85;
			initAngleY=0;
			minAngleY=-150;
			maxAngleY=150;
		};
		class Viewoptics: ViewOptics
		{
			initAngleX=0;
			minAngleX=0;
			maxAngleX=0;
			initAngleY=0;
			minAngleY=0;
			maxAngleY=0;
			initFov=0.1;
			minFov=0.1;
			maxFov=1.2;
			visionMode[]=
			{
				"Normal",
				"NVG",
				"Ti"
			};
			thermalMode[]={0,1};
		};
		class ls_impulsor: ls_impulsor_base
		{
			enabled=1;
			speed=300;
			fueldrain=0.0001;
			overchargespeed=800;
			overchargeFuelDrain=0.0001;
			overchargeCooldown=0
		};
		class exhausts
		{
		};
		class transportweapons
		{
		};
		class transportmagazines
		{
		};
		class transportItems
		{
		};
		class transportBackpacks
		{
		};
		class Reflectors
		{
			class Left
			{
				color[]={10000,7500,7000};
				ambient[]={100,75,70};
				intensity=50;
				size=1;
				innerAngle=15;
				outerAngle=65;
				coneFadeCoef=10;
				useFlare=1;
				flareSize=10;
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
				position="light_l";
				direction="light_l_end";
				hitpoint="light_l";
				selection="light_l";
			};
			class Right: Left
			{
				position="light_r";
				direction="light_r_end";
				hitpoint="light_r";
				selection="light_r";
			};
		};
		class simpleobject
		{
			animate[]=
			{
				
				{
					"CollisionLightRed1",
					0
				},
				
				{
					"CollisionLightGreen1",
					0
				},
				
				{
					"CollisionLightWhite1",
					0
				},
				
				{
					"CollisionLightWhite2",
					0
				},
				
				{
					"light_l",
					0
				},
				
				{
					"light_r",
					0
				}
			};
			hide[]=
			{
				"light_l",
				"light_r"
			};
			verticaloffset=0;
			verticaloffsetworld=0;
		};
		class AnimationSources: AnimationSources
		{
			class RocketPods
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class DropRack
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		class attributes
		{
		};
		animationlist[]={};
		class HitPoints: HitPoints
		{
			class HitHull
			{
				armor=999;
				convexComponent="hull_hit";
				depends="Total";
				explosionShielding=1;
				material=51;
				name="hull_hit";
				passThrough=1;
				visual="zbytek";
				radius=0.0099999998;
			};
			class HitFuel
			{
				convexcomponent="fuel_hit";
				hitpoint="fuel_hit";
				name="fuel_hit";
				explosionShielding=2;
				radius=0.1;
				visual="";
				passthrough=0.1;
				minimalhit=0.1;
				material=-1;
				armor=0.5;
			};
			class HitEngine
			{
				armor=0.25;
				convexComponent="engine_hit";
				explosionShielding=2;
				material=51;
				name="engine_hit";
				hitpoint="engine_hit";
				passThrough=1;
				visual="";
				radius=0.2;
			};
			class HitHRotor
			{
				armor=3;
				convexComponent="main_rotor_hit";
				explosionShielding=2.5;
				material=51;
				name="main_rotor_hit";
				passThrough=0.1;
				visual="";
				radius=0.0099999998;
			};
			class HitVRotor
			{
				armor=3;
				convexComponent="tail_rotor_hit";
				explosionShielding=6;
				material=51;
				name="tail_rotor_hit";
				passThrough=0.30000001;
				visual="";
				radius=0.0099999998;
			};
			class HitAvionics
			{
				armor=1;
				convexComponent="avionics_hit";
				explosionShielding=2;
				material=51;
				name="avionics_hit";
				passThrough=1;
				visual="";
				radius=0.5;
			};
		};
		class MarkerLights
		{
			class CollisionLightRed1
			{
				color[]={0.80000001,0,0};
				ambient[]={0.079999998,0,0};
				intensity=75;
				name="positionlight_red_1_pos";
				drawLight=1;
				drawLightSize=0.25;
				drawLightCenterSize=0.050000001;
				activeLight=0;
				blinking=0;
				dayLight=0;
				useFlare=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=25;
					quadratic=50;
					hardLimitStart=0.75;
					hardLimitEnd=1;
				};
			};
			class CollisionLightGreen1: CollisionLightRed1
			{
				color[]={0,0.80000001,0};
				ambient[]={0,0.079999998,0};
				name="positionlight_green_1_pos";
			};
			class CollisionLightWhite1: CollisionLightRed1
			{
				color[]={1,1,1};
				ambient[]={0.1,0.1,0.1};
				name="positionlight_white_1_pos";
				blinking=1;
				blinkingStartsOn=1;
				blinkingPattern[]={0.1,0.89999998};
				blinkingPatternGuarantee=1;
				drawLightSize=0.34999999;
				drawLightCenterSize=0.050000001;
			};
			class CollisionLightWhite2: CollisionLightWhite1
			{
				name="positionlight_white_2_pos";
			};
		};
		class Components: components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=500;
							maxRange=3000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=2000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=70;
						animDirection="mainGun";
						angleRangeHorizontal=46;
						angleRangeVertical=34;
						aimdown=-0.25;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=500;
							maxRange=2000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=1500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						maxTrackableSpeed=70;
						animDirection="mainGun";
						angleRangeHorizontal=46;
						angleRangeVertical=34;
						aimdown=-0.25;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=4000;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableSpeed=125;
						angleRangeHorizontal=180;
						angleRangeVertical=90;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						aimDown=30;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
					};
					class NVSensorComponent: SensorTemplateNV
					{
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				class Components: components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,16000,8000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components: components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoAirborneMiniMap";
					};
					class CrewDisplay
					{
						componentType="CrewDisplayComponent";
						resource="RscCustomInfoCrew";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
					};
					class VehiclePrimaryGunnerDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="PrimaryGunner";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,2000,16000,8000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportCounterMeasuresComponent;
		};
		soundEngineOnInt[]=
		{
			"3as\3AS_laat\sounds\LAAT_Start.ogg",
			"volume_sound/2",
			1
		};
		soundEngineOnExt[]=
		{
			"3as\3AS_laat\sounds\LAAT_Start.ogg",
			"volume_sound*1.5",
			1,
			300
		};
		soundEngineOffInt[]=
		{
			"3as\3AS_laat\sounds\LAAT_End.ogg",
			"volume_sound/2",
			1
		};
		soundEngineOffExt[]=
		{
			"3as\3AS_laat\sounds\LAAT_End.ogg",
			"volume_sound*1.5",
			1,
			300
		};
		class sounds
		{
			class EngineInt
			{
				sound[]=
				{
					"3AS\3as_HMP\SFX\HMP_Engine1.ogg",
					1.25893,
					1
				};
				frequency="rotorSpeed*(1+rotorThrust/6)*0.8";
				volume="2 * (1-camPos)*(rotorSpeed factor[0.4,1])";
			};
			class EngineExt
			{
				sound[]=
				{
					"3AS\3as_HMP\SFX\HMP_Engine1.ogg",
					2.5,
					1,
					1200
				};
				frequency="rotorSpeed*(1+rotorThrust/6)*0.8";
				volume="camPos*((rotorSpeed-0.72)*4)";
			};
			class RainExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_ext",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (rain - rotorSpeed/2) * 2";
			};
			class RainInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_int_open",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos)*(rain - rotorSpeed/2)*2";
			};
			class SlingLoadDownExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
					1.25893,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
					1.25893,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,1])";
			};
			class SlingLoadDownInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
					1,
					1,
					700
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
					1,
					1,
					700
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,1])";
			};
			class WindInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wind_closed",
					"db-7",
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[5, 60])*(speed factor[5, 60])";
			};
			class GStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress2b",
					0.316228,
					1,
					50
				};
				frequency=1;
				volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
			};
			class rotorLowAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.316228,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class rotorLowAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.22387201,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class scrubLandInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubLandInt_open",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05])";
			};
			class scrubLandExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubLandExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubLand factor[0.02, 0.05])";
			};
			class scrubBuildingInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubBuildingInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1 - camPos) * (scrubBuilding factor[0.02, 0.05])";
			};
			class scrubBuildingExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubBuildingExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubBuilding factor[0.02, 0.05])";
			};
			class scrubTreeInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1 - camPos) * ((scrubTree) factor [0, 0.01])";
			};
			class scrubTreeExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * ((scrubTree) factor [0, 0.01])";
			};
		};
		memoryPointsGetInDriver="pos_cargo";
		memoryPointsGetInDriverDir="pos_cargo_dir";
		memoryPointsGetInCargo="pos_cargo";
		memoryPointsGetInCargoDir="pos_cargo_dir";
		memoryPointsGetInGunner="pos_cargo";
		memoryPointsGetInGunnerDir="pos_cargo_dir";
		memoryPointsGetInCargoPrecise[]=
		{
			"pos_cargo"
		};
		memoryPointTaskMarker="TaskMarker_1_pos";
		memoryPointDriverOptics="driver_view";
		memorypointLRocket="rocketl";
		memorypointRRocket="rocketr";
		memorypointLmissile="rocketl";
		memorypointRmissile="rocketR";
		memorypointcm[]=
		{
			"flare_launcher",
			"flare_launcher2"
		};
		memorypointcmdir[]=
		{
			"flare_launcher_dir",
			"flare_launcher2_dir"
		};
		gunBeg[]=
		{
			"L_W_C",
			"R_W_M"
		};
		gunEnd[]=
		{
			"L_W_M",
			"R_W_C"
		};
		memoryPointGun[]=
		{
			"L_W_M",
			"R_W_C"
		};
		class Turrets: Turrets
		{
			class Copilot: MainTurret
			{
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunnerforceoptics=0;
				gunnername="Center Gun";
				usePiP=1;
				gunnerAction="MTT_Cargo";
				gunnerInAction="MTT_Cargo";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				iscopilot=0;
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				memoryPointGunnerOutOptics="gunnerviewout";
				memoryPointGunnerOptics="gunner_view";
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				minElev=-15;
				maxElev=45;
				minTurn=-40;
				maxTurn=40;
				initElev=0;
				initTurn=0;
				minCamElev=-10;
				maxCamElev=-45;
				selectionfireanim="zasleh";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.36234099,
					1,
					20
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.36234099,
					1,
					30
				};
				startengine=0;
				animationSourceBody="CenterTurret";
				animationSourceGun="CenterGun";
				body="CenterTurret";
				gun="CenterGun";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_AAT_Side"
				};
				magazines[]=
				{
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red"
				};
				gunBeg="C_C";
				gunEnd="C_M";
				memoryPointGun="C_M";
				class OpticsIn
				{
					class Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
						initanglex=0;
						initangley=0;
						initfov=0.46599999;
						maxanglex=30;
						maxangley=100;
						maxfov=0.46599999;
						minanglex=-30;
						minangley=-100;
						minfov=0.46599999;
						opticsdisplayname="W";
						thermalmode[]={0,1};
						visionmode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
					};
					class Medium: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initfov=0.093000002;
						maxfov=0.093000002;
						minfov=0.093000002;
						opticsdisplayname="M";
					};
					class Narrow: Wide
					{
						gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
						initfov=0.028999999;
						maxfov=0.028999999;
						minfov=0.028999999;
						opticsdisplayname="N";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						gunneropticseffect[]={};
						gunneropticsmodel="";
						initanglex=0;
						initangley=0;
						initfov=1.1;
						maxanglex=30;
						maxangley=100;
						maxfov=1.1;
						minanglex=-30;
						minangley=-100;
						minfov=0.133;
						visionmode[]=
						{
							"Normal",
							"NVG"
						};
					};
				};
				class HitTurret
				{
					armor=0.80000001;
					material=-1;
					name="gun1";
					passthrough=0.5;
					visual="gun1";
				};
				class HitGun
				{
					armor=0.40000001;
					material=-1;
					name="gun2";
					passthrough=0.2;
					visual="gun2";
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						class Components: components
						{
							class VehiclePrimaryGunnerDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="PrimaryGunner";
							};
							class VehicleMissileDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Missile";
							};
							class SensorDisplay
							{
								range[]={4000,2000,16000,8000};
								componentType="SensorsDisplayComponent";
								resource="RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						class Components: components
						{
							class VehiclePrimaryGunnerDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="PrimaryGunner";
							};
							class VehicleMissileDisplay
							{
								componentType="TransportFeedDisplayComponent";
								source="Missile";
							};
							class SensorDisplay
							{
								range[]={4000,2000,16000,8000};
								componentType="SensorsDisplayComponent";
								resource="RscCustomInfoSensors";
							};
						};
						defaultDisplay="SensorDisplay";
					};
				};
			};
			class LeftGun: MainTurret
			{
				weapons[]=
				{
					"FST_AAT_Side"
				};
				magazines[]=
				{
					"FST_500Rnd_127x99_mag_red",
					"FST_500Rnd_127x99_mag_red"
				};
				minElev=-80;
				maxElev=80;
				minTurn=-20;
				maxTurn=120;
				initElev=0;
				initTurn=45;
				minCamElev=-10;
				maxCamElev=-45;
				animationSourceBody="LeftTurret";
				animationSourceGun="LeftGun";
				body="LeftTurret";
				gun="LeftGun";
				castgunnershadow=1;
				commanding=-2;
				gunBeg[]=
				{
					"L_M_1",
					"L_M_2"
				};
				gunEnd[]=
				{
					"L_C_1",
					"L_C_2"
				};
				memoryPointGun[]=
				{
					"L_C_1",
					"L_C_2"
				};
				gunneraction="MTT_Cargo";
				gunnercompartments="Compartment8";
				gunnerdoor="";
				gunnerforceoptics=0;
				gunnerinaction="gunner_Heli_Transport_01";
				gunnerlefthandanimname="";
				gunnername="Left turret";
				gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				gunneropticsshowcursor=1;
				gunneroutopticsshowcursor=1;
				gunnerrighthandanimname="";
				iscopilot=0;
				lodturnedin=1000;
				lodturnedout=1000;
				memoryPointGunnerOptics="gunner_left_view";
				memorypointsgetingunner="pos_cargo_dir";
				memorypointsgetingunnerdir="pos_cargo";
				primarygunner=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.36234099,
					1,
					20
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.36234099,
					1,
					30
				};
				stabilizedinaxes=0;
				viewgunnershadow=1;
			};
			class RightDoorGun: LeftGun
			{
				gunnerName="Right Gun";
				minElev=-80;
				maxElev=80;
				minTurn=-120;
				maxTurn=20;
				initElev=0;
				initTurn=-45;
				minCamElev=-10;
				maxCamElev=-45;
				memoryPointGunnerOptics="gunner_right_view";
				gunBeg[]=
				{
					"R_M_1",
					"R_M_2"
				};
				gunEnd[]=
				{
					"R_C_1",
					"R_C_2"
				};
				memoryPointGun[]=
				{
					"R_M_1",
					"R_M_2"
				};
				animationSourceBody="RightTurret";
				animationSourceGun="RightGun";
				gun="RightGun";
				body="RightTurret";
				isCopilot=0;
				inGunnerMayFire=1;
				gunnerFireAlsoInInternalCamera=1;
				gunnerlefthandanimname="";
				gunnerrighthandanimname="";
				gunnerLeftLegAnimName="";
				gunnerRightLegAnimName="";
				stabilizedInAxes=3;
				selectionFireAnim="";
				commanding=-5;
				primaryObserver=0;
				primaryGunner=0;
				turretFollowFreeLook=0;
				isPersonTurret=0;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner",
					0.36234099,
					1,
					20
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_armor_gunner_vertical",
					0.36234099,
					1,
					30
				};
				gunneropticsmodel="\A3\weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				gunnerOutOpticsShowCursor=1;
				gunnerOpticsShowCursor=1;
				gunnerCompartments="Compartment9";
			};
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3AS\3AS_HMP\data\body.rvmat",
				"A3\Air_F_Beta\Heli_Attack_01\Data\Heli_Attack_01_base_destruct.rvmat",
				"3AS\3AS_HMP\data\Drop_Rack.rvmat",
				"A3\Air_F_Beta\Heli_Attack_01\Data\Heli_Attack_01_base_destruct.rvmat",
				"3AS\3AS_HMP\data\rocket_pods.rvmat",
				"A3\Air_F_Beta\Heli_Attack_01\Data\Heli_Attack_01_base_destruct.rvmat"
			};
		};
	};
	class FST_HMP_Gunship: FST_HMP_Base
	{
		author="Daara";
		displayname="[41st] HMP Gunship";
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		weapons[]=
		{
			"FST_AAT_Side",
			"CMFlareLauncher",
			"FST_Rapture_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"ls_weapon_CMFlareLauncher",
		};
		magazines[]=
		{
			"FST_500Rnd_127x99_mag_red",
			"FST_500Rnd_127x99_mag_red",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
		};
		class textureSources
		{
		};
	};
	class FST_HMP_Transport: FST_HMP_Base
	{
		author="Daara";
		displayname="[41st] HMP (Transport)";
		scope=2;
		scopegarage=2;
		scopecurator=2;
		scopearsenal=2;
		transportSoldier=12;
		tas_canLift=1;
		geardowntime=1.5;
		gearretracting=0;
		gearuptime=1.5;
		gearMinAlt=0;
		gearsUpFrictionCoef=0.001;
		maximumLoad=50000;
		class VehicleTransport
		{
			class Carrier
			{
				cargoBayDimensions[]=
				{
					"Limit1",
					"limit2"
				};
				disableHeightLimit=1;
				maxLoadMass=2000000;
				cargoAlignment[]=
				{
					"center",
					"front"
				};
				cargoSpacing[]={0,0.15000001,0};
				exits[]=
				{
					"exit"
				};
				unloadingInterval=2;
				loadingDistance=10;
				loadingAngle=60;
				parachuteClassDefault="B_Parachute_02_F";
				parachuteHeightLimitDefault=50;
			};
		};
		cargoAction[]=
		{
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo",
			"MTT_Cargo"
		};
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		cargoProxyIndexes[]={1,2,3,4,5,6,7,8,9,10,11,12};
		class AnimationSources: AnimationSources
		{
			class RocketPods
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class DropRack
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
		};
		class textureSources
		{
		};
	};
};
class CfgNonAIVehicles
{
	class ProxyWeapon;
	class ProxyHMP_1x_Pylon: ProxyWeapon
	{
		model="3AS\3AS_hmp\HMP_1x_Pylon.p3d";
		simulation="PylonPod";
	};
};
