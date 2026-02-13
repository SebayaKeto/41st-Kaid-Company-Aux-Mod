class CfgPatches
{
	class FST_Nu
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
            "FST_Nu_Shuttle",
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
	
class CfgVehicles{

	  class Air;
    class Helicopter: Air {
        class ACE_Actions;
    };
    class Helicopter_Base_F: Helicopter {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
    };
    class Helicopter_Base_H: Helicopter_Base_F {};
    class 3AS_laat_Base: Helicopter_Base_H {
        class Turrets;
    };
    class 3AS_nuclass_base: 3AS_laat_Base {
        class Turrets: Turrets {
            class Copilot;
            class Copilot2;
        };
        class HitPoints {
            class HitHull;
            class HitFuel;
            class HitEngine;
            class HitAvionics;
        };
        class ACE_SelfActions;
        class UserActions {
            class impulseOn;
        };
	};

	class FST_Nu_Shuttle: 3AS_nuclass_base
	{
		author = "Ruby and Gold!"
		displayname = "[41st] Nu-Class Shuttle";
		scope = 2;
		side = 1;
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		vehicleclass="Helicopter";
		crew="FST_Pilot_P1";
		hiddenSelections[]=
		{
			"camo1",
			"camo2",
			"camo3",
			"camo4"
		};
		editorPreview="3as\3AS_nu\images\3AS_nuclass.jpg";
		hiddenSelectionsTextures[]=
		{
			"41st_Vehicles\Nu\data\FST_Nu_exterior.paa",
			"41st_Vehicles\Nu\data\FST_Nu_Wings.paa",
			"41st_Vehicles\Nu\data\FST_Nu_Interior.paa",
			"41st_Vehicles\Nu\data\FST_Nu_Doors.paa",
		};
		tas_can_impulse=0;
		weapons[]=
		{
			"FST_30mm_Autocannon_LAAT",
			"FST_Rapture_AGM_Missile",
			"FST_Foehammer_AGM_Missile",
			"FST_Stormfury_AA_Missile",
			"FST_Harrower_HARM_Missile",
			"Laserdesignator_pilotCamera",
			"CMFlareLauncher",
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
			"FST_Stormfury_4Rnd_AA_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Rapture_4Rnd_AGM_Missile",
			"FST_Harrower_2Rnd_HARM_Missile",
			"FST_Foehammer_4Rnd_AGM_Missile",
		};
		class Turrets: Turrets
		{
			class Copilot: Copilot
			{
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT"
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil"
				};
			};
			class Copilot2: Copilot2
			{
				weapons[]=
				{
					"FST_30mm_Autocannon_LAAT"
				};
				magazines[]=
				{
					"FST_Thermal_Coil",
					"FST_Thermal_Coil",
					"FST_Thermal_Coil"
				};
			};
		};
		class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor=550;
				convexComponent="hull_hit";
				depends="Total";
				explosionShielding=1;
				material=51;
				name="hull_hit";
				passThrough=1;
				visual="zbytek";
				radius=0.0099999998;
			};
			class HitFuel: HitFuel
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
				armor=0.60000002;
			};
			class HitEngine: HitEngine
			{
				armor=3.5;
				convexComponent="engine_hit";
				explosionShielding=2;
				material=51;
				name="engine_hit";
				hitpoint="engine_hit";
				passThrough=1;
				visual="";
				radius=0.2;
			};
			class HitAvionics: HitAvionics
			{
				armor=1.5;
				convexComponent="avionics_hit";
				explosionShielding=2;
				material=51;
				name="avionics_hit";
				passThrough=1;
				visual="";
				radius=0.5;
			};
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
		class ls_impulsor: ls_impulsor_base
		{
			enabled=1;
			speed=300;
			fueldrain=9.9999997e-005;
			overchargespeed=600;
			overchargeFuelDrain=9.9999997e-005;
			overchargeCooldown=0
		};
	};
};