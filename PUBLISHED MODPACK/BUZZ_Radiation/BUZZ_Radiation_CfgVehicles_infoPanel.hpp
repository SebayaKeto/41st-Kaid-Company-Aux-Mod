// Adds the Radiation Monitor to the infantry side info panels ([ and ] keys),
// next to the vanilla GPS minimap and mine detector panels.
//
// NEEDS AN IN-GAME CHECK: this patches CAManBase >> Components. If after loading
// the mod the GPS or mine detector panels disappear on foot, open the Config Viewer at
// configFile >> "CfgVehicles" >> "CAManBase" >> "Components" and adjust the
// inheritance below to match, or comment out the #include of this file in CfgVehicles.hpp.
class Man;
class CAManBase: Man {
    class Components {
        class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
            class Components: Components {
                class BUZZ_Radiation_MonitorDisplay {
                    componentType = "CustomDisplayComponent";
                    resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                };
            };
        };
        class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
            class Components: Components {
                class BUZZ_Radiation_MonitorDisplay {
                    componentType = "CustomDisplayComponent";
                    resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                };
            };
        };
    };
};
