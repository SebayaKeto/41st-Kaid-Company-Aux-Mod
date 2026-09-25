# September 23 playtest fixes

This is a separate candidate. The published Aux, running Main, independent training server (2328/2329), and ended adviser session are preserved.

The latest debrief takes precedence: players like the extra B1 accuracy, and tankers **really enjoyed the AAT tactics**. This candidate preserves rifle accuracy, damage, AAT weapon profiles, target engagement and standoff tactics. Changes address reaction, movement and task execution.

| Feedback | Candidate change | Qualification limit |
|---|---|---|
| B1 squads circle/reposition instead of shooting; fireteams behave better | Frozen short formation bounds; stop correcting a unit's slot when it has a clear firing solution; same front for leader and followers | Dedicated tests compare 4/12 units; client combat feel still needs rehearsal |
| B1 leader gets far ahead | Leader shares the frozen front and waits for lagging ranks | Test includes leader displacement; uneven-terrain squads need observation |
| B1s ignore Saber except AT | Mounted crew no longer counts as competing exposed infantry; held FST garrisons can use the existing E5 armor service | Real E5 shots against AI-crewed Saber; human-crewed multiplayer check remains |
| AT hesitant below 60 metres | Launcher AI range curve starts at 15m; a detected, visible nearby armored target prompts native launcher selection | Real rockets at 25/45/75m; no scripted damage or forced rocket launch |
| Defense/FST garrisons slow to engage exposed players | Restore marching AI restrictions without releasing stations; bounded quarter-turn attention scans; request fire at perceived visible threats; avoid repeated defensive movement orders while engaging | Rear-contact fixture; darkness, windows and human exposure need rehearsal |
| B1 accuracy initially criticized, later liked | Preserve accuracy and damage; response changes are separate | More firing opportunities may change difficulty despite unchanged precision |
| AAT terrain stalls | Bound unsuccessful turn attempts, allow native driving recovery, try up to two short safe alternate approaches, and report persistent blockage | Natural-terrain/obstacle results in qualification report; no universal pathfinding guarantee |
| AATs still reverse into combat | Retain physical hull-turn assist with measured heading progress, bounded pulses and native recovery gaps | Front/side/rear approach measurements; legitimate retreat/reversing remains available |
| AAT tactics strongly liked | Preserve the successful target firing and standoff approach logic | Do not judge tactics solely by movement speed |
| Gulanthar closing/slope hesitation | Add climbing-entry/exit hysteresis and refresh stale idle pursuit only when native attack/animation control is free | Native attacks, damage, eating and cooldown timing remain intact; residual native pauses may remain |
| BX Creep does not go prone | Route BX Creep explicitly; task-owned prone posture and movement | Engine reports actual prone stance; graphical animation check remains |
| BXs react poorly to infantry | Bounded attention to native known, visible contacts; explicit task engagement | No omniscient enemy scan or repeated WebKnight loader |
| BX Task Ambush requested | New Zeus module and context action: hold concealed, hold fire, then engage detected visible infantry with weapons; initial trigger radius 50m | Native AI must detect the target; walls/friendlies/cancellation are tested separately |
| BX Task CQB should use melee | Close to visible infantry and trigger installed WebKnight melee animation/hit handling; no duplicate damage code | Engine records approach/animation; client visual timing remains |
| N99 Assault destination clicked but vehicle stationary | Preserve task mode, wait for unit ownership to settle on dispatch with at most three delayed retries, record exact vehicle/destination, and add bounded movement recovery | Initial and focused transfer tests passed, but broader runs still reproduce intermittent transfer hesitation; see REMAINING_WORK.md |
| Preacher entirely invisible to some clients, TFAR still audible | Add explicit selected-player visibility diagnostics/reset; protect asynchronous clone replacement against a player taking over an original | Root cause unconfirmed; reset cannot recreate an object missing from a client's replication or repair missing assets |
| Duplicate DAARA objective names; coordinates unusable | Included DAARA 0.4 Counterattack mission embeds an actual-map picker using exact IDs and mission acknowledgement | Server contract tested; human Zeus click-through remains |
| DAARA too passive, advice not translating into expected action | Separate DAARA candidate corrects encounter budgeting, safe spawn-ring search, pressure advice and visible director blockers | Adviser remains advisory; human-paced operation still required |
| Q_CloseAT missing brace popup | Experimental test-addon build now compiles configuration before packing; final replacements also compile and read back every entry | Failed trial retained; it was never a live Aux change |
| Players request only 5–10% more visibility through fog | Separate mission uses ground fog 0.65 / 1.05 (about 0.619); requested gain is clamped to 1.00–1.10; preserve height decay, base, lighting and indoor/Zeus relief | Five percent is a tuning target, not a measured increase in visible metres; player-client calibration remains |

## BX task defaults

Ambush holds the selected BX group where it is placed. It stays prone and silent until an eligible infantry contact within 50m is both known to the group and visible to a member. Once triggered, it uses normal ranged weapons while retaining its position. Reissue Ambush to rearm the concealment phase. CQB instead approaches nearby infantry for melee. Stop, Reset, replacement orders, disable, and ownership changes release only task-owned settings.

## Player visibility workflow

Select the affected player in Zeus, then use **BURNS → Player Visibility → Record visibility diagnostics**. This records each client's view of the same network object in its RPT, including missing-object reports. **Restore selected player visibility** explicitly clears that player's local/global hidden state. It does not restart the player, replace gear, reset TFAR or blindly unhide every player. Use it only for a player intended to be visible.

## Evidence

Read `QUALIFICATION.md` and `qualification/RUN_INDEX.json`, with the packaged run logs. Earlier failed fixtures remain identified rather than being counted as passing. Configuration checks and server tests cannot certify the Zeus GUI, all client assets, 100+ player networking, or the feel of an actual operation.

## September 24 additions

- AAT Assault, Rush and Hunt approach detected targets toward 150 m, with a 100–200 m firing band. Native fire-at-will waypoints preserve the movement order while allowing firing. Defend, hold and retreat are preserved; tanks do not automatically retreat merely for being inside 100 m.
- Optional Task AAT Section Assault (Test) coordinates two or three explicitly selected nearby AAT groups. Column travel becomes a spaced firing front on clear gentle terrain. Four-tank sections are rejected after inconsistent development results. Nearby unselected tanks are not recruited.
- Section Stop, replacement orders, native waypoints, protected/player takeover, disable and HC transfer release only owned settings. Driver behavior and attack permissions are restored.
- N99 movement is issued after waypoint creation with task and ownership guards, fixing lost orders during dispatch and transfer. Seven focused checks passed on the final build.
- DAARA 0.4 Counterattack is included as requested. Its bounded B1 counterattacks do not enable armor autonomy.
- Hill recovery experiments and torque increases are excluded. Hill rollback and Preacher's visibility root cause remain open.

- Player Saber handling: +20% torque, stronger turn assistance and revised reverse gearing across all 16 variants. Standard/Super retain 60 km/h; Recon retains 120 km/h. Reverse speed needs player calibration.
