# P26z26 readiness: is B13TEST = live P26z25 + build 13 only?

Checked Fri 27 Nov 2026, 04:17-04:18 (box clock). The check was read-only: tools/aux_entry_diff_b13.py hashed every file (results: `_checks/AUX_ENTRY_DIFF_B13TEST_vs_P26z25.json` / `.txt`). Nothing was pushed, published, copied or changed.

## Verdict: YES, effectively
The only content difference between the staged B13TEST Aux and live P26z25 is the Thirra terrain PBO, and it is the build-13 Binarize output.

| check | result |
|---|---|
| A) B13TEST vs the staged P26z25 release folder | 120 files vs 120. None only in one tree, no case differences. 119 are hard links to the same P26z25 file (same NTFS file id). **One file differs: `Addons/fst_ember_caldera.pbo`**, 8edc766a1a029e68 (174,827,773 B) -> 6671c7152345502d (174,834,990 B). |
| B) the staged P26z25 folder vs its RELEASE_MANIFEST.json | 120 of 120 sha256 match. None missing, none extra. |
| C) the local live Workshop copy vs that manifest | 119 of 120 sha256 match. `meta.cpp` differs **only in the `timestamp` line** that Steam writes when it downloads (5250998601038501020 here, vs 5250945778822642033 in the staged folder and in B13TEST); `protocol`, `publishedid` and `name` are equal. Steam `appworkshop_107410.acf`: installed manifest 2740359259603265369 = latest_manifest = the P26z25 publish (`hcontent_file` in workshop-after.json); NeedsUpdate 0. |
| D) B13TEST terrain vs the build-13 output | `C:/IslandsA/output_whole13/@FST_EmberCaldera/addons/fst_ember_caldera.pbo` = 6671c7152345502d, equal. |

The script's strict verdict flag reads `false` only because of the `meta.cpp` timestamp in check C. Read it as a pass: that line is Steam's, not ours.

## What build 13 changes, vs build 11 (live in P26z25)
- **Ground:**
  - 5,280 height points changed, up to 12.23 m. Every one is on op 5's isle:
    - the Kastro town box x 4340-4800 / y 16590-17220, including R-5-06's last ~65 m to the junction;
    - pit 1 (3475, 16820);
    - pit 2 (7645-7660, 16925-16930).
  - The heightmap diff is b13/ref_b11 vs b13/chain_b13_final_despiked.npy. The as-built delta gate (_checks/delta_gate_b13_asbuilt.txt) found 0 rows of op 6 in any changed box.
- **PBO:**
  - 218 of 1,476 entries differ (_checks/pbo_compare_b11_b13.txt): the WRP, roads (shp / dbf / shx), picturemap, and 205 S / 7 M texture tiles.
  - The tile count follows the same pattern as build 12, which the Omnibus accepted on 26 Nov.
  - config.bin is byte-equal to build 11. The date, climate and names are unchanged.
- **Engine use of B13TEST on 26 Nov:**
  - loads: Ember_Op5_b13r1, b13r6 and b13r7 PASS; Ember_Op6_b11r3V and V4 PASS;
  - the street walk and all captures;
  - Aux guard before and after each slot: the staged P26z25 folder and the live copy were unchanged.

## What P26z26 would be (the Aux Updater stages and publishes it, not this lane)
- Base: P26z25. Workshop 3048946639, manifest 2740359259603265369, 120 files, 8,659,253,000 B.
- Changed: `Addons/fst_ember_caldera.pbo` 8edc766a -> 6671c715, +7,217 B. New total 8,659,260,217 B. Nothing added or removed.
- Change note (suggested): "Thirra: Kastro town rebuilt with real streets (op 5); terrain pits on the crater ridge filled. Let Steam finish the update before joining. Update the server and headless clients, then start a new mission."
- Players download about 175 MB (the one terrain PBO) before Saturday.

## Gaps before P26z26 can go out
1. **No real P26z26 release folder exists yet.**
   - B13TEST is a test copy. 119 of its files are hard links into the P26z25 release folder, so an in-place edit there would also change the P26z25 rollback source.
   - The Aux Updater stages P26z26 as its own folder, with RELEASE_MANIFEST and a change note, and runs its pre-publish checks.
2. **Publish needs Miran's own typed "Go P26z26".** Nothing here is that go.
3. **After the publish, before the 07:00 freeze:** the live server and the HCs need the Steam update to P26z26. Players get it from Steam.
4. **Rollback source for the Aux:** the staged P26z25 folder, `C:/Users/Miran/Downloads/Steam-aux-release-20261125-P26z25-bacta` (120 of 120 manifest match today). The Aux Updater names its ROLLBACK folder at publish time, and it is used only on Miran's typed go naming it.
