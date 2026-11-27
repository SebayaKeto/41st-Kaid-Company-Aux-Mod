# P26z25 (25 Nov 2026): Bacta Tank fix

Published 21:51 EST (2026-11-26 02:51:24Z) on Miran's go "Go P26z25 if it passes", typed in the Aux Updater chat; the engine test passed at 21:49. --check ran at 02:50:15Z, right before. ManifestID 2740359259603265369, time_updated 1795661484, 120 files / 8,659,253,000 B (+236 vs P26z24). Verified.
Base = P26z24 (2736663053925847662). Nothing else changed.
- CHG 41st_Medical.pbo 87945d72 (1,835 B; was bb20ab0d, 1,599 B): config.cpp only, ACE_medical_treatment_actions >> FST_Bacta_Tank (Miran's pick via the Omnibus: "Bandaged, even if down").
  - condition: was isInStableCondition (alive, NOT unconscious, no bleeding, stable vitals) + medic still. Now: alive patient + all bleeding stopped (ace_medical_woundBleeding == 0) + medic still (speed < 1). Conscious or unconscious; no vitals check.
  - treatmentLocations = 0 (anywhere). Was inherited from the server's Personal Aid Kit location setting (ace_medical_treatment_locationPAK).
  - Kept from the PAK: full heal, medic level (medicPAK), self-treatment (allowSelfPAK), consumes the tank or not (consumePAK), treatment time.
  - Built by make_bacta25.py from the live P26z24 PBO; the patched config is 41st_Medical_config.cpp.patched. `PUBLISHED MODPACK/41st_Medical/config.cpp` (macro source) is NOT updated yet.

History: the old condition dated from 15 Mar 2025 ("Fixed Bacta Tank", 32be771c); 41st_Medical was byte-equal (bb20ab0d) in every recorded release from 26 Sep 2026 to P26z24. ACE 3.21.2 -> 3.21.3 (24 Nov) did not touch treatment. So P26z25 is a new behaviour, not a restore.

Tests (Omnibus BOX OK; probe test/BactaProbe_initPlayerLocal.sqf, 71-mod live list):
- Staged copy, 25 Nov 21:47 (test/run_bacta25.py, verdict_bacta25.json): PASS. Bleeding + unconscious: no bacta. Bandaged + unconscious: bacta; wakes in 13 s, blood 6, wounds 2 -> 0. Bandaged + awake: bacta, wounds 1 -> 0. 0 warnings. (Run 1 at 21:42 was void: the probe medic's inventory was full, so 0 tanks.)
- Live Workshop copy, 26 Nov 09:42 (test/run_bacta25_live.py, verdict_bacta25_live.json), after Miran updated this PC: PASS, same three results. RPT 390 'error' lines / 3,275, identical to the staged run; all base-mod skeleton lines; 0 script errors, 0 warning boxes, 0 lines naming 41st/FST/KAID.
- Note: the tank is not used up on our test box because consumePAK = 0 there; same as before the fix.

Knock-on: the server and HCs need P26z25 before Sat.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z24-from-P26z25 (--check 02:51:58Z; publish only on Miran's typed go naming it).
