class CfgPatches
{
	class FST_LAAT
	{
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"A3_weapons_F",
			"A3_Data_F",
			"A3_Air_F"
		};
		units[]=
		{
			"FST_laati_Turret",
			"FST_laati_mk2",
			"FST_laati_mk2Lights",
			"FST_laati_mk2Lights",
			"FST_laati_Turret_Daara",
			"FST_laati_Turret_Spade",
			"FST_laati_Turret_Shockcap",
			"FST_laati_Turret_Grim",
			"FST_laati_Turret_Qball",
			"FST_laati_Turret_Ripper",
			"FST_laati_Turret_Medusa",
			"FST_laati_Turret_Sierra",
			"FST_laati_Turret_Pole",
			"FST_laati_Turret_Jan",
			"FST_laati_Turret_Bees",
			"FST_laati_Turret_Ruby",
			"FST_laati_Turret_Hijack",
			"FST_laati_Turret_Fire",
			"FST_laati_Turret_Talisman",
			"FST_laati_Turret_Jorge",
			"FST_laati_Turret_Red",
			"FST_laati_mk2_Daara",
			"FST_laati_mk2_Shockcap",
			"FST_laati_mk2_Spade",
			"FST_laati_mk2_Grim",
			"FST_laati_mk2_Qball",
			"FST_laati_mk2_Ripper",
			"FST_laati_mk2_Medusa",
			"FST_laati_mk2_Sierra",
			"FST_laati_mk2_Pole",
			"FST_laati_mk2_Jan",
			"FST_laati_mk2_Bees",
			"FST_laati_mk2_Ruby",
			"FST_laati_mk2_Hijack",
			"FST_laati_mk2_Fire",
			"FST_laati_mk2_Talisman",
			"FST_laati_mk2_Jorge",
			"FST_laati_mk2_Red",
			"FST_laati_mk1Lights",
			"FST_laati_mk1Lights_Shockcap",
			"FST_laati_mk1Lights_Spade",
			"FST_laati_mk1Lights_Grim",
			"FST_laati_mk1Lights_Qball",
			"FST_laati_mk1Lights_Daara",
			"FST_laati_mk1Lights_Ripper",
			"FST_laati_mk1Lights_Medusa",
			"FST_laati_mk1Lights_Sierra",
			"FST_laati_mk1Lights_Pole",
			"FST_laati_mk1Lights_Jan",
			"FST_laati_mk1Lights_Bees",
			"FST_laati_mk1Lights_Ruby",
			"FST_laati_mk1Lights_Hijack",
			"FST_laati_mk1Lights_Fire",
			"FST_laati_mk1Lights_Talisman",
			"FST_laati_mk1Lights_Jorge",
			"FST_laati_mk1Lights_Red",
			"FST_laati_mk2Lights_Shockcap",
			"FST_laati_mk2Lights_Spade",
			"FST_laati_mk2Lights_Grim",
			"FST_laati_mk2Lights_Qball",
			"FST_laati_mk2Lights_Daara",	
			"FST_laati_mk2Lights_Ripper",
			"FST_laati_mk2Lights_Medusa",
			"FST_laati_mk2Lights_Sierra",
			"FST_laati_mk2Lights_Pole",
			"FST_laati_mk2Lights_Jan",
			"FST_laati_mk2Lights_Bees",
			"FST_laati_mk2Lights_Ruby",
			"FST_laati_mk2Lights_Hijack",
			"FST_laati_mk2Lights_Fire",
			"FST_laati_mk2Lights_Talisman",
			"FST_laati_mk2Lights_Jorge",
			"FST_laati_mk2Lights_Red",
			"FST_laati_Turret_RadarTestbed"
		};
		weapons[]=
		{
			"FST_SmokeLauncher"
		};
 		magazines[]=
		{
			"FST_SmokeLauncherMag"
		};
		ammo[]=
		{
			"FST_SmokeLauncherAmmo"
		}; 
	};
};
class Optics_Armored;
class Optics_Gunner_APC_01: Optics_Armored
{
	class Wide;
	class Medium;
	class Narrow;
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
class DefaultEventhandlers;
class CfgVehicles
{
	class AllVehicles;
	class Air: AllVehicles
	{
		class ACE_SelfActions;
	};
	class Helicopter: Air
	{
		TFAR_hasIntercom=1;
		TFAR_defaultIntercomSlot = -1;
		class ACE_SelfActions: ACE_SelfActions
		{
			class TFAR_IntercomChannel
			{
				displayName="$STR_tfar_core_Intercom_ACESelfAction_Name";
				condition="true";
				statement="";
				icon="";
				class TFAR_IntercomChannel_disabled
				{
					displayName = "Disabled";
					condition = "_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -2]; if (_intercom == -2) then { _vehicle setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -1, true]; _intercom = -1 }; _intercom != -1";
					statement = "(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)], -1, true];";
				};
				class TFAR_IntercomChannel_1
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 0";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],0,true];";
				};
				class TFAR_IntercomChannel_2
				{
					displayName="$STR_tfar_core_Intercom_ACESelfAction_Channel2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 1";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],1,true];";
				};
				class TFAR_IntercomChannel_Misc_1
				{
					displayName="Misc channel 1";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 2";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],2,true];";
				};
				class TFAR_IntercomChannel_Misc_2
				{
					displayName="Misc channel 2";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 3";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],3,true];";
				};
				class TFAR_IntercomChannel_Misc_3
				{
					displayName="Misc channel 3";
					condition="_vehicle = vehicle ACE_Player; _intercom = _vehicle getVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],-2]; if (_intercom == -2) then {_intercom = _vehicle getVariable ['TFAR_defaultIntercomSlot',TFAR_defaultIntercomSlot]}; _intercom != 4";
					statement="(vehicle ACE_Player) setVariable [format ['TFAR_IntercomSlot_%1',(netID ACE_Player)],4,true];";
				};
			};
		};
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
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
			};
			class CopilotTurret: MainTurret
			{
			};
		};
		class AnimationSources: AnimationSources
		{
		};
	};
	class 3AS_laat_Base: Helicopter_Base_H
	{
		class AnimationSources;
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitHRotor;
			class HitVRotor;
			class HitAvionics;
		};
	};
	class FST_laat_Base: 3AS_laat_Base
	{
		_generalmacro="FST_LAAT_i";
		accuracy=5;
		author="$STR_3AS_Studio";
		availableforsupporttypes[]=
		{
			"CAS_Heli",
			"Transport",
			"Drop"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] LAAT Base";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=0;
		side=1;
		fuelCapacity=8000;
		dustEffect="";
		waterEffect="";
		tas_can_impulse=0;
		tas_canBlift=1;
		tas_liftVars="[[[[0,-3.7,-7.8]]], [0], [0]]";
		altFullForce=10000;
		altNoForce=15000;
		maxSpeed=900;
		acceleration=600;
		maxFordingDepth=5;
		incomingMissileDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		LockDetectionSystem="1 + 2 + 4 + 8 + 16 + 32";
		getInRadius=5;
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
		defaultUserMFDvalues[]={0,1,0,1,0};
		armor=400;
		armorStructural=1;
		tf_range=100000;
		tf_isolatedAmount=0.40000001;
		tf_dialogUpdate="call TFAR_fnc_updateLRDialogToChannel;";
		tf_hasLRradio=1;
		enableRadio=1;
		ace_fastroping_enabled=1;
		ace_fastroping_ropeOrigins[]=
		{
			{1.5,1,-3.5},
			{1.5,2.5,-3.5},
			{1.5,-1,-3.5},
			{-1.5,1,-3.5},
			{-1.5,2.5,-3.5},
			{-1.5,-1,-3.5}
		};
		ace_fastroping_onCut="ace_fastroping_fnc_onCutCommon";
		ace_fastroping_onPrepare="ace_fastroping_fnc_onPrepareCommon";
		smokeLauncherAngle=360;
		smokeLauncherGrenadeCount=18;
		smokeLauncherVelocity=20;
 		class EventHandlers: DefaultEventhandlers
		{
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');_this execVM '\3AS\3as_Laat\LAATI\scripts\fired_laser.sqf';";
		}; 
		ace_cargo_hasCargo=1;
		ace_cargo_space=1000
        class ace_cargo {
            class cargo {
                class FST_ExplodeFuelBarrel_1 {
                    type = "FST_ExplodeFuelBarrel_1";
                    amount = 1;
                };
            };
        };
		class TransportItems
		{
			class _xx_IDA_Cauterizer
			{
				name="IDA_Cauterizer";
				count=1;
			};
			class _xx_ACE_plasmaIV
			{
				name="ACE_plasmaIV";
				count=2;
			};
			class _xx_FST_Bacta_Tank
			{
				name="FST_Bacta_Tank";
				count=1;
			};
		};
		class ls_impulsor: ls_impulsor_base
		{
			enabled=1;
			speed=300;
			fueldrain=9.9999997e-005;
			overchargespeed=800;
			overchargeFuelDrain=9.9999997e-005;
			overchargeCooldown=0
		};
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		class HitPoints
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
				convexcomponent="engine_hit";
				hitpoint="engine_hit";
				name="engine_hit";
				explosionShielding=2;
				radius=0.1;
				visual="";
				passthrough=0.1;
				minimalhit=0.1;
				material=-1;
				armor=4;
			};
			class HitEngine
			{
				armor=1;
				convexComponent="engine_hit";
				explosionShielding=2;
				material=51;
				name="engine_hit";
				hitpoint="engine_hit";
				passThrough=1;
				visual="";
				radius=0.2;
			};
			class HitEngine_1: HitEngine
			{
				convexComponent="engine_hit_1";
				name="engine_hit_1";
				hitpoint="engine_hit_1";
			};
			class HitEngine_2: HitEngine
			{
				convexComponent="engine_hit_2";
				name="engine_hit_2";
				hitpoint="engine_hit_2";
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
				armor=10;
				convexComponent="avionics_hit";
				explosionShielding=5;
				material=51;
				name="avionics_hit";
				passThrough=1;
				visual="";
				radius=0.5;
			};
			class HitGlass1
			{
				armor=2;
				name="HitGlass1";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
			class HitGlass2
			{
				armor=2;
				name="HitGlass2";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
			class HitGlass3
			{
				armor=2;
				name="HitGlass3";
				radius=0.40000001;
				visual="";
				passThrough=1;
				explosionShielding=3;
			};
		};
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
		weapons[]=
		{
			"FST_30mm_Autocannon_LAAT",
			"FST_Rapture_AGM_Missile",
			"FST_Foehammer_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher",
			"FST_SUU25",
			"FST_SmokeLauncher"
        };
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile", 
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
			maxTurn=360;
			initTurn=0;
			minElev=-5;
			maxElev=90;
			initElev=-10;
			maxXRotSpeed=0.30000001;
			maxYRotSpeed=0.30000001;
			pilotOpticsShowCursor=1;
			controllable=1;
			ace_missileguidance_usePilotCameraForTargeting=0;
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
						maxTrackableSpeed=400;
						componentType="IRSensorComponent";
						typeRecognitionDistance=2000;
						maxFogSeeThrough=-1;
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
						maxTrackableSpeed=400;
						aimDown=1;
						animDirection="";
						componentType="VisualSensorComponent";
						nightRangeCoef=0;
						maxFogSeeThrough=-1;
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
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						class GroundTarget
						{
							minRange=0;
							maxRange=4000;
							objectDistanceLimitCoef=-1;
							viewDistanceLimitCoef=-1;
						};
						typeRecognitionDistance=4000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=-1;
						maxGroundNoiseDistance=-1;
						maxFogSeeThrough=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
						animDirection="";
						aimDown=0;
						color[]={0.5,1,0.5,0.5};
						minTrackableSpeed=-1e+010;
						maxTrackableSpeed=1e+010;
						minTrackableATL=-1e+010;
						maxTrackableATL=1e+010;
						allowsMarking=1;
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
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
						typeRecognitionDistance=5000;
						angleRangeHorizontal=360;
						angleRangeVertical=360;
						groundNoiseDistanceCoef=-1;
						componentType="ActiveRadarSensorComponent";
						maxGroundNoiseDistance=-1;
						minSpeedThreshold=0;
						maxSpeedThreshold=0;
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
						typeRecognitionDistance=2000;
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
						maxFogSeeThrough=-1;
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
					class CrewDisplay
					{
						componentType = "CrewDisplayComponent";
						resource = "RscCustomInfoCrew";
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
					class CrewDisplay
					{
						componentType = "CrewDisplayComponent";
						resource = "RscCustomInfoCrew";
					};
				};
			};
			class TransportCounterMeasuresComponent;
		};
		class CargoTurret;
		class Turrets: Turrets
		{
			class Copilot: MainTurret
			{
				memoryPointGun="rear_chamber";
				gunBeg="rear_chamber";
				gunEnd="rear_muzzle";
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunneraction="LAAT_Pilot";
				gunnerCompartments="Compartment1";
				gunnerforceoptics=0;
				gunnername="CoPilot";
				usePiP=1;
				gunnergetinaction="Heli_Attack_01_Gunner_Enter";
				gunnergetoutaction="Heli_Attack_01_Gunner_Exit";
				gunnerinaction="";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				gunnerrighthandanimname="stick_copilot";
				initelev=-5;
				initturn=-180;
				iscopilot=1;
				maxelev=20;
				maxturn=-170;
				memorypointgunneroptics="backview";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				minelev=-20;
				minturn=-190;
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				selectionfireanim="zasleh3";
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
				animationSourceBody="mainTurret5";
				animationsourcegun="Maingun5";
				animationsourcehatch="";
				body="mainTurret5";
				gun="Maingun5";
				memorypointlmissile="Rocket_1";
				memorypointrmissile="Rocket_2";
				memoryPointLRocket="Rocket_1";
				memoryPointRRocket="Rocket_2";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
					//"FST_ParticleBeamCannon_B",
					"SmokeLauncher"
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"Laser_Battery",
					"Laser_Battery"
				};
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
				class Hitpoints
				{
					class HitTurret1
					{
						armor=0.80000001;
						material=-1;
						name="gun1";
						passthrough=0.5;
						visual="gun1";
					};
					class HitGun1
					{
						armor=0.40000001;
						material=-1;
						name="gun2";
						passthrough=0.2;
						visual="gun2";
					};
				};
			};
			class LeftDoorgun: MainTurret
			{
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
					"FST_LAAT_Ball_Turret",
					//"FST_ParticleBeamCannon",
					"Laserdesignator_pilotCamera"
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_thermal_coil_Ball",
					"FST_thermal_coil_Ball",
					"FST_thermal_coil_Ball",
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laserbatteries",
					"Laser_Battery"
				};
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				animationsourcebody="mainTurret";
				animationsourcegun="mainGun";
				animationsourcehatch="";
				body="mainTurret";
				gun="mainGun";
				castgunnershadow=1;
				commanding=-2;
				memoryPointGun="laser_l_muzzle";
				gunBeg="laser_l_muzzle";
				gunEnd="laser_l_chamber";
				gunneraction="LAAT_Gunner";
				gunnercompartments="Compartment2";
				gunnerdoor="";
				gunnerforceoptics=0;
				gunnerinaction="gunner_Heli_Transport_01";
				gunnerlefthandanimname="";
				gunnername="Ball Turret (Left)";
				gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				gunneropticsshowcursor=1;
				gunneroutopticsshowcursor=1;
				gunnerrighthandanimname="";
				iscopilot=0;
				lodturnedin=1000;
				lodturnedout=1000;
				minElev=-90;
				maxElev=90;
				initElev=0;
				minTurn=0;
				maxTurn=130;
				initTurn=0;
				selectionfireanim="";
				memorypointgunneroptics="laser_l_gunnerview";
				memorypointsgetingunner="pos_cargo_dir";
				memorypointsgetingunnerdir="pos_cargo";
				primarygunner=0;
				proxyindex=3;
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
				stabilizedinaxes=3;
				viewgunnershadow=1;
				class OpticsIn
				{
					class Wide
					{
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
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
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initfov=0.093000002;
						maxfov=0.093000002;
						minfov=0.093000002;
						opticsdisplayname="M";
					};
					class Narrow: Wide
					{
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
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
			};
			class RightDoorGun: LeftDoorgun
			{
				isCopilot=0;
				body="mainTurret2";
				gun="mainGun2";
				inGunnerMayFire=1;
				gunnerFireAlsoInInternalCamera=1;
				outGunnerMayFire=1;
				animationSourceBody="MainTurret2";
				animationSourceGun="MainGun2";
				memoryPointGun="laser_r_muzzle";
				gunBeg="laser_R_muzzle";
				gunEnd="lazer_R_chamber";
				minElev=-90;
				maxElev=90;
				initElev=0;
				minTurn=-130;
				maxTurn=0;
				initTurn=0;
				gunnerlefthandanimname="";
				gunnerrighthandanimname="";
				gunnerLeftLegAnimName="";
				gunnerRightLegAnimName="";
				stabilizedInAxes=3;
				selectionFireAnim="";
				proxyIndex=2;
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
				gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Transport_01_Optics_Gunner_F";
				gunnerOutOpticsShowCursor=1;
				gunnerOpticsShowCursor=1;
				gunnerName="Ball Turret (Right)";
				memoryPointGunnerOptics="laser_r_gunnerview";
				gunnerCompartments="Compartment5";
				memorypointsgetingunner="pos_cargo_dir";
				memorypointsgetingunnerdir="pos_cargo";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
					"FST_LAAT_Ball_Turret",
					//"FST_ParticleBeamCannon_R",
					"Laserdesignator_pilotCamera"
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_thermal_coil_Ball",
					"FST_thermal_coil_Ball",
					"FST_thermal_coil_Ball",
					"Laser_Battery_F",
					"Laser_Battery_F",
					"Laserbatteries",
					"Laser_Battery"
				};
				class OpticsIn
				{
					class Wide
					{
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_wide_F";
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
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_medium_F";
						initfov=0.093000002;
						maxfov=0.093000002;
						minfov=0.093000002;
						opticsdisplayname="M";
					};
					class Narrow: Wide
					{
						gunneropticsmodel="\A3\Weapons_F_Beta\Reticle\Heli_Attack_01_Optics_Gunner_narrow_F";
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
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_inside_5";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInCargo[]=
				{
					"pos_cargo"
				};
				memoryPointsGetInCargoDir[]=
				{
					"pos_cargo_dir"
				};
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				showAsCargo=1;
				gunnerName="Ramp Gunner (Left)";
				proxyIndex=15;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInCargo[]=
				{
					"pos_cargo"
				};
				memoryPointsGetInCargoDir[]=
				{
					"pos_cargo_dir"
				};
				gunnerName="Ramp Gunner (Right)";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="$STR_A3_TURRETS_BENCH_R1";
				proxyIndex=17;
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				showAsCargo=1;
				isPersonTurret=1;
				ejectDeadGunner=0;
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{9.4394999,-94.855698},
						{12.5849,-34.384102},
						{14.0365,60.875801},
						{14.1021,95}
					};
					limitsArrayBottom[]=
					{
						{-32.2276,-94.901703},
						{-32.7616,-79.195801},
						{-45,-75.648804},
						{-44.965302,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
				class dynamicViewLimits
				{
					CargoTurret_06[]={-65,95};
				};
				playerPosition=4;
				soundAttenuationTurret="";
				disableSoundAttenuation=1;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_04: CargoTurret_03
			{
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="$STR_A3_TURRETS_BENCH_L2";
				proxyIndex=18;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-65,95};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{10.6196,-94.8601},
						{11.1364,-69.195396},
						{14.0333,15.3744},
						{11.6789,94.968201}
					};
					limitsArrayBottom[]=
					{
						{-32.208099,-94.038101},
						{-32.368198,-78.541496},
						{-45,-72.854202},
						{-44.918598,94.886497}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
			class CargoTurret_05: CargoTurret_04
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_L1";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				proxyIndex=19;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-95,65};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{14.705,-95},
						{14.1224,-62.859001},
						{12.3049,32.941399},
						{9.0861998,94.947998}
					};
					limitsArrayBottom[]=
					{
						{-45,-94.965599},
						{-45,80.990402},
						{-31.903299,82.846497},
						{-31.793501,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
			class CargoTurret_06: CargoTurret_03
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_R2";
				proxyIndex=16;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-95,65};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{12.1826,-95},
						{14.4163,-16.698299},
						{11.5046,68.829201},
						{11.8156,94.980904}
					};
					limitsArrayBottom[]=
					{
						{-44.897598,-94.999397},
						{-44.973999,81.190598},
						{-32.447899,83.791603},
						{-32.740501,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
		};
 		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Lamps
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
		}; 
		class Library
		{
			libtextdesc="";
		};
		soundEngineOnInt[]=
		{
			"41st_Vehicles\LAAT\Sounds\LAAT_Startup_9_467.ogg",
			0.5,
			1
		};
		soundEngineOnExt[]=
		{
			"41st_Vehicles\LAAT\Sounds\LAAT_Startup_9_467.ogg",
			1.1,
			1,
			600
		};
		soundEngineOffInt[]=
		{
			"41st_Vehicles\LAAT\Sounds\LAAT_Shutdown_4_744.ogg",
			0.5,
			1
		};
		soundEngineOffExt[]=
		{
			"41st_Vehicles\LAAT\Sounds\LAAT_Shutdown_4_744.ogg",
			1.1,
			1,
			600
		};
		class Sounds
		{
			class EngineExt
			{
				sound[]=
				{
					"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
					0.8,
					1,
					1500
				};
				frequency="rotorSpeed";
				volume="4*camPos*((rotorSpeed-0.55))";
			};
			class DistanceSound
			{
				sound[]=
				{
					"A3\Sounds_F_Jets\vehicles\air\Shared\FX_Plane_Jet_wind_ext",
					1.5,
					1,
					10000
				};
				frequency=1;
				volume="2 * camPos*(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 300)/ 900),(((-150) max 900)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-250) max 900)/ 900),(((-200) max 900)/ 900)]))";
			};
			class TurbineSound
			{
				sound[]=
				{
					"A3\Sounds_F_Jets\vehicles\air\Plane_Fighter_01\B_PLANE_FIGHTER_01_engine_back",
					1.8,
					1,
					12000
				};
				frequency=0.80000001;
				volume="2 * camPos*(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 200)/ 900),(((-150) max 900)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-200) max 900)/ 900),(((-200) max 900)/ 900)]))";
			};
			class Flyby
			{
				sound[]=
				{
					"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
					0.7,
					1,
					500
				};
				frequency="rotorSpeed";
				volume="(camPos)";
			};
			class RotorExt
			{
				sound[]=
				{
					"3as\3as_laat\sounds\LAAT_Idle2.ogg",
					1.1,
					1,
					2000
				};
				frequency="rotorSpeed * (1-rotorThrust/5)";
				volume="camPos*(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 0)/ 900),(((-150) max 500)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-250) max 500)/ 900),(((-200) max 500)/ 900)])) / 3";
				cone[]={1.6,3.1400001,1.6,0.94999999};
			};
			class RotorSwistExt
			{
				sound[]=
				{
					"41st_Vehicles\LAAT\Sounds\LAAT_impulse_4_757.ogg",
					0.8,
					1,
					4000
				};
				frequency=1;
				volume="2 * camPos*(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 300)/ 900),(((-150) max 900)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-250) max 900)/ 900),(((-200) max 900)/ 900)]))";
				cone[]={1,1.4,1,0};
			};
			class EngineInt
			{
				sound[]=
				{
					"3as\3as_laat\sounds\LAAT_IdleInt.ogg",
					1.5,
					1
				};
				frequency="rotorSpeed";
				volume="3*(1-camPos)*(rotorSpeed-0.55)";
			};
			class RotorInt
			{
				sound[]=
				{
					"3as\3as_laat\sounds\LAAT_Idle2Int.ogg",
					1,
					1
				};
				frequency="rotorSpeed * (1-rotorThrust/5)";
				volume="(1-camPos)*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)*(playerPos)";
			};
			class TransmissionDamageExt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageExt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class damageAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.31622776,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
			};
			class damageAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.22387211,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
			};
			class rotorLowAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.31622776,
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
					0.22387211,
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
					"A3\Sounds_F\vehicles\air\noises\wheelsInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubLandExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrublandext",
					1,
					1,
					200
				};
				frequency=1;
				volume="camPos * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubBuildingInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wheelsInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos) * (scrubBuilding factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
			};
			class scrubBuildingExt
			{
				sound[]=
				{
					"A3\Sounds_F\dummysound",
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
					"A3\Sounds_F\vehicles\air\noises\scrubTreeInt",
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
			class SlingLoadDownExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
					1.2589254,
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
					1.2589254,
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
					500
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
					500
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,1])";
			};
			class WindInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wind_closed",
					0.26234132,
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
			};
			class GStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress2c",
					0.5,
					1,
					50
				};
				frequency=1;
				volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
			};
			class SpeedStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress3",
					0.70794576,
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[40,70])";
			};
			class CockpitNoises
			{
				sound[]=
				{
					"",
					0.70794576,
					1
				};
				frequency=1;
				volume="(1-camPos)*(1-playerPos)*(engineOn)";
			};
		};
		class SoundsExt
		{
			class SoundEvents
			{
			};
			class Sounds
			{
				class EngineExt
				{
					sound[]=
					{
						"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
						0.8,
						1,
						1500
					};
					frequency="rotorSpeed";
					volume="4*camPos*((rotorSpeed-0.55))";
				};
				class RotorExt
				{
					sound[]=
					{
						"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
						0.8,
						1,
						2000
					};
					frequency="rotorSpeed * (1-rotorThrust/5)";
					volume="camPos**(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 300)/ 900),(((-150) max 900)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-250) max 900)/ 900),(((-200) max 900)/ 900)]))";
					cone[]={1.6,3.1400001,1.6,0.94999999};
				};
				class RotorSwistExt
				{
					sound[]=
					{
						"41st_Vehicles\LAAT\Sounds\LAAT_impulse_4_757.ogg",
						0.7,
						1,
						2000
					};
					frequency=1;
					volume="2 * camPos*(((((-speed*3.6) max speed*3.6)/ 900) factor[(((-0) max 300)/ 900),(((-150) max 900)/ 900)]) * ((((-speed*3.6) max speed*3.6)/ 900) factor[(((-250) max 900)/ 900),(((-200) max 900)/ 900)]))";
					cone[]={1,1.4,1,0};
				};
				class EngineInt
				{
					sound[]=
					{
						"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
						0.8,
						1
					};
					frequency="rotorSpeed";
					volume="3*(1-camPos)*(rotorSpeed-0.55)";
				};
				class RotorInt
				{
					sound[]=
					{
						"41st_Vehicles\LAAT\Sounds\LAAT_Idle_50_027.ogg",
						0.8,
						1
					};
					frequency="rotorSpeed * (1-rotorThrust/5)";
					volume="(1-camPos)*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
				};
				class TransmissionDamageExt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageExt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class damageAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.31622776,
						1
					};
					frequency=1;
					volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
				};
				class damageAlarmExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.22387211,
						1,
						20
					};
					frequency=1;
					volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
				};
				class rotorLowAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
						0.31622776,
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
						0.22387211,
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
						"A3\Sounds_F\vehicles\air\noises\wheelsInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubLandExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\landing_wheels_large_int2",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (scrubLand factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubBuildingInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wheelsInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1-camPos) * (scrubBuilding factor[0.02, 0.05]) * (1 - (lateralMovement factor [0.7,1]))";
				};
				class scrubBuildingExt
				{
					sound[]=
					{
						"A3\Sounds_F\dummysound",
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
						"A3\Sounds_F\vehicles\air\noises\scrubTreeInt",
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
				class SlingLoadDownExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
						1,
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
						1,
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
						500
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
						500
					};
					frequency=1;
					volume="(1-camPos)*(slingLoadActive factor [0,1])";
				};
				class WindInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wind_closed",
						0.26234132,
						1,
						50
					};
					frequency=1;
					volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
				};
				class GStress
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\vehicle_stress2c",
						0.5,
						1,
						50
					};
					frequency=1;
					volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
				};
				class SpeedStress
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\vehicle_stress3",
						0.70794576,
						1,
						50
					};
					frequency=1;
					volume="(1-camPos)*(speed factor[40,70])";
				};
			};
		};
	};
	class FST_laati_Turret: FST_laat_Base
	{
		_generalmacro="FST_LAAT_i";
		accuracy=5;
		author="$STR_3AS_Studio";
		availableforsupporttypes[]=
		{
			"CAS_Heli",
			"Transport",
			"Drop"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] LAAT/i Mk I Gunship";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=1;
 		class EventHandlers: DefaultEventhandlers
		{
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');_this execVM '\3AS\3as_Laat\LAATI\scripts\fired_laser.sqf';";
		}; 
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
 		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Lamps
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				initPhase=1;
				animPeriod=1;
			};
		}; 
		class Library
		{
			libtextdesc="";
		};
	};
 	class FST_LAAT_LampBase: FST_laat_Base
	{
		class Reflectors
		{
			class Left
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=450;
				size=15;
				innerAngle=15;
				outerAngle=300;
				coneFadeCoef=5;
				position="Light_L_Pos";
				direction="Light_L_Dir";
				hitpoint="Light_b_hitpoint";
				selection="Light_L_Lamp";
				useFlare=1;
				flareSize=15;
				flareMaxDistance=5000;
				dayLight=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=300;
					hardLimitEnd=400;
				};
			};
			class Right
			{
				color[]={7000,7500,10000};
				ambient[]={70,75,100};
				intensity=450;
				size=15;
				innerAngle=15;
				outerAngle=300;
				coneFadeCoef=5;
				position="Light_R_Pos";
				direction="Light_R_Dir";
				hitpoint="Light_b_hitpoint";
				selection="Light_R_Lamp";
				useFlare=1;
				flareSize=15;
				flareMaxDistance=5000;
				dayLight=0;
				class Attenuation
				{
					start=0;
					constant=0;
					linear=1;
					quadratic=1;
					hardLimitStart=300;
					hardLimitEnd=400;
				};
			};
		};
	};
	class FST_laati_mk1Lights: FST_LAAT_LampBase
	{
		_generalmacro="TCW_LAAT_i";
		accuracy=5;
		author="$STR_3AS_Studio";
		availableforsupporttypes[]=
		{
			"CAS_Heli"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] LAAT/i Mk I Gunship (Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=1;
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
		class Turrets: Turrets
		{
			class Copilot: MainTurret
			{
				memoryPointGun="rear_chamber";
				gunBeg="rear_chamber";
				gunEnd="rear_muzzle";
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunneraction="LAAT_Pilot";
				gunnerforceoptics=0;
				gunnername="CoPilot";
				usePiP=1;
				gunnergetinaction="Heli_Attack_01_Gunner_Enter";
				gunnergetoutaction="Heli_Attack_01_Gunner_Exit";
				gunnerinaction="";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				gunnerrighthandanimname="stick_copilot";
				initelev=-5;
				initturn=-180;
				iscopilot=1;
				maxelev=20;
				maxturn=-170;
				memorypointgunneroptics="backview";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				minelev=-20;
				minturn=-190;
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				selectionfireanim="zasleh3";
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
				animationSourceBody="mainTurret5";
				animationsourcegun="Maingun5";
				animationsourcehatch="";
				body="mainTurret5";
				gun="Maingun5";
				memorypointlmissile="Rocket_1";
				memorypointrmissile="Rocket_2";
				memoryPointLRocket="Rocket_1";
				memoryPointRRocket="Rocket_2";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"Laser_Battery"
				};
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
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_inside_5";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Left)";
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				proxyIndex=15;
				showAsCargo=1;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Right)";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,95};
				};
			};
			class CargoTurret_03: CargoTurret
			{
				gunnerAction="passenger_bench_1";
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="$STR_A3_TURRETS_BENCH_R1";
				proxyIndex=17;
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				showAsCargo=1;
				isPersonTurret=1;
				ejectDeadGunner=0;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{9.4394999,-94.855698},
						{12.5849,-34.384102},
						{14.0365,60.875801},
						{14.1021,95}
					};
					limitsArrayBottom[]=
					{
						{-32.2276,-94.901703},
						{-32.7616,-79.195801},
						{-45,-75.648804},
						{-44.965302,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
				class dynamicViewLimits
				{
					CargoTurret_06[]={-65,95};
				};
				playerPosition=4;
				soundAttenuationTurret="";
				disableSoundAttenuation=1;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_04: CargoTurret_03
			{
				gunnerCompartments="Compartment2";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="$STR_A3_TURRETS_BENCH_L2";
				proxyIndex=18;
				class dynamicViewLimits
				{
					CargoTurret_05[]={-65,95};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{10.6196,-94.8601},
						{11.1364,-69.195396},
						{14.0333,15.3744},
						{11.6789,94.968201}
					};
					limitsArrayBottom[]=
					{
						{-32.208099,-94.038101},
						{-32.368198,-78.541496},
						{-45,-72.854202},
						{-44.918598,94.886497}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
			class CargoTurret_05: CargoTurret_04
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_L1";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				proxyIndex=19;
				class dynamicViewLimits
				{
					CargoTurret_04[]={-95,65};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{14.705,-95},
						{14.1224,-62.859001},
						{12.3049,32.941399},
						{9.0861998,94.947998}
					};
					limitsArrayBottom[]=
					{
						{-45,-94.965599},
						{-45,80.990402},
						{-31.903299,82.846497},
						{-31.793501,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
			class CargoTurret_06: CargoTurret_03
			{
				gunnerCompartments="Compartment2";
				gunnerName="$STR_A3_TURRETS_BENCH_R2";
				proxyIndex=16;
				class dynamicViewLimits
				{
					CargoTurret_03[]={-95,65};
				};
				class TurnOut
				{
					limitsArrayTop[]=
					{
						{12.1826,-95},
						{14.4163,-16.698299},
						{11.5046,68.829201},
						{11.8156,94.980904}
					};
					limitsArrayBottom[]=
					{
						{-44.897598,-94.999397},
						{-44.973999,81.190598},
						{-32.447899,83.791603},
						{-32.740501,95}
					};
				};
				class TurnIn: TurnOut
				{
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Lamps
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class Turrets
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
		};
		class Library
		{
			libtextdesc="";
		};
	};
	class FST_laati_mk2: FST_laat_Base
	{
		_generalmacro="TCW_LAAT_i";
		accuracy=5;
		author="$STR_3AS_Studio";
		availableforsupporttypes[]=
		{
			"CAS_Heli"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] LAAT/i Mk II Gunship";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=1;
 		class EventHandlers: DefaultEventhandlers
		{
			fired="_this call (uinamespace getvariable 'BIS_fnc_effectFired');_this execVM '\3AS\3as_Laat\LAATI\scripts\fired_laser.sqf';";
		}; 
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
		class Turrets: Turrets
		{
			class Copilot: MainTurret
			{
				memoryPointGun="rear_chamber";
				gunBeg="rear_chamber";
				gunEnd="rear_muzzle";
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunneraction="LAAT_Pilot";
				gunnerforceoptics=0;
				gunnername="CoPilot";
				usePiP=1;
				gunnergetinaction="Heli_Attack_01_Gunner_Enter";
				gunnergetoutaction="Heli_Attack_01_Gunner_Exit";
				gunnerinaction="";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				gunnerrighthandanimname="stick_copilot";
				initelev=-5;
				initturn=-180;
				iscopilot=1;
				maxelev=20;
				maxturn=-170;
				memorypointgunneroptics="backview";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				minelev=-20;
				minturn=-190;
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				selectionfireanim="zasleh3";
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
				animationSourceBody="mainTurret5";
				animationsourcegun="Maingun5";
				animationsourcehatch="";
				body="mainTurret5";
				gun="Maingun5";
				memorypointlmissile="Rocket_1";
				memorypointrmissile="Rocket_2";
				memoryPointLRocket="Rocket_1";
				memoryPointRRocket="Rocket_2";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"Laser_Battery"
				};
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
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_inside_5";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Left)";
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				proxyIndex=15;
				showAsCargo=1;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Right)";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,95};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class Lamps
			{
				source="user";
				animPeriod=1;
				initPhase=0;
			};
			class Turrets
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
		};
		class Library
		{
			libtextdesc="";
		};
	};
	class FST_laati_mk2Lights: FST_LAAT_LampBase
	{
		_generalmacro="TCW_LAAT_i";
		accuracy=5;
		author="$STR_3AS_Studio";
		availableforsupporttypes[]=
		{
			"CAS_Heli"
		};
		cost="3e+006";
		crew="FST_Pilot_P1";
		displayname="[41st] LAAT/i Mk II Gunship (Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		scope=2;
		side=1;
		typicalcargo[]=
		{
			"FST_Pilot_P1"
		};
		class Turrets: Turrets
		{
			class Copilot: MainTurret
			{
				memoryPointGun="rear_chamber";
				gunBeg="rear_chamber";
				gunEnd="rear_muzzle";
				caneject=0;
				castgunnershadow=1;
				commanding=-1;
				discretedistance[]={100,200,300,400,500,600,700,800,1000,1200,1500,1800,2100};
				discretedistanceinitindex=5;
				gunneraction="LAAT_Pilot";
				gunnerforceoptics=0;
				gunnername="CoPilot";
				usePiP=1;
				gunnergetinaction="Heli_Attack_01_Gunner_Enter";
				gunnergetoutaction="Heli_Attack_01_Gunner_Exit";
				gunnerinaction="";
				gunnerlefthandanimname="lever_copilot";
				gunneropticseffect[]=
				{
					"TankCommanderOptics1",
					"BWTV"
				};
				gunneropticsmodel="";
				gunnerrighthandanimname="stick_copilot";
				initelev=-5;
				initturn=-180;
				iscopilot=1;
				maxelev=20;
				maxturn=-170;
				memorypointgunneroptics="backview";
				memorypointsgetingunner="pos_driver";
				memorypointsgetingunnerdir="pos_driver_dir";
				minelev=-20;
				minturn=-190;
				outgunnermayfire=1;
				precisegetinout=1;
				primarygunner=0;
				selectionfireanim="zasleh3";
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
				animationSourceBody="mainTurret5";
				animationsourcegun="Maingun5";
				animationsourcehatch="";
				body="mainTurret5";
				gun="Maingun5";
				memorypointlmissile="Rocket_1";
				memorypointrmissile="Rocket_2";
				memoryPointLRocket="Rocket_1";
				memoryPointRRocket="Rocket_2";
				turretinfotype="RscOptics_Heli_Attack_01_gunner";
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT",
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"Laser_Battery"
				};
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
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerAction="passenger_inside_5";
				canHideGunner=0;
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Left)";
				proxyType="CPCargo";
				viewGunnerInExternal=1;
				proxyIndex=15;
				showAsCargo=1;
				soundAttenuationTurret="HeliAttenuationGunner";
				isPersonTurret=1;
				ejectDeadGunner=1;
				maxElev=15;
				minElev=-35;
				maxTurn=30;
				minTurn=-30;
				class dynamicViewLimits
				{
					CargoTurret_02[]={-65,95};
				};
				playerPosition=4;
				gunnerGetInAction="GetInHeli_Light_01bench";
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments="Compartment2";
				getOutAction="GetOutLow";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				gunnerName="Ramp Gunner (Right)";
				proxyIndex=14;
				class dynamicViewLimits
				{
					CargoTurret_01[]={-65,95};
				};
			};
		};
		class AnimationSources: AnimationSources
		{
			class Doors
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class Lamps
			{
				source="user";
				animPeriod=1;
				initPhase=1;
			};
			class Turrets
			{
				source="user";
				initPhase=0;
				animPeriod=0.001;
			};
		};
		class Library
		{
			libtextdesc="";
		};
	};
	class FST_laati_Turret_Daara: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Daara)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_Daara.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Shockcap: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Shockcap)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Shockcap.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Spade: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Spade)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Spade.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_Turret_Grim: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Grim)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Grim.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Grim.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_Turret_Qball: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Q-Ball)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Qball.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_Turret_Ripper: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Ripper)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ripper.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ripper.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_Turret_Medusa: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Medusa)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Medusa.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Medusa.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_Turret_Sierra: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Sierra)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Sierra.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Sierra.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Pole: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Pole)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Pole.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Pole.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Bees: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Bees)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Bees.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Bees.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Ruby: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Ruby)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ruby.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ruby.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Ruby.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Hijack: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Hijack)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Hijack.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Red: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Red)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Vengence";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Red.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Red.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Red.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Fire: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Fire)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Fire.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Talisman: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Talisman)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Talisman.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Talisman.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_Turret_Jorge: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=0;
		displayname="[41st] LAAT/i Mk I Gunship (Jorge)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_P2_Jorge";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Weapons_Jorge_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_Jorge_CO.paa",
		};
		textureList[]={};
	};
	class FST_laati_Turret_Jan: FST_laati_Turret
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Jan)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Viz";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Jan.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Daara: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Daara)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_Daara.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Shockcap: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Shockcap)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Shockcap.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Spade: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Spade)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Spade.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2_Grim: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Grim)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Grim.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Grim.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2_Qball: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Q-Ball)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Qball.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2_Ripper: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Ripper)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ripper.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ripper.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2_Medusa: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Medusa)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Medusa.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Medusa.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Sierra: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Sierra)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Sierra.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Sierra.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Pole: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Pole)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Pole.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Pole.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Bees: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Bees)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Bees.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Bees.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Ruby: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Ruby)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ruby.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ruby.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Ruby.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Hijack: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Hijack)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Hijack.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Red: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Red)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Vengence";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Red.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Red.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Red.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Fire: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Fire)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Fire.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Talisman: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Talisman)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Talisman.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Talisman.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2_Jorge: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=0;
		displayname="[41st] LAAT/i Mk II Gunship (Jorge)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_P2_Jorge";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Weapons_Jorge_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_Jorge_CO.paa",
		};
		textureList[]={};
	};
	class FST_laati_mk2_Jan: FST_laati_mk2
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Jan)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Viz";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Jan.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	// Start Lamps Customs
	class FST_laati_mk1Lights_Daara: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Daara/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_Daara.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Shockcap: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Shockcap/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Shockcap.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Spade: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Spadel/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Spade.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk1Lights_Grim: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Grim/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Grim.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Grim.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk1Lights_Qball: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Q-Ball/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Qball.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk1Lights_Ripper: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Ripper/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ripper.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ripper.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk1Lights_Medusa: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Medusa/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Medusa.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Medusa.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Sierra: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Sierra/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Sierra.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Sierra.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Pole: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Pole/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Pole.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Pole.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Bees: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Bees/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Bees.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Bees.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Ruby: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Ruby/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ruby.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ruby.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Ruby.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Red: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Red/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Vengence";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Red.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Red.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Red.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Fire: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Fire/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Fire.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Talisman: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Talisman/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Talisman.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Talisman.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Jorge: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=0;
		displayname="[41st] LAAT/i Mk I Gunship (Jorge/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_P2_Jorge";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Weapons_Jorge_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_Jorge_CO.paa",
		};
		textureList[]={};
	};
	class FST_laati_mk1Lights_Jan: FST_laati_mk1Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk I Gunship (Jan/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Viz";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Jan.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Daara: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Daara/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_Daara.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Shockcap: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Shockcap/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Shockcap.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		magazines[]=
		{
			"Laser_Battery",
			"Laserbatteries",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_LAAT_P_12rnd_M",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"FST_Thermal_Coil",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"240Rnd_CMFlare_Chaff_Magazine",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_SmokeLauncherMag",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Spade: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Spadel/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Spade.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2Lights_Grim: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Grim/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Grim.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Grim.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2Lights_Qball: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Q-Ball/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Qball.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	 
	class FST_laati_mk2Lights_Ripper: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Ripper/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ripper.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ripper.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};	
	class FST_laati_mk2Lights_Medusa: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Medusa/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Medusa.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Medusa.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Sierra: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Sierra/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Sierra.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Sierra.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Pole: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Pole/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Pole.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Pole.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Bees: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Bees/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Bees.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Bees.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Ruby: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Ruby/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Ruby.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Ruby.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Ruby.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Red: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Red/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Vengence";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Red.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Red.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_CO_41st_Red.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Hijack: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Hijack/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Daara";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Hijack.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Fire: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Fire/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Fire.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Talisman: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Talisman/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Steel";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Talisman.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st_Talisman.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Jorge: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=0;
		displayname="[41st] LAAT/i Mk II Gunship (Jorge/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_P2_Jorge";
		author="Gold";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_Jorge_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Weapons_Jorge_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"41st_Vehicles\NEWLAAT\Data\Interior_Jorge_CO.paa",
		};
		textureList[]={};
	};
	class FST_laati_mk2Lights_Jan: FST_laati_mk2Lights
	{
		scope=2;
		scopecurator=2;
		scopearsenal=2;
		side=1;
		displayname="[41st] LAAT/i Mk II Gunship (Jan/Lamps)";
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		author="Viz";
		hiddenselectionstextures[]=
		{
			"41st_Vehicles\NEWLAAT\Data\Hull_CO_41st_Jan.paa",
			"41st_Vehicles\NEWLAAT\Data\Wings_CO_41st.paa",
			"3AS\3as_Laat\LAATI\data\Weapons_CO.paa",
			"3AS\3as_Laat\LAATI\data\Weapon_Details_CO.paa",
			"3AS\3as_Laat\LAATI\data\Interior_CO.paa"
		};
		textureList[]={};
	};
};
class CfgAmmo
{
	class 3AS_Sabre_HE;
	class M_Scalpel_AT;
	class BulletBase;
	class FST_SmokeLauncherAmmo: BulletBase
	{
		muzzleEffect="BIS_fnc_effectFiredSmokeLauncher";
		effectsSmoke="EmptyEffect";
		weaponLockSystem="1 + 2 + 4";
		hit=1;
		indirectHit=0;
		indirectHitRange=0;
		timeToLive=15;
		thrustTime=10;
		airFriction=-0.1;
		simulation="shotCM";
		model="\A3\weapons_f\empty";
		maxControlRange=50;
		initTime=2;
		aiAmmoUsageFlags="4 + 8";
	};
	class laserAmmo: 3AS_Sabre_HE
	{
		airFriction=0;
		maxSpeed=10000;
		indirecthit=30;
		indirectHitRange=3;
		hit=100;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		cartridge="";
		model="a3\weapons_f\data\bullettracer\tracer_green";
		simulation="shotbullet";
		effectFly="3AS_PlasmaBolt_Medium_Green_Fly";
	};
	class laserAmmo_F: 3AS_Sabre_HE
	{
		hit=130;
		indirectHit=8;
		indirectHitRange=3;
		explosive=0.80000001;
		caliber=5.4000001;
		airlock=1;
		aiAmmoUsageFlags="64 + 128 + 256 + 512";
		tracerScale=2.5;
		tracerStartTime=0.1;
		tracerEndTime=4.6999998;
		explosionEffects="ExploAmmoExplosion";
		craterEffects="ExploAmmoCrater";
		model="a3\weapons_f\data\bullettracer\tracer_green";
		simulation="shotbullet";
		effectFly="3AS_Laser_effect_Green_fly";
		cartridge="";
	};
	class OPTRE_M_ASGM2_AA;
	class FST_Rapture_Anti_Tank_Missile: M_Scalpel_AT
	{
		displayname="High Explosive AT";
		warheadName="AT";
		hit=1000;
		model="OPTRE_weapons\Aircraft\ASGM10_missile_fly.p3d";
		indirecthit=500;
		indirecthitrange=10;
		caliber=50;
		allowAgainstInfantry=1;
		airLock=1;
		irLock=1;
		missileLockCone=120;
		missileKeepLockedCone=120;
		maneuvrability=25;
		airFriction=0.079999998;
		sideAirFriction=0.16;
		weaponLockSystem="1+2+4+8+16";
		thrust=240;
		trackOversteer = 1;
		flightProfiles[] = {TopDown};
		trackLead = 1;
		cmImmunity=0.85;
		missileLockMaxDistance=8000;
		missileLockMinDistance=50;
		effectsMissile="3AS_Rocket_effect_Blue_fly";
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class SomeRadarSensorComponent
					{
						componentType = "ActiveRadarSensorComponent";
						class AirTarget      // ranges for targets with sky background
						{
							minRange = 0;         //minimum possible range in meters  
							maxRange = 0;       //maximum possible range in meters                 
							objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
							viewDistanceLimitCoef = -1;      //range not limited by view distance           
						};
						class GroundTarget      // ranges for targets with ground background                           
						{
							minRange = 50;
							maxRange = 5500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 5500; // distance how far the target type gets recognized                                          
						angleRangeHorizontal = 180;     // sensor azimuth coverage in degrees         
						angleRangeVertical = 240;       // sensor elevation coverage in degrees       
						groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible           
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold         
					};
					class SomeLaserSensorComponent
					{
						componentType = "LaserSensorComponent";
						class AirTarget      // ranges for targets with sky background
						{
							minRange = 0;         //minimum possible range in meters  
							maxRange = 0;       //maximum possible range in meters                 
							objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
							viewDistanceLimitCoef = -1;      //range not limited by view distance           
						};
						class GroundTarget      // ranges for targets with ground background                           
						{
							minRange = 50;
							maxRange = 5500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 5500; // distance how far the target type gets recognized                                          
						angleRangeHorizontal = 180;     // sensor azimuth coverage in degrees         
						angleRangeVertical = 240;       // sensor elevation coverage in degrees       
						groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible           
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold         
					};					
				};
			};
		};			
	};
	class M_Air_AA;
	class FST_Foehammer_Anti_Tank_Missile : M_Air_AA
	{
		model = "\FIR_AirWeaponSystem_US\data\ASM2\ASM2_fly";
		proxyShape = "\FIR_AirWeaponSystem_US\data\ASM2\ASM2";
		warheadName = "HEAT";		
		submunitionAmmo = "FIR_HF_Tandem";
		submunitionDirectionType = "SubmunitionModelDirection";
		submunitionInitSpeed = 1000;
		submunitionParentSpeedCoef = 0.0;
		submunitionInitialOffset[] = {0,0,-0.2};
		triggerOnImpact = 1;
		deleteParentWhenTriggered = 0;		
		hit = 2000;
		indirectHit = 60;
		indirectHitRange = 8;
		timetoLive = 60;
		maneuvrability = 35;
		canLock = 1;
		airLock = 0;
		irLock = 1;
		laserLock = 1;
		nvLock = 0;
		initTime = 0.100000;
		thrustTime = 10;
		maxspeed = 500;
		maxControlRange = 2800;
		trackOversteer = 1;
		trackLead = 1;
		thrust = 300;
		effectsMissileInit = "MissileDAR1";
		effectsMissile = "3AS_Rocket_effect_Blue_fly";
		soundHit[] = { "A3\Sounds_F\weapons\Rockets\explosion_missile_01", 3.1622777, 1, 1800 };
		missileLockCone = 180;
		missileKeepLockedCone = 180;
		missileLockMaxDistance = 5500;
		missileLockMinDistance = 50;
		missileLockMaxSpeed = 550;	
		class Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class SomeRadarSensorComponent
					{
						componentType = "ActiveRadarSensorComponent";
						class AirTarget      // ranges for targets with sky background
						{
							minRange = 0;         //minimum possible range in meters  
							maxRange = 0;       //maximum possible range in meters                 
							objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
							viewDistanceLimitCoef = -1;      //range not limited by view distance           
						};
						class GroundTarget      // ranges for targets with ground background                           
						{
							minRange = 50;
							maxRange = 5500;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 5500; // distance how far the target type gets recognized                                          
						angleRangeHorizontal = 180;     // sensor azimuth coverage in degrees         
						angleRangeVertical = 240;       // sensor elevation coverage in degrees       
						groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible           
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold         
						allowsMarking = 1;
					};
					class SomeLaserSensorComponent
					{
						componentType = "LaserSensorComponent";
						class AirTarget      // ranges for targets with sky background
						{
							minRange = 0;         //minimum possible range in meters  
							maxRange = 0;       //maximum possible range in meters                 
							objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
							viewDistanceLimitCoef = -1;      //range not limited by view distance           
						};
						class GroundTarget      // ranges for targets with ground background                           
						{
							minRange = 50;
							maxRange = 7000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 5500; // distance how far the target type gets recognized                                          
						angleRangeHorizontal = 180;     // sensor azimuth coverage in degrees         
						angleRangeVertical = 240;       // sensor elevation coverage in degrees       
						groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible           
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold       
						allowsMarking = 1;						
					};					
				};
			};
		};			
	};
	class FST_Stormfury_High_Velocity_Missile: OPTRE_M_ASGM2_AA
	{
		model="OPTRE_weapons\Aircraft\ASGM10_missile_fly.p3d";
		hit=150;
		missileLockCone=120;
		missileKeepLockedCone=120;
		indirectHit=125;
		indirectHitRange=13;
		airLock=2;
		irLock=1;
		trackLead=1;
		trackOversteer=1;
		maneuvrability=35;
		airFriction=0.050000001;
		sideAirFriction=0.16;
		thrust=400;
		weaponLockSystem="1+2+4+8+16";
		cmImmunity=0.85;
		missileLockMaxDistance=10000;
		missileLockMinDistance=50;
		effectsMissile="3AS_Rocket_effect_Purple_fly";
	};
	class MissileCore;
	class MissileBase : MissileCore
	{
		class Components;
	};
	class FST_AGM88 : MissileBase
	{
		model = "\FIR_AirWeaponSystem_US\data\AGM88\AGM88_fly";
		proxyShape = "\FIR_AirWeaponSystem_US\data\AGM88\AGM88";
		hit = 4000;
		indirectHit = 4000;
		indirectHitRange = 10;
		timetoLive = 60;
		maneuvrability = 100;
		initTime = 0.100000;
		thrustTime = 15;
		maxspeed = 800;
		maxControlRange = 15000;
		trackOversteer = 1;
		trackLead = 1;
		thrust = 800;
		effectsMissile = "FIR_MissileEffect2";
		soundHit[] = { "A3\Sounds_F\weapons\Rockets\explosion_missile_01", 3.1622777, 1, 1800 };
		sideAirFriction = 1;
		autoSeekTarget = 1;
		lockSeekRadius = 15000;		
		flightProfiles[] = { "Direct","LoalDistance"};		
		class Direct{};
		class LoalDistance : Direct
		{
			lockSeekDistanceFromParent = 1000;
		};		 
		missileLockCone = 360;
		missileKeepLockedCone = 360;
		missileLockMaxDistance = 15000;	
		missileLockMinDistance = 100;
		missileLockMaxSpeed = 800;	
		class Components : Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class SomeRadarSensorComponent
					{
						componentType = "PassiveRadarSensorComponent";
						class AirTarget      // ranges for targets with sky background
						{
							minRange = 1;         //minimum possible range in meters  
							maxRange = 15000;       //maximum possible range in meters                 
							objectDistanceLimitCoef = -1;    //range not limited by obj. view distance
							viewDistanceLimitCoef = -1;      //range not limited by view distance           
						};
						class GroundTarget      // ranges for targets with ground background                           
						{
							minRange = 1;
							maxRange = 15000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						typeRecognitionDistance = 5000; // distance how far the target type gets recognized                                          
						angleRangeHorizontal = 160;     // sensor azimuth coverage in degrees         
						angleRangeVertical = 240;       // sensor elevation coverage in degrees       
						groundNoiseDistanceCoef = -1;  // portion of sensor-target-ground distance below which the targets become invisible to the sensor
						maxGroundNoiseDistance = -1;   // distance from the ground in meters, hard cap, above which the target will be visible even if still below groundNoiseDistanceCoef
						minSpeedThreshold = -1;        // target speed in km/h above which the target will start to become visible           
						maxSpeedThreshold = -1;       // target speed above which the target becomes visible even if below groundNoiseDistanceCoef, linearly decreases to minSpeedThreshold         
					};
				};
			};
		};
	};
};
class CfgMagazines
{
	class 200Rnd_65x39_Belt;
	class VehicleMagazine;
	class FST_SmokeLauncherMag: VehicleMagazine
	{
		author="$STR_A3_Bohemia_Interactive";
		scope=2;
		ammo="FST_SmokeLauncherAmmo";
		count=6;
		nameSound="smokeshell";
		initSpeed=14;
	};
	class OPTRE_8Rnd_C2GMLS_missiles;
	class FST_Rapture_12Rnd_AGM_Missile: OPTRE_8Rnd_C2GMLS_missiles
	{
		displayName="[41st] Rapture ATGM";
		displayNameShort="ATGM";
		count=12;
		initSpeed=200;
		maxLeadSpeed=650;
		ammo="FST_Rapture_Anti_Tank_Missile";
		effectsMissile="3AS_Rocket_effect_Blue_fly";
	};
	class FST_Rapture_4Rnd_AGM_Missile: OPTRE_8Rnd_C2GMLS_missiles
	{
		displayName="[41st] Rapture ATGM";
		displayNameShort="ATGM";
		count=4;
		initSpeed=200;
		maxLeadSpeed=650;
		ammo="FST_Rapture_Anti_Tank_Missile";
		effectsMissile="3AS_Rocket_effect_Blue_fly";
	};
	class FST_Foehammer_4Rnd_AGM_Missile: VehicleMagazine
	{
		displayName="[41st] Rapture ATGM";
		displayNameShort="ATGM";
		count=4;
		initSpeed=200;
		maxLeadSpeed=650;
		ammo="FST_Foehammer_Anti_Tank_Missile";
		effectsMissile="3AS_Rocket_effect_Blue_fly";
	};
	class FST_Stormfury_12Rnd_AA_Missile: OPTRE_8Rnd_C2GMLS_missiles
	{
		displayName="[41st] Stormfury HVAA";
		displayNameShort="HVAA";
		count=12;
		initSpeed=300;
		maxLeadSpeed=1000;
		ammo="FST_Stormfury_High_Velocity_Missile";
		effectsMissile="3AS_PlasmaBolt_Large_Purple_Fly";
	};
	class FST_Stormfury_4Rnd_AA_Missile: OPTRE_8Rnd_C2GMLS_missiles
	{
		displayName="[41st] Stormfury HVAA";
		displayNameShort="HVAA";
		count=4;
		initSpeed=300;
		maxLeadSpeed=1000;
		ammo="FST_Stormfury_High_Velocity_Missile";
		effectsMissile="3AS_PlasmaBolt_Large_Purple_Fly";
	};
	class FST_Harrower_2Rnd_HARM_Missile: OPTRE_8Rnd_C2GMLS_missiles
	{
		displayName="[41st] Harrower ARM";
		displayNameShort="HARM";
		count=2;
		initSpeed=300;
		maxLeadSpeed=1000;
		ammo="FST_AGM88";
		effectsMissile="3AS_Rocket_effect_Blue_fly";
	};
};
class Cfgweapons
{
	class CannonCore;
	class autocannon_Base_F: CannonCore
	{
		class player;
	};
	class mortar_155mm_AMOS: CannonCore
	{
	};
	class cannon_120mm: CannonCore
	{
	};
	class MGun;
	class GMG_F: MGun
	{
	};
	class GMG_20mm: GMG_F
	{
	};
	class GMG_40mm: GMG_F
	{
		class manual;
	};
	class LMG_RCWS: MGun
	{
	};
	class LMG_M200: LMG_RCWS
	{
	};
	class weapon_AGM_65Launcher;
	class missiles_ASRAAM;
	class FST_SmokeLauncher: MGun
	{
		scope=2;
		displayName="$STR_A3_SmokeLauncher0";
		sounds[]=
		{
			"StandardSound"
		};
		class StandardSound
		{
			soundSetShot[]=
			{
				"UGL_shot_SoundSet",
				"UGL_Tail_SoundSet",
				"UGL_InteriorTail_SoundSet"
			};
		};
		magazines[]=
		{
			"FST_SmokeLauncherMag"
		};
		reloadTime=3;
		magazineReloadTime=60;
		canLock=0;
		autoFire=0;
		simulation="cmlauncher";
		showToPlayer=1;
		minRange=0;
		maxRange=10000;
		textureType="semi";
	};
	class 3AS_LAAT_autocannon_30mm: LMG_M200
	{
		class HE: autocannon_Base_F{};
	};
	class FST_ParticleBeamCannon_F: 3AS_LAAT_autocannon_30mm
	{
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="z_gunl_chamber";
				directionName="z_gunl_muzzle";
			};
			class Effect1
			{
				effectName="";
				positionName="z_gunR_chamber";
				directionName="z_gunR_muzzle";
			};
		};
		class HE: HE
		{
			displayName="[41st] Particle Beam Cannon";
			magazines[]=
			{
				"Laser_Battery"
			};
			magazineReloadTime=10;
			class player: player
			{
				reloadTime=0.079999998;
				dispersion=0.0018;
				magazineReloadTime=10;
				sounds[]=
				{
					"StandardSound"
				};
				class StandardSound
				{
					begin1[]=
					{
						"3AS\3AS_Laat\sounds\LAAT_Cannon.wav",
						1.99526,
						1,
						1500
					};
					soundBegin[]=
					{
						"begin1",
						0.33000001
					};
					soundsetshot[]=
					{
						"3AS_HeavyBlaster_soundset"
					};
				};
			};
		};
	};
	class FST_ParticleBeamCannon: LMG_RCWS
	{
		displayName="[41st] Particle Cannon";
		magazineReloadTime=10;
		ballisticsComputer=2;
		aiDispersionCoefY=0.5;
		aiDispersionCoefX=0.5;
		scope=1;
		class GunParticles
		{
		};
		class manual: MGun
		{
			displayName="[41st] Heavy Repeater";
			sounds[]=
			{
				"StandardSound"
			};
			class BaseSoundModeType
			{
				closure1[]=
				{
					"A3\sounds_f\weapons\gatling\gatling_rotation_short_2",
					0.316228,
					1,
					20
				};
				closure2[]=
				{
					"A3\sounds_f\weapons\gatling\gatling_rotation_short_3",
					0.316228,
					1,
					20
				};
				soundClosure[]=
				{
					"closure1",
					0.5,
					"closure2",
					0.5
				};
			};
			class StandardSound: BaseSoundModeType
			{
				begin1[]=
				{
					"3AS\3AS_Laat\sounds\LAAT_Cannon.wav",
					1.99526,
					1,
					1500
				};
				soundBegin[]=
				{
					"begin1",
					0.33000001
				};
				soundsetshot[]=
				{
					"3AS_LAAT_SoundSet"
				};
			};
			soundContinuous=1;
			soundBurst=0;
			multiplier=1;
			reloadTime=0.033333302;
			dispersion=0;
			aiRateOfFire=0.5;
			aiRateOfFireDistance=10;
			minRange=0;
			minRangeProbab=0.0099999998;
			midRange=1;
			midRangeProbab=0.0099999998;
			maxRange=2;
			maxRangeProbab=0.0099999998;
		};
		class close: manual
		{
			soundBurst=0;
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=12;
			burstRangeMax=42;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0;
			aiRateOfFireDistance=50;
			minRange=0;
			minRangeProbab=0.69999999;
			midRange=100;
			midRangeProbab=0.75;
			maxRange=300;
			maxRangeProbab=0.2;
		};
		class short: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=36;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0;
			aiRateOfFireDistance=150;
			minRange=100;
			minRangeProbab=0.75;
			midRange=300;
			midRangeProbab=0.75;
			maxRange=600;
			maxRangeProbab=0.2;
		};
		class medium: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=30;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0;
			aiRateOfFireDistance=300;
			minRange=300;
			minRangeProbab=0.75;
			midRange=600;
			midRangeProbab=0.64999998;
			maxRange=800;
			maxRangeProbab=0.1;
		};
		class far: close
		{
			aiBurstTerminable=1;
			showToPlayer=0;
			burst=8;
			burstRangeMax=12;
			aiRateOfFire=0.5;
			aiRateOfFireDispersion=0;
			aiRateOfFireDistance=800;
			minRange=800;
			minRangeProbab=0.64999998;
			midRange=1000;
			midRangeProbab=0.30000001;
			maxRange=1500;
			maxRangeProbab=0.050000001;
		};
		drySound[]=
		{
			"A3\Sounds_F\arsenal\weapons_vehicles\LMG_Minigun_65mm\LMGMinigun65mm_dry.wss",
			1,
			1,
			10
		};
		magazines[]=
		{
			"Laser_Battery_F"
		};
	};
	class FST_ParticleBeamCannon_B: FST_ParticleBeamCannon_F
	{
		class GunParticles
		{
			class Effect
			{
				effectName="";
				positionName="b_start";
				directionName="b_end";
			};
		};
	};
	class FST_ParticleBeamCannon_R: FST_ParticleBeamCannon{};
	
	class FST_Rapture_AGM_Missile: weapon_AGM_65Launcher
	{
		displayName="[41st] Rapture Anti-Tank Missile";
		magazines[]=
		{
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
		};
		maxRange=6000;
		minRange=50;
		canlock=2;
		airLock=1;
		weaponLockDelay=2;
		reloadTime = 0.001;
		magazineReloadTime=1;
	};
	class FST_Rapture_AGM_Missile_AI: weapon_AGM_65Launcher
	{
		displayName="[41st] Rapture Anti-Tank Missile (AI)";
		magazines[]=
		{
			"FST_Rapture_12Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
		};
		maxRange=6000;
		minRange=25;
		canlock=2;
		airLock=1;
		weaponLockDelay=2;
		reloadTime = 5;
		magazineReloadTime=5;
	};
	class FST_Foehammer_AGM_Missile: weapon_AGM_65Launcher
	{
		displayName="[41st] Foehammer Dual-Mode ATGM";
		magazines[]=
		{
			"FST_Foehammer_4Rnd_AGM_Missile",
		};
		sounds[] = { "StandardSound" };
		class StandardSound
		{
			begin1[] = { "A3\Sounds_F\weapons\Rockets\titan_1", 2.5118864, 1, 1100 };
			soundBegin[] = { "begin1", 1 };
			weaponSoundEffect = "DefaultRifle";
		};
		initspeed = 10;
		magazineReloadTime = 0.1;
		reloadTime = 0.500000;
		aiRateOfFire = 4.0;
		aiRateOfFireDistance = 500;
		minRange = 50;
		minRangeProbab = 0.04;
		midRange = 1000;
		midRangeProbab = 0.85;
		maxRange = 6000;
		maxRangeProbab = 0.55;
		maxLeadSpeed = 2500;
		FIR_AWS_SMS_A10C_CODE = "FIR_AirWeaponSystem_US\ui\sms\a10\wep_MAV.paa";		
	};
	class FST_Stormfury_AA_Missile: missiles_ASRAAM
	{
		displayName="[41st] Stormfury High Velocity Missile";
		magazines[]=
		{
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile"
			
		};
		maxRange=6000;
		minRange=25;
		canlock=2;
		airLock=1;
		aiAmmoUsageFlags="128 + 256";
		weaponLockDelay=2;
		reloadTime = 0.001;
		magazineReloadTime=1;
	};
	class FST_Stormfury_AA_Missile_AI: missiles_ASRAAM
	{
		displayName="[41st] Stormfury High Velocity Missile (AI)";
		magazines[]=
		{
			"FST_Stormfury_12Rnd_AA_Missile",
			"FST_Stormfury_4Rnd_AA_Missile"
			
		};
		maxRange=6000;
		minRange=25;
		canlock=2;
		airLock=1;
		aiAmmoUsageFlags="128 + 256";
		weaponLockDelay=2;
		reloadTime = 5;
		magazineReloadTime=5;
	};
	class MissileLauncher;
	class FST_Harrower_HARM_Missile : MissileLauncher
	{
		scope = 2;
		holdsterAnimValue = 1;
		displayName = "[41st] Harrower HARM Missile";
		displayNameMagazine = "HARM";
		shortNameMagazine = "HARM";

		modes[] = {"LoalDistance"};
		class LoalDistance: MissileLauncher
		{
			textureType = "LOAL";
			displayName = "PB";
			minRange = 300;
			minRangeProbab = 0.4;
			midRange = 1000;
			midRangeProbab = 0.95;
			maxRange = 20000;
			maxRangeProbab = 0.9;
		};			
		sounds[] = { "StandardSound" };
		class StandardSound
		{
			begin1[] = { "A3\Sounds_F\weapons\Rockets\titan_1", 2.5118864, 1, 1100 };
			soundBegin[] = { "begin1", 1 };
			weaponSoundEffect = "DefaultRifle";
		};
		initspeed = 10;
		magazineReloadTime = 0.5;
		reloadTime = 0.001;
		aiRateOfFire = 4.0;
		aiRateOfFireDistance = 200;
		maxLeadSpeed = 2500;
		magazines[] = { "FST_Harrower_2Rnd_HARM_Missile" };
	};
};