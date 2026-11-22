# P26z11 (21 Nov 2026): Bees 4 commits on P26z10

Published 16:40 EST (21:40:14Z) on Miran's go typed in the Aux Updater chat ("Go P26z11"). ManifestID 6685848150132349175, time_updated 1795297214, 101 files / 8,401,065,624 B.
Base = P26z10 (134245045922254320). Rollback folder `Downloads/Steam-aux-ROLLBACK-to-P26z10-from-P26z11`.

- e43bc26b Bees: radiation kits + Spawn Radiation Kit Locker (41st_KitMenu), All Star (41st_Music), environmental helmets Trooper/NCO/Woodland (41st_Armor), NEW BUZZ_Radiation.
- 034978a1 Bees: radiation medical crate (BUZZ_Radiation/compat_41st).
- d136640a Bees: NEW BUZZ_ZeusVision.
- 91ac025d Bees: fixed All Star ogg.

Build: D:/AuxUpdater/p26z11/build.py. 41st_KitMenu / 41st_Music rebuilt from live (live == parent 6eb56a2d for every changed entry). 41st_Armor config.cpp = git merge-file(live, parent, head), clean, so the live-only helmet-name fixes stay (repo source still lacks them).
New PBOs packed from repo HEAD: prefix from $PBOPREFIX$, uncompressed, config.cpp as text (nested compat_41st / compat_fst configs).
Offline checks: CfgConvert OK on every config, sqf_balance OK, own-prefix refs: new addons 0 missing, Armor 15 / Music 5 missing = live. `--check` 21:39:12Z.
NOT run: engine boot (Miran's client and a server were up). Radiation_Kits.sqf hands out IDA items; convert before the IDA removal ships.
