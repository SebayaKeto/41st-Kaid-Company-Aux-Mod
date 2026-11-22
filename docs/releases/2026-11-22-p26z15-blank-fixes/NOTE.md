# P26z15 (22 Nov 2026): base-class blank fixes on P26z14

Published 00:04 EST 22 Nov (05:04:58Z) on Miran's go "Go P26z15", typed in the Aux Updater chat. ManifestID 4575268767879709269, time_updated 1795323898, 101 files / 8,401,067,421 B. Workshop API agrees.
Changes (only the named entries; pbo_gate PASS x4, CfgConvert OK x8):
- 41st_Vehicles 67172fc1: laatc config, `Helicopter: Air`.
- 41st_Weapons 7489a059: 773-firepuncher `arifle_MX_Base_F: Rifle_Base_F`; dc-15n + dlt15 `Rifle_Base_F: Rifle`; dc-15as + sbb3 light attachments `: FST_Base_Flashlight`, `Iteminfo: Iteminfo`, `Flashlight: Flashlight`.
- BUZZ_Vehicles 6347c656: atrt cargo patch `ItemInfo: UniformItem` (the AT-RT uniform item was blank after the full load).
- FST_Vehicles_Weapons e5210ad6: config.bin re-binarized, `missiles_titan: MissileLauncher` (unmodified round-trip byte-identical).
Audit and tiers: REPORT_BLANKS_P26z15.md.
Omnibus server-only load test (00:00 22 Nov): PASS. Base-class updates 293 -> 260; no Aux class blank after the full load; errors as z14. It also exposed blanks hidden before (dc-15n lights x8, dc-15u Rifle_Base_F), each repaired right away by our dc15x / dc15l: still order-dependent; next sweep.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z14-from-P26z15 (--check 05:05:51Z).
