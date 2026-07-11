// FST_HCSpawn -- preInit
// CBA settings + defaults + template definitions

// ============================================================
// HIDDEN DEFAULTS / INTERNAL TUNING
// ============================================================
// These are intentionally not all exposed in CBA. Fewer visible settings means
// fewer bad live-op combinations, while mission/server code can still override
// them before use if needed.

missionNamespace setVariable ["FST_HC_TransferBatchSize", missionNamespace getVariable ["FST_HC_TransferBatchSize", 4]];
missionNamespace setVariable ["FST_HC_TransferInterval", missionNamespace getVariable ["FST_HC_TransferInterval", 2.0]];
// Catch-all is a safety net for third-party/server-created AI. Zeus/module spawns
// are already tracked directly, so this does not need to sweep allGroups often.
missionNamespace setVariable ["FST_HC_CatchAllInterval", missionNamespace getVariable ["FST_HC_CatchAllInterval", 30]];
missionNamespace setVariable ["FST_HC_RecountInterval", missionNamespace getVariable ["FST_HC_RecountInterval", 60]];
missionNamespace setVariable ["FST_HC_CleanupInterval", missionNamespace getVariable ["FST_HC_CleanupInterval", 20]];
missionNamespace setVariable ["FST_HC_ZeusTransferSettleDelay", missionNamespace getVariable ["FST_HC_ZeusTransferSettleDelay", 0.2]];
missionNamespace setVariable ["FST_HC_ZeusLegacyFallback", missionNamespace getVariable ["FST_HC_ZeusLegacyFallback", false]];
missionNamespace setVariable ["FST_HC_GarrisonRadius", missionNamespace getVariable ["FST_HC_GarrisonRadius", 100]];
missionNamespace setVariable ["FST_HC_PatrolRadius", missionNamespace getVariable ["FST_HC_PatrolRadius", 150]];
missionNamespace setVariable ["FST_HC_TriggerActivationDist", missionNamespace getVariable ["FST_HC_TriggerActivationDist", 800]];
missionNamespace setVariable ["FST_HC_FillGarrisonSingleActive", true];
missionNamespace setVariable ["FST_HC_FillGarrisonBatchSize", missionNamespace getVariable ["FST_HC_FillGarrisonBatchSize", 8]];
missionNamespace setVariable ["FST_HC_FillGarrisonBatchDelay", missionNamespace getVariable ["FST_HC_FillGarrisonBatchDelay", 1.25]];
missionNamespace setVariable ["FST_HC_CleanupPostSpawnGrace", missionNamespace getVariable ["FST_HC_CleanupPostSpawnGrace", 60]];
missionNamespace setVariable ["FST_HC_DeadGroupCleanupEnabled", missionNamespace getVariable ["FST_HC_DeadGroupCleanupEnabled", true]];
missionNamespace setVariable ["FST_HC_DeadGroupAutoCleanupEnabled", false];
missionNamespace setVariable ["FST_HC_DeadGroupCleanupInterval", missionNamespace getVariable ["FST_HC_DeadGroupCleanupInterval", 1200]];
missionNamespace setVariable ["FST_HC_DeadGroupCleanupMinAge", missionNamespace getVariable ["FST_HC_DeadGroupCleanupMinAge", 300]];
missionNamespace setVariable ["FST_HC_DeadTrackedGroupCleanupMinAge", missionNamespace getVariable ["FST_HC_DeadTrackedGroupCleanupMinAge", 900]];
missionNamespace setVariable ["FST_HC_DeadGroupCleanupMaxPerPass", missionNamespace getVariable ["FST_HC_DeadGroupCleanupMaxPerPass", 25]];
// Dynamic simulation default OFF. When on, the server-side manager globally
// disables simulation for any flagged group outside its activation distance of
// a PLAYER (default 500m for "Group"; Zeus camera does not wake units). At our
// AO scale this froze most of the mission's AI whenever HCs were connected,
// because catchUntracked only sweeps groups (and transferGroup only flags them)
// when at least one HC is registered. Disabled units cannot move, respond to
// Zeus, or even be killed. Re-enable only with tuned activation distances.
missionNamespace setVariable ["FST_HC_EnableDynamicSimulationSystem", missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]];
missionNamespace setVariable ["FST_HC_DroidStanceEnabled", missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]];
missionNamespace setVariable ["FST_HC_DroidStanceInterval", missionNamespace getVariable ["FST_HC_DroidStanceInterval", 10]];
missionNamespace setVariable ["FST_HC_RedistributeOnHCDisconnect", missionNamespace getVariable ["FST_HC_RedistributeOnHCDisconnect", false]];
missionNamespace setVariable ["FST_HC_HCDisconnectSafeModeSeconds", missionNamespace getVariable ["FST_HC_HCDisconnectSafeModeSeconds", 120]];
missionNamespace setVariable ["FST_HC_ExplosionDiagEnabled", missionNamespace getVariable ["FST_HC_ExplosionDiagEnabled", false]];
missionNamespace setVariable ["FST_HC_ExplosionDiagInterval", missionNamespace getVariable ["FST_HC_ExplosionDiagInterval", 10]];
missionNamespace setVariable ["FST_HC_ExplosionDiagExplosionSpikeThreshold", missionNamespace getVariable ["FST_HC_ExplosionDiagExplosionSpikeThreshold", 75]];
missionNamespace setVariable ["FST_HC_ExplosionDiagKilledSpikeThreshold", missionNamespace getVariable ["FST_HC_ExplosionDiagKilledSpikeThreshold", 20]];
missionNamespace setVariable ["FST_HC_ExplosionDiagImmediateCooldown", missionNamespace getVariable ["FST_HC_ExplosionDiagImmediateCooldown", 5]];
missionNamespace setVariable ["FST_HC_ExplosionDiagLogBelowFPS", missionNamespace getVariable ["FST_HC_ExplosionDiagLogBelowFPS", 15]];
missionNamespace setVariable ["FST_HC_ExplosionDiagRecentLimit", missionNamespace getVariable ["FST_HC_ExplosionDiagRecentLimit", 40]];
missionNamespace setVariable ["FST_HC_EmergencyDroidBandaidEnabled", missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", true]];
missionNamespace setVariable ["FST_HC_EmergencyDroidScanInterval", missionNamespace getVariable ["FST_HC_EmergencyDroidScanInterval", 1.5]];
missionNamespace setVariable ["FST_HC_EmergencyDroidScanMaxPerPass", missionNamespace getVariable ["FST_HC_EmergencyDroidScanMaxPerPass", 250]];
missionNamespace setVariable ["FST_HC_EmergencyKillWindow", missionNamespace getVariable ["FST_HC_EmergencyKillWindow", 10]];
missionNamespace setVariable ["FST_HC_EmergencyKillSpikeThreshold", missionNamespace getVariable ["FST_HC_EmergencyKillSpikeThreshold", 12]];
missionNamespace setVariable ["FST_HC_EmergencyDeadDeleteDelay", missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteDelay", 0.25]];
missionNamespace setVariable ["FST_HC_EmergencyDeadDeleteMaxPerPass", missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteMaxPerPass", 20]];
missionNamespace setVariable ["FST_HC_EmergencyMuteSentences", missionNamespace getVariable ["FST_HC_EmergencyMuteSentences", true]];
missionNamespace setVariable ["FST_HC_PerHCSoftCap", missionNamespace getVariable ["FST_HC_PerHCSoftCap", 240]];
missionNamespace setVariable ["FST_HC_BlockSpawnWhenAllHCSoftCapped", missionNamespace getVariable ["FST_HC_BlockSpawnWhenAllHCSoftCapped", true]];


// Backward-compatible defaults for older saved CBA profiles / scripts.
missionNamespace setVariable ["FST_HC_InterceptEnabled", missionNamespace getVariable ["FST_HC_InterceptEnabled", true]];
missionNamespace setVariable ["FST_HC_ZeusInstantClone", missionNamespace getVariable ["FST_HC_ZeusInstantClone", true]];
missionNamespace setVariable ["FST_HC_ZeusImmediateTransfer", missionNamespace getVariable ["FST_HC_ZeusImmediateTransfer", false]];
missionNamespace setVariable ["FST_HC_BlockFillGarrisonWithoutHC", missionNamespace getVariable ["FST_HC_BlockFillGarrisonWithoutHC", true]];

// ============================================================
// EMERGENCY LIVE-OP BANDAID
// ============================================================


[
    "FST_HC_EmergencyDroidBandaidEnabled", "CHECKBOX",
    ["Emergency Droid Stability Bandaid", "Live-op bandaid: mutes droid radio protocol, dampens ACE medical AI state on local droids, and quickly deletes dead droid bodies on HCs/server. Use until the ACE/droid wound-handler issue is fixed in config."],
    ["FST HC Spawn", "Emergency"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_EmergencyDeadDeleteDelay", "SLIDER",
    ["Dead Droid Delete Delay", "Seconds before dead droids are deleted by the emergency bandaid. Lower is safer for crashes, higher preserves bodies longer."],
    ["FST HC Spawn", "Emergency"], [0.05, 5, 0.25, 2], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_EmergencyDeadDeleteMaxPerPass", "SLIDER",
    ["Dead Droid Deletes Per Pass", "Maximum dead droid bodies deleted every 0.5 seconds by the emergency bandaid."],
    ["FST HC Spawn", "Emergency"], [1, 50, 20, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_EmergencyMuteSentences", "CHECKBOX",
    ["Emergency Mute AI Radio Sentences", "Disables AI radio sentence playback on the dedicated server and HCs. This is heavy-handed, but it prevents missing droid radio protocol spam from hammering RPTs during combat."],
    ["FST HC Spawn", "Emergency"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_PerHCSoftCap", "SLIDER",
    ["Per-HC Soft AI Cap", "Emergency cap used when choosing an HC target. If every HC is over this count and blocking is enabled, heavy spawns are blocked instead of overloading one HC or falling back to the server."],
    ["FST HC Spawn", "Core"], [100, 500, 240, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlockSpawnWhenAllHCSoftCapped", "CHECKBOX",
    ["Block Spawns When All HCs Soft-Capped", "Emergency behavior: if all HCs are already over the per-HC soft cap, block new heavy AI spawns rather than risking another HC crash or server fallback."],
    ["FST HC Spawn", "Core"], true, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// CORE SETTINGS
// ============================================================

[
    "FST_HC_Enabled", "CHECKBOX",
    ["Enable HC System", "Enable headless client offloading."],
    ["FST HC Spawn", "Core"], true, true, {}, true
] call CBA_fnc_addSetting;

[
    "FST_HC_ZeusMode", "LIST",
    ["Zeus Placement Mode", "Instant clone/replace is the live-op default. setGroupOwner is cleaner but can take several seconds. Off leaves Zeus-placed AI on the server."],
    ["FST HC Spawn", "Core"],
    [["instant", "transfer", "off"], ["Instant clone/replace", "setGroupOwner transfer", "Off"], 0],
    true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_AICap", "SLIDER",
    ["AI Cap", "Max tracked AI units across all HCs. 0 = no cap. For 150-player ops, keep this conservative."],
    ["FST HC Spawn", "Core"], [0, 3000, 900, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlockHeavySpawnsWithoutHC", "CHECKBOX",
    ["Block Heavy Spawns Without HCs", "Prevents Fill Garrison, Frontline, and QRF mass spawns from falling back onto the dedicated server if all HCs are disconnected."],
    ["FST HC Spawn", "Core"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_EmergencyRedistributeDelay", "SLIDER",
    ["HC Death Redistribute Delay", "Seconds between group transfers after an HC disconnects. Higher is safer during live ops."],
    ["FST HC Spawn", "Core"], [0.2, 2, 1.0, 2], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_RedistributeOnHCDisconnect", "CHECKBOX",
    ["Redistribute AI After HC Crash", "OFF by default. If an HC crashes, do not immediately shove its tracked groups onto the remaining HC during a live object/network storm."],
    ["FST HC Spawn", "Core"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_HCDisconnectSafeModeSeconds", "SLIDER",
    ["HC Crash Safe Mode Seconds", "Seconds to pause transfer/catch-all activity after an HC disconnects. This reduces server/HC ownership churn during crash recovery."],
    ["FST HC Spawn", "Core"], [0, 300, 120, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DebugLogging", "CHECKBOX",
    ["Verbose RPT Logging", "Extra HC spawn/transfer logging. Leave off during live ops unless debugging."],
    ["FST HC Spawn", "Core"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_ExplosionDiagEnabled", "CHECKBOX",
    ["Automatic Explosion Diagnostics", "Logs HC/server explosive ammo, explosion hit spikes, killed-unit spikes, FPS, and local AI counts. Leave enabled until the crash cause is isolated."],
    ["FST HC Spawn", "Diagnostics"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_ExplosionDiagInterval", "SLIDER",
    ["Explosion Diagnostic Interval", "Seconds between automatic explosion diagnostic RPT summaries."],
    ["FST HC Spawn", "Diagnostics"], [5, 30, 10, 0], true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// ZEUS / BLACKLIST
// ============================================================

[
    "FST_HC_ZeusHoldEnabled", "CHECKBOX",
    ["Enable Zeus Hold", "Allow Zeus to pull groups from HC to local/server ownership with Shift+F2."],
    ["FST HC Spawn", "Zeus / Blacklist"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlacklistNames", "EDITBOX",
    ["Blacklisted Names", "Variable names to exclude from offloading. Format: name1,name2,..."],
    ["FST HC Spawn", "Zeus / Blacklist"], "ignore", true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlacklistTypes", "EDITBOX",
    ["Blacklisted Types", "Classnames to exclude. Format: type1,type2,..."],
    ["FST HC Spawn", "Zeus / Blacklist"], "", true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlacklistVehicles", "CHECKBOX",
    ["Blacklist All Vehicles", "Prevent offloading groups currently in vehicles."],
    ["FST HC Spawn", "Zeus / Blacklist"], false, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// CLEANUP
// ============================================================

[
    "FST_HC_DespawnEnabled", "CHECKBOX",
    ["Enable Despawn Cleanup", "Delete tracked AI groups after players have engaged and then left the area."],
    ["FST HC Spawn", "Cleanup"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnEngageRadius", "SLIDER",
    ["Engagement Radius", "Ground players must come within this range before a group becomes eligible for later despawn."],
    ["FST HC Spawn", "Cleanup"], [50, 1000, 300, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnRadius", "SLIDER",
    ["Despawn Radius", "After activation, groups start the stale timer when no ground players are within this range."],
    ["FST HC Spawn", "Cleanup"], [200, 3000, 1000, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnTimer", "SLIDER",
    ["Despawn Timer", "Seconds with no ground players nearby before an activated group is deleted."],
    ["FST HC Spawn", "Cleanup"], [60, 1800, 600, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupCleanupEnabled", "CHECKBOX",
    ["Enable Manual Dead OPFOR Cleanup", "Allows the manual dead-group cleanup event to delete local dead OPFOR groups during controlled lulls. Manual cleanup bypasses the automatic interval."],
    ["FST HC Spawn", "Cleanup"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupAutoCleanupEnabled", "CHECKBOX",
    ["Enable Automatic Dead OPFOR Cleanup", "Disabled in this build. Dead-group cleanup is manual-only to avoid combat-time delete storms."],
    ["FST HC Spawn", "Cleanup"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupCleanupInterval", "SLIDER",
    ["Dead Group Cleanup Interval", "Seconds between automatic dead OPFOR group sweeps. Default is 20 minutes; use manual cleanup during lulls if needed."],
    ["FST HC Spawn", "Cleanup"], [300, 1800, 1200, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupCleanupMinAge", "SLIDER",
    ["Dead Group Minimum Age", "Seconds an OPFOR group must have zero alive units before the dead-group sweeper may delete it."],
    ["FST HC Spawn", "Cleanup"], [60, 900, 300, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadTrackedGroupCleanupMinAge", "SLIDER",
    ["Tracked Dead Group Minimum Age", "Extra-safe delay for FST-tracked groups with zero alive units. Higher values reduce object/reference churn during intense combat."],
    ["FST HC Spawn", "Cleanup"], [300, 1800, 900, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupCleanupMaxPerPass", "SLIDER",
    ["Dead Groups Max Per Sweep", "Maximum dead OPFOR groups deleted in one automatic sweep. Keep low; manual cleanup can be requested separately during lulls."],
    ["FST HC Spawn", "Cleanup"], [1, 60, 25, 0], true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// FILL GARRISON SAFETY
// ============================================================

[
    "FST_HC_FillGarrisonMaxUnits", "SLIDER",
    ["Max Units Per Fill", "Hard cap for one Fill Garrison click. Large bases are sampled instead of fully filled."],
    ["FST HC Spawn", "Fill Garrison"], [24, 600, 120, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillGarrisonMaxDuration", "SLIDER",
    ["Hard Timeout", "Maximum seconds a Fill Garrison job may keep dispatching batches before it stops."],
    ["FST HC Spawn", "Fill Garrison"], [30, 120, 60, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillGarrisonMaxScanPositions", "SLIDER",
    ["Scan Position Cap", "Maximum candidate positions collected from one scan before sampling/filtering."],
    ["FST HC Spawn", "Fill Garrison"], [240, 2400, 700, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillGarrisonCooldown", "SLIDER",
    ["Cooldown", "Seconds after a Fill Garrison job finishes before another one may start."],
    ["FST HC Spawn", "Fill Garrison"], [0, 60, 20, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillGarrisonBatchDelay", "SLIDER",
    ["Batch Delay", "Seconds between Fill Garrison batches. Higher is gentler on the server."],
    ["FST HC Spawn", "Fill Garrison"], [0.5, 2.5, 1.25, 2], true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// TEMPLATES
// ============================================================

FST_HC_Templates = createHashMapFromArray [

    // --- B1 DROIDS ---
    ["b1_fireteam", [EAST, ["FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5"], "B1 Fire Team (4)"]],
    ["b1_squad", [EAST,
        ["FST_Droid_B1_Commander","FST_Droid_B1_AR","FST_Droid_B1_E5","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5"],
        "B1 Squad STD (12)"]],
    ["b1_squad_at", [EAST,
        ["FST_Droid_B1_Commander","FST_Droid_B1_AR","FST_Droid_B1_E5","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_AT","FST_Droid_B1_E5","FST_Droid_B1_E5"],
        "B1 Squad w/ AT (12)"]],
    ["b1_squad_aa", [EAST,
        ["FST_Droid_B1_Commander","FST_Droid_B1_AR","FST_Droid_B1_E5","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_AA","FST_Droid_B1_E5","FST_Droid_B1_E5"],
        "B1 Squad w/ AA (12)"]],
    ["b1_squad_ataa", [EAST,
        ["FST_Droid_B1_Commander","FST_Droid_B1_AR","FST_Droid_B1_E5","FST_Droid_B1_E5",
         "FST_Droid_B1_AT","FST_Droid_B1_E5","FST_Droid_B1_AR","FST_Droid_B1_E5",
         "FST_Droid_B1_E5","FST_Droid_B1_AA","FST_Droid_B1_E5","FST_Droid_B1_E5"],
        "B1 Squad AT/AA (12)"]],
    ["b1_gat_team", [EAST, ["FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_GAT"], "B1 Guided AT Team (4)"]],

    // --- BX COMMANDOS ---
    ["bx_killteam", [EAST, ["FST_BX","FST_BX","FST_BX","FST_BX"], "BX Kill Team (4)"]],
    ["bx_sniper_team", [EAST, ["FST_BX_Sniper","FST_BX_Sniper"], "BX Sniper Team (2)"]],
    ["bx_at_team", [EAST, ["FST_BX_AT","FST_BX_AT"], "BX Anti-Tank Team (2)"]],
    ["bx_aa_team", [EAST, ["FST_BX_AA","FST_BX_AA"], "BX Anti-Air Team (2)"]],

    // --- B2 SUPER BATTLE DROIDS ---
    ["b2_team", [EAST, ["FST_B2_TL","FST_B2","FST_B2_TL","FST_B2"], "B2 Team (4)"]],
    ["b2_squad", [EAST, ["FST_B2_TL","FST_B2","FST_B2_TL","FST_B2","FST_B2_TL","FST_B2","FST_B2_TL","FST_B2"], "B2 Squad (8)"]],
    ["b2_flame_team", [EAST, ["FST_B2_TL","FST_B2_Flame","FST_B2_Flame","FST_B2"], "B2 Flame Team (4)"]]
];

// Objective storage
FST_HC_Objectives = [];
FST_HC_ObjectivesFired = [];

// Client-side copies of HC tracking (populated via publicVariable from server)
// Initialized here so debug draw and other client code has valid arrays before HCs register
if (!isServer) then {
    FST_HC_Array = [];
    FST_HC_Ids = [];
};

missionNamespace setVariable ["FST_HCSpawn_buildVersion", "HANDOFF_V23_SAFE_DISCONNECT_AUTO_EXPDIAG_2026-05-23", true];
diag_log "[FST_HCSpawn] preInit complete - HANDOFF_V23_SAFE_DISCONNECT_AUTO_EXPDIAG_2026-05-23";
