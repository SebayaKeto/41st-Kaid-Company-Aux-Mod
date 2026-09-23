# September 23 candidate qualification

Status: local test copy prepared; **the full candidate is not cleared for tonight's live operation**. AAT facing/engagement remains inconsistent. The verified Gulanthar repair is included; experimental AAT changes are not.

The independent local Aux copy is `@Kaid_Aux_Candidate` beside this report. It contains the installed mod plus the incoming Armor, HCSpawn, Combat and Gulanthar candidates. The supplied Gulanthar PBO failed runtime movement tests and was replaced here with the verified repair described below. The training server and its mod staging directory were not changed.

## Verified intake and build

- Handoff: 25 file checksums and five transfer-package checksums matched.
- Integrated and pod archives: all 152 and 12 inner manifest entries matched.
- The separately transferred Armor PBO matched the expected SHA-256.
- Candidate PBO contents were compared with their included source. Armor has only the two intended script differences from the installed PBO; 1,851 other entries match.
- `candidate-manifest.json` records the incoming copy; `final-candidate-manifest.json` records the repaired copy. `repair-audit.json` records the difference and source readback.

## Dedicated-server results

Tests used the same 97-mod dependency preset, the profiling 2.22 server executable, loopback-only isolated ports and, for the main and combat suites, four real headless clients. No graphical Arma client was launched.

| Area | Observed result |
|---|---|
| Four HCs | All four joined. HC4 was selected for vehicles. B1 group ownership was acknowledged locally by every HC. |
| B1 formations | COLUMN advanced about 30 metres in 12 seconds; contact changed it to LINE; 12 distinct slots and a fixed assembly front were observed. |
| B1 controls | Hold fire, Zeus hold, native travel orders, exemptions, protected BLUFOR vehicles and boarding cleanup passed the exercised checks. |
| E5 assistance | Real ammunition was fired at an AI-crewed vehicle. Active infantry took priority. Prisoner/surrender guards, revival cancellation and delayed group-merge cleanup passed. |
| AAT weapons/movement | Cannon and side-gun shots occurred with no task, Rush and Hunt. The focused VR suite passed front/side/rear firing, latch release and native-order protection. Subsequent repeated trials exposed inconsistent hull facing and occasional no-fire cases. This remains a release blocker. |
| Gulanthar | Repaired build passed 37 checks across normal, Berserker and Alpha: natural flat/uphill/downhill movement, climbing state, feature-disable release and external attack transitions. |
| Full pod deployments | Each of Munificent, Providence, Diamond and Jorge Providence submitted 24 drops and produced 24 impact craters. Living troop counts were 90, 92, 92 and 81 in that run. A separate 24-drop trial produced 99 living troops. |
| Pod faults/concurrency | Missing-all-anchor abort passed. Independent dry-ground suite passed 9/9: half-anchor reuse submitted 24 drops, coordinates followed terrain around 188 m elevation, ship destruction stopped the next iteration, and simultaneous ships submitted 48 drops. |

Delivery is not loss-free: in the clean half-anchor stress case, 98 infantry creations were recorded and 79 remained alive after one minute. In the clean concurrent case, 193 were created and 182 remained alive. The cause of every loss was not isolated; repeated landing locations and terrain require a client rehearsal. The earlier concurrent run had 152 living troops. Do not describe these results as every delivered droid surviving.

## AAT disposition

The original candidate fired in the principal tests, but one repeated front-target Rush trial presented its front within 55 degrees of the target in **0 of the final 20 samples**, despite firing 13 shots. Side/rear trials did better. A mission-only feedback-based steering experiment improved the facing samples but failed to fire in one rear-target trial, so it was not promoted.

Disabling the entire assist also failed to provide a general fallback: a rear target behind an unassigned AAT did not receive fire during that observation. The CBA setting was confirmed disabled on the server and all four HCs. Consequently no supposedly safe disabled-assist override is included in the staged operation mission. A narrower mission-only native-task-movement experiment is documented separately in the test evidence; it is not part of the addon.

These were repeatable scripted fixtures with AI-crewed, invulnerable targets, not proof of player-vehicle or visual behavior. Target physics remained enabled. Keep the AAT changes out of an unconditional release signoff until this behavior is resolved and checked with a client.

## Gulanthar repair

The supplied movement class exposed the climbing state but failed to load the inherited normal movement graph. All three variants remained stationary with animation `<none>`; logs reported missing movement connections and `NoActions`.

The repair adds an opt-in climbing state to the existing complete `CfgMovesForm939` graph, preserves its Actions inheritance, and adds an explicit walking-to-climbing connection. The Gulanthar-only helper selects it. Existing walk, sprint, attack and eating states are not overwritten. No external model, animation or behavior asset was copied into this addon.

