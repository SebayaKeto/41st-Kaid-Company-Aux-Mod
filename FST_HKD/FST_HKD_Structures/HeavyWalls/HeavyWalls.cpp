

// ===================================================================================
// HKD DEFENSIVE FORTIFICATIONS - HEAVY WALLS
// ===================================================================================
// Hoersch-Kessel Driveworks defensive structures: heavy fortification walls
// Made from battle-hardened armor plating and reinforced materials
// Designed for perimeter defense, base construction, and tactical positions
// Supports multi-faction scenarios with 4 texture variants (Blank, CIS, HKD, RawForged)

// =========================================================================
// STRAIGHT WALL SECTION BASE CLASS
// =========================================================================
class FST_HKD_Wall_Heavy_Straight_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Straight Wall (Base)"; // Internal display name
    description = "A section of heavy reinforced wall. Designed for perimeter defense and area fortification. Provides protection against small arms and light explosives."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_HeavyWall_Straight.p3d"; // 3D model file
    mapSize = 5.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo", "Camo1", "Camo2"}; // Textureable selection names
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Default textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Material files
    
    armor = 800; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_Straight_Blank : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (Unpainted)"; // Editor list name
    description = "Straight wall section - unpainted hull plating. Perimeter defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraight.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Straight_CIS : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (CIS)"; // Editor list name
    description = "Straight wall section - CIS markings. Perimeter defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraightCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_CIS_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // CIS variant textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // CIS material files
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Straight_HKD : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (HKD)"; // Editor list name
    description = "Straight wall section - HKD corporate markings. Perimeter defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraightCompany.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_HKD_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // HKD variant textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // HKD material files
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Straight_RawForged : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (Raw Forged)"; // Editor list name
    description = "Straight wall section - raw forged metal appearance. Perimeter defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraightRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_RawForged_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Raw Forged variant textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Raw Forged material files
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Straight_DarkMetal : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (Dark Metal)"; // Editor list name
    description = "Straight wall section - dark metallic finish. Perimeter defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraightRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_DarkMetal_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Dark Metal variant textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Dark Metal material files
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Straight_DarkMetal_CIS : FST_HKD_Wall_Heavy_Straight_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Straight (Dark Metal - CIS)"; // Editor list name
    description = "Straight wall section - dark metallic finish with CIS markings. Perimeter defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_HeavyWallStraightCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_DarkMetal_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_CIS_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Dark Metal CIS variant textures
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Dark Metal CIS material files
    
    class EventHandlers {}; // Empty event handler class
};

/* 
// =========================================================================
// CURVED WALL SECTION BASE CLASS
// =========================================================================
class FST_HKD_Wall_Heavy_Curved_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Curved Wall (Base)"; // Internal display name
    description = "A curved section of heavy reinforced wall. Designed for perimeter corners, defensive angles, and structural flow. Provides protection against small arms and light explosives."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_Wall_Heavy_Curved.p3d"; // 3D model file
    mapSize = 5.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved.rvmat"}; // Material file
    
    armor = 800; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_Curved_Blank : FST_HKD_Wall_Heavy_Curved_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Curved (Unpainted)"; // Editor list name
    description = "Curved wall section - unpainted hull plating. Corner defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallCurvedBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Curved_CIS : FST_HKD_Wall_Heavy_Curved_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Curved (CIS)"; // Editor list name
    description = "Curved wall section - CIS markings. Corner defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallCurvedCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_CIS_co.paa"}; // CIS variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_CIS.rvmat"}; // CIS material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Curved_HKD : FST_HKD_Wall_Heavy_Curved_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Curved (HKD)"; // Editor list name
    description = "Curved wall section - HKD corporate markings. Corner defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallCurvedHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_HKD_co.paa"}; // HKD variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_HKD.rvmat"}; // HKD material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Curved_RawForged : FST_HKD_Wall_Heavy_Curved_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Curved (Raw Forged)"; // Editor list name
    description = "Curved wall section - raw forged metal appearance. Corner defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallCurvedRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_RawForged_co.paa"}; // Raw Forged texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Curved_RawForged.rvmat"}; // Raw Forged material file
    
    class EventHandlers {}; // Empty event handler class
};

 */
