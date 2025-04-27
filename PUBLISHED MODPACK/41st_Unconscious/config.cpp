class CfgPatches {
    class FST_Unconscious {
        requiredAddons[] = {
            "cba_main",
            "ace_common",
            "ace_medical",
            "ace_medical_feedback",
            "acearcade_arcadeunconscious"
        };
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
    };
};

class Extended_PostInit_EventHandlers {
    class mymod_override {
        init = "";
    };
};

class CfgFunctions {
    class acearcade_arcadeunconscious {
        class Functions {
            class unconsciousRadio {
                file = "\41st_Unconscious\functions\fnc_unconsciousRadio.sqf";
            };
        };
    };
};