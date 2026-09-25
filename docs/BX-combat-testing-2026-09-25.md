# BX combat update â€” tested with the installed WebKnight mod

AI 41st BX commandos now run 15% faster during ordinary upright/crouched running and sprinting. They commit to visible hostile infantry within 12 metres and repeatedly use WebKnight's existing melee animations within 3.2 metres. Successful attack attempts extend the short commitment; a pursuit that cannot reach its target expires after eight seconds and yields back to normal combat. Minimum repeat delay is 2.2 seconds, plus animation completion and scheduler timing.

The earlier dodge-recovery fix is included: a BURNS standing order preserves WebKnight's temporary crouch after a dodge and records only stance changes BURNS actually writes. Stopping a task therefore cannot restore an obsolete dodge crouch.

## Compatibility and ownership

These are original BURNS changes. The runtime loads the installed `@WebKnight_Droids` through a directory junction; no dormant GitHub copy of WebKnight's controller is loaded, edited, or included. The external PBO hash is `0e1561094d6797b1622f3e6cba59f56d9d9c6fe49175f9263ecfd44d6790ca24`.

The running multiplier releases for special animations, prone movement, death, vehicles, player control, exemptions and disabled BURNS. It yields to an externally owned coefficient, including WebKnight's native 1.35 post-dodge effect. Animation transitions use the event's new state, because the engine's state getter can still return the previous run state inside that event. All connected peers receive the coefficient; the boost has a separate JIP queue entry which is removed on release.

Melee pursuit temporarily owns gunfire, automatic combat and the individual engagement mode, restoring them when it ends. Task changes release that temporary state before recording a new task's baseline. Acquisition requires known, visible, living hostile infantry and rejects friendly, captive, downed, hidden and vehicle targets. It respects external path holds, Zeus group holds, manual distant move orders, and stealth/retreat/defensive tasks. It does not change melee damage, dodge immunity, health, force effects, animation files, or WebKnight handlers.

CBA settings: **BX running speed** defaults to 1.15 (range 1.00â€“1.30); **BX aggressive melee** defaults on. Disabling aggressive melee retains the older explicit CQB task behavior. Changes target `FST_BX` and inherited 41st variants, excluding the unrelated Womprat/player costume class.

## Runtime evidence

The exact same addon binary passed **210/210 checks** across a dedicated server and four headless clients, plus **25/25 cross-machine coefficient observations**. Standard, sniper, AT, AA and rusty BXs were exercised. CfgConvert succeeded and packed SQF bytes match the delivered source. No new script errors were found; existing third-party particle-expression warnings remain.

The 90 speed/melee checks include natural AI running against matched unarmed, fatigue-disabled human and unmodified BX controls; close pursuit; repeated melee; normal attack timing; external speed ownership; exemptions; hold-fire; captives; and restoring combat controls after task changes. Running velocity was sampled 200 times per unit; the 95th percentile measures steady running separately from pathfinding pauses.

| Measurement | Tested result |
|---|---:|
| BX steady running velocity | 26.47â€“26.48 km/h |
| Matched human steady running velocity | 22.97â€“23.03 km/h |
| Running advantage | 15.0â€“15.3% |
| Melee animation starts in each 20-second close-enemy fixture | 3â€“7 |
| Melee animation speed coefficient in that fixture | 1.00 |

The final regression run checks obstruction, friendly targets, feature disable, manual movement/Zeus holds, prone and death cleanup, roster cleanup and network coefficients. It then triggers real installed WebKnight dodges with near-miss projectiles and runs 60 checks through the normal BURNS CQB/creep/ambush scheduler with stock custom health. WebKnight retains its recovery crouch and restores standing normally; near misses leave health unchanged.

Melee targets used the installed mod's invincibility fixture flag to prevent knockback from ending repeatability measurements. These counts measure pursuit and attack decisions, not damage balance or player survival. Tests use VR on one host with five owner processes; live human-client/JIP and terrain-specific playtesting are not claimed. Earlier trial fixtures exposed an AI ranged-order conflict, mixed-side control interference and an animation-transition race; those trials were rejected before this final candidate.

## Delivery

`BX-Combat-Update-Tested.zip` includes the exact tested unsigned PBO, complete matching BURNS source, fixtures, summaries, and this report. Replace the existing FST_HCSpawn addon when adopting it; do not load duplicate copies. Server, headless clients and player clients should use the matching addon in a fresh session with the installed WebKnight dependency.

No live server folder or Workshop installation was changed. Private test processes are stopped after validation. The exact tested PBO is committed at `PUBLISHED MODPACK/FST_HCSpawn.pbo`; matching sources, fixtures and summaries accompany it in this repository.

Tested PBO SHA-256: `dbaa1e1933aca0070a18ce5154c5dc5848da4991398b34839b7801a9436aa6be`.
