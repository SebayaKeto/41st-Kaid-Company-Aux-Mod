class CfgPatches {
    class BUZZ_Radiation_main {
        name = "BUZZ_Radiation";
        author = "Connor";
        units[] = {"BUZZ_Radiation_ModuleZone", "BUZZ_Radiation_ModuleSafeZone", "BUZZ_Radiation_ModuleDeconZone"};
        weapons[] = {"BUZZ_Radiation_Iodine", "BUZZ_Radiation_Monitor", "BUZZ_Radiation_FlushIV"};
        requiredVersion = 2.14;
        requiredAddons[] = {
            "A3_Modules_F",
            "A3_UI_F",
            "3DEN",
            "cba_main",
            "cba_settings",
            "ace_common",
            "ace_medical_treatment"
        };
    };
};

class Extended_PreInit_EventHandlers {
    class BUZZ_Radiation_main {
        init = "call compileScript ['\BUZZ_Radiation\BUZZ_Radiation_XEH_preInit.sqf']";
    };
};
class Extended_PostInit_EventHandlers {
    class BUZZ_Radiation_main {
        init = "call compileScript ['\BUZZ_Radiation\BUZZ_Radiation_XEH_postInit.sqf']";
    };
};

// Root-level vanilla side panel lists
class DefaultVehicleSystemsDisplayManagerLeft {
    class Components {
        class BUZZ_Radiation_MonitorDisplay {
            componentType = "CustomDisplayComponent";
            resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
        };
    };
};
class DefaultVehicleSystemsDisplayManagerRight {
    class Components {
        class BUZZ_Radiation_MonitorDisplay {
            componentType = "CustomDisplayComponent";
            resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
        };
    };
};

#include "BUZZ_Radiation_CfgFunctions.hpp"
#include "BUZZ_Radiation_CfgFactionClasses.hpp"
#include "BUZZ_Radiation_CfgSounds.hpp"
#include "BUZZ_Radiation_CfgWeapons.hpp"
#include "BUZZ_Radiation_CfgVehicles.hpp"
#include "BUZZ_Radiation_ACE_Medical_Treatment_Actions.hpp"
#include "BUZZ_Radiation_RscInGameUI.hpp"
