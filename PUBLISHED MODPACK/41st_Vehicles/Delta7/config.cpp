class CfgPatches
{
	class FST_Delta7
	{
		requiredAddons[]=
		{
			"A3_Air_F_Jets"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Delta7",
			"FST_Delta7_Daara",
		};
		weapons[]={};
		author="$STR_3AS_Studio";
	};
};
class Extended_init_EventHandlers
{
	class FST_Delta7
	{
		class laat_init_eh
		{
			init="(_this) spawn ls_vehicle_fnc_ImpulsorMonitor; [_this select 0,"""",[7,8,9,10]] call ls_vehicle_fnc_laatCargoTurretPhase;";
		};
	};
	class FST_Delta7_Daara
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
	};
	class Plane_Base_F: Plane
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
		};
		class Components;
		class ViewPilot;
	};
	class FST_Delta7: Plane_Base_F
	{
		class EjectionSystem
		{
			EjectionSeatEnabled=0;
		};
		scope=2;
		vehicleClass="Air";
		side=1;
		displayName="[41st] Delta-7 Interceptor";
		author="Daara";
		simulation="airplaneX";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		typicalCargo[]=
		{
			"FST_Pilot_P1"
		};
		crewVulnerable=1;
		driverAction="Plane_Fighter_03_pilot";
		driverLeftHandAnimName="throttle";
		driverRightHandAnimName="stick_pilot";
		precisegetinout=1;
		driverCanEject=1;
		cargoCanEject=0;
		ejectDeadGunner=0;
		ejectDeadCargo=0;
		ejectDeadDriver=0;
		disableInventory=0;
		getInAction="GetInLow";
		getOutAction="GetOutLow";
		getInRadius=5;
		editorPreview="\3AS\3AS_Delta7\data\ui\Delta_7_F.jpg";
		picture="3AS\3AS_Delta7\data\ui\Delta_side_ca.paa";
		icon="3AS\3AS_Delta7\data\ui\Delta_top_ca.paa";
		mapSize=16.25;
		model="\3AS\3AS_Delta7\3AS_Delta7_F.p3d";
		animated=1;
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2",
			"camo3"
		};
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Delta7\data\Delta7_Hull_co.paa",
			"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
			"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
			"3as\3as_delta7\data\delta7_interfaces_ca.paa"
		};
		weapons[]=
		{
			"FST_ARC_Light_Canon",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"FST_ARC_1000Rnd_Heavy_shells",
			"FST_ARC_1000Rnd_Heavy_shells",
			"FST_ARC_1000Rnd_Heavy_shells",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine"
		};
		cabinOpening=1;
		gearRetracting=1;
		geardowntime=3;
		gearuptime=3.9000001;
		lightOnGear=1;
		damperSize=0.0099999998;
		damperForce=0.0099999998;
		damperDamping=0;
		canFloat=0;
		formationX=25;
		formationZ=25;
		fuelCapacity=1550;
		availableForSupportTypes[]=
		{
			"CAS_Bombing"
		};
		driveOnComponent[]={};
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
							minRange=0;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=1;
							viewDistanceLimitCoef=1;
						};
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						maxTrackableSpeed=600;
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
							minRange=0;
							maxRange=10000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=6000;
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
							minRange=0;
							maxRange=32000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
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
							minRange=0;
							maxRange=14000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=14000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=10000;
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
							minRange=0;
							maxRange=6000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
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
							minRange=0;
							maxRange=8000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
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
						range[]={2000,4000,8000,16000,30000};
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
						range[]={8000,2000,4000,16000,30000};
						resource="RscCustomInfoSensors";
					};
				};
			};
			class TransportPylonsComponent
			{
				UIPicture="3as\3as_arc170\data\plane_arc_pylon_ca.paa";
				class pylons
				{
					class pylons1
					{
						hardpoints[]=
						{
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
						attachment="PylonRack_Missile_BIM9X_x2";
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
						hardpoints[]=
						{
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
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
							"B_AMRAAM_D_RAIL",
							"B_AMRAAM_D_DUAL_RAIL",
							"B_AGM65_RAIL",
							"B_AGM65_DUAL_RAIL",
							"ARC_AGM_PYLON",
							"B_HARM_RAIL",
							"DAGR",
							"B_BOMB_PYLON",
						};
						attachment="PylonRack_Missile_AMRAAM_D_x1";
						priority=7;
						maxweight=5000;
						UIposition[]={0.60000002,0.44999999};
					};
					class pylons6: pylons5
					{
						UIposition[]={0.050000001,0.44999999};
						mirroredMissilePos=5;
					};
				};
				class presets
				{
					class empty
					{
						displayName="$STR_empty";
						attachment[]={};
					};
					class AA
					{
						displayName="$STR_A3_cfgmagazines_titan_aa_dns";
						attachment[]=
						{
							"PylonRack_Missile_BIM9X_x1",
							"PylonRack_Missile_BIM9X_x1",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"PylonRack_Missile_AMRAAM_D_x1",
							"PylonRack_Missile_AMRAAM_D_x1"
						};
					};
					class CAS
					{
						displayName="$STR_A3_CAS_PRESET_DISPLAYNAME";
						attachment[]=
						{
							"PylonRack_Missile_BIM9X_x1",
							"PylonRack_Missile_BIM9X_x1",
							"PylonMissile_1Rnd_Bomb_04_F",
							"PylonMissile_1Rnd_Bomb_04_F",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM",
							"3as_PylonRack_ARC_6Rnd_Missile_AGM"
						};
					};
				};
			};
		};
		memoryPointLDust="pos_dust_left";
		memoryPointRDust="pos_dust_right";
		memoryPointGun[]=
		{
			"konec hlavne",
			"konec hlavne1",
			"konec hlavne2",
			"konec hlavne3"
		};
		memoryPointLMissile="l strela";
		memoryPointRMissile="p strela";
		memoryPointLRocket="l raketa";
		memoryPointRRocket="p raketa";
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
		memoryPointsGetInDriver="pos_driver";
		memoryPointsGetInDriverDir="pos_driver_dir";
		memoryPointDriverOptics="pos_PilotCamera";
		memoryPointsGetInDriverPrecise="pos_getin_driver_precise";
		slingLoadCargoMemoryPoints[]=
		{
			"SlingLoadCargo1",
			"SlingLoadCargo2",
			"SlingLoadCargo3",
			"SlingLoadCargo4"
		};
		selectionClan="clan";
		selectionDashboard="backlighting";
		armor=300;
		armorStructural=2;
		damageResistance=0.0040000002;
		epeImpulseDamageCoef=120;
		waterLeakiness=1.5;
		destrType="DestructWreck";
		minTotalDamageThreshold=0.0080000004;
		class Damage
		{
			tex[]={};
			mat[]=
			{
				"3as\3AS_Delta7\data\Delta7_Hull.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_damage.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_destruct.rvmat",
				"3as\3AS_Delta7\data\Delta7_Landing_Gear.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_02_damage.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_02_destruct.rvmat",
				"3as\3AS_Delta7\data\Delta7_Cockpit.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_damage.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_destruct.rvmat",
				"3as\3AS_Delta7\data\Delta7_Interfaces.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_damage.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_fuselage_01_destruct.rvmat",
				"3as\3AS_Delta7\data\Delta7_Glass.rvmat",
				"3as\3AS_Delta7\data\Delta7_Glass.rvmat",
				"a3\air_f_jets\plane_fighter_04\data\Fighter_04_glass_01_damage.rvmat"
			};
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				name="HitHull";
				visual="Hit_Hull";
				armor=4.5;
				explosionShielding=3;
				passThrough=1;
				radius=0.25;
				minimalHit=0.050000001;
				depends="0";
				material=-1;
			};
			class HitEngine: HitHull
			{
				name="HitEngine";
				visual="Hit_Engine";
				armor=3.5;
				explosionShielding=3.5;
				passThrough=0;
				radius=0.60000002;
				minimalHit=0.02;
			};
			class HitAvionics: HitHull
			{
				name="HitAvionics";
				visual="Hit_Avionics";
				armor=3;
				explosionShielding=3.5;
				passThrough=0;
				radius=0.2;
				minimalHit=0.050000001;
			};
			class HitFuel: HitHull
			{
				name="HitFuel";
				visual="Hit_Fuel";
				armor=3;
				explosionShielding=4;
				passThrough=0;
				radius=0.25;
				minimalHit=0.1;
			};
		};
		LockDetectionSystem=8;
		incomingMissileDetectionSystem="8 + 16";
		enableGPS=1;
		radarTarget=1;
		visualTarget=1;
		radarTargetSize=1;
		visualTargetSize=1;
		irTargetSize=1;
		namesound="Plane";
		class Turrets
		{
		};
		class TransportMagazines
		{
		};
		class TransportWeapons
		{
		};
		class TransportItems
		{
		};
		class AnimationSources
		{
			class muzzle_rot_20mm
			{
				source="ammorandom";
				weapon="weapon_Fighter_Gun20mm_AA";
			};
			class mfd_ammo_count_source
			{
				source="revolving";
				weapon="weapon_Fighter_Gun20mm_AA";
			};
			class canopy_hide
			{
				source="user";
				animPeriod=0.001;
				initPhase=0;
			};
			class ejection_seat_motion
			{
				source="user";
				animPeriod=0.25;
				initPhase=0;
			};
			class ejection_seat_hide: canopy_hide
			{
			};
			class HitHull
			{
				source="Hit";
				hitpoint="HitHull";
				raw=1;
			};
			class HitFuel: HitHull
			{
				hitpoint="HitFuel";
			};
			class HitAvionics: HitHull
			{
				hitpoint="HitAvionics";
			};
			class HitLAileron: HitHull
			{
				hitpoint="HitLAileron";
			};
			class HitRAileron: HitHull
			{
				hitpoint="HitRAileron";
			};
			class HitLCRudder: HitHull
			{
				hitpoint="HitLCRudder";
			};
			class HitLCElevator: HitHull
			{
				hitpoint="HitLCElevator";
			};
			class HitRElevator: HitHull
			{
				hitpoint="HitRElevator";
			};
			class HitEngine: HitHull
			{
				hitpoint="HitEngine";
			};
			class Muzzle_flash
			{
				source="ammorandom";
				weapon="3AS_Delta7_20mm_AA_Cannon";
			};
		};
		selectionFireAnim="zasleh";
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
			minTurn=-120;
			maxTurn=120;
			initTurn=0;
			minElev=-5;
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
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\FX_Plane_Fighter_04_cabine_open_ext",
			3.1622801,
			1,
			40
		};
		cabinCloseSound[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\FX_Plane_Fighter_04_cabine_close_ext",
			3.1622801,
			1,
			40
		};
		cabinOpenSoundInternal[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\FX_Plane_Fighter_04_cabine_open_int",
			10,
			1,
			40
		};
		cabinCloseSoundInternal[]=
		{
			"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_04\FX_Plane_Fighter_04_cabine_close_int",
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
			"3AS\3AS_Delta7\sounds\jedistarfighter_startup.ogg",
			1,
			1
		};
		soundEngineOnExt[]=
		{
			"3AS\3AS_Delta7\sounds\jedistarfighter_startup.ogg",
			1.75,
			1,
			300
		};
		soundEngineOffInt[]=
		{
			"3AS\3AS_Delta7\sounds\jedistarfighter_turnoff.ogg",
			1,
			1
		};
		soundEngineOffExt[]=
		{
			"3AS\3AS_Delta7\sounds\jedistarfighter_turnoff.ogg",
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
				"3AS_Delta7_EngineLowExt_SoundSet",
				"3AS_Delta7_EngineHighExt_SoundSet",
				"3AS_Delta7_ForsageExt_SoundSet",
				"3AS_Delta7_WindNoiseExt_SoundSet",
				"3AS_Delta7_EngineLowInt_SoundSet",
				"3AS_Delta7_EngineHighInt_SoundSet",
				"3AS_Delta7_ForsageInt_SoundSet",
				"3AS_Delta7_WindNoiseInt_SoundSet",
				"3AS_Delta7_VelocityInt_SoundSet"
			};
		};
		class RainExt
		{
			sound[]=
			{
				"A3\Sounds_F\vehicles\noises\rain1_ext",
				1.77828,
				1,
				100
			};
			frequency=1;
			volume="camPos * rain * (speed factor[50, 0])";
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
			volume="(1-camPos) * rain * (speed factor[50, 0])";
		};
		defaultUserMFDvalues[]={0.20999999,1,0.25400001,0.64999998};
		class MFD
		{
			class AirplaneHUD
			{
				topLeft="HUD_top_left";
				topRight="HUD_top_right";
				bottomLeft="HUD_bottom_left";
				borderLeft=0;
				borderRight=0;
				borderTop=0;
				borderBottom=0;
				color[]={0.082000002,0.40799999,0.039000001,1};
				helmetMountedDisplay=1;
				helmetPosition[]={-0.037500001,0.037500001,0.1};
				helmetRight[]={0.075000003,0,0};
				helmetDown[]={0,-0.075000003,0};
				font="";
				turret[]={-2};
				class Bones
				{
					class HUDCenter
					{
						type="fixed";
						pos[]={0.5,0.5};
					};
					class HorizonBankSource
					{
						type="rotational";
						source="HorizonBank";
						center[]={0.5,0.5};
						min=-6.2831001;
						max=6.2831001;
						minAngle=-360;
						maxAngle=360;
					};
					class HorizonDiveSource
					{
						source="horizonDive";
						type="linear";
						min=-1;
						max=1;
						minPos[]={0.5,2.5};
						maxPos[]={0.5,-1.5};
					};
					class VelocityVector
					{
						type="vector";
						source="velocityToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class ForwardVector
					{
						type="vector";
						source="forward";
						pos0[]={0,0};
						pos10[]={0.234,0.23};
					};
					class WeaponAim
					{
						type="vector";
						source="weaponToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class TargetingPodDir
					{
						source="pilotcameratoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class TargetingPodTarget
					{
						source="pilotcameratargettoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class SliderDiveSource
					{
						type="linear";
						source="horizonDive";
						min="RAD(-10)";
						max="RAD(10)";
						minPos[]={0.105,0.38};
						maxPos[]={0.105,0.54000002};
					};
					class SliderDiveSource30: SliderDiveSource
					{
						min="RAD(10)";
						max="RAD(30)";
						minPos[]={0,-0.039999999};
						maxPos[]=
						{
							0,
							"0)"
						};
					};
					class SliderDiveSource90: SliderDiveSource30
					{
						min="RAD(30)";
						max="RAD(90)";
						minPos[]={0,-0.039999999};
					};
					class SliderDiveSource30m: SliderDiveSource
					{
						min="RAD(-30)";
						max="RAD(-10)";
						minPos[]={0,0};
						maxPos[]={0,0.039999999};
					};
					class SliderDiveSource90m: SliderDiveSource30m
					{
						min="RAD(-90)";
						max="RAD(-30)";
						maxPos[]={0,0.039999999};
					};
					class SliderAltitudeSource
					{
						type="linear";
						source="altitudeAGL";
						sourceOffset=-3;
						min=0;
						max=1000;
						minPos[]={0.88499999,0.2};
						maxPos[]={0.88499999,0.375};
					};
					class GForceSource
					{
						type="linear";
						source="gmeter";
						sourceScale=0.15000001;
						min=-1;
						max=3;
						minPos[]={0.105,0.69999999};
						maxPos[]={0.105,0.86000001};
					};
					class SliderVSpeedSource
					{
						type="linear";
						source="vspeed";
						min=-15;
						max=15;
						minPos[]={0.79500002,0.60000002};
						maxPos[]={0.79500002,0.83999997};
					};
					class ImpactPoint
					{
						type="vector";
						source="ImpactPointToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class ImpactPointRockets
					{
						type="vector";
						source="ImpactPointToView";
						pos0[]={0.5,0.565};
						pos10[]={0.73400003,0.79500002};
					};
					class WPPoint
					{
						type="vector";
						source="WPPointToView";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class rtdRPM1
					{
						type="linear";
						source="rpm";
						min=0.1;
						max=1;
						minPos[]={0,-0.075000003};
						maxPos[]={0,0};
					};
					class rtdRPM2: rtdRPM1
					{
						source="rpm";
					};
					class Limit0109
					{
						type="limit";
						limits[]={0.1,0.1,0.89999998,0.89999998};
					};
					class Target
					{
						source="targettoview";
						type="vector";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class ThrustVectoringRotation
					{
						type="rotational";
						source="vtolvectoring";
						sourceScale=100;
						center[]={0.059999999,0.145};
						min=0;
						max=100;
						minAngle=0;
						maxAngle=-90;
						aspectRatio=0.98290598;
					};
					class MissileFlightTimeRot1
					{
						type="rotational";
						source="MissileFlightTime";
						sourceScale=0.46000001;
						center[]={0,0};
						min=0;
						max=0.5;
						minAngle=0;
						maxAngle=18;
						aspectRatio=0.98290598;
					};
					class MissileFlightTimeRot2: MissileFlightTimeRot1
					{
						maxAngle=36;
						max=1;
					};
					class MissileFlightTimeRot3: MissileFlightTimeRot1
					{
						maxAngle=54;
						max=1.5;
					};
					class MissileFlightTimeRot4: MissileFlightTimeRot1
					{
						maxAngle=72;
						max=2;
					};
					class MissileFlightTimeRot5: MissileFlightTimeRot1
					{
						maxAngle=90;
						max=2.5;
					};
					class MissileFlightTimeRot6: MissileFlightTimeRot1
					{
						maxAngle=108;
						max=3;
					};
					class MissileFlightTimeRot7: MissileFlightTimeRot1
					{
						maxAngle=126;
						max=3.5;
					};
					class MissileFlightTimeRot8: MissileFlightTimeRot1
					{
						maxAngle=144;
						max=4;
					};
					class MissileFlightTimeRot9: MissileFlightTimeRot1
					{
						maxAngle=162;
						max=4.5;
					};
					class MissileFlightTimeRot10: MissileFlightTimeRot1
					{
						maxAngle=180;
						max=5;
					};
					class MissileFlightTimeRot11: MissileFlightTimeRot1
					{
						maxAngle=198;
						max=5.5;
					};
					class MissileFlightTimeRot12: MissileFlightTimeRot1
					{
						maxAngle=216;
						max=6;
					};
					class MissileFlightTimeRot13: MissileFlightTimeRot1
					{
						maxAngle=234;
						max=6.5;
					};
					class MissileFlightTimeRot14: MissileFlightTimeRot1
					{
						maxAngle=252;
						max=7;
					};
					class MissileFlightTimeRot15: MissileFlightTimeRot1
					{
						maxAngle=270;
						max=7.5;
					};
					class MissileFlightTimeRot16: MissileFlightTimeRot1
					{
						maxAngle=288;
						max=8;
					};
					class MissileFlightTimeRot17: MissileFlightTimeRot1
					{
						maxAngle=306;
						max=8.5;
					};
					class MissileFlightTimeRot18: MissileFlightTimeRot1
					{
						maxAngle=324;
						max=9;
					};
					class MissileFlightTimeRot19: MissileFlightTimeRot1
					{
						maxAngle=342;
						max=9.5;
					};
					class MissileFlightTimeRot20: MissileFlightTimeRot1
					{
						maxAngle=360;
						max=10;
					};
					class HorizonBankRotFull
					{
						type="rotational";
						source="horizonBank";
						center[]={0,0};
						min=-3.1415999;
						max=3.1415999;
						minAngle=-180;
						maxAngle=180;
						aspectRatio=1;
					};
					class Airport1
					{
						type="vector";
						source="airportCorner1toview";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
					};
					class Airport2: Airport1
					{
						source="airportCorner2toview";
					};
					class Airport3: Airport1
					{
						source="airportCorner3toview";
					};
					class Airport4: Airport1
					{
						source="airportCorner4toview";
					};
					class ILS_H
					{
						type="ils";
						pos0[]={0.5,0.5};
						pos3[]={0.57020003,0.5};
					};
					class ILS_W: ILS_H
					{
						pos3[]={0.5,0.56900001};
					};
				};
				class Draw
				{
					alpha="user3";
					color[]=
					{
						"user0",
						"user1",
						"user2"
					};
					condition="(1 - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37))*on";
					class VelocityLine
					{
						type="line";
						width=2;
						points[]=
						{
							
							{
								"HUDCenter",
								1
							},
							
							{
								"VelocityVector",
								1
							},
							{},
							
							{
								"VelocityVector",
								{0,-0.0049145301},
								1
							},
							
							{
								"VelocityVector",
								{0.0024999999,-0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0.0043299999,-0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{0.0049999999,0},
								1
							},
							
							{
								"VelocityVector",
								{0.0043299999,0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{0.0024999999,0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0,0.0049145301},
								1
							},
							
							{
								"VelocityVector",
								{-0.0024999999,0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{-0.0043299999,0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{-0.0049999999,0},
								1
							},
							
							{
								"VelocityVector",
								{-0.0043299999,-0.0024572599},
								1
							},
							
							{
								"VelocityVector",
								{-0.0024999999,-0.0042559798},
								1
							},
							
							{
								"VelocityVector",
								{0,-0.0049145301},
								1
							},
							{}
						};
					};
					class Static
					{
						type="line";
						width=3;
						points[]=
						{
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,0.0099999998},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0,0},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,-0.0099999998},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.015,0.0099999998},
								1
							},
							{},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.088,0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.088,-0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,-0.015},
								1
							},
							
							{
								"SliderDiveSource90",
								1,
								"SliderDiveSource30",
								1,
								"SliderDiveSource",
								1,
								"SliderDiveSource30m",
								1,
								"SliderDiveSource90m",
								1,
								{0.029999999,0.015},
								1
							},
							{},
							
							{
								{0.1,0.30000001},
								1
							},
							
							{
								{0.1,0.62},
								1
							},
							{},
							
							{
								{0.1,0.30000001},
								1
							},
							
							{
								{0.079999998,0.30000001},
								1
							},
							{},
							
							{
								{0.1,0.34},
								1
							},
							
							{
								{0.079999998,0.34},
								1
							},
							{},
							
							{
								{0.1,0.38},
								1
							},
							
							{
								{0.079999998,0.38},
								1
							},
							{},
							
							{
								{0.1,0.46000001},
								1
							},
							
							{
								{0.079999998,0.46000001},
								1
							},
							{},
							
							{
								{0.1,0.54000002},
								1
							},
							
							{
								{0.079999998,0.54000002},
								1
							},
							{},
							
							{
								{0.1,0.57999998},
								1
							},
							
							{
								{0.079999998,0.57999998},
								1
							},
							{},
							
							{
								{0.1,0.62},
								1
							},
							
							{
								{0.079999998,0.62},
								1
							},
							{},
							
							{
								"GForceSource",
								{0.015,0.0099999998},
								1
							},
							
							{
								"GForceSource",
								{0,0},
								1
							},
							
							{
								"GForceSource",
								{0.015,-0.0099999998},
								1
							},
							
							{
								"GForceSource",
								{0.015,0.0099999998},
								1
							},
							{},
							
							{
								{0.1,0.68800002},
								1
							},
							
							{
								{0.1,0.81999999},
								1
							},
							{},
							
							{
								{0.1,0.69999999},
								1
							},
							
							{
								{0.079999998,0.69999999},
								1
							},
							{},
							
							{
								{0.1,0.74000001},
								1
							},
							
							{
								{0.079999998,0.74000001},
								1
							},
							{},
							
							{
								{0.1,0.77999997},
								1
							},
							
							{
								{0.079999998,0.77999997},
								1
							},
							{},
							
							{
								{0.1,0.81999999},
								1
							},
							
							{
								{0.079999998,0.81999999},
								1
							},
							{},
							
							{
								{0.46000001,0.07},
								1
							},
							
							{
								{0.54000002,0.07},
								1
							},
							
							{
								{0.54000002,0.035},
								1
							},
							
							{
								{0.46000001,0.035},
								1
							},
							
							{
								{0.46000001,0.07},
								1
							},
							{},
							
							{
								{0.15000001,0.115},
								1
							},
							
							{
								{0.85000002,0.115},
								1
							},
							{},
							
							{
								{0,0.95999998},
								1
							},
							
							{
								{1.1,0.95999998},
								1
							},
							{},
							
							{
								{0.47999999,0.5},
								1
							},
							
							{
								{0.49000001,0.5},
								1
							},
							{},
							
							{
								{0.50999999,0.5},
								1
							},
							
							{
								{0.51999998,0.5},
								1
							},
							{},
							
							{
								{0.5,0.49000001},
								1
							},
							
							{
								{0.5,0.47999999},
								1
							},
							{},
							
							{
								{0.5,0.50999999},
								1
							},
							
							{
								{0.5,0.51999998},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{-0.02,0},
								1
							},
							
							{
								"WeaponAim",
								1,
								{-0.0099999998,0},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0.0099999998,0},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0.02,0},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0,-0.0099999998},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0,-0.02},
								1
							},
							{},
							
							{
								"WeaponAim",
								1,
								{0,0.0099999998},
								1
							},
							
							{
								"WeaponAim",
								1,
								{0,0.02},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.16500001,7.0890902e-009},
								1
							},
							
							{
								"HUDCenter",
								{-0.22,9.45212e-009},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.16500001,-1.9339701e-009},
								1
							},
							
							{
								"HUDCenter",
								{0.22,-2.57863e-009},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.082500003,0.140452},
								1
							},
							
							{
								"HUDCenter",
								{-0.096249998,0.16385999},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.082500003,0.140452},
								1
							},
							
							{
								"HUDCenter",
								{0.096249998,0.16385999},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.142894,0.081089698},
								1
							},
							
							{
								"HUDCenter",
								{-0.16671,0.094604701},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.142894,0.081089698},
								1
							},
							
							{
								"HUDCenter",
								{0.16671,0.094604701},
								1
							},
							{},
							
							{
								"HUDCenter",
								{-0.116673,0.114678},
								1
							},
							
							{
								"HUDCenter",
								{-0.155564,0.152904},
								1
							},
							{},
							
							{
								"HUDCenter",
								{0.116673,0.114678},
								1
							},
							
							{
								"HUDCenter",
								{0.155563,0.152904},
								1
							},
							{},
							
							{
								{0.033333302,0.14866699},
								1
							},
							
							{
								{0.054000001,0.162},
								1
							},
							
							{
								{0.13500001,0.162},
								1
							},
							
							{
								{0.13500001,0.14866699},
								1
							},
							
							{
								{0.126333,0.139667},
								1
							},
							
							{
								{0.118,0.139667},
								1
							},
							
							{
								{0.093333296,0.129333},
								1
							},
							
							{
								{0.033333302,0.129333},
								1
							},
							
							{
								{0.015666701,0.111},
								1
							},
							
							{
								{0.0086666699,0.115333},
								1
							},
							
							{
								{0.0116667,0.13600001},
								1
							},
							{}
						};
					};
					class DiveNumber
					{
						type="text";
						source="horizondive";
						sourceScale=57.29578;
						sourceOffset=0;
						align="left";
						scale=1;
						pos[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.085000001,
								"0.00-0.011"
							},
							1
						};
						right[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.12,
								"0.00-0.011"
							},
							1
						};
						down[]=
						{
							"SliderDiveSource90",
							1,
							"SliderDiveSource30",
							1,
							"SliderDiveSource",
							1,
							"SliderDiveSource30m",
							1,
							"SliderDiveSource90m",
							1,
							
							{
								0.085000001,
								"0.03-0.011"
							},
							1
						};
					};
					class VSpeedGroup
					{
						condition="on";
						class VSpeedNumber
						{
							type="text";
							source="vspeed";
							sourceScale=1;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.82+0.07",
									0.72799999
								},
								1
							};
							right[]=
							{
								
								{
									"0.86+0.07",
									0.72799999
								},
								1
							};
							down[]=
							{
								
								{
									"0.82+0.07",
									0.76300001
								},
								1
							};
						};
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.84899998,0.75999999},
									1
								},
								
								{
									{0.92900002,0.75999999},
									1
								},
								
								{
									{0.92900002,0.72500002},
									1
								},
								
								{
									{0.84899998,0.72500002},
									1
								},
								
								{
									{0.84899998,0.75999999},
									1
								},
								{}
							};
						};
					};
					class VSpeedGroupUp
					{
						condition="vspeed";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.86900002,0.71499997},
									1
								},
								
								{
									{0.90899998,0.71499997},
									1
								},
								
								{
									{0.889,0.69499999},
									1
								},
								
								{
									{0.86900002,0.71499997},
									1
								},
								{}
							};
						};
					};
					class VSpeedGroupDown
					{
						condition="-vspeed";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.86900002,0.76999998},
									1
								},
								
								{
									{0.90899998,0.76999998},
									1
								},
								
								{
									{0.889,0.79000002},
									1
								},
								
								{
									{0.86900002,0.76999998},
									1
								},
								{}
							};
						};
					};
					class AltGroup
					{
						condition="1000 - altitudeAGL";
						class Static
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"SliderAltitudeSource",
									{0.024,0.0099999998},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.0089999996,0},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.024,-0.0099999998},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.024,0.0099999998},
									1
								},
								{},
								
								{
									"SliderAltitudeSource",
									{0.035,0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.093000002,0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.093000002,-0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.035,-0.015},
									1
								},
								
								{
									"SliderAltitudeSource",
									{0.035,0.015},
									1
								},
								{},
								
								{
									{0.889,0.2},
									1
								},
								
								{
									{0.889,0.375},
									1
								},
								{},
								
								{
									{0.87900001,0.2},
									1
								},
								
								{
									{0.89899999,0.2},
									1
								},
								{},
								
								{
									{0.87900001,0.375},
									1
								},
								
								{
									{0.89899999,0.375},
									1
								},
								{}
							};
						};
						class AltNumber
						{
							type="text";
							source="altitudeAGL";
							sourceScale=1;
							sourceOffset=-3;
							align="left";
							scale=1;
							pos[]=
							{
								"SliderAltitudeSource",
								
								{
									0.085000001,
									"0.00-0.011"
								},
								1
							};
							right[]=
							{
								"SliderAltitudeSource",
								
								{
									0.11,
									"0.00-0.011"
								},
								1
							};
							down[]=
							{
								"SliderAltitudeSource",
								
								{
									0.085000001,
									"0.03-0.011"
								},
								1
							};
						};
						class AltStatic50
						{
							type="text";
							source="static";
							text="1000";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.88499999,0.171},
								1
							};
							right[]=
							{
								{0.92500001,0.171},
								1
							};
							down[]=
							{
								{0.88499999,0.20100001},
								1
							};
						};
					};
					class SpeedNumber
					{
						type="text";
						source="speed";
						sourceScale=3.5999999;
						sourceLength=3;
						align="left";
						scale=1;
						pos[]=
						{
							{0.13,0.22},
							1
						};
						down[]=
						{
							{0.13,0.25999999},
							1
						};
						right[]=
						{
							{0.2,0.22},
							1
						};
					};
					class Angle_90
					{
						type="text";
						source="static";
						text="90";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.285},
							1
						};
						right[]=
						{
							{0.11,0.285},
							1
						};
						down[]=
						{
							{0.07,0.315},
							1
						};
					};
					class Angle_30
					{
						type="text";
						source="static";
						text="30";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.32499999},
							1
						};
						right[]=
						{
							{0.11,0.32499999},
							1
						};
						down[]=
						{
							{0.07,0.35499999},
							1
						};
					};
					class Angle_10
					{
						type="text";
						source="static";
						text="10";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.36500001},
							1
						};
						right[]=
						{
							{0.11,0.36500001},
							1
						};
						down[]=
						{
							{0.07,0.39500001},
							1
						};
					};
					class Angle_0
					{
						type="text";
						source="static";
						text="0";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.44499999},
							1
						};
						right[]=
						{
							{0.11,0.44499999},
							1
						};
						down[]=
						{
							{0.07,0.47499999},
							1
						};
					};
					class Angle_10m
					{
						type="text";
						source="static";
						text="-10";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.52499998},
							1
						};
						right[]=
						{
							{0.11,0.52499998},
							1
						};
						down[]=
						{
							{0.07,0.55500001},
							1
						};
					};
					class Angle_30m
					{
						type="text";
						source="static";
						text="-30";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.565},
							1
						};
						right[]=
						{
							{0.11,0.565},
							1
						};
						down[]=
						{
							{0.07,0.59500003},
							1
						};
					};
					class Angle_90m
					{
						type="text";
						source="static";
						text="-90";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.60500002},
							1
						};
						right[]=
						{
							{0.11,0.60500002},
							1
						};
						down[]=
						{
							{0.07,0.63499999},
							1
						};
					};
					class GMeterStatic3
					{
						type="text";
						source="static";
						text="3";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.68300003},
							1
						};
						right[]=
						{
							{0.11,0.68300003},
							1
						};
						down[]=
						{
							{0.07,0.713},
							1
						};
					};
					class GMeterStatic2
					{
						type="text";
						source="static";
						text="2";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.72299999},
							1
						};
						right[]=
						{
							{0.11,0.72299999},
							1
						};
						down[]=
						{
							{0.07,0.75300002},
							1
						};
					};
					class GMeterStatic1
					{
						type="text";
						source="static";
						text="1";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.76300001},
							1
						};
						right[]=
						{
							{0.11,0.76300001},
							1
						};
						down[]=
						{
							{0.07,0.79299998},
							1
						};
					};
					class GMeterStatic0
					{
						type="text";
						source="static";
						text="0";
						scale=1;
						sourceScale=1;
						align="left";
						pos[]=
						{
							{0.07,0.80299997},
							1
						};
						right[]=
						{
							{0.11,0.80299997},
							1
						};
						down[]=
						{
							{0.07,0.833},
							1
						};
					};
					class CollectiveNumber
					{
						type="text";
						source="throttle";
						sourceScale=100;
						align="left";
						scale=1;
						pos[]=
						{
							{0.889,0.46000001},
							1
						};
						right[]=
						{
							{0.93900001,0.46000001},
							1
						};
						down[]=
						{
							{0.889,0.495},
							1
						};
					};
					class CollectiveText
					{
						type="text";
						source="static";
						text="%";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.89899999,0.46000001},
							1
						};
						right[]=
						{
							{0.949,0.46000001},
							1
						};
						down[]=
						{
							{0.89899999,0.495},
							1
						};
					};
					class ThrustVectoring
					{
						condition="1+vtolvectoring";
						class VectorigNumber
						{
							type="text";
							source="vtolvectoring";
							sourceScale=90;
							align="left";
							scale=1;
							pos[]=
							{
								{0.102,0.14},
								1
							};
							right[]=
							{
								{0.127,0.14},
								1
							};
							down[]=
							{
								{0.102,0.155},
								1
							};
						};
						class VectoringArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,-0.0060000001},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.044,0},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,0.0060000001},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.034000002,-0.0060000001},
									1
								},
								{},
								
								{
									"ThrustVectoringRotation",
									{-0.044,0},
									1
								},
								
								{
									"ThrustVectoringRotation",
									{-0.0040000002,0},
									1
								},
								{}
							};
						};
					};
					class ThrustVectoringAuto
					{
						condition="-vtolvectoring";
						class VectorigNumber
						{
							type="text";
							source="static";
							sourceScale=1;
							text="AUTO";
							align="left";
							scale=1;
							pos[]=
							{
								{0.103,0.14},
								1
							};
							right[]=
							{
								{0.123,0.14},
								1
							};
							down[]=
							{
								{0.103,0.155},
								1
							};
						};
					};
					class EngineRPM
					{
						type="line";
						width=3;
						points[]=
						{
							
							{
								{0.88999999,0.5},
								1
							},
							
							{
								{0.88999999,0.66000003},
								1
							},
							{},
							
							{
								{0.92000002,0.5},
								1
							},
							
							{
								{0.86000001,0.5},
								1
							},
							{},
							
							{
								{0.92000002,0.66000003},
								1
							},
							
							{
								{0.86000001,0.66000003},
								1
							},
							{},
							
							{
								{0.91000003,0.54000002},
								1
							},
							
							{
								{0.87,0.54000002},
								1
							},
							{},
							
							{
								{0.91000003,0.57999998},
								1
							},
							
							{
								{0.87,0.57999998},
								1
							},
							{},
							
							{
								{0.91000003,0.62},
								1
							},
							
							{
								{0.87,0.62},
								1
							},
							{}
						};
					};
					class EngineRPMLines
					{
						type="line";
						width=5;
						points[]=
						{
							
							{
								
								{
									"0.90+0.01",
									0.66000003
								},
								1
							},
							
							{
								"rtdrpm1",
								
								{
									"0.90+0.01",
									0.66000003
								},
								1
							},
							{},
							
							{
								
								{
									"0.86+0.01",
									0.66000003
								},
								1
							},
							
							{
								"rtdrpm2",
								
								{
									"0.86+0.01",
									0.66000003
								},
								1
							},
							{},
							{}
						};
					};
					class RPM60Text
					{
						type="text";
						source="static";
						text="60";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.64499998},
							1
						};
						right[]=
						{
							{0.95499998,0.64499998},
							1
						};
						down[]=
						{
							{0.92500001,0.67000002},
							1
						};
					};
					class RPM80Text
					{
						type="text";
						source="static";
						text="80";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.60500002},
							1
						};
						right[]=
						{
							{0.95499998,0.60500002},
							1
						};
						down[]=
						{
							{0.92500001,0.63},
							1
						};
					};
					class RPM100Text
					{
						type="text";
						source="static";
						text="100";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.565},
							1
						};
						right[]=
						{
							{0.95499998,0.565},
							1
						};
						down[]=
						{
							{0.92500001,0.58999997},
							1
						};
					};
					class RPM120Text
					{
						type="text";
						source="static";
						text="120";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.92500001,0.52499998},
							1
						};
						right[]=
						{
							{0.95499998,0.52499998},
							1
						};
						down[]=
						{
							{0.92500001,0.55000001},
							1
						};
					};
					class HeadingNumber
					{
						type="text";
						source="heading";
						sourceScale=1;
						align="center";
						scale=1;
						pos[]=
						{
							
							{
								"0.80-0.302",
								"0.082-0.043"
							},
							1
						};
						right[]=
						{
							
							{
								"0.84-0.302",
								"0.082-0.043"
							},
							1
						};
						down[]=
						{
							
							{
								"0.80-0.302",
								"0.117-0.043"
							},
							1
						};
					};
					class HeadingRotationArrow
					{
						condition="5-abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)";
						class HeadingArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.51999998,0.079999998},
									1
								},
								
								{
									{0.5,0.11},
									1
								},
								
								{
									{0.47999999,0.079999998},
									1
								},
								
								{
									{0.51999998,0.079999998},
									1
								},
								{}
							};
						};
					};
					class HeadingRotation
					{
						condition="abs(cameraDir-heading)*( (abs(heading-cameraDir))<=355)-5";
						class HeadingHeadNumber
						{
							type="text";
							source="cameraDir";
							sourceScale=1;
							align="center";
							scale=1;
							pos[]=
							{
								
								{
									"0.80-0.302",
									"0.082+0.001"
								},
								1
							};
							right[]=
							{
								
								{
									"0.83-0.302",
									"0.082+0.001"
								},
								1
							};
							down[]=
							{
								
								{
									"0.80-0.302",
									"0.113+0.001"
								},
								1
							};
						};
						class HeadingArrow
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									{0.47799999,0.075000003},
									1
								},
								
								{
									{0.52200001,0.075000003},
									1
								},
								
								{
									{0.55199999,0.094999999},
									1
								},
								
								{
									{0.52200001,0.115},
									1
								},
								
								{
									{0.47799999,0.115},
									1
								},
								
								{
									{0.44800001,0.094999999},
									1
								},
								
								{
									{0.47799999,0.075000003},
									1
								},
								{}
							};
						};
					};
					class HeadingScale
					{
						type="scale";
						horizontal=1;
						source="heading";
						sourceScale=0.1;
						sourceoffset=0;
						width=3;
						NeverEatSeaWeed=1;
						top=0.15000001;
						center=0.5;
						bottom=0.85000002;
						lineXleft=0.114;
						lineYright=0.12;
						lineXleftMajor=0.114;
						lineYrightMajor=0.13;
						majorLineEach=2;
						numberEach=6;
						step=0.5;
						stepSize=0.034482799;
						align="center";
						scale=1;
						pos[]={0.15000001,0.13};
						right[]={0.20999999,0.13};
						down[]={0.15000001,0.17};
					};
					class HorizonBanking
					{
						type="line";
						width=3;
						clipTL[]={0,0.1};
						clipBR[]={1,0.89999998};
						points[]=
						{
							
							{
								"HorizonBankSource",
								{0.16,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.1,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.085000001,-0.015},
								1
							},
							
							{
								"HorizonBankSource",
								{0.07,0},
								1
							},
							
							{
								"HorizonBankSource",
								{0.050000001,0},
								1
							},
							{},
							
							{
								"HorizonBankSource",
								{-0.16,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.1,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.085000001,-0.015},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.07,0},
								1
							},
							
							{
								"HorizonBankSource",
								{-0.050000001,0},
								1
							},
							{}
						};
					};
					class CoordXNumber
					{
						type="text";
						source="coordinateX";
						sourceScale=0.0099999998;
						sourceLength=3;
						sourceOffset=-0.5;
						align="right";
						scale=1;
						pos[]=
						{
							{0.80900002,0.96100003},
							1
						};
						right[]=
						{
							{0.85900003,0.96100003},
							1
						};
						down[]=
						{
							{0.80900002,0.99599999},
							1
						};
					};
					class CoordYNumber: CoordXNumber
					{
						source="coordinateY";
						pos[]=
						{
							{0.89899999,0.96100003},
							1
						};
						right[]=
						{
							{0.949,0.96100003},
							1
						};
						down[]=
						{
							{0.89899999,0.99599999},
							1
						};
					};
					class Time: CoordXNumber
					{
						source="time";
						text="%X";
						align="left";
						pos[]=
						{
							{0.60500002,0.96100003},
							1
						};
						right[]=
						{
							{0.65499997,0.96100003},
							1
						};
						down[]=
						{
							{0.60500002,0.99599999},
							1
						};
					};
					class CurrentWeapon
					{
						type="text";
						source="weapon";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.97899997,0.889},
							1
						};
						right[]=
						{
							{1.029,0.889},
							1
						};
						down[]=
						{
							{0.97899997,0.92400002},
							1
						};
					};
					class CurrentAmmo: CurrentWeapon
					{
						source="ammo";
						align="left";
						pos[]=
						{
							{0.97899997,0.921},
							1
						};
						right[]=
						{
							{1.029,0.921},
							1
						};
						down[]=
						{
							{0.97899997,0.95599997},
							1
						};
					};
					class CoordXText
					{
						type="text";
						source="static";
						text="GRID:";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.65499997,0.96100003},
							1
						};
						right[]=
						{
							{0.70499998,0.96100003},
							1
						};
						down[]=
						{
							{0.65499997,0.99599999},
							1
						};
					};
					class CoordYText
					{
						type="text";
						source="static";
						text="";
						scale=1;
						sourceScale=1;
						align="right";
						pos[]=
						{
							{0.875,0.96100003},
							1
						};
						right[]=
						{
							{0.92500001,0.96100003},
							1
						};
						down[]=
						{
							{0.875,0.99599999},
							1
						};
					};
					class LightsGroup
					{
						condition="lights";
						class LightsText
						{
							type="text";
							source="static";
							text="LIGHT";
							align="left";
							scale=1;
							pos[]=
							{
								{0.149,0.96100003},
								1
							};
							right[]=
							{
								{0.199,0.96100003},
								1
							};
							down[]=
							{
								{0.149,0.99599999},
								1
							};
						};
					};
					class CollisionLights
					{
						condition="collisionlights";
						class CollisionLightsText
						{
							type="text";
							source="static";
							text="COLL";
							align="left";
							scale=1;
							pos[]=
							{
								{0.30899999,0.96100003},
								1
							};
							right[]=
							{
								{0.359,0.96100003},
								1
							};
							down[]=
							{
								{0.30899999,0.99599999},
								1
							};
						};
					};
					class WeaponsLocking
					{
						condition="missilelocking";
						blinkingPattern[]={0.2,0.2};
						blinkingStartsOn=1;
						class Text
						{
							type="text";
							source="static";
							text="LOCKING";
							align="center";
							scale=1;
							pos[]=
							{
								{0.215,0.87970102},
								1
							};
							right[]=
							{
								{0.27500001,0.87970102},
								1
							};
							down[]=
							{
								{0.215,0.928846},
								1
							};
						};
					};
					class TargetInfo
					{
						condition="missilelocked";
						class TargetLockedText
						{
							type="text";
							source="static";
							text="TARGET ACQUIRED";
							scale=1;
							sourceScale=1;
							align="center";
							pos[]=
							{
								{0.19499999,0.85900003},
								1
							};
							right[]=
							{
								{0.235,0.85900003},
								1
							};
							down[]=
							{
								{0.19499999,0.88999999},
								1
							};
						};
						class TimeOfFlightText
						{
							type="text";
							source="static";
							text="TOF:";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.127+0.13",
									0.889
								},
								1
							};
							right[]=
							{
								{0.30199999,0.889},
								1
							};
							down[]=
							{
								
								{
									"0.127+0.13",
									0.92400002
								},
								1
							};
						};
						class DistanceText
						{
							type="text";
							source="static";
							text="DISTANCE:";
							scale=1;
							sourceScale=1;
							align="left";
							pos[]=
							{
								
								{
									"0.125+0.13",
									0.921
								},
								1
							};
							right[]=
							{
								{0.30000001,0.921},
								1
							};
							down[]=
							{
								
								{
									"0.125+0.13",
									0.95599997
								},
								1
							};
						};
						class TOF_source: CurrentWeapon
						{
							source="missileflighttime";
							align="right";
							pos[]=
							{
								{0.26899999,0.889},
								1
							};
							right[]=
							{
								{0.31900001,0.889},
								1
							};
							down[]=
							{
								{0.26899999,0.92400002},
								1
							};
						};
						class TargetDistance: CurrentWeapon
						{
							source="targetDist";
							sourceLength=0;
							sourcePrecision=1;
							sourceScale=0.001;
							align="right";
							pos[]=
							{
								{0.26899999,0.921},
								1
							};
							right[]=
							{
								{0.31900001,0.921},
								1
							};
							down[]=
							{
								{0.26899999,0.95599997},
								1
							};
						};
					};
					class IncomingMissile
					{
						condition="incomingmissile";
						blinkingPattern[]={0.30000001,0.30000001};
						blinkingStartsOn=1;
						class Text
						{
							type="text";
							source="static";
							text="!INCOMING MISSILE!";
							align="center";
							scale=1;
							pos[]=
							{
								{0.48500001,0.21623901},
								1
							};
							right[]=
							{
								{0.54500002,0.21623901},
								1
							};
							down[]=
							{
								{0.48500001,0.265385},
								1
							};
						};
					};
					class GearGroup
					{
						type="group";
						condition="ils";
						class GearText
						{
							type="text";
							source="static";
							text="GEAR";
							align="center";
							scale=1;
							pos[]=
							{
								{0.5,0.889},
								1
							};
							right[]=
							{
								{0.54000002,0.889},
								1
							};
							down[]=
							{
								{0.5,0.92400002},
								1
							};
						};
					};
					class ILS
					{
						condition="ils";
						class Glideslope
						{
							clipTL[]={0,0};
							clipBR[]={1,1};
							class ILS
							{
								type="line";
								points[]=
								{
									
									{
										"ILS_W",
										{-0.23999999,0},
										1
									},
									
									{
										"ILS_W",
										{0.23999999,0},
										1
									},
									{},
									
									{
										"ILS_W",
										{-0.23999999,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{-0.23999999,0.0235897},
										1
									},
									{},
									
									{
										"ILS_W",
										{-0.12,-0.0176923},
										1
									},
									
									{
										"ILS_W",
										{-0.12,0.0176923},
										1
									},
									{},
									
									{
										"ILS_W",
										{0,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{0,0.0235897},
										1
									},
									{},
									
									{
										"ILS_W",
										{0.12,-0.0176923},
										1
									},
									
									{
										"ILS_W",
										{0.12,0.0176923},
										1
									},
									{},
									
									{
										"ILS_W",
										{0.23999999,-0.0235897},
										1
									},
									
									{
										"ILS_W",
										{0.23999999,0.0235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{0,-0.235897},
										1
									},
									
									{
										"ILS_H",
										{0,0.235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,-0.235897},
										1
									},
									
									{
										"ILS_H",
										{0.024,-0.235897},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.017999999,-0.117949},
										1
									},
									
									{
										"ILS_H",
										{0.017999999,-0.117949},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,0},
										1
									},
									
									{
										"ILS_H",
										{0.024,0},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.017999999,0.117949},
										1
									},
									
									{
										"ILS_H",
										{0.017999999,0.117949},
										1
									},
									{},
									
									{
										"ILS_H",
										{-0.024,0.235897},
										1
									},
									
									{
										"ILS_H",
										{0.024,0.235897},
										1
									}
								};
							};
							class airport
							{
								type="line";
								points[]=
								{
									
									{
										"airport1",
										1
									},
									
									{
										"airport2",
										1
									},
									
									{
										"airport4",
										1
									},
									
									{
										"airport3",
										1
									},
									
									{
										"airport1",
										1
									}
								};
							};
						};
					};
					class MGun
					{
						condition="-2+mgun*ImpactDistance";
						class Cross
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0393162},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0.02,-0.024},
									1
								},
								
								{
									"ImpactPoint",
									{0.025,-0.030999999},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0,-0.0020000001},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0020000001},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{-0.0020000001,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.0020000001,0},
									1
								},
								{}
							};
						};
						class Circle
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0275214},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0344017},
									1
								},
								
								{
									"MissileFlightTimeRot1",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot2",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot3",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot4",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot5",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot6",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot7",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot8",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot9",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot10",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot11",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot12",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot13",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot14",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot15",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot16",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot17",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot18",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot19",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot20",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot20",
									{0,0.028000001},
									1,
									"ImpactPoint",
									1
								}
							};
						};
						class Circle_Min_Range
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								}
							};
						};
						class Distance
						{
							type="text";
							source="ImpactDistance";
							sourceScale=0.001;
							sourcePrecision=1;
							max=15;
							align="center";
							scale=1;
							pos[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.079999998},
								1
							};
							right[]=
							{
								"ImpactPoint",
								{0.045000002,-0.079999998},
								1
							};
							down[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.039999999},
								1
							};
						};
					};
					class Rockets
					{
						condition="-2+rocket*ImpactDistance";
						class Cross
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0393162},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0.02,-0.024},
									1
								},
								
								{
									"ImpactPoint",
									{0.025,-0.030999999},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{0,-0.0020000001},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0020000001},
									1
								},
								{},
								
								{
									"ImpactPoint",
									{-0.0020000001,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.0020000001,0},
									1
								},
								{}
							};
						};
						class Circle
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0275214},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0344017},
									1
								},
								
								{
									"MissileFlightTimeRot1",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot2",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot3",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot4",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot5",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot6",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot7",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot8",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot9",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot10",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot11",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot12",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot13",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot14",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot15",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot16",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot17",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot18",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot19",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot20",
									{0,0.035},
									1,
									"ImpactPoint",
									1
								},
								
								{
									"MissileFlightTimeRot20",
									{0,0.028000001},
									1,
									"ImpactPoint",
									1
								}
							};
						};
						class Circle_Min_Range
						{
							type="line";
							width=3;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0294872},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029999999,0},
									1
								},
								
								{
									"ImpactPoint",
									{-0.029544,-0.0051189698},
									1
								},
								
								{
									"ImpactPoint",
									{-0.028191,-0.0100846},
									1
								},
								
								{
									"ImpactPoint",
									{-0.025979999,-0.0147436},
									1
								},
								
								{
									"ImpactPoint",
									{-0.022980001,-0.0189544},
									1
								},
								
								{
									"ImpactPoint",
									{-0.019284001,-0.022587201},
									1
								},
								
								{
									"ImpactPoint",
									{-0.015,-0.0255359},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01026,-0.0277091},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0052080001,-0.029038999},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0294872},
									1
								}
							};
						};
						class Distance
						{
							type="text";
							source="ImpactDistance";
							sourceScale=0.001;
							sourcePrecision=1;
							max=15;
							align="center";
							scale=1;
							pos[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.079999998},
								1
							};
							right[]=
							{
								"ImpactPoint",
								{0.045000002,-0.079999998},
								1
							};
							down[]=
							{
								"ImpactPoint",
								{-0.0020000001,-0.039999999},
								1
							};
						};
					};
					class BombCrosshairGroup
					{
						type="group";
						condition="bomb";
						class BombCrosshair
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"ImpactPoint",
									{0,-0.0982906},
									1
								},
								
								{
									"ImpactPoint",
									{0.01736,-0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0.034200002,-0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{0.050000001,-0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{0.064280003,-0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{0.0766,-0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{0.086599998,-0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{0.093970001,-0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{0.098480001,-0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{0.1,0},
									1
								},
								
								{
									"ImpactPoint",
									{0.098480001,0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{0.093970001,0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{0.086599998,0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{0.0766,0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{0.064280003,0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{0.050000001,0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{0.034200002,0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{0.01736,0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0,0.0982906},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01736,0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{-0.034200002,0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{-0.050000001,0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{-0.064280003,0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0766,0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{-0.086599998,0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{-0.093970001,0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{-0.098480001,0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{-0.1,0},
									1
								},
								
								{
									"ImpactPoint",
									{-0.098480001,-0.0170632},
									1
								},
								
								{
									"ImpactPoint",
									{-0.093970001,-0.033615399},
									1
								},
								
								{
									"ImpactPoint",
									{-0.086599998,-0.0491453},
									1
								},
								
								{
									"ImpactPoint",
									{-0.0766,-0.063181199},
									1
								},
								
								{
									"ImpactPoint",
									{-0.064280003,-0.075290598},
									1
								},
								
								{
									"ImpactPoint",
									{-0.050000001,-0.085119702},
									1
								},
								
								{
									"ImpactPoint",
									{-0.034200002,-0.0923637},
									1
								},
								
								{
									"ImpactPoint",
									{-0.01736,-0.096796602},
									1
								},
								
								{
									"ImpactPoint",
									{0,-0.0982906},
									1
								},
								{},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,-0.0196581},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0.014,-0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									
									{
										"+ 0.02",
										0
									},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0.014,0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,0.0196581},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{-0.014,0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									
									{
										"- 0.02",
										0
									},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{-0.014,-0.0137607},
									1
								},
								
								{
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,-0.0196581},
									1
								},
								{},
								
								{
									"VelocityVector",
									0.001,
									"ImpactPoint",
									1,
									"Limit0109",
									1,
									{0,0},
									1
								},
								
								{
									"VelocityVector",
									1,
									"Limit0109",
									1,
									{0,0},
									1
								}
							};
						};
						class Distance
						{
							type="text";
							source="ImpactDistance";
							sourceScale=0.001;
							sourcePrecision=1;
							max=15;
							align="center";
							scale=1;
							pos[]=
							{
								"ImpactPoint",
								{-0.0020000001,0.11},
								1
							};
							right[]=
							{
								"ImpactPoint",
								{0.045000002,0.11},
								1
							};
							down[]=
							{
								"ImpactPoint",
								{-0.0020000001,0.15000001},
								1
							};
						};
					};
					class WP
					{
						condition="wpvalid";
						class WPdist
						{
							type="text";
							source="wpdist";
							sourceScale=0.001;
							sourcePrecision=1;
							align="left";
							scale=1;
							pos[]=
							{
								{0.935,0.79713702},
								1
							};
							right[]=
							{
								{0.97500002,0.79713702},
								1
							};
							down[]=
							{
								{0.935,0.83448702},
								1
							};
						};
						class WPstatic
						{
							type="text";
							source="static";
							text=">";
							align="center";
							scale=2;
							pos[]=
							{
								{0.94999999,0.79713702},
								1
							};
							right[]=
							{
								{0.97000003,0.79713702},
								1
							};
							down[]=
							{
								{0.94999999,0.83448702},
								1
							};
						};
						class WPIndex
						{
							type="text";
							source="wpIndex";
							sourceScale=1;
							align="right";
							scale=1;
							pos[]=
							{
								{0.95999998,0.79713702},
								1
							};
							right[]=
							{
								{1,0.79713702},
								1
							};
							down[]=
							{
								{0.95999998,0.83448702},
								1
							};
						};
						class WP
						{
							width=1;
							type="line";
							points[]=
							{
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										0.015,
										-0.035
									},
									1
								},
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										0,
										0
									},
									1
								},
								
								{
									"wppoint",
									1,
									
									{
										"HorizonBankRotFull",
										-0.015,
										-0.035
									},
									1
								}
							};
						};
					};
					class RadarBoxes
					{
						type="radartoview";
						pos0[]={0.5,0.5};
						pos10[]={0.73400003,0.73000002};
						width=2;
						points[]=
						{
							
							{
								{-0.0020000001,-0.0019658101},
								1
							},
							
							{
								{0.0020000001,-0.0019658101},
								1
							},
							
							{
								{0.0020000001,0.0019658101},
								1
							},
							
							{
								{-0.0020000001,0.0019658101},
								1
							},
							
							{
								{-0.0020000001,-0.0019658101},
								1
							}
						};
					};
					class TargetDiamond
					{
						class shape
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.02,0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.02,-0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,-0.0196581},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.02,0.0196581},
									1
								}
							};
						};
					};
					class TargetLocked
					{
						condition="missilelocked";
						class shape
						{
							type="line";
							width=4;
							points[]=
							{
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0294872},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0.029999999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,0.0294872},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{-0.029999999,0},
									1
								},
								
								{
									"Target",
									1,
									"Limit0109",
									1,
									{0,-0.0294872},
									1
								}
							};
						};
					};
				};
			};
			class HMD_CMPilot: AirplaneHUD
			{
				turret[]={-1};
				class Draw
				{
					alpha="user3";
					color[]=
					{
						"user0",
						"user1",
						"user2"
					};
					condition="on - (cameraHeadingDiffY<=-28) + (abs(cameraHeadingDiffX)>=37)";
					class CMName
					{
						type="text";
						source="cmweapon";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.86900002,0.84899998},
							1
						};
						right[]=
						{
							{0.91900003,0.84899998},
							1
						};
						down[]=
						{
							{0.86900002,0.884},
							1
						};
					};
					class CMCount
					{
						type="text";
						source="cmammo";
						sourceScale=1;
						align="left";
						scale=1;
						pos[]=
						{
							{0.97899997,0.84899998},
							1
						};
						right[]=
						{
							{1.029,0.84899998},
							1
						};
						down[]=
						{
							{0.97899997,0.884},
							1
						};
					};
				};
			};
		};
		vtol=4;
		VTOLPitchInfluence=2;
		VTOLRollInfluence=5;
		VTOLYawInfluence=12;
		airBrake=55;
		airBrakeFrictionCoef=2.5;
		flaps=0;
		flapsFrictionCoef=0.30000001;
		brakeDistance=500;
		wheelSteeringSensitivity=2.5;
		maxSpeed=1300;
		altFullForce=6000;
		altNoForce=12000;
		rudderInfluence=0.96599996;
		aileronSensitivity=1.1;
		elevatorSensitivity=1.2;
		elevatorControlsSensitivityCoef=4;
		aileronControlsSensitivityCoef=3.5;
		rudderControlsSensitivityCoef=2;
		elevatorCoef[]={0.40000001,0.60000002,0.76000005,0.51999998,0.59000003,0.56,0.53000003,0.5,0.44999999,0.40000001,0.34999999,0.28,0.27000001,0.25999999,0.25,0.25};
		aileronCoef[]={0.60000002,0.89999998,0.94999999,1,1.05,1,1,0.94999999,0.94999999,0.92500001,0.89999998,0.85000002,0.82499999,0.80000001,0.80000001,0.75};
		rudderCoef[]={0.5,1.8,2.5999999,2.75,2.8,2.8499999,2.9000001,2.95,2.98,3.01,2.7,1.1,0.89999998,0.69999999,0.5,0.30000001};
		angleOfIndicence=0.0024999999;
		draconicForceXCoef=6;
		draconicForceYCoef=5.5;
		draconicForceZCoef=6.5;
		draconicTorqueXCoef=2.0999999;
		draconicTorqueYCoef=0.1;
		envelope[]={0.2,1,2.5,4.8000002,6,7,7.5,7.5,7.5,7,6.4000001,5.5999999,4.0999999,3.7,3.3,3,2.5,2,1.5};
		thrustCoef[]={1.5,1.5,1.6,1.8,2,2.5,3,3.5,2.5,2,1.7,1.5,1.1,1,1,1};
		airFrictionCoefs0[]={0,0,0};
		airFrictionCoefs1[]={0.1,0.050000001,0.0066};
		airFrictionCoefs2[]={0.001,0.0049999999,6.4e-005};
		gunAimDown=0;
		landingSpeed=260;
		stallSpeed=210;
		stallWarningTreshold=0.15000001;
		acceleration=300;
		landingAoa="7.5*3.1415/180";
		maxOmega=2000;
		class Wheels
		{
			class Wheel_front
			{
				boneName="wheel_front";
				steering=1;
				side="left";
				center="wheel_front_center";
				boundary="wheel_front_rim";
				width=0.25999999;
				mass=150;
				MOI=40;
				dampingRate=0.1;
				dampingRateDamaged=1;
				dampingRateDestroyed=1000;
				maxBrakeTorque=1000;
				maxHandBrakeTorque=0;
				suspTravelDirection[]={0,-1,0};
				suspForceAppPointOffset="wheel_front_center";
				tireForceAppPointOffset="wheel_front_center";
				maxCompression=0.1;
				maxDroop=0.15000001;
				sprungMass=1500;
				springStrength=54000;
				springDamperRate=18000;
				latStiffX=3;
				latStiffY=20;
				frictionVsSlipGraph[]=
				{
					{0,1},
					{0.5,1},
					{1,1}
				};
				longitudinalStiffnessPerUnitGravity=900;
			};
			class Wheel_left: Wheel_front
			{
				boneName="wheel_left";
				steering=0;
				center="wheel_left_center";
				boundary="wheel_left_rim";
				width=0.38;
				maxBrakeTorque=2000;
				longitudinalStiffnessPerUnitGravity=1700;
				sprungMass=4500;
				springStrength=288000;
				springDamperRate=72000;
				suspForceAppPointOffset="wheel_left_center";
				tireForceAppPointOffset="wheel_left_center";
			};
			class Wheel_right: Wheel_left
			{
				boneName="wheel_right";
				side="right";
				center="wheel_right_center";
				boundary="wheel_right_rim";
				suspForceAppPointOffset="wheel_right_center";
				tireForceAppPointOffset="wheel_right_center";
			};
		};
		class UserActions
		{
			class Plane_Fighter_04_Eject
			{
				priority=0.050000001;
				shortcut="Eject";
				displayName="$STR_A3_action_eject";
				condition="player in this && {speed this > 1}";
				statement="[this] spawn BIS_fnc_planeEjection";
				position="pilotcontrol";
				radius=10;
				onlyforplayer=1;
				showWindow=0;
				hideOnUse=1;
			};
		};
		class TextureSources
		{
			class Base
			{
				displayName="Base";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Delta7_Hull_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
				factions[]=
				{
					"3AS_rep"
				};
			};
			class PloKoon: Base
			{
				displayName="Plo Koon";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_PK_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Ani: Base
			{
				displayName="Anakin";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Anakin_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Tano: Base
			{
				displayName="Ashoka";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Ahsoka_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Blue: Base
			{
				displayName="Blue";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Blue_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Orange: Base
			{
				displayName="Orange";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Orange_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Green: Base
			{
				displayName="Green";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Green_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
			class Purple: Base
			{
				displayName="Purple";
				author="$STR_3AS_Studio";
				textures[]=
				{
					"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Purple_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
					"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
					"3as\3as_delta7\data\delta7_interfaces_ca.paa"
				};
			};
		};
		animationList[]={};
		textureList[]=
		{
			"Base",
			1,
			"PloKoon",
			1,
			"Ani",
			1,
			"Tano",
			1,
			"Blue",
			1,
			"Orange",
			1,
			"Green",
			1,
			"Purple",
			1
		};
		class Exhausts
		{
			class Exhaust_Left
			{
				position="pos_exhaust_l_start";
				direction="pos_exhaust_l_end";
				effect="ExhaustsEffectPlaneHP";
			};
			class Exhaust_Right
			{
				position="pos_exhaust_r_start";
				direction="pos_exhaust_r_end";
				effect="ExhaustsEffectPlaneHP";
			};
		};
		class WingVortices
		{
			class WingTipLeft
			{
				effectName="FX_WingVortices_FighterJet";
				position="pos_wingtip_vapour_L";
			};
			class WingTipRight: WingTipLeft
			{
				position="pos_wingtip_vapour_R";
			};
			class BodyLeft_inner_1
			{
				effectName="FX_FuselageVapour_FighterJet";
				position="pos_body_vapour_L";
			};
			class BodyRight_inner_1: BodyLeft_inner_1
			{
				position="pos_body_vapour_R";
			};
		};
		class RenderTargets
		{
		};
		class MarkerLights
		{
		};
		class Reflectors
		{
		};
		extCameraPosition[]={0,4,-20};
		class ViewPilot: ViewPilot
		{
			initFov=1;
			initAngleX=0;
			minAngleX=-40;
			maxAngleX=75;
			initAngleY=0;
			minAngleY=-110;
			maxAngleY=110;
			minMoveX=-0.1;
			maxMoveX=0.1;
			minMoveY=-0.025;
			maxMoveY=0.1;
			minMoveZ=-0.1;
			maxMoveZ=0.1;
		};
		class Library
		{
			libEnable=1;
			libTextDesc="";
		};
		class Eventhandlers: Eventhandlers
		{
			hit="_this call bis_fnc_planeAiEject";
		};
	};
	class FST_Delta7_Daara: FST_Delta7
	{
		author="$STR_3as_Studio";
		scope=2;
		displayName="[41st] Delta-7 Interceptor (Daara)";
		hiddenSelectionsTextures[]=
		{
			"3AS\3AS_Delta7\data\Textures\Delta7_Hull_Green_co.paa",
			"3AS\3AS_Delta7\data\Delta7_Landing_Gear_co.paa",
			"3AS\3AS_Delta7\data\Delta7_Cockpit_co.paa",
			"3as\3as_delta7\data\delta7_interfaces_ca.paa"
		};
		weapons[]=
		{
			"FST_ARC_Heavy_Chaingun",
			"FST_Rapture_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"ls_weapon_CMFlareLauncher",
			"Laserdesignator_pilotCamera"
		};
		magazines[]=
		{
			"FST_ARC_4000Rnd_Heavy_shells",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"ls_mag_192rnd_CMFlareChaff_cyan",
			"Laserbatteries",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile"
		};
	};
};
