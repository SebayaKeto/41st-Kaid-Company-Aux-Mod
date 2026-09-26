# Main and HC stability batch — 26 September 2026

Prepared for downtime deployment. Publishing this commit does not update or restart Main, HCs, or clients. Live performance recovery is not yet verified.

## Changes

- Suppress unchanged script state broadcasts; retain ownership handoff and corrective updates.
- Run Gulanthar and Raider controllers on their owner, guard duplicate initialization, and end obsolete controllers after ownership changes.
- Bound Gulanthar effects/searches and AT-RT wreck effects; terminate obsolete rider monitors.
- Block new heavy spawns during sustained low FPS or above configured limits and notify Zeus. Existing units remain intact.
- Pace managed spawns, cache curator registration retries, and limit cleanup to two groups / 24 AI per normal tick with player/objective protections.
- Improve AAT targeting of AT-TE armor and native cannon firing behavior without changing damage.
- Include the pending Droideka turret tracking change in source and the Vehicles archive.

## Packaging

The manifest lists four refreshed non-Raider PBOs and the installed sound-only PBO. The Vehicles archive includes the two AT-RT script fixes plus the pending Droideka config change; every other entry matches the previously validated release archive. Existing Droids, Umbaran, and Gulanthar PBO changes are included as present in the working tree and are not covered by these stability checks.

The full Raider PBO is deliberately excluded from Git and retained locally. Deploy the locally verified Raider replacement archive, which preserves the installed model. Source fixes are under `FST_Vehicles/FST_Vehicles_Land/FST_Vehicles_Land_APC/FST_Vehicles_Land_APC_SabreAPC`; model-source build equivalence remains unverified. Its updated config and three new function files are required together. Removing archive tracking does not rewrite repository history or delete the local file.

## Raider sound preservation

Compared the installed aux Raider and sound archives with repository source. The Raider source config compiled identically to the installed baseline before the controller changes; those changes preserve sound, weapon, armor, and physics settings. Horn audio already matches. The sound addon config also compiles identically, but seven installed TX180 audio assets differ: three cannon recordings plus external idle, internal idle, engine-off, and engine-on recordings. Those installed recordings are copied into source and the installed `FST_Sounds.pbo` is included. Every other sound asset matches repository source. The full Raider archive and its model are not uploaded to GitHub in this batch.

The complete audit covers all **79 installed Raider archive entries**, all **166 sound-addon entries**, and the armor-extension DLL. All 15 material sources compile byte-for-byte to the installed material files; textures and unchanged scripts match directly. The armor DLL matches exactly. The replacement preserves every deployed archive entry except the two intentional config/controller updates, and adds the new controller functions/config source.

The repository has an editable MLOD model; the installed archive has a compiled ODOL model. Those hashes cannot establish build equivalence. The local replacement PBO preserves the installed ODOL byte-for-byte, and neither model nor full Raider PBO is uploaded to GitHub. Repository source-only files such as editable textures and model.cfg have no directly comparable standalone entries in the deployed archive. See `raider-complete-audit.json` for the entry-by-entry results.

Armor and Music archives remain local and unchanged; this commit changes none of their source files or assets.

## Validation and rollout

The stability release passed 71 isolated Arma engine checks, 35 SQF parser checks, and four addon config compilations. The additional Droideka config also compiles. Archive repacking verifies unchanged entries and replacement contents. These are not full-mod performance or multiplayer ownership-transfer results.

During downtime, back up deployed addons, distribute matching rebuilt addons to Main, every HC, and clients as required, and restart together. The installed distribution has no signatures on the changed archives, so the prepared Workshop package preserves that format; the unchanged ARQ signature is retained. If moving to signature enforcement, sign the affected archives and distribute the matching public key through the normal release process. Validate actual HC transfers, Raider animations/HUD, AAT firing, and Main FPS before scaling AI counts. Do not combine new scripts with old compiled configs.

## Complete Workshop package

The original Steam upload payload contained **69 files / 7,008,006,929 bytes**, based on the complete installed aux. Nine audited release archives were overlaid; only five actually differ from that installed baseline: Vehicles, BURNS Combat, HCSpawn, JMSEF animals, and the Raider. All other 64 files are unchanged. Armor and Music are included unchanged in Steam and remain excluded from this Git commit. The armor-extension DLL and current sounds are preserved.

`workshop-package-manifest.json` records every payload hash and the replacement archive hashes. The full Raider PBO is included only in the local Steam payload, never in GitHub. This complete package includes the final Vehicles build and installed Raider sounds and supersedes the earlier five-PBO local selection. `workshop-change-note.txt` is the prepared update note for existing Workshop item [3048946639](https://steamcommunity.com/sharedfiles/filedetails/?id=3048946639).

Package preparation does not establish publication or live deployment. A successful Publisher result and fresh Workshop metadata are required to confirm publication; Main/HC rollout remains separate.

## Verified Workshop publication

Published to existing Workshop item [3048946639](https://steamcommunity.com/sharedfiles/filedetails/?id=3048946639) at **2026-09-26T10:15:47Z** using the official Arma 3 Publisher. Steam's upload log reports **OK**. Fresh public API metadata reports **7,008,006,929 bytes**, matching the complete **69-file** payload verified against the release manifest before upload. See `publication-receipt.json` for the timestamp, content manifest ID, and verification evidence.

Armor and Music remain unchanged. The full Raider PBO/model remain excluded from GitHub. This records Workshop publication only; live Main/HC deployment was not performed and remains a separate rollout.

## Raider startup packaging hotfix

The original publication included both root config.cpp and config.bin in the Raider PBO. Arma prioritizes config.cpp, which referenced an unpackaged Sounds header and blocked startup. The corrected package removes only this redundant source entry. All 82 retained PBO entries and headers, the compiled config, deployed ODOL model, sounds, and controller scripts are byte-for-byte unchanged. The Git source config remains available.

The corrected full upload contains 69 files / 7,007,928,124 bytes. See raider-packaging-hotfix.json for hashes and preservation checks. An isolated Arma 3 2.22.154075 probe with CBA, JLTS and 3AS passed addon/config loading and reached engine/server initialization without the missing include. Unrelated base-mission, BattlEye and Steam warnings mean full gameplay and multiplayer validation remain outstanding. Corrective Workshop publication is pending.
