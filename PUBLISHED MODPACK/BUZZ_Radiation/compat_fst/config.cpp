// FST vehicle side panel patch
class CfgPatches {
    class BUZZ_Radiation_Compat_FST {
        name = "BUZZ_Radiation FST Vehicle Panels";
        author = "Connor";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.14;
        skipWhenMissingDependencies = 1;
        requiredAddons[] = {
            "BUZZ_Radiation_main",
            "3AS_APC_Jug",
            "3AS_ARC_170",
            "3AS_Imperial_Air_Gozanti",
            "3AS_ITT",
            "3AS_LAAT",
            "3AS_LAAT_Cargo",
            "3AS_LAAT_LE",
            "3AS_Nu",
            "3AS_Republic_Heli_Rho",
            "3AS_SaberTank",
            "FST_APC_Jug",
            "FST_ARC_170",
            "FST_ARC_170_Rear",
            "FST_Gozanti",
            "FST_ITT",
            "FST_JMSLLTE_vehgr_ITT",
            "FST_LAAT",
            "FST_LAAT_Cargo",
            "FST_LAAT_LE",
            "FST_Nu",
            "FST_Rho",
            "FST_SaberTank"
        };
    };
};
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class VehicleSystemsTemplateLeftDriver;
class VehicleSystemsTemplateRightDriver;
class CfgVehicles {
    class Plane_Fighter_03_dynamicLoadout_base_F;
    class 3as_arc_170_base: Plane_Fighter_03_dynamicLoadout_base_F {
        class Components;
    };
    class FST_Arc_170_Rear: 3as_arc_170_base {
        class Components: Components {
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
        };
    };
    class 3AS_laat_Base;
    class FST_laat_Base: 3AS_laat_Base {
        class components {
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
        };
    };
    class Car;
    class Car_F: Car {
        class Turrets {
            class MainTurret;
        };
    };
    class Wheeled_Apc_F: Car_F {
        class NewTurret;
        class Turrets;
    };
    class FST_Jug_base_F: Wheeled_Apc_F {
        class Turrets: Turrets {
            class MainTurret1: NewTurret {
                class Components {
                    class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                            };
                        };
                    };
                    class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                            };
                        };
                    };
                };
            };
        };
        class Components {
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
        };
    };
    class FST_JMSLLTE_veh_ITT_base: Car_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class Components {
                    class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                            };
                        };
                    };
                    class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                            };
                        };
                    };
                };
            };
        };
    };
    class Tank;
    class 3AS_Rho_Base_F;
    class 3AS_LAAT_Cargo_Base;
    class 3AS_nuclass_base;
    class FST_Nu_Shuttle: 3AS_nuclass_base {
        class components {
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
        };
    };
    class Plane_Base_F;
    class Plane_Fighter_03_base_F: Plane_Base_F {
        class Components;
    };
    class FST_Arc_170: 3as_arc_170_base {
        class Components: Components {
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
        };
    };
    class 3AS_Patrol_LAAT_Base;
    class 3AS_Gozanti_Base_F: Plane_Fighter_03_base_F {
        class Components: Components {
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
        };
        class Turrets {
            class MainTurret;
        };
    };
    class FST_Gozanti: 3AS_Gozanti_Base_F {
        class Turrets: Turrets {
            class MainTurret: MainTurret {
                class components {
                    class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                            };
                        };
                    };
                    class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                        class Components {
                            class BUZZ_Radiation_MonitorDisplay {
                                componentType = "CustomDisplayComponent";
                                resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                            };
                        };
                    };
                };
            };
        };
    };
    class FST_LAAT_LE: 3AS_Patrol_LAAT_Base {
        class components {
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
        };
    };
    class FST_LAATC: 3AS_LAAT_Cargo_Base {
        class components {
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
        };
    };
    class FST_Rho_Shuttle: 3AS_Rho_Base_F {
        class Components {
            class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
            class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft {
                class Components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
        };
    };
    class Tank_F: Tank {
        class Components;
    };
    class 3as_saber_01_Base: Tank_F {
        class Components: Components {
            class VehicleSystemsDisplayManagerLeft: VehicleSystemsTemplateLeftDriver {
                class components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorLeft";
                    };
                };
            };
            class VehicleSystemsDisplayManagerRight: VehicleSystemsTemplateRightDriver {
                class components {
                    class BUZZ_Radiation_MonitorDisplay {
                        componentType = "CustomDisplayComponent";
                        resource = "RscCustomInfoBUZZ_Radiation_MonitorRight";
                    };
                };
            };
        };
    };
};
