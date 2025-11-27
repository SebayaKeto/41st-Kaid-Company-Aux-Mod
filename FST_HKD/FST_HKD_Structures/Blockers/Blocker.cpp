

// ===================================================================================
// HKD DEFENSIVE FORTIFICATIONS - VEHICLE/INFANTRY BLOCKERS & BARRIERS
// ===================================================================================
// Hoersch-Kessel Driveworks defensive structures: wedge barriers, walls, and fortifications
// Made from battle-hardened armor plating and reinforced materials
// Designed for area denial, vehicle obstacles, and defensive positions
// Supports multi-faction scenarios, custom deployments, and universal compatibility

// =========================================================================
// LARGE WEDGE BARRIER BASE CLASS (Vehicle Deflector)
// =========================================================================
class FST_HKD_Blocker_Large_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Large Wedge Barrier (Base)"; // Internal display name
    description = "A massive, wedge-shaped slab of reinforced armor plating. Designed to force vehicles upward, exposing underbelly. Provides heavy protection against small arms and light cannons."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_Blocker_Large.p3d"; // 3D model file
    mapSize = 4.0; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers"; // Editor subcategory
    
    class Damage // Damage texture configuration
    {
        tex[] = {}; // Damage textures (empty - uses hidden selections)
        mat[] = {}; // Damage materials (empty - uses hidden selections)
    };
    
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo.rvmat"}; // Material file
    
    armor = 600; // Structural durability
    destrType = "DestructBuilding"; // Destruction class type
    
    class DestructionEffects // Visual effects on destruction
    {
    };
};
class FST_HKD_Blocker_Large_Blank : FST_HKD_Blocker_Large_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Large Blocker - Unpainted"; // Editor list name
    description = "Massive wedge blocker - unpainted hull plating. Vehicle deflector."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg"; // Preview image
    
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Large_Default : FST_HKD_Blocker_Large_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Large Blocker - Standard"; // Editor list name
    description = "Massive wedge blocker - HKD markings. Vehicle deflector."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"}; // HKD variant texture
    
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Large_Corporate : FST_HKD_Blocker_Large_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Large Blocker - Corporate"; // Editor list name
    description = "Massive wedge blocker - HKD corporate markings. Vehicle deflector."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"}; // HKD variant texture
    class EventHandlers {}; // Empty event handler class
};
// =========================================================================
// MEDIUM COVER BARRIER BASE CLASS (Infantry Cover)
// =========================================================================
class FST_HKD_Blocker_Medium_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Medium Cover Barrier (Base)"; // Internal display name
    description = "Reinforced cover slab for infantry and unit positioning and area denial."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_Blocker_Medium.p3d"; // 3D model file
    mapSize = 2.0; // Icon size on map (smaller than vehicle blocker)
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers"; // Editor subcategory
    class Damage { tex[] = {}; mat[] = {}; }; // Damage textures/materials
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo.rvmat"}; // Material file
    armor = 300; // Structural durability (lighter than vehicle blocker)
    destrType = "DestructBuilding"; // Destruction class type
    class DestructionEffects {}; // Destruction visual effects
};
class FST_HKD_Blocker_Medium_Blank : FST_HKD_Blocker_Medium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Medium Blocker - Unpainted"; // Editor list name
    description = "Medium blocker - unpainted plating. Infantry positioning."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg"; // Preview image
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Medium_Default : FST_HKD_Blocker_Medium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Medium Blocker - Standard"; // Editor list name
    description = "Medium blocker - HKD markings. Infantry positioning."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"}; // HKD variant texture
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Medium_Corporate : FST_HKD_Blocker_Medium_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Medium Blocker - Corporate"; // Editor list name
    description = "Medium blocker - HKD corporate markings. Infantry/droid positioning."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"}; // HKD variant texture
    class EventHandlers {}; // Empty event handler class
};
// =========================================================================
// ANTI-PERSONNEL SPIKES & LINES (Infantry Deterrent)
// =========================================================================
class FST_HKD_Spike_Single_Base : House_F 
{
    scope = 0;
    author = "Hoersch-Kessel Driveworks";
    displayName = "HKD Anti-Personnel Spike (Base)";
    description = "Single anti-personnel spike. Infantry deterrent.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantrySpike.p3d";
    mapSize = 1.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo.rvmat"};
    armor = 100;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
class FST_HKD_Spike_Single : FST_HKD_Spike_Single_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Anti-Personnel Spike";
    description = "Single anti-personnel spike - standard variant. Infantry deterrent.";
    class EventHandlers {};
};
class FST_HKD_Spike_Line5m : House_F 
{
    scope = 2;
    scopeCurator = 2;
    author = "Hoersch-Kessel Driveworks";
    displayName = "[HKD] Anti-Personnel Spike Line (5m)";
    description = "Five-meter line of anti-personnel spikes - barrier deployment.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantrySpikeFiveM.p3d";
    mapSize = 5.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    armor = 200;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
class FST_HKD_Spike_Line10m : House_F 
{
    scope = 2;
    scopeCurator = 2;
    author = "Hoersch-Kessel Driveworks";
    displayName = "[HKD] Anti-Personnel Spike Line (10m)";
    description = "Ten-meter line of anti-personnel spikes - extended barrier deployment.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantrySpikeTenM.p3d";
    mapSize = 10.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    armor = 400;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
// =========================================================================
// SMALL DEFENSIVE BLOCKER BASE CLASS (Compact Cover)
// =========================================================================
class FST_HKD_Blocker_Small_Base : House_F 
{
    scope = 0; // Hidden base class - not placeable directly
    author = "Hoersch-Kessel Driveworks"; // Asset creator
    displayName = "HKD Small Blocker (Base)"; // Internal display name
    description = "Compact defensive blocker for positioning and light cover. Ideal for quick deployments and smaller positions."; // Editor tooltip
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_Blocker_Small.p3d"; // 3D model file
    mapSize = 1.5; // Icon size on map
    editorCategory = "fst_hkd_edcat"; // Editor category
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers"; // Editor subcategory
    class Damage { tex[] = {}; mat[] = {}; }; // Damage textures/materials
    hiddenSelections[] = {"Camo"}; // Textureable selection name
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"}; // Default texture
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo.rvmat"}; // Material file
    armor = 200; // Structural durability (lighter than medium blocker)
    destrType = "DestructBuilding"; // Destruction class type
    class DestructionEffects {}; // Destruction visual effects
};
class FST_HKD_Blocker_Small_Blank : FST_HKD_Blocker_Small_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Small Blocker - Unpainted"; // Editor list name
    description = "Compact blocker - unpainted hull plating. Light defensive positioning."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg"; // Preview image
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Small_Default : FST_HKD_Blocker_Small_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Small Blocker - Standard"; // Editor list name
    description = "Compact blocker - HKD markings. Light defensive positioning."; // Editor tooltip
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"}; // HKD variant texture
    class EventHandlers {}; // Empty event handler class
};
class FST_HKD_Blocker_Small_Corporate : FST_HKD_Blocker_Small_Base 
{
    scope = 2; // Placeable in editor and visible in-game
    scopeCurator = 2; // Placeable by curator/admin
    displayName = "[HKD] Small Blocker - Corporate"; // Editor list name
    description = "Compact blocker - HKD corporate markings. Light defensive positioning."; // Editor tooltip
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg"; // Preview image
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"}; // HKD variant texture
    class EventHandlers {}; // Empty event handler class
};
// =========================================================================
// ANTI-VEHICLE TANK TRAPS (Vehicle Deterrent)
// =========================================================================
class FST_HKD_Trap_Tank_Base : House_F 
{
    scope = 0;
    author = "Hoersch-Kessel Driveworks";
    displayName = "HKD Anti-Vehicle Tank Trap (Base)";
    description = "HKD anti-vehicle trap for vehicle deterrent and area denial.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_TankTrap.p3d";
    mapSize = 2.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo.rvmat"};
    armor = 400;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
class FST_HKD_Trap_Tank_Blank : FST_HKD_Trap_Tank_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Anti-Vehicle Tank Trap - Unpainted";
    description = "Tank trap - unpainted hull plating. Vehicle deterrent.";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapBlank.jpg";
    class EventHandlers {};
};
class FST_HKD_Trap_Tank_Default : FST_HKD_Trap_Tank_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Anti-Vehicle Tank Trap - Standard";
    description = "Tank trap - HKD markings. Vehicle deterrent";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapCIS.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_CIS_CO.paa"};
    class EventHandlers {};
};
class FST_HKD_Trap_Tank_Corporate : FST_HKD_Trap_Tank_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Anti-Vehicle Tank Trap - Corporate";
    description = "Tank trap - HKD corporate markings. Vehicle deterrent.";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapCompany.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_HKD_co.paa"};
    class EventHandlers {};
};