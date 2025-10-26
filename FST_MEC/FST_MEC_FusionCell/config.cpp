#include "mec_base_defines.hpp"

class CfgPatches
{
    class FST_MEC_FusionCell_Patch
    {
        units[] = {};
        weapons[] = {}; 
        magazines[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"ace_common", "ace_interact_menu", "A3_Data_F_Loadorder""A3_Structures_F_Exp_Civilian"}; 
        author = MEC_AUTHOR;
    };
};
class CfgVehicles
{
	class Land_WoodenCrate_01_F;
	#include "mec_fusioncell_item.hpp"
};