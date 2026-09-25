# AAT hill torque comparison — September 24

This is a diagnostic comparison, not a deployed mod change. The loaded AAT uses tankX, peakTorque 5832, enginePower 1400, maxOmega 175, and a measured empty vehicle mass of about 50,071 kg. The isolated subclasses change only peakTorque: 6706.8 (+15%) or 7581.6 (+30%). The frozen candidate's combat scripts, weapons, speed limit, gearbox and torque curve are retained.

Two clear 80m natural-terrain lanes on Altis were surveyed at 10m intervals. The moderate lane is approximately 9–12 degrees through the measured climb, increasing near the destination; the steep lane is approximately 21–23 degrees. Each vehicle starts at rest, aligned uphill, with healthy AI crew and a native move order. There are no enemies or scripted combat movement orders. Every class runs the exact same lane sequentially; the second repeat reverses class order. These conditions isolate basic climbing capability, but do not reproduce Umbara surface grip, obstacles or combat driving.

Times below are the first approximately one-second sample reaching 60m of uphill progress while within 12m of the lane centre. Speed is the mean of samples between 10m and 60m. This avoids the native driver's destination braking. The raw fixture also recorded a strict 70m crossing; one current-AAT run stopped at 69.981m, so that raw crossing marker alone must not be treated as a climbing failure. Raw samples and markers are retained in TORQUE_RESULTS.json.

Run48 uses native destination routing. Run50 instead supplies a straight uphill route after letting the crew's Stop order settle. The first route-control setup (run49) remained stopped on its moderate-slope control and was aborted; it is not evidence about climbing power. Run50 confirms its control vehicle drives. Its raw arrival marker is at 60m. Sound-controller RPM/thrust values were zero on this dedicated server and are not usable evidence of driver inputs.

| Route | Slope | Repeat | Torque | First sample at 60m (seconds) | Mean climb speed (km/h) | Greatest downhill loss (m) |
|---|---|---:|---|---:|---:|---:|
| Native | moderate | 1 | Current | 15.5 | 15.5 | 0.0 |
| Native | moderate | 1 | +15% | 15.5 | 15.6 | 0.0 |
| Native | moderate | 1 | +30% | 15.5 | 16.2 | 0.0 |
| Native | steep | 1 | Current | Not reached | N/A | 49.9 |
| Native | steep | 1 | +15% | Not reached | N/A | 60.8 |
| Native | steep | 1 | +30% | Not reached | N/A | 49.6 |
| Native | moderate | 2 | +30% | 15.5 | 16.3 | 0.0 |
| Native | moderate | 2 | +15% | 15.5 | 15.6 | 0.0 |
| Native | moderate | 2 | Current | 15.5 | 15.8 | 0.0 |
| Native | steep | 2 | +30% | Not reached | N/A | 49.8 |
| Native | steep | 2 | +15% | Not reached | N/A | 51.2 |
| Native | steep | 2 | Current | Not reached | N/A | 49.9 |
| Explicit | moderate | 1 | Current | 15.5 | 15.9 | 0.0 |
| Explicit | moderate | 1 | +15% | 15.5 | 15.6 | 0.0 |
| Explicit | moderate | 1 | +30% | 14.5 | 17.2 | 0.0 |
| Explicit | steep | 1 | Current | 25.8 | 9.5 | 0.0 |
| Explicit | steep | 1 | +15% | 24.8 | 9.7 | 0.0 |
| Explicit | steep | 1 | +30% | 24.8 | 9.7 | 0.0 |
| Explicit | moderate | 2 | +30% | 14.5 | 16.6 | 0.0 |
| Explicit | moderate | 2 | +15% | 15.5 | 15.7 | 0.0 |
| Explicit | moderate | 2 | Current | 15.5 | 15.8 | 0.0 |
| Explicit | steep | 2 | +30% | 24.8 | 9.8 | 0.0 |
| Explicit | steep | 2 | +15% | 24.8 | 9.6 | 0.0 |
| Explicit | steep | 2 | Current | 25.8 | 9.5 | 0.0 |

The checks verify loaded torque multipliers, unchanged comparison properties and healthy local drivers. They do not establish that a buff is desirable in gameplay. See CONCLUSIONS.md for the decision after reviewing these measurements.
