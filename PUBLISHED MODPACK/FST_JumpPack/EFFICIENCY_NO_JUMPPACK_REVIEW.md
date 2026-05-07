# No-Jump-Pack Efficiency Pass

Changes made after the idle-safe version:

1. `XEH_postinit.sqf` now exits immediately on dedicated servers and headless clients using `hasInterface`. This removes the old forever `waitUntil {!isNull player}` thread from server/HC instances.
2. Added CBA setting `FST_jumppack_enabled` under `41st Elite Corps > JumpPack`. Default is enabled. Set it false for ops with no jump packs to prevent client runtime hooks from being registered.
3. Removed the `CAManBase` Deleted XEH. That handler woke up for every deleted infantry unit. Local particle scripts and landing cleanup now own effect cleanup instead.
4. Arsenal handlers now have a no-op path for normal infantry. Closing Arsenal with no jump pack and no backpack change no longer forces a cache refresh.
5. Effect scripts now clean only their own created particle/light objects after 1 second. This avoids old jumps deleting effects from newer mid-air jumps.
6. `remove_effects.sqf` now avoids scanning `attachedObjects` unless tracked jump-pack effects existed.

Default behavior remains enabled. The hard-off setting is opt-in per mission/server setting.
