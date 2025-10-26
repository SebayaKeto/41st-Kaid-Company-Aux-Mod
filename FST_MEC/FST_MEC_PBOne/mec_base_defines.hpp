/*
    mec_base_ddefines.hpp
    Maldova Engineering Corp. (MEC) - Core Definitions
    
    This file defines constants and path variables used across all MEC
    configuration (.hpp) and scripting (.sqf) files.
*/

// --- CORE FRAMEWORK DEFINITIONS ---
#define MEC_TAG FST_MEC             // Global tag for CfgFunctions (e.g., MEC_fnc_initializeMECPebble)
#define MEC_PREFIX MEC              // Item/Class prefix (e.g., MEC_PB1_Item)
#define MEC_AUTHOR "Maldova Engineering Corp. / FST"

// --- FILE PATH DEFINITIONS (Based on user-specified structure) ---
#define MEC_CORE_PATH FST\FST_MEC\FST_MEC_Core
#define MEC_FUNCTION_PATH MEC_CORE_PATH\functions
#define MEC_ELECTRICITY_PATH MEC_FUNCTION_PATH\electricitysystem
#define MEC_ELECTRICITY_PATH_PPSYSTEM MEC_ELECTRICITY_PATH\MEC_generic_power_management.sqf

// --- LOGISTICAL CONSTANTS (Based on documents) ---
#define MEC_RSU_PEBBLE_MASS 10      // Mass value for the MEC_PB1_Item (kg)
#define MEC_SHIELD_FAILURE_SOUND "Alarm_Red_SoundSet" // Sound class for wall shield failure
#define MEC_BATTERY_CAPACITY 100    // Max charge (100%) for MEC-PB/1 cells

// --- UTILITY ---
#define TRUE 1
#define FALSE 0