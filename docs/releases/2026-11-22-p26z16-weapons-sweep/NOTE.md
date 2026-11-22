# P26z16 (22 Nov 2026): 41st_Weapons blank sweep on P26z15

Published 00:38 EST 22 Nov (05:38:50Z) on Miran's go "Go P26z16", typed by him in the Mapmaking Omnibus session (verified in its transcript). ManifestID 7698095297189820764, time_updated 1795325930, 101 files / 8,401,068,659 B. Workshop API agrees.
Only change: 41st_Weapons.pbo -> 7f61028c; DC-15N, DC-15U, DC-1A config.cpp only (pbo_gate PASS, CfgConvert OK x3).
- DC-15N, DC-15U: the four [41st] light attachments inherit FST_Base_Flashlight, Iteminfo: Iteminfo, Flashlight: Flashlight.
- DC-15U, DC-1A: Rifle_Base_F: Rifle.
Found by sweep.py after the z15 load test exposed blanks hidden behind the earlier ones.
Omnibus server-only load test (00:33 22 Nov): PASS. Base-class updates 260 -> 225 (35 gone, 0 new); no 41st_Weapons blank; errors = z15 (4 known flaps/stall lines). Checked in the RPT by the Aux Updater too.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z15-from-P26z16.
