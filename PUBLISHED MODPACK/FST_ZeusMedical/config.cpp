// FST_ZeusMedical -- Zeus tools for staging ACE medical scenes on stock ACE (no medical overhaul).
// Zeus modules (Zen, category "41st Medical"): Wound Casualty, Set Blood Volume, Set Pain, Casualty Scenario,
// Cardiac Arrest, Plot Armor, Spawn Wounded Trooper. Everything runs through ACE's public medical functions and
// events on the machine where the unit is local (CBA target events), so HC- and player-owned units work.

class CfgPatches {
    class FST_ZeusMedical {
        name = "FST Zeus Medical";
        author = "41st Elite Corps";
        url = "";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_settings", "ace_medical", "ace_medical_statemachine", "ace_medical_treatment"};
        version = "1.0.2";
    };
};

class CfgFunctions {
    class FST_zeusMed {
        tag = "FST_zeusMed";
        class main {
            file = "FST_ZeusMedical\functions";
            class registerModules {};
            class unitFromModule {};
            class applyLocal {};
            class plotArmorLocal {};
            class plotArmorTick {};
            class plotArmorRestore {};
            class scenarios {};
            class spawnCasualty {};
        };
    };
};

class Extended_PreInit_EventHandlers {
    class FST_ZeusMedical {
        init = "call compile preprocessFileLineNumbers 'FST_ZeusMedical\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class FST_ZeusMedical {
        init = "call compile preprocessFileLineNumbers 'FST_ZeusMedical\XEH_postInit.sqf'";
    };
};
