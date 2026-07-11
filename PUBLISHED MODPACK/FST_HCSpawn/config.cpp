// FST_HCSpawn -- HC spawn & management system

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
            class enforceDroidStance {};
            class trackGroup {};
            class catchUntracked {};
            class recountUnits {};
            class cleanupDeadGroups {};
            class requestDeadGroupCleanup {};
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
            class queueZeusGroup {};
            class legacyRespawnGroup {};
            class handleZeusOriginalDecision {};
        };
        class Spawn {
            file = "FST_HCSpawn";
            class spawnGroupOnTarget {};
            class createGroupLocal {};
            class fillGarrison {};
            class requestFillGarrison {};
            class registerZenModules {};
            class getFSTOpforUnitOptions {};
            class addEditableObjects {};
            class isValidFSTOpforUnit {};
            class isSafeGarrisonPos {};
            class applyUnitLoadoutSafe {};
        };
        class Objectives {
            file = "FST_HCSpawn";
            class addObjective {};
            class checkObjectives {};
            class cleanupGroups {};
            class frontlineSpawn {};
            class qrfSpawn {};
        };
        class Debug {
            file = "FST_HCSpawn";
            class debugDraw {};
            class requestDebugSnapshot {};
            class fpsMonitor {};
            class statusReport {};
            class initExplosionDiag {};
            class initEmergencyDroidBandaid {};
            class emergencyStabilizeDroid {};
            class emergencyStabilizeGroup {};
        };
    };
};

#include "CfgEventHandlers.hpp"

// Zeus modules registered via ZEN in fn_registerZenModules.sqf
