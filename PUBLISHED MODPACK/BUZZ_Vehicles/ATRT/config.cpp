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
//  LAAT/i COMPATIBILITY TABLE
//  Classnames accepted by "Load into LAAT/i". Add new reskins here.
// -----------------------------------------------------------------------------
class CfgBUZZ_ATRT {
    laatiClasses[] = {
        "FST_laati_Turret",
        "FST_laati_mk2",
        "FST_laati_mk2Lights",
        "FST_laati_Turret_Qball",
        "FST_laati_mk2_Qball",
        "FST_laati_mk2Lights_Qball",
        "FST_laati_Turret_Grim",
        "FST_laati_mk2_Grim",
        "FST_laati_mk2Lights_Grim",
        "FST_laati_Turret_Sierra",
        "FST_laati_mk2_Sierra",
        "FST_laati_mk2Lights_Sierra",
        "FST_laati_Turret_Aether",
        "FST_laati_mk2_Aether",
        "FST_laati_mk2Lights_Aether",
        "FST_laati_Turret_Cait",
        "FST_laati_mk2_Cait",
        "FST_laati_mk2Lights_Cait",
        "FST_laati_Turret_Fire",
        "FST_laati_mk2_Fire",
        "FST_laati_mk2Lights_Fire",
        "FST_laati_Turret_Talisman",
        "FST_laati_mk2_Talisman",
        "FST_laati_mk2Lights_Talisman",
        "FST_laati_Turret_Pole",
        "FST_laati_mk2_Pole",
        "FST_laati_mk2Lights_Pole",
        "FST_laati_Turret_Red",
        "FST_laati_mk2_Red",
        "FST_laati_mk2Lights_Red",
        "FST_laati_Turret_Oak",
        "FST_laati_mk2_Oak",
        "FST_laati_mk2Lights_Oak"
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
            class orbitalDropServer  {};   // → BUZZ_fnc_orbitalDropServer,  file fn_orbitalDropServer.sqf
            class orbitalDropInit    { postInit = 1; };   // registers the Zeus module (client, needs ZEN)
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

    // AT-RT spotlight — longer-range clone of FST_Attachment_Light_Beam_White.
    // Built from acc_flashlight directly rather than inherited, since FST's
    // class isn't resolved yet at this point in load order.
    class acc_flashlight;
    class BUZZ_ATRT_Spotlight: acc_flashlight {
        displayName  = "[41st] AT-RT Spotlight";
        scope        = 2;
        scopeArsenal = 2;
        class Iteminfo {
            allowedSlots[] = {801, 701, 901};
            mass           = 4;
            mountAction    = "MountSide";
            scope          = 0;
            type           = 301;
            unmountAction  = "DismountSide";
            class Flashlight {
                ambient[]        = {0.9, 0.81, 0.7};
                color[]          = {180, 160, 130};
                coneFadeCoef     = 30;
                dayLight         = 0;
                direction        = "flash";
                flareMaxDistance = 2000;  // was 500 — visible flare glow range
                flareSize        = 4;
                innerAngle       = 8;
                intensity        = 140;
                irLight          = 0;
                outerAngle       = 25;
                position         = "flash dir";
                scale[]          = {1, 1, 1};
                size             = 1;
                useFlare         = 1;
                volumeShape      = "a3\data_f\VolumeLightFlashlight.p3d";
                class Attenuation {
                    constant       = 0.2;
                    hardLimitEnd   = 2000;  // was 540 — absolute max beam distance
                    hardLimitStart = 120;   // was 27 — push full brightness out further too
                    linear         = 0.2;
                    quadratic      = 0.2;
                    start          = 20;
                };
            };
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
            // PointerSlot whitelist — FST_T15's own list doesn't know about our
            // custom BUZZ_ATRT_Spotlight, so LinkedItems rejects it ("item does
            // not match to this weapon!") without this override.
            class PointerSlot: PointerSlot {
                compatibleItems[] = {
                    "BUZZ_ATRT_Spotlight",
                };
            };
        };

        // Pre-attached light module (LinkedItems, not linkedItems[] — same name, can't coexist).
        class LinkedItems {
            class LinkedItemsAcc {
                slot = "PointerSlot";
                item = "BUZZ_ATRT_Spotlight";
            };
        };

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

        // ACE Dragging — decouples carry/drag from upstream 3AS_Small_Box_9_Black_Prop's mass.
        ace_dragging_canDrag           = 1;
        ace_dragging_dragPosition[]    = {0, 1.2, 0};
        ace_dragging_dragDirection     = 0;
        ace_dragging_ignoreWeight      = 1;

        ace_dragging_canCarry          = 1;
        ace_dragging_carryPosition[]   = {0, 1.2, 0};
        ace_dragging_carryDirection    = 0;
        ace_dragging_ignoreWeightCarry = 1;

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

        // Baseline magazine load — guarantees non-empty stock regardless of spawn method.
        class TransportMagazines {
            class _BUZZ_ATRT_T15ReserveMag {
                magazine = "BUZZ_ATRT_T15ReserveMag";
                count    = 16;
            };
        };

        class EventHandlers {
            init = "(_this select 0) call compile preprocessFileLineNumbers '\BUZZ_Vehicles\ATRT\scripts\reserve_supply_init.sqf';";
        };
    };
};