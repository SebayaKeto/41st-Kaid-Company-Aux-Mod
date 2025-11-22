////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.45
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 24 11:48:44 2024 : 'file' last modified on Wed Apr 17 19:43:44 2024
////////////////////////////////////////////////////////////////////
#include "\FST\FST_CCN\ccn_base_defines.hpp"
#define _ARMA_

class CfgPatches
{
	class FST_CCN_Core
	{
		author = CCN_AUTHOR;
		units[] = {};
		weapons[] = {};
		requiredAddons[] = 
        {
            "A3_Data_F_Enoch_Loadorder",
            "A3_Data_F_ParticleEffects",
            "A3_Sounds_F",
            "CBA_MAIN",
            "FST_Core",
            "FST_Common"
        };
		requiredversion = 0.1;
	};
};
class CfgEditorCategories
{
	// Main categories adapted for CCN Architecture
	class FST_CCN_CategoryStructures
	{
		displayname = "[CCN] Hive Structures";
	};
	class FST_CCN_CategoryPowerSystems
	{
		displayname = "[CCN] Hive Power & Shields";
	};
	class FST_CCN_CategoryLogistics
	{
		displayname = "[CCN] Logistics Pods";
	};
	class FST_CCN_CategoryHiveBarriers
	{
		displayname = "[CCN] Hive Barriers";
	};
	class FST_CCN_CategoryDefensiveSystems
	{
		displayname = "[CCN] Automated Defense";
	};
	class FST_CCN_CategoryBunkers
	{
		displayname = "[CCN] Hive Bunkers";
	};
	class FST_CCN_CategoryMisc
	{
		displayname = "[CCN] Miscellaneous";
	};
};

class CfgEditorSubcategories
{
	// --- BARRIER SUBCATEGORIES (By Material) ---
	class FST_CCN_Subcategory_Bronzium
	{
		displayName = "[CCN] Bronzium (Drone Tier)";
	};
	class FST_CCN_Subcategory_Chitin
	{
		displayName = "[CCN] Heavy Chitin (Warrior Tier)";
	};
	class FST_CCN_Subcategory_Phrik
	{
		displayName = "[CCN] Phrik-Lattice (Queen Tier)";
	};
    class FST_CCN_Subcategory_Shielded
    {
        displayName = "[CCN] Shielded Composites";
    };

	// --- LOGISTICS SUBCATEGORIES ---
	class FST_CCN_Subcategory_Pods_Resource
	{
		displayName = "[CCN] Resource Pods (Larva)";
	};
	class FST_CCN_Subcategory_Pods_Droid
	{
		displayName = "[CCN] Deployment Pods (Pupa)";
	};
	class FST_CCN_Subcategory_Pods_Support
	{
		displayName = "[CCN] Support Pods (Adult)";
	};
	class FST_CCN_Subcategory_Pods_Misc
	{
		displayName = "[CCN] Miscellaneous Pods";
	};

	// --- POWER SUBCATEGORIES ---
	class FST_CCN_Subcategory_Generators
	{
		displayName = "[CCN] Geo-Thermal Spires";
	};
	class FST_CCN_Subcategory_Shields
	{
		displayName = "[CCN] Shield Emitters";
	};
};
class CfgCloudlets
{
    class HouseDestrSmokeSmall;
    class ObjectDestructionSparks;
    class ObjectDestructionShrapnel;

    // --- MATERIAL: BRONZIUM (Types 1-2) ---
    // Characteristics: Metallic dust, Gold/Brown hue, sharp shards.
    class CCN_Cloudlet_Bronzium_Dust: HouseDestrSmokeSmall
    {
        interval = 0.05;
        lifeTime = 4.0; 
        // Bronze/Brownish metallic dust (Reddish-Gold)
        color[] = {{0.6, 0.4, 0.2, 0.8}, {0.55, 0.35, 0.15, 0.5}, {0.5, 0.3, 0.1, 0}}; 
        size[] = {1.0, 2.5, 4.0};
    };
    class CCN_Cloudlet_Bronzium_Shards: ObjectDestructionSparks
    {
        lifeTime = 1.5;
        size[] = {0.5, 0.3, 0.1};
        // Orange/Gold sparks typical of Bronzium
        color[] = {{1, 0.6, 0.1, -50}}; 
        emissiveColor[] = {{200, 100, 10, 1}};
    };

