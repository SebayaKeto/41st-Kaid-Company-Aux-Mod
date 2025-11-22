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