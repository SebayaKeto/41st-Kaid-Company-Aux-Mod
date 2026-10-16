// =============================================================================
//  BUZZ Low Cell — Higher pitched shots as the cell runs dry
//  Guns are opted in from lowcell_weapons.hpp.
// =============================================================================

#include "lowcell_macros.hpp"


// -----------------------------------------------------------------------------
//  PATCH REGISTRATION
// -----------------------------------------------------------------------------
class CfgPatches {
    class BUZZ_LowCell {
        units[]   = {};
        weapons[] = {};
        requiredVersion = 0.1;
        // Must include the addon of every gun in lowcell_weapons.hpp
        requiredAddons[] = {
            "cba_xeh",
            "FST_DC15AS",
            "FST_DC15AS",
            "FST_DC15AS",
        };
    };
};


// -----------------------------------------------------------------------------
//  SHARED TUNING
// -----------------------------------------------------------------------------
class CfgBUZZ_LowCell {
    shotPitches[]    = {0.97, 0.985, 1.00, 1.015, 1.03};             // ±3%
    lowCellPitches[] = {1.14, 1.17, 1.19, 1.21, 1.23, 1.26};       // +20%, ±5%
    volumeScale      = 1;
};


// -----------------------------------------------------------------------------
//  FUNCTIONS
// -----------------------------------------------------------------------------
class CfgFunctions {
    class BUZZ {
        class LowCell {
            file = "BUZZ_LowMagGunSound\BUZZ_LowCell\functions";
            class lowCellShot { file = "BUZZ_LowMagGunSound\BUZZ_LowCell\functions\fnc_lowCellShot.sqf"; };
            class lowCellDebug { file = "BUZZ_LowMagGunSound\BUZZ_LowCell\functions\fnc_lowCellDebug.sqf"; };
        };
    };
};

class Extended_FiredBIS_EventHandlers {
    class CAManBase {
        BUZZ_LowCell = "_this call BUZZ_fnc_lowCellShot;";
    };
};


// -----------------------------------------------------------------------------
//  WEAPONS
// -----------------------------------------------------------------------------
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;

class CfgWeapons {
    #include "lowcell_weapons.hpp"
};
