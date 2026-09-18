// =============================================================================
//  BUZZ AT-RT — 41st Elite Corps Walker
//
//  DEPENDENCIES:
//    - 3AS mod       (provides 3AS_ATRT.p3d model, 3AS_9999Rnd_ATRT_Mag ammo,
//                     3AS_ATRT_Collision class)
//    - FST_ATRT mod  (provides FST_ATRT vehicle base + FST_ATRT_Weapon_F)
//    - FST_T15_AT    (provides FST_T15 weapon base)
// =============================================================================


// -----------------------------------------------------------------------------
//  PATCH REGISTRATION
// -----------------------------------------------------------------------------
class CfgPatches {
    class BUZZ_ATRT {
        units[]   = {"BUZZ_ATRT", "BUZZ_ATRT_AmmoBearer", "BUZZ_ATRT_TransportCrate", "BUZZ_ATRT_ReserveCrate"};
        weapons[] = {"BUZZ_ATRT_T15", "BUZZ_ATRT_T15_Bearer"};
        requiredVersion = 0.1;
        requiredAddons[] = {
            "A3_Data_F",
            "A3_Characters_F",
            "3AS_ATRT",
            "3AS_Weapons",
            "FST_ATRT",
            "FST_T15_AT"
        };
    };
};


// -----------------------------------------------------------------------------
//  SERVER FUNCTIONS
// -----------------------------------------------------------------------------
class CfgFunctions {
    class BUZZ {
        class ATRT {
            file = "\BUZZ_Vehicles\ATRT\scripts";
            class packServer        {};   // → BUZZ_fnc_packServer,        file fn_packServer.sqf
            class unpackServer      {};   // → BUZZ_fnc_unpackServer,      file fn_unpackServer.sqf
            class resyncBoxServer    {};   // → BUZZ_fnc_resyncBoxServer,    file fn_resyncBoxServer.sqf
            class laatiLoadServer    {};   // → BUZZ_fnc_laatiLoadServer,    file fn_laatiLoadServer.sqf
            class laatiLoadAnim      {};   // → BUZZ_fnc_laatiLoadAnim,      file fn_laatiLoadAnim.sqf
            class laatiDeployServer  {};   // → BUZZ_fnc_laatiDeployServer,  file fn_laatiDeployServer.sqf
            class laatiAutoMount     {};   // → BUZZ_fnc_laatiAutoMount,     file fn_laatiAutoMount.sqf
            class laatiInstallDeploy {};   // → BUZZ_fnc_laatiInstallDeploy, file fn_laatiInstallDeploy.sqf
            class laatiDeployAction  {};   // → BUZZ_fnc_laatiDeployAction,  file fn_laatiDeployAction.sqf
        };
    };
};


// -----------------------------------------------------------------------------
//  AMMO
// -----------------------------------------------------------------------------
class CfgAmmo {
    class FST_blasterbolt;

    // ATRT-specific bolt
    class BUZZ_ATRT_T15Bolt : FST_blasterbolt {
        hit              = 100;
        indirectHit      = 5;
        indirectHitRange = 3.0;
        caliber          = 10.2;
        // Component-distribution blast
        explosive        = 1;
        timetolive       = 5;
        coefGravity      = 0.01;
    };
};


// -----------------------------------------------------------------------------
//  RECOIL
// -----------------------------------------------------------------------------
class CfgRecoils {
    class BUZZ_recoilZero {
        muzzleImpulse[] = {0, 0};
        temporary[]     = {0, 0};
        permanent[]     = {0, 0};
    };
};


// -----------------------------------------------------------------------------
//  FACTION
// -----------------------------------------------------------------------------
class CfgFactionClasses {
    class BUZZ {
        displayName = "Bees' Testing Units";
        priority    = 2;
        side        = 1;
        icon        = "";
    };
};


// -----------------------------------------------------------------------------
//  EDITOR CATEGORY + SUBCATEGORY
//  Explicit editorCategory required
// -----------------------------------------------------------------------------
class CfgEditorCategories {
    class BUZZ_Vehicles {
        displayName = "Walkers";
    };
};

