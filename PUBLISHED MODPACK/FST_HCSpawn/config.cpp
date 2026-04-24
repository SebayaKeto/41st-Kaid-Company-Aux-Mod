// Hi Ruby

class CfgPatches {
    class FST_HCSpawn {
        name = "FST HC Spawn System";
        author = "Daara";
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
            class setHCIndex {};
        };
        class GroupTracking {
            file = "FST_HCSpawn";
            class trackGroup {};
            class untrackGroup {};
            class catchUntracked {};
            class recountUnits {};
        };
        class Transfer {
            file = "FST_HCSpawn";
            class processTransfers {};
            class transferGroup {};
            class reapplyGarrison {};
            class rebalance {};
            class emergencyRedistribute {};
        };
        class Zeus {
            file = "FST_HCSpawn";
            class initZeus {};
            class zeusHold {};
            class interceptZeusPlace {};
        };
        class Spawn {
            file = "FST_HCSpawn";
            class spawnGroupOnTarget {};
            class createGroupLocal {};
            class quickSpawnAtPos {};
            class fillGarrison {};
            class requestFillGarrison {};
            class registerZenModules {};
            class canSpawn {};
        };
        class Objectives {
            file = "FST_HCSpawn";
            class addObjective {};
            class checkObjectives {};
            class cleanupGroups {};
        };
        class Debug {
            file = "FST_HCSpawn";
            class debugDraw {};
            class debugToggle {};
            class fpsMonitor {};
            class statusReport {};
        };
    };
};

#include "CfgEventHandlers.hpp"


