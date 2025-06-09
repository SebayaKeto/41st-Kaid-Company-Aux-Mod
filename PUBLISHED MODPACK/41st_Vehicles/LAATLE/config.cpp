class CfgPatches
{
	class FST_LAAT_LE
	{
		author="Daara";
		requiredaddons[]=
		{
		};
		requiredversion=1;
		units[]=
		{
			"FST_LAAT_LE"
		};
		weapons[]={};
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
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class ls_impulsor_base;
class CfgVehicles
{
	class 3AS_Patrol_LAAT_Base;
	class FST_LAAT_LE: 3AS_Patrol_LAAT_Base
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/le Light Partol Craft";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		model="3AS\3as_LAAT\LAAT_LE\LAAT_LE.p3d";
		icon="3AS\3as_LAAT\LAAT_LE\data\ui\LAATLE_top_ca.paa";
		picture="3AS\3as_Laat\LAATI\data\ui\LAAT_Profile_ca.paa";
		editorpreview="\3AS\3as_Laat\LAATI\data\editorpreview\3as_laat.jpg";
		author="Daara";
		armor=400;
		fuelConsumptionRate=0.1;
		smokeLauncherGrenadeCount=18;
		smokeLauncherVelocity=8;
		smokeLauncherOnTurret=0;
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000;
		fuelCapacity=8000;
		tas_canBlift=1;
        tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]"; 
		tas_can_impulse=0;	
		maxFordingDepth=5;
		incomingMissileDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		LockDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		accuracy=0.5;
		geardowntime=1.5;
		gearretracting=1;
		gearuptime=1.5;
		gearMinAlt=0;
		gearsUpFrictionCoef=0.001;
		nameSound="veh_helicopter_s";
		mainBladeRadius=0.1;
		liftForceCoef=3;
		bodyFrictionCoef=1.9845001;
		cyclicAsideForceCoef=2.8;
		backRotorForceCoef=1.8;
		cyclicForwardForceCoef=2;
		acceleration=600;
		maxSpeed=600;
		brakeDistance=200;
		mainRotorSpeed=-1;
		backRotorSpeed=1;
		maxMainRotorDive=7;
		minMainRotorDive=-7;
		neutralMainRotorDive=0;
		driveOnComponent[]=
		{
			"Skids"
		};
		class RotorLibHelicopterProperties
		{
			RTDconfig="A3\Air_F_Beta\Heli_Attack_02\RTD_Heli_Attack_02.xml";
			autoHoverCorrection[]={3.2,0,0};
			defaultCollective=0.80500001;
			retreatBladeStallWarningSpeed=83;
			maxTorque=6500;
			stressDamagePerSec=0.0099999998;
			maxHorizontalStabilizerLeftStress=8000;
			maxHorizontalStabilizerRightStress=8000;
			maxVerticalStabilizerStress=4000;
			horizontalWingsAngleCollMin=0;
			horizontalWingsAngleCollMax=0;
			maxMainRotorStress=225000;
			maxTailRotorStress=225000;
		};
		startDuration=2.5;
		castDriverShadow=0;
		canFloat=1;
		waterLeakiness=0.2;
		waterResistanceCoef=0.89999998;
		waterResistance=1;
		waterLinearDampingCoefY=3;
		waterLinearDampingCoefX=2;
		waterAngularDampingCoef=3;
		armorStructural=1;
		altFullForce=137400;
		altNoForce=172400;
		crewCrashProtection=1;
		explosionShielding=0.33000001;
		epeImpulseDamageCoef=0;
		slingLoadMaxCargoMass=5000000;
		preciseGetInOut=0;
		cargoPreciseGetInOut[]={0};
		driverAction="LE_Pilot";
		getInAction="ChopperLight_L_In_H";
		getOutAction="GetOutLow";
		memoryPointsGetInCargo[]=
		{
			"pos_cargo"
		};
		memoryPointsGetInCargoDir[]=
		{
			"pos_cargo_dir"
		};
		usePreciseGetInAction=0;
		memoryPointsGetInDriverPrecise="pos_driver";
		memorypointsgetindriver="pos_driver";
		memorypointsgetindriverdir="pos_driver_dir";
		memoryPointsGetInCargoPrecise[]=
		{
			"GetIn_Cargo",
			"GetIn_Cargo2"
		};
		cargoGetInAction[]=
		{
			"GetInLow"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		getInRadius=10;
		typicalCargo[]=
		{
			"B_HeliPilot_F"
		};
		memorypointlmissile="Rocket_1";
		memorypointrmissile="Rocket_2";
		memoryPointLRocket="Rocket_1";
		memoryPointRRocket="Rocket_2";
		weapons[]=
		{
			"Laserdesignator_pilotCamera",
			"FST_30mm_Autocannon_LAAT",
			"CMFlareLauncher",
			"FST_Stormfury_AA_Missile",
        };
		magazines[]=
		{
			"FST_Thermal_Coil",
			"Laser_Battery",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"Laserbatteries",
			"FST_Stormfury_12Rnd_AA_Missile",
		};
		hiddenSelections[]=
		{
			"camo"
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\LAATLE\Data\41st_patrol01_CO.paa"
		};
		cargoaction[]=
		{
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Left",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right",
			"RTT_Cargo_Right"
		};
		class ls_impulsor: ls_impulsor_base
		{
			enabled=1;
			speed=300;
			fueldrain=0.0001;
			overchargespeed=600;
			overchargeFuelDrain=0.0001;
			overchargeCooldown=0
		};
		class components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=6000;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=6000;
							maxRange=6000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=180;
						angleRangeVertical=180;
						maxTrackableSpeed=400;
						componentType="IRSensorComponent";
						typeRecognitionDistance=2000;
						maxFogSeeThrough=0.995;
						color[]={1,0,0,1};
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class VisualSensorComponent: SensorTemplateVisual
					{
						class AirTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=100;
						aimDown=1;
						animDirection="";
						componentType="VisualSensorComponent";
						nightRangeCoef=0;
						maxFogSeeThrough=0.94;
						color[]={1,1,0.5,0.80000001};
						typeRecognitionDistance=2000;
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						minTrackableSpeed=-1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						componentType="PassiveRadarSensorComponent";
						class AirTarget
						{
							minRange=20000;
							maxRange=20000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=20000;
							maxRange=20000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						color[]={0.5,1,0.5,0.5};
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
						allowsMarking=0;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=10000;
							maxRange=10000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=8000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=0.2;
						componentType="ActiveRadarSensorComponent";
						maxGroundNoiseDistance=200;
						minSpeedThreshold=30;
						maxSpeedThreshold=40;
						color[]={0,1,1,1};
						allowsMarking=1;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class LaserSensorComponent: SensorTemplateLaser
					{
						componentType="LaserSensorComponent";
						class AirTarget
						{
							minRange=6000;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=6000;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=180;
						angleRangeVertical=180;
						typeRecognitionDistance=0;
						color[]={1,1,1,0};
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
					class NVSensorComponent: SensorTemplateNV
					{
						componentType="NVSensorComponent";
						color[]={1,1,1,0};
						typeRecognitionDistance=0;
						class AirTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=8000;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						angleRangeHorizontal=90;
						angleRangeVertical=90;
						allowsMarking=1;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
			{
				defaultDisplay="EmptyDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,6000,8000,12000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
			{
				defaultDisplay="SensorDisplay";
				class Components
				{
					class EmptyDisplay
					{
						componentType="EmptyDisplayComponent";
					};
					class MinimapDisplay
					{
						componentType="MinimapDisplayComponent";
						resource="RscCustomInfoMiniMap";
					};
					class VehicleDriverDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Driver";
					};
					class VehicleMissileDisplay
					{
						componentType="TransportFeedDisplayComponent";
						source="Missile";
					};
					class SensorDisplay
					{
						componentType="SensorsDisplayComponent";
						range[]={4000,6000,8000,12000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				uiPicture="lsd_vehicles_heli\laati\data\ui\laat_icon.paa";
				class Pylons
				{
					class PylonLeft1
					{
						attachment="PylonRack_Missile_AMRAAM_D_x1";
						priority=5;
						hardpoints[]=
						{
							"SCALPEL_1RND",
							"B_ASRAAM",
							"DAR",
							"DAGR",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_SDB_QUAD_RAIL",
							"B_GBU12",
							"B_AGM65_RAIL"
						};
						turret[]={0};
						UIposition[]={0.059999999,0.40000001};
					};
					class PylonRight1: PylonLeft1
					{
						mirroredMissilePos=1;
						UIposition[]={0.63999999,0.40000001};
					};
				};
			};
			class TransportCounterMeasuresComponent
			{
				class pilotCamera
				{	
					class OpticsIn
					{
						class Wide
						{
							opticsDisplayName="WFOV";
							initAngleX=0;
							minAngleX=0;
							maxAngleX=0;
							initAngleY=0;
							minAngleY=0;
							maxAngleY=0;
							initFov="(75 / 120)";
							minFov="(75 / 120)";
							maxFov="(75 / 120)";
							directionStabilized=1;
							thermalMode[]={0,1};
							visionMode[]=
							{
								"Normal",
								"NVG",
								"Ti"
							};
							gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
							opticsPPEffects[]=
							{
								"OpticsCHAbera2",
								"OpticsBlur2"
							};
						};
						class Medium: Wide
						{
							opticsDisplayName="MFOV";
							initFov="(14.4 / 120)";
							minFov="(14.4 / 120)";
							maxFov="(14.4 / 120)";
							gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
						};
						class Narrow: Wide
						{
							opticsDisplayName="NFOV";
							initFov="(4.8 / 120)";
							minFov="(4.8 / 120)";
							maxFov="(4.8 / 120)";
							gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
						};
						showMiniMapInOptics=1;
						showUAVViewInOptics=0;
						showSlingLoadManagerInOptics=0;
					};
					minTurn=-180;
					maxTurn=180;
					initTurn=0;
					minElev=-10;
					maxElev=90;
					initElev=-10;
					maxXRotSpeed=0.30000001;
					maxYRotSpeed=0.30000001;
					pilotOpticsShowCursor=1;
					controllable=1;
					ace_missileguidance_usePilotCameraForTargeting=0;
				};	
			};
		};
		class UserActions
		{
			class impulse
			{
				displayName="Impulse";
				position="pilotview";
				radius=5;
				onlyforplayer=0;
				shortcut="User19";
				condition="isEngineOn this and player == currentPilot this;";
				statement="this call ls_vehicle_fnc_ImpulseJoystick;";
			};
			class repulse: impulse
			{
				displayName="Repulse";
				shortcut="User20";
				condition="isEngineOn this and player == currentPilot this;";
				statement="this call ls_vehicle_fnc_RepulseJoystick;";
			};
			class beacons_start
            {
                displayName="$STR_A3_CfgVehicles_beacons_on";
                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\beacons_ON_ca.paa' size='2.5' />";
                position="pilotview";
                available=0;
                showWindow=0;
                radius=9;
                onlyForplayer=0;
                condition="(ace_player == driver this) AND {this animationSourcePhase 'Beacons' < 0.5}";
                statement="this animateSource ['Beacons',1];";
            };
            class beacons_stop: beacons_start
            {
                displayName="$STR_A3_CfgVehicles_beacons_off";
                displayNameDefault="<img image='\A3\Ui_f\data\IGUI\Cfg\Actions\beacons_OFF_ca.paa' size='2.5' />";
                condition="(ace_player == driver this) AND {this animationSourcePhase 'Beacons' > 0.5}";
                statement="this animateSource ['Beacons',0];";
            };
            class LeftDoor_Open
            {
                available=0;
                showWindow=0;
                displayName="Left Door Open";
                position="pilotview";
                radius=9;
                condition="(ace_player == driver this) && (this animationSourcePhase 'Door_L' == 0)";
                statement="this animateSource ['Door_L',1];";
                onlyforplayer=0;
            };
            class LeftDoor_Close
            {
                available=0;
                showWindow=0;
                displayName="Left Door Close";
                position="pilotview";
                radius=9;
                condition="(ace_player == driver this) && (this animationSourcePhase 'Door_L' == 1)";
                statement="this animateSource ['Door_L',0];";
                onlyforplayer=0;
            };
            class RightDoor_Open
            {
                available=0;
                showWindow=0;
                displayName="Right Door Open";
                position="pilotview";
                radius=9;
                condition="(ace_player == driver this) && (this animationSourcePhase 'Door_R' == 0)";
                statement="this animateSource ['Door_R',1];";
                onlyforplayer=0;
            };
            class RightDoor_Close
            {
                available=0;
                showWindow=0;
                displayName="Right Door Close";
                position="pilotview";
                radius=9;
                condition="(ace_player == driver this) && (this animationSourcePhase 'Door_R' == 1)";
                statement="this animateSource ['Door_R',0];";
                onlyforplayer=0;
            };
		};
	};
};