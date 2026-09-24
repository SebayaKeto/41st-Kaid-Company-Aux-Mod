# Candidate qualification — September 23

**Rehearsal candidate, not a fully cleared live release.** The infantry, BX task, configuration, fog and DAARA checks passed. AAT navigation is improved in some cases but remains inconsistent; Preacher's client-specific invisibility is not root-caused. No Workshop update or live-server replacement was performed.

## Evidence

| Area | Result | Scope |
|---|---|---|
| Infantry, BX and N99 full suite, run33 | 48/48 | Four real HCs; actual rockets at 25/45/75m; rifle shots at Saber; FST-held positions; 4/12-unit firing squads; BX prone/ambush/melee and cleanup |
| Repeat suite, run39 | 47/48 | Reproduced a second N99 race: an old task ran on the new owner before the replacement task arrived. Final repair keys the driver update to both owner and task revision. All other checks passed again. |
| Final N99 replacement suite, run41 | 7/7 | Two N99s, two HC owners, replacement orders during server→HC and HC→server transfers. This uses the final HCSpawn PBO. |
| DAARA 0.3 with updated Aux, run34 | 36/36 | Real HC spawn of 12 units and defend acknowledgment, budgets, capture identity/idempotence and director gates. Subsequent Aux changes affect tank movement only. |
| Gulanthars, run31 | 21/21 creature checks | All three classes moved on flat, uphill and downhill terrain; climbing state entered uphill; no missing animation states. Native pauses/attack timing are preserved. |
| Natural-terrain armor, run31 | 38/42 total checks | Four failures: AAT did not fire in rear and slope cases for both baseline and candidate. Both still moved and aligned in those cases. This does not establish a universal improvement or prove why firing failed. |
| Visible Saber armor fixture, run35 | 12/12 | Firing, movement, facing and turn cleanup passed for front/rear/obstacle. Revealed that a recovery waypoint could still leave a driver stopped; led to direct bounded driver recovery. |
| Stronger armor recovery fixture, run38 | 13/15 | Rear/obstacle reached the firing band; front case failed sustained facing and firing-band distance. All cases fired and cleaned up turn control. Residual AAT behavior remains open. |
| Alternative steering trial, run40 | 13/15; not adopted | Removing the short stop did not resolve the firing-band failures. `trialArmor.sqf` is test-only and is not inside the final Aux PBO. |
| Fog after weather guard, run36 | 3/3 | Actual density 0.619048, decay 0.017, original fog base retained. No measurement of human visual range is claimed. |
| Build integrity | Passed | All three configs compiled with CfgConvert; every packed source entry read back byte-for-byte; original baseline PBO hashes preserved. |

The final HCSpawn hash is in `build-verification.json`. Runs retain their own loaded hashes and fixture hashes; earlier passing suites are not mislabeled as tests of a later binary. The last source change affects only the N99 driver task key, covered by run41. AAT/Gulanthar behavior is inherited unchanged from the component versions identified above.

## Remaining checks before a live release

- AAT orientation, sustained movement and rough-terrain navigation remain inconsistent. Keep the tankers' liked firing/standoff tactics; do not interpret “moved” as “all pathfinding fixed.”
- Diagnose Preacher on an affected player client using the explicit visibility diagnostics. The new selected-player reset helps only a hidden object; it cannot repair missing replication or assets. No root cause is claimed.
- Verify the Zeus map picker and task menus visually, BX melee appearance, human-crewed Saber interaction and fog visibility on a graphics-capable client. This box runs dedicated servers and HCs only.
- Rehearse the resulting combat difficulty. B1 precision and damage were retained, but earlier reactions mean more firing opportunities.
- No 100-player performance/load certification is claimed. Existing dependency warnings (including creature ACE hitpoints and inherited model/config errors) are preserved in raw RPTs; the final changed SQF paths did not generate script errors in the completed checks.

Earlier failed development fixtures remain in `QUALIFICATION.json`: run27 exposed an empty formation-slot array; runs28/30 corrected invalid occlusion setup, stance restoration and locality handling; run29 had a test arithmetic error; run32/39 exposed the two N99 races. Run37 was deliberately stopped before testing to release a locked mission file. These are not counted as passing qualification.

DAARA 0.4 counterattack development is a separate candidate in the user's Daara Testing task. It is not silently included in this sealed 0.3-based package.
