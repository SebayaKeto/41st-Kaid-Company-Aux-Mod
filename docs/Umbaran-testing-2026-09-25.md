# 41st Umbaran units with BURNS — independent validation

Tested 25 September 2026 in a separate loopback dedicated-server session. The corrected Umbaran addon was verified against source and tested without additional balance changes. This is a staged Aux patch, not an installed or published update.

## Combat comparison

Eighteen native-AI 4-versus-4 firefights: six scenarios per unit class, using defend, assault and hunt at 120–180 metres, with open ground and sandbag cover. Each team faced four identical vanilla NATO riflemen at skill 0.5. The tested teams retained their own weapons, armor, authored skills and BURNS roles. Starting lanes rotated between scenarios. All sides could take real damage. No target reveal, forced-fire command or scripted damage was used in this comparison; BURNS' own suppression behavior remained active.

Each scenario ran for 75 seconds. “Active survivors” excludes incapacitated soldiers. “Opponents down” includes killed and incapacitated enemies, not guaranteed deaths. First-shot time is measured from the start of each fight. These are six different scenarios per class, not a large repeated statistical trial or a test of intelligence in isolation.

| Team | Active survivors | Opponents down | Median first shot |
|---|---:|---:|---:|
| B1 riflemen | 4/24 | 13/24 | 5.21 s |
| Ordinary Umbarans | 24/24 | 24/24 | 4.99 s |
| Umbaran SpecOps | 20/24 | 23/24 | 3.61 s |

### Actual 41st clone opponents

Nine additional native-AI 4-versus-4 fights used `FST_Trooper_P2_DC15S` opponents. This clone class actually spawns without a rifle by default, despite its name. An initial unarmed fixture was stopped and excluded. The corrected fixture explicitly equipped every clone with `FST_DC15S`, eight `FST_blaster_cell_Blue` magazines and an assault pack for ammunition, retained the class's armor, and set skill to 0.5 after initialization. Every opponent's loaded rifle and skills were logged and checked before starting each fight. Each tested class ran defend at 140 m on open ground, assault at 140 m with cover, and hunt at 180 m with cover, for 60 seconds per scenario. No scripted damage, reveals or forced-fire commands were added. This brought the valid comparison total to 27 firefights.

| Team | Active survivors | Clone opponents down | Median first shot |
|---|---:|---:|---:|
| B1 riflemen | 0/12 | 2/12 | 3.97 s |
| Ordinary Umbarans | 7/12 | 4/12 | 3.53 s |
| Umbaran SpecOps | 9/12 | 8/12 | 3.10 s |

Both human classes exhibited flank-and-suppress during hunt; B1s used line-advance. Umbarans retained native cover, suppression and combat AI. Ordinary infantry general/leadership skills were 0.8 versus B1 0.5; SpecOps general skill was 1.0. Ordinary Umbaran and B1 aiming accuracy both measured 0.5; SpecOps retained its authored 0.95. This verification introduced no additional accuracy buff.

## Unit, group and ownership checks

- All 11 unit classes loaded with usable weapons/ammunition; the Commander intentionally uses a pistol.
- All seven group presets spawned at expected strength: fireteam 6, anti-air 3, marksmen 3, standard squad 16, anti-tank squad 16, SpecOps pair 2, SpecOps team 4.
- All classes were recognized as human infantry by BURNS, with Medic and Engineer/EOD specialties intact.
- Four real headless clients joined. Server-to-HC transfer preserved loadouts and human settings. The production HCSpawn creation path also created an armed group that advanced on an assault order.
- The follow-up checked every group preset accepting assault, moving, and clearing its task/restoring pathfinding after stop. AT and AA units had loaded secondary launchers. Dedicated vehicle/aircraft kill effectiveness was not measured.
- Initial integration result: 57/58 passed. Follow-up result: 31/31 passed.

## The detection failure is retained

One fireteam did not fire at an invulnerable, stationary exposed target at 140 metres within the original 30-second window (target knowledge was about 0.58). Its assault and hunting counterparts passed. This failure has not been relabeled as a pass.

Three fresh fireteams and three six-unit B1 teams then received the same defend task against stationary targets at 140 metres, with a 90-second observation window. No target knowledge or firing was forced. First-shot measurements below distinguish eventual engagement from meeting the original 30-second threshold.

| Team | Repeat | First shot | Rounds fired |
|---|---:|---:|---:|
| UmbaranFireteam | 1 | 5.83 s | 443 |
| B1Six | 1 | 6.63 s | 464 |
| UmbaranFireteam | 2 | 4.34 s | 624 |
| B1Six | 2 | 3.54 s | 558 |
| UmbaranFireteam | 3 | 5.95 s | 320 |
| B1Six | 3 | 3.75 s | 315 |

