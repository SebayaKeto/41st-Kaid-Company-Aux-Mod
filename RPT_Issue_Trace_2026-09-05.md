# Arma 3 RPT Issue Trace - 2026-09-05

## Scope

Source report: `Arma3_x64_2026-09-05_22-10-10.rpt`

- Report span: `22:10:11` through `22:19:29` (558 seconds)
- Total lines: 27,221
- Mission: `tempMissionSP.Altis`
- Major log bursts:
  - `22:10:35`: 3,166 lines (11.6%)
  - `22:10:36`: 16,442 lines (60.4%)
  - `22:10:43`: 2,755 lines (10.1%)
- Those three startup seconds account for 22,363 lines, or 82.2% of the entire report.
- Only two messages were logged from `22:11:46` through `22:18:59`, after mission initialization.

## Executive Summary

The most prevalent problem is a startup-time configuration cascade, not a sustained runtime script loop. The cascade is mostly associated with DBA classes and malformed or incomplete helper classes under `CfgVehicles`. FST also contributes through a stale HKD package that exposes an empty `StaticObject` base and loads obsolete HKD scripts with parser errors.

The Sabre armor UI does not produce repeated errors and is not supported by this RPT as the cause of sustained lag. The strongest Sabre-specific hitch candidate is first-time model loading: its Geometry and Fire Geometry LODs produce 18 `Strange convex component` warnings at `22:11:36`.

## Ranked Issues

| Priority | Issue | Count / evidence | Ownership | Likely effect |
|---|---|---:|---|---|
| 1 | `CfgVehicles` missing-property cascade | 12,903 `Warning Message` lines | Mostly DBA; stale FST HKD also contributes | Large startup/config-load stalls and heavy RPT I/O |
| 2 | HKD SQF parser failures | 20 expression errors and 20 `Missing ;` reports across five functions | FST stale `fst_hkd_core.pbo` | Broken HKD functions and an initialization hitch |
| 3 | Global base-class replacement conflicts | 180 replacement/update notices | Mixed mod set; two confirmed FST HKD UI overrides | Compatibility risk; can cause UI behavior changes |
| 4 | Missing textures | 57 | TKE, DBA, and two BI references | Missing icons plus avoidable load attempts/log noise |
| 5 | Malformed model convex components | 31 total; 18 belong to the Sabre | FST Sabre plus BI assets | Plausible one-time model/spawn hitch |
| 6 | Sabre extension not found | 2 attempts | FST deployment/loading | Enhanced assessment disabled; negligible sustained cost |

## 1. Configuration Warning Cascade

### Evidence

The warning families are:

| Message family | Count |
|---|---:|
| `No entry` | 6,303 |
| `'/' is not a value` | 4,843 |
| `Size: '/' not an array` | 1,372 |
| `[]: '/' not an array` | 288 |
| `Cannot evaluate '' - no file` | 288 |

These messages are related. Arma encounters incomplete classes and then queries hundreds of expected vehicle properties, producing a cascade for each affected class.

The largest repeated contexts were evaluated 262 times each. They include:

- DBA clone unit classes such as `k_clone_unit_104thWolfpack_Dirty`, `k_clone_unit_41stGC_Dirty`, `k_clone_unit_187th_Dirty`, and other unit variants.
- DBA capital ship and supply classes such as `Venator_MK2`, `SupplyDC15X`, and `SupplyE11D`.
- Incomplete helper classes exposed as vehicles: `MainTurret`, `Turrets`, `CargoTurret_01`, `HitPoints`, `MFD`, `Components`, `NewTurret`, `ItemInfo`, and `CopilotTurret`.
- FST HKD's `StaticObject` context (262 repetitions) and `FST_HKD_Blocker_Base` context (254 repetitions).

The report's most frequent `Last modified by` attribution records are:

| Addon attribution | Records |
|---|---:|
| `DBA_P2CloneUnits` | 435 |
| `DBA_Aux_Mod_CapitalShips` | 258 |
| `FST_HKD_Structures` | 254 |

These attribution counts are not one-to-one warning totals, but they identify the main config owners involved in the cascades.

### FST HKD Root Cause

The live report loads `P:\@FST\addons\fst_hkd_core.pbo`, but no separate live `fst_hkd_structures.pbo` appears in the package list.

The matching obsolete structure source forward-declares an empty `StaticObject` and derives `FST_HKD_Blocker_Base` from it:

