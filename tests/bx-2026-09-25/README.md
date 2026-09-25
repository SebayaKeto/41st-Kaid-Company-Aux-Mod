# BX qualification

The installed external WebKnight mod is required. No WebKnight controller source is bundled here.

Use the exact tested FST_HCSpawn PBO and the usual Aux/dependency set. The VR fixture has four headless-client slots. Its init waits for those four owners and dispatches one variant per owner plus the dedicated server.

In `BXEnhance.VR/init.sqf`, `Q_fnc_stance` selects `guards.sqf` for the order/network/death checks followed by real dodge recovery, or `run.sqf` for the movement and melee comparison. Package the mission normally and run privately. These are automated fixtures with target invincibility and control loadouts; they are not a playable mission.

The two result summaries contain 210 passed checks. `peer-speed-results.json` contains 25 owner/observer coefficient checks. The build manifest identifies the exact addon and installed dependency. Full raw private RPTs are retained in the local delivery Runtime-Evidence.zip; no live server or Workshop deployment was performed.
