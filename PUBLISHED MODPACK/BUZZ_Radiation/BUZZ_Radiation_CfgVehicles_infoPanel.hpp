// Adds the Radiation Monitor to the infantry side info panels
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
