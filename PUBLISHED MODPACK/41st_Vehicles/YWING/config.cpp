class CfgPatches
{
	class FST_SHB_Bomber
	{
		units[]=
		{
			"FST_SHB_Bomber"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder"
		};
		author="$STR_3AS_Studio";
	};
};
class Extended_init_EventHandlers
{
	class FST_SHB_Bomber
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
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
class CfgVehicles
{
	class Air;
	class Plane: Air
	{
		class HitPoints;
		class NewTurret;
	};
	class Plane_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class Components;
		class Eventhandlers;
		class ViewPilot;
		class ACE_selfActions;
	};
	class Plane_Fighter_03_base_F: Plane_Base_F
	{
		class Turrets
		{
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
			};
			class HitEngine: HitHull
			{
			};
			class HitAvionics: HitHull
			{
			};
			class HitFuel: HitHull
			{
			};
			class HitLAileron: HitHull
			{
			};
			class HitRAileron: HitLAileron
			{
			};
			class HitLCRudder: HitHull
			{
			};
			class HitLCElevator: HitHull
			{
			};
			class HitRElevator: HitHull
			{
			};
		};
		class AnimationSources: AnimationSources
		{
		};
		class Components: Components
		{
		};
		class UserActions;
	};
	class Plane_Fighter_03_dynamicLoadout_base_F: Plane_Fighter_03_base_F
	{
		class Components: Components
		{
			class TransportPylonsComponent;
		};
	};
	class BTL_Base: Plane_Fighter_03_dynamicLoadout_base_F
	{
	};
	class 3AS_BTLB_Bomber: BTL_Base
	{
	};
	class FST_SHB_Bomber: 3AS_BTLB_Bomber
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		vtol=4;
		author="Ghostly";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		displayName="[41st] BTL-Y Wing Strategic Bomber";
		model="3as\3AS_BTLB\3AS_BTLB_Bomber.p3d";
		icon="3AS\3AS_BTLB\data\ui\BTLB_top_ca.paa";
		picture="A3\Air_F_Gamma\Plane_Fighter_03\Data\UI\Plane_Fighter_03_CA.paa";
		ls_impulsor_fuelDrain_1=9.9999997e-005;
		ls_impulsor_fuelDrain_2=9.9999997e-005;
		ls_impulsor_boostSpeed_1=400;
		ls_impulsor_boostSpeed_2=800;
		tas_impulse_break=100;
		ls_hasImpulse=1;
		tas_can_impulse=0;
		ace_cargo_space=1000;
		ace_cargo_hasCargo=1;
		selectionFireAnim="zasleh";
		simulation="airplaneX";
		armor=400;
		acceleration=800;
		maxSpeed=1000;
		airBrake=90;
		airBrakeFrictionCoef=40;
		fuelConsumptionRate=0.2;
		fuelCapacity=8000;
		laserScanner=1;
		driverCanEject=1;
		showAllTargets=4;
		showCrewAim=0;
		radarType=8;
		radarTargetSize=1.0;
		visualTargetSize=1.0;
		irTargetSize=1.0;
		irTarget=1;
		radarTarget=1;
		lockDetectionSystem="2 + 8 + 4 + 16";
		incomingMissileDetectionSystem="2 + 8 + 4";
		incommingmissliedetectionsystem=16;
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\YWING\Data\FST_BTLB_Body.paa",
			"3as\3AS_btlb\data\detail_co.paa",
			"3as\3AS_btlb\data\interior_co.paa"
		};
		memoryPointGun[]=
		{
			"Konec hlavne L",
			"Konec hlavne R"
		};
		weapons[]=
		{
			"FST_30mm_Autocannon_YWing",
			"FST_Rapture_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"ls_weapon_CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"FST_thermal_Y_Wing",
			"FST_thermal_Y_Wing",
			"FST_thermal_Y_Wing",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"Laserbatteries",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile"
		};
		memoryPointCM[]=
		{
			"flare_launcher1",
			"flare_launcher2"
		};
		memoryPointCMDir[]=
		{
			"flare_launcher1_dir",
			"flare_launcher2_dir"
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=4;
				explosionShielding=3;
				name="HitHull";
				passThrough=1;
				visual="Hit_Hull";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="0";
				material=-1;
			};
			class HitEngine: HitHull
			{
				armor=3;
				explosionShielding=4;
				name="HitEngine";
				passThrough=1;
				visual="Hit_Engine";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="0";
			};
			class HitFuel: HitHull
			{
				armor=4.5;
				explosionShielding=4;
				name="HitFuel";
				passThrough=0.80000001;
				visual="";
				radius=0.30000001;
				minimalHit=0.1;
				depends="0";
			};
			class HitLAileron: HitHull
			{
				armor=1.5;
				explosionShielding=3;
				name="HitLAileron";
				passThrough=0.30000001;
				visual="Hit_AileronL";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="HitLAileron_Link";
			};
			class HitRAileron: HitLAileron
			{
				armor=1.5;
				explosionShielding=3;
				name="HitRAileron";
				passThrough=0.30000001;
				visual="Hit_AileronR";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="HitRAileron_Link";
			};
			class HitLCRudder: HitHull
			{
				armor=2;
				explosionShielding=3;
				name="HitLCRudder";
				passThrough=0.30000001;
				visual="Hit_RudderC";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="0";
			};
			class HitLCElevator: HitHull
			{
				armor=1.5;
				explosionShielding=3;
				name="HitLCElevator";
				passThrough=0.30000001;
				visual="Hit_ElevatorL";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="0";
			};
			class HitRElevator: HitHull
			{
				armor=1.5;
				explosionShielding=3;
				name="HitRElevator";
				passThrough=0.30000001;
				visual="Hit_ElevatorR";
				radius=0.30000001;
				minimalHit=0.050000001;
				depends="0";
			};
		};
		htMin=60;
		htMax=1800;
		afMax=200;
		mfMax=100;
		mFact=0;
		tBody=0;
		landingAoa="6 * 3.1415 / 180";
		landingSpeed=215;
		stallSpeed=50;
		stallWarningTreshold=0.1;
		armorStructured=1;
		draconicTorqueYCoef[]={0,1.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		draconicForceYCoef=6;
		envelope[]={0.1,0.19,0.28999999,1.6,1.9,2.5899999,4,5.3000002,6.9099998,8.75,9.8000002,9.5,9.3999996,8.6000004,8.1999998,8};
		draconicForceXCoef=6;
		draconicForceZCoef=6.5;
		draconicTorqueXCoef=2.0999999;
		angleOfIndicence=0.079999998;
		airFriction0[]={75,50,12};
		airFriction1[]={75,50,12};
		airFriction2[]={75,50,12};
		altNoForce=13000;
		altFullForce=10000;
		elevatorCoef[]={0.2,0.38999999,0.50999999,0.60000002,0.68000001,0.75,0.80000001,0.85000002,0.89999998,0.74000001,0.30000001};
		elevatorSensitivity=0.89999998;
		elevatorControlsSensitivityCoef=4;
		aileronCoef[]={0.5,0.69999999,1,1,1.2,1.15,1.1};
		aileronSensitivity=2;
		aileronControlsSensitivityCoef=3;
		rudderCoef[]={1.6,2,2,2.9000001,2.8,2,1};
		rudderInfluence=0.89999998;
		rudderControlsSensitivityCoef=6;
		thrustCoef[]={1.8,1.9,1.95,2,2.5,3,3.5,2.5,2,1.7,1.5,1.1,1,1,1};
		irScanRangeMin=10;
		irScanRangeMax=10000;
		irScanToEyeFactor=8;
		wheelSteeringSensitivity=1.5;
		maxOmega=2000;
		flaps=1;
		flapsFrictionCoef=0.31999999;
		gearsUpFrictionCoef=0.60000002;
		airFrictionCoefs0[]={0,0,0};
		airFrictionCoefs1[]={0.1,0.5,0.0066};
		airFrictionCoefs2[]={0.001,0.0049999999,6.8000001e-005};
		cost=10000000;
		type="VAir";
		threat[]={0.2,0.69999999,0.89999998};
		VTOLPitchInfluence=1;
		VTOLRollInfluence=10;
		VTOLYawInfluence=12;
		explosionShielding=5.25;
		class camShakeGForce
		{
			power=1;
			frequency=20;
			distance=0;
			minSpeed=1;
		};
		minGForce=0.30000001;
		maxGForce=10;
		gForceShakeAttenuation=0.5;
		driveoncomponent[]={};
		camouflage=8;
		audible=10;
		accuracy=0.2;
		class Turrets
		{
			class BubbleGun: NewTurret
			{
				isCopilot=0;
				canEject=1;
				startEngine=0;
				minElev=-5;
				maxElev=80;
				initElev=0;
				minTurn=-180;
				maxTurn=180;
				initTurn=0;
				class OpticsIn
				{
					class Wide
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.46599999;
						minFov=0.46599999;
						maxFov=0.46599999;
						opticsDisplayName="W";
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
					};
					class Medium: Wide
					{
						initFov=0.093000002;
						minFov=0.093000002;
						maxFov=0.093000002;
						opticsDisplayName="M";
						gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
					};
					class Narrow: Wide
					{
						initFov=0.028999999;
						minFov=0.028999999;
						maxFov=0.028999999;
						opticsDisplayName="N";
						gunnerOpticsModel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						minFov=0.25;
						maxFov=1.25;
						initFov=0.75;
						visionMode[]=
						{
							"Normal",
							"NVG"
						};
						gunnerOpticsModel="";
						gunnerOpticsEffect[]={};
					};
				};
				soundServo[]=
				{
					"",
					0.0099999998,
					1
				};
				outGunnerMayFire=1;
				commanding=-1;
				primaryGunner=1;
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerinaction="gunner_apctracked1aa_in";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				memorypointgunneroptics="gunnerview";
				memorypointsgetingunner="pos gunner";
				memorypointsgetingunnerdir="pos gunner dir";
				stabilizedInAxes=3;
				gunnerforceoptics=0;
				gunnerName="Bubble Gunner";
				proxytype="CPGunner";
				proxyIndex=1;
				gunnerLeftHandAnimName="lever_copilot";
				gunnerRightHandAnimName="stick_copilot";
				gunnerLeftLegAnimName="";
				gunnerRightLegAnimName="";
				animationsourcebody="MainTurret";
				animationsourcegun="Maingun";
				animationsourcehatch="";
				body="MainTurret";
				gun="Maingun";
				memoryPointGun[]=
				{
					"Konec hlavne C1",
					"Konec hlavne C2"
				};
				selectionFireAnim="zaslehTurret";
				castGunnerShadow=1;
				viewGunnerShadow=1;
				precisegetinout=0;
				turretInfoType="RscOptics_Heli_Attack_01_gunner";
				discreteDistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discreteDistanceInitIndex=5;
				weapons[]=
				{
					"FST_LAAT_Ball_Turret"
				};
				magazines[]=
				{
					"FST_LAAT_350_Laser_Round",
					"FST_LAAT_350_Laser_Round",
					"FST_LAAT_350_Laser_Round",
					"FST_LAAT_350_Laser_Round"
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="FST_30mm_Autocannon_YWing";
			};
			class Muzzle_Flash2
			{
				source="ammorandom";
				weapon="FST_30mm_Autocannon_YWing";
			};
		};
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
					initFov="(30 / 120)";
					minFov="(30 / 120)";
					maxFov="(30 / 120)";
					directionStabilized=1;
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				};
				class Medium: Wide
				{
					opticsDisplayName="MFOV";
					initFov="(6 / 120)";
					minFov="(6 / 120)";
					maxFov="(6 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName="NFOV";
					initFov="(2 / 120)";
					minFov="(2 / 120)";
					maxFov="(2 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
			driverForceOptics=0;
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			minElev=-180;
			maxElev=180;
			initElev=0;
			maxXRotSpeed=1;
			maxYRotSpeed=1;
            maxMouseXRotSpeed=0.5;
            maxMouseYRotSpeed=0.5;
            pilotOpticsShowCursor=1;
            controllable=1;
        };
        class components
        {
            class TransportCountermeasuresComponent //////////// WHAT WAS ADDED
            {};                                     //////////// WHAT WAS ADDED
            class SensorsManagerComponent
            {
                class Components
                {
                    class IRSensorComponent: SensorTemplateIR
                    {
                        class AirTarget
                        {
                            minRange=8000;
                            maxRange=8000;
                            objectDistanceLimitCoef=-1;
                            viewDistanceLimitCoef=
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
						angleRangeHorizontal=360;
						angleRangeVertical=360;
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
						angleRangeHorizontal=360;
						angleRangeVertical=360;
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
				UIPicture="3as\3AS_arc170\data\plane_arc_pylon_ca.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"B_BIM9X_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"B_HARM_RAIL",
							"ARC_AGM_PYLON",
							"B_BOMB_PYLON",
							"ARC_EMP_RAIL"
						};
						attachment="PylonMissile_1Rnd_Bomb_04_F";
						priority=10;
						maxweight=5000;
						UIposition[]={0.5,0.25};
					};
					class pylons2: pylons1
					{
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=1;
					};
					class pylons3: pylons1
					{
						attachment="PylonMissile_1Rnd_Bomb_04_F";
						priority=9;
						maxweight=5000;
						UIposition[]={0.55000001,0.34999999};
					};
					class pylons4: pylons3
					{
						UIposition[]={0.1,0.34999999};
						mirroredMissilePos=3;
					};
					class pylons5: pylons1
					{
						hardpoints[]=
						{
							"B_BIM9X_RAIL",
							"B_AMRAAM_D_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"B_HARM_RAIL",
							"ARC_AGM_PYLON",
							"B_BOMB_PYLON",
							"ARC_EMP_RAIL"
						};
						attachment="PylonRack_Missile_AGM_02_x2";
						priority=7;
						maxweight=5000;
						UIposition[]={0.60000002,0.44999999};
					};
					class pylons6: pylons5
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=5;
					};
					class pylons7: pylons1
					{
						attachment="PylonMissile_1Rnd_Bomb_04_F";
						priority=9;
						maxweight=5000;
						UIposition[]={0.44999999,0.40000001};
					};
					class pylons8: pylons3
					{
						UIposition[]={0.2,0.40000001};
						mirroredMissilePos=7;
					};
				};
			};
		};
	};
	class FST_Ywing_Bomber_Green: FST_SHB_Bomber
	{
		author="Gold";
		displayName="[41st] FST-Y Wing Strategic Bomber";
		hiddenselections[]=
		{
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\YWING\Data\Chassis\FST_YWing_Chasis_CO.paa",
			"41st_Vehicles\YWING\Data\Detail\FST_YWing_Detail_CO.paa",
			"3as\3AS_btlb\data\interior_co.paa"
		};
	};
};