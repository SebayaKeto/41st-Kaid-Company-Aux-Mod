
// ===================================================================================
// MASTER CONFIG: FST_HKD_Structures
// This file acts as the master config for all subfolders. DO NOT COMPILE SUBFOLDER CONFIGS ALONE.
// Add all subfolder config includes below. Only define CfgVehicles here to avoid double counting.
// ===================================================================================

class CfgPatches
{
    class FST_HKD_Structures
    {
        author = "FST";
        name = "FST HKD Structures";
        requiredAddons[] = {"A3_Structures_F"};
        requiredVersion = 0.1;
        units[] = {
            // ===== LARGE WEDGE BARRIERS (Vehicle Deflectors) =====
            "FST_HKD_Barrier_WedgeLarge_Blank",
            "FST_HKD_Barrier_WedgeLarge_Default",
            "FST_HKD_Barrier_WedgeLarge_Corporate",
            
            // ===== MEDIUM COVER BARRIERS (Infantry Cover) =====
            "FST_HKD_Barrier_CoverMedium_Blank",
            "FST_HKD_Barrier_CoverMedium_Default",
            "FST_HKD_Barrier_CoverMedium_Corporate",
            
            // ===== SMALL DEFENSIVE BLOCKERS (Compact Cover) =====
            "FST_HKD_Blocker_Small_Blank",
            "FST_HKD_Blocker_Small_Default",
            "FST_HKD_Blocker_Small_Corporate",
            
            // ===== ANTI-PERSONNEL SPIKES =====
            "FST_HKD_Spike_Single",
            "FST_HKD_Spike_Line5m",
            "FST_HKD_Spike_Line10m",
            
            // ===== ANTI-VEHICLE TANK TRAPS =====
            "FST_HKD_Trap_Tank_Blank",
            "FST_HKD_Trap_Tank_Default",
            "FST_HKD_Trap_Tank_Corporate"
        };
        weapons[] = {};
    };
};

class CfgVehicles
{
    class House_F;
    #include "Blockers/Blocker.cpp"
};
