# P26y-burns (7 Nov 2026): Aparra terrain v8b2 + autumn tree V2 + BURNS rev2 on P26w

Published 02:47 EST (07:47Z) on Miran's go in the Aux Updater chat ("Go P26y-burns"). ManifestID 3678869065428710874, time_updated 1794037644, 94 files / 7,892,492,042 B.
Base and rollback = P26w (1924247649507854408). Folder `Downloads/Steam-aux-release-20261106-P26y-aparra-v8b2-treesV2-burns`, built by `D:/AuxUpdater/aatcrew/make_p26y.py --burns`.

- fst_appalachia.pbo b81af5a3 (285,604,557): Aparra terrain v8b2, WRP b48e33f0 (Miran "Tantiss B plays", APP-R167).
- fst_app_autumn.pbo fd532f8e (26,376,014): tree V2; View + Fire geometry added on 6 models, live crown fire fix kept (Miran "Ship V2 Saturday", APP-R185). Proof `D:/AuxUpdater/p26y/PROOF_V2_vs_LIVE.md`; 6 models byte-identical to flown test 3beeee0d.
- FST_HCSpawn.pbo f0b6dc52 (712,313): BURNS rev2 hygiene: drops stale targets, no steered rounds without sight; no measured reduction in blind fire or hits.

Offline checks: stage_terrain (only the pre-existing lighting-patch world note, same as live), viewverify 6/6, `--check` passed 07:46Z.
NOT run: engine boot of the combined payload.
