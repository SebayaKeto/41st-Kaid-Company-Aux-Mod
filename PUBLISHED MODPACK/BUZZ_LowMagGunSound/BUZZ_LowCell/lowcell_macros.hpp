// =============================================================================
//  BUZZ Low Cell — Macros
//  One LOWCELL_n line per gun in lowcell_weapons.hpp, n = number of fire modes.
//  No spaces after the commas in a line: the preprocessor keeps them.
// =============================================================================

// Points the fire mode at a silent sound class. StandardSound is left intact so
// BUZZ_fnc_lowCellShot can read the gun's samples from it.
#define LOWCELL_SILENT_MODE(MODE,MODEPARENT) \
    class MODE: MODEPARENT { \
        sounds[] = {"BUZZ_SilentSound"}; \
        class BUZZ_SilentSound { \
            weaponSoundEffect = ""; \
            closure1[]        = {}; \
            closure2[]        = {}; \
            soundClosure[]    = {}; \
            begin1[]          = {"", 0, 1, 0}; \
            soundBegin[]      = {"begin1", 1}; \
        }; \
    };

#define LOWCELL_1(WEAPON,PARENT,PERCENT,M1,P1) \
    class WEAPON: PARENT { \
        BUZZ_lowCell        = 1; \
        BUZZ_lowCellPercent = PERCENT; \
        LOWCELL_SILENT_MODE(M1,P1) \
    };

#define LOWCELL_2(WEAPON,PARENT,PERCENT,M1,P1,M2,P2) \
    class WEAPON: PARENT { \
        BUZZ_lowCell        = 1; \
        BUZZ_lowCellPercent = PERCENT; \
        LOWCELL_SILENT_MODE(M1,P1) \
        LOWCELL_SILENT_MODE(M2,P2) \
    };

#define LOWCELL_3(WEAPON,PARENT,PERCENT,M1,P1,M2,P2,M3,P3) \
    class WEAPON: PARENT { \
        BUZZ_lowCell        = 1; \
        BUZZ_lowCellPercent = PERCENT; \
        LOWCELL_SILENT_MODE(M1,P1) \
        LOWCELL_SILENT_MODE(M2,P2) \
        LOWCELL_SILENT_MODE(M3,P3) \
    };
