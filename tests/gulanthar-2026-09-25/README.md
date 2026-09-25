# Gulanthar pursuit qualification

Use both tested addon PBOs in build.json with the installed Aux/dependency set. External creature controllers are not bundled. The mission has four HC slots and dispatches fixtures to all five owners.

For the flat comparison and guard tests, select run.sqf in init.sqf and package as Gulanthar.VR. For final fleeing-human pursuit followed by packs and guards, select chase.sqf, also on VR. For pack tests alone select pack.sqf. For the natural uphill/downhill checks select terrain.sqf and package as Gulanthar.Altis; only the dedicated server spawns that terrain fixture to avoid interference between owners. Startup waits for all four HCs. Test targets are invulnerable. Sustained-speed and pack fixtures reposition targets; the fleeing human moves naturally. These are private automated tests, not playable missions.

The baseline helper is the prior committed BURNS helper with exemption names changed only inside the fixture, so the current shared service yields to the baseline runner. Native creature functions are unchanged. Alternate owners reverse comparison order; one owner does not reveal its target. Results retain all checks and movement metrics. Full raw logs and preliminary failures are retained in the local Runtime-Evidence.zip.
