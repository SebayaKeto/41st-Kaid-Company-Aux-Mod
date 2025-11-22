////////////////////////////////////////////////////////////////////
//DeRap: config.bin
//Produced from mikero's Dos Tools Dll version 9.45
//https://mikero.bytex.digital/Downloads
//'now' is Wed Apr 24 11:48:44 2024 : 'file' last modified on Wed Apr 17 19:43:44 2024
////////////////////////////////////////////////////////////////////
#include "functions.cpp"
#define _ARMA_

class CfgPatches
{
	class FST_MEC_Core
	{
		author = "Maldova";
		units[] = {};
		weapons[] = {};
		requiredAddons[] = {"A3_Data_F_Enoch_Loadorder","CBA_MAIN","FST_Core","FST_Common"};
		requiredversion = 0.1;
	};
};
class CfgEditorCategories
{
	// Main categories
	class FST_MEC_CategoryStructures
	{
		displayname = "[MEC] Structures";
	};
	class FST_MEC_CategoryPowerSystems
	{
		displayname = "[MEC] Power Systems";
	};
	class FST_MEC_CategoryEquipment
	{
		displayname = "[MEC] Equipment";
	};
	class FST_MEC_CategoryAegisBarriers
	{
		displayname = "[MEC] Aegis";
	};
	class FST_MEC_CategoryDefensiveSystems
	{
		displayname = "[MEC] Defensive Systems";
	};
	class FST_MEC_CategoryBunkers
	{
		displayname = "[MEC] Bunkers";
	};
	class FST_MEC_CategoryMisc
	{
		displayname = "[MEC] Miscellaneous";
	};
};
class CfgEditorSubcategories
{
	// Structures subcategories
	class FST_MEC_SubcategoryBarriers
	{
		displayName = "[MEC] Barriers";
	};
	class FST_MEC_SubcategoryPlatforms
	{
		displayName = "[MEC] Platforms";
	};
	// Power Systems subcategories
	class FST_MEC_SubcategoryBatteries
	{
		displayName = "[MEC] Batteries";
	};
	class FST_MEC_SubcategoryGenerators
	{
		displayName = "[MEC] Generators";
	};
	class FST_MEC_SubcategoryConduits
	{
		displayName = "[MEC] Power Conduits";
	};
	class FST_MEC_BreakerBoxes
	{
		displayName = "[MEC] Breaker Boxes";
	};
	// Aegis Barriers subcategories
	class FST_MEC_AegisBarriers_Duracrete
	{
		displayName = "[MEC] Duracrete Barriers";
	};
	class FST_MEC_AegisBarriers_Plasteel
	{
		displayName = "[MEC] Plasteel Barriers";
	};
	class FST_MEC_AegisBarriers_Titanium
	{
		displayName = "[MEC] Titanium Barriers";
	};
	class FST_MEC_AegisBarriers_Beskar
	{
		displayName = "[MEC] Beskar Barriers";
	};
	// Defensive Systems subcategories
	class FST_MEC_SubcategoryTurrets
	{
		displayName = "[MEC] Turrets";
	};
	class FST_MEC_SubcategoryMissileSystems
	{
		displayName = "[MEC] Missile Systems";
	};
	// Bunker subcategories
	class FST_MEC_SubcategoryBunkerModules
	{
		displayName = "[MEC] Bunker Modules";
	};
	class FST_MEC_SubcategoryBunkerEntrances
	{
		displayName = "[MEC] Bunker Entrances";
	};
	class FST_MEC_SubcategoryBunkerRoofs
	{
		displayName = "[MEC] Bunker Roofs";
	};
	class FST_MEC_SubcategoryBunkerWalls
	{
		displayName = "[MEC] Bunker Walls";
	};
	class FST_MEC_SubcategoryBunkerFloors
	{
		displayName = "[MEC] Bunker Floors";
	};
	class FST_MEC_SubcategoryBunkerStairs
	{
		displayName = "[MEC] Bunker Stairs";
	};
	class FST_MEC_SubcategoryBunkerDetails
	{
		displayName = "[MEC] Bunker Details";
	};
	class FST_MEC_SubcategoryBunkerDoors
	{
		displayName = "[MEC] Bunker Doors";
	};
	class FST_MEC_SubcategoryBunkerHatches
	{
		displayName = "[MEC] Bunker Hatches";
	};
	class FST_MEC_SubcategoryBunkerLadders
	{
		displayName = "[MEC] Bunker Ladders";
	};
	class FST_MEC_SubcategoryBunkerUtilities
	{
		displayName = "[MEC] Bunker Utilities";
	};
	class FST_MEC_SubcategoryBunkerFurniture
	{
		displayName = "[MEC] Bunker Furniture";
	};
	class FST_MEC_SubcategoryBunkerDecor
	{
		displayName = "[MEC] Bunker Decor";
	};
	class FST_MEC_SubcategoryBunkerStorage
	{
		displayName = "[MEC] Bunker Storage";
	};
	class FST_MEC_SubcategoryBunkerMisc
	{
		displayName = "[MEC] Bunker Miscellaneous";
	};
	class FST_MEC_SubcategoryBunkerRuin
	{
		displayName = "[MEC] Bunker Ruins";
	};
};
class CfgCloudlets
{
    class HouseDestrSmokeSmall;
    class ObjectDestructionSparks;
    class ObjectDestructionShrapnel;
    class ObjectDestructionFire1Small;

