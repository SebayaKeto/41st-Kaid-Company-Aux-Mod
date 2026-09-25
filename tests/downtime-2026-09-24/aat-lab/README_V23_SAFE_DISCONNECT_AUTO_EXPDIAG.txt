FST_HCSpawn Handoff V23 - Safe Disconnect + Auto Explosion Diagnostics

Based on the uploaded V21 safe HC disconnect package, with the V22 explosion diagnostic retained and the build string corrected to V23.

Deployment sanity check:
- In the HC/server RPT, you MUST see:
  [FST_HCSpawn] preInit complete - HANDOFF_V23_SAFE_DISCONNECT_AUTO_EXPDIAG_2026-05-23
  [FST_HCSpawn] postInit starting - HANDOFF_V23_SAFE_DISCONNECT_AUTO_EXPDIAG_2026-05-23
- On server/HCs, you should also see:
  [FST_EXPDIAG][started]

If the RPT says HANDOFF_V19, HANDOFF_V20, or HANDOFF_V21 only, the new PBO is not what the server is actually loading.

Crash-diagnosis log tags:
- [FST_EXPDIAG][summary]
- [FST_EXPDIAG][immediate_explosion_spike]
- [FST_EXPDIAG][immediate_killed_spike]

Important: this package does not alter the existing safe HC disconnect behavior from V21. It only adds/retains the automatic explosion blackbox and makes the loaded build version obvious in RPT.
