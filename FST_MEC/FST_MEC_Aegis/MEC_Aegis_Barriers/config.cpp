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
			repairableClass = "";
		};
	};
	class MEC_Aegis_Barrier_Duracrete_Large: MEC_Aegis_Barrier_Base
	{
		scope = 2; 
		displayName = "Duracrete Aegis Barrier (Large)";
		model = "FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\FST_MEC_DuracreteBarrier.p3d"; 
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\Data\DuracreteTextures\Camo_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\Data\DuracreteTextures\Camo.rvmat"};
		replaceDamagedHitpoints[] = {"Hitzone_1_hitpoint"};
		replaceDamaged = "MEC_Aegis_Barrier_Duracrete_Large_Damaged";
		class DestructionEffects : DestructionEffects 
		{
			class ruins
			{
				simulation = "ruin"; 
				type = "FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\FST_MEC_DuracreteBarrier_Destroyed.p3d"; 
				position = ""; 
				intensity = 1; 
				interval = 1; 
				lifeTime = 1; 
			};
		};
	};
	class MEC_Aegis_Barrier_Duracrete_Large_Damaged: MEC_Aegis_Barrier_Base
	{
		scope = 1; 
		displayName = MEC_AEGIS_DISPLAY_NAME_TYPE_1;
		model = "FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\FST_MEC_DuracreteBarrier_Damaged.p3d";
		hiddenSelections[] = {"Camo","Camo1"}; 
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\Data\DuracreteTextures\Camo_co.paa","FST\FST_MEC\FST_MEC_Common\ConcreteDamaged\ConcreteDamaged_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_Aegis\MEC_Aegis_Barriers\Data\DuracreteTextures\Camo.rvmat","FST\FST_MEC\FST_MEC_Common\ConcreteDamaged\ConcreteDamaged.rvmat"};
		replaceDamagedHitpoints[] = {};
		replaceDamaged = "";
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
			repairable = 1;
			repairableClass = "MEC_Aegis_Barrier_Duracrete_Large";
		};
		class Damage
		{
			tex[] = {};
			mat[] = {};
		};
	};
};