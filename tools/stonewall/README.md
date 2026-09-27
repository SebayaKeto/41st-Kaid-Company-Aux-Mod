# Project Stonewall

Save a live Arma 3 op where it stands, then carry only the marked player-built bases (ACE Fortify,
Daidalos) into the next mission as an Eden layer.

```
live op ──(Zeus marks keep areas)──> stonewall_save ──> RPT ──> extract ──> clean ──> bake ──> next mission (new copy)
```

## Zeus modules: FST_Stonewall addon (for the Aux)

`addon/FST_Stonewall` is the source; `python tools/build.py` packs `release/@FST_Stonewall/addons/FST_Stonewall.pbo`
(prefix `FST_Stonewall`, needs CBA; the Zen modules appear when Zen is loaded). Zeus > Modules > **41st Stonewall**:

| Module | What it does |
|---|---|
| **Keep Area (carry base over)** | Opens a dialog: base name, circle or square, radius (drawn live), rotation. Creates a green keep-area marker plus a flag label. |
| **Remove Keep Area** | Place it inside a Stonewall keep area to delete that area. |
| **Save Mission** | Asks whether to save everything built or keep areas only, then saves on the server. The Zeus gets a confirmation, and the keep-area data lands in the Zeus's own RPT too. |

With the addon loaded, every mission also gets:
- exact `built` tags (objects created after the start) and `zeus` tags;
- CBA settings (Addon Options > 41st Stonewall): tracking on/off, and **Daidalos object variables**.
  Enter Daidalos's variable name there once it's known; no repack is needed.

