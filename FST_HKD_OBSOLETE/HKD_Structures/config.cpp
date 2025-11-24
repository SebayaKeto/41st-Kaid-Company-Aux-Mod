#include "HKD_Base_Defines.hpp"

class CfgPatches {
    class FST_HKD_Structures {
        name = HKD_FULL_NAME;
        units[] = {
            "FST_HKD_Blocker_Blank",
            "FST_HKD_Blocker_CIS",
            "FST_HKD_Blocker_HKD"
        };
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"A3_Structures_F"};
        author = HKD_AUTHOR;
        authorUrl = "";
        version = 1.0;
    };
};
class CfgVehicles 
{
    class StaticObject;

    // =========================================================================
    // BASE BLOCKER CLASS
    // =========================================================================
    class FST_HKD_Blocker_Base : StaticObject 
    {
        scope = 0;
        author = HKD_AUTHOR;
        displayName = "HKD Blocker (Base)";
        description = HKD_DESC_BLOCKER;
        model = "\FST\FST_HKD\HKD_Structures\HKD_VehicleBlocker.p3d";
        mapSize = 4.0;
        editorCategory = "FST_HKD_CategoryStructures";
        editorSubcategory = "FST_HKD_Subcategory_Barriers";
        
        class Damage 
        {
            tex[] = {};
            mat[] = {};
        };
        
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"};
        hiddenSelectionsMaterials[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo.rvmat"};
        
        armor = 600;
        destrType = "DestructBuilding";
        HKD_CanBeGravDropped = 0;
        
        class DestructionEffects 
        {
        };
    };

    // =========================================================================
    // VARIATION 1: BLANK (Unpainted Hull Plating)
    // =========================================================================
    class FST_HKD_Blocker_Blank : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - Blank";
        description = HKD_DESC_BLOCKER + " [Unpainted Hull Plating]";
        editorCategory = "FST_HKD_CategoryStructures";
        editorSubcategory = "FST_HKD_Subcategory_Barriers";
        HKD_CanBeGravDropped = 1;
        
        hiddenSelectionsTextures[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"};
        hiddenSelectionsMaterials[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo.rvmat"};
        
        editorPreview = "\FST\FST_HKD\HKD_Structures\Data\UI\HKD_UI_BlockerLargeBlank.jpg";
        
        class EventHandlers {};
    };

    // =========================================================================
    // VARIATION 2: CIS (Confederacy of Independent Systems Markings)
    // =========================================================================
    class FST_HKD_Blocker_CIS : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - CIS";
        description = HKD_DESC_BLOCKER + " [CIS Markings]";
        editorCategory = "FST_HKD_CategoryStructures";
        editorSubcategory = "FST_HKD_Subcategory_Barriers";
        HKD_CanBeGravDropped = 1;
        
        hiddenSelectionsTextures[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"};
        hiddenSelectionsMaterials[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo.rvmat"};
        
        editorPreview = "\FST\FST_HKD\HKD_Structures\Data\UI\HKD_UI_BlockerLargeCIS.jpg";
        
        class EventHandlers {};
    };

    // =========================================================================
    // VARIATION 3: HKD (HKD Corporate Markings)
    // =========================================================================
    class FST_HKD_Blocker_HKD : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - HKD";
        description = HKD_DESC_BLOCKER + " [HKD Corporate Markings]";
        editorCategory = "FST_HKD_CategoryStructures";
        editorSubcategory = "FST_HKD_Subcategory_Barriers";
        HKD_CanBeGravDropped = 1;
        
        hiddenSelectionsTextures[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"};
        hiddenSelectionsMaterials[] = {"FST\FST_HKD\HKD_Structures\Data\Textures\VehicleBlockers\Camo.rvmat"};
        
        editorPreview = "\FST\FST_HKD\HKD_Structures\Data\UI\HKD_UI_BlockerLargeCompany.jpg";
        
        class EventHandlers {};
    };
};
