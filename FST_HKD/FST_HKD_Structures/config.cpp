
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
            "FST_HKD_VehBlocker_Blank",
            "FST_HKD_VehBlocker_CIS",
            "FST_HKD_VehBlocker_HKD",
            "FST_HKD_InfBlocker_Blank",
            "FST_HKD_InfBlocker_CIS",
            "FST_HKD_InfBlocker_HKD"
        };
        weapons[] = {};
    };
};

class CfgVehicles
{
    #include "Blockers/Blocker.cpp"
};
