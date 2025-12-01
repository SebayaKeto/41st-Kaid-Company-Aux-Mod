
// ===================================================================================
// HKD PROPS - CARGO CRATES
// ===================================================================================
// Hoersch-Kessel Driveworks cargo and equipment storage containers
// Small-sized modular cargo crates for field equipment storage
// Supports multi-faction scenarios with 5 color variants (Standard, Blue, Orange, White, General Logistics)

// =========================================================================
// CARGO CRATE SMALL BASE CLASS
// =========================================================================
class FST_HKD_Crate_CargoSmall_Base : ReammoBox_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Cargo Crate Small (Base)"; // Internal display name
    description = "A small modular cargo crate for equipment and supplies storage. Useful for compact base operations and field logistics."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Props\Crates\HKD_CargoCrateModuleSmall.p3d"; // 3D model file
    mapSize = 2.5; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_props_crates"; // Editor subcategory
    
    class Damage // Damage material progression
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = 
        {
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo.rvmat", // Normal state
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo.rvmat", // Light damage
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Destroyed.rvmat" // Destroyed state
        };
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo.rvmat"}; // Material file
    
    armor = 150; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    mass = 200; // Mass in kg for ACE cargo calculations
    
    // Structural armor
    structuralDamage = 1; // Enable structural damage system
    
    // Cargo configuration - Allow all item types
    maximumLoad = 10000; // Maximum cargo weight
    transportMaxMagazines = 500; // Magazine storage capacity
    transportMaxWeapons = 100; // Weapon storage capacity
    transportMaxBackpacks = 50; // Backpack storage capacity
    
    // ACE Cargo configuration
    ace_cargo_space = 150; // ACE cargo space in liters
    ace_cargo_size = 6; // Cargo size category - fits medium attachment points
    ace_cargo_canLoad = 1; // Can be loaded via ACE cargo
    ace_cargo_hasCargo = 0; // Not a vehicle (doesn't require cargo system)
    ace_draggable = 1; // Can be dragged via ACE drag system
    ace_canLoad = 1; // Can be loaded onto vehicles
    
    // ACE Drag and Carry configuration
    ace_carryable = 1; // Can be carried
    ace_drag_maxWeightCarry = 200; // Maximum weight for carrying (200kg = crate mass)
    
    // ACE Interaction settings
    ace_common_allowSprint = 0; // No sprinting while interacting
    
    class DestructionEffects // Visual effects on destruction
    {
        class Smoke
        {
            simulation = "smoke";
            type = "SmokeShellWhite";
            position = "";
            intensity = 1.0;
            interval = 0.1;
        };
        
        class Fire
        {
            simulation = "fire";
            type = "FirePlace";
            position = "";
            intensity = 0.5;
            interval = 0.1;
        };
        
        class Explosion
        {
            simulation = "explosion";
            type = "BombCluster";
            position = "";
            intensity = 0.3;
            interval = 0.05;
        };
    };
};

