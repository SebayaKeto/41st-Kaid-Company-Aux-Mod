# September 23 combined test package

Contains the six small built addon PBOs, staged Daara mission, whole-mod manifest and checksum verifier. Source for the complete changes is in PUBLISHED MODPACK. Includes remote main e309bee5 (AT-RT light/attachments, ship repair and recall, Umbara trees) plus the B1/AAT candidate, Armor pod source and verified Gulanthar repair.

The 2.22 GB Armor PBO is not duplicated in Git. Use the supplied 41st_Armor.pbo with SHA-256 346433572966480ffaacab156bb379f907940586eaf8b17427b7a50cb9bbd737; its two changed scripts are included in PUBLISHED MODPACK/41st_Armor/Data. The complete local candidate and Workshop upload include that exact PBO. Overlay these six PBOs and that Armor PBO on the existing full Aux Mod; do not load this partial folder as a standalone mod.

Use final-candidate-manifest.json and Verify-Candidate.ps1 -ModPath <full-mod-folder> to verify the resulting complete copy. Preserve the existing mod for rollback. Use the same build on server, four HCs and clients. The staged Daara mission disables the conflicting Zeus waypoint override.

This is a test release, not live-operation clearance. B1 exercised server checks passed; Gulanthar repair passed 37 checks; pod delivery had some troop losses. AAT facing and occasional firing remain inconsistent, and no speculative steering change was promoted. The newly pulled updates passed config syntax checks and source-to-PBO readback; see combined-smoke-test.json for the final runtime smoke result. Visual AT-RT lighting, Umbara rendering and player/Zeus/ACE behavior still need the client test.
