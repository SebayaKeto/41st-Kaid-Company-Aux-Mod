#include "MEC_Conduits_BreakerBox.hpp"
class CfgPatches
{
	class MEC_FST_Conduits
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
		author = MEC_FULL_NAME;
	};
};
class CfgVehicles 
{
    class House;
	class House_F: House
	{
		class DestructionEffects;
	};
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Base, "FST_MEC_BreakerBox", "Breaker Box (Base)", "Camo.paa", "Camo.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Yellow, "FST_MEC_BreakerBox", "Breaker Box (Yellow)", "Camo_Yellow.paa", "Camo.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_MEC, "FST_MEC_BreakerBox", "Breaker Box (MEC)", "Camo_MEC.paa", "Camo_MEC.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Republic, "FST_MEC_BreakerBox", "Breaker Box (Republic)", "Camo_Republic.paa", "Camo_Republic.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Senate, "FST_MEC_BreakerBox", "Breaker Box (Senate)", "Camo_Senate.paa", "Camo_Senate.rvmat");
};