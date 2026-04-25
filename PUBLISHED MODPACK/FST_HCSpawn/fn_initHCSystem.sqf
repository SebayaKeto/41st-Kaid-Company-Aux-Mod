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
FST_HC_UnitCounts = [];     // [count1, count2, ...] — bookkeeping

// Group tracking — via setVariable on each group
// "FST_HC_tracked" = [hcIndex, unitCount] on tracked groups
// "FST_HC_heldBy" = zeusClientOwner on held groups
// "FST_HC_onHC" = hcIndex (server-local, debug draw uses owner command)
FST_HC_TrackedCount = 0;

// Transfer queue
FST_HC_TransferQueue = [];

// State flags
FST_HC_Transferring = false;
FST_HC_EmergencyMode = false;

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

// Transfer queue processor
[] spawn FST_HCSpawn_fnc_processTransfers;

// Catch-all scanner for untracked groups (e.g. from other scripts)
[{
    [] call FST_HCSpawn_fnc_catchUntracked;
}, FST_HC_CatchAllInterval, []] call CBA_fnc_addPerFrameHandler;

// Periodic unit recount (bookkeeping accuracy)
[{
    [] call FST_HCSpawn_fnc_recountUnits;
}, 30, []] call CBA_fnc_addPerFrameHandler;

// Despawn cleanup (delete AI groups far from all players)
if (FST_HC_DespawnEnabled) then {
    [{
        [] call FST_HCSpawn_fnc_cleanupGroups;
    }, 15, []] call CBA_fnc_addPerFrameHandler;
};

// Objectives (delayed to allow mission init.sqf to populate)
[{
    if (count FST_HC_Objectives > 0) then {
        [] call FST_HCSpawn_fnc_checkObjectives;
        diag_log format ["[FST_HCSpawn] Objective PFH started — %1 objectives", count FST_HC_Objectives];
    };
}, [], 3] call CBA_fnc_waitAndExecute;

diag_log "[FST_HCSpawn] HC system initialized";
