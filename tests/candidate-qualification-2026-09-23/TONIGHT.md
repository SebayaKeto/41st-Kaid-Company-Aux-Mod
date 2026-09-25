# Tonight's rehearsal package

The local mod and mission are prepared. The B1 changes passed the exercised server checks; the broken Gulanthar movement graph has been repaired and passed 37 checks. AAT behavior still needs resolution and a client rehearsal before treating this as an approved live release.

## Files to use together

- `@Kaid_Aux_Candidate`: complete independent Aux Mod folder, including the new Armor pod candidate, B1/AAT candidate and repaired Gulanthar addon.
- `missions/DaaraUmbaraTest2_Candidate.m_36vwm796742s99.pbo`: staged Daara mission, with the conflicting Zeus waypoint override disabled.
- `final-candidate-manifest.json` and `Verify-Candidate.ps1`: exact file list and a read-only checksum check. Run the script beside the mod folder after copying it. It rejects missing, altered and additional files.
- `rollback/Addons`: verified copies of the three original installed PBOs. The Gulanthar addon was new, so rollback also requires removing that new addon if it was installed. The live installation has not been changed.

## Before players arrive

1. Keep the current live preset available as the fallback. Rehearse the candidate separately first.
2. Load this same Aux folder on the rehearsal server, all four HCs and participating clients, alongside the existing dependency preset. Remove the older Aux and any optional AAT preview from that rehearsal preset to avoid duplicate addons.
3. Run `Verify-Candidate.ps1` against each copied candidate. Select the staged Daara mission for rehearsal. Use the normal signing process if the destination enforces signatures; these candidate PBOs are unsigned.
4. Confirm all four HCs connect. Spawn a 12-droid B1 group: check COLUMN travel, LINE contact formation, Rush/Hunt, hold fire, Zeus hold and boarding.
5. Test an AAT against targets in front, beside and behind it, both unassigned and on Rush/Hunt. Check cannon and side guns, hull direction, stopping, and a new manual travel order. Automated tests found inconsistent facing and occasional no-fire cases. Disabling the entire assist did not fix every case.
6. Walk normal, Berserker and Alpha Gulanthars across flat ground, up a natural slope and downhill; observe attack transitions and feature-disable release.
7. Drop pods over clear dry ground away from the player assembly area. All four ship types submitted 24 drops in testing, including anchor reuse. Troop losses occurred during delivery; do not count every spawned droid as a guaranteed survivor. Observe impacts, collisions and cleanup from a client.
8. Check Zeus menus/possession, player Saber/Raider protection and actual ACE incapacitation/revive/carry/drag. These require a client and were not possible on this server-only box. Rehearse the Daara objectives and adviser flow with two players.

If the AAT or client checks fail, keep the existing live preset for tonight. There is no verified switch that makes the full AAT candidate reliable in every tested situation. The experiments retained in the evidence are not included in the mod folder.

`READINESS.md` gives the detailed results and limitations. `qualification-evidence.zip` contains the source, logs, audits and local Git patches. Nothing has been published to Workshop or pushed to GitHub.
