#include "MEC_Aegis_Defines.hpp"
class CfgPatches
{
	class MEC_Aegis_Barriers
	{
		units[] = {};
		weapons[] = {};
		requiredVersion = 1.0;
		requiredAddons[] = 
        {
            "A3_Structures_F_Exp_Civilian",
			"FST_Core",
			"FST_Common"
        }; 
		author = MEC_SHORT_NAME;
	};
};
class CfgVehicles 
{
    class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class MEC_Aegis_Barrier_Base : House_F 
	{ 
		scope = 2; 
		scopeCurator = 2; 
		displayName = "MEC Aegis Barrier System"; 
		author = MEC_FULL_NAME; 
		destructType = "DestructNo"; 
		editorCategory = "FST_MEC_CategoryAegisBarriers"; 
		editorSubcategory = "FST_MEC_AegisBarriers_Duracrete"; 
		model = ""; 
		hiddenSelections[] = {"Camo"}; 
		hiddenSelectionsTextures[] = {""};
		hiddenSelectionsMaterials[] = {""};
		descriptionShort = MEC_AEGIS_DESCRIPTION_TYPE_1; 
		
	};
};