class CfgPatches
{
    class FST_ShipScripts
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.0;
        requiredAddons[] = {"A3_Functions_F"};
    };
};

class CfgFunctions
{
    class FST
    {
        class RepairRearmRefuel
        {
            file = "FST_ShipScripts\FST_RepairRearmRefuel";
            class initTrigger { file = "FST_ShipScripts\FST_RepairRearmRefuel\fnc_initTrigger.sqf"; };
        };

        class TractorBeam
        {
            file = "FST_ShipScripts\FST_TractorBeam";
            class scan { file = "FST_ShipScripts\FST_TractorBeam\fnc_scan.sqf"; };
        };

        class VehicleSpawner
        {
            file = "FST_ShipScripts\FST_VehicleSpawner";
            class initVehicleData     { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_initVehicleData.sqf"; };
            class openGUI             { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_openGUI.sqf"; };
            class getSelectedPad      { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_getSelectedPad.sqf"; };
            class isPadClear          { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_isPadClear.sqf"; };
            class setStatus           { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_setStatus.sqf"; };
            class removePreviewVehicle{ file = "FST_ShipScripts\FST_VehicleSpawner\fnc_removePreviewVehicle.sqf"; };
            class spawnPreviewVehicle { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_spawnPreviewVehicle.sqf"; };
            class populateVehicleList { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_populateVehicleList.sqf"; };
            class updateCategory      { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_updateCategory.sqf"; };
            class updateSelection     { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_updateSelection.sqf"; };
            class spawnVehicle        { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_spawnVehicle.sqf"; };
            class deploy              { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_deploy.sqf"; };
            class garage              { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_garage.sqf"; };
            class destroyPadCamera    { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_destroyPadCamera.sqf"; };
            class updatePadCamera     { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_updatePadCamera.sqf"; };
            class serverSpawnVehicle  { file = "FST_ShipScripts\FST_VehicleSpawner\fnc_serverSpawnVehicle.sqf"; };
        };
    };
};

#include "FST_VehicleSpawner\FST_RscControls.hpp"
#include "FST_VehicleSpawner\FST_VehicleSpawnerDialog.hpp"
