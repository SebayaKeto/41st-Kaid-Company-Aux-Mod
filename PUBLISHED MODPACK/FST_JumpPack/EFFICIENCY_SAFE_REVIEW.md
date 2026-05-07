# FST JumpPack Conservative Efficiency + Safety Pass

This pass keeps the working jump model intact: fall damage is blocked during flight, combat damage is reduced by `FST_jumppack_air_damage_mult` (default 0.5), and repeated mid-air jumps are still allowed.

## Changed

- Removed the nested duplicate `FST_JumpPack/FST_JumpPack` folder from the deliverable.
- Added a low-cost damage watchdog inside the existing 0.25s recharge PFH. It restores `ace_medical_allowDamage` only if this addon marked the ACE override active and the flight state is over/invalid, or if the HandleDamage EH is missing.
- No timeout is used, so aircraft jumps and repeated mid-air jumps are not cut off early.
- Removed one no-op HUD threshold call after energy is spent; the threshold HUD only does useful work while energy rises.
- Removed an unused directional-jump division that could produce a divide-by-zero edge case when camera Z was flat.
- Changed final effect cleanup from `spawn` to `call` at landing because `remove_effects.sqf` does not sleep.
- Added a guard against zero/invalid max energy in the recharge HUD helper.

## Safety behavior

The watchdog is intentionally conservative. It does **not** remove jump protection while the player is airborne. It only restores ACE damage when:

- the player is on the ground,
- the player is underwater/in water landing state,
- the player died,
- the player entered a vehicle, or
- the addon says its damage override is active but the stored HandleDamage EH is gone.

That means the failure mode should be full normal damage, not permanent invincibility.
