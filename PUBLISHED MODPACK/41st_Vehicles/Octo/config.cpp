class CfgPatches
{
	class FST_Octo
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F_Jets"
		};
		units[]=
		{
			"FST_Octo",
			"FST_OctoStatic",
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
class DefaultEventhandlers;
class CfgVehicles
{
	class NonStrategic;
	class StaticShip;
	class Building;
	class House_F;
	class FloatingStructure_F;
	class thingx;
	class Ship;
	class LandVehicle;
	class StaticWeapon: LandVehicle
	{
		class Turrets;
		class HitPoints;
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class Components;
	};
	class FST_Octo_Base: StaticMGWeapon
	{
		author="Daara";
		scope=0;
		scopeCurator=0;
		vehicleClass="Autonomous";
		picture="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_picture_CA.paa";
		uiPicture="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_picture_CA.paa";
		icon="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_icon_CA.paa";
		displayName="[41st] Octuptarra Tri-Droid (Cinematic)";
		hasDriver=0;
		hasGunner=1;
		isUav=1;
		getInRadius=0;
		threat[]={0.30000001,0.30000001,1};
		cost=150000;
		accuracy=1;
		editorPreview="\A3\EditorPreviews_F_Jets\Data\Cfgvehicles\B_AAA_system_01_F.jpg";
		unitInfoType="RscUnitInfoTank";
		model="DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Octo\Octo.p3d";
		extCameraPosition[]={0,1.5,-10};
		canFloat=0;
		animationList[]={};
		enableGPS=1;
		radartype=2;
		radarTarget=1;
		radarTargetSize=0.89999998;
		visualTarget=1;
		visualTargetSize=1.2;
		irTarget=1;
		irTargetSize=0.5;
		reportRemoteTargets=1;
		receiveRemoteTargets=1;
		reportOwnPosition=1;
		lockDetectionSystem=0;
		incomingMissileDetectionSystem=16;
		uavCameraGunnerPos="gunnerview";
		uavCameraGunnerDir="gunnerview_dir";
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=100;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						typeRecognitionDistance=3500;
						maxTrackableSpeed=800;
						angleRangeHorizontal=60;
						angleRangeVertical=40;
						animDirection="mainGun";
						aimDown=-0.5;
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
							minRange=7000;
							maxRange=7000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=7000;
						angleRangeHorizontal=360;
						angleRangeVertical=100;
						aimDown=-45;
						maxTrackableSpeed=1388.89;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
				};
			};
		};
		armor=1000;
		armorStructural=5;
		explosionshielding=1;
		class HitPoints: HitPoints
		{
			class Hull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.12;
			};
		};
		crewExplosionProtection=0.99989998;
		damageResistance=0.0040000002;
		damageEffect="AirDestructionEffects";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner="GunnerIn";
				memoryPointsGetInGunnerDir="GunnerIn_dir";
				turretinfotype="RscOptics_APC_Tracked_01_gunner";
				animationSourceBody="Mainturret";
				Body="Mainturret";
				animationSourceGun="Maingun";
				Gun="Maingun";
				optics=1;
				minElev=-5;
				maxElev=35;
				minTurn=-360;
				maxTurn=360;
				hasgunner=1;
				gunnerName="Octo Droid AI";
				primary=1;
				primaryGunner=1;
				startEngine=0;
				enableManualFire=1;
				selectionFireAnim="zasleh";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm",
					1.4125376,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm_vertical",
					1.4125376,
					1,
					30
				};
				memoryPointGunnerOptics="gunnerview";
				displayName="";
				gunnerForceOptics=1;
				memoryPointGun[]=
				{
					"usti hlavne"
				};
				uavCameraGunnerPos="gunnerview";
				uavCameraGunnerDir="gunnerview_dir";
				forceHideGunner=1;
				gunnerOutForceOptics=1;
				viewgunnerinExternal=0;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				castGunnerShadow=0;
				showAllTargets=2;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName="W";
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.46599999;
						minFov=0.46599999;
						maxFov=0.46599999;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName="M";
						initFov=0.093000002;
						minFov=0.093000002;
						maxFov=0.093000002;
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName="N";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov=0.028999999;
						minFov=0.028999999;
						maxFov=0.028999999;
					};
				};
				weapons[]=
				{
					"FST_AAT_Cannon",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"SmokeLauncherMag"
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="otocvez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=1;
						radius=0.15000001;
					};
					class HitGun
					{
						armor=0.75;
						material=-1;
						name="otocvez";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
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
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
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
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
		};
		class AttributeValues
		{
			RadarUsageAI=1;
		};
	};
	class FST_Octo: FST_Octo_Base
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.467;
			verticalOffsetWorld=-0.039000001;
			init="''";
		};
		author="Daara";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
	};
	class FST_Octo_BaseStatic: StaticMGWeapon
	{
		author="Daara";
		scope=0;
		scopeCurator=0;
		vehicleClass="Autonomous";
		picture="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_picture_CA.paa";
		uiPicture="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_picture_CA.paa";
		icon="\A3\Static_F_Jets\AAA_system_01\Data\UI\AAA_system_01_icon_CA.paa";
		displayName="[FST] Octuptarra Tri-Droid Static";
		hasDriver=0;
		hasGunner=1;
		isUav=1;
		getInRadius=0;
		threat[]={0.30000001,0.30000001,1};
		cost=150000;
		accuracy=1;
		editorPreview="\A3\EditorPreviews_F_Jets\Data\Cfgvehicles\B_AAA_system_01_F.jpg";
		unitInfoType="RscUnitInfoTank";
		model="DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_TriDroidStatic\DBA_TriDroidStatic.p3d";
		extCameraPosition[]={0,9.5,-20};
		canFloat=0;
		animationList[]={};
		enableGPS=1;
		radartype=2;
		radarTarget=1;
		radarTargetSize=0.89999998;
		visualTarget=1;
		visualTargetSize=1.2;
		irTarget=1;
		irTargetSize=0.5;
		reportRemoteTargets=1;
		receiveRemoteTargets=1;
		reportOwnPosition=1;
		lockDetectionSystem=0;
		incomingMissileDetectionSystem=16;
		uavCameraGunnerPos="Laser_Pos";
		uavCameraGunnerDir="Laser_Dir";
		class AnimationSources
		{
			class mainturretfake
			{
				source="user";
				animPeriod=4;
				initPhase=0;
			};
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="FST_AAT_Cannon";
			};
			class muzzle_reload_cannon
			{
				source="reload";
				weapon="FST_AAT_Cannon";
			};
		};
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=100;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3500;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						typeRecognitionDistance=3500;
						maxTrackableSpeed=800;
						angleRangeHorizontal=60;
						angleRangeVertical=40;
						animDirection="mainGun";
						aimDown=-0.5;
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
							minRange=7000;
							maxRange=7000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=7000;
						angleRangeHorizontal=360;
						angleRangeVertical=100;
						aimDown=-45;
						maxTrackableSpeed=1388.89;
					};
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
				};
			};
		};
		armor=1000;
		armorStructural=5;
		explosionshielding=1;
		class HitPoints: HitPoints
		{
			class Hull
			{
				armor=4.5;
				material=-1;
				name="telo";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.2;
				explosionShielding=0.2;
				radius=0.12;
			};
		};
		damageResistance=0.0040000002;
		damageEffect="AirDestructionEffects";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner="GunnerIn";
				memoryPointsGetInGunnerDir="GunnerIn_dir";
				turretinfotype="RscOptics_APC_Tracked_01_gunner";
				animationSourceBody="Mainturret";
				Body="Mainturret";
				animationSourceGun="Maingun";
				Gun="Maingun";
				optics=1;
				minElev=-25;
				maxElev=35;
				minTurn=-360;
				maxTurn=360;
				hasgunner=1;
				gunnerName="Octo Droid AI";
				primary=1;
				primaryGunner=1;
				startEngine=0;
				enableManualFire=1;
				selectionFireAnim="Cannon_Effect";
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm",
					1.4125376,
					1,
					30
				};
				soundServoVertical[]=
				{
					"A3\Sounds_F\vehicles\boat\Boat_Armed_01\servo_boat_comm_vertical",
					1.4125376,
					1,
					30
				};
				memoryPointGunnerOptics="Laser_Pos";
				displayName="";
				gunBeg="Laser_Dir";
				gunEnd="Laser_Pos";
				gunnerForceOptics=1;
				memoryPointGun[]=
				{
					"Laser_Pos"
				};
				uavCameraGunnerPos="Laser_Pos";
				uavCameraGunnerDir="Laser_Dir";
				forceHideGunner=1;
				gunnerOutForceOptics=1;
				viewgunnerinExternal=0;
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				castGunnerShadow=0;
				showAllTargets=2;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName="W";
						initAngleX=0;
						minAngleX=-30;
						maxAngleX=30;
						initAngleY=0;
						minAngleY=-100;
						maxAngleY=100;
						initFov=0.46599999;
						minFov=0.46599999;
						maxFov=0.46599999;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName="M";
						initFov=0.093000002;
						minFov=0.093000002;
						maxFov=0.093000002;
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName="N";
						gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov=0.028999999;
						minFov=0.028999999;
						maxFov=0.028999999;
					};
				};
				weapons[]=
				{
					"FST_AAT_Cannon",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"IDA_thermal_coil_HP",
					"SmokeLauncherMag"
				};
				class HitPoints
				{
					class HitTurret
					{
						armor=0.80000001;
						material=-1;
						name="otocvez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=1;
						radius=0.15000001;
					};
					class HitGun
					{
						armor=0.75;
						material=-1;
						name="otocvez";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.15000001;
					};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
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
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
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
							class UAVDisplay
							{
								componentType="UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType="SensorsDisplayComponent";
								range[]={16000,8000,4000,2000};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
		};
		class AttributeValues
		{
			RadarUsageAI=1;
		};
		class EventHandlers: DefaultEventhandlers
		{
			Fired="_this ExecVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_TriDroidStatic\functions\Rotate.sqf';";
		};
	};
	class FST_OctoStatic: FST_Octo_BaseStatic
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.467;
			verticalOffsetWorld=-0.039000001;
			init="''";
		};
		author="Daara";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
	};
};