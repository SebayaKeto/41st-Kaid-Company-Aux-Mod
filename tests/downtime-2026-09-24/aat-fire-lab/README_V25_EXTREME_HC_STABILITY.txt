FST_HCSpawn V25 - EXTREME HC STABILITY (2026-05-24)

This build is based on V24/V23 safe HC disconnect lineage and is intended as an emergency live-op stability bandaid after repeated HC crashes.

Purpose:
- Keep HCs enabled.
- Do not dump AI onto the dedicated server.
- Reduce droid radio protocol spam on HCs/server.
- Reduce dead-droid / ACE post-death churn.
- Prevent one HC from being driven far over the safe local-AI count during combat.

Key changes from V24:
1. Explosion diagnostics default OFF.
2. Emergency Droid Stability Bandaid default ON.
3. Runs enableSentences false on dedicated server and HCs when the emergency mute setting is enabled.
4. Applies droid stabilization immediately on HC-created units, after loadout restore, after setGroupOwner transfers, and via periodic scanner.
5. Dead droid bodies are hidden/simulation-disabled immediately on the local HC, then deleted quickly in small batches.
6. Adds a per-HC soft cap, default 240 AI, used when choosing a spawn target.
7. If all HCs are over soft cap, heavy spawns are blocked instead of falling back onto the dedicated server.

Expected RPT confirmation:
[FST_HCSpawn] postInit starting - HANDOFF_V25_EXTREME_HC_STABILITY_2026-05-24
[FST_HCSpawn][EMERGENCY] V25 droid bandaid active

Recommended emergency CBA settings for tonight:
- FST HC Spawn > Diagnostics > Automatic Explosion Diagnostics: OFF
- FST HC Spawn > Emergency > Emergency Droid Stability Bandaid: ON
- FST HC Spawn > Emergency > Emergency Mute AI Radio Sentences: ON
- FST HC Spawn > Emergency > Dead Droid Delete Delay: 0.25
- FST HC Spawn > Emergency > Dead Droid Deletes Per Pass: 20
- FST HC Spawn > Core > Per-HC Soft AI Cap: 220-240
- FST HC Spawn > Core > Block Spawns When All HCs Soft-Capped: ON
- FST HC Spawn > Core > Block Heavy Spawns Without HCs: ON
- FST HC Spawn > Core > Redistribute AI After HC Crash: OFF

Tradeoffs:
- Droid bodies disappear very fast.
- AI radio chatter on server/HC is muted.
- New mass spawns may be blocked once every HC is saturated.

This is not the final proper config fix. The long-term fix is still to correct the droid ACE medical/biology path, missing swdroidvoice assets/config, and any weapon/magazine config warnings.
