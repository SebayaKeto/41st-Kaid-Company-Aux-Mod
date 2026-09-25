# Gulanthar sustained pursuit running

Normal, Berserker and Alpha Gulanthars use a dedicated running gait during the installed creature controller's aggressive movement orders. The running state is 20% faster than the native sprint state; the uphill gait is 22% faster than the previous climbing gait. Slow-forward animation selections retain the pursuit run, reducing repeated walk/idle interruptions.

The controller still selects targets and destinations and owns attacks, eating, cooldowns and damage. BURNS changes the locomotion state only, without changing animation-speed coefficients, enabling disabled AI features, teleporting creatures, or replacing external functions. It follows the native MOVE destination rather than requiring a separate Arma target-knowledge entry. Close approach yields to native walking within 3 metres of that destination. Steep slopes beyond the supported gait range remain native. Stalled-order recovery retains the known, visible-target gate and a cooldown.

The default-on CBA setting **Gulanthar pursuit running** controls the new run. The existing uphill setting controls climbing. Both respect global disable, unit/group exemptions, Zeus holds, player control, manual waypoints, disabled PATH/MOVE/ANIM, attachments and vehicles. BURNS stop/retreat/defensive intent prevents the helper from restarting pursuit assistance; a new hunt or patrol can enable it again. Native creature-controller movement remains native when assistance is disabled.

## Measured results

The dedicated server plus four HCs ran all three variants against a moving target with paired previous-helper/candidate observations. Test order was reversed on alternating owners. One owner received no scripted reveal, leaving target detection to the installed controller. Each variant has 600 quarter-second samples across five owners; elapsed runs were approximately 33 seconds because of scheduler timing.

| Measurement | Previous helper | Candidate |
|---|---:|---:|
| 95th-percentile ground speed | 26.0 km/h | 31.2 km/h |
| Samples moving faster than 15 km/h | 39.0% | 98.3% |
| Samples below 1 km/h | 11.3% | 0.0% |
| Mean forward progress per measured run | 106.2 m | 279.4 m |

**240 checks passed** across flat pursuit/command guards, real Altis uphill/downhill movement and eight-creature packs on all five owners. Checks cover native melee starts, attack/eating locks, normal animation coefficients, health, death, feature disable, manual orders, retreat/stop, exemptions and forced stops. Config compilation and packed-source byte checks passed. No new SQF or creature movement-graph errors were detected. Existing native blood/particle-expression diagnostics were retained separately.

The speed comparison uses an invulnerable target kept ahead of the creature to measure sustained pursuit. Those measurements and natural terrain tests used the same gait configuration with an initial 12m approach cutoff. A separate fleeing AI human test exposed slowing before melee range; the final build reduces that cutoff to 3m and repeats pursuit, eight-creature packs and all command/attack guards on the dedicated server and four HCs. This is not a human-player chase benchmark. Terrain tests validate progression on one natural Altis slope in both directions; arbitrary buildings, water, rocks and cliffs can still constrain native pathfinding. Human-client JIP and transfer of a running native creature controller between owners are not claimed.

The initial Altis comparison was rejected because uncontrolled spawn positions could land on structures; an initial fixture's baseline compilation and a verbose diagnostic also needed correction. Those preliminary logs are retained, not counted as final qualification.

## Delivery

The matching tested PBOs are `FST_HCSpawn.pbo` and `FST_BURNS_Gulanthar.pbo`. Use both with the installed dependencies and matching server/HC/player addon versions. No installed creature or WebKnight mod was edited; no live server or Workshop files were changed. The exact tested PBOs and matching source are in `PUBLISHED MODPACK`; test fixtures and summaries are under `tests/gulanthar-2026-09-25`.

## Final fleeing-human pursuit and remaining limitation

A normal AI human ran away without position resets. All five local owners completed the final pursuit test; target acquisition remains native. Two owners reached native melee; three did not reach melee before the approximately 84-second timeout, resulting in six failed extended-chase assertions. These failures are preserved and are not counted as passes. Late native acquisition and catch-up remain a limitation. This update is qualified for faster sustained locomotion and command/attack guards, not guaranteed interception of every fleeing target. The initial 12m cutoff test also failed its catch/melee expectations and is retained in the raw evidence; its shorter duration prevents a clean before/after interception comparison. Final measured minimum distances and first melee-animation times are:

- Owner 0: closest distance 8.74m; no melee before timeout.
- Owner 1: closest distance 3.02m; first native melee at 38.5s after release.
- Owner 2: closest distance 13.43m; no melee before timeout.
- Owner 4: closest distance 13.42m; no melee before timeout.
- Owner 3: closest distance 3.58m; first native melee at 50.4s after release.
