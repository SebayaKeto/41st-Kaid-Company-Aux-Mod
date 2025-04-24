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
        init = "call compile preprocessFileLineNumbers '\41st_Unconscious\XEH_postInit.sqf'";
    };
};	