The save request goes by `remoteExecCall`. The server checks the engine-verified sender (`remoteExecutedOwner`),
who must be a Zeus or a logged-in admin. A mission CfgRemoteExec whitelist can block the request; the module then
tells Zeus after 90 s to use the console fallback. The data copy back to Zeus goes by CBA events. A second request
while a save is running is refused, with a message. Every machine tags the objects it creates as "built" (a
player's Fortify or Daidalos pieces are created on their own PC). See `REVIEW.md` for the code review. The debug-console paste script stays as the fallback for servers without the addon. It's
generated from the same source file (`functions/fn_save.sqf`), so both routes always match.

Engine test: `test/addon_test.py` (CBA + ACE + Zen + the release PBO): 20/22 for 1.2.2 after two review rounds. The 2 misses need a headless client, which joins only about 1 run in 5 on this rig (see REVIEW.md). The module
**dialogs** themselves need a desktop client and are untested; the functions and events behind them are tested.

## 1. During the op (Zeus)

Mark every base that should carry over with ONE of:

| Tool | How |
|---|---|
| Zen area marker | Zeus > Markers > Area: draw a rectangle or ellipse over the base. **Every** Zeus-drawn Zen area marker counts, so don't use them for anything else in an op you plan to save. |
| Map marker | A marker whose text is `KEEP <radius> [name]`, e.g. `KEEP 80 Ridge FOB` (circle, 80 m radius). The radius is required, so "Keep clear" never counts. Place it in **Global** channel or as Zeus. The server can't see side or group channel markers. |
| Stonewall module | Only in missions with Stonewall built in: Zeus > Modules > Stonewall > Keep Area (name + radius). |

## 2. Save (end of the op, before the mission ends)

- **Debug console** (logged-in admin): paste all of `sqf/stonewall_save.min.sqf`, then press **SERVER EXEC**.
  Use the `.min` file: the console can't take comments.
  Scroll to the bottom of the box before executing, to check the last line pasted.
- **Fallback, if a paste gets cut off:** SERVER EXEC `sqf/stonewall_save_parts/part1_of_M.sqf` … `partM_of_M.sqf` (currently 12 parts)
  in order. Each part is about 1,000 characters, and the last one runs the save.
- **Zen "Execute Code" module**, target Server: paste the same `.min` text.
- **Missions with Stonewall built in:** Zeus > Modules > Stonewall > Save Mission.

A chat line confirms it:
`Stonewall <id>: saved N objects, M inside K keep areas`

The data goes to:
- the **server RPT** (everything);
- the **Zeus's own RPT** (the keep-area part), so a Zeus on this PC needs nothing from the box.

The save changes nothing in the mission. It runs in the background, taking a few seconds per 10k objects.

## 3. Offline (this PC)

```bash
python D:\Stonewall\tools\stonewall.py extract <server-or-client.rpt> --out save.json
python D:\Stonewall\tools\stonewall.py clean save.json --live-mission <the op's mission .pbo> --out kept.json --report report.md
python D:\Stonewall\tools\stonewall.py bake kept.json --into <next mission .pbo or folder> --out <NEW folder> --pbo <NEW .pbo>
```

- `clean` keeps objects that meet all of these:
  - inside a keep area (plus a 5 m margin);
  - alive and not hidden;
  - a static or thing. Static weapons, vehicles, boxes and "other" are dropped unless you pass `--include-kind`, and ACE spare wheels and tracks are always dropped;
  - Fortify-built, Daidalos-built, or created during the op. Zeus-placed objects are dropped unless you pass `--include-zeus`.
- Objects with no build tag are dropped unless you pass `--live-mission` (which removes the op's own editor objects
  and keeps the rest) or `--keep-unknown`. Always pass `--live-mission`.
- `extract` refuses to guess when an RPT holds several saves; pass `--sid` (or `--latest`).
- Read `report.md` before baking. It lists every area with counts, sources and top classes, and a "kept without a build tag" list to eyeball.
- `bake` never modifies its input. It writes a new mission folder (and optional `.pbo`) with layer
  `Stonewall <date> (<op>)` > `Keep <area name>`. It appends the layer as the last `Mission > Entities` item,
  gives it fresh Eden IDs and bumps both ID providers. It also adds any missing `addons[]` / AddonsMetaData entries.
  The world must match: bake refuses a Kaid save into a Duskfall mission unless you pass `--any-world`.
- The new mission then goes through the usual gates (`pre_review.py`, delivery_check) and the Omnibus install path.
  Stonewall doesn't install anything.

## How objects are recognised

| Source tag | Meaning | Needs |
|---|---|---|
| `fortify` | ACE Fortify placed it (ACE stamps `ace_fortify_tokensUsed` on every placed object) | nothing; works on any live mission |
| `daidalos` | Daidalos placed it | the Daidalos variable names in the CBA setting (or `stonewall_daidalosVars` without the addon). **Not yet known:** the mod isn't on this PC |
| `built` | created after mission start on a player's PC (ACE Fortify and player build mods create there) | the FST_Stonewall addon, or `stonewall_init.sqf` in the mission |
| `zeus` | placed by a Zeus (curator event, or created on a PC while in the Zeus interface) | the FST_Stonewall addon, or `stonewall_init.sqf` |
| `spawned` | created by the server or a headless client (mission scripts, HCSpawn, Zen compositions); dropped unless `--include-spawned` | the FST_Stonewall addon |
| `fortify_class` | class is in the mission's ACE Fortify preset, but no stamp | nothing |
| `unknown` | none of the above; kept only if it isn't one of the op's editor objects | `--live-mission` |

Until the Daidalos tag is added, Daidalos builds come through as `unknown`. They're still kept inside keep areas
once `--live-mission` has removed the op's editor objects.

## Mission integration (optional, for missions we build)

Copy `sqf/stonewall_init.sqf` and `sqf/stonewall_save.sqf` into `<mission>\stonewall\`, then add to `init.sqf`:

```sqf
[] execVM "stonewall\stonewall_init.sqf";
```

This adds exact `built` / `zeus` tags and the two Zen modules.

## Test status (27 Sep 2026, `runtime/t-20260927-132204`, ALL PASS)

Two dedicated-server boots on VR with CBA and ACE, ~40 s each.
- Phase 1 recognised all 3 keep-area types and ignored a non-keep area marker. Clean kept 6 Fortify objects plus a
  corner piece in a rotated rectangle, 4 tracker-built and 3 untagged objects. It dropped Zeus props, a vehicle, a
  destroyed barrier, objects outside the areas and the mission's own 2 editor objects.
- Offline keep-area maths agrees with the engine's `inArea` on every object.
- Phase 2 booted the baked **PBO**. Every kept object was back with 0.0000 m position error and 0.00000 vector
  error, including tilted pieces (pitch and roll up to 20°).
- Phase 2 saved through the console fallback parts.
- Re-run after the code review (`runtime/t-20260927-141528`): 16/16 PASS.

Not tested:
- A real ACE Fortify placement by a player. The test sets ACE's stamp directly: `ace_fortify_tokensUsed`, which
  ACE sets in its deploy code.
- Zen modules and the client-RPT copy (they need a desktop client).
- Daidalos (not installed).

## Layout

| Path | What |
|---|---|
| `sqf/stonewall_save.sqf` | save script (readable). Rebuild the `.min` with `python tools/minify_sqf.py sqf/stonewall_save.sqf sqf/stonewall_save.min.sqf` |
| `sqf/stonewall_init.sqf` | optional mission hook: tags + Zen modules |
| `tools/stonewall.py` | extract / clean / bake |
| `tools/sqmtext.py` | span-keeping mission.sqm reader, so edits are spliced in and the rest of the file stays byte-identical |
| `test/engine_test.py` | two-boot engine round trip on VR (ports 3802-3803, engine_lane owner `Stonewall`) |

Rotations use the Omnibus `vendor/eden_rotation.py` (engine-verified Eden convention). Mission PBOs are read with
`preflight/mission_preflight.py`'s strict reader. Both are imported, not copied.
