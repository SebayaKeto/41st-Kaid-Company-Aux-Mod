# P26z26 (27 Nov 2026): Thirra terrain build 13 (op 5)

Published 10:29 EST (2026-11-27 15:29:18Z) on Miran's go "Go P26z26", typed in the Aux Updater chat. --check ran at 15:28:17Z, right before, and still showed P26z25 as live (time_updated 1795661484). ManifestID 8502866253138205417, time_updated 1795793358, 120 files / 8,659,260,217 B (+7,217 vs P26z25). Verified.
Base = P26z25 (2740359259603265369). Nothing else changed.
- CHG fst_ember_caldera.pbo 6671c715 (174,834,990 B; was 8edc766a, build 11): Thirra build 13 from the Thirra lane (C:/IslandsA/output_whole13).
  - Every change is on op 5's isle: the Kastro town box (x 4340-4800 / y 16590-17220, including R-5-06's last ~65 m), pit 1 (3475, 16820) and pit 2 (7645-7660, 16925-16930). 5,280 height points changed.
  - 218 of 1,476 entries differ: the WRP, roads, picturemap and 205 S / 7 M tiles. config.bin is byte-equal to build 11.
  - Details: THIRRA_P26z26_READINESS.md.
- Staged by make_p26z26.py, on the Omnibus's ask while Miran was asleep. Every file is a real copy (no hard links into the P26z25 rollback source), each sha-checked against the manifest. The content is byte-equal to the Thirra lane's test copy Steam-aux-B13TEST-20261126 (120/120).

Checks:
- check_b13.py / check_b13.json: PBO read-back rebuilds byte-equal; same prefix and the same 1,476 entry names as build 11; config.bin -> CfgConvert rc 0; dupscope 0.
- Op 5 load, 27 Nov 04:31-04:36 (Omnibus BOX OK; test/run_p26z26_op5.py, Ember_Op5_b13r6 8057c3de, 71-mod live list, Aux = the staged folder):
  - The server reached Starting mission in 47 s (the Thirra lane's b13r6 run took 45 s). The client joined on attempt 1 and was in the mission 44 s after launch. 120 s soak, no input.
  - Script errors: server 7, equal to the Thirra lane's b13r6 server run. Client 4, equal to the 26 Nov B13TEST op 5 client runs. All are vehicle config lines (MFD 'flaps' / 'stall', Hit{L,R}Aileron_Link) seen in server loads since P26z22.
  - 0 warning boxes; 0 error lines naming 41st / FST / KAID / ember_caldera. Server RPT ~330 lines/min in the mission.
  - verdict_p26z26_op5.json says PASS=false only because the runner's own gate wants 0 script errors. Against the baseline it is equal.

Knock-on: the live server and 4 HCs need P26z26 before the Sat 28 Nov 07:00 freeze (op 5 = Ember_Op5_b13r6). The live-copy load check is owed once Steam fetches it here (held: the Omnibus BOX HOLD while Miran plays).
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z25-from-P26z26 (--check 15:29:46Z; publish only on Miran's typed go naming it).
Note: the Bees Radiation commits (c4c70526, 4dc9efe5, merged here 26 Nov 23:38) are in the repo but in no published release, P26z26 included.
