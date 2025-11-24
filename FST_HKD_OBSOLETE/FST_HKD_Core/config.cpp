#define _ARMA_

class CfgPatches
{
	class FST_HKD_Core
	{
        addonRootClass = "A3_Modules_F_Curator";
        author = "Hoersch-Kessel Drive";
		units[] = 
        {
            "Module_HKD_Drop_Single",
            "Module_HKD_Drop_Radius"
        };
		weapons[] = {};
        requiredAddons[] = 
        {
            "A3_Data_F_Enoch_Loadorder",
            "A3_Data_F_ParticleEffects",
            "A3_Sounds_F",
            "A3_Modules_F",
            "A3_Modules_F_Curator",
            "CBA_MAIN",
            "FST_Core",
            "FST_Common",
            "FST_HKD_Structures"
        };
		requiredversion = 0.1;
	};
};
#include "HKD_Dialogs.hpp"
#include "HKD_Faction_Def.hpp"
#include "FST_HKD_Settings.hpp"

class CfgEditorCategories
{
    class FST_HKD_CategoryStructures 
    { 
        displayName = "[HKD] Naval Fortifications"; 
    };
    class HKD_Zeus_Modules
    {
        displayName = "[HKD] Modules";
    };
};
class CfgEditorSubcategories
{
    class FST_HKD_Subcategory_Barriers 
    { 
        displayName = "[HKD] Hull-Plate Barriers"; 
    };
    class FST_HKD_Subcategory_Turrets 
    { 
        displayName = "[HKD] Void-Sealed Turrets"; 
    };
};
class CfgFunctions
{
    class FST_HKD
    {
        tag = "HKD";
        class DropSystem
        {
            file = "FST\FST_HKD\FST_HKD_Core\Functions";
            class moduleHKDDropSingle {};
            class moduleHKDDropRadius {};
            class moduleHKDDropRadius_Execution {};
            class dialogHandler {};
            class initHKDDrop {}; 
            class serverHKDDropExecution {};
            class serverSetCancel {};
            class clientUpdateProgress {};
        };
    };
};
class CfgVehicles
{
    class Logic;
    class Module_F: Logic
    {
        class ArgumentsBaseUnits;
        class ModuleDescription;
        class AttributeValues;
    };

    // --- BASE MODULE ---
    class Module_HKD_Drop_Base: Module_F
    {
        author = "Hoersch-Kessel Drive";
        _generalMacro = "Module_HKD_Drop_Base";
        scope = 1; // Abstract
        scopeCurator = 2;
        category = "HKD_Zeus_Modules";
        functionPriority = 1;
        isGlobal = 1;
        isTriggerActivated = 0;
        isDisposable = 0;
        curatorCanAttach = 1;
        
        // Define Shared Arguments
        class Arguments
        {
            class Object_Class
            {
                displayName = "Object Class";
                description = "Classname of object to drop (Must have HKD_CanBeGravDropped=1)";
                typeName = "STRING";
                defaultValue = "FST_HKD_Blocker_Blank";
            };
            class Drop_Altitude
            {
                displayName = "Drop Altitude (m)";
                typeName = "NUMBER";
                defaultValue = "1000";
            };
            class Random_Dir
            {
                displayName = "Randomize Rotation";
                typeName = "BOOL";
                defaultValue = "1";
            };
            class Compass_Dir
            {
                displayName = "Fixed Direction (0-360)";
                description = "Only used if Random Rotation is disabled";
                typeName = "NUMBER";
                defaultValue = "0";
            };
            class Enable_Thrusters
            {
                displayName = "Enable Thruster FX";
                typeName = "BOOL";
                defaultValue = "1";
            };
        };
    };

    // --- MODULE 1: SINGLE DROP ---
    class Module_HKD_Drop_Single: Module_HKD_Drop_Base
    {
        author = "Hoersch-Kessel Drive";
        _generalMacro = "Module_HKD_Drop_Single";
        scope = 2; // Visible
        scopeCurator = 2;
        displayName = "HKD Drop (Single)";
        function = "HKD_fnc_moduleHKDDropSingle";
        icon = "\a3\Modules_F_Curator\Data\iconOrdnance_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitModule_ca.paa";
    };

    // --- MODULE 2: RADIUS DROP ---
    class Module_HKD_Drop_Radius: Module_HKD_Drop_Base
    {
        author = "Hoersch-Kessel Drive";
        _generalMacro = "Module_HKD_Drop_Radius";
        scope = 2; // Visible
        scopeCurator = 2;
        displayName = "HKD Drop (Radius)";
        function = "HKD_fnc_moduleHKDDropRadius";
        icon = "\a3\Modules_F_Curator\Data\iconsmoke_ca.paa";
        portrait = "\a3\Modules_F_Curator\Data\portraitModule_ca.paa";
        
        class Arguments: Arguments
        {
            // Add Radius specific arguments FIRST so they appear at the top
            class Drop_Count
            {
                displayName = "Object Count";
                description = "Number of objects to drop in the area";
                typeName = "NUMBER";
                defaultValue = "10";
            };
            class Drop_Radius
            {
                displayName = "Radius (m)";
                description = "Area spread for the drop";
                typeName = "NUMBER";
                defaultValue = "100";
            };
            
            // Re-declare base args to ensure they appear in the list
            class Object_Class { displayName = "Object Class"; typeName = "STRING"; defaultValue = "FST_HKD_Blocker_Blank"; };
            class Drop_Altitude { displayName = "Drop Altitude"; typeName = "NUMBER"; defaultValue = "1000"; };
            class Random_Dir { displayName = "Randomize Rotation"; typeName = "BOOL"; defaultValue = "1"; };
            class Compass_Dir { displayName = "Fixed Direction"; typeName = "NUMBER"; defaultValue = "0"; };
            class Enable_Thrusters { displayName = "Enable Thruster FX"; typeName = "BOOL"; defaultValue = "1"; };
        };
    };
};