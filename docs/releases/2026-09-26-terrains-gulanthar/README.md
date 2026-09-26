# Terrains, Gulanthar hill fix and B1 drop pods — 26 September 2026 (13:00 push)

This was a full-payload update of Workshop item 3048946639. It came from the staging folder `Downloads\Steam-aux-release-20260926-terrains` (72 files, 8,086,115,517 bytes). The Aux Updater published it with PublisherCmd on Miran's go. The base was the 10:32Z release (69 files, 7,007,928,124 bytes).

## Changes

| | File | SHA-256 | Bytes |
|---|---|---|---:|
| Added | Addons/fst_umbara_highway.pbo ("41st Umbara - Ground War Highway") | 1a4a4a9e81d577eaf9407116fdc54350af8a89fc43d42fc018218a8a2f8f57fc | 433,833,300 |
| Added | Addons/fst_umbara_scarreach.pbo ("Umbara - Scar Reach") | 1b702db54ba121e51d6a891362866de1c61e124ab6765edce8c4b7b626118cbe | 193,103,980 |
| Added | Addons/fst_umbara_lantern.pbo ("41st Umbara - Black Lantern") | 2b1af020dd73839738c981b91107b96d0d7a6cd27e00e086ce866b0f5d296400 | 451,246,530 |
| Changed | Addons/FST_HCSpawn.pbo | 5441c6983e2dda7239ce143a2991ea4d586eb9a2f09e032f1394201faa3d57df | 588,658 |
| Changed | Addons/JMSEF_animals.pbo | bb02de51e38f6df5f2630e47a73f5017f3337418bd25ac645a1c9a984d64fc79 | 21,094,465 |
| Changed | Addons/FST_BURNS_Gulanthar.pbo | f16bd0c22b704eb2857e9f50ce080d5ebaf07e64dc674383fe692efa915429d7 | 2,206 |
| Changed | Addons/41st_Armor.pbo (only `Data/Modules.sqf` differs) | 1084b5e2953d5843583426b0ee3cb5497300ccf4aa42a79313f844f2ddd5097a | 2,235,446,922 |

The other 65 files are byte-identical to the base release. `workshop-package-manifest.json` lists every file with its SHA-256.

## Checks

- **Terrains** (`tools/release/terrain_checks/stage_terrain.py`):
  - Each hash matches the owner's frozen copy.
  - Each prefix is a single line.
  - Each ships `config.bin` only.
  - Every dependency resolves in the 101-mod op set.
  - There is no CfgPatches, world, prefix or class collision.
  - Known global side effect: Highway and Black Lantern hide 3AS `Land_3as_fob_hangar` and `Land_3as_tent` from Zeus/Eden and reparent the tent to the grey tent. Both terrains define these identically.
- **Gulanthar:** five isolated dedicated-server runs on real Altis slopes. See `docs/gulanthar-hills-2026-09-26`. The median uphill 45 m time went from 21.1 s to 11.6 s, and 8 of 9 fleeing targets were caught uphill (was 2 of 9).
- **B1 drop pods:**
  - Each freshly spawned squad gets 5 s of `allowDamage false`. Damage is then re-enabled where each unit is local, using the same `remoteExec ["spawn"]` the pod code already uses.
  - SQFLint is clean.
  - The archive entry was replaced at the same size; the other 1,869 entries are byte-identical.
  - It has not been engine-tested.
- **Payload:** re-hashed against the manifest immediately before the upload.

## Publication

Published and verified at 2026-09-26T17:05:29Z (13:05 EDT), in about 2 minutes. PublisherCmd exited 0. Steam logged "Upload finished for workshop item 3048946639 : OK", ManifestID 5663728693729551817. The public API shows time_updated 1790442329 and file_size 8,086,115,517 bytes, which equals the payload. See `publication-receipt.json`.

## Kept out of Git

GitHub cannot hold these files, so they stay local:
- `41st_Armor.pbo` (2.2 GB) and the three terrain PBOs;
- the full Raider PBO and model.

The source of the Armor change is `PUBLISHED MODPACK/41st_Armor/Data/Modules.sqf`.

## Server rollout (Miran)

1. Run a FASTER Aux update on Main and every HC before loading Highway, Scar Reach or Black Lantern.
2. MPMissions:
   - Highway: load `FSTHighway_Overgrown.fst_umbara_highway.pbo` 3b10433c…; the fallback is `FSTHighway_Op.fst_umbara_highway.pbo` 16f26a16….
   - Ghar: load `GharCaldera_Op.fst_umbara_ghar.pbo` 8ad7c154…. Its terrain f0c07543 was already live.
3. Remove the test mods `@HighwayExact`, `@FST_UmbaraScarReach` and `@FST_UmbaraRazorback` from every mod line. Only one copy of each terrain may load.
