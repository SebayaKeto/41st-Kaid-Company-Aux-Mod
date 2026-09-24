# Qualification — 24 September test candidate

**198/199 selected dedicated-server/HC checks passed, plus 99 adviser offline tests.** This is a rehearsal build with open issues, not an unrestricted production sign-off. N99 owner-transfer movement remained intermittent in development runs even when the focused test passed. Hill rollback and Preacher visibility remain open; Saber reverse speed needs a player-driver check.

| Suite | Passed | Evidence run |
|---|---:|---|
| AAT approach and setting restoration | 9/9 | run88-tonight-range |
| Three-AAT column, firing line and four-HC transfer | 22/22 | run90-tonight-sections |
| Focused N99 movement and owner transfers | 7/7 | run87-tonight-n99 |
| Section validation and takeover cleanup | 16/16 | run95-tonight-guards |
| DAARA 0.4 counterattack contract | 71/71 | run91-tonight-daara |
| Saber variants, turning and forward speed | 26/26 | run96-saber-final |
| Combined B1, AT, garrison, BX and N99 regression | 47/48 | run97-tonight-combined |

The first five suites used the exact three packaged AI addon hashes, before the separate Saber handling addon was added. The final Saber and combined-regression suites used **all four final addons together**. No AI source changed between those suites. Every replacement configuration compiled and every PBO entry was read back against source. The complete 65-file Aux was hashed against its frozen baseline plus the exact patch and test metadata.

## What was measured

- Assault, Rush and Hunt AATs each approached from 400 m, entered the 100–200 m firing band and fired. The preferred goal is 150 m; native stopping distance and line of sight affect the actual distance.
- The three-tank AAT section moved in column, deployed fixed firing slots and all three fired. Four real HC transfers and restoration of task-owned settings passed. Guards cover four-tank rejection, external holds, replacement/native waypoints and protected takeover. Two-tank acceptance/cleanup was exercised; the full moving-line exercise used three tanks.
- Saber, Super Saber and Recon each turned through 90 degrees in about 3.1 seconds. Earlier baseline comparisons measured 5.1–5.3 seconds for standard/Super and 6.2 for Recon. Standard/Super reached 59.4/59.6 km/h. Recon reached 99.3 within the test lane and retains its requested 120 km/h setting. All 16 skins/families inherited the new handling; upstream 3AS stayed unchanged.
- Saber BACK/KEY DOWN input probes failed to produce a valid reverse run, including with baseline tanks. These probes are retained in raw logs and **are not counted as successful reverse-speed tests**. The gearing change is staged for player calibration.

## Open results and test interpretation

N99 transfer stalls were reproduced in broad runs 85 and 93 (8 m and 15 m against a 30 m movement requirement). The deferred-order repair and approach-preserving combat mode improve some cases but do not establish a complete fix. Any same-name failure in the final combined run is expressly recorded in `KNOWN_ISSUES.json` and included in the denominator above, never silently excluded.

One earlier BX Ambush assertion failed on an instantaneous FIREWEAPON flag despite recording 33 shots after its trigger. The final fixture checks the trigger and actual firing; it retains the flag/animation in diagnostics. Hold-fire before the trigger and restoration after Stop remain separate checks. Native WebKnight animation control is not overridden just to keep a sampled flag enabled.

Failed hill recovery, four-tank formations, rejected driver-input experiments and incomplete runs are retained in `qualification/EVIDENCE.zip` and identified by `RUN_INDEX.json`. Only `FINAL_RUNS.json` contributes to the selected totals. Old qualification totals are not added again.

## DAARA and exact identities

DAARA's 99 offline tests were rerun with `python -m unittest discover -p test_*.py` in the extracted adviser directory. The original archive and all 62 payload checksum entries were verified before staging. The playable mission SHA-256 is `6027f601c90bbb2c11268cca2045c3b1f49c9be9a6cde32e7b65b2a9e91986ac`.

- FST_BURNS_Combat.pbo: `591e11a23f0169827c38beb43ce59bf259a559b8b683f7fbb7b185cbb8bf0c6a`
- FST_BURNS_Gulanthar.pbo: `feab7bf6afe769b0e403162121d6d203682aba4bdb7d3dd22540e6ef2353949e`
- FST_HCSpawn.pbo: `021290fb22f637a2717cd3e42e07a0953977223d854dc777ecec18ae906713ac`
- FST_Saber_Handling.pbo: `554fbe66bf7544baf6db9c407ee6a650367ae0bd37694d254caed94fc237f2e3`

`FULL_AUX_MANIFEST.json` identifies all 65 files; `SHA256SUMS.txt` covers the portable package. This box has no GPU, so client visuals, Zeus interaction, actual Umbara approaches and operation balance still need tonight's rehearsal. Read `TEST_OP_CARD.md`, `SABER_HANDLING.md` and `REMAINING_WORK.md`.

The candidate and DAARA mission are prepared locally. Main/Training configurations and Workshop were not changed. Only explicitly isolated test processes were launched and stopped.
