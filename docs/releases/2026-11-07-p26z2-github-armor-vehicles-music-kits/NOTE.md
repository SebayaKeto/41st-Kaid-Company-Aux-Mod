# P26z2 (7 Nov 2026): 6 GitHub commits + helmet-name fix on P26y-burns

Published 12:19 EST (17:19Z) on Miran's go in the Aux Updater chat ("Go P26z2"). ManifestID 4859353477812028692, time_updated 1794071964, 94 files / 7,909,353,462 B.
Base and rollback = P26y-burns (3678869065428710874). Folder `Downloads/Steam-aux-release-20261107-P26z2-github-armor-vehicles-music-kits`, built by `D:/AuxUpdater/aatcrew/make_p26z.py` (work dir D:/AuxUpdater/p26z).

- 5c8ff041 House: Elite Vulture texture, Hyena texture on Hyena Bomber + CAS Vulture (41st_Vehicles).
- a2f24b32 RazaVuzamai: AC8 - Frostwave (41st_Music).
- 784cd9cb House: Sevens armor, Persuade jump pack, Rumble P2 Helmet V2 clean/dirty, Corpse armor (41st_Armor).
- 784e9b72 House: Fynock Gozanti base textures (41st_Vehicles).
- 2466b80e House: Mask armor (41st_Armor). Its 2 body textures were committed at the PUBLISHED MODPACK root; packed at Data/Uniforms where config.cpp references them.
- ae532be7 LaerDar: AT-RT kit logic; ACE microDAGR -> cTab ItemMicroDAGR (SW_cTab), as committed (41st_KitMenu).
- Not on GitHub (Miran "Fix all 6"): 7 editor units' linkedItems FST_AB_Helmet_X -> FST_Airborne_Helmet_X (Mask, Gode, Prime, Sin, Remedy, Remedy V2 Dirty -> ..._Drity, Blue).
  Repo patch (not applied): D:/AuxUpdater/p26z/repo_patch/fixes_p26z2.patch + 2 git mv for the Maska paa.

PBOs: 41st_Armor 1bd9f99c, 41st_KitMenu e4409ddd, 41st_Music c13719d2, 41st_Vehicles 62a5760e. fst_appalachia / fst_app_autumn / FST_HCSpawn unchanged from P26y-burns.
Offline checks: live == repo@fed91f84 for all 4, CfgConvert parse, sqf_balance, missing refs = live (Armor 16, Music 6, Vehicles 0), `--check` passed 17:18Z.
NOT run: engine boot, kit fit test.
