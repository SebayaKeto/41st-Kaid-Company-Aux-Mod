class CfgPatches
{
    class FST_HKD_Structures
    {
        author = "FST";
        name = "FST HKD Structures";
        requiredAddons[] = {"A3_Structures_F"};
        requiredVersion = 0.1;
        units[] = {
            "FST_HKD_Blocker_Blank",
            "FST_HKD_Blocker_CIS",
            "FST_HKD_Blocker_HKD"
        };
        weapons[] = {};
    };
};

// Include Blockers
#include "Blockers\config.cpp"
