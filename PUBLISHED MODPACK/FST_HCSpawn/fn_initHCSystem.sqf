// FST_HCSpawn_fnc_initHCSystem
// Server-side. Initializes all data structures, mission event handlers,
// and starts the transfer processor and catch-all scanner.

if (!isServer) exitWith {};

// ============================================================
// DATA STRUCTURES
// ============================================================

// HC tracking
FST_HC_Array = [];          // [hcObj1, hcObj2, ...]
FST_HC_Ids = [];            // [ownerId1, ownerId2, ...]
FST_HC_UnitCounts = [];     // [count1, count2, ...] -- bookkeeping

// Group tracking -- via setVariable on each group
// "FST_HC_tracked" = [hcIndex, unitCount] on tracked groups
// "FST_HC_heldBy" = zeusClientOwner on held groups
// "FST_HC_onHC" = hcIndex (server-local, debug draw uses owner command)
// "FST_HC_managed" = true on groups this addon or Zeus created (despawn eligibility)
FST_HC_TrackedCount = 0;
FST_HC_TrackedGroups = [];   // server-local cache; avoids scanning allGroups for routine cleanup/recount
FST_HC_HeldGroups = [];      // server-local cache of Zeus-held groups; avoids allGroups scans on every disconnect

// Transfer queue
FST_HC_TransferQueue = [];

// Debug/status counters
FST_HC_TransferSuccesses = 0;
FST_HC_TransferFailures = 0;
FST_HC_ZeusImmediateRequests = 0;
FST_HC_ZeusImmediateFallbacks = 0;
FST_HC_ZeusLegacyFallbacksUsed = 0;
FST_HC_ZeusInstantCloneRequests = 0;

// State flags
FST_HC_Transferring = false;
FST_HC_EmergencyMode = false;      // true only while emergencyRedistribute is moving groups
FST_HC_SafeModeUntil = -1;         // HC-disconnect safe mode; transfers/catch-all pause while time < this
FST_HC_RecountScheduled = false;   // debounce for HC-requested recounts

// ============================================================
// DISCONNECT HANDLER
// ============================================================
addMissionEventHandler ["HandleDisconnect", {
    params ["_unit", "_id", "_uid", "_name"];
    [_unit, _id, _uid, _name] call FST_HCSpawn_fnc_handleDisconnect;
    false
}];

// ============================================================
// START PROCESSORS
// ============================================================

// Dynamic simulation system: only affects objects/groups that are explicitly
// enableDynamicSimulation true. This addon enables it on non-critical idle groups.
// Default OFF (see XEH_preInit). The manager's simulation changes are global and
// activation is driven by player proximity only; Zeus does not wake units.
if (missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]) then {
    enableDynamicSimulationSystem true;
};

// Transfer queue processor
[] spawn FST_HCSpawn_fnc_processTransfers;

// Catch-all scanner for untracked groups (e.g. from other scripts)
[{
    [] call FST_HCSpawn_fnc_catchUntracked;
}, FST_HC_CatchAllInterval, []] call CBA_fnc_addPerFrameHandler;

// Periodic unit recount (bookkeeping accuracy)
[{
    [] call FST_HCSpawn_fnc_recountUnits;
}, FST_HC_RecountInterval, []] call CBA_fnc_addPerFrameHandler;

// Dead OPFOR group cleanup is manual-only in this build. Munificent/drop-pod systems
// can leave all-dead groups behind, but V12 proved that automatic combat-time sweeping
// can create dangerous object/network churn. Zeus can run it from the
// "--- Cleanup Dead Groups ---" module during controlled lulls.
missionNamespace setVariable ["FST_HC_LastDeadGroupCleanup", time];
missionNamespace setVariable ["FST_HC_DeadGroupAutoCleanupEnabled", false];
diag_log "[FST_HCSpawn] Automatic dead-group cleanup disabled; manual cleanup module available.";

// Droid stance keeper runs from XEH_postInit on the server and every HC.

// Despawn cleanup (delete AI groups far from all players). The PFH is always
// registered and the function checks FST_HC_DespawnEnabled itself, so the CBA
// checkbox can be toggled live.
[{
    [] call FST_HCSpawn_fnc_cleanupGroups;
}, FST_HC_CleanupInterval, []] call CBA_fnc_addPerFrameHandler;

// Objective checker. Start once even if objectives are added later by mission scripts/triggers.
[{
    if !(missionNamespace getVariable ["FST_HC_ObjectivePFHStarted", false]) then {
        missionNamespace setVariable ["FST_HC_ObjectivePFHStarted", true];
        [] call FST_HCSpawn_fnc_checkObjectives;
        diag_log "[FST_HCSpawn] Objective PFH started";
    };
}, [], 3] call CBA_fnc_waitAndExecute;

diag_log "[FST_HCSpawn] HC system initialized";
