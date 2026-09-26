// FST_HCSpawn -- HC spawn & management system

class CfgPatches {
    class FST_HCSpawn {
        name = "FST HC Spawn System";
        author = "41st Elite Corps";
        url = "";
        units[] = {"FST_BURNS_Module_rush","FST_BURNS_Module_hunt","FST_BURNS_Module_ambush","FST_BURNS_Module_creep","FST_BURNS_Module_assault","FST_BURNS_Module_retreat","FST_BURNS_Module_cqb","FST_BURNS_Module_garrison","FST_BURNS_Module_camp","FST_BURNS_Module_defend","FST_BURNS_Module_patrol","FST_BURNS_Module_reset","FST_BURNS_Module_target","FST_BURNS_Module_artillery_register","FST_BURNS_Module_artillery_remove","FST_BURNS_Module_artillery_fire","FST_BURNS_Module_enable_unit","FST_BURNS_Module_disable_unit","FST_BURNS_Module_enable_group","FST_BURNS_Module_disable_group","FST_BURNS_Module_radio_on","FST_BURNS_Module_radio_off","FST_BURNS_Module_reinforce_on","FST_BURNS_Module_reinforce_off","FST_BURNS_Module_configure","FST_BURNS_Module_set_radio","FST_HC_Module_b1_fireteam","FST_HC_Module_b1_squad","FST_HC_Module_b1_squad_at","FST_HC_Module_b1_squad_aa","FST_HC_Module_b1_squad_ataa","FST_HC_Module_b1_gat_team","FST_HC_Module_bx_killteam","FST_HC_Module_bx_sniper_team","FST_HC_Module_bx_at_team","FST_HC_Module_bx_aa_team","FST_HC_Module_b2_team","FST_HC_Module_b2_squad","FST_HC_Module_fill","FST_HC_Module_frontline","FST_HC_Module_qrf","FST_HC_Module_vehicle","FST_HC_Module_vehicle_transfer","FST_HC_Module_cleanup"};
        weapons[] = {};
        requiredVersion = 2.18;
        requiredAddons[] = {"cba_main", "cba_keybinding", "cba_settings", "A3_Modules_F"};
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
            class isPlayerControlledUnit {};
            class burnsStateGet {};
            class burnsStateSet {};

            class sendToVehicleHC {};
            class reapplyGarrison {};
            class requestTransferState {};
            class captureTransferState {};
            class receiveTransferState {};
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
            class spawnPace {};
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
            class burnsCuratorWaypoint {};
            class burnsSimulation {};
            class burnsSpecialTick {};
            class burnsRecoverStations {};
            class burnsRushTarget {};
            class burnsIsDown {};
            class burnsEngagementAllowed {};
            class burnsReleasePointFire {};
            class burnsPointFire {};
            class burnsAcquirePointFire {};
            class burnsArmorPulseEnd {};
            class burnsArmorAssist {};
            class burnsReaction {};
            class burnsVisibility {};
            class burnsBXTask {};
            class burnsB2Line {};
            class burnsReleaseB2Line {};
            class burnsBXMobility {};
            class burnsBXMelee {};
            class burnsReleaseBXCharge {};
            class burnsInitBXEnhancements {};

            class burnsReleaseBX {};
            class burnsVehicleProgress {};
            class burnsArmorSectionCreate {};
            class burnsArmorSectionGoal {};
            class burnsArmorSectionsTick {};
            class burnsArmorSectionDriver {};
            class burnsN99Move {};
            class burnsGulantharSlope {};
            class burnsInitEngagement {};

            class burnsB1Advance {};
            class burnsB1Formation {};
            class burnsB1Eligible {};
            class burnsB1Hit {};
            class burnsReleaseAdvance {};
            class burnsReleaseStation {};
            class burnsReleaseAdvanceUnit {};
            class burnsSuspendTask {};
            class burnsCancelAdvanceMove {};

            class burnsDialog {};
            class registerBurnsEvents {};
            class registerBurnsModules {};
            class registerNativeModule {};
            class queueNativeModule {};
            class burnsRequest {};
            class burnsArtillery {};
            class combatTaskTick {};
            class burnsRole {};
            class burnsApplyRole {};
            class burnsRestoreRole {};
            class burnsRestoreGroupRole {};
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
            class heavyKind {};
            class heavyCheck {};
            class heavyZeus {};
            class initPerformance {};
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
#include "BURNS_CfgModules.hpp"

// Zeus modules registered via ZEN in fn_registerZenModules.sqf
