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
};
class CfgEditorSubcategories
{
	class FST_MEC_SubcategoryBarriers
	{
		displayName = "[MEC] Barriers";
	};
	class FST_MEC_SubcategoryPlatforms
	{
		displayName = "[MEC] Platforms";
	};
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
	class FST_MEC_AegisBarriers_Duracrete
	{
		displayName = "[MEC] Duracrete Barriers";
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
        sound[] = {"@A3\sounds_f\structures\destr\wall_destr_01.wss", 3.16, 0.75, 200};
        titles[] = {};
    };

    // --- PLASTEEL ---
    class MEC_Sound_Plasteel_Snap
    {
        name = "MEC_Plasteel_Snap";
        // Vanilla 'DestrGlass' @ 0.6 pitch (Sounds like crunching hard plastic)
        sound[] = {"@A3\sounds_f\structures\destr\glass_destr_02.wss", 1.77, 0.6, 100};
        titles[] = {};
    };

    // --- TITANIUM ---
    class MEC_Sound_Titanium_Shear
    {
        name = "MEC_Titanium_Shear";
        // Vanilla 'DestrMetal' @ 0.6 pitch (Heavy tearing metal)
        sound[] = {"@A3\sounds_f\structures\destr\metal_destr_01.wss", 3.16, 0.6, 200};
        titles[] = {};
    };

    // --- BESKAR ---
    class MEC_Sound_Beskar_Ring
    {
        name = "MEC_Beskar_Ring";
        // Vanilla 'HitMetal' @ 0.5 pitch (Gong-like impact)
        sound[] = {"@A3\Sounds_F\physics\bullet_impacts\metal_plate_01.wss", 4.0, 0.5, 100};
        titles[] = {};
    };
};