
// ===================================================================================
// HKD PROPS - SUPPLY CRATES
// ===================================================================================
// Hoersch-Kessel Driveworks supply and ammunition storage containers
// Medium-sized cargo crates for field equipment storage
// Supports multi-faction scenarios with 4 color variants (Standard, Blue, Orange, White)

// =========================================================================
// SUPPLY CRATE MEDIUM BASE CLASS
// =========================================================================
class FST_HKD_Crate_SupplyMedium_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Supply Crate Medium (Base)"; // Internal display name
    description = "A medium-sized supply crate for equipment and ammunition storage. Useful for forward operating base logistics."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Props\Crates\HKD_SupplyCrateMedium.p3d"; // 3D model file
    mapSize = 3.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_props_crates"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo.rvmat"}; // Material file
    
    armor = 100; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Crate_SupplyMedium_Blank : FST_HKD_Crate_SupplyMedium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Medium (Standard)"; // Editor list name
    description = "Supply crate - standard finish. Field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Brown.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_SupplyMedium_Blue : FST_HKD_Crate_SupplyMedium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Medium (Blue)"; // Editor list name
    description = "Supply crate - blue finish variant. Field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Blue.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Blue_co.paa"}; // Blue variant texture
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_SupplyMedium_Orange : FST_HKD_Crate_SupplyMedium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Medium (Orange)"; // Editor list name
    description = "Supply crate - orange finish variant. Field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Orange.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Orange_co.paa"}; // Orange variant texture
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_SupplyMedium_White : FST_HKD_Crate_SupplyMedium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Medium (White)"; // Editor list name
    description = "Supply crate - white finish variant. Field logistics storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_White.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_White_co.paa"}; // White variant texture
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Crate_SupplyMedium_GeneralLogistics : FST_HKD_Crate_SupplyMedium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Supply Crate - Medium (General Logistics)"; // Editor list name
    description = "Supply crate - red finish variant for general logistics. Field supply storage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Props\Crates\Data\UI\HKD_UICrateMedium_Red.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red_co.paa"}; // Red variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Props\Crates\Data\Textures\Camo_Red.rvmat"}; // Red material file
    
    class EventHandlers {}; // Empty event handler class
};
