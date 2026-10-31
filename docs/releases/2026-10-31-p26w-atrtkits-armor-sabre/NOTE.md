# P26w (31 Oct 2026): 7 GitHub commits on P26v-full

Published 12:22 EDT on Miran's go in the Aux Updater chat ("Publish when ready"). ManifestID 1924247649507854408, time_updated 1793463754, 94 files / 7,892,436,885 B.
Base and rollback = P26v-full (3798944629488011625). Folder `Downloads/Steam-aux-release-20261031-P26w-atrtkits-armor-sabre`, built by `D:/AuxUpdater/aatcrew/make_p26w.py`.

- 098bd6fa House: Q-Ball P2 helmet, officer visor, life support (41st_Armor).
- a497b1e4 Bees: RTO hacking chips, datacard entries as magazines (41st_KitMenu).
- b150cb0b + 294651f9 LaerDar: 4 AT-RT kits and role rules; perf comments dropped, code unchanged (41st_KitMenu).
- 5c70b7ed House: Remedy unit uniforms, Bogu crewman helmet, Bigmike/Snorlax/Wheeze P2 helmets (41st_Armor).
- 90249a42 Maldova: FST_VW_SabreAPC_LG_Missile hit=1200, indirectHit=80 patched into the live config.bin (FST_Vehicles_Weapons). Blender files and wall PNGs do not ship.
- 20e94b32 Bees: AT-RT BUZZ_shotVolume 0.75 (BUZZ_Vehicles).

Offline checks: live == repo@9e0b2b3f for KitMenu and BUZZ_Vehicles, CfgConvert parse, sqf_balance, new textures present, 16 missing refs as live, `--check` passed.
NOT run: engine boot, kit fit test (no engine word). No classes removed or renamed; no HCSpawn/AI/spawn/cleanup files touched.
