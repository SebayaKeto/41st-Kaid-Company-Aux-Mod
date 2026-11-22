# P26z13 (21 Nov 2026): Saber base-class fix on P26z12

Published 22:23 EST (03:23:20Z 22 Nov) on Miran's go typed in the Aux Updater chat ("Go P26z13"); staging asked there ("Yes, stage the fix"). ManifestID 1711484598255058317, time_updated 1795317800, 101 files / 8,401,065,782 B. Workshop API agrees.
Only change: Addons/FST_Saber_Handling.pbo -> c6917270 (1,173 B; src D:/AuxUpdater/saberhandling/src2), config.cpp only (aatcrew/pbo_gate.py PASS, CfgConvert OK).
Why: the live addon (since 14 Oct) declared `class 3AS_Saber_01_Base {class complexGearbox;};` with no parent, blanking 3AS's Tank_F parent (Miran's client RPT 21 Nov 16:55, line 527). Fix declares `class Tank_F; class 3AS_Saber_01_Base: Tank_F`.
Not boot-tested, no drive check. Repo copy PUBLISHED MODPACK/FST_Saber_Handling not yet updated.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z12-from-P26z13 (--check 03:23:47Z; differs only in FST_Saber_Handling.pbo).
