class CfgPatches
{
    class fst_droidstance
    {
        name = "FST Droid Stance Control";
        author = "Daara";
        requiredVersion = 0.1;
        requiredAddons[] = { "cba_main", "41st_Droids" };
        units[] = {};
        weapons[] = {};
    };
};

class CfgFunctions
{
    class fst_droidstance
    {
        class droidstance
        {
            file = "fst_droidstance\functions";
            class init {};
        };
    };
};

class Extended_PostInit_EventHandlers
{
    class fst_droidstance
    {
        init = "call fst_droidstance_fnc_init";
    };
};
