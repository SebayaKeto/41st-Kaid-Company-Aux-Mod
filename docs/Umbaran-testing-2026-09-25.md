# Umbaran units and BURNS qualification — 25 September 2026

The corrected 41st Umbaran addon passed 58 isolated dedicated-server assertions with four matching headless clients. The patch is ready for an Aux build. It has not been installed into the running server or published to Workshop.

## Changes

- Give the addon its own `41st_UmbaranUnits` patch identity and declare its actual inherited-addon dependencies. The old identity collided with `41st_CorruptPDF` and was skipped by Arma.
- Match faction, units and all seven groups to OPFOR.
- Preserve parent vest armor and equip SpecOps with its intended armored bodysuit.
- Give ordinary infantry native armor 6, between the too-fragile armor-4 and overly durable armor-8 trials. SpecOps keeps its authored hitpoint armor.
- Raise ordinary cognition/leadership to at least 0.8, reaction skill to 0.9, aiming speed to 0.8 and reload skill to 0.75. Authored accuracy is unchanged. B1 cognition/leadership measured 0.5 in this preset.
- Complete loadouts/skills after native spawn setup, atomically on the owning machine, and retry initialization on locality acquisition. This prevents a half-initialized unit or reset skills during creation/transfer.
- Restore functional Medic and Engineer/EOD specialties.

## Runtime evidence

All 11 unit types spawn with usable weapon ammunition (the Commander intentionally uses a pistol). All seven group presets spawn at their expected sizes. BURNS classifies them as human infantry and retains native cover, suppression and combat behavior. No B1 marching policy is applied.

Exposed hostile AI engagement tests used no reveal or forced-fire commands. Defending fireteams, assaulting squads and hunting SpecOps opened fire; SpecOps selected flank-and-suppress. Both ownership transfer and the production HCSpawn group-creation path retained loadouts and human skills, and HC-controlled Assault moved successfully. The fixture waits for ownership to settle: an early fixed-delay probe was inconclusive and is retained in the previous runs.

Twelve repeated native projectile trials per class used `FST_blasterbolt_High_Blue`, identical stationary front-torso geometry and the same preset. Projectiles were created 5 metres in front of a standing target at 1.15 metres above ground and given 300 m/s velocity; no scripted damage was applied. These measure projectiles until incapacitation or death, with a maximum of 16. A target still healthy at that limit is a censored result, not a 16-projectile kill. They are a small controlled sample, not a universal combat kill-count guarantee or a player-fired weapon qualification.

| Class | Trial projectile counts | Median |
|---|---|---|
| FST_Droid_B1_E5 | 9, 4, 5, 5, 7, 3, 7, 2, 9, 6, 6, 11 | 6.0 |
| FST_UmbaranInf_Standard | 9, 7, 9, 9, 11, 11, 10, 14, 13, 15, 12, 2 | 10.5 |
| FST_UmbaranInf_SO | 7, 9, 8, 6, 9, 8, 12, 9, 9, 8, 11, 8 | 8.5 |

Raw evidence: `outputs/testing/runs/run128-umbaran-final`. Earlier runs 123–127 retain baseline findings and rejected intermediate settings. No live Main, Training or existing BURNS server files were changed. Visual faces/textures, player animation and broad terrain balance still need a graphical-client playtest.

## Package

Copy the PBO from `Aux-Patch/Addons` into the Aux build's Addons folder, then restart a matching server/client session. Do not load this alongside another PBO defining the same classes. Keep all existing Aux dependencies.

SHA256: `c999a8eec9501c5b810951b2808d6f76205552c819e701a17bdd909beb426b4c`. Packed prefix: `41st_UmbaranUnits`. The packed files match the source, the internal PBO checksum passes, and no unresolved Git LFS pointers are present.
