# HEMTT Migration Notes

This is a conservative first-pass HEMTT migration.

- Only `41st_Unconscious` and `FST_Barricades` were moved into `addons/`.
- `PUBLISHED MODPACK` is intentionally untouched.
- Uncertain prefix decisions are deferred to a later pass.
- Duplicate `CfgPatches` risks still need manual review.
- No Arma runtime paths were rewritten.
- Disabled `addons/FST_Barricades/Data/Backup.cpp` by renaming it to `Backup.cpp.disabled` because HEMTT scans/lints `.cpp` files and this backup file contains invalid config syntax.
- Migrated `FST_Common` into `addons/FST_Common` because `FST_Barricades` depends on its shared textures/materials.
