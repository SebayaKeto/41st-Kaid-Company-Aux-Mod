# Maps, MEAP, Stonewall and Arquitens fix: 27 September 2026 (published 16:04 EDT)

This was a full-payload update of Workshop item 3048946639 from staging option "G" (`Downloads/Steam-aux-release-20260927-G-stonewall`): 88 files, 9,219,395,044 bytes. The base was the 26 Sep 13:05 EDT release (72 files, time_updated 1790442329). It was published on Miran's "go G".

## Publication

Published and verified at 2026-09-27T20:04:33Z. PublisherCmd exited 0. Steam logged "Upload finished ... : OK", ManifestID 2929933409186581831. The public API shows time_updated 1790539473 and file_size 9,219,395,044 bytes, which equals the payload.

## Changes against the 26 Sep 13:05 release

| | File | SHA-256 | Bytes |
|---|---|---|---:|
| Added | Addons/fst_umbara_blackfen.pbo | ed54812e90935ddffaaee1ac3d9c99c525b62715792306eec7aaac9e968af57c | 181,524,603 |
| Added | Addons/MEAP_Core.pbo | 807ffc54e8d8176beb19d9edca000c70b5f74f8d4e562caea66e7897c5f26047 | 11,842 |
| Added | Addons/MEAP_Economy_Core.pbo | 0946c642ad506413a6d23ac4ff83763317086f49dbc6f5ffa70a82cbd02b5a00 | 33,843 |
| Added | Addons/MEAP_SW_Core.pbo | b7a327985ac61c2de1e819097f91158e19780d55e1b53936e24ba1af1a45b071 | 183,584,356 |
| Added | Addons/MEAP_SW_Props.pbo | 231c97b170987fc4b5576f5db5e0a68dc87629b07ab638f510dc124cce66d446 | 44,480,965 |
| Added | Addons/MEAP_SW_Structures.pbo | 8b14eab1258e5d0bfdacc3f32e28bae69cbd928354863549e0423712252d0fcc | 19,018,536 |
| Added | Addons/MEAP_Architect_Core.pbo | 2cf7bd5029d7dbd326f379a0ddf4c963a4035a7689c794f205fa82b9dcf69c7d | 179,889 |
| Added | Addons/fst_umbara_razorback.pbo | 5e70af9a89667067a407969c04b280ca877fd9c0c60c3d9c2e68228764b9d06e | 64,501,312 |
| Added | Addons/fst_umbara_fallfire.pbo | 352e6b50248c8293331b97a72293b08a0aa91ba652ec7fd4e2a3fe6c5e04d84b | 64,266,031 |
| Added | Addons/fst_umbara_gloomreef.pbo | 2f6319d21af0de436a2ce6530b647bfd6ba8e5e7783229f40357aa1c71cd7cee | 60,206,492 |
| Added | Addons/fst_umbara_hollowdeep.pbo | 9ae0ea22eee8ef7eff634791566cdd85a9231a968fa8c58b91c97cc4518fcbb4 | 64,567,456 |
| Added | Addons/fst_umbara_gloamport.pbo | 9af81df674e351031301a0093ceadf33e2dafb0498ac26931bcd7f2ebad242a4 | 61,351,657 |
| Added | Addons/fst_umbara_droidworks.pbo | f96376a1d139911830972fff2fe2fde70e519f81941be423f7a320f0f0698ab1 | 192,450,970 |
| Added | Addons/fst_umbara_lumenvale.pbo | 1ac90a45ea74cbb73871e0811f4f827dd1dbbbd9903cd64c9298a4c2f425a77f | 188,946,655 |
| Added | Addons/fst_blacklantern_kit2.pbo | 252da9b905b579469f1fee52cdeac7b5da226817c66258c76732b8f8794fa585 | 14,200,189 |
| Added | Addons/FST_Stonewall.pbo | 69fa0a88b51f5b19b038f9b240a63f8f57c57b159f0396623a54f738d246f6b9 | 29,009 |
| Changed | Addons/fst_umbara_lantern.pbo | 29685e81095c0dec8239594ba2f9ff4b7252111092ec914ffda636a2534acb45 | 455,940,582 |
| Changed | Addons/kaid_iron_tide.pbo | 37af4849b9281dee7b01514ae3c8144a800b09d38280fab1a18add0be2f24de6 | 184,648,680 |
| Changed | Addons/arq_ships.pbo | e56c7c686d501be90ba05f426ee37c4d322ecad1dd9478e292448bab2ae8473d | 151,035 |

## What it is

- **New maps:**
  - Blackfen v121, Razorback, Fallfire, Gloomreef, Hollowdeep, Lumen Vale.
  - Droidworks G: f96376a1, the build Miran played. Omnibus confirmed it before the FM install.
  - Gloamport R08e: hover yard.
- **Updated maps:** Black Lantern V13, with its new asset addon fst_blacklantern_kit2 252da9b9; Iron Tide R19c14.
- **MEAP/Daidalos** (6 PBOs): integrated in the repo on 24 Sep, but never published until now.
- **FST_Stonewall 1.2.4:** Zeus Keep Area / Remove Keep Area / Save Mission modules and base carry-over tagging.
- **Arquitens fix** (arq_ships e56c7c68):
  - removes the player HandleDamage override that caused one-hit kills;
  - adds a spawn placement guard;
  - removes interiors on delete.
- **Vigil** was dropped (retired) and never published.

## Checks

- **Every map:** hash-identical to FINISHED MISSIONS or the owners' forwards. Droidworks G was confirmed by Omnibus; its FM install followed.
- **`tools/release/terrain_checks/stage_terrain.py` integration checks:** no problems across the payload. The only warnings are shared 3AS glow, tent and hangar redefinitions that were already live and are identical.
- **Non-map addons:** tested by the Aux Updater on an isolated dedicated server with 4 HCs, the full 101-mod op set and the exact payload.
  - MEAP fixture: 44/44.
  - Stonewall: loaded and tags correct.
  - 0 script errors, and 0 Stonewall or arq errors.
- **Not engine-observed:** client-side ride-along on the Arquitens, the MEAP camera UI, and Stonewall's rejection of a non-Zeus graphical player.

## Server rollout (Miran)

1. Update the Aux on Main and every HC (FASTER), then start a new mission session.
2. Players must not load a standalone @MEAP.
