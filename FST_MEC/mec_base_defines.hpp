// --- 1. CORE MOD TAGS AND PATHS ---
#define MEC_FULL_NAME "Maldova Engineering Corporation (MEC)"
#define MEC_SHORT_NAME "MEC"
#define MEC_TAG FST_MEC                             // The CfgFunctions Tag (e.g., MEC_TAG_fnc_...)
#define MEC_TAG_POWERSYSTEM "MEC_PowerSystem"       // Tag for Power System Functions
#define MEC_PREFIX "MEC"                            // General Prefix for Classnames (e.g., MEC_PB1_Item)
#define MEC_AUTHOR "Maldova Engineering Corp."      // Author/Manufacturer Tag
#define MEC_FUNCTION_PATH FST\FST_MEC\FST_MEC_Core\functions // Base path for CfgFunctions

// --- 2. LOGISTICAL AND STRUCTURAL CONSTANTS ---
#define MEC_RSU_PEBBLE_MASS 0.5                     // Mass of the MEC-PB/1 'Utility Pebble' (0.5 kg)
#define MEC_RSU_PULSE_MASS 1000                     // Mass of the MEC-P1 Pulse Cell (1000 kg/1 RSU Factor)
#define MEC_RSU_DOCK_MASS 150                       // Mass of the MEC-CD/P Charging Dock (150 kg)

// --- 3. POWER SYSTEM DEFAULT VALUES AND LOGIC ---
#define MEC_SUPPLIER_SEARCH_RADIUS 15               // Max search distance for a Consumer to find a Supplier (meters)
#define MEC_MIN_SHIELD_DMG 0.1                      // Minimum damage required to trigger shield effect

#define MEC_POWER_DEFAULT_MAX_CHARGE 10000          // Default Max Charge for Walls/Cells
#define MEC_POWER_DEFAULT_INITIAL_CHARGE 10000      // Default Starting Charge
#define MEC_POWER_DEFAULT_CHARGE_RATE 200           // Default Consumer Draw Rate (Units/Sec)
#define MEC_POWER_DEFAULT_SUPPLIER_RATE 200         // Default Supplier Output Rate (Units/Sec)

#define MEC_WALL_RESERVE_CAPACITY 5000              // Default internal capacity for the Wall's Reserve Cell
#define MEC_PULSE_CHARGE_RATE_MAX 500               // Max theoretical output rate for the MEC-P1

// --- 4. CATEGORIES AND UI ---
#define MEC_TAG_MECSYSTEMS "MEC Systems"            // Category for Modules in the Editor
#define MEC_ICON_PATH FST\FST_MEC\ui\icons\mec_icon // Base path for custom PAA icons

// --- 5. POWER SYSTEM TYPES (For Compatibility Checks) ---
// Used by MEC_PowerSystem_SupplierType and MEC_PowerSystem_Type attributes
#define MEC_TYPE_FUSION_CELL "FusionCell"           // Primary Type for MEC-P1 Pulse Cell (Supplier)
#define MEC_TYPE_BATTERY_CELL "BatteryCell"         //(Supplier)
#define MEC_TYPE_FUSION_CELL "FusionCell"           //(Supplier)
#define MEC_TYPE_HYPERMATTER_CELL "HypermatterCell" //(Supplier)
#define MEC_TYPE_RESERVE_CELL "ReserveCell"         // Internal, non-removable battery in walls (Supplier)
#define MEC_TYPE_FLUID_TANK "FluidTank"             // For Liquid Containment Unit (LCU-3) logic
#define MEC_TYPE_WALL_SHIELD "WallShield"           // Primary Type for Wall Shield Systems (Consumer)
#define MEC_TYPE_DOCK "ChargingDock"                // Primary Type for Charging Docks (Consumer)
#define MEC_TYPE_PEBBLE "UtilityPebble"             // Primary Type for MEC-PB/1 (Battery/Supplier)

// --- 6. STRUCTURAL AND ASSET TYPES ---
#define MEC_WALL_LIGHT "SW_LB_WALL"                 // Light Barrier Classification
#define MEC_WALL_MEDIUM "SW_MB_WALL"                // Medium Barrier Classification
#define MEC_WALL_HEAVY "SW_HB_WALL"                 // Heavy Barrier Classification