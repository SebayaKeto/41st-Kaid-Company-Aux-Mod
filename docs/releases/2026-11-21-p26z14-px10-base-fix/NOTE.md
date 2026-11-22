# P26z14 (21 Nov 2026): PX10 base-class fix on P26z13

Published 23:35 EST (04:35:28Z 22 Nov) on Miran's go "Go P26z14", typed by him in the Mapmaking Omnibus session (verified in its transcript; relayed here by the Omnibus). ManifestID 9087755986104411506, time_updated 1795322128, 101 files / 8,401,066,077 B. Workshop API agrees.
Only change: Addons/41st_Vehicles.pbo -> 151f840f (687,150,322 B); only px10\config.cpp replaced (pbo_gate PASS, 440 entries identical). Fixed config copied here as px10_config.cpp.
Why: FST_PX10_41st redeclared 3AS_PX10_Base_F without its parent (Tank_F->'') and its HitPoints without inheritance (HitPoints->''). ls_compat_tas restored Tank_F; HitPoints stayed blank. Fix declares Tank -> Tank_F (HitPoints: HitPoints) -> 3AS_PX10_Base_F: Tank_F { HitPoints: HitPoints } as 3AS does, plus requiredAddons 3AS_Rebel_Armor_PX10.
Tested: Omnibus server-only load test (Ember_Op3plus r7, 23:20 21 Nov): 0 PX10 base-class lines, updates 296 -> 293. Not covered: client, PX10 drive.
Rollback: Downloads/Steam-aux-ROLLBACK-to-P26z13-from-P26z14 (--check 04:35:54Z).