On natural Altis slopes, the three variants advanced approximately 57.4, 55.5 and 60.4 metres during the 30-second observations. Climbing was observed in all three; flat and downhill trials used native states. This is behavior evidence, not a comparative performance benchmark.

The repaired PBO SHA-256 is `feab7bf6afe769b0e403162121d6d203682aba4bdb7d3dd22540e6ef2353949e`.

## Mission compatibility

The bundled Daara Test2 mission still forced `zen_context_menu_overrideWaypoints = true`. The staged `missions/DaaraUmbaraTest2_Candidate.m_36vwm796742s99.pbo` changes that single setting to `false`. All 21 PBO entries were compared; only `cba_settings.sqf` differs. Its adviser, objectives and other mission content are unchanged. This mission has not received a human rehearsal in this task.

## Evidence and test limitations

Raw RPT logs and process records are preserved under `runs/`. `runtime-results.json` includes passed and failed assertions, including superseded fixtures. A raw pass total is not release clearance.

- Runs 01–04 were harness-startup attempts, not behavioral qualification. Run 05 established initial engine behavior but had only three registered HCs and several fixture timing/ownership errors.
- Run 06 tested the incoming build. The VR ramp remained flat, so its uphill assertions were invalid; the broken Gulanthar movement graph was a separate genuine defect. Its AAT cleanup assertion also confused removal of a task with disabling the still-active no-task assist.
- Run 07's strict hill search found no site. Its fallback pod site crossed water. Its immediate group-merge assertion ran before the scheduled cleanup; the repeated check with a one-second wait passed in run 09. Destroying a ship inside anchor selection allowed one already-started request, then correctly aborted the next iteration.
- Run 08 is the complete repaired Gulanthar trial: 37/37. Run 09 is the focused combat trial: 17/17.
- Run 10 measured blocked Altis gunner visibility, explaining the initial no-fire case. Later AAT checks in that run were invalidated by a missing test helper and cleanup shared with another fixture; they are not used as combat qualification. Its unmodified external-creature control reproduced the blood-particle expression warnings seen during Gulanthar attacks.
- Run 11 compared original, experimental feedback steering and disabled assistance. Its experimental rear firing failure is retained. Run 12 is the independent dry-ground pod suite: 9/9, without the unrelated AAT fixture.
- Run 13 was stopped because the fixture omitted CBA's mission-settings-file flag; its requested setting did not apply. Run 14 corrected that flag and confirmed the disabled setting on all five machines, but the fallback did not pass all firing/facing cases. This is why no disabled-assist deployment preset is recommended.
- Run 15 tested a mission-only version that separated native Rush/Hunt movement from hull-turn pulses. It passed 27/29 assertions, including its Rush/Hunt cases, but failed unassigned front-facing consistency and unassigned rear firing. It was not promoted. Neither this experiment nor run 11's steering experiment changes the delivered PBOs.
- Dependency/config warnings exist in these modded-server logs. They are not described as globally clean. Blood-particle warnings also occur on the unmodified external creature, separate from the movement-graph repair.
- AI targets were used, often invulnerable and explicitly revealed to make fixtures repeatable. These checks do not establish natural detection range, player damage behavior, human network conditions or visual correctness.

## Required client rehearsal

This GPU-less machine cannot complete the human-client portion: Zeus right-click/context actions and possession, player Saber/Raider protection, real ACE incapacitation/revive/carry/drag, cross-HC casualty contention, rendering and pod collisions from a player's view. The Daara adviser/live-model and two-player rehearsal were not performed. No 100–150-player / 800–1000-AI qualification is claimed.

Use exactly the same candidate on the test server, all HCs and rehearsal clients, with no duplicate older Aux or optional AAT preview loaded. This candidate remains unsigned; use the normal signing process if enabling signature enforcement. No Workshop publication or live FASTER selection was performed.

## Local files and repository

- Mod copy: `@Kaid_Aux_Candidate/`.
- Verified standalone repair and source: `repaired/FST_BURNS_Gulanthar.pbo` and `repaired/config.cpp`.
- Staged mission: `missions/DaaraUmbaraTest2_Candidate.m_36vwm796742s99.pbo`.
- Rollback: `rollback/Addons/` contains verified copies of the three affected installed PBOs. Their live hashes still match the intake baseline; the new Gulanthar addon remains absent from the live mod.
- Exact-file manifests, content audits and raw logs are beside this report.
- Repository branch: `codex/qualify-sept23-candidates`, using an isolated worktree under this task's `work/candidate-repo`. The original repository's `main` checkout was not replaced. Changes are local; nothing was pushed.

All isolated test processes were stopped after testing. The original training server was left running. The isolated runtime now has no mission selected by default, so relaunching it cannot accidentally start an experimental test mission.
