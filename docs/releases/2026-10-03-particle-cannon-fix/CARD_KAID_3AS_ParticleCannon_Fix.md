# KAID_3AS_ParticleCannon_Fix: staged, NOT published (3 Oct 2026, Aux Updater)

**Status:** staged only. It ships only on Miran's own go in the Aux Updater chat, as an add-on to a future Aux variant.

## Files
- PBO: `D:/AuxUpdater/pcannon/@KAID_PCFix/addons/KAID_3AS_ParticleCannon_Fix.pbo`
  - sha256 `fe4179626176fd4b8e93e181bb19d33eb27d14e1215a320c015471727c606d35`
  - one entry (`config.cpp`, 965 B)
- Source: `D:/AuxUpdater/pcannon/patch_src/KAID_3AS_ParticleCannon_Fix/config.cpp`

## Target
- **Vehicle:** `3as_ParticleCannon` (3AS addon `3AS_Static_ParticleCannon`).
  - Parent chain: `3as_ParticleCannon_Base` > `StaticMGWeapon` > `StaticWeapon`.
  - Child: DBA `O_DBA_CIS_Particle_Cannon_F` (`DBA_CIS_Static_Cannons`), which inherits the fix.
- **Weapon:** `3AS_ParticleCannon` (`3AS_Static_ADSD` + `3AS_Static_ParticleCannon`).
  - Modes: manual / close / shorty / medium / far, out to 2100 m.
- **Magazine:** 4x `12Rnd_125mm_HE_T_Green`.
- **Ammo:** `Sh_125mm_HE_T_Green`.

## Before / after

| Value | Before | After |
|---|---|---|
| `Turrets/MainTurret/minElev` | -10 | **-30** |
| `maxElev` | 35 | 35 (unchanged) |
| traverse | 360 | 360 (unchanged) |
| ammo `aiAmmoUsageFlags` | 64+128+256 (infantry + light vehicles + armour) | unchanged, already correct |
| ammo `cost` / hit / indirectHit | 300 / 300 / 80, radius 6 | unchanged |
| weapon `aiRateOfFire` / ranges | sane | unchanged |

So the only change is gun depression. Nothing else in its config stops AI from engaging infantry or vehicles.

## Engine evidence

All tests ran on an isolated server with the full client modlist and the live Aux (`hb-fix`).

1. **Level ground, VR terrain, stock config.** The AI engages:
   - MRAP at 350 m: 10 shots;
   - infantry at 200 m: killed in 4 shots;
   - MBT at 350 m: 14 shots.
2. **Geonosis terrain, gun on high ground, target 350 m away, stock config:**
   - about 4° below: engages;
   - about 14° below: 2 shots;
   - **about 24° below: 0 shots.** The barrel stays stuck at about -10°.
3. **Same 24° site with the patch:** the barrel now reaches -24° to -30°. The AI still held fire, because the muzzle line (about 2 m above ground) clipped the mesa lip about 4 m in front of the gun. A forced shot cleared the lip and landed just beyond the target, so the barrel fires along its visual angle.
4. **The same gun moved 7 m past the lip, on the slope:** the gun tilts about 35° with the slope, so even stock kills the MRAP in 3 hits. Stock and patched behave the same there.

**Conclusion:** the patch removes the -10° depression cap, which is a real blocker for level-mounted guns on mesas or walls firing at targets more than about 10° below. It is necessary but not sufficient: the gun also needs a clear line from the muzzle to the target, so place it at the lip or raise it. I don't have an engine proof yet of patched AI fire from a *level* gun at a steep drop with a clear muzzle line. If needed, a Landing W1 site (real placement) is the next test.

## Pre-checks
- Prefix `KAID_3AS_ParticleCannon_Fix` and CfgPatches class `KAID_3AS_ParticleCannon_Fix` are unique; neither is in the live Aux.
- `requiredAddons[] = {"3AS_Static_ParticleCannon"}`, so it loads after the source. `skipWhenMissingDependencies = 1`.
- **Inheritance is unchanged.** Boot RPT shows no "Updating base class" line from this addon. Turrets parent = `3as_ParticleCannon_Base/Turrets`, and the base MainTurret parent = `StaticMGWeapon/Turrets/MainTurret`, both as before.
- The patch loaded (`configSourceAddonList` on MainTurret includes it). DBA child `minElev` reads -30.

## Ship path
At push time:
1. Add `Addons/KAID_3AS_ParticleCannon_Fix.pbo` to a new variant of the live base (`Downloads/Steam-aux-release-20261003-hb-fix`).
2. Update its manifest and run `--check`.
3. Publish only on Miran's go.
