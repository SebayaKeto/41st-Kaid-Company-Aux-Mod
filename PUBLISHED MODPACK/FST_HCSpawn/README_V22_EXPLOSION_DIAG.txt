FST_HCSpawn V22 - Automatic Explosion Diagnostic merge

Built from uploaded V21 package: FST_HCSpawn_handoff_v21_safe_hc_disconnect.zip

Changes from V21:
- Added FST_HCSpawn_fnc_initExplosionDiag as an addon function.
- Registered the function in config.cpp under Debug.
- Added CBA settings:
  - FST_HC_ExplosionDiagEnabled, default true
  - FST_HC_ExplosionDiagInterval, default 10 seconds
- XEH_postInit now starts diagnostics automatically on the dedicated server and each headless client.
- No remoteExec was added.
- Existing V21 HC disconnect safe-mode behavior was left intact.
- Existing manual-only dead-group cleanup behavior was left intact.

RPT tags to search:
- [FST_EXPDIAG][started]
- [FST_EXPDIAG][summary]
- [FST_EXPDIAG][immediate_explosion_spike]
- [FST_EXPDIAG][immediate_killed_spike]

Important fields:
- firedTotal / firedAmmo: local explosive ammo fired by that machine's local AI/vehicles.
- explosionEvents: number of explosion EH hits on local CAManBase units during the interval.
- killedUnits: local CAManBase deaths during the interval.
- recentAmmo: ammo class plus hit/indirectHit/indirectHitRange/explosive/simulation/explosionEffects/craterEffects.
- recentExplosions: local unit classes touched by explosion EH.
- recentDeaths: local unit classes killed and killer/instigator type if available.

How to use:
Pack FST_HCSpawn as normal into a PBO and replace the prior V21 PBO.
Leave Automatic Explosion Diagnostics enabled until the next live test/crash review.
