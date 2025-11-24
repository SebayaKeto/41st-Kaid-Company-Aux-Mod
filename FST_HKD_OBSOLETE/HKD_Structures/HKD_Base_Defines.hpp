// ===================================================================================
// HOERSCH-KESSEL DRIVE (HKD) COMMON DEFINITIONS
// ===================================================================================
// Author: Maldova Engineering Corp. (Simulated)
// Date: 22 BBY
// Description: Centralized constants, macros, and text for the HKD Faction.

// --- 1. CORE MOD TAGS AND PATHS ---
#define HKD_FULL_NAME "Hoersch-Kessel Drive, Inc. (HKD)"
#define HKD_SHORT_NAME "HKD"
#define HKD_TAG FST_HKD                             
#define HKD_PREFIX "HKD"                            
#define HKD_AUTHOR "Hoersch-Kessel Drive"      

// --- 2. MATERIAL & PRODUCT TIERS ---
// HKD uses naval terminology for its ground assets.
#define HKD_MAT_TYPE_1  "Hull-Plate (Recycled)"
#define HKD_MAT_TYPE_2  "Void-Sealed Alloy"
#define HKD_MAT_TYPE_3  "Capital-Grade Armor"

// --- 3. EDITOR DISPLAY NAMES ---
// Categories
#define HKD_CAT_STRUCTURES "[HKD] Naval Fortifications"
#define HKD_CAT_LOGISTICS  "[HKD] Orbital Logistics"

// Subcategories
#define HKD_SUBCAT_BARRIERS "[HKD] Hull-Plate Barriers"
#define HKD_SUBCAT_TURRETS  "[HKD] Void-Sealed Turrets"
#define HKD_SUBCAT_BLOCKERS "[HKD] Area Denial (Blockers)"

// --- 4. LORE DESCRIPTIONS ---
#define HKD_DESC_BLOCKER "A massive, wedge-shaped slab of recycled starship armor. Designed to force repulsor tanks upward, exposing their underbelly. Immune to small arms and light cannons."
#define HKD_DESC_WALL    "Standard HKD defensive line. Constructed from the cut-down hull plating of obsolete Lucrehulk battleships. Heavy, unshielded, but extremely durable."
#define HKD_DESC_DROP    "Orbital drop capable. This unit features retro-thrusters and a weighted base for kinetic insertion."

// --- 5. SYSTEM CONSTANTS ---
#define HKD_DROP_VAR "HKD_CanBeGravDropped" // The variable checked by the drop scripts to see if an object is eligible for dropping