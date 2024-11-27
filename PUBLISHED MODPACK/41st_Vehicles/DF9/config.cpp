class CfgPatches
{
	class FST_Static_DF9
	{
		addonRootClass="3AS_Static";
		requiredAddons[]=
		{
			"3AS_Main"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_DF9_Radar",
			"FST_DF9_Rocket",
			"FST_DF9_Base",
		};
		weapons[]={};
		magazines[]={};
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
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class Eventhandlers;
class WeaponCloudsMGun;
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
		class UserActions;
	};
	class Radar_System_01_base_F: StaticMGWeapon
	{
		class AnimationSources;
	};
	class FST_DF9_Base: StaticMGWeapon
	{
		author="Daara";
		scope=2;
		side=0;
		armor=1250;
		faction="FST_BattleDroids_Faction";
		crew="FST_Droid_B1_E5";
		memoryPointsGetInGunner="pos_gunner";
		memoryPointsGetInGunnerDir="pos_gunner_dir";
		displayName="[41st] DF9 Turret Base";
		class Armory
		{
			description="";
		};
		model="3AS\3as_static\DF9\model\3AS_DF9.p3d";
		editorSubcategory="EdSubcat_Turrets";
		icon="3AS\3as_static\DF9\Data\ui\Df9_top_ca.paa";
		picture="3AS\3as_static\DF9\Data\ui\Df9_Side_ca.paa";
		Uipicture="3AS\3as_static\DF9\Data\ui\Df9_Side_ca.paa";
		threat[]={1,0.30000001,0.30000001};
		cost=150000;
		getInAction="";
		getOutAction="";
		receiveRemoteTargets=1;
		reportRemoteTargets=1;
		reportOwnPosition=1;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_Static\DF9\data\DF9_Standard.rvmat",
				"3as\3AS_Static\DF9\data\DF9_Standard.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat"
			};
		};
		hiddenSelections[]=
		{
			"camo1"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_static\DF9\Data\DF9_Standard_CO.paa"
		};
		class Components
		{
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
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"3AS_DF9_30mm_Cannon"
				};
				magazines[]=
				{
					"3AS_250Rnd_30mm_DF9_shells",
					"3AS_250Rnd_30mm_DF9_shells",
					"3AS_250Rnd_30mm_DF9_shells",
					"3AS_250Rnd_30mm_DF9_shells"
				};
				gunnerAction="FieldCannon_Gunner";
				gunnerGetInAction="GetInHigh";
				gunnerGetOutAction="GetOutHigh";
				displayName="Gunner";
				memoryPointsGetInGunner="pos_gunner";
				memoryPointsGetInGunnerDir="pos_gunner_dir";
				ejectDeadGunner=1;
				gunnerForceOptics=1;
				forceHideGunner=1;
				gunnerRightHandAnimName="OtocHlaven_shake";
				gunnerLeftHandAnimName="OtocHlaven_shake";
				body="MainTurret";
				gun="MainGun";
				animationSourceBody="MainTurret";
				animationSourceGun="MainGun";
				minElev=-20;
				maxElev=45;
				minTurn=-360;
				maxTurn=360;
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
				memoryPointGun[]=
				{
					"usti hlavne"
				};
				gunBeg="usti hlavne";
				gunEnd="konec hlavne";
				selectionFireAnim="Zasleh";
				LODOpticsIn=1;
				optics=1;
				discreteDistance[]={100,200,300,400,600,800,1000,1200,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				turretInfoType="RscOptics_crows";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
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
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
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
		};
		class AnimationSources
		{
			class Missiles_revolving
			{
				source="revolving";
				weapon="missiles_titan_AA";
			};
			class Missiles_reloadMagazine: Missiles_revolving
			{
				source="reloadMagazine";
			};
			class Muzzle_Flash
			{
				source="ammorandom";
				weapon="3AS_DF9_30mm_Cannon";
			};
			class recoil_source
			{
				source="reload";
				weapon="3AS_DF9_30mm_Cannon";
			};
		};
		soundGetOut[]=
		{
			"A3\sounds_f\dummysound",
			0.001,
			1,
			5
		};
		soundGetIn[]=
		{
			"A3\sounds_f\dummysound",
			0.00031622799,
			1,
			5
		};
		class DestructionEffects
		{
			class LightBig1
			{
				simulation="light";
				type="ObjectDestructionLight";
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
				intensity=1;
				interval=1;
				lifeTime=1;
				type="Fire";
			};
			class FireBig1
			{
				simulation="particles";
				type="ObjectDestructionFire1";
				position="destructionEffect1";
				intensity=0.15000001;
				interval=1;
				lifeTime=3;
			};
			class Refract1
			{
				simulation="particles";
				type="ObjectDestructionRefract";
				position="destructionEffect1";
				intensity=0.15000001;
				interval=1;
				lifeTime=3;
			};
			class SmokeBig1
			{
				simulation="particles";
				type="ObjectDestructionSmoke";
				position="destructionEffect1";
				intensity=0.15000001;
				interval=1;
				lifeTime=3.5;
			};
			class SparksBig1
			{
				simulation="particles";
				type="ObjectDestructionSparks";
				position="destructionEffect1";
				intensity=0;
				interval=1;
				lifeTime=0;
			};
			class FireSparksBig1
			{
				simulation="particles";
				type="FireSparks";
				position="destructionEffect2";
				intensity=1;
				interval=1;
				lifeTime=2.8;
			};
			class FireBig2
			{
				simulation="particles";
				type="ObjectDestructionFire2";
				position="destructionEffect2";
				intensity=0.15000001;
				interval=1;
				lifeTime=3;
			};
			class SmokeBig1_2
			{
				simulation="particles";
				type="ObjectDestructionSmoke1_2";
				position="destructionEffect2";
				intensity=0.15000001;
				interval=1;
				lifeTime=3.5;
			};
			class SmokeBig2
			{
				simulation="particles";
				type="ObjectDestructionSmoke2";
				position="destructionEffect2";
				intensity=1;
				interval=1;
				lifeTime=3.2;
			};
		};
	};
	class FST_DF9_Rocket: FST_DF9_Base
	{
		displayName="[41st] CIS Ship Defense Rocket Turret";
		class Armory
		{
			description="";
		};
		model="3AS\3as_static\DF9\model\3AS_DF9_Rocket.p3d";
		icon="3AS\3as_static\DF9\Data\ui\Df9_top_ca.paa";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_static\DF9\Data\DF9_RK_GREY_CO.paa"
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_Static\DF9\data\DF9_RK.rvmat",
				"3as\3AS_Static\DF9\data\DF9_RK.rvmat",
				"A3\Static_F_Gamma\data\StaticTurret_01_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
				{
					"FST_Stormfury_AA_Missile"
				};
				magazines[]=
				{
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Stormfury_12Rnd_AA_Missile",
					"FST_Stormfury_12Rnd_AA_Missile"
				};
				minElev=-30;
				maxElev=60;
				memoryPointGun[]=
				{
					""
				};
				missileBeg="spice rakety";
				missileEnd="konec rakety";
				gunBeg="";
				gunEnd="";
				gunnerOpticsModel="\a3\weapons_f_gamma\reticle\HMG_01_Optics_Gunner_F";
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
						initFov=0.155;
						minFov=0.155;
						maxFov=0.155;
						visionMode[]=
						{
							"Normal",
							"NVG",
							"Ti"
						};
						thermalMode[]={0,1};
						gunnerOpticsModel="A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
						gunnerOpticsEffect[]={};
					};
					class Narrow: Wide
					{
						gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
						initFov=0.046999998;
						minFov=0.046999998;
						maxFov=0.046999998;
					};
				};
			};
		};
		class EventHandlers
		{
			fired="[_this select 0,_this select 6,'missile_move','MissileBase'] call BIS_fnc_missileLaunchPositionFix;";
		};
		class AnimationSources
		{
			class Missiles_revolving
			{
				source="revolving";
				weapon="3AS_missiles_titan_AA";
			};
			class Missiles_reloadMagazine: Missiles_revolving
			{
				source="reloadMagazine";
			};
		};
	};
	class FST_DF9_Radar: Radar_System_01_base_F
	{
		author="Daara";
		scope=2;
		armor=1250;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="EdSubcat_Turrets";
		crew="O_UAV_AI";
		displayName="[41st] CIS Warship Sensors";
		model="3AS\3AS_Static\DF9\model\3AS_DF9_Radar.p3d";
		isUav=1;
		uavCameraGunnerPos="pos_gunner_view";
		uavCameraGunnerDir="pos_gunner_view_dir";
		threat[]={0.1,0.1,1};
		cost=3000000;
		accuracy=0.12;
		class TextureSources
		{
		};
		enableGPS=1;
		radartype=2;
		radarTarget=1;
		radarTargetSize=1;
		visualTarget=1;
		visualTargetSize=1.2;
		irTargetSize=0.5;
		reportRemoteTargets=1;
		receiveRemoteTargets=1;
		reportOwnPosition=1;
		lockDetectionSystem="CM_none";
		incomingMissileDetectionSystem="CM_Missile";
		hiddenSelectionsTextures[]=
		{
			"3AS\3as_static\DF9\Data\DF9_RAD_GREY_CO.paa"
		};
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class DataLinkSensorComponent: SensorTemplateDataLink
					{
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						animDirection="mainGun";
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=12000;
							maxRange=12000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						animDirection="mainGun";
						typeRecognitionDistance=12000;
						maxTrackableSpeed=1388.89;
					};
				};
			};
		};
		animated=1;
		class AnimationSources: AnimationSources
		{
		};
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_Static\DF9\data\DF9_RAD.rvmat",
				"3as\3AS_Static\DF9\data\DF9_RAD.rvmat",
				"A3\Static_F_Sams\Radar_System_01\data\Radar_System_01_mat_01_destruct.rvmat"
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minelev=-10;
				maxelev=75;
				minturn=-180;
				maxturn=180;
				initElev=15;
				initTurn=0;
				maxHorizontalRotSpeed=1;
				maxVerticalRotSpeed=1;
				hasGunner=1;
				canUseScanners=1;
				primary=1;
				primaryGunner=1;
				startEngine=0;
				gunnerForceOptics=1;
				uavCameraGunnerPos="pos_gunner_view";
				uavCameraGunnerDir="pos_gunner_view_dir";
				memoryPointGunnerOptics="pos_gunner_view";
				weapons[]=
				{
					"FakeWeapon"
				};
				magazines[]={};
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
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
	};
};