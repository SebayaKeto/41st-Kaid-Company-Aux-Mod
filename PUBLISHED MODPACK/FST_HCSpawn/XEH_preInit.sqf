// FST_HCSpawn — preInit
// CBA settings + defaults + template definitions

// ============================================================
// HIDDEN DEFAULTS / INTERNAL TUNING
// ============================================================
// These are intentionally not all exposed in CBA. Fewer visible settings means
// fewer bad live-op combinations, while mission/server code can still override
// them before use if needed.

missionNamespace setVariable ["FST_HC_TransferBatchSize", missionNamespace getVariable ["FST_HC_TransferBatchSize", 4]];
missionNamespace setVariable ["FST_HC_TransferInterval", missionNamespace getVariable ["FST_HC_TransferInterval", 2.0]];
missionNamespace setVariable ["FST_HC_CatchAllInterval", missionNamespace getVariable ["FST_HC_CatchAllInterval", 15]];
missionNamespace setVariable ["FST_HC_ZeusTransferSettleDelay", missionNamespace getVariable ["FST_HC_ZeusTransferSettleDelay", 0.2]];
missionNamespace setVariable ["FST_HC_ZeusLegacyFallback", missionNamespace getVariable ["FST_HC_ZeusLegacyFallback", false]];
missionNamespace setVariable ["FST_HC_GarrisonRadius", missionNamespace getVariable ["FST_HC_GarrisonRadius", 100]];
missionNamespace setVariable ["FST_HC_PatrolRadius", missionNamespace getVariable ["FST_HC_PatrolRadius", 150]];
missionNamespace setVariable ["FST_HC_TriggerActivationDist", missionNamespace getVariable ["FST_HC_TriggerActivationDist", 800]];
missionNamespace setVariable ["FST_HC_FillGarrisonSingleActive", true];
missionNamespace setVariable ["FST_HC_FillGarrisonBatchSize", missionNamespace getVariable ["FST_HC_FillGarrisonBatchSize", 8]];

// Backward-compatible defaults for older saved CBA profiles / scripts.
missionNamespace setVariable ["FST_HC_InterceptEnabled", missionNamespace getVariable ["FST_HC_InterceptEnabled", true]];
missionNamespace setVariable ["FST_HC_ZeusInstantClone", missionNamespace getVariable ["FST_HC_ZeusInstantClone", true]];
missionNamespace setVariable ["FST_HC_ZeusImmediateTransfer", missionNamespace getVariable ["FST_HC_ZeusImmediateTransfer", false]];
missionNamespace setVariable ["FST_HC_BlockFillGarrisonWithoutHC", missionNamespace getVariable ["FST_HC_BlockFillGarrisonWithoutHC", true]];

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
    "FST_HC_DebugLogging", "CHECKBOX",
    ["Verbose RPT Logging", "Extra HC spawn/transfer logging. Leave off during live ops unless debugging."],
    ["FST HC Spawn", "Core"], false, true, {}, false
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

// ============================================================
// FILL GARRISON SAFETY
// ============================================================

[
    "FST_HC_FillGarrisonMaxUnits", "SLIDER",
    ["Max Units Per Fill", "Hard cap for one Fill Garrison click. Large bases are sampled instead of fully filled."],
    ["FST HC Spawn", "Fill Garrison"], [24, 600, 160, 0], true, {}, false
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
    ["FST HC Spawn", "Fill Garrison"], [0.3, 2, 1.0, 2], true, {}, false
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

missionNamespace setVariable ["FST_HCSpawn_buildVersion", "PREOP_FINAL_REVIEW_2026-05-04", true];
diag_log "[FST_HCSpawn] preInit complete - PREOP_FINAL_REVIEW_2026-05-04";
