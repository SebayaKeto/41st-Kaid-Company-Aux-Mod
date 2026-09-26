# Gulanthar hills and hesitation — 26 September 2026

Miran asked why Gulanthars still struggle with hills and wanted them to stop hesitating near players. This build sits on top of the Codex cap/pursuit candidate (`docs/gulanthar-pursuit-2026-09-26`), which is included unchanged apart from the lines below. It is staged for the next Workshop update and is not published yet.

## Causes found

1. **Engine slope limit plus a walk-only move set.** `CfgSlopeLimits` (vanilla `data_f`) forbids AI sprinting above a 0.3 grade (about 17°) and running above 0.6 (about 31°). The Necroplague form939 move set maps its run actions (SlowF/TactF) to `form939_walk`. So once a slope removes the sprint, the creature walks at about 1 m/s. In testing, native creatures walked on 93–98% of samples on 18–27° lanes.
2. **The old climb gait was a walk.** `BURNS_gulanthar_climb` played the walk animation 2.2× faster, about 2 m/s. Above 33° even that was dropped.
3. **Gaits forced from idle froze the creature.** The helper forced the run gait onto an idle creature while its path was still being planned. The creature then stayed idle until the native stuck handler intervened, about 20 s later. This happened at spawn and after every attack.
4. **Constant re-ordering.** The candidate controller re-issued `doMove` every 0.5–1 s. Each order restarts path planning, and a gaited creature drops to idle while it replans.
5. **Gait upkeep under load.** The shared BURNS engagement service visits four groups per 0.1 s and one creature per group, so in a busy op each Gulanthar was serviced only every several seconds.

## Changes

- **`FST_BURNS_Gulanthar/config.cpp`:**
  - The climb gait now uses the gallop animation (`form939_sprint` file, speed 2.5), classed as a normal run (`useFastMove=0`), so the sprint slope limit never applies.
  - Its actions map every movement to itself.
  - When a slope forces the native sprint down to SlowF/TactF, the creature gallops instead of walking.
- **`FST_HCSpawn/fn_burnsGulantharSlope.sqf`:**
  - The climb band has no upper limit and also covers descents steeper than −25°.
  - Gaits are never forced onto an idle creature.
  - The stall-recovery order yields for 4 s after a controller order.
- **`JMSEF_animals/functions.sqf`:**
  - While charging, the controller re-orders only when the target has moved more than max(4 m, 15% of the distance), the order has finished, or the creature has stalled for 3 s.
  - The controller calls the gait helper at its own cadence.

## Evidence

The test harness is `tests/gulanthar-hills-2026-09-26`. It is an isolated dedicated server with CBA, Necroplague Mutants, Improved Melee System, WBK Zombies and the three archives. Each run used 12 clear Altis lanes (4°, 18°, 27° and 33–35°), one creature per lane with all three variants, and an invulnerable target 60 m up-slope. After a creature reached the target, the target jumped back to the lane start and fled downhill. Variants were run with and without 80 extra AI groups present.

| Measure | Old candidate | This build |
|---|---:|---:|
| Median time to climb 45 m on 18–35° lanes | 21.1 s | 11.6 s |
| Median time to close 10 m after the target flees | 20.6 s | 6.0 s |
| Fleeing target caught on uphill lanes | 2/9 | 8/9 |
| Same with 80 extra AI groups: climb 45 m | 26.1 s | 11.5 s |
| Native (no helper) climb 45 m | about 40 s or never | — |

`results-runs3-5.txt` holds the per-lane rows.

Runs 1–2 were exploratory, testing native, candidate, gallop variants and order policies; their RPTs are in `D:\AuxUpdater\gulhill\profile`.

Not covered:
- human players or multiplayer/HC ownership transfer;
- slopes steeper than about 35° (Altis has no clear 60 m lanes that steep);
- tuned downhill behaviour.

The old 8-creature cap is gone, so large packs still need frame-time monitoring.
