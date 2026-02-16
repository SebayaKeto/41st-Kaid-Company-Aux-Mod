class CfgPatches
{
	class FST_Scorponek
	{
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Static_F_Jets",
			"41st_Addon"
		};
		units[]=
		{
			"FST_Scorponek"
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
class CfgVehicles
{
	class Land;
	class LandVehicle: Land
	{
		class ViewPilot;
		class ViewGunner;
		class NewTurret;
	};
	class StaticWeapon: LandVehicle
	{
		class Turrets
		{
			class MainTurret;
		};
	};
	class StaticMGWeapon: StaticWeapon
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				class ViewOptics;
			};
		};
		class Components;
	};
	class HitPoints;
	class DBA_Scorponek_Base: StaticMGWeapon{};
	class FST_Scorponek_Base: DBA_Scorponek_Base
	{
		author="Viz";
		scope=0;
		scopeCurator=0;
		faction="FST_BattleDroids_Faction";
		accuracy=1;
		class HitPoints: HitPoints
		{
			class Hit_Hull
			{
				armor=30;
				name="Hit_Hull";
				visual="zbytek";
				radius=0.25;
				minimalHit=0.050000001;
				explosionShielding=0.2;
				depends="Total";
				passThrough=1;
				material=-1;
			};
			class Hit_Shield
			{
				armorComponent="ShieldComponent";
				armor=3;
				name="Hit_Shield";
				visual="zbytek";
				radius=0.25;
				minimalHit=0.050000001;
				explosionShielding=0.2;
				depends="Total";
				passThrough=0;
				material=-1;
			};
		};
		armor=200;
		armorStructural=2;
		explosionshielding=1;
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
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=2800;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						typeRecognitionDistance=2800;
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
							minRange=8000;
							maxRange=8000;
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
						typeRecognitionDistance=4000;
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
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				memoryPointsGetInGunner="GunnerIn";
				memoryPointsGetInGunnerDir="GunnerIn_dir";
				turretinfotype="RscOptics_APC_Tracked_01_gunner";
				animationSourceBody="MainTurret";
				Body="MainTurret";
				animationSourceGun="MainGun";
				Gun="MainGun";
				optics=1;
				minElev=-15;
				maxElev=55;
				minTurn=-360;
				maxTurn=360;
				hasgunner=1;
				gunnerName="Scorponek AI";
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
				gunnerForceOptics=1;
				memoryPointGun[]=
				{
					"gun_left_Down",
					"gun_left_Up",
					"gun_Right_Down",
					"Gun_left_Up"
				};
				uavCameraGunnerPos="camera_pos";
				uavCameraGunnerDir="camera_dir";
				memoryPointGunnerOptics="camera_pos";
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
					"FST_AAT_Cannon"
				};
				magazines[]=
				{
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red",
					"FST_thermal_coil_LP_Red"
				};
			};
		};
		class animationsources
		{
			class ScorponekShieldHide
			{
				animPeriod=0.001;
				initPhase=0;
				source="user";
			};
		};
	};
	class FST_Scorponek: FST_Scorponek_Base
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.467;
			verticalOffsetWorld=-0.039000001;
			init="''";
		};
		author="Viz";
		scope=2;
		scopeCurator=2;
		side=0;
		displayName="[41st] Scorponek";
		crew="B_UAV_AI";
		typicalCargo[]=
		{
			"B_UAV_AI"
		};
	};
};
class Extended_Init_EventHandlers
{
	class FST_Scorponek
	{
		class FST_Scorponek_Init_Eh
		{
			init="_this execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Scorponek\ScorponekShieldRegen.sqf'";
		};
	};
};
class Extended_HitPart_EventHandlers
{
	class FST_Scorponek
	{
		class FST_Scorponek_HitPart_Eh
		{
			hitpart="_this select 0 execVM 'DBA_CIS\Addons\DBA_Vehicles\DBA_GroundVehicles\DBA_Scorponek\ScorponekShieldHit.sqf'";
		};
	};
};