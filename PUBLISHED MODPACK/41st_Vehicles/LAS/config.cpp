class CfgPatches
{
	class FST_LAS
	{
		units[]=
		{
			"FST_CIS_LAS_Passenger",
            "FST_CIS_LAS_Gunship"
		};
		weapons[]={};
		requiredVersion=0.1;
		requiredAddons[]=
		{
			"A3_Armor_F_Beta"
		};
	};
};
class SensorTemplatePassiveRadar;
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
class CfgVehicles
{
        class Helicopter;
        class Helicopter_Base_F: Helicopter
        {
            class Turrets;
            class HitPoints;
        };
        class Helicopter_Base_H: Helicopter_Base_F
        {
            class RotorLibHelicopterProperties;
            class ViewPilot;
            class ViewOptics;
            class EventHandlers;
            class Turrets: Turrets
            {
                class CopilotTurret;
                class MainTurret;
            };
            class AnimationSources;
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
            };
            class Components;
        };
        class 3AS_LAS_Base_F: Helicopter_Base_H {};
        class 3AS_Rep_LAS_Z6_F: 3AS_LAS_Base_F {};
        class FST_CIS_LAS_Passenger: 3AS_LAS_Base_F
        {
            author = "Ruby";
            scope = 2;
            model="\3AS\3AS_Republic_Heli\LAS\model\3AS_LAS.p3d";
            side = 1;
            faction="FST_Faction";
            editorSubcategory="FST_Air_Vehicle";
            crew="FST_Pilot_P1";
            displayname = "[41st] LAS (Passenger)";
            hiddenSelections[]=
            {
                "camo0",
                "camo1",
                "camo2"
            };
            hiddenSelectionsTextures[]=
            {
                "41st_Vehicles\LAS\Data\FST_LAS_Exterior_Kaid_CO.paa",
                "\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
                "41st_Vehicles\LAS\Data\FST_LAS_Wings_Kaid_CO.paa"
            };
            weapons[]=
            {
                "FST_30mm_Autocannon_LAAT",
                "FST_Stormfury_AA_Missile",
                "CMFlareLauncher"
            };
            magazines[]=
            {
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "FST_Stormfury_12Rnd_AA_Missile",
                "FST_Thermal_Coil",
                "FST_Thermal_Coil",
                "FST_Thermal_Coil",
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
        };
    class FST_CIS_LAS_Gunship: 3AS_Rep_LAS_Z6_F
    {
        author = "Ruby";
        scope = 2;
        side = 1;
        faction="FST_Faction";
		editorSubcategory="FST_Air_Vehicle";
        model="\3AS\3AS_Republic_Heli\LAS\model\3AS_LAS_z6.p3d";
        crew="FST_Pilot_P1";
        displayname = "[41st] LAS (Gunship)";
        hiddenSelections[]=
        {
            "camo0",
            "camo1",
            "camo2"
        };
        hiddenSelectionsTextures[]=
        {
            "41st_Vehicles\LAS\Data\FST_LAS_Exterior_Kaid_CO.paa",
            "\3AS\3AS_Republic_Heli\LAS\data\3AS_LAS_Interior_co.paa",
            "41st_Vehicles\LAS\Data\FST_LAS_Wings_Kaid_CO.paa"
        };
        weapons[]=
            {
                "FST_30mm_Autocannon_LAAT",
                "FST_Stormfury_AA_Missile",
                "FST_Rapture_AGM_Missile",
                "CMFlareLauncher"
            };
            magazines[]=
            {
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "240Rnd_CMFlare_Chaff_Magazine",
                "FST_Stormfury_4Rnd_AA_Missile",
                "FST_Stormfury_4Rnd_AA_Missile",
                "FST_Rapture_4Rnd_AGM_Missile",
                "FST_Thermal_Coil",
                "FST_Thermal_Coil",
                "FST_Thermal_Coil",
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
                    position="light_l_pos";
                    direction="light_l_dir";
                    hitpoint="Light_L";
                    selection="Light_L";
                    useFlare=1;
                    flareSize=15;
                    flareMaxDistance=5000;
                    dayLight=0;
                    class Attenuation
                    {
                        start=0;
                        constant=0;
                        linear=1;
                        quadratic=0.25;
                        hardLimitStart=300;
                        hardLimitEnd=400;
                    };
                };
                class Right: Left
                {
                    position="light_r_pos";
                    direction="light_r_dir";
                    hitpoint="Light_R";
                    selection="Light_R";
                };
            };
        class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				weapons[]=
                {
                    "3AS_LAS_Z6_HE_2_W",
                };
                magazines[]=
                {
                    "3AS_LAS_1000Rnd_Z6_HE_Mag",
                    "3AS_LAS_1000Rnd_Z6_HE_Mag"
                };
                gunnerType = "FST_Pilot_P1";
			};
			class MainTurret1: MainTurret
			{
                gunnerName="Right Gunner";
				primaryGunner=0;
				proxyIndex=2;
				initTurn=-90;
				minTurn="-90 - 55";
				maxTurn="-90 + 55";
                gunBeg="maingun1_start";
				gunEnd="maingun1_end";
				memoryPointGunnerOptics="gunnerOptics1";
				selectionFireAnim="zaslehMain1";
                body="mainturret1";
				gun="maingun1";
				animationSourceBody="mainturret1";
				animationSourceGun="maingun1";
				gunnerAction="LAS_Gunner";
				gunnerInAction="LAS_Gunner";
				gunnerLeftHandAnimName="gunner1_left_hand";
				gunnerRightHandAnimName="gunner1_right_hand";
				gunnerLeftLegAnimName="gunner_1_legs";
				gunnerRightLegAnimName="gunner_1_legs";
				memoryPointsGetInGunner="pos_cargo";
				memoryPointsGetInGunnerDir="pos_cargo_dir";
				commanding=-2;
                backRotorForceCoef=2.5;
                bodyFrictionCoef=0.5;
                cyclicAsideForceCoef=2.5;
                cyclicForwardForceCoef=2;
                LiftForceCoef=5;
                limitedSpeedCoef=0.22;
                maxSpeed=300;
                startDuration=5;
                backRotorSpeed=0;
                mainBladeCenter="rotor_center";
                mainBladeRadius=0;
                mainRotorSpeed=0;
                tailBladeCenter="rotor_02_center";
                tailBladeRadius=0;
                tailBladeVertical=0;
                numberPhysicalWheels=0;
                maxBackRotorDive=0;
                maxMainRotorDive=0;
                minBackRotorDive=0;
                minMainRotorDive=0;
                neutralBackRotorDive=0;
                neutralMainRotorDive=0;
                fuelCapacity=1360;
                fuelConsumptionRate=0.126;
                maxFordingDepth=10.65;
                washDownDiameter="40.0f";
                washDownStrength="1.0f";
                waterLeakiness=0.0099999998;
                slingLoadMaxCargoMass=40000;
				weapons[]=
                {
                    "3AS_LAS_Z6_HE_2_W",
                };
                magazines[]=
                {
                    "3AS_LAS_1000Rnd_Z6_HE_Mag",
                    "3AS_LAS_1000Rnd_Z6_HE_Mag"
                };
                gunnerType = "FST_Pilot_P1";
			};
		};
    };
};