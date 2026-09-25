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
// Automatic dead-group sweeping is manual-only in this build. The old
// "Enable Automatic Dead OPFOR Cleanup" checkbox and interval slider were
// never read by any code path, so they were removed from the CBA menu (V27).
missionNamespace setVariable ["FST_HC_DeadGroupAutoCleanupEnabled", false];
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
// Default false 2026-08-01 (team decision) -- must match the addSetting default
// below; this raw seed runs first, so leaving it true would silently win over
// CBA_fnc_addSetting's default regardless of that call's own value.
missionNamespace setVariable ["FST_HC_EmergencyDroidBandaidEnabled", missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", false]];
missionNamespace setVariable ["FST_HC_EmergencyDroidScanInterval", missionNamespace getVariable ["FST_HC_EmergencyDroidScanInterval", 1.5]];
missionNamespace setVariable ["FST_HC_EmergencyDroidScanMaxPerPass", missionNamespace getVariable ["FST_HC_EmergencyDroidScanMaxPerPass", 250]];
missionNamespace setVariable ["FST_HC_EmergencyKillWindow", missionNamespace getVariable ["FST_HC_EmergencyKillWindow", 10]];
missionNamespace setVariable ["FST_HC_EmergencyKillSpikeThreshold", missionNamespace getVariable ["FST_HC_EmergencyKillSpikeThreshold", 12]];
missionNamespace setVariable ["FST_HC_EmergencyDeadDeleteDelay", missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteDelay", 0.25]];
missionNamespace setVariable ["FST_HC_EmergencyDeadDeleteMaxPerPass", missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteMaxPerPass", 20]];
missionNamespace setVariable ["FST_HC_EmergencyMuteSentences", missionNamespace getVariable ["FST_HC_EmergencyMuteSentences", true]];
missionNamespace setVariable ["FST_HC_PerHCSoftCap", missionNamespace getVariable ["FST_HC_PerHCSoftCap", 400]];
// V28: a mounted group may change owner only while every vehicle it occupies is
// slower than this (m/s). Ownership hops on moving vehicles split crew and hull
// across machines for a few frames and wreck multi-crew coordination.
missionNamespace setVariable ["FST_HC_VehicleTransferMaxSpeed", missionNamespace getVariable ["FST_HC_VehicleTransferMaxSpeed", 1.5]];
missionNamespace setVariable ["FST_HC_BlockSpawnWhenAllHCSoftCapped", missionNamespace getVariable ["FST_HC_BlockSpawnWhenAllHCSoftCapped", true]];


// Backward-compatible defaults for older saved CBA profiles / scripts.
missionNamespace setVariable ["FST_HC_InterceptEnabled", missionNamespace getVariable ["FST_HC_InterceptEnabled", true]];
missionNamespace setVariable ["FST_HC_ZeusInstantClone", missionNamespace getVariable ["FST_HC_ZeusInstantClone", true]];
missionNamespace setVariable ["FST_HC_ZeusImmediateTransfer", missionNamespace getVariable ["FST_HC_ZeusImmediateTransfer", false]];
missionNamespace setVariable ["FST_HC_BlockFillGarrisonWithoutHC", missionNamespace getVariable ["FST_HC_BlockFillGarrisonWithoutHC", true]];

// ============================================================
// EMERGENCY LIVE-OP BANDAID
// ============================================================


// Default flipped OFF 2026-08-01 per team decision: instant droid-death vanish
// (hideObject+enableSimulation false fired synchronously on Killed) was reported
// as a visible regression during ops. This setting is still the fast, no-repack
// way to re-enable the bandaid live if HC crashes/FPS drops return -- flip it
// back on in FST HC Spawn > Emergency, no code change needed.
[
    "FST_HC_EmergencyDroidBandaidEnabled", "CHECKBOX",
    ["Emergency Droid Stability Bandaid", "Live-op bandaid: mutes droid radio protocol, dampens ACE medical AI state on local droids, and quickly deletes dead droid bodies on HCs/server. Use until the ACE/droid wound-handler issue is fixed in config."],
    ["FST HC Spawn", "Emergency"], false, true, {}, false
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

// ============================================================
// DROID CORPSE CLEANUP
// ============================================================
// Added 2026-08-08 after disabling the emergency droid bandaid's instant
// hideObject/fast-delete. Without it, nothing else deletes dead droid bodies
// while players remain engaged, and corpses were piling up during long
// firefights. This sweeper leaves a corpse fully visible/simulated for a
// while (a real death, not a vanish), then freezes its simulation, then
// deletes it -- bounding the total corpse count without vanishing on kill.
[
    "FST_HC_DroidCorpseCleanupEnabled", "CHECKBOX",
    ["Droid Corpse Cleanup", "Delayed cleanup of dead droid bodies (separate from the emergency bandaid). Prevents unbounded corpse accumulation during long droid firefights."],
    ["FST HC Spawn", "Cleanup"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DroidCorpseSimOffDelay", "SLIDER",
    ["Droid Corpse Sim-Off Delay", "Seconds after death before a droid corpse's simulation/physics is frozen. It stays visible as a static body."],
    ["FST HC Spawn", "Cleanup"], [2, 60, 8, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DroidCorpseDeleteDelay", "SLIDER",
    ["Droid Corpse Delete Delay", "Seconds after death before a droid corpse is deleted. Higher preserves bodies longer during a fight but allows more to accumulate."],
    ["FST HC Spawn", "Cleanup"], [5, 180, 25, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DroidCorpseDeleteMaxPerPass", "SLIDER",
    ["Droid Corpse Deletes Per Pass", "Maximum dead droid bodies deleted per second by the corpse cleanup sweeper."],
    ["FST HC Spawn", "Cleanup"], [1, 50, 10, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_PerHCSoftCap", "SLIDER",
    ["Per-HC Soft AI Cap", "Emergency cap used when choosing an HC target. If every HC is over this count and blocking is enabled, heavy spawns are blocked instead of overloading one HC or falling back to the server."],
    ["FST HC Spawn", "Core"], [100, 1000, 400, 0], true, {}, false
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
    ["AI Cap", "Max tracked AI units across all HCs. 0 = no cap. Default 1100 accommodates an 800-1000 AI op plus crew/reservation headroom; it is not a performance guarantee."],
    ["FST HC Spawn", "Core"], [0, 3000, 1100, 0], true, {}, false
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

// V27: server-side sanity check on who is asking for spawns/holds. CBA events
// do not carry a verified sender, so this validates the CLAIMED owner ID
// against the live curator/admin list. It stops non-Zeus clients from firing
// the spawn/hold events by accident or via a stray script, not a determined
// spoofer. Turn off only if legitimate Zeus requests are being rejected.
[
    "FST_HC_EventAuthEnabled", "CHECKBOX",
    ["Require Zeus/Admin For Spawn Events", "Server rejects spawn, fill, QRF, frontline, hold and cleanup requests whose claimed sender is not a current curator or logged-in admin."],
    ["FST HC Spawn", "Core"], true, true, {}, false
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
    ["Blacklist All Vehicles", "Prevent the catch-all and Zeus placement from offloading groups currently in vehicles. With a vehicle HC configured, Zeus can still send a stopped vehicle over with the '--- Send To Vehicle HC ---' module."],
    ["FST HC Spawn", "Zeus / Blacklist"], false, true, {}, false
] call CBA_fnc_addSetting;

// ============================================================
// INTEGRATED COMBAT TASKS (V29)
// Original BURNS AI. No LAMBS source or runtime dependency.
[
    "BURNS_AIThinkOnlyLocal", "CHECKBOX",
    ["Process AI On Its Owner", "Avoid duplicate remote-AI targeting work on server, HCs and players (Arma 2.20+). Scripts querying remote AI knowledge must run on the AI owner. Turn off if another system requires remote targeting data."],
    ["BURNS", "Performance"], true, true, {
        params ["_enabled"];
        private _options = getMissionOptions;
        if ("AIThinkOnlyLocal" in _options) then {
            _options set ["AIThinkOnlyLocal", _enabled];
            setMissionOptions _options;
            diag_log format ["[BURNS] owner %1 AIThinkOnlyLocal=%2",clientOwner,getMissionOptions get "AIThinkOnlyLocal"];
        };
    }, false
] call CBA_fnc_addSetting;
[
    "FST_HC_CombatTasksEnabled", "CHECKBOX",
    ["Enable BURNS AI", "Original owner-local tactics and role profiles. B1 line infantry; B2/BX remain controlled by Workshop WebKnight. Off leaves existing native waypoints."],
    ["BURNS", "Tactics"], true, true, {}, false
] call CBA_fnc_addSetting;
[
    "FST_HC_CombatTaskInterval", "SLIDER",
    ["Combat Order Interval", "Seconds between nearby or engaged group tactical updates. Groups are staggered under a measured work budget; loaded owners may take longer."],
    ["BURNS", "Tactics"], [5, 60, 15, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "BURNS_HumanBuildingCover", "CHECKBOX",
    ["Human building cover", "Supplement native cover movement after a known contact. Shared cached searches, at most two soldiers repositioned every 45 seconds."],
    ["FST HC Spawn", "BURNS"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "BURNS_DistanceScheduling", "CHECKBOX",
    ["Reduce Distant Tactical Updates", "Update distant groups less often while their native movement and combat continue. Nearby players or known enemies restore normal frequency. Disable to use the combat interval everywhere."],
    ["BURNS", "Performance"], true, true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_NearDistance", "SLIDER",
    ["Normal Update Distance", "Groups within this many metres of a living player use the combat interval. Any known enemy also keeps normal frequency, including AI-only battles."],
    ["BURNS", "Performance"], [300, 3000, 1200, 0], true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_DistantInterval", "SLIDER",
    ["Distant Order Interval", "Seconds between distant tactical updates, never faster than the combat interval. Does not pause reinforcements, pathfinding, weapons or WebKnight scripts."],
    ["BURNS", "Performance"], [15, 120, 45, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "BURNS_HumanSkill", "SLIDER",
    ["Non-Droid Tactical Skill", "Minimum commanding, courage, reload, spotting and general skills for hostile non-droid AI. Does not increase rifle accuracy to this value. Zeus can opt out with BURNS_exempt on the group."],
    ["BURNS", "Role Profiles"], [0, 1, 0.7, 2], true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_HumanAccuracy", "SLIDER",
    ["Non-Droid Accuracy", "Minimum aiming accuracy for hostile non-droid AI. Default 0.25 keeps skilled opponents from becoming perfect shots."],
    ["BURNS", "Role Profiles"], [0, 1, 0.25, 2], true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_LowVisibilityAssist", "CHECKBOX",
    ["Low Visibility B1 Sight Assist", "Opt-in mission aid for dense-fog grading. B1s require two unobstructed forward visual checks within the configured range. No changes to normal-map sight ranges; inactive below 0.4 fog."],
    ["BURNS", "Mission Visibility"], false, true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_VisibleContactRange", "SLIDER",
    ["Visible Contact Range", "Range for the optional B1 sight assist. Match what players can identify through the mission's gloom. Not a global AI firing or detection cap."],
    ["BURNS", "Mission Visibility"], [50,250,125,0], true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_B1Reaction", "SLIDER",
    ["B1 Reaction Skill", "Minimum reaction skill, with faster rifle handling capped at 0.75. Leaves spotting distance and shooting accuracy unchanged."],
    ["BURNS", "Role Profiles"], [0,1,0.85,2], true, {}, false
] call CBA_fnc_addSetting;
[
    "BURNS_B1MarchSpeed", "SLIDER",
    ["B1 March Speed", "Metres per second while assembling and advancing. B1s retain standing LINE formation; terrain and pathfinding can temporarily separate the line."],
    ["BURNS", "Role Profiles"], [1, 5, 2.5, 1], true, {}, false
] call CBA_fnc_addSetting;

// VEHICLE HC (V29)
// ============================================================

[
    "FST_HC_VehicleHCEnabled", "CHECKBOX",
    ["Dedicated Vehicle HC", "Route all AI vehicle spawns (vehicle quick spawn, QRF convoys, ship QRF vultures, script requests) to one HC and keep infantry balancing off it."],
    ["FST HC Spawn", "Vehicle HC"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_VehicleHCSlot", "SLIDER",
    ["Vehicle HC Slot", "Mission HC entity number (HC4 = slot 4), independent of connection order. If that slot is not connected, vehicles fall back to the least-loaded HC."],
    ["FST HC Spawn", "Vehicle HC"], [1, 8, 4, 0], true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_VehicleHCExclusive", "CHECKBOX",
    ["Keep Infantry Off The Vehicle HC", "Infantry spawns and transfers never pick the vehicle HC while another HC is available. Dismounted QRF passengers are moved to an infantry HC."],
    ["FST HC Spawn", "Vehicle HC"], true, true, {}, false
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

// V27: the catch-all sweeps editor-placed and mission-script AI onto HCs too.
// Before this flag, the despawn cleanup would delete those groups (HVTs, scripted
// objective units) ten minutes after players left. Default ON restricts despawn
// to groups this addon or Zeus created; OFF restores the old "everything" behavior.
[
    "FST_HC_DespawnOnlyManaged", "CHECKBOX",
    ["Despawn Only Addon/Zeus Groups", "Only despawn groups created by FST HC Spawn modules or placed by Zeus. Editor-placed and mission-script AI are left alone even after they are offloaded to an HC."],
    ["FST HC Spawn", "Cleanup"], true, true, {}, false
] call CBA_fnc_addSetting;

[
    "FST_HC_DeadGroupCleanupEnabled", "CHECKBOX",
    ["Enable Manual Dead OPFOR Cleanup", "Allows the manual dead-group cleanup (Zeus module '--- Cleanup Dead Groups ---') to delete local dead OPFOR groups during controlled lulls."],
    ["FST HC Spawn", "Cleanup"], true, true, {}, false
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
[
    "BURNS_HumanSuppression", "CHECKBOX",
    ["Human suppression recovery", "Near misses briefly disturb human aim. B1s and WebKnight droids are excluded. Bounded to 64 recent victims per AI owner; native suppression continues for overflow."],
    ["FST HC Spawn", "BURNS Combat"], true, true, {}, false
] call CBA_fnc_addSetting;
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
    ["b2_squad", [EAST, ["FST_B2_TL","FST_B2","FST_B2_TL","FST_B2","FST_B2_TL","FST_B2","FST_B2_TL","FST_B2"], "B2 Squad (8)"]]
];

// --- VEHICLE TEMPLATES (V28) ---
// key -> [side, class, description, default behaviour, isAir]
FST_HC_VehicleTemplates = createHashMapFromArray [
    ["aat",          [EAST, "FST_AAT",             "AAT Tank",                 "hunt",   false]],
    ["n99",          [EAST, "FST_N99",             "N99 Tank",                 "hunt",   false]],
    ["mtt",          [EAST, "FST_MTT",             "MTT (crew only)",          "move",   false]],
    ["pac",          [EAST, "FST_PAC_41st",        "PAC Transport (crew only)","move",   false]],
    ["sac",          [EAST, "FST_SAC_41st",        "SAC Transport (crew only)","move",   false]],
    ["hmp",          [EAST, "FST_HMP_Transport",   "HMP Gunship",              "sad",    true]],
    ["vulture",      [EAST, "FST_CIS_Vulture",     "Vulture Droid",            "sad",    true]],
    ["vulture_aa",   [EAST, "FST_CIS_Vulture_AA",  "Vulture Droid (AA)",       "loiter", true]],
    ["vulture_cas",  [EAST, "FST_CIS_Vulture_CAS", "Vulture Droid (CAS)",      "sad",    true]],
    ["vulture_elite",[EAST, "FST_CIS_Vulture_Elite","Vulture Droid (Elite)",   "sad",    true]]
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

missionNamespace setVariable ["FST_HCSpawn_buildVersion", "V30_5_B1_DEPLOYMENT_PREVIEW_2026-09-22", true];
diag_log "[FST_HCSpawn] preInit complete - V30_5_B1_DEPLOYMENT_PREVIEW_2026-09-22";













["BURNS_RifleAssistEnabled","CHECKBOX",["B1 vehicle and casualty fire","Allow bounded E5 single-shot assistance against visible armored targets and downed enemies."],"BURNS",true,1] call CBA_fnc_addSetting;

["BURNS_ArmorAssistEnabled","CHECKBOX",["AAT engagement and facing","Assist hostile AI AAT gunners and use short hull-turn corrections. Player vehicles are excluded."],"BURNS",true,1] call CBA_fnc_addSetting;

["BURNS_GulantharSlopeEnabled","CHECKBOX",["Gulanthar uphill gait","Use a dedicated climbing gait during uphill pursuit without changing attack animation speed."],"BURNS",true,1] call CBA_fnc_addSetting;


BURNS_sourceFingerprint="20e5363898734d4e09164508309fd7ef45ebd1e6d84a9747c4b9244dbf326e98";
diag_log format ["[BURNS_SOURCE] %1",BURNS_sourceFingerprint];

["BURNS_BXRunSpeed","SLIDER",["BX running speed","Ordinary running only. Dodge, attack, injury and external speed effects retain their own timing."],"BURNS",[1,1.3,1.15,2],1] call CBA_fnc_addSetting;
["BURNS_BXMeleeEnabled","CHECKBOX",["BX aggressive melee","AI BXs close on visible enemies within 12 metres and repeat melee when in reach. Respects hold, stealth and defensive orders."],"BURNS",true,1] call CBA_fnc_addSetting;

["BURNS_B2LineEnabled","CHECKBOX",["B2 combat firing line","Deploy AI 41st B2 groups into a firing line with short coordinated advances against visible known enemies."],"BURNS",true,1] call CBA_fnc_addSetting;

["BURNS_GulantharRunEnabled","CHECKBOX",["Gulanthar pursuit running","Use a faster sustained running gait during visible pursuit, preserving native attacks and eating."],"BURNS",true,1] call CBA_fnc_addSetting;