    // --- MATERIAL: DURACRETE (Types 1-3) ---
    // Characteristics: Heavy, grey dust that lingers. Non-flammable.
    class MEC_Cloudlet_Duracrete_Dust: HouseDestrSmokeSmall
    {
        interval = 0.05;
        lifeTime = 6.0; 
        color[] = {{0.55, 0.52, 0.48, 0.9}, {0.5, 0.5, 0.5, 0.5}, {0.6, 0.6, 0.6, 0}}; // Concrete/Earthen Grey
        size[] = {1.5, 3.5, 5.0};
        rubbing = 0.1; // Heavy particles, affected by wind but slow
    };
    class MEC_Cloudlet_Duracrete_Chunks: ObjectDestructionShrapnel
    {
        lifeTime = 3;
        weight = 200; // Very heavy
        volume = 0.5;
        rubbing = 0.05;
        size[] = {0.2, 0.1, 0.1}; // Visible chunks
    };

    // --- MATERIAL: PLASTEEL (Types 4-6) ---
    // Characteristics: Synthetic white/blue smoke (polymer burn), light debris.
    class MEC_Cloudlet_Plasteel_Smoke: HouseDestrSmokeSmall
    {
        lifeTime = 4.0;
        color[] = {{0.9, 0.9, 1.0, 0.8}, {0.95, 0.95, 1.0, 0.4}, {1, 1, 1, 0}}; // White with Blue tint
        size[] = {1.0, 2.5, 4.0}; // Tighter plumes
        rubbing = 0.05; // Light smoke
    };
    class MEC_Cloudlet_Plasteel_Shards: ObjectDestructionSparks
    {
        color[] = {{0.5, 0.8, 1, -10}}; // Blue static discharge sparks
        size[] = {0.3, 0.1, 0};
        emissiveColor[] = {{10, 30, 255, 1}}; // Glowing blue bits
    };

    // --- MATERIAL: TITANIUM (Types 7-11) ---
    // Characteristics: Oily black smoke, standard orange sparks.
    class MEC_Cloudlet_Titanium_Smoke: HouseDestrSmokeSmall
    {
        lifeTime = 8.0; // Long burning
        color[] = {{0.1, 0.1, 0.1, 0.95}, {0.15, 0.15, 0.15, 0.6}, {0.2, 0.2, 0.2, 0}}; // Thick Oil Black
        size[] = {2.0, 4.0, 7.0};
    };
    class MEC_Cloudlet_Titanium_Sparks: ObjectDestructionSparks
    {
        lifeTime = 0.8;
        size[] = {0.5, 0.2, 0};
        bounceOnSurface = 0.5; // Bounces off floor
    };

    // --- MATERIAL: BESKAR (Type 12) ---
    // Characteristics: No smoke (too pure), intense super-heated white sparks.
    class MEC_Cloudlet_Beskar_Flash: ObjectDestructionSparks
    {
        particleFSLoop = 0; // One shot
        lifeTime = 0.4;
        size[] = {2.0, 0.5, 0}; // Flash
        color[] = {{1, 1, 1, -500}}; // Blinding white heat
        emissiveColor[] = {{500, 500, 500, 1}};
    };
    class MEC_Cloudlet_Beskar_Sparks: ObjectDestructionSparks
    {
        lifeTime = 1.5; // Long lasting sparks
        size[] = {0.8, 0.4, 0};
        color[] = {{0.8, 0.9, 1, -100}}; // White-Blue hot metal
    };
};
class CfgSounds
{
    // --- DURACRETE ---
    class MEC_Sound_Duracrete_Crumble
    {
        name = "MEC_Duracrete_Crumble";
        // Vanilla 'DestrWall' @ 0.75 pitch (Deeper, heavier)
        sound[] = {"a3\sounds_f\sfx\special_sfx\house_destroy_1.wss", 3.16, 0.75, 200};
        titles[] = {};
    };

    // --- PLASTEEL ---
    class MEC_Sound_Plasteel_Snap
    {
        name = "MEC_Plasteel_Snap";
        // Vanilla 'DestrGlass' @ 0.6 pitch (Sounds like crunching hard plastic)
        sound[] = {"a3\sounds_f\arsenal\sfx\bullet_hits\glass_01.wss", 1.77, 0.6, 100};
        titles[] = {};
    };

    // --- TITANIUM ---
    class MEC_Sound_Titanium_Shear
    {
        name = "MEC_Titanium_Shear";
        // Vanilla 'DestrMetal' @ 0.6 pitch (Heavy tearing metal)
        sound[] = {"a3\sounds_f\arsenal\sfx\bullet_hits\metal_07.wss", 3.16, 0.6, 200};
        titles[] = {};
    };

    // --- BESKAR ---
    class MEC_Sound_Beskar_Ring
    {
        name = "MEC_Beskar_Ring";
        // Vanilla 'HitMetal' @ 0.5 pitch (Gong-like impact)
        sound[] = {"a3\sounds_f\arsenal\sfx\bullet_hits\metal_plate_01.wss", 4.0, 0.5, 100};
        titles[] = {};
    };
};