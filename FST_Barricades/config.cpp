class CfgPatches
{
	class FST_Barricades_SecurityBarrier
	{
		author="Maldova";
		requiredAddons[]=
		{
			"A3_Structures_F_Exp_Civilian",
			"FST_Core"
		};
		requiredVersion=0.1;
		units[]=
		{
			"FST_Barricade_SecurityBarrier",
			"FST_Barricade_SecurityBarrier_Factory",
			"FST_Barricade_SecurityBarrier_Sand",
			"FST_Barricade_SecurityBarrier_Tundra",
			"FST_Barricade_SecurityBarrier_Jungle",
			"FST_Barricade_SecurityBarrierShieldWide",
			"FST_Barricade_SecurityBarrierShieldTowerTop"
		};
		weapons[]={};
	};
};
class CfgVehicles
{
	class House;
	class House_F: House
	{
		class DestructionEffects;
	};
	class Ruins_F;
	class FST_Barricade_SecurityBarrier_Base: House_F
	{
		editorCategory = "FST_CatagoryBarricades";
		editorSubcategory = "FST_Subcategory_SecurityBarricades";
		scope = 1;
		scopecurator = 1;
		placement = "vertical";
		mapSize = 1;
		destrType = "DestructNo";
		displayName = "[41st] Security Barrier";
		model = "FST\FST_Barricades\41st_SecurityBarrier.p3d";
		faction = "prop";
		eden = 1;
	};
	// Base Asset and Texture
	class FST_Barricade_SecurityBarrier: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Factory: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Factory)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Factory_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Factory_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	//Camo Colors
	class FST_Barricade_SecurityBarrier_Sand: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Sand)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Sand_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Tundra: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Tundra)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_Tundra_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	class FST_Barricade_SecurityBarrier_Jungle: FST_Barricade_SecurityBarrier_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Security Barrier (Jungle)";
		hiddenSelections[] = {"Camo1","Plasteel", "Steel"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Barricades\Data\Textures\FSTBarrier_JungleOvergrown_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Barricades\Data\Textures\FSTBarrier.rvmat"};
	};
	// Shielded Security Barricade
	class FST_Barricade_SecurityBarrierShieldWide_Base: FST_Barricade_SecurityBarrier_Base
	{
		displayName = "[41st] Security Barrier (Shield)";
		model = "FST\FST_Barricades\41st_SecurityBarrierShieldWide.p3d";
		class AnimationSources
        {
            class Shield_Hide
            {
                type = "identity";
                source = "user";
                initPhase = 1; // 1 = hidden, 0 = visible
                animPeriod = 0;
            };
        };
        
        //For static objects
        class SimpleObject
        {
            eden = true;
            animate[] = 
            {
              {"Shield", 1} //0 visible, 1 invisible.  Setting it here as well.
            };
            
        };
	};
	class FST_Barricade_SecurityBarrierShieldWide: FST_Barricade_SecurityBarrierShieldWide_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Shielded Security Barrier";
		hiddenSelections[] = {"Camo1","Plasteel", "Shield"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\Camo1_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Common\Data\Textures\Shield\BlueShield_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\Camo1.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Common\Data\Textures\Shield\Shield.rvmat"};
	};
	//Tower Top W/ Shield No Ladder
	class FST_Barricade_SecurityBarrierShieldTowerTop_Base: FST_Barricade_SecurityBarrier_Base
	{
		displayName = "[41st] Shielded Security Tower Top";
		model = "FST\FST_Barricades\41st_SecurityTowerTopNoLadder.p3d";
		Shield_Hidden = false;
		class UserActions
		{
			class Shield_Toggle
			{
				displayName = "Toggle Shields";       // Text in the action menu
				displayNameDefault = "Toggle Shields"; // Text when looking at the object
				position = "Shield_Interaction";    // Memory point in the model
				radius = 2;                  // Interaction distance in meters
				onlyForPlayer = true;          // Only show for players, not AI
				showWindow = true;             // Show text near the center of the screen
				hideOnUse = true;              // Close the menu after using
				priority = 20;                   // Higher number = higher priority
				condition = "true";            // Action is always available
				statement = "_this call FST_fnc_toggleShield;"; // Call the function
			};
		};
	};
	class FST_Barricade_SecurityBarrierShieldTowerTop: FST_Barricade_SecurityBarrierShieldTowerTop_Base
	{
		scope = 2;
		scopecurator = 2;
		displayName = "[41st] Shielded Security Tower Top";
		hiddenSelections[] = {"Camo1","Plasteel", "Shield", "Camo1Low","Camo2","StairArmor","Railing","MetalGrid"};
		hiddenSelectionsTextures[] = {"FST\FST_Barricades\Data\Textures\Camo1_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa", "FST\FST_Common\Data\Textures\Shield\BlueShield_co.paa","FST\FST_Barricades\Data\Textures\Camo1_co.paa","FST\FST_Barricades\Data\Textures\Camo2_co.paa","FST\FST_Common\Data\Textures\SteelStained\SteelStained_co.paa","FST\FST_Common\Data\Textures\HazardSteel\HazardSteel_co.paa","FST\FST_Common\Data\Textures\MetalGrid\MetalGrid_co.paa"};
		hiddenSelectionsMaterials[] = {"FST\FST_Barricades\Data\Textures\Camo1.rvmat", "FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat", "FST\FST_Common\Data\Textures\Shield\Shield.rvmat","","FST\FST_Barricades\Data\Textures\Camo2.rvmat","FST\FST_Common\Data\Textures\SteelStained\Steel.rvmat","FST\FST_Common\Data\Textures\HazardSteel\HazardSteel.rvmat","FST\FST_Common\Data\Textures\MetalGrid\MetalGrid.rvmat"};
		Shield_Hidden = false;
		class AnimationSources
		{
			class Shield_Source
			{
				source = user; // "user" = custom source = not controlled by some engine value
				initPhase = 0; // Initial value of animations based on this source
				animPeriod = 1; // Coefficient for duration of change of this animation
				sound = "GenericDoorsSound"; /// Selects sound class from CfgAnimationSourceSounds that is going to be used for sounds of doors
			};
		};
		class UserActions
        {
            class HideShield
            {
                displayName = "Deactivate Shield"; // Text displayed in the user action menu
                position = "Shield_Interaction"; //  Where the action appears (e.g., "action", "wheel", "cargo")
                onlyForPlayer = true; // Only the player can see this action
				radius = 12;
                condition = "!(this getVariable ['Shield_Hidden', false])";  // Action is available if shield is NOT hidden
                statement = "this hideSelection ['Shield', true]; this setVariable ['Shield_Hidden', true];"; // Hides the selection and sets a variable
            };
             class ShowShield
            {
                displayName = "Activate Shield"; // Text displayed in the user action menu
                position = "Shield_Interaction";
                onlyForPlayer = true;
				radius = 12;
                condition = "this getVariable ['Shield_Hidden', false]";  // Action is available if shield IS hidden
                statement = "this hideSelection ['Shield', false]; this setVariable ['Shield_Hidden', false];";
            };
        };
	};
};
class cfgFunctions
{
	class FST_Barricades
	{
		tag = "FST";

		class Scripts
		{
			file = "FST\FST_Barricades\Functions";

			class toggleShield{};
		};
	};
};