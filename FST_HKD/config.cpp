// Hoersch-Kessel Driveworks Core Config
// Main configuration entry point for the HKD addon

#include "hkd_defines.hpp"

class CfgPatches
{
    class fst_hkd
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {};
        author = HKD_NAME;
        version = HKD_VERSION;
    };
};
class CfgEditorCategories
{
    class fst_hkd_edcat
    {
        displayName = "HKD - Hoersch-Kessel Driveworks";
    };
};
class CfgEditorSubcategories
{
    // Droids
    class fst_hkd_edsubcat_droids_battle
    {
        displayName = "Droids - Battle";
    };
    class fst_hkd_edsubcat_droids_support
    {
        displayName = "Droids - Support";
    };
    class fst_hkd_edsubcat_droids_special
    {
        displayName = "Droids - Special";
    };
    
    // Ground Vehicles
    class fst_hkd_edsubcat_vehicles_light
    {
        displayName = "Vehicles - Light";
    };
    class fst_hkd_edsubcat_vehicles_armored
    {
        displayName = "Vehicles - Armored";
    };
    class fst_hkd_edsubcat_vehicles_heavy
    {
        displayName = "Vehicles - Heavy";
    };
    class fst_hkd_edsubcat_vehicles_artillery
    {
        displayName = "Vehicles - Artillery";
    };
    
    // Aircraft
    class fst_hkd_edsubcat_aircraft_fighters
    {
        displayName = "Aircraft - Fighters";
    };
    class fst_hkd_edsubcat_aircraft_bombers
    {
        displayName = "Aircraft - Bombers";
    };
    class fst_hkd_edsubcat_aircraft_transport
    {
        displayName = "Aircraft - Transport";
    };
    class fst_hkd_edsubcat_aircraft_gunship
    {
        displayName = "Aircraft - Gunships";
    };
    
    // Turrets
    class fst_hkd_edsubcat_turrets_light
    {
        displayName = "Turrets - Light";
    };
    class fst_hkd_edsubcat_turrets_heavy
    {
        displayName = "Turrets - Heavy";
    };
    class fst_hkd_edsubcat_turrets_aa
    {
        displayName = "Turrets - Anti-Air";
    };
    
    // Structures - Fortifications
    class fst_hkd_edsubcat_structures_fortifications
    {
        displayName = "Structures - Fortifications";
    };
    class fst_hkd_edsubcat_structures_fortifications_walls
    {
        displayName = "Structures - Fortifications - Walls";
    };
    class fst_hkd_edsubcat_structures_fortifications_barriers
    {
        displayName = "Structures - Fortifications - Barriers";
    };
    class fst_hkd_edsubcat_structures_fortifications_bunkers
    {
        displayName = "Structures - Fortifications - Bunkers";
    };
    class fst_hkd_edsubcat_structures_fortifications_gates
    {
        displayName = "Structures - Fortifications - Gates";
    };
    
    // Structures - Buildings
    class fst_hkd_edsubcat_structures_buildings
    {
        displayName = "Structures - Buildings";
    };
    class fst_hkd_edsubcat_structures_buildings_industrial
    {
        displayName = "Structures - Buildings - Industrial";
    };
    class fst_hkd_edsubcat_structures_buildings_command
    {
        displayName = "Structures - Buildings - Command";
    };
    class fst_hkd_edsubcat_structures_buildings_residential
    {
        displayName = "Structures - Buildings - Residential";
    };
    class fst_hkd_edsubcat_structures_buildings_storage
    {
        displayName = "Structures - Buildings - Storage";
    };
    class fst_hkd_edsubcat_structures_buildings_medical
    {
        displayName = "Structures - Buildings - Medical";
    };
    class fst_hkd_edsubcat_structures_buildings_research
    {
        displayName = "Structures - Buildings - Research";
    };
    
    // Structures - Props & Details
    class fst_hkd_edsubcat_structures_props
    {
        displayName = "Structures - Props";
    };
    class fst_hkd_edsubcat_structures_props_crates
    {
        displayName = "Structures - Props - Crates";
    };
    class fst_hkd_edsubcat_structures_props_containers
    {
        displayName = "Structures - Props - Containers";
    };
    class fst_hkd_edsubcat_structures_props_machinery
    {
        displayName = "Structures - Props - Machinery";
    };
    class fst_hkd_edsubcat_structures_props_debris
    {
        displayName = "Structures - Props - Debris";
    };
    class fst_hkd_edsubcat_structures_props_furniture
    {
        displayName = "Structures - Props - Furniture";
    };
    class fst_hkd_edsubcat_structures_props_signs
    {
        displayName = "Structures - Props - Signs";
    };
    
    // Weapons
    class fst_hkd_edsubcat_weapons_rifles
    {
        displayName = "Weapons - Rifles";
    };
    class fst_hkd_edsubcat_weapons_cannons
    {
        displayName = "Weapons - Cannons";
    };
    class fst_hkd_edsubcat_weapons_missiles
    {
        displayName = "Weapons - Missiles";
    };
    class fst_hkd_edsubcat_weapons_special
    {
        displayName = "Weapons - Special";
    };
    
    // Equipment & Items
    class fst_hkd_edsubcat_equipment_armor
    {
        displayName = "Equipment - Armor";
    };
    class fst_hkd_edsubcat_equipment_tools
    {
        displayName = "Equipment - Tools";
    };
    class fst_hkd_edsubcat_equipment_electronics
    {
        displayName = "Equipment - Electronics";
    };
};

// Include marker definitions
#include "hkd_markers.hpp"

// ============================================================================
// MAP COLOR SCHEMES
// ============================================================================
class CfgFactionColors
{
    class HKD_Primary
    {
        displayName = "HKD - Primary";
        color[] = {0.2, 0.8, 0.2};
    };
    
    class HKD_Secondary
    {
        displayName = "HKD - Secondary";
        color[] = {0.2, 0.6, 1.0};
    };
    
    class HKD_Accent
    {
        displayName = "HKD - Accent";
        color[] = {0.8, 0.5, 0.2};
    };
    
    class HKD_Warning
    {
        displayName = "HKD - Warning";
        color[] = {0.8, 0.2, 0.2};
    };
    
    class HKD_Neutral
    {
        displayName = "HKD - Neutral";
        color[] = {0.5, 0.5, 0.5};
    };
    
    class HKD_Highlight
    {
        displayName = "HKD - Highlight";
        color[] = {0.9, 0.8, 0.1};
    };
};

// ============================================================================
// CUSTOM MAP COLORS
// ============================================================================
class CfgFactionMarkerColors
{
    class HKD_Corporate
    {
        displayName = "HKD - Corporate";
        side = "CIVILIAN";
        defaultColor[] = {0.2, 0.8, 0.2, 1.0};
        defaultIcon = "\A3\ui_f\data\map\markers\civilian\civilian_ca.paa";
    };
    
    class HKD_Military
    {
        displayName = "HKD - Military";
        side = "EAST";
        defaultColor[] = {0.8, 0.2, 0.2, 1.0};
        defaultIcon = "\A3\ui_f\data\map\markers\military\military_ca.paa";
    };
    
    class HKD_Research
    {
        displayName = "HKD - Research";
        side = "CIVILIAN";
        defaultColor[] = {0.2, 0.6, 1.0, 1.0};
        defaultIcon = "\A3\ui_f\data\map\markers\military\installation_ca.paa";
    };
};