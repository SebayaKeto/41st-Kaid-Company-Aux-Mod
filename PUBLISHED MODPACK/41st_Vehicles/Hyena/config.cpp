class CfgPatches
{
	class FST_Hyena
	{
		units[]=
		{
			"FST_CIS_Hyena_Bomber"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Data_F_Tank_Loadorder"
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
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class Eventhandlers;
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
	};
	class Plane_Fighter_03_base_F: Plane_Base_F
	{
		class Turrets
		{
		};
		class HitPoints: HitPoints
		{
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
	class FST_Hyena_Base_F: Plane_Fighter_03_dynamicLoadout_base_F
	{
		class EjectionSystem
		{
			EjectionSeatEnabled=0;
		};
		author="$STR_3AS_Studio";
		forceInGarage=1;
		gearretracting=1;
		scope=2;
		scopeCurator=2;
		side=0;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		displayName="[41st] Vulture Droid";
		vtol=4;
		crew="FST_Droid_B1_OOM";
		typicalCargo[]=
		{
			"FST_Droid_B1_OOM"
		};
		driverForceOptics=1;
		viewDriverInExternal=0;
		LODDriverTurnedIn=1;
		destrType="DestructWreck";
		driverAction="Plane_Fighter_03_pilot";
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		driverCompartments="Compartment1";
		driverCanEject=0;
		driverLeftHandAnimName="throttle_pilot";
		driverRightHandAnimName="throttle_pilot";
		driverleftleganimname="pedal";
		driverrightleganimname="pedal";
		memoryPointTaskMarker="TaskMarker_1_pos";
		memoryPointsGetInDriver="pos driver";
		memoryPointsGetInDriverDir="pos driver dir";
		memoryPointsGetInCargo="GetIn_pilot_pos";
		memoryPointsGetInCargoDir="GetIn_pilot_dir";
		class ViewPilot: ViewPilot
		{
			initAngleX=0;
		};
		cargoAction[]=
		{
			"passenger_generic01_foldhands"
		};
		cargoGetInAction[]=
		{
			"GetInHigh"
		};
		cargoGetOutAction[]=
		{
			"GetOutHigh"
		};
		cargoCompartments[]=
		{
			"Compartment3"
		};
		class Exhausts
		{
			class Exhaust_main
			{
				position="exhaust1";
				direction="Exhaust1_dir";
				effect="ExhaustsEffectPlane";
			};
			class Exhaust_main2
			{
				position="exhaust2";
				direction="Exhaust2_dir";
				effect="ExhaustsEffectPlane";
			};
		};
		antiRollbarForceCoef=0;
		antiRollbarForceLimit=0;
		antiRollbarSpeedMin=50;
		antiRollbarSpeedMax=300;
		driverOpticsModel="\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
		editorPreview="\3as\3as_vulture\3as_Vulture_dynamicLoadout.jpg";
		model="3as\3as_vulture\model\vulture.p3d";
		picture="3as\3as_vulture\data\vulture_picture_co.paa";
		icon="3AS\3as_Vulture\data\ui\Vulture_top_ca.paa";
		hiddenselections[]=
		{
			"camo1"
		};
		hiddenselectionstextures[]=
		{
			"3as\3as_vulture\data\VultureDroid_CO.paa"
		};
		mapSize=20.5;
		geardowntime=2;
		gearuptime=2;
		fuelCapacity=2540;
		lightOnGear=1;
		damperSize=0.0099999998;
		damperForce=0.0099999998;
		damperDamping=0;
		formationX=30;
		formationZ=30;
		viewDriverShadowDiff=0.5;
		viewDriverShadowAmb=0.5;
		availableForSupportTypes[]={};
		driveOnComponent[]={};
		features="Randomization: No      <br />Camo selections: 2 - the main body, wings and gear      <br />Script door sources: None      <br />Script animations: None      <br />Executed scripts: None       <br />Firing from vehicles: No      <br />Slingload: No      <br />Cargo proxy indexes: None";
		weapons[]=
		{
			"3AS_Vulture_Cannon",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"3AS_300Rnd_Vulture_Shells",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		selectionFireAnim="zasleh";
		LockDetectionSystem=8;
		incomingMissileDetectionSystem="8 + 16";
		enableGPS=1;
		radarTarget=1;
		visualTarget=1;
		radarTargetSize=1;
		visualTargetSize=1.2;
		irTargetSize=1.2;
		namesound="Plane";
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
							maxRange=5000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=500;
							maxRange=3000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=120;
						maxTrackableSpeed=500;
					};
					class VisualSensorComponent: SensorTemplateVisual
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
							maxRange=3000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=26;
						angleRangeVertical=20;
						maxTrackableSpeed=100;
						aimDown=1;
						animDirection="pilotCameraRotY";
					};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange=13000;
							maxRange=13000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=9000;
							maxRange=9000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=6000;
						angleRangeHorizontal=360;
						angleRangeVertical=120;
						groundNoiseDistanceCoef=0.1;
					};
					class AntiRadiationSensorComponent: SensorTemplateAntiRadiation
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
							minRange=16000;
							maxRange=16000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						maxTrackableATL=100;
						maxTrackableSpeed=60;
						angleRangeHorizontal=60;
						angleRangeVertical=180;
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
				class Components
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
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
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
						resource="RscCustomInfoAirborneMiniMap";
					};
					class UAVDisplay
					{
						componentType="UAVFeedDisplayComponent";
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
						range[]={16000,8000,4000,2000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture="\A3\Air_F_Jets\Plane_Fighter_02\Data\UI\Fighter_02_3DEN_ca.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"3AS_CIS_Vulture_AA",
							"3AS_CIS_Vulture_HEAP"
						};
						attachment="";
						priority=13;
						maxweight=300;
						UIposition[]={0.60000002,0.44999999};
						name="3AS_Vulture_MFD";
					};
					class pylons2: pylons1
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=1;
					};
					class pylons3
					{
						hardpoints[]=
						{
							"3AS_CIS_Vulture_AA",
							"3AS_CIS_Vulture_HEAP"
						};
						attachment="";
						priority=11;
						maxweight=1050;
						UIposition[]={0.55000001,0.34999999};
						name="3AS_Vulture_MFD";
					};
					class pylons4: pylons3
					{
						UIposition[]={0.1,0.34999999};
						mirroredMissilePos=3;
					};
					class pylons5
					{
						hardpoints[]=
						{
							"3AS_CIS_Vulture_AA",
							"3AS_CIS_Vulture_HEAP"
						};
						attachment="";
						priority=9;
						maxweight=1200;
						UIposition[]={0.5,0.25};
						name="3AS_Vulture_MFD";
					};
					class pylons6: pylons5
					{
						UIposition[]={0.15000001,0.25};
						mirroredMissilePos=5;
					};
				};
				class Presets
				{
					class Default
					{
						displayName="$STR_vehicle_default";
						attachment[]={};
					};
					class AA
					{
						displayName="$STR_A3_cfgmagazines_titan_aa_dns";
						attachment[]=
						{
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA"
						};
					};
					class CAS
					{
						displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[]=
						{
							"3AS_PylonRack_Vulture_12Rnd_Rocket_HEAP",
							"3AS_PylonRack_Vulture_12Rnd_Rocket_HEAP",
							"3AS_PylonRack_Vulture_12Rnd_Rocket_HEAP",
							"3AS_PylonRack_Vulture_12Rnd_Rocket_HEAP",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA",
							"3AS_PylonRack_Vulture_1Rnd_Missile_AA"
						};
					};
				};
			};
		};
		memoryPointDriverOptics="PilotCamera_pos";
		memoryPointLDust="pos_dust_left";
		memoryPointRDust="pos_dust_right";
		memoryPointGun="nosegun";
		gunBeg[]=
		{
			"Usti hlavne1",
			"Usti hlavne2"
		};
		gunEnd[]=
		{
			"Konec hlavne1",
			"Konec hlavne2"
		};
		memoryPointLRocket="l_rocket_point";
		memoryPointRRocket="r_rocket_point";
		memoryPointCM[]=
		{
			"pos_flare_launcher_1",
			"pos_flare_launcher_2"
		};
		memoryPointCMDir[]=
		{
			"pos_flare_launcher_1_dir",
			"pos_flare_launcher_2_dir"
		};
		armor=65;
		armorStructural=2;
		armorLights=1;
		damageResistance=0.0040000002;
		epeImpulseDamageCoef=120;
		waterLeakiness=5.5;
		damageEffect="AirDestructionEffects";
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3as_vulture\data\vulture.rvmat",
				"A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_damage.rvmat",
				"A3\Air_F_Gamma\Plane_Fighter_03\Data\Plane_Fighter_03_body_1_destruct.rvmat"
			};
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				name="HitHull";
				visual="Hit_Hull";
				armor=3.5;
				explosionShielding=2.5;
				passThrough=1;
				radius=0.5;
				minimalHit=0.050000001;
				depends="0";
				material=-1;
			};
			class HitEngine: HitHull
			{
				name="HitEngine";
				visual="Hit_Engine";
				armor=2.5;
				explosionShielding=4;
				passThrough=0.80000001;
				radius=0.60000002;
				minimalHit=0.050000001;
			};
		};
		extCameraPosition[]={0,4,-25};
		class AnimationSources: AnimationSources
		{
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="3AS_Vulture_Cannon";
			};
			class canopy_hide
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class ejection_seat_hide
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class ejection_seat_motion
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		airBrake=1;
		airBrakeFrictionCoef=5;
		flaps=1;
		flapsFrictionCoef=0.31999999;
		gearsUpFrictionCoef=0.60000002;
		brakeDistance=360;
		wheelSteeringSensitivity=1.5;
		maxSpeed=950;
		altFullForce=6000;
		altNoForce=16000;
		rudderInfluence=0.89999998;
		aileronSensitivity=1.1;
		elevatorSensitivity=1.3;
		elevatorControlsSensitivityCoef=5;
		aileronControlsSensitivityCoef=5;
		rudderControlsSensitivityCoef=4;
		envelope[]={0,0.050000001,0.20999999,0.47,0.82999998,1.29,1.86,2.54,3.3099999,4.1900001,5.1799998,6.2600002,7.4499998,8.75,10.1,10.5,9.6999998,9,8.3999996,7.8000002,7.3000002,7,6.8000002,6.5999999,6.5,6.4000001};
		thrustCoef[]={2.5,3.5,3.5999999,3.8,4,4.5,5,4.5,3.5,3,2.7,2.5,2.0999999,2,1,1};
		elevatorCoef[]={0,0.80000001,0.89999998,1,1.1,1.2,1.2,1.3,1.3,1.3,1.4,1.4,1.4};
		aileronCoef[]={0,0.5,1,1.2,1.3,1.2,1.1};
		rudderCoef[]={0.5,1.8,2.5999999,2.75,2.8,2.8499999,2.9000001,2.95,2.98,3.01,2.7,1.1,0.89999998,0.69999999,0.5,0.30000001};
		angleOfIndicence="-0.5*3.1415/180";
		draconicForceXCoef=6.5;
		draconicForceYCoef=8.5;
		draconicForceZCoef=9;
		draconicTorqueXCoef[]={6.4000001,7.5,8.1999998,9,9.6999998,9.8999996,10.1,10.2,10.2,10.3,10.3};
		draconicTorqueYCoef[]={14.6,10.1,3.0999999,0.89999998,0.1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
		airFrictionCoefs0[]={0,0,0};
		airFrictionCoefs1[]={0.1,0.5,0.0082};
		airFrictionCoefs2[]={0.001,0.0049999999,7.5000004e-005};
		gunAimDown=0;
		landingSpeed=215;
		stallSpeed=50;
		stallWarningTreshold=0.12;
		acceleration=600;
		landingAoa="4*3.1415/180";
		unitInfoType="RscOptics_CAS_Pilot";
		driverWeaponsInfoType="RscOptics_CAS_01_TGP";
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
					visionMode[]=
					{
						"Normal",
						"NVG",
						"Ti"
					};
					thermalMode[]={0,1};
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
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
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				};
				class Narrow: Wide
				{
					opticsDisplayName="NFOV";
					initFov="(4.8 / 120)";
					minFov="(4.8 / 120)";
					maxFov="(4.8 / 120)";
					gunnerOpticsModel="\A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				};
			};
			minTurn=-180;
			maxTurn=180;
			initTurn=0;
			minElev=0;
			maxElev=90;
			initElev=15;
			maxXRotSpeed=1;
			maxYRotSpeed=1;
			maxMouseXRotSpeed=0.5;
			maxMouseYRotSpeed=0.5;
			pilotOpticsShowCursor=1;
			controllable=1;
		};
		attenuationEffectType="PlaneAttenuation";
		soundGetIn[]=
		{
			"A3\Sounds_F\vehicles\air\CAS_01\getin_wipeout",
			1,
			1,
			40
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\air\Plane_Fighter_03\getout",
			1,
			1,
			40
		};
		cabinOpenSound[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\FX_Plane_Fighter_02_cabine_open_ext",
			3.1622801,
			1,
			40
		};
		cabinCloseSound[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\FX_Plane_Fighter_02_cabine_close_ext",
			3.1622801,
			1,
			40
		};
		cabinOpenSoundInternal[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\FX_Plane_Fighter_02_cabine_open_int",
			10,
			1,
			40
		};
		cabinCloseSoundInternal[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\FX_Plane_Fighter_02_cabine_close_int",
			10,
			1,
			40
		};
		soundWaterCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_1",
			1.41254,
			1,
			500
		};
		soundWaterCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\planes\plane_crash_water_2",
			1.41254,
			1,
			500
		};
		soundWaterCrashes[]=
		{
			"soundWaterCollision1",
			0.5,
			"soundWaterCollision2",
			0.5
		};
		buildCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		buildCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		buildCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		buildCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
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
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_1",
			3.1622801,
			1,
			900
		};
		WoodCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_2",
			3.1622801,
			1,
			900
		};
		WoodCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_6",
			3.1622801,
			1,
			900
		};
		WoodCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_wood_ext_8",
			3.1622801,
			1,
			900
		};
		soundWoodCrash[]=
		{
			"woodCrash0",
			0.25,
			"woodCrash1",
			0.25,
			"woodCrash2",
			0.25,
			"woodCrash3",
			0.25
		};
		armorCrash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		armorCrash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		armorCrash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		armorCrash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
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
		Crash0[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_1",
			1,
			1,
			900
		};
		Crash1[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_2",
			1,
			1,
			900
		};
		Crash2[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_3",
			1,
			1,
			900
		};
		Crash3[]=
		{
			"A3\Sounds_F\vehicles\crashes\cars\cars_coll_big_default_ext_4",
			1,
			1,
			900
		};
		soundCrashes[]=
		{
			"Crash0",
			0.25,
			"Crash1",
			0.25,
			"Crash2",
			0.25,
			"Crash3",
			0.25
		};
		soundDammage[]=
		{
			"",
			0.56234097,
			1
		};
		soundEngineOnInt[]=
		{
			"3AS\3as_vulture\sounds\VultureEngineON.ogg",
			1,
			1
		};
		soundEngineOnExt[]=
		{
			"3AS\3as_vulture\sounds\VultureEngineON.ogg",
			1.75,
			1,
			300
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\O_Plane_Fighter_02_engine_shut_int",
			1,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_02\O_Plane_Fighter_02_engine_shut_ext",
			1.75,
			1,
			300
		};
		soundLocked[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedOn1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_lockedon2",
			1,
			1.5
		};
		soundGearUp[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_up",
			2.25,
			1,
			250
		};
		soundGearDown[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_gear_down",
			2.25,
			1,
			250
		};
		soundFlapsUp[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Up",
			1.5,
			1,
			150
		};
		soundFlapsDown[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_Flaps_Down",
			1.5,
			1,
			150
		};
		soundSetSonicBoom[]=
		{
			"Plane_Fighter_SonicBoom_SoundSet"
		};
		class Sounds
		{
			soundSets[]=
			{
				"3AS_Vulture_EngineLowExt_SoundSet",
				"3AS_Vulture_EngineHighExt_SoundSet",
				"3AS_Vulture_ForsageExt_SoundSet",
				"3AS_Vulture_WindNoiseExt_SoundSet",
				"3AS_Vulture_EngineExt_Middle_SoundSet",
				"3AS_Vulture_Voice_SoundSet",
				"3AS_Vulture_EngineExt_Dist_Front_SoundSet",
				"3AS_Vulture_EngineExt_Dist_Rear_SoundSet",
				"3AS_Vulture_EngineLowInt_SoundSet",
				"3AS_Vulture_EngineHighInt_SoundSet",
				"3AS_Vulture_ForsageInt_SoundSet",
				"3AS_Vulture_WindNoiseInt_SoundSet",
				"3AS_Vulture_VelocityInt_SoundSet"
			};
		};
		defaultUserMFDvalues[]={0.15000001,1,0.15000001,0.64999998};
		maxOmega=2000;
		brakeIdleSpeed=1;
		class TextureSources
		{
		};
		animationList[]={};
		textureList[]={};
		class Reflectors
		{
			class Gear_Front_light_1
			{
				position="light_1_1_source";
				direction="light_1_1_target";
				hitpoint="HitLight1";
				selection="Light_1";
				color[]={7000,7500,10000,1};
				ambient[]={100,100,100,0};
				intensity=45;
				size=1;
				innerAngle=15;
				outerAngle=20;
				coneFadeCoef=1;
				useFlare=1;
				dayLight=0;
				FlareSize=4;
				class Attenuation
				{
					start=1;
					constant=0;
					linear=0;
					quadratic=4;
					hardLimitStart=150;
					hardLimitEnd=300;
				};
			};
		};
		class MarkerLights
		{
			class CollisionLight_wingtip_red
			{
				color[]={0.80000001,0,0};
				ambient[]={0.079999998,0,0};
				intensity=90;
				name="wingtip_marker_light_red";
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
			class CollisionLight_wingtip_green: CollisionLight_wingtip_red
			{
				color[]={0,0.80000001,0};
				ambient[]={0,0.079999998,0};
				name="wingtip_marker_light_green";
			};
			class CollisionLightWhite1
			{
				color[]={1,1,1};
				ambient[]={0.1,0.1,0.1};
				name="marker_light_white_rear";
				intensity=90;
				drawLight=1;
				drawLightSize=0.34999999;
				drawLightCenterSize=0.050000001;
				activeLight=0;
				dayLight=0;
				useFlare=0;
				blinking=1;
				blinkingPattern[]={0.1,0.89999998};
				blinkingStartsOn=1;
				blinkingPatternGuarantee=1;
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
			class CollisionLightWhite2: CollisionLightWhite1
			{
				name="marker_light_white";
			};
		};
		class WingVortices
		{
			class BodyLeft_inner
			{
				effectName="WingVortices";
				position="body_vapour_L_S";
			};
			class BodyRight_inner: BodyLeft_inner
			{
				position="body_vapour_R_S";
			};
			class BodyLeft_outer: BodyLeft_inner
			{
				position="body_vapour_L_E";
			};
			class BodyRight_outer: BodyLeft_inner
			{
				position="body_vapour_R_E";
			};
		};
		class Library
		{
			libEnable=1;
			libTextDesc="";
		};
		class Eventhandlers: Eventhandlers
		{
			init="_this # 0 confirmSensorTarget [west, true];";
		};
	};
	class FST_CIS_Hyena_Bomber: FST_Hyena_Base_F
	{
		class SimpleObject
		{
			eden=1;
			verticalOffset=2.346;
			verticalOffsetWorld=-0.127;
			init="[this, '', []] call bis_fnc_initVehicle";
		};
		author="Daara";
		scope=2;
		side=0;
		forceInGarage=0;
		scopeCurator=2;
		faction="FST_BattleDroids_Faction";
		editorSubcategory="FST_Air_Vehicle";
		displayName="[41st] Hyena Bomber Droid";
		threat[]={0.2,0.5,1};
		class Components: Components
		{
			class TransportPylonsComponent: TransportPylonsComponent
			{
				class pylons: pylons
				{
					class pylons1: pylons1
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
					class pylons2: pylons2
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
					class pylons3: pylons3
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
					class pylons4: pylons4
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
					class pylons5: pylons5
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
					class pylons6: pylons6
					{
						attachment="PylonRack_Bomb_GBU12_x2";
					};
				};
			};
		};
	};
};
