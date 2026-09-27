# Stonewall code review - 27 Sep 2026 (FST_Stonewall 1.1.0 -> 1.2.0)

Two passes: an independent reviewer agent read the code cold, and I (the author session) did my own pass.
Every finding below was checked against the code, and fixes were re-tested on a dedicated server.

| # | Sev | Finding | Status |
|---|---|---|---|
| 1 | HIGH | The save request trusted a **claimed** owner ID sent over a CBA event. Any client could claim to be the server (owner 2) and trigger a save. The optional mission hook used `compile` (so a client could overwrite the function with publicVariable) and did no auth check. | **Fixed.** Requests now go through `remoteExecCall`, and the save checks the engine-verified `remoteExecutedOwner` (must be Zeus or a logged-in admin). The CBA save event is gone and the hook uses `compileFinal`. Tested: 2 server requests pass, the second is locked out. The HC rejection test could not run (see below). |
| 2 | HIGH | The save and clean over-collected: attached, carried and towed objects, crewed turrets, smokes, chemlights, mines (not CfgVehicles classes), scope-0 helpers, ACE spare wheels and tracks, and static weapons and "other" by default. | **Fixed.** The save skips non-CfgVehicles classes, scope < 1, attached or rope-attached objects, crewed objects, ACE explosives and mines. The default kinds are now static and thing (the others are opt-in), and ACE wheels/tracks and hidden objects are excluded. |
| 3 | MED-HIGH | Untagged objects were kept even with no `--live-mission`, which duplicates the op's editor objects. | **Fixed.** They're dropped unless `--live-mission` or `--keep-unknown` is given, and the report explains why. |
| 4 | MED | Bake inserted at the start of the closing-brace line. On a one-line `Entities{...}` sqm that puts the item outside Entities: an Item gap, which crashes the server. | **Fixed.** It inserts before the brace in that case. `validate_sqm` then re-checks items == children and Item0..N at every level, unique ids, and nextID > max id, and refuses to write otherwise. Tested on a one-line sqm and on Scar Reach (660k lines). |
| 5 | MED | Build stamps might be local-only. | **ACE is fine:** ACE sets `ace_fortify_tokensUsed` with public=true (read in ace_fortify.pbo), and the server now also tags from `acex_fortify_objectPlaced`. **My finding:** the "built" tracker ran on the server only, so objects created on a player's PC (Fortify, Daidalos) were never tagged. **Fixed:** every machine tags the objects it creates (`local` guard, public setVariable), and only for Static, Thing and StaticWeapon types. **Engine test pending:** the headless-client test would not connect in 3 tries (the HC stalls after its sessionID). Time-boxed. |
| 6 | MED | The save lock expired after 120 s, and whichever save finished first cleared it for all. The requester got no feedback. | **Fixed.** The lock is keyed to its save and only that save clears it; a stale lock is taken over after 900 s. The requester is told "a save is already running". |
| 7 | LOW-MED | `bake --into mission.sqm` dropped the rest of the mission folder. | **Fixed.** It copies the parent folder. |
| 8 | LOW-MED | `addons[]` got every patching addon (ACE compat, server-only), which can make the mission unjoinable. | **Fixed.** Only the defining addon is recorded and baked. Tested. |
| 9 | LOW | Extract silently took the newest save when the RPT held several. | **Fixed.** It lists them and requires `--sid` (or `--latest`). |
| 10 | LOW | Without the addon, the client copy goes by remoteExec, which a mission whitelist can block. | **Accepted.** The server RPT always has the full data. The addon uses CBA events for the copy. |
| 11 | LOW | "Keep clear" or "KEEPER" markers counted as keep areas, and so did every Zen area marker. | **Fixed.** The text must be `KEEP <radius> [name]`, and a CBA setting can turn Zen area markers off. Tested: "Keep clear of LZ" is ignored. |
| 12 | LOW | A second `build.py` run failed renaming old parts on Windows. | **Fixed.** Old parts get a timestamp suffix (set aside, never deleted). |
| A | MED | (mine) Non-UTF-8 bytes in a mission.sqm would crash bake. | **Fixed.** Surrogateescape round trip, so the bytes are preserved exactly. |
| B | LOW | (mine) The Zeus Save module waited forever if a mission CfgRemoteExec whitelist blocked the request. | **Fixed.** After 90 s it tells Zeus to use the debug-console fallback. |

## Tests after the fixes (27 Sep, 14:0x-14:16)
- `test/engine_test.py`: **16/16 PASS**. Two boots: paste script (11-part console fallback), clean, bake to PBO,
  reload. 0.0000 m and 0.00000 pose error.
