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
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Base, "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d", "Breaker Box (Base)", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo.paa", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Yellow, "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d", "Breaker Box (Yellow)", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Yellow.paa", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_MEC, "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d", "Breaker Box (MEC)", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_MEC.paa", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_MEC.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Republic, "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d", "Breaker Box (Republic)", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Republic.paa", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Republic.rvmat");
    MEC_POWERSYSTEM_BREAKERBOX_CLASS(MEC_BreakerBox_Senate, "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d", "Breaker Box (Senate)", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Senate.paa", "FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Senate.rvmat");
};