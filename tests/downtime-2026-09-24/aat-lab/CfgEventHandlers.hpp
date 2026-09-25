class Extended_PreInit_EventHandlers {
    class FST_HCSpawn {
        init = "call compile preprocessFileLineNumbers 'FST_HCSpawn\XEH_preInit.sqf'";
    };
};

class Extended_PostInit_EventHandlers {
    class FST_HCSpawn {
        init = "call compile preprocessFileLineNumbers 'FST_HCSpawn\XEH_postInit.sqf'";
    };
};
