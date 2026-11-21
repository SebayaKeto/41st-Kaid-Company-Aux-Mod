class CfgVehicles {
    class Logic;
    class Module_F: Logic {
        class AttributesBase {
            class Default;
            class Edit;
            class Combo;
            class Checkbox;
            class CheckboxNumber;
            class ModuleDescription;
            class Units;
        };
        class ModuleDescription {
            class AnyBrain;
        };
    };

    // ------------------------------------------------------------------
    // Radiation Zone: Background / Dangerous / Lethal
    // ------------------------------------------------------------------
    class BUZZ_Radiation_ModuleZone: Module_F {
        scope = 2;
        displayName = "Radiation Zone";
        author = "Connor";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\danger_ca.paa";
        portrait = "\a3\ui_f\data\igui\cfg\simpletasks\types\danger_ca.paa";
        category = "BUZZ_Radiation_Modules";
        function = "BUZZ_Radiation_fnc_moduleZone";
        functionPriority = 1;
        isGlobal = 2;          // runs on every machine, including JIP
        isTriggerActivated = 0;
        isDisposable = 0;
        is3DEN = 0;

        // Draw and resize the zone directly in Eden (ellipse or rectangle).
        canSetArea = 1;
        canSetAreaShape = 1;
        canSetAreaHeight = 1;
        class AttributeValues {
            size3[] = {100, 100, -1};
            isRectangle = 0;
        };

        class Attributes: AttributesBase {
            class Tier: Combo {
                property = "BUZZ_Radiation_ModuleZone_Tier";
                displayName = "Radiation tier";
                tooltip = "Background: protective gear makes players immune.\nDangerous: about 15 minutes to death.\nLethal: about 3 minutes to death.\n(Exact times are in Addon Options > BUZZ_Radiation.)";
                typeName = "NUMBER";
                defaultValue = "1";
                class Values {
                    class Background { name = "Background"; value = 0; };
                    class Dangerous  { name = "Dangerous";  value = 1; };
                    class Lethal     { name = "Lethal";     value = 2; };
                };
            };
            class Condition: Edit {
                property = "BUZZ_Radiation_ModuleZone_Condition";
                displayName = "Active condition";
                tooltip = "SQF expression, checked every second on every machine. The zone only irradiates while it returns true.\n(_this select 0) is this module.\nExample: missionNamespace getVariable ['reactor_breached', false]";
                control = "EditCodeMulti3";
                typeName = "STRING";
                defaultValue = """true""";
            };
            class ModuleDescription: ModuleDescription {};
        };

        class ModuleDescription: ModuleDescription {
            description = "Irradiates everyone inside the module's area. Resize the area in Eden, or sync one or more triggers to the module to use their areas instead.";
            sync[] = {"EmptyDetector"};
            class EmptyDetector {
                description = "Optional. Each synced trigger's area becomes part of this zone (the module's own area is then ignored).";
                displayName = "Trigger area";
                position = 0;
                direction = 0;
                optional = 1;
                duplicate = 1;
            };
        };
    };

    // ------------------------------------------------------------------
    // Safe Zone: blocks all radiation, including Background
    // ------------------------------------------------------------------
    class BUZZ_Radiation_ModuleSafeZone: BUZZ_Radiation_ModuleZone {
        displayName = "Radiation Safe Zone";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\defend_ca.paa";
        portrait = "\a3\ui_f\data\igui\cfg\simpletasks\types\defend_ca.paa";
        BUZZ_Radiation_fixedTier = -2;
        class Attributes: AttributesBase {
            class Condition: Edit {
                property = "BUZZ_Radiation_ModuleSafeZone_Condition";
                displayName = "Active condition";
                tooltip = "SQF expression, checked every second on every machine. The safe zone only shields while it returns true.\n(_this select 0) is this module.";
                control = "EditCodeMulti3";
                typeName = "STRING";
                defaultValue = """true""";
            };
            class ModuleDescription: ModuleDescription {};
        };
        class ModuleDescription: ModuleDescription {
            description = "No radiation reaches anyone inside this area, whatever zones overlap it. Poisoning already absorbed still has to be treated.";
        };
    };

    // ------------------------------------------------------------------
    // Decontamination Zone: blocks radiation and clears dose
    // ------------------------------------------------------------------
    class BUZZ_Radiation_ModuleDeconZone: BUZZ_Radiation_ModuleSafeZone {
        displayName = "Radiation Decontamination Zone";
        icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\heal_ca.paa";
        portrait = "\a3\ui_f\data\igui\cfg\simpletasks\types\heal_ca.paa";
        BUZZ_Radiation_fixedTier = -1;
        class ModuleDescription: ModuleDescription {
            description = "Shields like a Safe Zone and also clears absorbed dose quickly (rate set in Addon Options > BUZZ_Radiation).";
        };
    };

    #include "BUZZ_Radiation_CfgVehicles_infoPanel.hpp"
};
