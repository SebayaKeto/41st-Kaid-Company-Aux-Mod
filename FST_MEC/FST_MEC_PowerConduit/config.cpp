#include "mec_base_defines.hpp"

class CfgPatches
{
    class FST_MEC_PowerConduit_Patch
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
    class MEC_RSU_Conduit_Item : Item_Base_F
    {
        scope = 2;
        displayName = "RSU Power Conduit";
        //model = "\A3\Structures_F\Items\Vessels\Pipe_Cond_short_F.p3d";
        //icon = QPATHTOF(power_conduit.paa);
        mass = 20; // 20 kg
        descriptionShort = "Standardized Republic power conduit hose. Required to link high-output generators (50m range).";
        ACE_isAceTool = 1;
        ACE_inventory_category = "MEC_Logistics";
        ACE_volume = 1;
    };
};