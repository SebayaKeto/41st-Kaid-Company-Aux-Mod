# P26z24 (25 Nov 2026): Thirra build 11 + built-in QoL (KAID_QoL) + menu fix

Published 09:55 EST (2026-11-25 14:55:09Z) on Miran's go "Go P26z24", typed in the Aux Updater chat. --check ran at 14:54:06Z, right before. ManifestID 2736663053925847662, time_updated 1795618509, 120 files / 8,659,252,764 B (-98,967 vs P26z23). Verified.
Base = P26z23 (8906419198321423684). One folder, so players download once before Sat.
- ADD KAID_QoL.pbo 94202ecc (6,605 B): our own Remove stamina, Remove stamina - ACE 3, No Weapon Sway and More Aircraft Displays (pilot/co-pilot ETA + fuel panel; it stands down if the old mod is loaded). Source: KAID_QoL_src/, built by make_qol24.py.
- CHG fst_ember_caldera.pbo 8edc766a: Thirra terrain build 11 (Miran's pick "Build 10, drop pad"; same 1,476 entries as 9c, config.bin byte-equal; 281 paa/rvmat/roads/wrp changed).
- CHG 41st_Menu.pbo 1f4d724e: config.cpp only (Miran: "Include the menu fix in P26z24"). RscDisplayMainMenuBackground controls get their vanilla bases back (same black look), and the stray typeless RscDisplayMain News control is removed. Built by make_menufix.py; the patched config is 41st_Menu_config.cpp.patched. It differs from `PUBLISHED MODPACK/41st_Menu/config.cpp` only in those lines; the source tree is NOT updated yet.

Tests (Omnibus BOX OK, 25 Nov):
- Thirra op 5 / op 6 server loads: PASS. 0 new script errors, base-class lines or warnings vs the Thirra lane's build-11 runs; the 4 menu base-class lines are gone.
- QoL, server Wed op with 75 and 71 mods: PASS.
- QoL client, first build: an engine box "Variable 'kaid_qol_panel' does not support serialization" on every client. Fixed before publish: the panel control now lives in uiNamespace. Re-test after the Steam restart: 71 mods PASS (panel shown, 0 warnings); 75 mods: our box gone. The only box left is the old More Aircraft Displays mod's own 'ctrleta' one, which goes away when that mod comes off.
- Menu-stall A/B (with vs without the menu fix): void. 14/16 boots hit the box-side "Creating action map cache" freeze, so whether the fix stops the menu stalls is unproven.

Knock-on: the server and HCs need P26z24 before Sat (ops 5/6 need build 11). The 4 mods can come off the preset, server and HCs (canonical LIVE_MODLIST is now 71 mods).
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z23-from-P26z24 (--check 14:55:47Z; publish only on Miran's typed go naming it).
