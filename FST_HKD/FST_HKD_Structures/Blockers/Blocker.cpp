

// ===================================================================================
// HKD BLOCKERS - VEHICLE/INFANTRY BLOCKERS
// ===================================================================================
// Massive wedge-shaped barriers made from recycled starship armor
// Designed for area denial and forcing vehicles upward to expose underside

// =========================================================================
// BASE BLOCKER CLASS
// =========================================================================
class FST_HKD_VehBlocker_Base : House_F 
{
    scope = 0;
    author = "Hoersch-Kessel Driveworks";
    displayName = "HKD Blocker (Base)";
    description = "A massive, wedge-shaped slab of recycled starship armor. Designed to force repulsor tanks upward, exposing their underbelly. Immune to small arms and light cannons.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_VehicleBlocker.p3d";
    mapSize = 4.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    
    class Damage 
    {
        tex[] = {};
        mat[] = {};
    };
    
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo.rvmat"};
    
    armor = 600;
    destrType = "DestructBuilding";
    
    class DestructionEffects 
    {
    };
};
class FST_HKD_VehBlocker_Blank : FST_HKD_VehBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Blocker - Blank";
    description = "Massive wedge-shaped barrier (Unpainted Hull Plating)";
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg";
    
    class EventHandlers {};
};
class FST_HKD_VehBlocker_CIS : FST_HKD_VehBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Blocker - CIS";
    description = "Massive wedge-shaped barrier (CIS Markings)";
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg";
    hiddenSelectionsTextures[] = {"\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"};
    
    class EventHandlers {};
};
class FST_HKD_VehBlocker_HKD : FST_HKD_VehBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Vehicle Blocker - HKD";
    description = "Massive wedge-shaped barrier (HKD Corporate Markings)";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"};
    class EventHandlers {};
};
class FST_HKD_InfBlocker_Base : House_F 
{
    scope = 0;
    author = "Hoersch-Kessel Driveworks";
    displayName = "HKD Infantry Blocker (Base)";
    description = "A reinforced slab designed for infantry cover and area denial.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantryBlocker.p3d";
    mapSize = 2.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    class Damage { tex[] = {}; mat[] = {}; };
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_Blank_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo.rvmat"};
    armor = 300;
    destrType = "DestructBuilding";
    class DestructionEffects {};
};
class FST_HKD_InfBlocker_Blank : FST_HKD_InfBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Infantry Blocker - Blank";
    description = "Infantry cover (Unpainted Hull Plating)";
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeBlank.jpg";
    class EventHandlers {};
};
class FST_HKD_InfBlocker_CIS : FST_HKD_InfBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Infantry Blocker - CIS";
    description = "Infantry cover (CIS Markings)";
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCIS.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_CIS_co.paa"};
    class EventHandlers {};
};
class FST_HKD_InfBlocker_HKD : FST_HKD_InfBlocker_Base 
{
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Infantry Blocker - HKD";
    description = "Infantry cover (HKD Corporate Markings)";
    editorPreview = "\FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_BlockerLargeCompany.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\VehicleBlockers\Camo_HKD_co.paa"};
    class EventHandlers {};
};
// =========================================================================
// INFANTRY SPIKES
// =========================================================================
class FST_HKD_InfantrySpike : House_F {
    scope = 2;
    scopeCurator = 2;
    author = "Hoersch-Kessel Driveworks";
    displayName = "[HKD] Infantry Spike";
    description = "Anti-personnel spike for area denial.";
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
class FST_HKD_InfantrySpikeLineFiveM : House_F {
    scope = 2;
    scopeCurator = 2;
    author = "Hoersch-Kessel Driveworks";
    displayName = "[HKD] Infantry Spike Line (5m)";
    description = "Five-meter line of anti-personnel spikes.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantrySpikeFiveM.p3d";
    mapSize = 5.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo.rvmat"};
    armor = 100;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
class FST_HKD_InfantrySpikeLineTenM : House_F {
    scope = 2;
    scopeCurator = 2;
    author = "Hoersch-Kessel Driveworks";
    displayName = "[HKD] Infantry Spike Line (10m)";
    description = "Ten-meter line of anti-personnel spikes.";
    model = "FST\FST_HKD\FST_HKD_Structures\Blockers\HKD_InfantrySpikeTenM.p3d";
    mapSize = 10.0;
    editorCategory = "fst_hkd_edcat";
    editorSubcategory = "fst_hkd_edsubcat_structures_fortifications_barriers";
    hiddenSelections[] = {"Camo"};
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_co.paa"};
    hiddenSelectionsMaterials[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo.rvmat"};
    armor = 100;
    destrType = "DestructBuilding";
    class EventHandlers {};
};
// =========================================================================
// TANK TRAP BLOCKERS (3 VARIANTS)
// =========================================================================
class FST_HKD_TankTrap_Base : House_F {
    scope = 0;
    author = "Hoersch-Kessel Driveworks";
    displayName = "HKD Tank Trap (Base)";
    description = "Anti-vehicle tank trap for area denial.";
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
class FST_HKD_TankTrap_Blank : FST_HKD_TankTrap_Base {
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Tank Trap - Blank";
    description = "Tank trap (Unpainted Hull Plating)";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapBlank.jpg";
    class EventHandlers {};
};
class FST_HKD_TankTrap_CIS : FST_HKD_TankTrap_Base {
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Tank Trap - CIS";
    description = "Tank trap (CIS Markings)";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapCIS.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_CIS_CO.paa"};
    class EventHandlers {};
};
class FST_HKD_TankTrap_HKD : FST_HKD_TankTrap_Base {
    scope = 2;
    scopeCurator = 2;
    displayName = "[HKD] Tank Trap - HKD";
    description = "Tank trap (HKD Corporate Markings)";
    editorPreview = "FST\FST_HKD\FST_HKD_Structures\Blockers\Data\UI\HKD_UI_TankTrapCompany.jpg";
    hiddenSelectionsTextures[] = {"FST\FST_HKD\FST_HKD_Structures\Blockers\Data\Textures\TankTraps\Camo_HKD_co.paa"};
    class EventHandlers {};
};