# FST Jumppack Performance Rewrite — Changelog
## Drop-in replacement files for the FST_JumpPack addon

---

## The Problem

The original per-frame handler created catastrophic load at 60 players:

| Metric (per client, per frame) | Old | New |
|---|---|---|
| Scheduled thread spawns | 2 | 0 |
| Config tree walks | 3 | 0 |
| Network variable broadcasts | 2 | 0 (broadcast only on meaningful events) |
| Tick rate | Every frame (~60/sec) | Every 0.25s (4/sec) |

**At 60 clients × 30fps, the old system generated ~3,600 spawned threads/sec and
~3,600 network setVariable broadcasts/sec just for energy recharge.**

---

## Files CHANGED (7 files)

### per_frame_EH.sqf
- Replaced `CBA_fnc_addPerFrameHandler` with 0ms delay → **0.25s interval**
- Replaced `spawn` → **`call`** (no scheduled thread creation)

### add_cba_per_frame.sqf (the recharge tick)
- **Removed all 3 config lookups** (`is_jumppack`, `get_recharge_rate`, `get_energy_capacity`)
  — now reads cached values from player variables set by `handle_loadout_change`
- **Energy stored locally** (`setVariable` without `true`) — only broadcast when hitting full charge
- **`last_call_time` is local-only** — no other client needs it
- **`show_energy_recharge` called, not spawned** — eliminates a scheduled thread per tick
- Added fast early-exit: cached boolean check for `FST_jumppack_hasJumppack`

### handle_loadout_change.sqf
- Now **caches all config values** when backpack changes:
  `FST_jumppack_hasJumppack`, `cachedCapacity`, `cachedRecharge`,
  `cachedJumpTypes`, `cachedEffectScript`, `cachedEffectPositions`, `cachedSoundIgnite`
- Clears stale cache when switching to a non-jumppack backpack
- Preserves original behavior: timer reset on backpack change

### XEH_postinit.sqf
- Removed outer `spawn {}` wrapper (unnecessary for CBA EH registration)
- **Primes the config cache** on mission start by forcing a `handle_loadout_change` call
- `sleep 0.5` removed (was arbitrary, not needed with cache priming)

### decide_jump.sqf
- Replaced `is_jumppack` config lookup → cached `FST_jumppack_hasJumppack` check
- Replaced `BIS_fnc_returnConfigEntry` for jump types → cached `FST_jumppack_cachedJumpTypes`
- Replaced `get_energy_capacity` config lookup → cached `FST_jumppack_cachedCapacity`
- `show_energy_recharge` changed from `spawn` to `call`
- All behavior (error messages, memeify, energy cost, prone/directional checks) preserved exactly

### jump.sqf
- Replaced `is_jumppack` config lookup → cached check
- Replaced sound path config lookup → cached `FST_jumppack_cachedSoundIgnite`
- Replaced effect script/position config lookups → cached values
- All flight behavior (velocity, allowDamage, waitUntil landing, jump_id tracking) preserved exactly

### set_jumptype.sqf
- Replaced `is_jumppack` config lookup → cached check
- Replaced jump types config lookup → cached `FST_jumppack_cachedJumpTypes`
- Hint display preserved exactly

### arsenal_closed.sqf
- Now re-primes the config cache (arsenal may have changed the backpack)
- Uses cached capacity instead of config lookup
- Behavior preserved: sets energy to full, enables recharge

---

## Files UNCHANGED (13 files — drop in your originals)

These files need NO modifications:

- `XEH_preInit.sqf` — Function compilation, no perf issues
- `configDBA.cpp` — Config classes, no changes needed
- `keybinds.sqf` — CBA keybind registration, fine as-is
- `add_arsenal_handlers.sqf` — Event handler registration, fine as-is
- `add_cba_player_loadout_EH.sqf` — CBA loadout EH registration, fine as-is
- `add_particle_effects.sqf` — Only called during jumps (event-driven)
- `arsenal_opened.sqf` — Just sets a variable, fine as-is
- `is_jumppack.sqf` — Still used by handle_loadout_change for initial check
- `get_energy_capacity.sqf` — Still used by handle_loadout_change for caching
- `get_recharge_rate.sqf` — Still used by handle_loadout_change for caching
- `show_current_energy.sqf` — HUD display, fine as-is
- `show_energy_recharge.sqf` — Threshold display, fine as-is (now called instead of spawned)
- `memeify_test.sqf` — Easter egg messages, fine as-is
- `remove_effects.sqf` — Effect cleanup, fine as-is

---

## New Player Variables (set by handle_loadout_change)

| Variable | Scope | Purpose |
|---|---|---|
| `FST_jumppack_hasJumppack` | player, local | Fast boolean: does player have a jumppack? |
| `FST_jumppack_backpack_class` | player, local | Last-seen backpack class for change detection |
| `FST_jumppack_cachedCapacity` | player, local | Energy capacity from config |
| `FST_jumppack_cachedRecharge` | player, local | Recharge rate from config |
| `FST_jumppack_cachedJumpTypes` | player, local | Jump type array from config |
| `FST_jumppack_cachedEffectScript` | player, local | Effect script name from config |
| `FST_jumppack_cachedEffectPositions` | player, local | Effect attachment points from config |
| `FST_jumppack_cachedSoundIgnite` | player, local | Ignition sound paths from config |

---

## Testing Notes

1. **Basic test**: Equip jumppack, verify energy recharges and HUD updates at 12.5% thresholds
2. **Jump test**: All jump types, prone check, directional/non-directional, energy cost deduction
3. **Arsenal test**: Open arsenal, swap backpack, close — verify energy resets to full
4. **Loadout test**: Pick up a non-jumppack backpack mid-mission — verify recharge stops cleanly
5. **Multiplayer test**: 10+ players with jumppacks — verify no script lag or desync
6. **Edge case**: Die mid-jump, respawn — verify system recovers (cache re-primes on loadout EH)
