# P26z22 (24 Nov 2026): Halloween release on P26z20

Published 22:30 EST (2026-11-25 03:30:23Z) on Miran's go "Publish P26z22 here", typed in the Aux Updater chat. He had first typed "Go P26z22" in the Zenoc Halloween session (~22:23); that publish attempt was blocked by this session's permission check. Staging: Omnibus request relaying "Yes, Fix 1" + the click-fix work; Miran typed "Add Pole face first" here.
ManifestID 8098004868618132953, time_updated 1795577423, 119 files / 8,659,344,866 B (+221,218,394). Workshop API agrees (time_updated, file_size, hcontent_file).
Base = P26z20 (6235468048858355231). Changes:
- Click-fix candidate 3: 15 new KAID compat PBOs (DBA, ACE 3 Extension, OPTRE FC, IDA, LS, 3AS, helicopter HitTransmission, Tank_F CargoTurret, tank RCWSOptics, static MG ViewOptics) + Aux-own config fixes in 41st_Weapons (missing attachments dropped: DC-15AS, DC17, SPA-K12, Westar, Z6), 41st_Ammo (FST_smoke_Impact sound), 41st_Vehicles (Saber heavy laser cannon scope).
- WBK Leaper shadow-texture compats (KAID_WBK_Leaper1/2ShadowTex_Compat; byte copies of WBK's own leaper textures at the paths the shadow LODs ask for).
- Zenoc Halloween terrain w14m fst_zenoc_halloween.pbo 2becbd80 (back in the Aux; needs CYTECH Core Assets 2764686098).
- House 0ccaa04e Pole face (41st_Armor 69189af4; only FST_Clone_Pole.paa; was P26z21, never published alone).
Gameplay change: Tank_F CargoTurret fix restores FFV seats (OPTRE Spectre AI 1->3 turrets, Spectre Recovery 0->2). Not looked at in game.
Tested: server load tests (warnings 8,632 -> 2, script errors = base); unattended Zenoc client 0 warnings before/after start (cand3, 23 Nov); exact live 75 proof 0 startup warnings (24 Nov 01:38); Leaper engine proof 0 "Cannot load texture" (24 Nov 12:57); Halloween op server-only load test on the staged folder before the Pole face (24 Nov 16:04): 12/12 facilities, 4/4 caves, PODS 22/22, dynsim 268+45, 0 mission script errors. Gates: aatcrew/gate_p26z22.json PASS.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z20-from-P26z22 (--check 03:30:58Z; publish only on Miran's typed go naming it).
Server + HCs need the Steam update before the Halloween op Wed 25 Nov 20:00 EST.
