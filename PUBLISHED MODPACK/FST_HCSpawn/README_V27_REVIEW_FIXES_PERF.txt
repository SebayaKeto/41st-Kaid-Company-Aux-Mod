FST_HCSpawn V27 - REVIEW FIXES + PERFORMANCE PASS (2026-09-20)

Base: V26R2 STABILITY MERGE. Full code review applied; no feature removed.

RPT verification strings (both must show V27):
[FST_HCSpawn] preInit complete - HANDOFF_V27_REVIEW_FIXES_PERF_2026-09-20
[FST_HCSpawn] postInit starting - HANDOFF_V27_REVIEW_FIXES_PERF_2026-09-20

============================================================
CORRECTNESS FIXES
============================================================
1. Zeus Hold vs transfer queue race. A group queued for HC transfer and then
   held (Shift+F2) was moved to an HC a few seconds later while still flagged
   held. Hold now removes the group from the queue; the processor, transferGroup
   and emergencyRedistribute all skip held groups. (fn_zeusHold, fn_processTransfers,
   fn_transferGroup, fn_emergencyRedistribute)
2. Objectives no longer lost when blocked. checkObjectives marked an objective as
   fired BEFORE spawning; if the router blocked (HCs still connecting, all HCs
   soft-capped) the objective never spawned for the rest of the op. It is now
   marked fired only after at least one group dispatched, and retries every 30s.
   spawnGroupOnTarget now returns true/false. (fn_checkObjectives, fn_spawnGroupOnTarget)
3. Despawn cleanup restricted to managed groups. New CBA setting
   "Despawn Only Addon/Zeus Groups" (Cleanup, default ON). Editor-placed and
   mission-script AI that the catch-all offloaded to HCs were being deleted ten
   minutes after players left. Groups get FST_HC_managed=true from createGroupLocal,
   fillGarrison, qrfSpawn and interceptZeusPlace. (fn_cleanupGroups)
4. Server-side authorization on client events. New FST_HCSpawn_fnc_isAuthorizedCaller
   validates the claimed owner ID against current curators / logged admins for
   spawn, quickSpawn, fill, frontline, QRF, hold, status, snapshot and cleanup
   events. CBA setting "Require Zeus/Admin For Spawn Events" (Core, default ON).
   Note: this stops accidental / stray-script use, not a client that lies about
   its owner ID (CBA events carry no verified sender). (fn_registerEvents)
5. Zeus mode "Off" now really leaves Zeus-placed AI alone: catch-all skips
   client-owned groups in that mode. (fn_catchUntracked)
6. Blacklist rework: vehicle check is live (was cached forever), verdict cache is
   keyed to the blacklist strings (setting changes take effect), name matching
   covers unit vehicleVarName / leader vehicle varName / group id as the setting
   text says, matching is case-insensitive. (fn_isBlacklisted)
7. HC-disconnect safe mode uses its own deadline (FST_HC_SafeModeUntil) instead of
   borrowing FST_HC_EmergencyMode, so a finishing redistribute no longer ends the
   safe-mode window early. queueZeusGroup's immediate transfer also respects the
   pause. (fn_handleDisconnect, fn_processTransfers, fn_catchUntracked, fn_queueZeusGroup,
   fn_cleanupDeadGroups)
8. Loadout restore after transfer only re-applies when gear actually differs from
   the server snapshot, and goes through applyUnitLoadoutSafe (droid empty-loadout
   guard). Old check fired only when uniform=="" (always for droids, never for
   uniformed units). (fn_registerEvents)
9. Blocked spawns now tell the requesting Zeus (quickSpawn, frontline, clone) and
   frontline reports "N/M waves deployed" instead of always "complete".
10. Fill Garrison "Max Units Per Fill" honors the full 24-600 slider (was hard
    clamped to 120). Fallback defaults aligned with CBA defaults.
11. Manual dead-group cleanup now has a UI: ZEN module "--- Cleanup Dead Groups ---".
12. trackGroup accepts the HC owner ID (arg 5); HC-created groups send it so an
    HC disconnect between dispatch and track cannot mis-file the group.
