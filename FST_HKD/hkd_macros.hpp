// HKD Asset Creation Macros
// Simplified macros for defining common asset types

#ifndef __HKD_MACROS_HPP__
#define __HKD_MACROS_HPP__

// ============================================================================
// VEHICLE MACROS
// ============================================================================

#define CREATE_HKD_VEHICLE(CLASS_NAME, DISPLAY_NAME, MODEL_PATH, TEXTURE_PATH, VEHICLE_CLASS) \
    class CLASS_NAME \
    { \
        scope = 2; \
        displayName = DISPLAY_NAME; \
        model = MODEL_PATH; \
        vehicleClass = VEHICLE_CLASS; \
        hiddenSelections[] = {"camo"}; \
        hiddenSelectionsTextures[] = {TEXTURE_PATH}; \
    }

// ============================================================================
// STRUCTURE MACROS
// ============================================================================

#define CREATE_HKD_STRUCTURE(CLASS_NAME, DISPLAY_NAME, MODEL_PATH, TEXTURE_PATH) \
    class CLASS_NAME \
    { \
        scope = 2; \
        displayName = DISPLAY_NAME; \
        model = MODEL_PATH; \
        vehicleClass = "Fortifications"; \
        hiddenSelections[] = {"camo"}; \
        hiddenSelectionsTextures[] = {TEXTURE_PATH}; \
    }

// ============================================================================
// EQUIPMENT/ITEM MACROS
// ============================================================================

#define CREATE_HKD_ITEM(CLASS_NAME, DISPLAY_NAME, TYPE) \
    class CLASS_NAME \
    { \
        scope = 2; \
        displayName = DISPLAY_NAME; \
        type = TYPE; \
    }

// ============================================================================
// WEAPON MACROS
// ============================================================================

#define CREATE_HKD_WEAPON(CLASS_NAME, DISPLAY_NAME, MODEL_PATH) \
    class CLASS_NAME \
    { \
        scope = 2; \
        displayName = DISPLAY_NAME; \
        model = MODEL_PATH; \
    }

#endif
