# P26z9 (19 Nov 2026) - Suddra build 3 + Thirra build 9
Published 2026-11-19T06:04:58Z, ManifestID 7743901439059980302, 99 files / 8,393,288,631 B. Base: P26z8 (5504948947415350007).
Go: Miran typed "Go P26z9" in the Aux Updater chat, 19 Nov ~01:0x EST.
Changed (config.bin only in each, per pbo_gate.py; CfgWorlds startDate ISO -> d/m/yyyy fixes Eden ~3 fps; ACE weather climate keys):
- Addons/fst_suddra.pbo -> b3 44e6b75c (283,049,305 B), C:/Suddra/terrain/output_b3; startDate 1/10/2035
- Addons/fst_ember_caldera.pbo -> b9 8a995e6a (174,933,374 B), C:/IslandsA/output_whole9; startDate 21/6/2035
KNOWN DEFECT: lane 17 withdrew Thirra b9 after the upload had started (ACE climate seasons reversed: warmest Dec-Feb under a June date).
Harmless per the Omnibus; fix = P26z10 (Thirra 9b d0b22c5c), staged, waits for Miran's "Go P26z10".
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z8-from-P26z9 (--check passed 06:05Z).
stage_terrain: only the known Stratis re-open flags (same as P26z8).