- [FST_HKD_OBSOLETE/HKD_Structures/config.cpp](FST_HKD_OBSOLETE/HKD_Structures/config.cpp#L19)
- [FST_HKD_OBSOLETE/HKD_Structures/config.cpp](FST_HKD_OBSOLETE/HKD_Structures/config.cpp#L26)

That empty base explains both the `StaticObject` and blocker-base property cascades. The current source already uses the valid `House_F` base:

- [FST_HKD/FST_HKD_Structures/config.cpp](FST_HKD/FST_HKD_Structures/config.cpp#L75)
- [FST_HKD/FST_HKD_Structures/Blockers/Blocker.cpp](FST_HKD/FST_HKD_Structures/Blockers/Blocker.cpp#L14)

### Recommended Action

1. Remove `fst_hkd_core.pbo` from the live mod if the old HKD drop system is intentionally obsolete.
2. If HKD is still required, rebuild and deploy the current HKD structures package, then replace the old core package only after its scripts are repaired.
3. Report the DBA clone-unit and capital-ship cascades upstream with the affected class names. They are the largest non-FST source and cannot be corrected from this repository unless their source packages are available.
4. Retest startup and confirm that `StaticObject.StaticObject` and `FST_HKD_Blocker_Base.FST_HKD_Blocker_Base` no longer appear as repeated contexts.

## 2. HKD SQF Parser Failures

At `22:11:43`, five HKD functions generate parser errors. Each source location is reported four times:

| Function | Reported line | Failure |
|---|---:|---|
| `fn_moduleHKDDropSingle.sqf` | 27 | Standalone `exitWith {}` inside a nested `then` block |
| `fn_moduleHKDDropRadius.sqf` | 23 | Same activator-selection pattern |
| `fn_moduleHKDDropRadius_Execution.sqf` | 22 | Standalone `exitWith {}` used to abort the function |
| `fn_dialogHandler.sqf` | 72 | Standalone `exitWith {}` in the no-valid-class branch |
| `fn_serverHKDDropExecution.sqf` | 9 | `setRandomSeed _seed` is rejected by the loaded Arma runtime |

Matching source currently exists under the obsolete tree:

- [fn_moduleHKDDropSingle.sqf](FST_HKD_OBSOLETE/FST_HKD_Core/Functions/fn_moduleHKDDropSingle.sqf#L27)
- [fn_moduleHKDDropRadius.sqf](FST_HKD_OBSOLETE/FST_HKD_Core/Functions/fn_moduleHKDDropRadius.sqf#L23)
- [fn_moduleHKDDropRadius_Execution.sqf](FST_HKD_OBSOLETE/FST_HKD_Core/Functions/fn_moduleHKDDropRadius_Execution.sqf#L22)
- [fn_dialogHandler.sqf](FST_HKD_OBSOLETE/FST_HKD_Core/Functions/fn_dialogHandler.sqf#L72)
- [fn_serverHKDDropExecution.sqf](FST_HKD_OBSOLETE/FST_HKD_Core/Functions/fn_serverHKDDropExecution.sqf#L9)

There is also a latent type problem in the activator-selection code: `owner _x` returns a numeric network owner ID, but the next expression applies `isNull` and `isPlayer`, which expect objects.

### Recommended Action

- Preferred: remove the obsolete live `fst_hkd_core.pbo` if these modules are retired.
- Otherwise, migrate the core into the active HKD tree and repair all five functions before repacking.
- Express early exits as condition guards, for example `if (condition) exitWith { ... };`, rather than a standalone `exitWith {}` inside a nested `then` block.
- Select the player object directly from `_units`; do not pass the numeric result of `owner` to `isNull` or `isPlayer`.
- Replace `setRandomSeed` with a supported deterministic PRNG implementation, or remove deterministic queue reconstruction and transmit the generated queue.

## 3. Global UI Class Overrides

The report contains 180 base-class replacement/update notices across the loaded mod set. Most are normal compatibility patches, but the obsolete HKD core directly replaces global UI classes:

- `RscText`
- `RscButton`
- `RscListbox`

Source: [FST_HKD_OBSOLETE/FST_HKD_Core/HKD_Dialogs.hpp](FST_HKD_OBSOLETE/FST_HKD_Core/HKD_Dialogs.hpp#L2)

The RPT specifically records FST HKD updating `RscButton` and `RscListbox`. Global base-control replacement can affect unrelated dialogs and can conflict with ACE, JLTS, or other UI packages.

### Recommended Action

Use unique classes such as `HKD_RscText`, `HKD_RscButton`, and `HKD_RscListbox`. Inherit from existing global controls where available instead of redefining them.

## 4. Missing Textures

| Missing texture | Count | Owner |
|---|---:|---|
| `tke_ext_core_v\data\ui\shuttle_map_icon_ca.paa` | 24 | TKE |
| `tke_ext_core_v\data\ui\heli_map_icon_ca.paa` | 16 | TKE |
| `tke_ext_core_v\data\ui\apc_map_icon_ca.paa` | 8 | TKE |
| `dba_vulturedroid\fighter_icon.paa` | 4 | DBA |
| `dba_trifighter\fighter_icon.paa` | 3 | DBA |
| `a3\modules_f_curator\data\portraitmodule_ca.paa` | 2 | Referenced BI path |

The TKE paths account for 48 of the 57 missing-texture messages. These are not FST assets.

### Recommended Action

Correct the source addon paths or restore the missing PAA files in the owning packages. Validate path casing and PBO prefixes after repacking.

## 5. Sabre Model Warnings

At `22:11:36`, first-time Sabre model loading produces:

- 10 `Strange convex component` warnings in `Geometry`.
- 8 `Strange convex component` warnings in `Geometry Fire`.
- Missing convex components for `Track_L`, `Track_R`, and `Slide`.
- Four invalid `gunBeg`/`gunEnd` value warnings.
- Missing `commanderview` and `commanderview_dir` render-target memory points.

The config references dual muzzle points and commander optics here:

- [config.cpp](FST_Vehicles/FST_Vehicles_Land/FST_Vehicles_Land_APC/FST_Vehicles_Land_APC_SabreAPC/config.cpp#L1462)
- [config.cpp](FST_Vehicles/FST_Vehicles_Land/FST_Vehicles_Land_APC/FST_Vehicles_Land_APC_SabreAPC/config.cpp#L1612)

The skeleton definitions are in:

- [model.cfg](FST_Vehicles/FST_Vehicles_Land/FST_Vehicles_Land_APC/FST_Vehicles_Land_APC_SabreAPC/model.cfg)

### Likely Impact

This is the strongest Sabre-specific explanation for a one-time hitch when the vehicle is first spawned, previewed, or loaded. It does not indicate a continuing UI cost.

### Recommended Action

1. In Object Builder, make Geometry and Fire Geometry components 77-81 and 90-94 closed, convex, and valid; regenerate components after cleanup.
2. Ensure named selections `Track_L`, `Track_R`, and `Slide` resolve to valid convex components in the relevant geometry LOD.
3. Add or correct paired Memory LOD points for each configured `gunBeg` and `gunEnd` muzzle.
4. Add `commanderview` and `commanderview_dir`, or change the config to existing commander camera memory-point names.
5. Repack and verify that the warning burst disappears on the Sabre's first spawn.

## 6. Sabre Armor Extension Discovery

The RPT reports two failed lookups:

```text
CallExtension 'FST_SabreArmorExtension' could not be found
[FST Vehicle Diagnostics] Extension response rejected; using local assessment.
```

The armor UI disables extension use after the first rejected response in each script instance and continues with local assessment:

- [fn_showVehicleArmorStatus.sqf](FST_Vehicles/FST_Vehicles_Land/FST_Vehicles_Land_APC/FST_Vehicles_Land_APC_SabreAPC/Functions/fn_showVehicleArmorStatus.sqf)

This is not a sustained performance problem. It does mean the native extension was not active during this run.

### Recommended Action

- Confirm the DLL is present at the root of the exact `@FST` mod folder used in the launcher.
- Confirm the DLL architecture and Arma x64 naming convention.
- Restart Arma after replacing the DLL; an already running process will not validate a later deployment.
- Confirm the next RPT no longer contains `CallExtension ... could not be found`.

## Runtime Findings

After mission initialization, the RPT is quiet. The only entries between `22:11:46` and `22:18:59` are:

- `22:14:12 Fresnel n must be >0, given n=0,k=1.4`
- `22:16:03 ... Unknown action TurnOut ... TX-180 "Raider" APC`

There is no repeated Sabre armor UI error, extension retry loop, scheduler warning, or script-error storm during gameplay.

## Recommended Remediation Order

1. Remove or rebuild the stale live `fst_hkd_core.pbo`.
2. Repair the five HKD SQF parser failures before retaining that feature.
3. Fix or report the DBA `CfgVehicles` inheritance/config cascades.
4. Repair the Sabre Geometry, Fire Geometry, and Memory LOD warnings.
5. Correct the missing TKE and DBA UI textures in their owning addons.
6. Verify Sabre extension discovery after a complete Arma restart.
7. Capture a profiler trace or repeat a controlled first-spawn/second-spawn comparison if a hitch remains after the RPT is clean.

## Verification Checklist

A clean follow-up run should show:

- No repeated `StaticObject.StaticObject` or `FST_HKD_Blocker_Base` contexts.
- No HKD `Error in expression` or `Error Missing ;` entries.
- No Sabre `Strange convex component`, missing track component, muzzle, or commander-view warnings.
- No `FST_SabreArmorExtension could not be found` message.
- A major reduction from 12,903 warning messages and from the 22,363-line startup bursts.
- No new warning burst when spawning a second Sabre after the first model load.
