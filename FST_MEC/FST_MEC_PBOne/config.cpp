#include "mec_base_defines.hpp"

class CfgPatches
{
    class FST_MEC_PBOne_Patch
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"ace_common"}; 
        name = "MEC: Maldova Engineering Corp."; // Mod Name
        author = MEC_AUTHOR; // Author information
        logo = MEC_ICON_PATH; // Path to logo
        picture = MEC_ICON_PATH; // Path to picture
        dlcTag = "MEC_Mod"; // DLC Tag
    };
};
class CfgVehicles
{
    class Item_Base_F; 
    class Static_F;
    #include "mec_pebble_item.hpp"
};
class CfgWeapons
{
    #include "mec_pebble_weapon.hpp"
};