    // --- MATERIAL: HEAVY CHITIN (Type 3) ---
    // Characteristics: Organic/Industrial feel. Sickly Green/Grey smoke.
    class CCN_Cloudlet_Chitin_Smoke: HouseDestrSmokeSmall
    {
        lifeTime = 5.0;
        // Green/Grey smoke (Industrial coolant/organic decay)
        color[] = {{0.3, 0.4, 0.3, 0.9}, {0.35, 0.45, 0.35, 0.5}, {0.4, 0.5, 0.4, 0}}; 
        rubbing = 0.1;
    };
    class CCN_Cloudlet_Chitin_Debris: ObjectDestructionShrapnel
    {
        lifeTime = 2.0;
        weight = 150; 
        // Dark Green chunks
        color[] = {{0.1, 0.2, 0.1, 1}};
    };

    // --- MATERIAL: PHRIK-LATTICE (Type 4) ---
    // Characteristics: Electrical discharge, Purple/Red sparks (Shield failure).
    class CCN_Cloudlet_Phrik_Discharge: ObjectDestructionSparks
    {
        particleFSLoop = 0; // Burst
        lifeTime = 0.3;
        size[] = {2.5, 0.1, 0};
        // Purple/Red electrical discharge
        color[] = {{0.8, 0.1, 0.8, -50}}; 
        emissiveColor[] = {{100, 10, 100, 1}};
    };

	// --- MATERIAL: SHIELDED COMPOSITE (Type 5) ---
	// Characteristics: Dull grey smoke with metallic fragments.
	class CCN_Cloudlet_Shielded_Smoke: HouseDestrSmokeSmall
	{
		lifeTime = 4.5;
		// Dull Grey smoke
		color[] = {{0.4, 0.4, 0.4, 0.9}, {0.45, 0.45, 0.45, 0.5}, {0.5, 0.5, 0.5, 0}}; 
		size[] = {1.2, 3.0, 4.5};
		rubbing = 0.08;
	};
};
class CfgSounds
{
    // --- BRONZIUM (Sharp Metallic Snap) ---
    class CCN_Sound_Bronzium_Snap
    {
        name = "CCN_Bronzium_Snap";
        // Pitch 1.2 makes 'metal_destr' sound lighter/sharper/brittle
        sound[] = {"A3\sounds_f\structures\destr\metal_destr_02.wss", 3.0, 1.2, 150}; 
        titles[] = {};
    };

    // --- CHITIN (Hollow/Organic Thud) ---
    class CCN_Sound_Chitin_Collapse
    {
        name = "CCN_Chitin_Collapse";
        // Pitch 0.8 on 'glass_destr' creates a hollow, crunchy sound
        sound[] = {"A3\sounds_f\structures\destr\glass_destr_01.wss", 2.5, 0.8, 100}; 
        titles[] = {};
    };

    // --- PHRIK (Electrical Failure) ---
    class CCN_Sound_Phrik_Failure
    {
        name = "CCN_Phrik_Failure";
        // High pitched spark sound
        sound[] = {"A3\sounds_f\sfx\special_sfx\sparkles_01.wss", 3.0, 0.5, 200}; 
        titles[] = {};
    };

	// --- SHIELDED COMPOSITE (Dull Thud with Metallic Ring) ---
	class CCN_Sound_Shielded_Impact
	{
		name = "CCN_Shielded_Impact";
		// Combination of 'HitMetal' and 'HitWood' sounds blended
		sound[] = {"A3\sounds_f\structures\destr\hit_metal_01.wss", 2.0, 0.7, 150,  "A3\sounds_f\structures\destr\hit_wood_01.wss", 1.5, 0.9, 100}; 

		titles[] = {};
	};
};
class CfgVehicles 
{
    class House;
	class House_F: House
	{
		class DestructionEffects;
	};

    // --- ROOT CCN BASE ---
	class CCN_Barrier_Base : House_F 
	{ 
		scope = 0; 
		displayName = "CCN Hive Barrier"; 
		author = CCN_FULL_NAME; 
		destructType = "DestructBuilding"; 
		editorCategory = "FST_CCN_CategoryHiveBarriers"; 
		model = ""; 
	};

