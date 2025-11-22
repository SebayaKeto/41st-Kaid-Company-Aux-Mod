#include "\FST\FST_MEC\mec_base_defines.hpp"
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
		scope = 1; 
		scopeCurator = 1; 
		displayName = "MEC Aegis Barrier System"; 
		author = MEC_FULL_NAME; 
		destructType = "DestructNo"; 
		editorCategory = "FST_MEC_CategoryAegisBarriers"; 
		editorSubcategory = "FST_MEC_AegisBarriers_Duracrete"; 
		model = "FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\FST_MEC_DuracreteBarrier.p3d"; 
		hiddenSelections[] = {"Camo"}; 
		hiddenSelectionsTextures[] = {""};
		hiddenSelectionsMaterials[] = {""};
		descriptionShort = MEC_AEGIS_DESCRIPTION_TYPE_1;
		class MEC_CobaltProperties //Class used to define the Power System properties
		{ 
			powerConsumption = 0;
			repairable = 0;
			shielded = 0;
			shieldStrength = 0;
			shieldRechargeRate = 0;
			shieldRechargeDelay = 0;
		};
		class MEC_AegisProperties 
		{ 
			MEC_MaterialType = MEC_AEGIS_TYPE_1;
			maxHealth = 1000; 
			repairable = 0;
		};
		class DestructionEffects : DestructionEffects 
		{
			class Dust 
			{
				simulation = "particles"; 
				type = "HouseDestruction"; 
				position = "destructionEffect1"; 
				intensity = 1; 
				interval = 1; 
				lifeTime = 1; 
			}; 
		};
	};
};