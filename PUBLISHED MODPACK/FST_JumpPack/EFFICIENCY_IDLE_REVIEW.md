# FST JumpPack — Idle-Safe Efficiency Pass

Built on top of `FST_JumpPack_conservative_safe`.

## Goal

Keep the working jump-pack behavior, including 50% in-air combat damage and fall-damage suppression, while making the addon effectively idle when nobody in the operation is wearing a jump pack.

## Key changes

### Demand-started recharge/watchdog PFH

The 0.25 second PFH no longer starts automatically for every client after postInit.

It now starts only when:

- the local player has a configured FST jump pack, or
- the local player has an active jump-created damage override that needs watchdog cleanup.

When both are false, the PFH removes itself with `CBA_fnc_removePerFrameHandler`.

### Watchdog still protects against permanent invincibility

The ACE damage restore watchdog is preserved. If a player removes the pack while airborne, the PFH stays alive until the active damage override is cleaned up. The PFH only stops after `FST_jumppack_damageOverrideActive` is false.

### No timeout-based cleanup

There is still no hard timeout on the damage override. Aircraft exits and repeated mid-air jumps are preserved. Cleanup is still tied to landing, water, vehicle entry, death, or invalid EH state.

### Less work for fully charged jump-pack users

If energy is already full / unchanged, the recharge PFH now updates only the timer and exits before doing backpack variable writes or HUD threshold checks.

### Arsenal flag is local-only

`FST_do_energy_recharge` is only read locally, so arsenal open/close no longer broadcasts it over the network.

Also fixed an edge case where opening Arsenal without a jump pack could leave `FST_do_energy_recharge` false.

### Deleted EH safety guard

The CAManBase deleted EH still exists for cleanup safety, but it now immediately exits for normal infantry unless the unit actually has `FST_jumppack_effects`. It also calls cleanup instead of spawning a scheduled thread.

### Effect tracking is local-only

Jump-pack particles/lights are local client effects, so `FST_jumppack_effects` is no longer public-broadcast.

## Expected idle behavior

If nobody is wearing a jump pack:

- no recharge/watchdog PFH should be running on clients,
- no 0.25s energy loop should exist,
- keybind registration still exists but only does work on keypress,
- loadout/arsenal handlers still exist but only run on those events,
- deleted CAManBase EH does only a cheap variable/count guard and exits.

## Debug checks

Local client, no jump pack:

```sqf
missionNamespace getVariable ["FST_jumppack_rechargePFH", -1]
```

Expected:

```sqf
-1
```

Local client, wearing jump pack:

```sqf
[
    player getVariable ["FST_jumppack_hasJumppack", false],
    missionNamespace getVariable ["FST_jumppack_rechargePFH", -1]
]
```

Expected:

```sqf
[true, someNumber]
```

After removing the jump pack and landing / no active override:

```sqf
[
    player getVariable ["FST_jumppack_hasJumppack", false],
    player getVariable ["FST_jumppack_damageOverrideActive", false],
    missionNamespace getVariable ["FST_jumppack_rechargePFH", -1],
    player getVariable ["ace_medical_allowDamage", true]
]
```

Expected:

```sqf
[false, false, -1, true]
```
