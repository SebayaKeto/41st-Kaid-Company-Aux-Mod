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

Compared the installed aux Raider and sound archives with repository source. The Raider source config compiled identically to the installed baseline before the controller changes; those changes preserve sound, weapon, armor, and physics settings. Horn audio already matches. The sound addon config also compiles identically, but seven installed TX180 audio assets differ: three cannon recordings plus external idle, internal idle, engine-off, and engine-on recordings. Those installed recordings are copied into source and the installed `FST_Sounds.pbo` is included. Every other sound asset matches repository source. The full Raider archive and its model are not uploaded in this batch.

The complete audit covers all **79 installed Raider archive entries**, all **166 sound-addon entries**, and the armor-extension DLL. All 15 material sources compile byte-for-byte to the installed material files; textures and unchanged scripts match directly. The armor DLL matches exactly. The replacement preserves every deployed archive entry except the two intentional config/controller updates, and adds the new controller functions/config source.

The repository has an editable MLOD model; the installed archive has a compiled ODOL model. Those hashes cannot establish build equivalence. The local replacement PBO preserves the installed ODOL byte-for-byte, and neither model nor full Raider PBO is uploaded. Repository source-only files such as editable textures and model.cfg have no directly comparable standalone entries in the deployed archive. See `raider-complete-audit.json` for the entry-by-entry results.

Armor and Music archives remain local and unchanged; this commit changes none of their source files or assets.

## Validation and rollout

The stability release passed 71 isolated Arma engine checks, 35 SQF parser checks, and four addon config compilations. The additional Droideka config also compiles. Archive repacking verifies unchanged entries and replacement contents. These are not full-mod performance or multiplayer ownership-transfer results.

During downtime, back up deployed addons, distribute matching rebuilt addons to Main, every HC, and clients as required, and restart together. Re-sign rebuilt archives using the normal release process. Validate actual HC transfers, Raider animations/HUD, AAT firing, and Main FPS before scaling AI counts. Do not combine new scripts with old compiled configs.
