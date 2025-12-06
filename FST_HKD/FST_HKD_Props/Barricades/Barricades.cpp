
// ===================================================================================
// HKD PROPS - BARRICADES
// ===================================================================================
// Hoersch-Kessel Driveworks tactical barricade systems
// Modular defensive barriers for field fortifications
// All barricades reference the single HKD_InfantryBarrier.p3d model and Camo_InfantryBarricade textures

class FST_HKD_Barricade_Portable_Base : ThingX 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Portable Barricade (Base)"; // Internal display name
    description = "A lightweight portable barricade for quick defensive positions. Easily movable and stackable for rapid fortification."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Props\Barricades\HKD_InfantryBarrier.p3d"; // 3D model file
    mapSize = 2.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_props_barricades"; // Editor subcategory
    
    class Damage // Damage material progression
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = 
        {
            "FST\FST_HKD\FST_HKD_Props\Barricades\Data\Textures\Camo_InfantryBarricade.rvmat", // Normal state
            "FST\FST_HKD\FST_HKD_Props\Barricades\Data\Textures\Camo_InfantryBarricade.rvmat", // Light damage
            "FST\FST_HKD\FST_HKD_Props\Barricades\Data\Textures\Camo_InfantryBarricade_Destroyed.rvmat" // Destroyed state
        };
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Barricades\Data\Textures\Camo_InfantryBarricade_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Barricades\Data\Textures\Camo_InfantryBarricade.rvmat"}; // Material file
    
    armor = 75; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    mass = 40; // Mass in kg for ACE cargo calculations
    
    // Structural armor
    structuralDamage = 1; // Enable structural damage system
    
    // ACE Cargo configuration
    ace_cargo_space = 30; // ACE cargo space in liters
    ace_cargo_size = 3; // Cargo size category - fits small attachment points
    ace_cargo_canLoad = 1; // Can be loaded via ACE cargo
    ace_cargo_hasCargo = 0; // Not a vehicle (doesn't require cargo system)
    ace_draggable = 1; // Can be dragged via ACE drag system
    ace_canLoad = 1; // Can be loaded onto vehicles
    
    // ACE Drag and Carry configuration
    ace_carryable = 1; // Can be carried
    ace_drag_maxWeightCarry = 40; // Maximum weight for carrying (40kg = barricade mass)
    
    // ACE Interaction settings
    ace_common_allowSprint = 0; // No sprinting while interacting
    
    class DestructionEffects // Visual effects on destruction
    {
        class Smoke
        {
            simulation = "smoke";
            type = "SmokeShellWhite";
            position = "";
            intensity = 0.6;
            interval = 0.1;
        };
        
        class Dust
        {
            simulation = "particles";
            type = "Dust";
            position = "";
            intensity = 0.4;
            interval = 0.1;
        };
    };
};

class FST_HKD_Barricade_Portable_Blank : FST_HKD_Barricade_Portable_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Portable Barricade (Standard)"; // Editor list name
    description = "Portable barricade - standard finish. Lightweight defensive barrier for quick fortification."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Barricades\Data\UI\HKD_UI_InfantryBarricade.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};