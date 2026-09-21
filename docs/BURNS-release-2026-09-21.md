# BURNS V30.1 release

Original BURNS behavior is integrated in FST_HCSpawn, with native weapon and turret profiles in FST_BURNS_Combat. Remove LAMBS Danger, Waypoints, RPG, Turrets, Suppression and LAMBS compatibility addons from server, HC and player presets. There is no LAMBS source or dependency in BURNS.

Use four named mission slots HC1–HC4. HC4 handles vehicle spawns; the remaining HCs handle infantry. The release defaults use a 400-unit per-HC soft cap and 1,100 managed-AI cap. Local clients must be listed in the server's localClient configuration.

B1s use upright posture and line formation. B2/BX behavior remains with the active WebKnight Workshop addon. Do not load the retired copies from PUBLISHED MODPACK. Human opponents retain cover and combat behavior. BURNS spatial work is bounded, cached and owned by the group's current machine; Zeus requests include ownership acknowledgements and bounded retries.

Validation before release included four-HC ownership and role tests, a 1,000-AI load fixture, and a separate network test at 500 ms latency, jitter and packet loss. These synthetic tests do not certify an operation with 150 human clients. Automatic artillery, automatic static-weapon manning and complete parity with every LAMBS defend option remain outside this release.

Retain Umbara Variant A for the debut. Removing another 30% of vegetation produced a modest client rendering improvement in the local test but no consistent server gain. The full Variant A preserves more props and its existing vehicle-collision fix. The debut mission also keeps its visual-effect loop off headless clients.

The accompanying September 20 Maldova PBOs provide Sabre model/material, seat and missile-audio updates. The incoming Evox BARC textures now both have selectable helmet classes. Package the existing x64 armour extension as FST_SabreArmorExtension_x64.dll at the mod root. Maldova's reported LAAT airlift-placement issue is not claimed fixed; ground-spawn the vehicle pending a separate flight test.

Generated PBO copies are release outputs, not source changes to commit wholesale. Retain backups of the prior PBOs and mission before deployment.