    // TEMPLATE: BRONZIUM (Standard CIS)
    class CCN_Template_Bronzium: CCN_Barrier_Base
    {
        class DestructionEffects : DestructionEffects 
		{
            class Sound { simulation = "sound"; type = "CCN_Sound_Bronzium_Snap"; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
            class Dust { simulation = "particles"; type = "CCN_Cloudlet_Bronzium_Dust"; position = ""; intensity = 1; interval = 1; lifeTime = 0.05; };
            class Sparks { simulation = "particles"; type = "CCN_Cloudlet_Bronzium_Shards"; position = ""; intensity = 1; interval = 1; lifeTime = 0.05; };
			class ruins { simulation = "ruin"; type = ""; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
		};
    };

    // TEMPLATE: HEAVY CHITIN (Organic/Hive)
    class CCN_Template_Chitin: CCN_Barrier_Base
    {
        class DestructionEffects : DestructionEffects 
		{
            class Sound { simulation = "sound"; type = "CCN_Sound_Chitin_Collapse"; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
            class Smoke { simulation = "particles"; type = "CCN_Cloudlet_Chitin_Smoke"; position = ""; intensity = 1; interval = 1; lifeTime = 0.05; };
            class Debris { simulation = "particles"; type = "CCN_Cloudlet_Chitin_Debris"; position = ""; intensity = 1; interval = 1; lifeTime = 0.05; };
			class ruins { simulation = "ruin"; type = ""; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
		};
    };

    // TEMPLATE: PHRIK-LATTICE (High-Tier)
    class CCN_Template_Phrik: CCN_Barrier_Base
    {
        class DestructionEffects : DestructionEffects 
		{
            class Sound { simulation = "sound"; type = "CCN_Sound_Phrik_Failure"; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
            class Flash { simulation = "particles"; type = "CCN_Cloudlet_Phrik_Discharge"; position = ""; intensity = 1; interval = 1; lifeTime = 0.05; };
			class ruins { simulation = "ruin"; type = ""; position = ""; intensity = 1; interval = 1; lifeTime = 1; };
		};
    };
	// ============================================
	// --- CCN AUTONOMOUS DRONE BASE ---
	// ============================================
	class UGV_01_base_F;
	class CCN_Drone_Base: UGV_01_base_F
	{
		scope = 0;
		displayName = "CCN Autonomous Unit";
		author = CCN_FULL_NAME;
		side = 0; 
		faction = "FST_CCN_FACTION";
		crew = "O_UAV_AI";
		
		isUav = 1;
		enableGPS = 1;
		radarType = 8;
		reportOwnPosition = 1;
		
		// AI Skill Coefficients (Representing the Hive Mind precision)
		precision = 0.8;  // High aiming precision
		aimingShake = 0.1; // Very steady
		aimingSpeed = 1.5; // Fast target acquisition
		spotable = 0.8;   // Standard visibility profile
		
		// --- SENSOR COMPONENTS ---
		// Defines what the drone can "see"
		class Components 
		{
			class SensorsManagerComponent 
			{
				class Components 
				{
					class LaserSensorComponent 
					{
						class AirTarget 
						{
							minRange = 500; 
							maxRange = 3000; 
							objectDistanceLimitCoef = -1; 
							viewDistanceLimitCoef = -1; 
						};
						class GroundTarget 
						{
							minRange = 500; 
							maxRange = 3000; 
							objectDistanceLimitCoef = -1; 
							viewDistanceLimitCoef = -1; 
						};
						maxTrackableSpeed = 50; 
						angleRangeHorizontal = 180; 
						angleRangeVertical = 180; 
						animDirection = "mainGun"; 
						componentType = "LaserSensorComponent";
						typeRecognitionDistance = 2000; // Distance to ID target types
					};
					class ActiveRadarSensorComponent 
					{
						class AirTarget 
						{
							minRange = 500; 
							maxRange = 5000; 
							objectDistanceLimitCoef = -1; 
							viewDistanceLimitCoef = -1; 
						};
						class GroundTarget 
						{
							minRange = 500; 
							maxRange = 4000; 
							objectDistanceLimitCoef = -1; 
							viewDistanceLimitCoef = -1; 
						};
						maxTrackableSpeed = 100; 
						angleRangeHorizontal = 360; // 360-degree awareness
						angleRangeVertical = 100; 
						groundNoiseDistanceCoef = 0.2; 
						maxGroundNoiseDistance = 200; 
						minSpeedThreshold = 0; 
						animDirection = "mainGun"; 
						componentType = "ActiveRadarSensorComponent";
						typeRecognitionDistance = 4000; 
					};
				};
			};
		};

