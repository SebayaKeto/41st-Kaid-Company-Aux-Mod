# September 24 downtime testing

The unchanged sealed Aux candidate passed all 48 regression checks with four real headless clients. This includes B1 firing and formation behavior, FST-held garrisons, AT at 25/45/75m, BX prone/ambush/melee/cancellation, all four HC posture restorations, and the N99 ownership-transfer order.

The AAT experiments used separate test-only PBOs. No experimental code was installed into Main, Training, the candidate source, or the sealed September 23 package. Do not deploy the lab builds.

## AAT results

Each case lasted 45 samples approximately one second apart. Front, rear and artificial-obstacle approaches used a stationary invulnerable Saber on flat VR terrain. Runs44/45 repeated each case twice; run46 ran each case once. These are diagnostic screening comparisons, not a population-scale or natural-terrain certification. “In range” means the final distance was below 155m; it does not prove the intended 120m standoff was held, and some trials closed much nearer.

### run44-verified-aat

| Variant | Cases ending in range | Facing enemy samples | Shots |
|---|---:|---:|---:|
| candidate | 5/6 | 176/270 | 15 |
| driver-aware | 6/6 | 237/270 | 29 |
| fire-only | 5/6 | 209/270 | 18 |
| short-pulse | 3/6 | 173/270 | 12 |

48/48 checks confirmed the selected variants executed and their steering controls released. These checks verify the fixture and cleanup, not that every vehicle achieved good tactics.

### run45-aat-orders

In this run, `fire-only` also disables group attack orders. In run44 it only removes scripted hull steering.

| Variant | Cases ending in range | Facing enemy samples | Shots |
|---|---:|---:|---:|
| candidate | 3/6 | 131/270 | 12 |
| driver-no-target | 4/6 | 201/270 | 15 |
| fire-only | 5/6 | 233/270 | 16 |
| no-attack | 4/6 | 197/270 | 14 |

48/48 checks confirmed the selected variants executed and their steering controls released. These checks verify the fixture and cleanup, not that every vehicle achieved good tactics.

### run46-aat-fire-cadence

| Variant | Cases ending in range | Facing enemy samples | Shots |
|---|---:|---:|---:|
| candidate | 3/3 | 85/135 | 6 |
| interval5 | 2/3 | 103/135 | 8 |
| once | 2/3 | 105/135 | 8 |
| once-no-turn | 2/3 | 92/135 | 8 |

24/24 checks confirmed the selected variants executed and their steering controls released. These checks verify the fixture and cleanup, not that every vehicle achieved good tactics.

## Interpretation and limits

The driver-only AWARE trial is promising: 6/6 cases ended in range and it faced the enemy in 237/270 samples, compared with 5/6 and 176/270 for the paired candidate. It still fired. This is a lead for a future candidate, not a finished fix: restoration on Stop, Zeus takeover, role changes and HC ownership transfers needs testing before this driver setting can ship. Gunner behavior, weapons and BURNS target/standoff calculations were retained in this trial.

Shortening steering pulses was worse in the repeated comparison. Removing native group attack orders alone did not eliminate inconsistent movement. The fire-order cadence results above help distinguish repeated commands from driver behavior; no single run proves a universal solution.

No rear-first movement samples were recorded in these controlled lanes. The user-reported reversing issue was not reproduced here, so it is not marked fixed. Rough terrain and actual client combat still need rehearsal. Preacher's client-specific visibility issue is also still unconfirmed.

## Correction to earlier evidence

Read `COMPARISON_ERRATA.md`. Arma rejected protected-function replacements in run31 and run40, invalidating their comparative labels. Run42 repeated that setup mistake and was stopped. The corrected lab registers each variant in its own PBO and records which variant executed. The separate 48-check full-candidate regression has no such replacement or rejection.

## Integrity and cleanup

`RESULTS.json` contains exact fixture and loaded-build hashes, rejected overrides, completed checks and individual case measurements. `evidence/RAW_LOGS.zip` retains the RPTs. `test-source` contains the fixtures and isolated lab source. The original candidate's three PBO hashes and sealed ZIP hash were rechecked after testing. The live-server configuration was not changed, and owned test processes were stopped at completion.

## Hill torque comparison

Read `TORQUE_REPORT.md` for the separate same-slope engine comparison requested during this session. This uses torque-only subclasses of the unchanged candidate.
