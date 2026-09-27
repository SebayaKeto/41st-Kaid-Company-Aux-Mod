// FST_Stonewall -- Project Stonewall: carry player-built bases (ACE Fortify / Daidalos) into the next mission.
// Zeus modules (Zen, category "41st Stonewall"): Keep Area, Remove Keep Area, Save Mission.
// The save writes to the RPT; the offline tool (D:\Stonewall\tools\stonewall.py) cleans and bakes it.

class CfgPatches {
    class FST_Stonewall {
        name = "FST Stonewall";
        author = "41st Elite Corps";
        url = "";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_settings"};
        version = "1.2.4";
    };
};

class CfgFunctions {
    class FST_stonewall {
        tag = "FST_stonewall";
        class main {
            file = "FST_Stonewall\functions";
            class save {};
            class isAuthorized {};
            class createKeepArea {};
            class removeKeepArea {};
            class registerModules {};
            class awaitReply {};
        };
    };
};

class Extended_PreInit_EventHandlers {
    class FST_Stonewall {
        init = "call compile preprocessFileLineNumbers 'FST_Stonewall\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class FST_Stonewall {
        init = "call compile preprocessFileLineNumbers 'FST_Stonewall\XEH_postInit.sqf'";
    };
};