13. HC registration waits for the HC player entity (30s) and re-registers every
    60s if its owner ID is missing from FST_HC_Ids.
14. reapplyGarrison no longer sets forceSpeed 0 (never reverted); transferGroup
    restores the vehicle's previous lock state instead of forcing unlocked.
15. Template module chat line fixed ("%%1" is not an SQF escape).
16. Status report keybind is admin/Zeus only. Stale build strings and comments fixed.
17. Removed dead CBA settings: "Enable Automatic Dead OPFOR Cleanup" and
    "Dead Group Cleanup Interval" (never read by any code path). Despawn PFH is
    always registered so the Despawn checkbox can be toggled live.

============================================================
PERFORMANCE
============================================================
Network:
- Removed 3 public setVariable broadcasts per spawned unit (FST_HC_created,
  FST_HC_spawnSettlingUntil, FST_spawnDamageDeferUntilLocal). Nothing off-machine
  reads them. A 120-unit fill was ~360 messages to every client.
- FST_skipSpawnDamage set locally (no consumers anywhere in the modpack).
- FST_HC_interceptQueued is only publicVariable-cleared when it was set (it was
  broadcast on every trackGroup / transfer / hold).
- Fill Garrison job state and FST_HC_LastHeavySpawnTime are server-only (were
  broadcast on every batch).
- emergencyStabilizeGroupLocal event skipped when the bandaid is off.
Server CPU:
- catchUntracked exits early when no HC can accept groups (all soft-capped);
  it used to re-queue the same groups every 30s and fail each one.
- catchUntracked no longer walks every unit of every untracked group looking for
  suppressed clone originals; the server marks the group instead.
- handleDisconnect uses a held-group cache instead of an allGroups scan on every
  player disconnect (150 players leaving = 150 scans).
- FST_HC_evt_recountUnits is debounced (one recount 0.5s after a burst).
- statusReport does one allGroups pass instead of two.
- checkObjectives skips the player build when nothing is pending.
- getSpawnTarget soft-cap EMERGENCY log throttled to once per 30s.
- FST_HC_LastHeavySpawnTime is no longer bumped by single Zeus placements, so the
  despawn cleanup actually runs under steady Zeus activity.
Server + HC CPU:
- enforceDroidStance: cheapest filters first, and only units still on stance
  AUTO get setUnitPos (also stops it overriding stances Zeus set on purpose).
- initExplosionDiag caches per-ammo config data (was 4-7 config reads per shot).
Client:
- getFSTOpforUnitOptions pre-filters CfgVehicles by the FST_ prefix inside
  configClasses instead of running isKindOf on every class in the modpack.

============================================================
NOT CHANGED (verify in-game before touching)
============================================================
- buildingPos positions are used as ATL for placement and the water safety
  trace. On land ATL==AGL so it is fine; over piers/water structures the Z may
  be off. Test a pier garrison before changing.
- Instant clone still drops unit identity (name/face/voice/varName/setVariable
  data). Documented in fn_interceptZeusPlace.
- explosion diag enable is read once at postInit (needs a restart to toggle).

Test checklist:
- RPT shows the V27 strings on server AND each HC.
- Place a squad, immediately Shift+F2 hold: it stays on the Zeus client
  (Shift+F4 report shows it under "Zeus held", not under an HC).
- Non-Zeus player pressing Shift+F4 gets "admin or Zeus only".
- Fill Garrison with slider at 200 places up to 200 (was capped at 120).
- Editor-placed OPFOR near players, then leave for > Despawn Timer: still there.
- Zeus module "--- Cleanup Dead Groups ---" appears and reports counts.

============================================================
IN-GAME SMOKE TEST 2026-09-20 (dedicated server + 3 headless clients)
============================================================
Ran on Arma 3 2.22 with the full September V1 mod list, VR map, this build.
Passed:
- All 3 HCs register (owners 4/5/6). 9 quick spawns balance across them by
  unit count (e.g. 23/28/21). quickSpawn from a fake owner ID is rejected
  with the [AUTH] log line. Server-created droid group is caught and moved to
  an HC. Zeus hold/release round trip keeps ownership and re-tracks. Frontline
  path spawns and tracks. Recount matches real unit totals.