- `test/addon_test.py`: **17/20**. Everything passes except the 3 checks that need the headless client (the HC
  joining, the HC-built object's tag, and the HC's rejected save request). The HC never connects on this rig
  (stalls after sessionID); that's a harness problem, time-boxed after 3 tries.
- Offline: bake self-check on Scar Reach's 660k-line mission and on a one-line Entities sqm; 2,000 random
  rotations round-trip exactly.

## Still unverified in engine
- Tags on objects built on a player's PC or an HC (item 5). The logic is small, but the first real op with the
  addon should end with one save plus `clean --live-mission` as a cross-check.
- The Zen module dialogs themselves (they need a desktop client).
- Daidalos: not installed; only the variable-name setting is tested.

---

# Round 2 - 27 Sep 2026 ~14:20-14:47 (1.2.0 -> 1.2.2)

A fresh reviewer agent (no knowledge of round 1) plus my own full re-read of the final files.
The reviewer confirmed round 1's fixes and the paste script (the 11/12 parts rebuild byte-identically, escaping is valid).

| # | Sev | Finding | Status |
|---|---|---|---|
| R2-1 | MED | Tracker network cost. Every Static/Thing a machine creates got 2 public, JIP-persistent setVariables, including the WeaponHolderSimulated left by each AI death. | **Fixed (1.2.1).** Skips weapon holders, ruins, craters, mines and CBA dummies. One broadcast (`stonewall_src`); `born` stays local. Tested: a dropped weapon gets no tag. |
| R2-2 | MED | "built" meant any object any script created, so Zen compositions, HCSpawn props and mission scripts inside a keep area were baked in. | **Fixed (1.2.2).** Tags now depend on the creating machine: player PC = `built`, player PC in Zeus = `zeus`, server/HC = `spawned`. `spawned` is opt-in (`--include-spawned`). Tested: server-script objects are tagged `spawned`, dropped by default and kept with the flag. |
| R2-3 | LOW-MED | The only reply came after the whole save, so on a big op Zeus got a false "no answer after 90 s" and might retry via the console. | **Fixed (1.2.1).** The server sends "save started" as soon as it takes the lock. |
| R2-4 | LOW-MED | (mine, confirmed by reviewer) Keep-area markers were created on the Zeus's PC and could vanish if that Zeus disconnects before the save. | **Fixed (1.2.1).** Create and remove run on the server via remoteExecCall with the same verified-sender check; the server confirms by message. Tested through remoteExecCall. |
| R2-5 | LOW | Clients could publicVariable-overwrite the save lock (jamming saves for the mission), `stonewall_opts`, the Daidalos lists and the console paste buffer (arbitrary server code between an admin's pastes). Voted-in admins passed the check. | **Fixed (1.2.2).** The lock, the keep counter, the tracker lists and the paste buffer live in `localNamespace` (never synced). Every input is type-checked. Only logged-in admins pass (`admin == 2`). |
| R2-6 | LOW | The AddonsMetaData insert still used the old start-of-line pattern; `validate_sqm` didn't check the List. | **Fixed.** Same safe insertion as Entities, and `validate_sqm` checks List items/names. |
| R2-7 | LOW | The bake world check was silently skipped when the target name had no `.world` suffix. | **Fixed.** It refuses unless the world is known or `--any-world` is given. |
| R2-8 | LOW | (mine) `stonewall_opts` of the wrong type threw an error after the lock was taken. | **Fixed.** Type-guarded. |

## Found by testing in round 2: a headless client's save request was accepted
In one run the test HC joined, and its `remoteExecCall` save request was **accepted**, although the HC is neither
Zeus nor admin. The HC connects only about 1 run in 5 on this rig, and the next 4 runs (which log the requester's
ID and admin level) never had it join, so the exact cause is **undetermined**.
- **Decision:** HCs are now explicitly allowed. They're trusted (they can only join from `headlessClients[]`), the
  same model FST_HCSpawn uses.
- **Open:** the path where a normal non-Zeus player is rejected has not been observed in engine; that needs a real
  client. The worst case if it were open is a read-only save: RPT lines and a brief CPU spike, no mission change.
  The save's header now logs `req=<owner>|reqAdmin=<level>|reqRemote=<bool>` for every save, so the first live use
  shows who asked.

## Tests after round 2 (1.2.2, PBO sha256 effb79e2...)
- `test/engine_test.py`: **16/16 PASS** (`runtime/t-20260927-144542`), using the console paste parts (localNamespace buffer).
- `test/addon_test.py`: **20/22** (`runtime/a-20260927-144334`); the 2 misses are the HC not joining. When the HC did
  join (run a-20260927-143302), its object and its save request both reached the server.

---

# Round 3 - 27 Sep 2026 ~14:50-15:00 (1.2.2 -> 1.2.3)

A third fresh reviewer. It verified every round-2 fix, found **no crash, data-loss or SQF syntax defects**, and
decoded all 12 paste parts back to the min script byte for byte.

| # | Sev | Finding | Status |
|---|---|---|---|
| R3-1 | MED (listen/self-hosted only) | A listen host has an interface, so its script-made objects were tagged `built`, and the host Zeus got no replies (false 90 s warning). | **Fixed.** Only a pure client (`hasInterface && !isServer`) tags `built`. Replies to a hosting Zeus go through CBA localEvent. |
| R3-2 | LOW-MED | The mission hook (`stonewall_init.sqf`, for servers without the addon) had none of the round-2 tracker fixes. | **Fixed.** It now uses the same tracker rules. Its header says to prefer the addon: the hook's keep markers are still created on the Zeus's PC. |
| R3-3 | LOW-MED | ACE body bags (`ACE_bodyBagObject`, created on the player's PC) at a FOB aid station would be baked in. | **Fixed.** Skipped by the tracker and excluded in clean. |
| R3-4 | LOW | Keep Area and Remove Keep Area failed silently under a mission remoteExec whitelist. | **Fixed.** A 20 s "no answer" notice suggests a `KEEP <radius> <name>` marker instead. |
| R3-5 | LOW | Build tags are object variables a malicious client could forge. | **Fixed.** With `--live-mission`, every source (not only untagged objects) gets the editor-object check. CHANGE_NOTE wording corrected. |

Tests (1.2.3, PBO sha256 673f20da...): `engine_test.py` 16/16 (`runtime/t-20260927-145734`); `addon_test.py` 20/22
(`runtime/a-20260927-145519`, the 2 misses are the HC not joining). The Aux Updater's full-modset boot of 1.2.2 (101
mods, 4 HCs that connected, 0 script errors) covered the unchanged parts.

---

# Round 4 - 27 Sep 2026 ~15:00-15:12 (1.2.3 -> 1.2.4)

A fourth fresh reviewer: **nothing serious**. It verified R3-1, R3-2, R3-4 and R3-5, and re-derived the min script and
all 12 parts byte for byte. In parallel I ran an engine probe of the one open question from round 2.

| # | Sev | Finding | Status |
|---|---|---|---|
| R4-1 | LOW-MED | R3-3 was incomplete: the ACE blue/white/old body bags (`ACE_bodyBagObject_*`, subclasses) were saved as `unknown` and could be kept. | **Fixed.** The save skips `ACE_bodyBagObject` and all subclasses, plus `ACE_Grave`, via isKindOf. The clean exclude is `^ACE_bodyBagObject(_\w+)?$`. Tested: a blue bag is not saved. |
| R4-2 | LOW | The client helper `FST_stonewall_fnc_awaitReply` and `FST_stonewall_lastReply` were plain globals, so a client's publicVariable could overwrite them on Zeus PCs. | **Fixed.** `awaitReply` is a CfgFunctions function (compileFinal); the reply time lives in localNamespace. |
| R4-3 | LOW | Text: Remove Keep Area's notice told Zeus to create a KEEP marker; the README part count and size were stale. | **Fixed.** |
| R4-4 | **finding** | **Engine probe (test-only build with HC trust removed, `runtime/probe_nohc`, not for release):** an HC's `remoteExecCall` of the save arrives on the server with `isRemoteExecuted=false remoteExecutedOwner=0`, exactly like a server-local call. The server's own remoteExecCall shows `true / 2`. Arma 2.22.154075. | **Handled honestly.** `remoteExecutedOwner` can't identify every sender on this engine, so the Zeus/admin check stops honest misuse and gives feedback, but it is **not a security boundary**. Under the default CfgRemoteExec, a client that can run scripts can already remoteExec any command. The dead HC clause is removed and the code comments say this. Every save's header logs `req/reqAdmin/reqRemote`. A strict "reject unknown origin" rule was **not** adopted: it could lock out genuine Zeus requests if real clients behave like the HC, and that can't be tested without a graphical client. |

Tests (1.2.4, PBO sha256 69fa0a88...): `engine_test.py` 16/16 (`runtime/t-20260927-151114`); `addon_test.py` 21/23
(`runtime/a-20260927-150855`; the 2 misses are the HC not joining).