class CfgEditorSubcategories {
    class BUZZ_Vehicles {
        displayName = "Walkers";
    };
};


// -----------------------------------------------------------------------------
//  MAGAZINE
// -----------------------------------------------------------------------------
class CfgMagazines {
    class FST_thermal_coil_LP_Blue;

    // Equipped magazine (do not touch)
    class BUZZ_ATRT_T15Mag: FST_thermal_coil_LP_Blue {
        displayName = "[41st] DO NOT TOUCH";
        count       = 9999;  // Prevents engine ejection
        ammo        = "BUZZ_ATRT_T15Bolt";
    };

    // Cosmetic reserve-ammo clone
    class BUZZ_ATRT_T15ReserveMag: BUZZ_ATRT_T15Mag {
        displayName = "[41st] AT-RT Power Cells";
    };
};


// -----------------------------------------------------------------------------
//  WEAPON
// -----------------------------------------------------------------------------
class Mode_FullAuto;
class SlotInfo;
class CowsSlot;
class MuzzleSlot;
class PointerSlot;
class UnderBarrelSlot;

class CfgWeapons {
    class FST_T15;
    class WeaponSlotsInfo;

    // Cargo capacity patch
    class ItemCore;
    class FST_ATRT_Base: ItemCore {
        class ItemInfo {
            containerClass = "Supply100";
        };
    };

    class BUZZ_ATRT_T15: FST_T15 {
        displayName = "[41st] AT-RT Cannon";
        author      = "BEES";
        model       = "3AS\ATRT\Weapon\3AS_ATRT_Weapon_f.p3d";
        selectionFireAnim = "zasleh";
        recoil            = "BUZZ_recoilZero";
        recoilProne       = "BUZZ_recoilZero";
        inertia           = 0;
        // Ballistic crosshair
        cursorAim         = "gl";
        cursor            = "EmptyCursor";
        cursorAimOn       = "CursorAimOn";
        magazines[] = {"BUZZ_ATRT_T15Mag"};
        muzzles[]   = {"this"};

        class WeaponSlotsInfo: WeaponSlotsInfo {
            class CowsSlot: CowsSlot {
                linkProxy         = "\A3\data_f\proxies\weapon_slots\TOP";
                compatibleItems[] = {};
            };
        };
        linkedItems[] = {};

        modes[] = {"FullAuto"};

        class FullAuto: Mode_FullAuto {
            sounds[] = {"StandardSound"};

            class BaseSoundModeType {
                weaponSoundEffect = "";
                closure1[]        = {};
                closure2[]        = {};
                soundClosure[]    = {};
            };

            class StandardSound: BaseSoundModeType {
                weaponSoundEffect = "";
                begin1[] = {"\41st_Weapons\T15\Data\t15v1 2-177.ogg", 1,    1,     1800};
                begin2[] = {"\41st_Weapons\T15\Data\t15v1 2-177.ogg", 1.25, 1.015, 1800};
                begin3[] = {"\41st_Weapons\T15\Data\t15v1 2-177.ogg", 1.25, 0.985, 1800};
                begin4[] = {"\41st_Weapons\T15\Data\t15v1 2-177.ogg", 1.25, 1.010, 1800};
                begin5[] = {"\41st_Weapons\T15\Data\t15v1 2-177.ogg", 1.25, 0.995, 1800};
                soundBegin[] = {"begin1",0.20,"begin2",0.20,"begin3",0.20,"begin4",0.20,"begin5",0.20};
            };

            reloadTime = 0.2;
            dispersion = 0.001;

            minRange       = 2;     minRangeProbab = 0.80;
            midRange       = 500;   midRangeProbab = 0.75;
            maxRange       = 3000;  maxRangeProbab = 0.20;

            aiDispersionCoefY = 6;
            aiDispersionCoefX = 4;
        };
    };

