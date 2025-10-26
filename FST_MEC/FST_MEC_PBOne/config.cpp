#include "mec_base_defines.hpp" // NEW: Include base definitions

class CfgPatches
{
    class FST_MEC_PBOne_Patch
    {
        units[] = {};
        weapons[] = {}; 
        magazines[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_common", "ace_interact_menu", "A3_Data_F_Loadorder"}; 
        author = MEC_AUTHOR;
    };
};
class CfgVehicles
{
    class Item_Base_F; 
    class Static_F;
    #include "mec_pebble_item.hpp"       // MEC-PB/1 Item
};
class CfgWeapons
{
    #include "mec_pebble_weapon.hpp"
};