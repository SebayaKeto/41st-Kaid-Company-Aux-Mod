

// ===================================================================================
// HKD DEFENSIVE FORTIFICATIONS - WALL GREEBLE DETAILS
// ===================================================================================
// Hoersch-Kessel Driveworks wall detailing and greeble elements
// Small decorative and functional details for wall surface variation
// Designed as lightweight overlays for wall texture variation and detail enhancement

// =========================================================================
// WALL GREEBLE SMALL BASE CLASS
// =========================================================================
class FST_HKD_WallGreeble_Small_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Wall Greeble Small (Base)"; // Internal display name
    description = "A small greeble detail element for wall surface variation. Adds visual detail and texture layering to fortification walls."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\WallGreeble\HKD_WallGreebleSmall.p3d"; // 3D model file
    mapSize = 1.5; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_greeble"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Default texture (uses HeavyWalls Camo2)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Material file (uses HeavyWalls Camo2)
    
    armor = 50; // Structural durability (lightweight detail piece)
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_WallGreeble_Small : FST_HKD_WallGreeble_Small_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Wall Greeble - Small"; // Editor list name
    description = "Wall greeble detail element for surface variation and detail enhancement."; // Editor tooltip
    
    class EventHandlers {}; // Empty event handler class
};