- HC crash: process killed. Server saw the drop in 15s, cleared 4 orphaned
  groups, ran the 120s safe mode, then the catch-all moved every orphan onto
  the surviving HCs (35/36 units, 0 on server, 0 on the dead owner).
Fixed from the test:
- XEH_postInit: the 60s HC re-register PFH fired on the frame it was added
  (CBA behaviour), racing the primary registration and double-registering.
  The check is now armed 60s after postInit.
- fn_fpsMonitor: each (re)registration stacked another PFH on the HC. The
  function now removes its previous handler before adding a new one.
Server config note (live server, not the addon):
- kickClientsOnSlowNetwork[] 4th element must be 1 (or the entry absent) so
  a crashed HC is actually dropped by the engine. With it set to 0 the engine
  only logs "DisconnectTimeout too high" and HandleDisconnect never fires, so
  the dead HC's droids stay frozen until it reconnects. disconnectTimeout
  (5-90s) sets how fast that happens.

============================================================
V28 -- DEDICATED VEHICLE HC (2026-09-20)
============================================================
Why: crewed AI vehicles handed to an HC mid-motion split crew and hull across
machines for a few frames, which broke multi-crew coordination, so vehicle
offload had to stay disabled. V28 creates vehicles on their final owner
instead of moving them, and keeps that owner free of infantry.

Settings (FST HC Spawn > Vehicle HC):
- Dedicated Vehicle HC (default on)
- Vehicle HC Slot (default 4 = the HC that registered as HC4). If that slot is
  not connected, vehicles fall back to the least-loaded HC.
- Keep Infantry Off The Vehicle HC (default on)
Hidden: FST_HC_VehicleTransferMaxSpeed (1.5 m/s) for the transfer safety check.

What goes to the vehicle HC:
- "--- Vehicle Spawn ---" Zeus module (FST_HC_VehicleTemplates: AAT, N99, MTT,
  PAC, SAC, HMP, Vulture/AA/CAS/Elite), count/behaviour/skill/airborne.
- "--- QRF Response ---": any QRF with a transport or escort is built entirely
  on the vehicle HC (fn_qrfBuildLocal via ownerEvent). Passengers are moved to
  an infantry HC once every one of them has dismounted (re-home path).
- Ship QRF vultures (41st_Armor Modules.sqf: Munificent, Providence, Diamond,
  Providence Jorge) now call FST_HCSpawn_fnc_spawnVehicleOnTarget when the
  addon and an HC are present; otherwise the old server-side spawn runs.
- Any script: [side, class, pos, dir, behaviour, radius, callerOrMinusOne,
  options] call FST_HCSpawn_fnc_spawnVehicleOnTarget, or the
  FST_HC_evt_spawnVehicle server event from a Zeus client.
- "--- Send To Vehicle HC ---" Zeus module for placed vehicles: moves the
  selected group only when every vehicle is stopped, landed, fully crewed by
  that group and has no player aboard. Bypasses "Blacklist All Vehicles".

Transfers: fn_transferGroup routes mounted groups to the vehicle HC and refuses
unsafe ones (fn_isVehicleTransferSafe), then verifies vehicle and crew ended
up on the same owner and logs a [WARN] if not.

Also fixed: QRF passengers never dismounted at the TR UNLOAD waypoint
(moveInCargo assigns them to the vehicle; the waypoint only ejects unassigned
cargo). They are now ejected on arrival.

Smoke test 2026-09-20 (server + 3 HCs, slot 3 as vehicle HC): infantry only
ever landed on HC1/HC2; AAT/PAC/vultures all created on HC3 with hull and crew
on the same owner; ground vehicles drive MOVE orders and QRF convoy routes;
vultures airborne at 150+ m/s; stationary AAT sent over, moving AAT refused;
QRF passengers dismounted and re-homed to HC2.

Live-server checklist for the vehicle HC: 4 HCs connected (HC4 = vehicle HC),
mission has 4 HeadlessClient_F slots, server.cfg has localClient[] with the HC
address, Per-HC Soft AI Cap raised (op log showed all 3 HCs over 240).
