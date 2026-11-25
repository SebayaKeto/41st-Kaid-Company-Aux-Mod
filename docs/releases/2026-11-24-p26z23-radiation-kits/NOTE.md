# P26z23 (24 Nov 2026): Bees' radiation + kit fixes on P26z22

Published 23:54 EST (2026-11-25 04:54:30Z) on Miran's go "Go P26z23", typed in the Aux Updater chat (staging: "Stage P26z23 now"). ManifestID 8906419198321423684, time_updated 1795582470, 119 files / 8,659,351,731 B (+6,865). Workshop API agrees (time_updated, file_size, hcontent_file).
Base = P26z22 (8098004868618132953). Source: Bees 6764d96a "Radiation Fixes and Kit Fixes" (pushed 23 Nov 19:26).
- 41st_KitMenu a0e64f26: FST_autoCustoms.sqf + XEN_PreInit.sqf (radiation kits offer the player's own radiation-protected helmet; named players included). 43/45 entries identical.
- BUZZ_Radiation 6086a81c: CfgFunctions hpp + XEH postInit + fnc_tick + compat_41st config changed, fnc_zeusZone added (Zeus Enhanced "BUZZ Radiation > Radiation Zone" module; Geiger/cough say3D from a local helper object; radiation medical crate lists the 9 FST_MedicalCrate items + radiation gear). 44/49 identical.
Built from the live PBOs (D:/AuxUpdater/rad23/make_rad23.py): each entry checked == pre-Bees file first; dupscope + CfgConvert -bin on all 3 configs; CfgFunctions paths exist; crate's 9 lines == live FST_MedicalCrate. pbo_gate: only Bees' entries differ.
NOT engine-tested at publish (Miran's go came while the box was held by Suddra). Load test staged: D:/AuxUpdater/p26z23_load/run_opload23.py (Wed op aa9dc3ea19b0, base-class + warning diff vs P26z22); runs on the next Omnibus BOX OK. Geiger sounds need an MP test (Bees' note).
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z22-from-P26z23 (--check 04:55:01Z; publish only on Miran's typed go naming it).
Server + HCs need the Steam update before the Halloween op Wed 25 Nov 20:00 EST.
