# Black Lantern V15 kit2 and Daidalos fix: 27 September 2026 (published 21:56 EDT)

This was a full-payload update of Workshop item 3048946639 from staging option "H" (`Downloads/Steam-aux-release-20260927-H-1900`): 88 files, 9,219,346,568 bytes. The base was the 27 Sep 16:04 EDT release G (time_updated 1790539473). It was published on Miran's "go H".

## Publication

Published and verified at 2026-09-28T01:56:04Z. PublisherCmd exited 0. Steam logged "Upload finished ... : OK", ManifestID 5862834072050369302. The public API shows time_updated 1790560564 and file_size 9,219,346,568 bytes, which equals the payload.

## Changes against release G

| | File | SHA-256 | Bytes |
|---|---|---|---:|
| Changed | Addons/fst_blacklantern_kit2.pbo | bc53b15cc00685051e88bdca054b21086ace9fe12399f99a84a6701cfa5b9d7e | 14,149,759 |
| Changed | Addons/MEAP_Architect_Core.pbo | 7fd2c068623ca493cf62fcd28f080d5a3a20d2a981a440e0416bfb64313ae367 | 181,843 |

- **fst_blacklantern_kit2:** the Black Lantern V15 airbase models (interior lighting, wall screens, light strips, ceiling panels). The Black Lantern terrain is unchanged (29685e81).
  - FM install 17:25, mission Canon15 0aac4640; Airbase engine run-61 passed on these bytes.
  - Integration: all 37 bl3_* objects in Canon15 are kit2 classes.
- **MEAP_Architect_Core (Daidalos):**
  - The 21 mission ACE Fortify props were added to the default palette and default costs, using exact configName case.
  - The cost lookup bug is fixed: `isNil` wrapped an assignment, so every object cost 5.
  - Engine-tested on an isolated server with 4 HCs: MEAP fixture 44/44, the palette has 42 classes, and the costs are as configured.
  - Server CBA settings that override Object Costs still win over these defaults.

## Server rollout (Miran)

Update the Aux on Main and every HC, then start a new mission session.