    // Deactivated weapon variant
    class BUZZ_ATRT_T15_Bearer: BUZZ_ATRT_T15 {
        displayName = "T-15 Heavy Blaster (Deactivated)";
        magazines[] = {};
    };
};


// -----------------------------------------------------------------------------
//  VEHICLE
// -----------------------------------------------------------------------------
class CfgVehicles {
    class FST_ATRT;
    class 3AS_Small_Box_9_Black_Prop;
    class 3AS_Supply_Large_Orange_Prop;

    class BUZZ_ATRT: FST_ATRT {
        author      = "BEES";
        model       = "\3AS\ATRT\3AS_ATRT.p3d";
        displayName = "[41st] AT-RT (Armed)";

        // Global init override
        class EventHandlers {
            init = "(_this select 0) call compile preprocessFileLineNumbers '\BUZZ_Vehicles\ATRT\scripts\init.sqf';";
        };
        scope             = 2;
        scopeCurator      = 2;
        faction           = "BUZZ";
        editorCategory    = "BUZZ_Vehicles";
        editorSubcategory = "BUZZ_Vehicles";
        crew              = "";

        // Restore uniform container
        uniformClass = "FST_ATRT_Uniform";
        nakedUniform = "FST_ATRT_Uniform";

        maxSpeed         = 60;
        limitedSpeedCoef = 1.0;
        runSpeedScale    = 2.33;
        sprintSpeedScale = 1.40;
        showHMD          = 1;

        ace_captives_canBeRestrained = 0;

        // Explosion knockdown resistance
        explosionShielding = 6;

        // ACE Medical opt-out
        ace_medical_enabled           = 0;
        ace_medical_isAdvancedMedical = 0;

        weapons[]     = {"BUZZ_ATRT_T15"};
        magazines[]   = {"BUZZ_ATRT_T15Mag"};
        linkedItems[] = {"FST_NVG_Invisible", "ItemMap", "ItemGPS"};

        // Supply-box magazine count
        BUZZ_crateMagCount = 3;

        class textureSources {
            class Default {
                displayName = "Default";
                author      = "BEES";
                textures[]  = {"BUZZ_Vehicles\ATRT\Data\BUZZ_ATRT_CO.paa"};
                factions[]  = {};
            };
        };

        textureList[] = {"Default", 1};
    };

    // Unarmed ammo-bearer variant
    class BUZZ_ATRT_AmmoBearer : BUZZ_ATRT {
        displayName = "[41st] AT-RT Ammo Bearer (Unarmed)";
        weapons[]   = {"BUZZ_ATRT_T15_Bearer"};
        magazines[] = {};
        BUZZ_crateMagCount = 12;
    };

    class BUZZ_ATRT_TransportCrate : 3AS_Small_Box_9_Black_Prop {
        author            = "BEES";
        displayName       = "[41st] AT-RT Transport Crate";
        scope             = 2;
        scopeCurator      = 2;
        faction           = "BUZZ";
        editorCategory    = "BUZZ_Vehicles";
        editorSubcategory = "BUZZ_Vehicles";
        ace_cargo_size    = 1;

        class EventHandlers {
            init = "(_this select 0) call compile preprocessFileLineNumbers '\BUZZ_Vehicles\ATRT\scripts\crate_init.sqf';";
        };
    };

    // Standalone reserve-ammo supply
    class BUZZ_ATRT_ReserveCrate : 3AS_Supply_Large_Orange_Prop {
        author            = "BEES";
        displayName       = "[41st] AT-RT Reserve Supply";
        scope             = 2;
        scopeCurator      = 2;
        faction           = "BUZZ";
        editorCategory    = "BUZZ_Vehicles";
        editorSubcategory = "BUZZ_Vehicles";
        hiddenSelectionsTextures[] = {"BUZZ_Vehicles\ATRT\Data\wyrwulf_supply_large_CO.paa"};

        class EventHandlers {
            init = "(_this select 0) call compile preprocessFileLineNumbers '\BUZZ_Vehicles\ATRT\scripts\reserve_supply_init.sqf';";
        };
    };
};