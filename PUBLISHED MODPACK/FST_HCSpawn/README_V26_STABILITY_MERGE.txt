V26 STABILITY MERGE - 2026-07-04
Base: V25 EXTREME HC STABILITY (never fielded), plus the two fixes from the
V23-line "dynsim/stance" patch. Both prior branches are superseded by this build.

RPT verification string:
[FST_HCSpawn] postInit starting - HANDOFF_V26R2_STABILITY_MERGE_DYNSIM_OFF_STANCE_FIX_FG_SOFTCAP_2026-07-04
[FST_HCSpawn][EMERGENCY] V25 droid bandaid active

Carried over from V25 (unchanged):
- Emergency droid bandaid (InitPost/Killed stabilization, NoVoice, ACE var hints)
- enableSentences false on server/HC (FST_HC_EmergencyMuteSentences)
- Fast dead-droid hide/sim-off + batched delete (delay 0.25s, 20/pass)
- Per-HC soft cap (FST_HC_PerHCSoftCap, default 240) + block-when-capped
- Block heavy spawns without HC (no server fallback)
- Explosion diagnostics (default per V25 settings)

Fixes applied on top:
1. Dynamic simulation OFF by default (FST_HC_EnableDynamicSimulationSystem=false)
   and every per-group enableDynamicSimulation call gated behind that flag.
   Root cause of "units lose simulation when HCs are on": catchUntracked only
   sweeps groups when HCs are registered; transferGroup then flagged every
   mobile group on the SERVER, whose dyn-sim manager globally freezes any
   flagged group with no player within activation distance (Zeus does not wake
   units; frozen units cannot move or be killed).
2. Droid stance keeper restored: fn_enforceDroidStance registered in
   CfgFunctions and scheduled every 10s on server AND HCs (setUnitPos is
   arguments-local, so server-only stance scripts stop covering HC-owned
   droids). reapplyGarrison also reasserts setUnitPos "UP" after setGroupOwner.
   Settings: FST_HC_DroidStanceEnabled (true), FST_HC_DroidStanceInterval (10).

Test checklist:
- RPT shows the V26 handoff string on server AND each HC.
- Group placed 1km+ from players still moves and takes damage (dyn-sim off).
- B1s on HC-owned garrisons return upright within ~10s; stay upright after a
  Shift+F2 hold/release cycle.
- Watch RPT for stuck network-state update retries during heavy kills; if they
  appear, raise EmergencyDeadDeleteDelay / lower DeletesPerPass.

R2 (final review pass, same date):
3. Fill Garrison now respects BlockHeavySpawnsWithoutHC when getSpawnTarget
   returns no usable HC (all HCs over soft cap OR none connected). Previously
   the batch loop silently fell back to spawning the batch on the dedicated
   server, defeating the soft cap. The job now stops cleanly and tells the
   calling Zeus how many units were placed before the stop.
Known/accepted: QRF and Frontline create groups on the server and rely on the
transfer sweep; they are gated by the hard AICap and the no-HC block, but NOT
by the per-HC soft cap. If all HCs are soft-capped, QRF groups will sit on the
server until an HC drops below cap. Acceptable for squad-scale spawns; do not
use QRF as a mass-spawn workaround while capped.
