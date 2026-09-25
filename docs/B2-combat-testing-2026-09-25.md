# B2 firing line and Flame B2 removal

Flame B2 (`FST_B2_Flame`) and its BURNS Flame Team spawn module/template are removed. Regular B2 and B2 team leaders remain. The retired stance source also no longer names Flame B2. The installed external WebKnight mod is unchanged.

Pure AI 41st B2 groups form a line facing a known, visible hostile contact within 350 metres. They use five-metre lateral slots and short six-metre bounds, waiting for most of the line to catch up before advancing again. They retain a 45-metre firing distance. The default-on **B2 combat firing line** CBA setting can disable the behavior.

The helper uses native movement and group formation/fire rules, preserving WebKnight's walking pace, weapon gestures, firing handlers, animation speed, health and damage behavior. It runs in the existing bounded BURNS owner service. Mixed groups, empty-handed units, players, remote control, vehicles, attachments, exemptions, path holds, Zeus holds, manual waypoints and defensive/retreat/stop orders are excluded. Stop, loss of contact or disabling BURNS restores owned group settings. A new patrol permits combat formation again.

## Validation

The exact two addon binaries passed **145 runtime checks** across a private dedicated server and four headless clients using installed WebKnight (`0e1561094d6797b1622f3e6cba59f56d9d9c6fe49175f9263ecfd44d6790ca24`). Combat fixtures exercised groups of 2, 4 and 8 regular B2s/team leaders against visible stationary targets. All formed a wider-than-deep front, maintained spacing, advanced and continued firing. Median nearest-neighbor distances measured after initial deployment ranged from 4.99 to 5.39 metres. Guards checked restoration, holds, settings, task intent, mixed groups, casualty leadership, lost contact, native AI/health, and absence of Flame B2/module/template on every owner.

CfgConvert accepted both configs; packed config and asset/script bytes match staged source. No new script errors occurred. Existing third-party particle-expression warnings were excluded. The 120-second movement observation allows wide walking formations to settle; one earlier 60-second trial advanced only 6.6 metres and failed an eight-metre progress check. Earlier mixed-Flame trials also failed; their missing installed weapon dependency helped motivate removal. Those trials are retained in raw evidence rather than counted as final passes.

These are controlled VR integration tests, not human-player or terrain-specific playtesting. Buildings and terrain can constrain spacing and native pathfinding. No WebKnight source is bundled or overridden.

## Delivery

The two matching unsigned addons are `41st_Droids.pbo` and `FST_HCSpawn.pbo`. Existing missions that explicitly name the removed Flame B2 class must replace those units. Server, headless clients and player clients should use matching updated Aux files in a fresh session. No live server or Workshop files were changed.

Both PBO hashes, matching source changes, mission fixtures and summaries accompany this report. The exact tested PBOs and matching source are committed in `PUBLISHED MODPACK`; fixtures and summaries are under `tests/b2-2026-09-25`.
