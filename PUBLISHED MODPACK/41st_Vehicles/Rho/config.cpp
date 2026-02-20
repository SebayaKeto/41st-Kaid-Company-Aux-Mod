
class CfgPatches
{
	class FST_Rho
    {
		requiredAddons[]=
		{
			"A3_Armor_F_Beta",
			"3AS_Republic_Heli_Rho"
		};
		units[]=
        {
            "FST_Rho_Shuttle",
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
	class Components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class Components;
};
class VehicleSystemsTemplateLeftPilot: DefaultVehicleSystemsDisplayManagerLeft
{
	class Components;
};
class VehicleSystemsTemplateRightPilot: DefaultVehicleSystemsDisplayManagerRight
{
	class Components;
};
class ls_impulsor_base;

class CfgVehicles
{
    class Air;
	class Helicopter: Air
	{
        class ACE_Actions;
	};
	class Helicopter_Base_F: Helicopter {
        class ACE_Actions: ACE_Actions {
            class ACE_MainActions;
        };
	};
	class Helicopter_Base_H: Helicopter_Base_F
	{
		class Turrets;
	};
	class 3AS_Rho_Base_F: Helicopter_Base_H
	{
        class ACE_SelfActions;
        class Turrets: Turrets
		{
			class CopilotTurret;
            class CopilotTurret2;
		};
    };
	class FST_Rho_Shuttle: 3AS_Rho_Base_F
	{
		author = "Ruby";
		scope = 2;
		displayname = "[41st] Rho-Class Shuttle";
		side = 1;
		faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
		crew="FST_Pilot_P1";
		tas_canLift=1;
		tas_can_impulse=0;
		hiddenSelections[]=
		{
			"camo",
			"camo1",
			"camo2",
			"camo3",
			"camo4",
			"camo5",
			"camo6"
		};
		hiddenSelectionsTextures[]=
		{
			"\41st_Vehicles\Rho\Data\FST_Rho_Hull.paa",
			"\3as\3as_republic_heli\nu_class\data\hull_front_co.paa",
			"\41st_Vehicles\Rho\data\FST_Rho_Wings.paa",
			"3as\3as_republic_heli\rho_class\data\cockpit_co.paa",
			"\41st_Vehicles\Rho\data\FST_Rho_Cockpit_Interface.paa",
			"\41st_Vehicles\Rho\data\FST_Rho_Interior.paa",
			"3as\3as_republic_heli\rho_class\data\interior_optional_co.paa"
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
        class TextureSources
        {
            class FST_Rho
            {
                displayName = "[41st] Rho";
                author = "Ruby";
                textures[]=
                {
                    "\41st_Vehicles\Rho\Data\FST_Rho_Hull.paa",
                    "\3as\3as_republic_heli\nu_class\data\hull_front_co.paa",
                    "\41st_Vehicles\Rho\data\FST_Rho_Wings.paa",
                    "3as\3as_republic_heli\rho_class\data\cockpit_co.paa",
                    "\41st_Vehicles\Rho\data\FST_Rho_Cockpit_Interface.paa",
                    "\41st_Vehicles\Rho\data\FST_Rho_Interior.paa",
                    "3as\3as_republic_heli\rho_class\data\interior_optional_co.paa"
                };
            };
        };
		class Turrets: Turrets
        {
            class CopilotTurret: CopilotTurret
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
            class CopilotTurret2: CopilotTurret2
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
			overchargeCooldown=0;
		};
	};
};