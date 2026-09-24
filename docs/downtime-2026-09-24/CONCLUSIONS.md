# Decision after downtime testing

The user's report that AATs slide/reverse downhill while attempting to climb has been reproduced as substantial downhill movement on a clear 22-degree Altis slope under a native destination order. The data does not distinguish powered reversing from physical slipping: RPM/thrust sound controllers returned zero on this dedicated server and cannot establish the driver's inputs.

**Do not add a torque buff to the release on this evidence.** Current torque, +15%, and +30% all failed to reach 60m uphill within the 35-sample native-route window, twice per class. All three climbed the same hill when supplied a straight route after the crew's stop orders settled, twice per class. Current torque was sufficient under that control. This supports investigating routing/driver control before increasing engine power; it does not prove that grip or torque can never matter on Umbara or steeper/rougher terrain.

| Torque | Native steep-lane completions | Explicit-route completions | Explicit-route 60m times |
|---|---:|---:|---|
| Current | 0/2 | 2/2 | 25.8s, 25.8s |
| +15% | 0/2 | 2/2 | 24.8s, 24.8s |
| +30% | 0/2 | 2/2 | 24.8s, 24.8s |

The separate candidate regression passed 48/48 checks with four actual headless clients. The 18 native-route and 30 explicit-route checks concern fixture identity, unchanged properties and healthy local drivers; they are not assertions that the native routing worked. The frozen Aux candidate, its source commit and its sealed ZIP remain unchanged. No lab build was deployed to Main, Training or Workshop.

## Next implementation target

The current `burnsVehicleProgress` recovery treats any displacement over four metres as progress and only attempts recovery when speed falls below 2 km/h. A vehicle travelling downhill away from its destination can therefore avoid the stuck detector. This is a source-level finding, not proof that this helper alone caused tonight's behavior: the native-routing experiment reproduced downhill loss without BURNS task movement running.

A release-quality recovery should measure progress toward the current goal and recognize sustained downhill loss during an uphill order. The successful explicit-route fixture is a control, not a production implementation: it uses a surveyed clear corridor and stops the crew before setting the route. Copying it directly into combat could interfere with gunner orders, other vehicles, terrain avoidance, Zeus commands or HC transfers.

Before promoting a bounded uphill recovery, validate a clear short corridor, preserve intentional retreat/reverse commands, preserve player/Zeus authority and gunner tactics, cancel on replacement orders/Stop/ownership change, and test native task resumption afterward. Repeat on Umbara with combat and obstacles. Do not disable reverse globally or hide the problem with a teleport/velocity shove.

The earlier driver-only AWARE experiment remains a promising separate finding for combat facing. It also needs ownership and cancellation qualification before promotion. The existing B1 accuracy and successful AAT tactics are retained.

## Evidence correction

`COMPARISON_ERRATA.md` retracts earlier AAT comparison labels where Arma rejected protected-function replacements. Corrected experiments registered real function variants and logged execution. Run49's immediate stop/route control stayed stationary even on its moderate control lane, so it was aborted. Run50 lets stop orders settle first and confirms its control vehicle actually drives; both runs' raw evidence is retained.
