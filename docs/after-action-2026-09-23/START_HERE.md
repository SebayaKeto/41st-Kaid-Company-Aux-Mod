# September 23 after-action candidate

This package contains the Aux fixes, the separate DAARA 0.3.0 adviser package, and an Umbara mission with slightly thinner fog. It is built for rehearsal. It has not been uploaded to Workshop or applied to the running Main or Training servers.

## What to use

- `patch/Addons`: replacement Aux PBOs. HCSpawn and Combat changed; Gulanthar config is the unchanged repaired baseline. Full source is in `source`.
- `MPMissions/DaaraUmbara_030_AfterAction.m_36vwm796742s99.pbo`: DAARA candidate mission with the new fog adjustment. Use this mission for the combined candidate rehearsal.
- `Daara-0.3.0-Candidate.zip`: sealed DAARA package, including the adviser, its own instructions, and qualification results. Its older mission PBO does **not** include the later fog adjustment. The adviser defaults to port 8770 with automatic mode off; keep the ended port-8766 session separate.
- `FEEDBACK_AND_CHANGES.md`: every playtest report, the corresponding change, and remaining validation limits.
- `QUALIFICATION_SUMMARY.md`, `QUALIFICATION.json`, and `evidence`: test outcomes, failed intermediate runs, exact build identities and logs.

## Rehearsal and rollback

1. Verify `SHA256SUMS.txt` before using the files.
2. Make a separate copy of the published Aux. Back up its `FST_HCSpawn.pbo`, `FST_BURNS_Combat.pbo`, and `FST_BURNS_Gulanthar.pbo`. Replace those files in the copy with `patch/Addons`. Do not load both Aux copies together. The candidate PBOs have not been release-signed.
3. Use the same candidate Aux on the isolated server, HCs and participating players. Keep the normal dependency mods. The preassembled local test copy is `outputs/testing/server/@AfterActionNext` under this task, outside this portable package.
4. Select the new uniquely named mission on the rehearsal server. Do not change the independent Training server on game port 2328/query 2329. Main on 2302 was intentionally restarted and must remain running.
5. Rehearse the map objective picker, BX tasks, garrison reactions, player-crewed Saber engagement, AAT navigation and the modest fog change. Preacher's visibility issue needs an affected player client to establish the cause.
6. Roll back by restoring the backed-up Aux PBOs and selecting the prior mission. No live deployment is required to inspect this package.

The fog change targets a small improvement: ground density 0.65 becomes approximately 0.619, with the same altitude falloff. Exact perceived distance is not measurable on this GPU-less box. `KAID_Umbara_VisibilityGain` defaults to 1.05 and is clamped to 1.00–1.10 when the environment script runs; 1.00 restores the original density. All environment fallbacks and the weather guard use the revised ground value. Rendering-distance limits are unchanged.

## Intended behavior

B1s retain the accuracy players liked, but spend less time rearranging during contact. Held garrisons retain their positions and scan for threats. AT launchers can engage from 15m and were exercised at 25/45/75m. BX Ambush holds concealed until a known, visible infantry threat enters range, then uses ranged weapons. Creep uses prone movement; CQB closes for melee. AAT target selection, weapons and standoff tactics are preserved while turn recovery and terrain blockage handling are bounded. N99 orders survive the reproduced HC transfer race.

This is not a claim that every terrain path or the invisible-player report is resolved. See the qualification summary for the remaining cases.