class FST_HKD_Crate_CargoSmall_Blank : FST_HKD_Crate_CargoSmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Cargo Crate - Small (Standard)"; // Editor list name
    description = "Cargo crate - standard finish. Compact field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Brown.jpg"; // Preview image
    ace_cargo_space = 150; // ACE cargo space in liters
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_CargoSmall_Blue : FST_HKD_Crate_CargoSmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Cargo Crate - Small (Blue)"; // Editor list name
    description = "Cargo crate - blue finish variant. Compact field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Blue.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Blue_co.paa"}; // Blue variant texture
    ace_cargo_space = 150; // ACE cargo space in liters
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_CargoSmall_Orange : FST_HKD_Crate_CargoSmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Cargo Crate - Small (Orange)"; // Editor list name
    description = "Cargo crate - orange finish variant. Compact field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Orange.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Orange_co.paa"}; // Orange variant texture
    ace_cargo_space = 150; // ACE cargo space in liters
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_CargoSmall_White : FST_HKD_Crate_CargoSmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Cargo Crate - Small (White)"; // Editor list name
    description = "Cargo crate - white finish variant. Compact field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_White.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_White_co.paa"}; // White variant texture
    ace_cargo_space = 150; // ACE cargo space in liters
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_CargoSmall_GeneralLogistics : FST_HKD_Crate_CargoSmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Cargo Crate - Small (General Logistics)"; // Editor list name
    description = "Cargo crate - red finish variant for general logistics. Compact field supply storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Red.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red_co.paa"}; // Red variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red.rvmat"}; // Red material file
    ace_cargo_space = 150; // ACE cargo space in liters
    
    class Damage // Override damage progression for red variant
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = 
        {
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red.rvmat", // Normal state
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red.rvmat", // Light damage
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red_Destroyed.rvmat" // Destroyed state
        };
    };
    
    class DestructionEffects // Reduced destruction effects for logistics variant
    {
        class Smoke
        {
            simulation = "smoke";
            type = "SmokeShellWhite";
            position = "";
            intensity = 0.6;
            interval = 0.15;
        };
        
        class Fire
        {
            simulation = "fire";
            type = "FirePlace";
            position = "";
            intensity = 0.3;
            interval = 0.15;
        };
    };
    
    class EventHandlers {}; // Empty event handler class
};

// =========================================================================
// SUPPLY CRATE SMALL BASE CLASS
// =========================================================================
class FST_HKD_Crate_SupplySmall_Base : ReammoBox_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Supply Crate Small (Base)"; // Internal display name
    description = "A small supply crate for compact equipment storage. Useful for tight spaces and minimal footprint logistics."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Props\Crates\HKD_SupplyCrateSmall.p3d"; // 3D model file
    mapSize = 2.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_props_crates"; // Editor subcategory
    
    class Damage // Damage material progression
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = 
        {
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_SmallCrate.rvmat", // Normal state
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_SmallCrate.rvmat", // Light damage
            "FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_SmallCrate_Destroyed.rvmat" // Destroyed state
        };
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_SmallCrate_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_SmallCrate.rvmat"}; // Material file
    
    armor = 100; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    mass = 10; // Mass in kg for ACE cargo calculations
    
    // Structural armor
    structuralDamage = 1; // Enable structural damage system
    
    // Cargo configuration - Allow all item types
    maximumLoad = 1000; // Maximum cargo weight (smaller crate)
    transportMaxMagazines = 250; // Magazine storage capacity
    transportMaxWeapons = 50; // Weapon storage capacity
    transportMaxBackpacks = 25; // Backpack storage capacity
    
    // ACE Cargo configuration
    ace_cargo_space = 75; // ACE cargo space in liters
    ace_cargo_size = 4; // Cargo size category - fits smaller attachment points
    ace_cargo_canLoad = 1; // Can be loaded via ACE cargo
    ace_cargo_hasCargo = 0; // Not a vehicle (doesn't require cargo system)
    ace_draggable = 1; // Can be dragged via ACE drag system
    ace_canLoad = 1; // Can be loaded onto vehicles
    
    // ACE Drag and Carry configuration
    ace_carryable = 1; // Can be carried
    ace_drag_maxWeightCarry = 200; // Maximum weight for carrying (200kg = crate mass)
    
    // ACE Interaction settings
    ace_common_allowSprint = 0; // No sprinting while interacting
    
    class DestructionEffects // Visual effects on destruction
    {
        class Smoke
        {
            simulation = "smoke";
            type = "SmokeShellWhite";
            position = "";
            intensity = 0.5;
            interval = 0.2;
        };
        
        class Fire
        {
            simulation = "fire";
            type = "FirePlace";
            position = "";
            intensity = 0.2;
            interval = 0.2;
        };
    };
};

class FST_HKD_Crate_SupplySmall_Blank : FST_HKD_Crate_SupplySmall_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Small (Standard)"; // Editor list name
    description = "Supply crate - standard finish. Compact equipment storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UISupplyCrateSmall.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};
