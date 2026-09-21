// FST_HCSpawn -- HC spawn & management system

class CfgPatches {
    class FST_HCSpawn {
        name = "FST HC Spawn System";
        author = "41st Elite Corps";
        url = "";
        units[] = {};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_keybinding", "cba_settings"};
    };
};

class CfgFunctions {
    class BURNS {
        class Public {
            class task { file = "FST_HCSpawn\fn_setCombatTask.sqf"; };
            class patrol { file = "FST_HCSpawn\fn_burnsPatrol.sqf"; };
            class role { file = "FST_HCSpawn\fn_burnsRole.sqf"; };
        };
    };
    class FST_HCSpawn {
        class HCManagement {
            file = "FST_HCSpawn";
            class initHCSystem {};
            class registerHC {};
            class handleDisconnect {};
            class getSpawnTarget {};
            class getVehicleHC {};
            class isBlacklisted {};
            class registerEvents {};
            class isAuthorizedCaller {};
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
            class isVehicleTransferSafe {};
            class isProtectedVehicleGroup {};
            class sendToVehicleHC {};
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
            class spawnVehicleOnTarget {};
            class createGroupLocal {};
            class setCombatTask {};
            class initCombatTasks {};
            class burnsTaskInterval {};
            class burnsPositions {};
            class burnsReservePositions {};
            class burnsUseCover {};
            class burnsVisibleContact {};
            class initVisibility {};
            class burnsSuppressed {};
            class initSuppression {};
            class burnsCommand {};
            class burnsSpecialTick {};
            class burnsDialog {};
            class burnsRequest {};
            class burnsArtillery {};
            class combatTaskTick {};
            class burnsRole {};
            class burnsApplyRole {};
            class burnsRestoreRole {};
            class burnsPatrol {};
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
            class qrfBuildLocal {};
        };
        class Debug {
            file = "FST_HCSpawn";
            class debugDraw {};
            class requestDebugSnapshot {};
            class fpsMonitor {};
            class statusReport {};
            class initExplosionDiag {};
            class initEmergencyDroidBandaid {};
            class initDroidCorpseCleanup {};
            class isDroidUnit {};
            class emergencyStabilizeDroid {};
            class emergencyStabilizeGroup {};
        };
    };
};

#include "CfgEventHandlers.hpp"
#include "BURNS_CfgContext.hpp"

// Zeus modules registered via ZEN in fn_registerZenModules.sqf
