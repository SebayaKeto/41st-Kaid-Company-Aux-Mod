# CARD: KAID_MineDetector_Fix (candidate b), 8 Nov 2026 ~00:30 EST

**For:** Aux Updater lane. Stage and ship ONLY on Miran's go (normal Aux rules: full-payload publish, `--check` right before, record in `docs/releases/`).

## The report
41st EOD (Medal clip, Sat-2 Aparra W4S2 op, 7 Nov) walked into a mine with the vanilla `MineDetector` panel open; the panel showed nothing for ~13 s and he died. Miran: the mine came from ZEN **Create Minefield**.

## What the engine tests showed (D:/AuxUpdater/minedetector/evidence, 8 runs, op modlist + live Aux P26z2, own server + windowed agent client, Miran's OK)
- The vanilla panel draws every mine type ZEN Create Minefield offers (APERS, bounding, tripwire, ACE toe-popper, SLAM, UXO, ACE flare trip, AT), placed through ZEN's own module path, made on the server or a client, captive or not, vanilla rifleman or `FST_Trooper_P2_EOD`: a big red glow (`run5_all_minefield_types.jpg`).
- **Except mines the player's side already knows** (`west revealMine _m`, which is what `zen_modules_fnc_bi_moduleMine` does when the server's ACE Zeus setting **Reveal Mines** (`ace_zeus_revealMines`) is above 0). Those draw at `sizeMine` = 1.5 (Contact UI, `A3_Ui_F_Orange`): a 2-3 px pip that is invisible on a 720p clip and easy to miss live (`fix_compare.png`, middle).
- Nothing else in the modset or the Aux touches the detector or the mines (config scan of the whole client modlist).

## The fix
`@KAID_MineDetector_Fix/addons/KAID_MineDetector_Fix.pbo`, 964 B, sha256 `F3FD064176A3C2635E3D6A4AB7021C9AC72EAAE2CB2DDF7E629A40A46094B21A`, prefix `KAID_MineDetector_Fix`, uncompressed, raw config.cpp only (source in `src/`).
```
class CfgPatches { class KAID_MineDetector_Fix { requiredAddons[] = {"A3_Ui_F", "A3_Ui_F_Orange"}; ... }; };
class RscCustomInfoMineDetect { sizeMine = 4; };   // = sizeMineUnknown; vanilla 1 (Ui_F) -> 1.5 (Ui_F_Orange)
```
- Client-side UI config only. No scripts, no CfgAmmo/CfgWeapons change, no server effect. Known mines now draw as a bold solid mine icon, as visible as unknown ones (`fix_compare.png`, right).
- requiredAddons MUST include `A3_Ui_F_Orange` (candidate a with only A3_Ui_F was overwritten back to 1.5).
- Engine-verified: run 8 (`C:\ReviewSessions\DetTest-20261108-001915`): `sizeMine 4` read in engine, revealed mine drawn large, no RPT errors/warnings on server or client.
- Add it to the Aux payload as one new PBO (new CfgPatches name, no collisions). Unsigned like the rest.

## Still open (tell Miran)
- Not proven that the live mine was revealed. Quick check: the live server's CBA settings, ACE Zeus > Reveal Mines. If it is "Disabled", the clip's cause is still unknown (the fix is harmless either way).
- If it is ON, the no-Aux alternative is setting it to Disabled on the server (it also stops BLUFOR "knowing" Zeus mines).

## Repro
`evidence/DetTest.VR` (VR mission: client initPlayerLocal runs the cases, server initServer makes mines; `zen:<ModuleMine class>` = ZEN's per-mine call), booted with `review_boot.py --client --window`; HUD frames via `evidence/grabwin.ps1` (PrintWindow PW_RENDERFULLCONTENT, DPI-aware). The SQF `screenshot` command does NOT capture the HUD.
