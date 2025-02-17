class CfgPatches
{
	class FST_Corvette_Weapons_pointdefense
	{
		units[]=
		{
			"FST_CIS_PD_Turret",
			"FST_CIS_PD_Turret_Inverted",
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"OPTRE_Corvette"
		};
		addonRootClass="OPTRE_Corvette";
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
class DefaultVehicleSystemsDisplayManagerLeft;
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
};
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret: NewTurret
			{
				class ViewOptics;
				class HitPoints
				{
					class HitGun;
					class HitTurret: HitGun
					{
						class DestructionEffects
						{
							class Smoke;
						};
					};
				};
			};
		};
		class Components;
		class Wounds;
		class HitPoints
		{
			class HitEngine;
			class HitHull;
			class HitTurret;
			class HitGun;
			class HitLTrack;
			class HitRTrack;
			class HitBody;
		};
		class ViewPilot;
		class CargoLight;
		class Reflectors;
		class UserActions;
	};
	class FST_CIS_PD_Turret: StaticWeapon
	{
		dlc="OPTRE";
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		isUav=1;
		crew="B_UAV_AI";
		armor=600;
		armorStructured=1;
		vehicleClass="OPTRE_UNSC_corvette_class";
		displayName="[41st] Ship Defense Cannon";
		model="\OPTRE_Corvette\weapons\pointdefense\turret.p3d";
		author="Daara";
		icon="iconCrateWpns";
		mapSize=2;
		gunBeg[]=
		{
			"z_gunL_chamber",
			"z_gunR_chamber"
		};
		gunEnd[]=
		{
			"z_gunL_muzzle",
			"z_gunR_muzzle"
		};
		uavCameraGunnerPos="pos_gunner_view";
		uavCameraGunnerDir="pos_gunner_view_dir";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
		enableGPS=1;
		radartype=2;
		radarTarget=1;
		radarTargetSize=2;
		visualTarget=1;
		visualTargetSize=2;
		irTarget=1;
		irTargetSize=2;
		reportRemoteTargets=1;
		receiveRemoteTargets=1;
		reportOwnPosition=1;
		lockDetectionSystem=1+8;
		incomingMissileDetectionSystem=16;
		class AttributeValues
		{
			RadarUsageAI=1;
		};
		class AnimationSources
		{
			class muzzle_rot_cannon
			{
				source="ammorandom";
				weapon="OPTRE_M9109_Turret";
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				body="mainturret";
				gun="maingun";
				animationsourcebody="MainTurret";
				animationSourceGun="MainGun";
				memoryPointGun[]=
				{
					"z_gunL_chamber",
					"z_gunR_chamber"
				};
				radartype = 8;
				gunAxis="gun_axis";
				turretAxis="turret_axis";
				minElev=-12;
				maxElev=120;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				maxHorizontalRotSpeed=5;
				maxVerticalRotSpeed=5;
				gunnerAction="driver_boat01";
				gunnerInAction="driver_boat01";
				gunnerGetInAction="GetInMRAP_01";
				gunnerGetOutAction="GetOutMRAP_01";
				gunnerName="Gunner";
				outGunnerMayFire=1;
				inGunnerMayFire=1;
				commanding=1;
				primaryGunner=1;
				soundServo[]=
				{
					"A3\Sounds_F\vehicles\armor\noises\servo_best",
					"db-40",
					1,
					50
				};
				uavCameraGunnerPos="pos_gunner_view_arty";
				uavCameraGunnerDir="pos_gunner_view_arty_dir";
				memoryPointGunnerOptics="pos_gunner_view_arty";
				cameraDir="pos_gunner_view_arty_dir";
				memoryPointsGetInGunner="Pos Gunner";
				memoryPointsGetInGunnerDir="Pos Gunner dir";
				weapons[]=
				{
					"FST_Flak_Cannon"
				};
				magazines[]=
				{
					"FST_FlakCannon_1000Rnd_AA_shells",
					"FST_FlakCannon_1000Rnd_AA_shells",
					"FST_FlakCannon_1000Rnd_AA_shells",
					"FST_FlakCannon_1000Rnd_AA_shells",
					"FST_FlakCannon_1000Rnd_AA_shells"
				};
				gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				gunnerOpticsShowCursor=1;
				turretInfoType="RscOptics_UAV_gunner";
				visionMode[]=
				{
					"Normal",
					"NVG",
					"Ti"
				};
				thermalMode[]={1,2,3,4,5};
				castGunnerShadow=1;
				startEngine=0;
				enableManualFire=0;
				gunnerForceOptics=1;
				gunnerForceOutOptics=1;
				hideWeaponsGunner=1;
				class ViewGunner: ViewOptics
				{
					initFov=0.69999999;
					minFov=0.0099999998;
					maxFov=1;
				};
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
							minRange=500;
							maxRange=4000;
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
						typeRecognitionDistance=4000;
						maxTrackableSpeed=1000;
						angleRangeHorizontal=90;
						angleRangeVertical=60;
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
					class DataLinkSensorComponent: SensorTemplateDataLink {};
				};
			};
			class VehicleSystemsDisplayManagerComponentLeft
			{
				class Components
				{
					class UAVDisplay
					{
						componentType = "UAVFeedDisplayComponent";
						range[] = {4000, 10000};
					};
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {4000, 10000};
					};
				};
			};
			class VehicleSystemsDisplayManagerComponentRight
			{
				class Components
				{
					class UAVDisplay
					{
						componentType = "UAVFeedDisplayComponent";
						range[] = {4000, 10000};
					};
					class SensorDisplay
					{
						componentType = "SensorsDisplayComponent";
						range[] = {4000, 10000};
					};
				};
			};
		};
		class SimpleObject
		{
			eden=1;
		};
	};
	class FST_CIS_PD_Turret_Inverted: FST_CIS_PD_Turret
	{
		displayName="[41st] Ship Defense Cannon (Inverted)";
		model="\OPTRE_Corvette\weapons\pointdefense\turret_u.p3d";
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minElev=-120;
				maxElev=12;
				minTurn=-360;
				maxTurn=360;
				initTurn=0;
				class ViewGunner: ViewOptics
				{
					initFov=0.69999999;
					minFov=0.0099999998;
					maxFov=1;
				};
			};
		};
		class SimpleObject
		{
			eden=1;
		};
	};
};
