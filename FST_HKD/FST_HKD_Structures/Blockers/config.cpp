// ===================================================================================
// HKD BLOCKERS - VEHICLE BLOCKERS
// ===================================================================================
// Massive wedge-shaped barriers made from recycled starship armor
// Designed for area denial and forcing vehicles upward to expose underside

class CfgVehicles 
{
    class House_F;

    // =========================================================================
    // BASE BLOCKER CLASS
    // =========================================================================
    class FST_HKD_Blocker_Base : House_F 
    {
        scope = 0;
        author = "Hoersch-Kessel Driveworks";
        displayName = "HKD Blocker (Base)";
        description = "A massive, wedge-shaped slab of recycled starship armor. Designed to force repulsor tanks upward, exposing their underbelly. Immune to small arms and light cannons.";
        model = "\FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_VehicleBlocker.p3d";
        mapSize = 4.0;
        editorCategory = "fst_hkd_edcat";
        editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
        
        class Damage 
        {
            tex[] = {};
            mat[] = {};
        };
        
        hiddenSelections[] = {"Camo"};
        hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\Camo_Blank_co.paa"};
        hiddenSelectionsMaterials[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\Camo.rvmat"};
        
        armor = 600;
        destrType = "DestructBuilding";
        
        class DestructionEffects 
        {
        };
    };
    class FST_HKD_Blocker_Blank : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - Blank";
        description = "Massive wedge-shaped barrier (Unpainted Hull Plating)";
        editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg";
        
        hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\Camo_Blank_co.paa"};
        
        class EventHandlers {};
    };
    class FST_HKD_Blocker_CIS : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - CIS";
        description = "Massive wedge-shaped barrier (CIS Markings)";
        editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg";
        
        hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\Camo_CIS_co.paa"};
        
        class EventHandlers {};
    };
    class FST_HKD_Blocker_HKD : FST_HKD_Blocker_Base 
    {
        scope = 2;
        scopeCurator = 2;
        displayName = "[HKD] Blocker - HKD";
        description = "Massive wedge-shaped barrier (HKD Corporate Markings)";
        editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg";
        
        hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\Camo_HKD_co.paa"};
        
        class EventHandlers {};
    };
};
