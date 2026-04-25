// FST_HCSpawn — HC spawn & management system

class CfgPatches {
    class FST_HCSpawn {
        name = "FST HC Spawn System";
        author = "41st Elite Corps";
        url = "";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_keybinding", "cba_settings", "lambs_wp"};
    };
};

class CfgFunctions {
    class FST_HCSpawn {
        class HCManagement {
            file = "FST_HCSpawn";
            class initHCSystem {};
            class registerHC {};
            class handleDisconnect {};
            class getSpawnTarget {};
            class isBlacklisted {};
            class registerEvents {};
        };
        class GroupTracking {
            file = "FST_HCSpawn";
            class trackGroup {};
            class catchUntracked {};
            class recountUnits {};
        };
        class Transfer {
            file = "FST_HCSpawn";
            class processTransfers {};
            class transferGroup {};
            class reapplyGarrison {};
            class emergencyRedistribute {};
        };
        class Zeus {
            file = "FST_HCSpawn";
            class zeusHold {};
            class interceptZeusPlace {};
        };
        class Spawn {
            file = "FST_HCSpawn";
            class spawnGroupOnTarget {};
            class createGroupLocal {};
            class fillGarrison {};
            class requestFillGarrison {};
            class registerZenModules {};
        };
        class Objectives {
            file = "FST_HCSpawn";
            class addObjective {};
            class checkObjectives {};
            class cleanupGroups {};
            class frontlineSpawn {};
        };
        class Debug {
            file = "FST_HCSpawn";
            class debugDraw {};
            class fpsMonitor {};
            class statusReport {};
        };
    };
};

#include "CfgEventHandlers.hpp"

// Zeus modules registered via ZEN in fn_registerZenModules.sqf
