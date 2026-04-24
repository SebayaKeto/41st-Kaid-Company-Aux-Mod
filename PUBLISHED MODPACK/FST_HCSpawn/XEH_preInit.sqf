// FST_HCSpawn — preInit
// All CBA settings + template definitions

// ============================================================
// HC SYSTEM SETTINGS
// ============================================================

[
    "FST_HC_Enabled", "CHECKBOX",
    ["Enable HC System", "Enable headless client offloading"],
    ["FST HC Spawn", "HC System"], true, true, {}, true
] call CBA_fnc_addSetting;

[
    "FST_HC_TransferBatchSize", "SLIDER",
    ["Transfer Batch Size", "Groups transferred per batch cycle. Higher = faster but more server load."],
    ["FST HC Spawn", "HC System"], [1, 20, 5, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_TransferInterval", "SLIDER",
    ["Transfer Interval", "Seconds between transfer batch cycles."],
    ["FST HC Spawn", "HC System"], [1, 30, 3, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_CatchAllInterval", "SLIDER",
    ["Catch-All Scan Interval", "Seconds between scans for untracked groups. Higher = less server load."],
    ["FST HC Spawn", "HC System"], [5, 60, 10, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_RebalanceEnabled", "CHECKBOX",
    ["Enable Rebalancing", "Periodically rebalance AI load between HCs. OFF by default — born-local spawning keeps load balanced."],
    ["FST HC Spawn", "HC System"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_RebalanceInterval", "SLIDER",
    ["Rebalance Interval", "Seconds between rebalance checks."],
    ["FST HC Spawn", "HC System"], [60, 900, 300, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_RebalanceThreshold", "SLIDER",
    ["Rebalance Threshold", "Min unit count difference between most/least loaded HC before rebalancing."],
    ["FST HC Spawn", "HC System"], [5, 100, 20, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_PreserveLoadouts", "CHECKBOX",
    ["Preserve Loadouts on Transfer", "Save and reapply unit loadouts after setGroupOwner (fixes naked unit bug)."],
    ["FST HC Spawn", "HC System"], true, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// BLACKLISTS
// ============================================================

[
    "FST_HC_BlacklistNames", "EDITBOX",
    ["Blacklisted Names", "Variable names to exclude from offloading. Format: name1,name2,..."],
    ["FST HC Spawn", "Blacklist"], "ignore", true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlacklistTypes", "EDITBOX",
    ["Blacklisted Types", "Classnames to exclude. Format: type1,type2,..."],
    ["FST HC Spawn", "Blacklist"], "", true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_BlacklistVehicles", "CHECKBOX",
    ["Blacklist All Vehicles", "Prevent offloading groups in vehicles."],
    ["FST HC Spawn", "Blacklist"], false, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// ZEUS SETTINGS
// ============================================================

[
    "FST_HC_InterceptEnabled", "CHECKBOX",
    ["Intercept Zeus Placement", "Zeus-placed groups automatically move to HC."],
    ["FST HC Spawn", "Zeus"], true, true, {}, true
] call CBA_fnc_addSetting;

[
    "FST_HC_ZeusHoldEnabled", "CHECKBOX",
    ["Enable Zeus Hold", "Allow Zeus to pull groups from HC to local machine."],
    ["FST HC Spawn", "Zeus"], true, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// SPAWN SETTINGS
// ============================================================

[
    "FST_HC_GarrisonRadius", "SLIDER",
    ["Garrison Radius", "LAMBS garrison radius for quick-spawn."],
    ["FST HC Spawn", "Quick Spawn"], [25, 300, 100, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_PatrolRadius", "SLIDER",
    ["Patrol Radius", "LAMBS patrol radius for quick-spawn."],
    ["FST HC Spawn", "Quick Spawn"], [25, 500, 150, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_TriggerActivationDist", "SLIDER",
    ["Trigger Activation Distance", "Distance for baseline objective spawns."],
    ["FST HC Spawn", "Objectives"], [100, 2000, 800, 0], true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// FILL GARRISON SETTINGS
// ============================================================

[
    "FST_HC_FillDensity", "SLIDER",
    ["Fill Density %", "Percentage of building positions to fill."],
    ["FST HC Spawn", "Fill Garrison"], [10, 100, 75, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillB2Ratio", "SLIDER",
    ["B2 Ratio %", "Percentage of fill garrison droids that are B2s."],
    ["FST HC Spawn", "Fill Garrison"], [0, 100, 20, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_FillRadius", "SLIDER",
    ["Fill Scan Radius", "Radius to scan for buildings."],
    ["FST HC Spawn", "Fill Garrison"], [25, 500, 150, 0], true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// PERFORMANCE / SCALE SETTINGS
// ============================================================

[
    "FST_HC_AICap", "SLIDER",
    ["AI Cap", "Max total AI units across all HCs. 0 = no cap. Prevents spawning beyond this limit."],
    ["FST HC Spawn", "Performance"], [0, 3000, 1000, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnEnabled", "CHECKBOX",
    ["Enable Despawn Cleanup", "Delete AI groups after players have engaged and left the area."],
    ["FST HC Spawn", "Performance"], false, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnEngageRadius", "SLIDER",
    ["Engagement Radius", "Ground players must come within this range to activate a group for despawn eligibility."],
    ["FST HC Spawn", "Performance"], [50, 1000, 300, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnRadius", "SLIDER",
    ["Despawn Radius", "After activation, groups start the stale timer when no ground players are within this range."],
    ["FST HC Spawn", "Performance"], [200, 3000, 1000, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DespawnTimer", "SLIDER",
    ["Despawn Timer", "Seconds with no ground players nearby before an activated group is deleted. Default 600 (10 min)."],
    ["FST HC Spawn", "Performance"], [60, 1800, 600, 0], true, {}, false
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

diag_log "[FST_HCSpawn] preInit complete";