// =========================================================================
// OPEN GATE WALL SECTION BASE CLASS (Open)
// =========================================================================
class FST_HKD_Wall_Heavy_OpenGate_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Open Gate Wall (Base)"; // Internal display name
    description = "A heavy reinforced gate wall section with open passage. Designed for access passages and vehicle throughways. Provides perimeter framing with open movement capability."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_HeavyWall_GateOpen.p3d"; // 3D model file
    mapSize = 6.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo", "Camo1", "Camo2"}; // Textureable selection names
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Default texture (uses Straight wall textures)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Material file (uses Straight wall material)
    
    armor = 800; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_OpenGate_Blank : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (Unpainted)"; // Editor list name
    description = "Gate wall section (open) - unpainted hull plating. Access passage."; // Editor tooltip
    //editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_CIS : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (CIS)"; // Editor list name
    description = "Gate wall section (open) - CIS markings. Access passage."; // Editor tooltip
    //editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_CIS_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // CIS variant textures (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // CIS material files (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_HKD : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (HKD)"; // Editor list name
    description = "Gate wall section (open) - HKD corporate markings. Access passage."; // Editor tooltip
    //editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_HKD_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // HKD variant textures (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // HKD material files (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_Rawforged : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (Raw Forged)"; // Editor list name
    description = "Gate wall section (open) - Raw Forged markings. Access passage."; // Editor tooltip
    //editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_RawForged_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Raw Forged variant textures (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Raw Forged material files (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_DarkMetal : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (Dark Metal)"; // Editor list name
    description = "Gate wall section (open) - dark metallic finish. Access passage."; // Editor tooltip
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_DarkMetal_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Dark Metal variant textures (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Dark Metal material files (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_DarkMetal_CIS : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (Dark Metal - CIS)"; // Editor list name
    description = "Gate wall section (open) - dark metallic finish with CIS markings. Access passage."; // Editor tooltip
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_DarkMetal_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight_CIS_co.paa", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight_co.paa"}; // Dark Metal CIS variant textures (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo1_Straight.rvmat", "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo2_Straight.rvmat"}; // Dark Metal CIS material files (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};


/* // =========================================================================
// GATE WALL SECTION BASE CLASS (Closed)
// =========================================================================
class FST_HKD_Wall_Heavy_Gate_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Gate Wall (Base)"; // Internal display name
    description = "A heavy reinforced gate wall section with closed barrier. Designed for controlled access points and defensive chokepoints. Provides protection against small arms and light explosives."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_Wall_Heavy_Gate.p3d"; // 3D model file
    mapSize = 6.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate.rvmat"}; // Material file
    
    armor = 850; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_Gate_Blank : FST_HKD_Wall_Heavy_Gate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Gate (Unpainted)"; // Editor list name
    description = "Gate wall section (closed) - unpainted hull plating. Access control."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallGateBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Gate_CIS : FST_HKD_Wall_Heavy_Gate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Gate (CIS)"; // Editor list name
    description = "Gate wall section (closed) - CIS markings. Access control."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallGateCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_CIS_co.paa"}; // CIS variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_CIS.rvmat"}; // CIS material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Gate_HKD : FST_HKD_Wall_Heavy_Gate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Gate (HKD)"; // Editor list name
    description = "Gate wall section (closed) - HKD corporate markings. Access control."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallGateHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_HKD_co.paa"}; // HKD variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_HKD.rvmat"}; // HKD material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Gate_RawForged : FST_HKD_Wall_Heavy_Gate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Gate (Raw Forged)"; // Editor list name
    description = "Gate wall section (closed) - raw forged metal appearance. Access control."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallGateRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_RawForged_co.paa"}; // Raw Forged texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Gate_RawForged.rvmat"}; // Raw Forged material file
    
    class EventHandlers {}; // Empty event handler class
};

// =========================================================================
// OPEN GATE WALL SECTION BASE CLASS (Open)
// =========================================================================
class FST_HKD_Wall_Heavy_OpenGate_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Open Gate Wall (Base)"; // Internal display name
    description = "A heavy reinforced gate wall section with open passage. Designed for access passages and vehicle throughways. Provides perimeter framing with open movement capability."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_HeavyWall_GateOpen.p3d"; // 3D model file
    mapSize = 6.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_co.paa"}; // Default texture (uses Straight wall textures)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight.rvmat"}; // Material file (uses Straight wall material)
    
    armor = 800; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_OpenGate_Blank : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (Unpainted)"; // Editor list name
    description = "Gate wall section (open) - unpainted hull plating. Access passage."; // Editor tooltip
    //editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_CIS : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (CIS)"; // Editor list name
    description = "Gate wall section (open) - CIS markings. Access passage."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_CIS_co.paa"}; // CIS variant texture (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_CIS.rvmat"}; // CIS material file (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_OpenGate_HKD : FST_HKD_Wall_Heavy_OpenGate_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Open Gate (HKD)"; // Editor list name
    description = "Gate wall section (open) - HKD corporate markings. Access passage."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallOpenGateHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_HKD_co.paa"}; // HKD variant texture (uses Straight wall)
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Straight_HKD.rvmat"}; // HKD material file (uses Straight wall)
    
    class EventHandlers {}; // Empty event handler class
};

// =========================================================================
// BUNKER WALL SECTION BASE CLASS
// =========================================================================
class FST_HKD_Wall_Heavy_Bunker_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Bunker Wall (Base)"; // Internal display name
    description = "A heavy reinforced bunker wall section with gun emplacements. Designed for elevated defensive positions and tactical firing support. Provides maximum protection and combat effectiveness."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_Wall_Heavy_Bunker.p3d"; // 3D model file
    mapSize = 6.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker.rvmat"}; // Material file
    
    armor = 900; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_Bunker_Blank : FST_HKD_Wall_Heavy_Bunker_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Bunker (Unpainted)"; // Editor list name
    description = "Bunker wall section - unpainted hull plating. Elevated defensive position."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallBunkerBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Bunker_CIS : FST_HKD_Wall_Heavy_Bunker_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Bunker (CIS)"; // Editor list name
    description = "Bunker wall section - CIS markings. Elevated defensive position."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallBunkerCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_CIS_co.paa"}; // CIS variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_CIS.rvmat"}; // CIS material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Bunker_HKD : FST_HKD_Wall_Heavy_Bunker_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Bunker (HKD)"; // Editor list name
    description = "Bunker wall section - HKD corporate markings. Elevated defensive position."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallBunkerHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_HKD_co.paa"}; // HKD variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_HKD.rvmat"}; // HKD material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Bunker_RawForged : FST_HKD_Wall_Heavy_Bunker_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Bunker (Raw Forged)"; // Editor list name
    description = "Bunker wall section - raw forged metal appearance. Elevated defensive position."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallBunkerRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_RawForged_co.paa"}; // Raw Forged texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Bunker_RawForged.rvmat"}; // Raw Forged material file
    
    class EventHandlers {}; // Empty event handler class
};

// =========================================================================
// TOWER WALL SECTION BASE CLASS
// =========================================================================
class FST_HKD_Wall_Heavy_Tower_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Heavy Tower Wall (Base)"; // Internal display name
    description = "A heavy reinforced tower wall section with elevated observation platform. Designed for high-ground defensive superiority and reconnaissance. Provides maximum tactical advantage and firing positions."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\HKD_Wall_Heavy_Tower.p3d"; // 3D model file
    mapSize = 7.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_walls"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower.rvmat"}; // Material file
    
    armor = 950; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};

class FST_HKD_Wall_Heavy_Tower_Blank : FST_HKD_Wall_Heavy_Tower_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Tower (Unpainted)"; // Editor list name
    description = "Tower wall section - unpainted hull plating. Elevated observation and defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallTowerBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Tower_CIS : FST_HKD_Wall_Heavy_Tower_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Tower (CIS)"; // Editor list name
    description = "Tower wall section - CIS markings. Elevated observation and defense."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallTowerCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_CIS_co.paa"}; // CIS variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_CIS.rvmat"}; // CIS material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Tower_HKD : FST_HKD_Wall_Heavy_Tower_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Tower (HKD)"; // Editor list name
    description = "Tower wall section - HKD corporate markings. Elevated observation and defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallTowerHKD.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_HKD_co.paa"}; // HKD variant texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_HKD.rvmat"}; // HKD material file
    
    class EventHandlers {}; // Empty event handler class
};

class FST_HKD_Wall_Heavy_Tower_RawForged : FST_HKD_Wall_Heavy_Tower_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Heavy Wall - Tower (Raw Forged)"; // Editor list name
    description = "Tower wall section - raw forged metal appearance. Elevated observation and defense."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\UI\HKD_UI_WallTowerRawForged.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_RawForged_co.paa"}; // Raw Forged texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\HeavyWalls\Data\Textures\Camo_Tower_RawForged.rvmat"}; // Raw Forged material file
    
    class EventHandlers {}; // Empty event handler class
};

 */