		// --- DURABILITY & PROTECTION ---
		armor = 100;
		armorStructural = 2; // Multiplier for structural integrity
		damageResistance = 0.004; // Resistance to small arms fire
		crewVulnerable = 0; // AI "brain" cannot be sniped out easily
		crewExplosionProtection = 0.99; // Highly resistant to shockwaves
		
		// --- VISUALS & INTERFACE ---
		icon = "\A3\ui_f\data\map\VehicleIcons\iconDrone_ca.paa"; // Map icon
		picture = "\A3\Drones_F\Soft_F_Gamma\UGV_01\Data\UI\UGV_01_CA.paa"; // Inventory picture
		mapSize = 1.5; // Size on map in meters
		hiddenSelections[] = {"Camo", "Camo1"};
		
		// --- LOGISTICS ---
		transportSoldier = 0; // Cannot carry passengers
		typicalCargo[] = {};
		enableManualFire = 0; // Depends on if it has weapons (Base has none)
		
		// --- AUDIO (Default Electric Drone Hum) ---
		soundEngineOnInt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_int_start", 0.5, 1.0};
		soundEngineOnExt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_start", 0.7, 1.0, 200};
		soundEngineOffInt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_int_stop", 0.5, 1.0};
		soundEngineOffExt[] = {"A3\Sounds_F\vehicles\soft\UGV_01\UGV_01_ext_stop", 0.7, 1.0, 200};
		
		// --- DAMAGE & DESTRUCTION ---
		class EventHandlers 
		{
			killed = "params ['_unit']; playSound3D ['A3\Sounds_F\sfx\special_sfx\sparkles_03.wss', _unit, false, getPosASL _unit, 5, 1, 100];";
			init = "(_this select 0) spawn { \
            params ['_drone']; \
            while {alive _drone} do { \
                sleep 5; \
                /* Check for enemies (WEST/GUER) within 50m */ \
                private _enemies = _drone nearEntities [['Man', 'LandVehicle'], 50]; \
                _enemies = _enemies select {side _x != side _drone && side _x != CIVILIAN}; \
                \
                if (count _enemies > 0) then { \
                    /* Target Found */ \
                    private _target = _enemies select 0; \
                    _drone doMove (getPos _target); \
                    \
                    /* If close enough (5m), explode */ \
                    if (_drone distance _target < 5) then { \
                        playSound3D ['A3\Sounds_F\sfx\beeps\floppy_drive.wss', _drone, false, getPosASL _drone, 5, 2, 50]; \
                        sleep 1; \
                        private _bomb = createVehicle ['HelicopterExploSmall', getPosATL _drone, [], 0, 'CAN_COLLIDE']; \
                        _drone setDamage 1; \
                    }; \
                }; \
            }; \
        };";
    	};
		// --- ANIMATIONS & USER INTERACTIONS ---
		class UserActions
		{
			class CCN_Self_Destruct
			{
				displayName = "<t color='#ff0000'>INITIATE SELF-DESTRUCT</t>"; // Red text
				priority = 0;
				radius = 2;
				position = "";
				showWindow = 0;
				onlyForPlayer = 0; // AI or scripted usage
				condition = "alive this"; // Can only explode if not already dead
				
				// --- SELF DESTRUCT SCRIPT ---
				// 1. Plays alarm (Beep)
				// 2. Waits 3 seconds
				// 3. Spawns explosion (Helicopter explosion size)
				// 4. Sets damage to 1 (Kill)
				statement = "this spawn { \
					params ['_drone']; \
					playSound3D ['A3\Sounds_F\sfx\beeps\floppy_drive.wss', _drone, false, getPosASL _drone, 5, 2, 50]; \
					sleep 1; \
					playSound3D ['A3\Sounds_F\sfx\beeps\floppy_drive.wss', _drone, false, getPosASL _drone, 5, 2, 50]; \
					sleep 1; \
					playSound3D ['A3\Sounds_F\sfx\beeps\floppy_drive.wss', _drone, false, getPosASL _drone, 5, 2, 50]; \
					sleep 1; \
					private _bomb = createVehicle ['HelicopterExploSmall', getPosATL _drone, [], 0, 'CAN_COLLIDE']; \
					_drone setDamage 1; \
				};";
			};
		};
	};
}; 