## Durability and practical limits

The 36 repeated projectile trials produced substantial variation and censored B1 results (some targets remained active at the 16-projectile limit). The earlier report's fixed median advantage did not reproduce consistently. This validation therefore makes no universal durability or shots-to-kill claim; the native firefight results above are the practical comparison.

Tests used VR terrain in daylight, including a controlled cover layout. Actual Umbara vegetation/fog, graphical appearance, player-fired weapon behavior, player latency and large operation loads still require a gameplay rehearsal. The comparison server's sampled FPS was 26.1–32.4 with a 35 FPS cap; this is not a full-server capacity benchmark.

The script-error scan across all three runs and all five nodes found 0 matching expression/undefined/missing/generic error lines. Separately, hitpoint-expression compilation errors were reproduced in the diagnostic B1 spawn before either Umbaran class was created; the preceding vanilla infantry spawn did not emit those errors. Thus these errors are not specific to the new Umbarans. This does not establish that every armor calculation is correct, and they remain recorded in `hitpoint-compile-diagnostics.json`. Other modpack startup/config warnings also remain. Existing BURNS server processes and files were not changed.

## Tested build and delivery

Umbaran source commit: `dc2d6c11afd88e3674ce5d7265b16617e4c68032`. Addon SHA256: `c999a8eec9501c5b810951b2808d6f76205552c819e701a17bdd909beb426b4c`. All 59 private Aux PBO hashes were checked after testing and were unchanged. The tested HCSpawn and Combat PBO entries also matched current repository source.

The patch fixes the addon identity/dependencies, OPFOR alignment, vest and SpecOps uniform setup, native infantry armor, initialization/locality timing, authored human skills and Medic/EOD specialties. The source changes are accompanied by independent integration and combat-comparison evidence.

The exact tested addon is committed at `PUBLISHED MODPACK/41st_UmbaranUnits.pbo` through Git LFS. It is an unsigned patch requiring the existing Aux/dependency set. It has not been installed into live server folders, signed or published to Workshop. Server, headless clients and player clients need matching updated Aux files in a fresh session for deployment.

All three test missions and machine-readable summaries are under `tests/umbaran-2026-09-25/independent-validation/`. The full raw logs, including the excluded unarmed-clone setup and original timing failure, are retained in the local validation delivery's `Runtime-Evidence.zip`. The original failed timing check is also retained in the committed `results.json`.

## Individual firefights

| Scenario | Order / range / layout | Team | Active survivors | Opponents down | First shot |
|---|---|---|---:|---:|---:|
| 1 | defend / 120 m / open | B1 riflemen | 3 | 4 | 3.19 s |
| 1 | defend / 120 m / open | Ordinary Umbarans | 4 | 4 | 3.32 s |
| 1 | defend / 120 m / open | Umbaran SpecOps | 2 | 4 | 3.38 s |
| 2 | assault / 120 m / open | B1 riflemen | 0 | 3 | 6.85 s |
| 2 | assault / 120 m / open | Ordinary Umbarans | 4 | 4 | 2.91 s |
| 2 | assault / 120 m / open | Umbaran SpecOps | 4 | 4 | 2.45 s |
| 3 | hunt / 180 m / open | B1 riflemen | 0 | 3 | 7.16 s |
| 3 | hunt / 180 m / open | Ordinary Umbarans | 4 | 4 | 6.67 s |
| 3 | hunt / 180 m / open | Umbaran SpecOps | 3 | 4 | 6.08 s |
| 4 | defend / 180 m / cover | B1 riflemen | 1 | 2 | 12.33 s |
| 4 | defend / 180 m / cover | Ordinary Umbarans | 4 | 4 | 8.03 s |
| 4 | defend / 180 m / cover | Umbaran SpecOps | 4 | 3 | 8.03 s |
| 5 | assault / 180 m / cover | B1 riflemen | 0 | 1 | 3.57 s |
| 5 | assault / 180 m / cover | Ordinary Umbarans | 4 | 4 | 8.09 s |
| 5 | assault / 180 m / cover | Umbaran SpecOps | 4 | 4 | 3.85 s |
| 6 | hunt / 120 m / cover | B1 riflemen | 0 | 0 | 3.38 s |
| 6 | hunt / 120 m / cover | Ordinary Umbarans | 4 | 4 | 2.85 s |
| 6 | hunt / 120 m / cover | Umbaran SpecOps | 3 | 4 | 2.54 s |
