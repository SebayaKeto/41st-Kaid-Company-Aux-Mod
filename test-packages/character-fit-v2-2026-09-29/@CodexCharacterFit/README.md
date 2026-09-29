# Codex Character Fit V2 — local test build

This build tests the repaired Body C character against Arma 3 animation. The original detailed Blender source is preserved separately.

## Load the test

1. Extract this archive to a folder of your choice.
2. In the Arma 3 Launcher, open Mods, choose Local mod, and select the extracted @CodexCharacterFit folder.
3. Enable this version alone if an earlier Codex Character Fit test is present, since they use the same class names.
4. In Eden, find **Jedi Body C - Arma Fit V2**. The unit class is `CK_Fit_Jedi`; the uniform class is `CK_U_Fit_Jedi`.
5. Review standing, rifle aiming, walking, running, crouching, kneeling, prone, and equipment changes with your usual weapons.

## What this build verifies

The exported mesh uses no more than four bone weights per vertex. Armor plates remain rigid. The source garment and exported game mesh were checked against the recorded official animation sample set, and the exact packaged addon completed its local dedicated-server probe. Detailed results and qualified contacts are recorded beside the source study.

## Remaining production work

This is a fit test with simple game materials. The Blender wool and white-armor wear still need game texture baking. The head remains temporary, and collision, shadow, memory and other support LODs retain provisional BI sample scaffolding. The local server test verifies loading and animation state; it does not render the outfit or prove every weapon-specific hand alignment or every animation available in Arma.

No game installation files were changed, and this package has not been published.
