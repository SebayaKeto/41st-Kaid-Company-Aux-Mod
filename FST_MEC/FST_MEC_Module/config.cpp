#include "mec_base_defines.hpp"

class CfgPatches
{
    class FST_MEC_ZeusModules_Patch
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
        requiredAddons[] = {"ace_common"}; 
        name = "MEC: Maldova Engineering Corp."; // Mod Name
        author = MEC_AUTHOR; // Author information
        logo = MEC_ICON_PATH; // Path to logo
        picture = MEC_ICON_PATH; // Path to picture
        dlcTag = "MEC_Mod"; // DLC Tag
    };
};
class CfgVehicles
{
    class Logic;
    class Module_F: Logic {};

    class MEC_Power_Module: Module_F
    {
        // General properties
        scope = 2; // Visible in editor
        scopeCurator = 2; // Visible in Zeus
        displayName = "MEC Power System Configurator";
        category = MEC_TAG_CATEGORY;
        function = "MEC_TAG_fnc_moduleInit"; // The function this module executes on synced objects
        isGlobal = 2; // Executes on server and clients
        is3DEN = 0; // Not visible in 3D editor logic
        
        class EventHandlers {
            // When the module is placed in the editor and synced to objects, this runs
            init = "_this call (missionNamespace getVariable 'MEC_TAG_fnc_moduleInit');";
        };

        // --- ATTRIBUTES INJECTION ---
        // The attributes themselves are defined in the CfgAttributeClasses section below.
        class SimpleAttributes {};
    };
};
class CfgAttributeClasses
{
    class MEC_Power_Config
    {
        displayName = "MEC Power System";
        // The class of object this attribute page will apply to.
        // We target House and Logic to cover Walls, Docks, and the Zeus Module itself.
        baseClasses[] = {"House", "Logic"}; 

        class Attributes
        {
            // ATTRIBUTE 1: ENABLE/DISABLE SYSTEM
            class MEC_PowerSystem_Enabled
            {
                property = "MEC_PowerSystem";
                control = "Checkbox";
                displayName = "Power System Active";
                tooltip = "If checked, this object will participate in the MEC power grid (Supplier/Consumer loops active).";
                defaultValue = "true";
                expression = "_this setVariable [MEC_TAG + '_PowerSystem', _value, true];";
            };

            // ATTRIBUTE 2: ROLE DEFINITION (Supplier/Consumer)
            class MEC_PowerSystem_Role
            {
                property = "MEC_PowerSystem_Role_Selection";
                control = "Combo";
                displayName = "Power Role";
                tooltip = "Defines if the asset is a Supplier (MEC-P1), a Consumer (Wall), or both (e.g., Dock).";
                defaultValue = "0"; // 0: Dual Role, 1: Supplier Only, 2: Consumer Only
                
                typeName = "NUMBER";
                
                class Values 
                {
                    class Dual {name = "Dual Role (Default)"; value = 0;};
                    class Supplier {name = "Supplier Only (Battery/Generator)"; value = 1;};
                    class Consumer {name = "Consumer Only (Wall/Dock)"; value = 2;};
                };
                
                // This expression sets the specific IsSupplier/IsConsumer flags based on the combo box selection.
                expression = "_this setVariable [MEC_TAG + '_RoleSelection', _value, true];";
            };

            // ATTRIBUTE 3: SUPPLIER OUTPUT SETTINGS
            class MEC_PowerSystem_SupplierRadius
            {
                property = "MEC_PowerSystem_SupplierRadius";
                control = "Edit";
                displayName = "Supplier Radius (Meters)";
                tooltip = "Max range for power transfer via physical conduit/induction.";
                defaultValue = QUOTE(MEC_STATIC_SUPPLY_RADIUS);
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_SupplierRadius', _value, true];";
            };

            class MEC_PowerSystem_SupplierRate
            {
                property = "MEC_PowerSystem_SupplierRate";
                control = "Edit";
                displayName = "Supplier Rate (Units/Sec)";
                tooltip = "Maximum rate this object can output power.";
                defaultValue = QUOTE(MEC_PULSE_SUPPLY_RATE);
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_SupplierRate', _value, true];";
            };
            
            // ATTRIBUTE 4: CHARGE CAPACITY SETTINGS
            class MEC_PowerSystem_MaxCharge
            {
                property = "MEC_PowerSystem_MaxCharge";
                control = "Edit";
                displayName = "Max Charge Capacity";
                tooltip = "The total energy reserve this asset can hold (units).";
                defaultValue = QUOTE(MEC_WALL_CAPACITY_MAX);
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_MaxCharge', _value, true];";
            };
            
            class MEC_PowerSystem_InitialCharge
            {
                property = "MEC_PowerSystem_InitialCharge";
                control = "Edit";
                displayName = "Initial Charge";
                tooltip = "Charge upon mission start (units).";
                defaultValue = "0";
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_InitialCharge', _value, true];";
            };
            
            // ATTRIBUTE 5: CONSUMER CONSUMPTION SETTINGS
            class MEC_PowerSystem_ChargeRate
            {
                property = "MEC_PowerSystem_ChargeRate";
                control = "Edit";
                displayName = "Consumer Draw Rate (Units/Sec)";
                tooltip = "Maximum rate this asset will draw power from a Supplier.";
                defaultValue = QUOTE(MEC_WALL_CHARGE_RATE);
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_ChargeRate', _value, true];";
            };
            
            class MEC_PowerSystem_DischargeRate
            {
                property = "MEC_PowerSystem_DischargeRate";
                control = "Edit";
                displayName = "Reserve Discharge Rate (Units/Sec)";
                tooltip = "Rate at which internal reserve power is consumed when not connected to a grid.";
                defaultValue = QUOTE(MEC_WALL_DISCHARGE_RATE);
                typeName = "NUMBER";
                expression = "_this setVariable [MEC_TAG + '_DischargeRate', _value, true];";
            };
        };
    };
};
