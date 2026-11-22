# P26z7 (18 Nov 2026): Suddra build 1 + Ember Caldera build 8 on P26z6

Published 14:14 EST (19:14Z) on Miran's go typed in the Aux Updater chat ("Go P26z7"). ManifestID 6426817668243429582, time_updated 1795029288, 99 files / 8,393,332,328 B (+291,204,731 B vs P26z6).
Base and rollback = P26z6 (8190672032863050125). Folder `Downloads/Steam-aux-release-20261118-P26z7-suddra-embercaldera8`, built by `D:/AuxUpdater/aatcrew/make_p26z7.py` (prep + finish).

- ADDED fst_suddra.pbo 4e5cb14e (283,094,169): Suddra build 1, world fst_suddra (owner look "Looks right", SUD-R32). C:/Suddra/terrain/output_b1.
- ADDED fst_suddra_reed.pbo 245bdd11 (223,526) and fst_sud_rpine.pbo eaea53ab (7,231,705): Suddra asset PBOs.
- CHANGED fst_ember_caldera.pbo 48c05c4a (build 5) -> 711e5584 (174,932,207, build 8). C:/IslandsA/output_whole8.

Checks: stage_terrain (repo tool, copied to D:/AuxUpdater/p26z7/tc; fresh index of the Nov V1 75-mod list minus the Aux): hashes, prefixes, bin only, requiredAddons all resolve.
Only flag on both terrains = the CfgWorlds Stratis re-open; class signature 289a9e97 is identical to live build 5, which gives the same flag and was live since 12 Nov. `--check` passed 19:13Z.
NOT run: engine boot of the combined payload.
