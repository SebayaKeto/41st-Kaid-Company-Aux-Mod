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
	class MEC_BreakerBox_Base : House_F 
	{ 
		scope = 1; 
		scopeCurator = 1; 
		displayName = "Breaker Box (Base)"; 
		author = MEC_FULL_NAME; 
		destructType = "DestructNo"; 
		editorCategory = "FST_MEC_CategoryPowerSystems"; 
		editorSubcategory = "FST_MEC_BreakerBoxes"; 
		model = "FST\FST_MEC\FST_MEC_PowerConduit\FST_MEC_BreakerBox.p3d"; 
		hiddenSelections[] = {"Camo"}; 
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Yellow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo.rvmat"};
		descriptionShort = "MEC Power Conduit. Constructed using Layered, Insulated containment doctrine for zero-surge power transfer in extreme thermal environments."; 
		class AnimationSources
		{
			// Animation sources for doors
			class Door_1_source
			{
				source = "user";
				initPhase = 0;
				animPeriod = 1;
				sound = "LightOutpostDoorsSound";
				soundPosition="door_1_axis";
			};
		};
		class UserActions
		{
			class OpenDoor_1
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorOpen.paa' size='6' />";
				displayName = "Open Breaker Door";
				position = "door_1_axis";
				priority = 11;
				radius = 5;
				condition="((this animationSourcePhase 'Door_1_source') < 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_1_source', 1]";
			};
			class CloseDoor_1: OpenDoor_1
			{
				displayNameDefault = "<img image='FST\FST_Core\UIImages\FST_DoorClose.paa' size='5' />";
				displayName = "Close Breaker Door";
				position = "door_1_axis";
				condition="((this animationSourcePhase 'Door_1_source') >= 0.5) && (cameraOn isKindOf 'CAManBase')";
				statement = "this animateSource ['Door_1_source', 0]";
			};
		};
		actionBegin1="OpenDoor_1";
		actionEnd1="CloseDoor_1";
		class SimpleObject
		{
			eden=1;
			animate[] =
			{
				{
					"door_1_rot",
					0
				}
			};
			hide[]={};
			verticalOffset=3.0599999;
			verticalOffsetWorld=0;
			init="''";
		};
	}; 
	class MEC_BreakerBox_Yellow : MEC_BreakerBox_Base
	{
		scope = 2; 
		scopeCurator = 2;
		displayName = "Breaker Box (Yellow)";
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Yellow_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo.rvmat"};
	};
	class MEC_BreakerBox_MEC : MEC_BreakerBox_Base
	{
		scope = 2; 
		scopeCurator = 2;
		displayName = "Breaker Box (MEC)";
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_MEC_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_MEC.rvmat"};
	};	
	class MEC_BreakerBox_Republic : MEC_BreakerBox_Base
	{
		scope = 2; 
		scopeCurator = 2;
		displayName = "Breaker Box (Republic)";
		hiddenSelectionsTextures[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Republic_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_MEC\FST_MEC_PowerConduit\Data\Textures\Camo_Republic.rvmat"};
	};
};