# P26z20 (22 Nov 2026): Daara stop fix on P26z19

Published 16:43 EST (21:43:11Z) on Miran's go "Go P26z20", typed in the Aux Updater chat (staging: "Yes, stage P26z20"). ManifestID 6235468048858355231, time_updated 1795383791, 101 files / 8,438,126,472 B. Workshop API agrees (time_updated, file_size, hcontent_file).
Base = P26z19 (71308130429365954). Only change: Addons/ck_character_v8.pbo -> sha256 728147be9b98e8dc49d36f204b1f296fe66b2b83cda080474e8873849e7f6bbf (97,674,462 B, same size).
- From Project Daara (D:/AuxUpdater/incoming/daara_stopfix_20261122). Only config.bin replaced; 42 other entries byte-identical, prefix kept (pbo_gate PASS).
- Derapped diff = exactly 9 numbers: "CK_Daara_Stp" cost 0.06 -> 0.04 in CK_Daara_WlkDf/Dfl/Dfr/Dl/Dr/Db/Dbl/Dbr and CK_Daara_RunDf. They tied with the vanilla stop route, so she sometimes stepped into the vanilla stand for ~0.4 s.
Tested: Project Daara, server-only on the Omnibus BOX OK 16:26-16:37 (74 Nov mods + P26z19 with this PBO swapped in): CKStopTest, CKStopRunTest, CKStopIdleTest PASS. Not run: full HC boot (the Omnibus post-op r7 boot on the z20 folder covers it).
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z19-from-P26z20 (--check 21:43:43Z).
