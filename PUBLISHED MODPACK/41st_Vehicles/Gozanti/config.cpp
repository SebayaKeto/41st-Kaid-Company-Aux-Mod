    class CfgPatches
    {
        class FST_Gozanti
        {
            requiredVersion=0.1;
            requiredAddons[]=
            {
                "A3_Armor_F_Beta",
                "3AS_Main",
                "3AS_Imperial_Air_Gozanti"
            };
            units[]=
            {
                "FST_Gozanti",
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

    class CfgVehicles {
        class Air;
        class Plane: Air {
            class ACE_Actions {
                class ACE_MainActions;
            };
            class ACE_SelfActions;
        };
        class Plane_Base_F: Plane {};
        class Plane_Fighter_03_base_F: Plane_Base_F {
            class HitPoints;
        };
        class 3AS_Gozanti_Base_F: Plane_Fighter_03_base_F {
            class Turrets {
                class MainTurret;
                class MainTurretRear;
                class MainTurretUnder;
            };
            class HitPoints: HitPoints {
                class HitHull;
            };
            class AnimationSources;
        };

        class FST_Gozanti: 3AS_Gozanti_Base_F {
            author = "Ruby";
            displayName = "[41st] Gozanti-Class Cruiser";
            scope = 2;
            scopeCurator = 2;
            side = 1;
            faction = "FST_Faction";
            editorSubcategory="FST_Air_Vehicle";
            vehicleClass = "";
            crew = "FST_Pilot_P1";
            typicalCargo[] = {"FST_Pilot_P1"};

            drivercanEject = 1;
            airbrake = 1;
            airbrakeForceCoef = 7.0;
            maxSpeed = 750;
            acceleration = 2600;
            maxOmega = 7500;

            weapons[] = 
            {
                "CMFlareLauncher",
                "Laserdesignator_pilotCamera",
                "FST_SmokeLauncher"
            };
            magazines[] = 
            {
                "FST_SmokeLauncherMag",
                "FST_SmokeLauncherMag",
                "FST_SmokeLauncherMag",
                "FST_SmokeLauncherMag",
                "FST_SmokeLauncherMag",
                "Laser_Battery",
                "Laserbatteries",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
            };
            class Turrets: Turrets {
                class MainTurret: MainTurret {
                    minElev = -10;
                    memoryPointGun[] = {"usti hlavne L", "usti hlavne R"};
                    gunBeg = "usti hlavne L";
                    gunEnd = "konec hlavne L";
                    weapons[] = {
                        "FST_ATTE_Turret"
                    };
                    magazines[] = {
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
                        "FST_thermal_coil_blue"
                    };
                    class OpticsIn {
                        class Wide {
                            directionStabilized = 1;
                            initAngleX = 0;
                            minAngleX = -30;
                            maxAngleX = 30;
                            initAngleY = 0;
                            minAngleY = -100;
                            maxAngleY = 100;
                            initFov = 25 / 120;
                            minFov = 25 / 120;
                            maxFov = 25 / 120;
                            gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                            opticsDisplayName = "WFOV";
                            visionMode[] = {"Normal", "NVG", "TI"};
                            thermalMode[] = {0, 1};
                        };
                        class Medium: Wide {
                            initFov = 10.5 / 120;
                            minFov = 10.5 / 120;
                            maxFov = 10.5 / 120;
                            gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                            opticsDisplayName = "MFOV";
                        };
                        class Narrow: Wide {
                            initFov = 2.5 / 120;
                            minFov = 2.5 / 120;
                            maxFov = 2.5 / 120;
                            gunnerOpticsModel="A3\Drones_F\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
                            opticsDisplayName = "NFOV";
                        };
                    };
                    class OpticsOut {
                        class Monocular {
                            initAngleX = 0;
                            minAngleX = -30;
                            maxAngleX = 30;
                            initAngleY = 0;
                            minAngleY = -100;
                            maxAngleY = 100;
                            minFov = 0.25;
                            maxFov = 1.25;
                            initFov = 0.75;
                            gunnerOpticsEffect[] = {};
                            gunnerOpticsModel = "";
                            visionMode[] = {"Normal", "NVG"};
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
            }
                class TransportCounterMeasuresComponent;
        };
                class MainTurretRear: MainTurretRear {
                    minElev = -12;
                    weapons[] = {
                        "FST_30mm_Autocannon_LAAT",
                        "FST_LAAT_Ball_Turret"
                    };
                    magazines[] = {
                        "FST_Thermal_Coil",
                        "FST_Thermal_Coil",
                        "FST_Thermal_Coil",
                        "FST_thermal_coil_Ball",
                        "FST_thermal_coil_Ball",
                        "FST_thermal_coil_Ball"
                    };
                };
            class MainTurretUnder: MainTurretUnder {
                minElev = -90;
                weapons[] = {
                        "FST_30mm_Autocannon_LAAT",
                        "FST_LAAT_Ball_Turret"
                    };
                    magazines[] = {
                        "FST_Thermal_Coil",
                        "FST_Thermal_Coil",
                        "FST_Thermal_Coil",
                        "FST_thermal_coil_Ball",
                        "FST_thermal_coil_Ball",
                        "FST_thermal_coil_Ball"
                    };
            };
            armor = 600
            armorStructural = 6;
        };
    };
};