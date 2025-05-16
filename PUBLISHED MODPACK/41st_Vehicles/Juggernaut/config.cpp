class CfgPatches
{
	class FST_APC_Jug
	{
		addonRootClass="A3_Armor_F_Beta";
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_Soft_F"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Jug",
			"FST_Jug_static",
			"FST_Jug_destroy_static"
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
class DefaultEventHandlers;
class EventHandlers;
class AnimationSources;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class RCWSOptics;
class Optics_Armored;
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
class Optics_Commander_01: Optics_Armored
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
class CfgVehicles
{
	class Car;
	class Car_F: Car
	{
		class NewTurret;
		class Sounds;
		class HitPoints
		{
			class HitBody;
			class HitEngine;
			class HitFuel;
			class HitHull;
		};
	};
	class Wheeled_APC_F: Car_F
	{
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
				class Turrets
				{
					class CommanderOptics;
				};
			};
		};
	};
	class Wreck_base_F;
	class FST_Jug_static: Wreck_base_F
	{
		author="Daara";
		mapsize=20;
		editorPreview="";
		scope=2;
		scopecurator=2;
		icon="iconObject_1x2";
		displayname="[41st] HAVw A5 Juggernaut (Static)";
		model="3as\3as_Jug\model\3as_jug_w.p3d";
		editorCategory="3AS_EditorCategory_General_Props";
		editorSubcategory="3as_Wrecks";
	};
	class FST_Jug_destroy_static: FST_Jug_static
	{
		displayname="[41st] HAVw A5 Juggernaut (Destroyed)";
		model="3as\3as_Jug\model\3as_jug_d.p3d";
	};
	class FST_Jug_base_F: Wheeled_APC_F
	{
		features="Randomization: No      <br />Camo selections: 3 - top of hull, bottom of hull, turret      <br />Script door sources: None      <br />Script animations: HideTurret      <br />Executed scripts: None       <br />Firing from vehicles: No      <br />Slingload: No      <br />Cargo proxy indexes: 1 to 8";
		author="Daara";
		destrType="DestructWreck";
		mapSize=10.44;
		_generalMacro="APC_Wheeled_01_base_F";
		accuracy=0.25;
		displayName="[41st] HAVw A5 Juggernaut";
		attenuationEffectType="TankAttenuation";
		extCameraPosition[]={0,12,-30};
		thrustDelay=0.1;
		brakeIdleSpeed=1.78;
		maxSpeed=90;
		fuelCapacity=100;
		wheelCircumference=2.8340001;
		fuelConsumptionRate=15;
		antiRollbarForceCoef=24;
		antiRollbarForceLimit=30;
		antiRollbarSpeedMin=15;
		antiRollbarSpeedMax=70;
		idleRpm=425;
		redRpm=2300;
		maxOmega=700;
		minOmega=50;
		class complexGearbox
		{
			GearboxRatios[]=
			{
				"R1",
				-4.8400002,
				"N",
				0,
				"D1",
				3.4300001,
				"D2",
				2.01,
				"D3",
				1.42,
				"D4",
				1,
				"D5",
				0.82999998,
				"D6",
				0.58999997
			};
			TransmissionRatios[]=
			{
				"High",
				1,
				"Low",
				6
			};
			AmphibiousRatios[]=
			{
				"R1",
				-10,
				"N",
				0,
				"D1",
				30
			};
			gearBoxMode="auto";
			moveOffGear=1;
			driveString="D";
			neutralString="N";
			reverseString="R";
		};
		simulation="carx";
		damperSize=0.2;
		damperForce=1;
		damperDamping=1;
		dampersBumpCoef=6;
		differentialType="all_limited";
		frontRearSplit=0.5;
		frontBias=1.3;
		rearBias=1.3;
		centreBias=1.3;
		clutchStrength=180;
		enginePower=2609;
		peakTorque=13000;
		dampingRateFullThrottle=0.079999998;
		dampingRateZeroThrottleClutchEngaged=13;
		dampingRateZeroThrottleClutchDisengaged=0.1;
		torqueCurve[]=
		{
			{0,0},
			{0.178,0.80000001},
			{0.25,1},
			{0.461,0.89999998},
			{0.89999998,0.80000001},
			{1,0.30000001}
		};
		changeGearMinEffectivity[]={0.5,0.15000001,0.97000003,0.97000003,0.97000003,0.97000003,0.97000003,0.98500001};
		switchTime=0.2;
		latency=1;
		class Wheels
		{
			class L1
			{
				boneName="wheel_1_1_damper";
				steering=1;
				side="left";
				center="wheel_1_1_axis";
				boundary="wheel_1_1_bound";
				width="0.2";
				mass=1050;
				MOI=1700;
				dampingRate=0.40000001;
				dampingRateDamaged=1;
				dampingRateDestroyed=1000;
				maxBrakeTorque=70000;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_1_1_axis";
				tireForceAppPointOffset="wheel_1_1_axis";
				maxCompression=0.5;
				maxDroop=0.5;
				sprungMass=4250;
				springStrength=106250;
				springDamperRate=17000;
				longitudinalStiffnessPerUnitGravity=100000;
				latStiffX=25;
				latStiffY=1800;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
			};
			class R1: L1
			{
				steering=1;
				boneName="wheel_2_1_damper";
				center="wheel_2_1_axis";
				boundary="wheel_2_1_bound";
				suspForceAppPointOffset="wheel_2_1_axis";
				tireForceAppPointOffset="wheel_2_1_axis";
				side="right";
			};
			class L2: L1
			{
				boneName="wheel_1_2_damper";
				steering=1;
				center="wheel_1_2_axis";
				boundary="wheel_1_2_bound";
				suspForceAppPointOffset="wheel_1_2_axis";
				tireForceAppPointOffset="wheel_1_2_axis";
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
			class L5: L1
			{
				boneName="wheel_1_5_damper";
				steering=0;
				center="wheel_1_5_axis";
				boundary="wheel_1_5_bound";
				maxHandBrakeTorque=4000;
				suspForceAppPointOffset="wheel_1_5_axis";
				tireForceAppPointOffset="wheel_1_5_axis";
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
			class R3: R1
			{
				boneName="wheel_2_3_damper";
				steering=1;
				center="wheel_2_3_axis";
				boundary="wheel_2_3_bound";
				suspForceAppPointOffset="wheel_2_3_axis";
				tireForceAppPointOffset="wheel_2_3_axis";
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
			class R5: R1
			{
				boneName="wheel_2_5_damper";
				steering=0;
				center="wheel_2_5_axis";
				boundary="wheel_2_5_bound";
				maxHandBrakeTorque=4000;
				suspForceAppPointOffset="wheel_2_5_axis";
				tireForceAppPointOffset="wheel_2_5_axis";
			};
		};
		editorSubcategory="FST_Ground_Vehicle";
		memoryPointTaskMarker="TaskMarker_1_pos";
		terrainCoef=1.5;
		turnCoef=2;
		canFloat=1;
		waterPPInVehicle=0;
		waterResistanceCoef=0.029999999;
		engineShiftY=-0.5;
		armor=2000;
		armorStructural=15;
		armorLights=0.1;
		crewExplosionProtection=0.99949998;
		damageResistance=0.0071899998;
		cost=1000000;
		driverAction="gunner_Mrap_01";
		driverInAction="ATAP_Gunner";
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		cargoAction[]=
		{
			"passenger_generic02_foldhands"
		};
		hideWeaponsCargo=1;
		driverForceOptics=0;
		driverOpticsModel="\a3\weapons_f\reticle\Optics_Driver_01_F";
		memoryPointDriverOptics="driverview";
		cargoIsCoDriver[]={0};
		forceHideDriver=1;
		class ViewOptics: ViewOptics
		{
			visionMode[]=
			{
				"Normal",
				"NVG"
			};
			initFov=0.85000002;
			minFov=0.85000002;
			maxFov=0.85000002;
		};
		class HitPoints: HitPoints
		{
			class HitBody: HitBody
			{
				armor=3.5;
				material=-1;
				name="karoserie";
				visual="zbytek";
				passThrough=1;
				minimalHit=0.1;
				explosionShielding=1.2;
				radius=0.40000001;
			};
			class HitEngine: HitEngine
			{
				armor=3.5;
				material=-1;
				name="motor";
				passThrough=0.5;
				minimalHit=0.1;
				explosionShielding=0.5;
				radius=0.30000001;
			};
			class HitFuel: HitFuel
			{
				armor=3.5;
				material=-1;
				name="palivo";
				passThrough=0.5;
				minimalHit=0.1;
				explosionShielding=0.5;
				radius=0.30000001;
			};
			class HitHull: HitHull
			{
				armor=2;
				material=-1;
				name="palivo";
				passThrough=0;
				minimalHit=0.1;
				explosionShielding=1.5;
				radius=0.30000001;
			};
		};
		weapons[]=
		{
			"TruckHorn"
		};
		magazines[]={};
		smokeLauncherGrenadeCount=18;
		smokeLauncherVelocity=8;
		smokeLauncherOnTurret=0;
		smokeLauncherAngle=360;
		driverIsCommander=0;
		memorypointlmissile="SAM_missile_1";
		memorypointrmissile="SAM_missile_2";
		memoryPointLRocket="SAM_missile_1";
		memoryPointRRocket="SAM_missile_2";
		memoryPointMissile[]=
		{
			"SAM_missile_1",
			"SAM_missile_2"
		};
		memoryPointMissileDir[]=
		{
			"SAM_backblast_pos",
			"SAM_backblast_2_pos"
		};
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class IRSensorComponent: SensorTemplateIR
					{
						class AirTarget
						{
							minRange=5000;
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=3000;
							maxRange=3000;
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
							minRange=2000;
							maxRange=2000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=1500;
							maxRange=1500;
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
							minRange=12000;
							maxRange=12000;
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
						typeRecognitionDistance=12000;
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
						typeRecognitionDistance=8000;
						angleRangeHorizontal=180;
						angleRangeVertical=180;
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
						range[]={800,2000,4000,1600};
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
						range[]={800,2000,4000,1600};
						resource="RscCustomInfoSensors";
					};
				};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret1: NewTurret
			{
				class ViewGunner;
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerAction="gunner_apcwheeled1_out";
				gunnerInAction="ATAP_Gunner";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				weapons[]=
				{
					"FST_ATTE_Turret",
					"FST_EWEB_RemoteTurret",
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
					"FST_EWEB_cell_Blue"
				};
				primaryObserver=0;
				elevationMode=0;
				initCamElev=0;
				minCamElev=-30;
				maxCamElev=50;
				gunAxis="OsaHlavne";
				gunBeg="gun_t_end";
				gunEnd="gun_t_start";
				gunnerName="Top Gunner";
				displayname="Top Gunner";
				initElev=10;
				primaryGunner=1;
				gunnerForceOptics=0;
				inGunnerMayFire=1;
				minTurn=-360;
				maxTurn=360;
				turretFollowFreeLook=1;
				body="mainTurret";
				animationSourceBody="mainTurret";
				animationSourceGun="mainGun";
				gun="maingun";
				initTurn=0;
				cameraDir="";
				LODTurnedIn=1100;
				LodOpticsIn=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				discreteDistanceCameraPoint[]=
				{
					"eye"
				};
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				memoryPointGunnerOptics="gunnerview";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				commanding=-1;
				proxyIndex=1;
				forcehidegunner=1;
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
				minelev=-10;
				maxelev=50;
				class HitPoints
				{
					class HitTurret
					{
						armor=1.2;
						material=-1;
						name="vez";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1.2;
						material=-1;
						name="zbran";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
				ejectDeadGunner=1;
				usepip=2;
				proxyType="CPGunner";
				startEngine=0;
				class Components
				{
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
								range[]={800,2000,4000,1600};
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
								range[]={800,2000,4000,1600};
								resource="RscCustomInfoSensors";
							};
						};
					};
				};
			};
			class Backturret: MainTurret1
			{
				class ViewGunner;
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerAction="gunner_apcwheeled1_out";
				gunnerInAction="ATAP_Gunner";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				weapons[]=
				{
					"FST_ATTE_Turret",
					"FST_EWEB_RemoteTurret",
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
					"FST_EWEB_cell_Blue"
				};
				commanding=-2;
				forcehidegunner=1;
				elevationMode=0;
				initCamElev=0;
				minCamElev=-25;
				maxCamElev=80;
				gunAxis="gun_b_gun_axis";
				gunBeg="gun_b_end";
				gunEnd="gun_b_start";
				memoryPointGun[]=
				{
					"gun_b_end"
				};
				missileBeg="gun_b_end";
				missileEnd="gun_b_start";
				initElev=0;
				turretAxis="gun_b_turret_axis";
				primaryGunner=0;
				gunnerName="Rear Gunner";
				displayname="Rear Gunner";
				gunnerForceOptics=0;
				inGunnerMayFire=1;
				minTurn=-360;
				maxTurn=360;
				turretFollowFreeLook=1;
				body="Mainturret_b";
				animationSourceBody="Mainturret_b";
				animationSourceGun="Maingun_b";
				proxyType="CPGunner";
				proxyIndex=2;
				gun="Maingun_b";
				initTurn=0;
				cameraDir="look";
				LODTurnedIn=1100;
				LodOpticsIn=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				discreteDistanceCameraPoint[]=
				{
					"eye"
				};
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				memoryPointGunnerOptics="gunnerview2";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				primaryObserver=0;
				class Reflectors
				{
					class Right
					{
						color[]={7000,7500,10000};
						ambient[]={70,75,100};
						intensity=50;
						size=1;
						innerAngle=15;
						outerAngle=65;
						coneFadeCoef=10;
						position="Light_b_pos";
						direction="Light_b_dir";
						hitpoint="Light_b_hitpoint";
						selection="Light_b";
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
					};
				};
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
				minelev=-5;
				maxelev=80;
				class HitPoints
				{
					class HitTurret
					{
						armor=1.2;
						material=-1;
						name="vezvelitele";
						visual="vez";
						passThrough=0;
						minimalHit=0.02;
						explosionShielding=0.30000001;
						radius=0.25;
					};
					class HitGun
					{
						armor=1.2;
						material=-1;
						name="zbranvelitele";
						visual="";
						passThrough=0;
						minimalHit=0;
						explosionShielding=1;
						radius=0.25;
					};
				};
				ejectDeadGunner=1;
				usepip=2;
				startEngine=0;
			};
			class Frontturret: NewTurret
			{
				class ViewGunner;
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerAction="gunner_apcwheeled1_out";
				gunnerInAction="ATAP_Gunner";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				displayname="Front Gunner";
				weapons[]=
				{
					"FST_ATTE_Turret",
					"FST_EWEB_RemoteTurret",
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
					"FST_EWEB_cell_Blue"
				};
				proxyType="CPGunner";
				proxyIndex=3;
				commanding=-3;
				elevationMode=0;
				initCamElev=0;
				minCamElev=-45;
				maxCamElev=0;
				gunEnd="";
				gunBeg="";
				memoryPointGun[]=
				{
					"ap_gun_1_1_end",
					"ap_gun_1_2_end",
					"ap_gun_2_1_end",
					"ap_gun_2_2_end"
				};
				primaryGunner=0;
				gunnerName="Front Gunner";
				gunnerForceOptics=0;
				forcehidegunner=1;
				inGunnerMayFire=1;
				minTurn=-30;
				maxTurn=30;
				initElev=-20;
				turretFollowFreeLook=0;
				body="Mainturret_ap";
				animationSourceBody="Mainturret_ap";
				animationSourceGun="Maingun_ap";
				gun="Maingun_ap";
				initTurn=0;
				cameraDir="";
				LODTurnedIn=1100;
				LodOpticsIn=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				discreteDistanceCameraPoint[]=
				{
					"eye"
				};
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				memoryPointGunnerOptics="gunnerview3";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				primaryObserver=0;
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				minelev=-55;
				maxelev=0;
				ejectDeadGunner=1;
				usepip=2;
				startEngine=0;
			};
			class Missleturret: MainTurret1
			{
				class ViewGunner;
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerAction="gunner_apcwheeled1_out";
				gunnerInAction="ATAP_Gunner";
				gunnerGetInAction="GetInAMV_cargo";
				gunnerGetOutAction="GetOutLow";
				weapons[]=
				{
					""
				};
				proxyType="CPGunner";
				displayname="Missile Gunner";
				proxyIndex=4;
				commanding=-4;
				elevationMode=0;
				initCamElev=0;
				minCamElev=-35;
				maxCamElev=35;
				initElev=0;
				turretAxis="";
				primaryGunner=0;
				forcehidegunner=1;
				gunnerName="Missle Gunner";
				memoryPointGun[]=
				{
					"rocket_2_end",
					"rocket_1_end"
				};
				gunnerForceOptics=0;
				inGunnerMayFire=1;
				minTurn=-20;
				maxTurn=20;
				missileBeg="";
				missileEnd="";
				turretFollowFreeLook=1;
				animationSourceGun="maingun_rocket";
				gun="maingun_rocket";
				animationSourceBody="MainTurret_rocket";
				body="MainTurret_rocket";
				initTurn=0;
				cameraDir="";
				LODTurnedIn=1100;
				LodOpticsIn=1;
				discreteDistance[]={100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000};
				discreteDistanceInitIndex=2;
				discreteDistanceCameraPoint[]=
				{
					"eye"
				};
				turretInfoType="RscOptics_APC_Wheeled_01_gunner";
				memoryPointGunnerOptics="rocketview";
				gunnerOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_02_F";
				primaryObserver=0;
				class ViewOptics: RCWSOptics
				{
					visionMode[]=
					{
						"Normal",
						"TI"
					};
				};
				minelev=-50;
				maxelev=45;
				magazines[]=
				{
					"3AS_24Rnd_Jug_Missile_Mag"
				};
				ejectDeadGunner=1;
				usepip=2;
				startEngine=0;
			};
			class Cargoturret_01: NewTurret
			{
				gunnerAction="passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerInAction="passenger_flatground_4_vehicle_passenger_stand_1";
				gunnerGetInAction="GetInLow";
				gunnerGetOutAction="GetOutLow";
				gunnerName="Crows Nest";
				memoryPointsGetInGunner="pos driver";
				memoryPointsGetInGunnerDir="pos driver dir";
				gunnerCompartments="Compartment1";
				proxyType="CPCommander";
				displayname="Crows Nest";
				proxyIndex=1;
				startEngine=0;
				isPersonTurret=1;
				inGunnerMayFire=1;
				outgunnermayfire=1;
				LODTurnedIn=1;
				LODOpticsIn=1;
				LODTurnedout=1;
				showAsCargo=0;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				isCopilot=0;
				hideWeaponsGunner=0;
				forceHideGunner=1;
				turretFollowFreeLook=0;
				viewGunnerInExternal=1;
				disableSoundAttenuation=1;
				canEject=1;
				commanding=0;
				allowLauncherIn=0;
				allowLauncherout=0;
				class TurnIn
				{
					limitsArrayTop[]=
					{
						{26,-26},
						{44.852001,95}
					};
					limitsArrayBottom[]=
					{
						{-6.1384001,-23.5436},
						{-9.0489998,-13.7683},
						{-23.624901,94.896301}
					};
				};
			};
		};
		class UserActions
		{
			class Crow_nest_down
			{
				displayName="Crows nest down";
				position="post_action";
				radius=10;
				onlyForPlayer=0;
				condition="this animationSourcePhase ""crownest"" == 5 AND (alive this)";
				statement="this animateSource [""crownest"",0]";
			};
			class Crow_nest_Up: Crow_nest_down
			{
				displayName="Crows nest up";
				condition="this animationSourcePhase ""crownest"" == 0  AND (alive this)";
				statement="this animateSource [""crownest"",5]";
			};
			class Close_rockets
			{
				displayName="Open Rocket Pods";
				position="missile_action";
				radius=10;
				onlyForPlayer=0;
				condition="(this animationSourcePhase ""rocket_move"" == 0) AND (alive this) ";
				statement="this animateSource [""rocket_move"",1]; vehicle player addWeaponTurret [""3AS_Jug_Missiles"",[3]];";
			};
			class Open_rockets: Close_rockets
			{
				displayName="Close Rocket Pods";
				condition="(this animationSourcePhase ""rocket_move"" == 1)  AND (alive this)";
				statement="this animateSource [""rocket_move"",0]; vehicle player removeWeaponTurret [""3AS_Jug_Missiles"",[3]];";
			};
		};
		class EventHandlers: EventHandlers
		{
			fired="[_this select 0,_this select 6,'missile_move','MissileBase'] call BIS_fnc_missileLaunchPositionFix; _this call (uinamespace getvariable 'BIS_fnc_effectFired');";
		};
		class AnimationSources: AnimationSources
		{
			class crownest
			{
				source="user";
				animPeriod=3;
				initPhase=0;
			};
			class rocket_move
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Revolving
			{
				source="revolving";
				weapon="3AS_Jug_Missiles";
			};
			class Revolving_SAM
			{
				source="revolving";
				weapon="3AS_Jug_SAM";
			};
		};
		viewCargoShadowDiff=0.050000001;
		viewCargoShadowAmb=0.5;
		getInAction="GetInlow";
		getOutAction="GetOutlow";
		cargoGetInAction[]=
		{
			"GetInAMV_cargo"
		};
		cargoGetOutAction[]=
		{
			"GetOutLow"
		};
		class Exhausts
		{
			class Exhaust1
			{
				position="exhaust";
				direction="exhaust_dir";
				effect="ExhaustsEffectAMV";
			};
		};
		engineStartSpeed=5;
		class NVGMarkers
		{
			class NVGMarker01
			{
				name="nvg_marker";
				color[]={0.029999999,0.003,0.003,1};
				ambient[]={0.003,0.00030000001,0.00030000001,1};
				brightness=0.001;
				blinking=1;
			};
		};
		explosionEffect="FuelExplosionBig";
		engineEffectSpeed=5;
		memoryPointsLeftEngineEffect="EngineEffectL";
		memoryPointsRightEngineEffect="EngineEffectR";
		class Reflectors
		{
			class Right
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=50;
				size=1;
				innerAngle=15;
				outerAngle=65;
				coneFadeCoef=10;
				position="Light_R_pos";
				direction="Light_R_dir";
				hitpoint="Light_R_hitpoint";
				selection="Light_R";
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
			};
			class Left: Right
			{
				position="Light_L_pos";
				direction="Light_L_dir";
				hitpoint="Light_L_hitpoint";
				selection="Light_L";
			};
			class Left2: Right
			{
				position="Light_L_pos2";
				direction="Light_L_dir2";
				hitpoint="Light_L_2_hitpoint";
				selection="Light_L_2";
			};
			class Right2: Right
			{
				position="Light_R_pos2";
				direction="Light_R_dir2";
				hitpoint="Light_R_2_hitpoint";
				selection="Light_R_2";
			};
		};
		aggregateReflectors[]=
		{
			
			{
				"Left"
			},
			
			{
				"Right"
			},
			
			{
				"Left2"
			},
			
			{
				"Right2"
			}
		};
		selectionFireAnim="";
		class RenderTargets
		{
			class mirror_l
			{
				renderTarget="mirror_l";
				class Camera
				{
					pointPosition="PIP0_pos";
					pointDirection="PIP0_dir";
					renderVisionMode=4;
					renderQuality=2;
					fov=0.69999999;
				};
			};
			class mirror_r
			{
				renderTarget="mirror_r";
				class Camera
				{
					pointPosition="PIP1_pos";
					pointDirection="PIP1_dir";
					renderVisionMode=4;
					renderQuality=2;
					fov=0.69999999;
				};
			};
		};
		transportSoldier=36;
		cargoProxyIndexes[]={1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
		getInProxyOrder[]={1,2,3,4,5,6,7,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36};
		showNVGCommander=1;
		showNVGGunner=1;
		showNVGDriver=1;
		numberPhysicalWheels=10;
		class VehicleTransport
		{
			class Cargo
			{
				canBeTransported=0;
			};
			class Carrier
			{
				cargoBayDimensions[]=
				{
					"cargo_dimension_1",
					"cargo_dimension_2"
				};
				disableHeightLimit=0;
				maxLoadMass=25000;
				cargoAlignment[]=
				{
					"center",
					"front"
				};
				cargoSpacing[]={0,0,0};
				exits[]=
				{
					"cargo_exit"
				};
				unloadingInterval=2;
				loadingDistance=5;
				loadingAngle=60;
				parachuteClassDefault="B_Parachute_02_F";
				parachuteHeightLimitDefault=5;
			};
		};
		soundGetIn[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234133,
			1
		};
		soundGetOut[]=
		{
			"A3\sounds_f\vehicles\armor\noises\get_in_out",
			0.56234133,
			1,
			20
		};
		soundTurnIn[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnOut[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnInInternal[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundTurnOutInternal[]=
		{
			"A3\Sounds_F\vehicles\noises\Turn_in_out",
			1.7782794,
			1,
			20
		};
		soundDammage[]=
		{
			"",
			0.56234133,
			1
		};
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_start",
			0.39810717,
			1
		};
		soundEngineOnExt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_start",
			0.56234133,
			1,
			200
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_stop",
			0.39810717,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_stop",
			0.56234133,
			1,
			200
		};
		soundBushCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1",
			0.17782794,
			1,
			100
		};
		soundBushCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2",
			0.17782794,
			1,
			100
		};
		soundBushCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3",
			0.17782794,
			1,
			100
		};
		soundBushCrash[]=
		{
			"soundBushCollision1",
			0.33000001,
			"soundBushCollision2",
			0.33000001,
			"soundBushCollision3",
			0.33000001
		};
		soundGeneralCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_1",
			1,
			1,
			100
		};
		soundGeneralCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_2",
			1,
			1,
			100
		};
		soundGeneralCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_3",
			1,
			1,
			100
		};
		soundGeneralCollision4[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_crash_default_4",
			1,
			1,
			100
		};
		soundCrashes[]=
		{
			"soundGeneralCollision1",
			0.25,
			"soundGeneralCollision2",
			0.25,
			"soundGeneralCollision3",
			0.25,
			"soundGeneralCollision4",
			0.25
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_1",
			1,
			1,
			200
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_2",
			1,
			1,
			200
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_3",
			1,
			1,
			200
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_building_4",
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
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_1",
			1,
			1,
			200
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_2",
			1,
			1,
			200
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_3",
			1,
			1,
			200
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_wood_4",
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
			0.16599999
		};
		ArmorCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_1",
			1,
			1,
			200
		};
		ArmorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_2",
			1,
			1,
			200
		};
		ArmorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_3",
			1,
			1,
			200
		};
		ArmorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\armors\tank_coll_armor_4",
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
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_01",
					0.3548134,
					1,
					200
				};
				frequency="0.95 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class Engine
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_02",
					0.39810717,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_03",
					0.44668359,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_06",
					0.50118721,
					1,
					250
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_07",
					0.56234133,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_08",
					0.63095737,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*camPos*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_engine_10",
					0.70794576,
					1,
					300
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*camPos*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class IdleThrust
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_01",
					0.56234133,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class EngineThrust
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_02",
					0.63095737,
					1,
					200
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_03",
					0.63095737,
					1,
					230
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_06",
					0.70794576,
					1,
					250
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_07",
					0.70794576,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_08",
					1,
					1,
					350
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_Thrust_ext
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\ext_exhaust_10",
					1.1220185,
					1,
					400
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*camPos*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class Idle_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_01",
					0.31622776,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class Engine_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_02",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_03",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_06",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_07",
					0.50118721,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_08",
					0.56234133,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_engine_10",
					0.63095737,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class IdleThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_01",
					0.3548134,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(10/ 2300),(200/ 2300)])*0.15";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(10/ 2300),(200/ 2300)]) * ((rpm/ 2300) factor[(500/ 2300),(425/ 2300)]))";
			};
			class EngineThrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_02",
					0.39810717,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(430/ 2300),(730/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(430/ 2300),(510/ 2300)]) * ((rpm/ 2300) factor[(730/ 2300),(620/ 2300)]))";
			};
			class Engine1_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_03",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(630/ 2300),(1000/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(600/ 2300),(720/ 2300)]) * ((rpm/ 2300) factor[(1100/ 2300),(840/ 2300)]))";
			};
			class Engine2_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_06",
					0.44668359,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(850/ 2300),(1300/ 2300)])*0.2";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(800/ 2300),(1000/ 2300)]) * ((rpm/ 2300) factor[(1300/ 2300),(1100/ 2300)]))";
			};
			class Engine3_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_07",
					0.50118721,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1100/ 2300),(1600/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1100/ 2300),(1270/ 2300)]) * ((rpm/ 2300) factor[(1550/ 2300),(1380/ 2300)]))";
			};
			class Engine4_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_08",
					0.56234133,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1400/ 2300),(2000/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*(((rpm/ 2300) factor[(1380/ 2300),(1500/ 2300)]) * ((rpm/ 2300) factor[(2000/ 2300),(1700/ 2300)]))";
			};
			class Engine5_Thrust_int
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\armor\APC\APC1\int_exhaust_10",
					0.63095737,
					1
				};
				frequency="0.8 + ((rpm/ 2300) factor[(1700/ 2300),(2300/ 2300)])*0.1";
				volume="engineOn*(1-camPos)*(0.4+(0.6*(thrust factor[0.1,1])))*((rpm/ 2300) factor[(1600/ 2300),(2100/ 2300)])";
			};
			class NoiseInt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_int_1",
					0.50118721,
					1
				};
				frequency="1";
				volume="(1-camPos)*(angVelocity max 0.04)*(Speed factor[4, 15])";
			};
			class NoiseExt
			{
				sound[]=
				{
					"A3\sounds_f\vehicles\armor\noises\noise_tank_ext_1",
					0.63095737,
					1,
					150
				};
				frequency="1";
				volume="camPos*(angVelocity max 0.04)*(Speed factor[4, 15])";
			};
			class TiresRockOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*rock*(Speed factor[2, 20])";
			};
			class TiresSandOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-sand1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*sand*(Speed factor[2, 20])";
			};
			class TiresGrassOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_dirt_soft_2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*grass*(Speed factor[2, 20])";
			};
			class TiresMudOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext-tires-mud2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*mud*(Speed factor[2, 20])";
			};
			class TiresGravelOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_gravel_1",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*gravel*(Speed factor[2, 20])";
			};
			class TiresAsphaltOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\ext_tires_asfalt_2",
					1,
					1,
					60
				};
				frequency="1";
				volume="camPos*asphalt*(Speed factor[2, 20])";
			};
			class NoiseOut
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					1.5848932,
					1,
					90
				};
				frequency="1";
				volume="camPos*(damper0 max 0.02)*(Speed factor[0, 8])";
			};
			class TiresRockIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_1",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*rock*(Speed factor[2, 20])";
			};
			class TiresSandIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-sand2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*sand*(Speed factor[2, 20])";
			};
			class TiresGrassIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_dirt_soft_2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*grass*(Speed factor[2, 20])";
			};
			class TiresMudIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int-tires-mud2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*mud*(Speed factor[2, 20])";
			};
			class TiresGravelIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_gravel_1",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*gravel*(Speed factor[2, 20])";
			};
			class TiresAsphaltIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\tires\int_tires_asfalt_2",
					0.70794576,
					1
				};
				frequency="1";
				volume="(1-camPos)*asphalt*(Speed factor[2, 20])";
			};
			class NoiseIn
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\noise_int_car_3",
					0.50118721,
					1
				};
				frequency="1";
				volume="(damper0 max 0.1)*(Speed factor[0, 8])*(1-camPos)";
			};
			class breaking_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 10])";
			};
			class acceleration_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_ext_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 10])";
			};
			class acceleration_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_ext_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02",
					1,
					1,
					100
				};
				frequency=1;
				volume="engineOn*camPos*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 6])";
			};
			class acceleration_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_int_road
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
			};
			class breaking_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_04_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[-0.2, -0.3])*(Speed factor[2, 6])";
			};
			class acceleration_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(LongSlipDrive factor[0.2, 0.3])*(Speed factor[10, 1])";
			};
			class turn_left_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[0.15, 0.3])*(Speed factor[0, 10])";
			};
			class turn_right_int_dirt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\soft\noises\slipping_tires_loop_02_int",
					1,
					1
				};
				frequency=1;
				volume="engineOn*(1-camPos)*(latSlipDrive factor[-0.15, -0.3])*(Speed factor[0, 10])";
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
					"A3\Sounds_F\vehicles\noises\rain1_int",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos)*(rain - rotorSpeed/2)*2";
			};
		};
	};
	class FST_B_Jug_01_base_F: FST_Jug_base_F
	{
		author="Daara";
		_generalMacro="B_APC_Wheeled_01_base_F";
		side=1;
		faction="FST_Faction";
		editorSubcategory="FST_Ground_Vehicle";
		crew="FST_Trooper_P2_DC15S";
		typicalCargo[]=
		{
			"FST_Trooper_P2_DC15S"
		};
	};
	class FST_Jug: FST_B_Jug_01_base_F
	{
		author="Daara";
		class SimpleObject
		{
			eden=1;
			animate[]=
			{
				
				{
					"damagehide",
					0
				},
				
				{
					"damagehidevez",
					0
				},
				
				{
					"damagehidehlaven",
					0
				},
				
				{
					"wheel_1_1_destruct",
					0
				},
				
				{
					"wheel_1_2_destruct",
					0
				},
				
				{
					"wheel_1_3_destruct",
					0
				},
				
				{
					"wheel_1_4_destruct",
					0
				},
				
				{
					"wheel_2_1_destruct",
					0
				},
				
				{
					"wheel_2_2_destruct",
					0
				},
				
				{
					"wheel_2_3_destruct",
					0
				},
				
				{
					"wheel_2_4_destruct",
					0
				},
				
				{
					"wheel_1_1_destruct_unhide",
					0
				},
				
				{
					"wheel_1_2_destruct_unhide",
					0
				},
				
				{
					"wheel_1_3_destruct_unhide",
					0
				},
				
				{
					"wheel_1_4_destruct_unhide",
					0
				},
				
				{
					"wheel_2_1_destruct_unhide",
					0
				},
				
				{
					"wheel_2_2_destruct_unhide",
					0
				},
				
				{
					"wheel_2_3_destruct_unhide",
					0
				},
				
				{
					"wheel_2_4_destruct_unhide",
					0
				},
				
				{
					"wheel_1_1",
					0
				},
				
				{
					"wheel_2_1",
					0
				},
				
				{
					"wheel_1_2",
					0
				},
				
				{
					"wheel_1_3",
					0
				},
				
				{
					"wheel_2_2",
					0
				},
				
				{
					"wheel_2_3",
					0
				},
				
				{
					"wheel_1_4",
					0
				},
				
				{
					"wheel_2_4",
					0
				},
				
				{
					"daylights",
					0
				},
				
				{
					"wheel_1_1_damage",
					0
				},
				
				{
					"wheel_1_2_damage",
					0
				},
				
				{
					"wheel_1_3_damage",
					0
				},
				
				{
					"wheel_1_4_damage",
					0
				},
				
				{
					"wheel_2_1_damage",
					0
				},
				
				{
					"wheel_2_2_damage",
					0
				},
				
				{
					"wheel_2_3_damage",
					0
				},
				
				{
					"wheel_2_4_damage",
					0
				},
				
				{
					"wheel_1_1_damper_damage_backanim",
					0
				},
				
				{
					"wheel_1_2_damper_damage_backanim",
					0
				},
				
				{
					"wheel_1_3_damper_damage_backanim",
					0
				},
				
				{
					"wheel_1_4_damper_damage_backanim",
					0
				},
				
				{
					"wheel_2_1_damper_damage_backanim",
					0
				},
				
				{
					"wheel_2_2_damper_damage_backanim",
					0
				},
				
				{
					"wheel_2_3_damper_damage_backanim",
					0
				},
				
				{
					"wheel_2_4_damper_damage_backanim",
					0
				},
				
				{
					"wheel_1_1_damper",
					0.47999999
				},
				
				{
					"wheel_2_1_damper",
					0.49000001
				},
				
				{
					"wheel_1_2_damper",
					0.49000001
				},
				
				{
					"wheel_1_3_damper",
					0.5
				},
				
				{
					"wheel_2_2_damper",
					0.49000001
				},
				
				{
					"wheel_2_3_damper",
					0.5
				},
				
				{
					"wheel_1_4_damper",
					0.50999999
				},
				
				{
					"wheel_2_4_damper",
					0.56999999
				},
				
				{
					"steering_1_1",
					0
				},
				
				{
					"steering_2_1",
					0
				},
				
				{
					"steering_1_2",
					0
				},
				
				{
					"steering_2_2",
					0
				},
				
				{
					"hatchdriver",
					0
				},
				
				{
					"mainturret",
					0
				},
				
				{
					"obsturret",
					0
				},
				
				{
					"turretbase",
					0
				},
				
				{
					"maingun",
					0
				},
				
				{
					"obsgun",
					0
				},
				
				{
					"rocket_1",
					0
				},
				
				{
					"rocket_2",
					0
				},
				
				{
					"damagehlaven",
					0
				},
				
				{
					"vrtulea",
					0
				},
				
				{
					"vrtuleb",
					0
				},
				
				{
					"poklop_gunner",
					0
				},
				
				{
					"poklop_commander",
					0
				},
				
				{
					"zasleh_rot",
					0
				},
				
				{
					"zasleh2_rot",
					81.639999
				},
				
				{
					"zasleh_hide",
					0
				},
				
				{
					"reverse_light",
					0
				}
			};
			hide[]=
			{
				"clan",
				"zasleh2",
				"zasleh_1",
				"light_l",
				"light_r",
				"light_r2",
				"light_l2",
				"zadni svetlo",
				"brzdove svetlo",
				"podsvit pristroju",
				"poskozeni"
			};
			verticalOffset=2.3859999;
			verticalOffsetWorld=-0.075999998;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		editorPreview="\3as\3as_Jug\images\3as_jug.jpg";
		_generalMacro="B_APC_Wheeled_01_cannon_F";
		scope=2;
		accuracy=0.30000001;
		displayName="[41st] HAVw A6 Juggernaut";
		class Library
		{
			libTextDesc="$STR_A3_CFGVEHICLES_APC_WHEELED_01_LIBRARY0";
		};
		model="3as\3as_Jug\model\3as_jug.p3d";
		icon="3AS\3as_Jug\data\ui\Jug_top_ca.paa";
		unitInfoType="RscUnitInfoTank";
		radarType=8;
		driverCanSee="4+8+2+32+16";
		gunnerCanSee="4+2+8+32+16";
		threat[]={1,1,0.30000001};
		hiddenSelections[]={};
		hiddenSelectionsTextures[]={};
		class EventHandlers: EventHandlers
		{
			fired="[_this select 0,_this select 6,'missile_move','MissileBase'] call BIS_fnc_missileLaunchPositionFix; _this call (uinamespace getvariable 'BIS_fnc_effectFired');";
		};
	};
};
