# 41st Saber handling rehearsal

The new `FST_Saber_Handling.pbo` tunes the standard, Super and Recon Saber families and their skins. It does not alter the separate Sabre APC or upstream 3AS tanks.

| Setting | Before | Candidate |
|---|---:|---:|
| Standard/Super maximum speed | 60 km/h | **60 km/h** |
| Recon maximum speed | 120 km/h | **120 km/h** |
| Peak engine torque | 6,000 | 7,200 (+20%) |
| Turning assistance force | 900,000 | 1,200,000 |
| Turning assistance fade range | 0–0.35 rad/s | 0.2–0.65 rad/s |
| Reverse gear ratio | −0.6 | −2.4 |

Forward gears, final-drive ratio, engine power, weapons, armor and damage remain unchanged. The reverse ratio supplies four times the gearing multiplication at the same engine torque, trading excessive theoretical reverse gearing speed for usable pulling force. That is a configuration change, not a claim of four times the measured reverse speed.

The initial side-by-side dedicated-server trial measured 90-degree turns at about 3.1 seconds for the candidates versus 5.1–5.3 seconds for the existing standard/Super tanks, and 6.2 seconds for Recon. The initial BACK/FAST input fixture did not produce valid longitudinal movement in either baseline or candidate, so those trials do not establish a reverse-speed improvement. Final loaded-class and movement results are in `QUALIFICATION.md` and the raw evidence.

For tonight, a tanker should test a stationary turn, sustained reverse on level ground, braking after reverse and a straight forward run. Preserve the intended forward limits. Report overshoot and sustained reverse speed before further tuning.

The final production-class fixture passed 26 checks: all 16 variants inherited the intended settings, the upstream 3AS base stayed unchanged, and all three families turned and drove forwards. Standard and Super reached 59.4 and 59.6 km/h respectively; Recon reached 99.3 km/h within the finite test lane while retaining its 120 km/h configuration. All three measured 3.1 seconds to turn through 90 degrees. Reverse probes remained inconclusive and are not included in the passing-check total.

This uses the engine's native drivetrain and steering settings, with no scripted velocity or acceleration boost. The parameter meanings follow [Bohemia's vehicle handling documentation](https://community.bistudio.com/wiki/Arma_3%3A_Vehicle_Handling_Configuration).
