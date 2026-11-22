# Aux base-class blanks: audit + P26z15 candidate (22 Nov 2026, 04:45Z)

Ask: Miran "Yes, check them" (typed in the Omnibus session, relayed). Offline only: configs + RPT sequence. No engine run, nothing published.
Sources: Omnibus P26z13 server load test RPT (`D:/Codex/Mapmaking_Omnibus/research/aux_P26z13_loadtest/arma3server_x64_2026-11-21_22-36-19.rpt`), cross-checked against Miran's client RPT `arma3_x64_2026-11-21_23-34-44.rpt` (same lines). Configs extracted from live P26z14 PBOs.
Tools: `trace.py` (follows every later update of the same class path to the final parent), `extract.py`, `make_fixes.py`, `aatcrew/make_p26z15.py`. Trace output: `trace_z13.json`.

**31 blanks = 2 broken now + 5 restored by another mod + 17 restored by our own addons + 7 main-menu UI (harmless).**

## 1. Broken now (still blank after the full load)
| # | Class path | Blanked by | Touches | Fix |
|---|---|---|---|---|
| 1 | `3AS_PX10_Base_F/HitPoints` (was HitPoints) | 41st_Vehicles px10 | PX-10 damage zones | **Done in P26z14 (live)** |
| 2 | `CfgWeapons/FST_ATRT_Base/ItemInfo` (was UniformItem) | BUZZ_Vehicles atrt (BUZZ_ATRT cargo patch) | the hidden AT-RT uniform item and its children: ItemInfo loses everything UniformItem gives it (the uniform item type in vanilla); its own uniformModel / uniformClass / containerClass / mass remain | `class UniformItem; ... class ItemInfo: UniformItem` (staged) |

## 2. Fine today only because another mod loads later and puts the parent back
| # | Class path | Blanked by | Restored by (final) | Touches | Risk if the order changes |
|---|---|---|---|---|---|
| 3 | `arifle_MX_Base_F` (Rifle_Base_F) | 41st_Weapons 773-firepuncher | DBA_RADC (DBA CIS 2781146469) | every MX-family weapon, including our blasters built on it (DC-15N, DLT-15, ...) | HIGH: if DBA leaves the modlist or loads earlier, every MX-based weapon loses its rifle base |
| 4-5 | `Rifle_Base_F` (Rifle), 2 lines | 41st_Weapons dc-15n, then dlt15 (DC-15L restores in between) | 3AS_Weapons_Block_Crossbow (3AS) | every rifle in the game | HIGH: depends on a 3AS crossbow addon loading after us |
| 6 | `missiles_titan` (MissileLauncher) | FST_Vehicles_Weapons (config.bin) | ace_realisticnames (ACE) | the Titan missile weapon family | MEDIUM |
| 7 | `3AS_PX10_Base_F` (Tank_F) | 41st_Vehicles px10 | ls_compat_tas | PX-10 | **Done in P26z14 (live)** |

## 3. Fine today only because another of OUR addons loads later
| # | Class path | Blanked by | Restored by | Touches | Risk |
|---|---|---|---|---|---|
| 8 | `CfgVehicles/Helicopter` (Air) | 41st_Vehicles laatc (FST_LAAT_Cargo) | 41st_Vehicles maf (FST_CIS_Heli_MAF) | every helicopter | HIGH impact: the order between those two patches is not pinned |
| 9-24 | 4 [41st] light attachments (Light/Module x Normal/Beam White): `Iteminfo` and `Iteminfo/Flashlight`, 16 lines | 41st_Weapons dc-15as and sbb3 | dc15x, then z6 (FST_Weapons_DC15L) | those four attachments; the top-level parent also flips acc_flashlight <-> FST_Base_Flashlight four times | LOW-MEDIUM: final values are a merge either way, so only the inheritance moves |

## 4. Harmless / intended: no fix
| # | Class path | By | Why |
|---|---|---|---|
| 25-27 | `RscDisplayMain/Controls/Group{Multiplayer,Options,Session}/Controls` | 41st_Menu | intended: the menu rebases these groups onto RscControlsGroupNoScrollbars and writes their full button lists; the blank stops the singleplayer buttons being inherited |
| 28-31 | `RscTitles/RscDisplayMainMenuBackground/Controls/{Background, BackgroundLeft, BackgroundRight, Picture}` | 41st_Menu | the 2.22 black menu backdrop; they lose RscText/RscPicture parents, but Miran's client RPT shows no errors for them and he sees this menu at every launch. Optional later fix (`Background: RscText`, `BackgroundLeft/Right: Background`, `Picture: RscPicture`); client-only, needs his look. Not staged |

## Six more, latent (not in the 31)
One of our addons appears to declare these with no parent, but loads before the class's owner, which then sets the parent. They're fine today. If our addon ever loads after the owner, it blanks them.
`Cannon_30mm_Plane_CAS_02_F` (fst_arc_170), `StaticMortar/Turrets/MainTurret` (fst_mortar), `MBT_01_base_F/Turrets/MainTurret/Turrets` (fst_av7), `3AS_Sabre_Cannons` (fst_sabertank), `ACE_muzzle_mzls_338` (fst_dc15u), `lsd_gar_bodyGlove_uniform` (41st_addon). Not fixed; a next pass.

## P26z15 candidate (staged, NOT published)
- Folder: `Downloads/Steam-aux-CANDIDATE-20261122-P26z15-blank-fixes` = live P26z14 + 4 PBOs, 101 files / 8,401,067,421 B (+1,344 B).
  - `41st_Vehicles.pbo` 67172fc1: laatc/config.cpp only (`class Air; class Helicopter: Air`).
  - `41st_Weapons.pbo` 7489a059: 5 configs. 773-firepuncher (`arifle_MX_Base_F: Rifle_Base_F`), dc-15n + dlt15 (`Rifle_Base_F: Rifle`), dc-15as + sbb3 (the 4 attachments now `: FST_Base_Flashlight` with `Iteminfo: Iteminfo` / `Flashlight: Flashlight`, plus the same FST_Base_Flashlight block already identical in t15/dc15x/dlt15/dp23/z6).
  - `BUZZ_Vehicles.pbo` 6347c656: atrt/config.cpp only (`ItemInfo: UniformItem`).
  - `FST_Vehicles_Weapons.pbo` e5210ad6: config.bin re-binarized (`missiles_titan: MissileLauncher`). The unmodified round-trip is byte-identical to live, so this is the only change.
- Checks: CfgConvert OK on all 8 configs; pbo_gate PASS on all 4 PBOs (only the named entries changed); `--check` 04:43:10Z.
- Not done: engine boot. A server-only load test should show the 22 non-menu blank lines gone, plus their restore lines (DBA, 3AS crossbow, ACE realistic names, MAF, DC-15X, Z-6). Needs BOX OK from the Omnibus. Miran's client was running at 23:35, so not now.
- Worth an in-game look before shipping: AT-RT ride (uniform), [41st] lights on DC-15AS / SBB-3, LAAT cargo.
- Repo copies not updated (commit on Miran's word).
- Publish only on Miran's typed go naming P26z15.
