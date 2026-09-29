# Lower garment repair — integration candidate

`lower_repaired.blend` is the exact audited 5 mm trouser-tuck candidate. SHA256: `4fa031b67fb3837fe29422503b4419a20e11468865f4db36ac8c495f53108acd`. The integration manifest names the four owned objects. The rear visible in this scene is superseded by the independent rear deliverable and must not be appended from this file.

Status: independently reviewed and ready for integration; root integrated/export/release checks remain pending. This is not an in-engine or universal animation guarantee.

## Final changes

- Rebuilt the two short front panels and ONE continuous broad center tabard as connected closed shells, retaining shaped hems and cloth facing. Paired outer/inner sections are 6.35 mm, compressed to 1.5 mm only in the tucked upper attachment. Each pair uses identical weights.
- Short panels release smoothly from Pelvis to their respective thigh over rest z=+0.077 to+0.022 m. The authored seam boundaries and modest clearance allowance are retained.
- Center fold uses the retained jointfit geometry and field: at most four influences per vertex from Pelvis, left/right upper-leg and upper-leg-roll bones. The rejected position warps and calf-palette experiments were NOT imported.
- Trousers retain all topology, UVs, materials and visible coverage. Their top cut is anchored smoothly to Pelvis over a 140 mm band. The final repair additionally takes up existing inner-thigh fabric slack by at most5 mm across 121 vertices, with a smooth geodesic release. Body C coordinates and all final tabard/short-panel coordinates are unchanged by this last tuck.
- Original v8, purchased armor, head/body, upper tunic, white armor and test poses remain untouched. No geometry was deleted or hidden to clear a pose.

## Structure

| Object | Vertices | Triangles | Maximum influences |
|---|---:|---:|---:|
| cloth_lower_tabard_front_left |924|1844|2|
| cloth_lower_tabard_front_right |924|1844|2|
| cloth_refine_v8_front_tabard |1508|3012|4|
| cloth_black_leg_underlayer |1213|2320|4|

Each green shell is one connected closed surface with zero nonmanifold edges. The original trouser openings and two components are retained. Weight sums differ from1 by less than4.5e-8. The saved armature has no action and identity pose bases. `lower_structure.json` records the measurements.

## Actual 140-case result

`lower_trousertuck_trial_shell140_quantized_report.json` checks the exact scene bytes now copied to `lower_repaired.blend`: rest, four fixed official poses, all14 walking,39 running and82 crouch-walking stored frames. Corrected raw official matrices are used directly, with no extra inverse bind. All tested lower weights are normalized and quantized to exact254-unit largest-remainder precision in memory. Actual saved outer/inner/edge triangles are compared against visible trousers; component-union closed proxies supply containment only. Crossed faces receive28 sixth-division barycentric samples.

The continuous center tabard has **zero exposed outer, inner or edge triangle crossings and zero positive exposed-depth samples in all140 cases**. The previous kneel and unsampled running breakthroughs are gone in the same unannotated defect-angle views. No center rest shape was altered by the final tuck.

Remaining contacts are explicitly localized in the manifest, rather than treated as a blanket zero-intersection pass:

- Center inventory attachment: only tucked/straddling upper triangles, rest z approximately+0.037 to+0.080 m; no contained samples below the+0.050 m classification boundary.
- Left short-panel upper attachment: existing fixed kneel/inventory contacts, including straddling triangles and an upper-edge contact. Integrated upper/rear preview showed coverage; root must retain this coverage in the final export.
- Left short panel in six running frames: inner thickness grazing beneath intact outer cloth; no outer/open-edge contacts in those frames.
- Right short panel: existing upper straddling attachment contacts during crouch walk; no positive exposed-depth samples.

The upper-tuck classification is a rest-coordinate localization, not proof that every such point is hidden from every camera. Root's integrated review remains required. The tabard's diagonal skeletal fold in asymmetrical kneel remains, with no claim of dynamic cloth simulation.

## Evidence

- `trousertuck_closeups/`: same kneel, inventory and running defect cameras; root visually accepted the repaired nicks.
- `trousertuck_render/`: rest and overview poses.
- `trouser_tuck_report.json`, `trouser_tuck_delta.npz`: exact small trouser displacement and source hash.
- `trouser_underbody_clearance.json`: initial contact vertices had6.8–17.9 mm of rest room above Body C, reconstructed through the exact official bind maps in memory. Independent all-pose review is complete; its precise limits are recorded below.
- `center_final_controls.npz`, the two `*_final_controls.npz`, and `trouser_waist_weights.npz`: authored fields; final trouser positions are in `trouser_tuck_delta.npz`.
- `apply_lower_repair.py`: exact-object append/relink helper.

The previous16-sample final is preserved as `lower_repaired_phase_samples_only.blend` and is rejected for dense running failures. Other trials are evidence only. In particular `lower_dual12_trial.blend` and the variable-palette weight solution are rejected, despite favorable partial solver metrics.


## Independent final review

`validation/trouser_tuck_independent_final.json` verifies that only120 trouser vertices change meaningfully versus jointfit, all74 scene meshes preserve their structure, and evaluated triangulation/weights remain exact. Maximum posed movement is5.00013 mm, maximum face-normal change17.55 degrees, and no face rotates over90 degrees. Maximum edge-length change is2.02 mm. No source anatomy was edited.

All changed rest vertices retain at least1.569 mm of Body C clearance, with no newly inside rest samples. One pre-existing rest triangle-center overlap increases from0.578 to0.828 mm. Over140 poses, the largest newly introduced overlap with the hidden full-body reference is0.967 mm at one inventory triangle-center sample; other new overlaps are at most0.368 mm. The much larger roughly16.96 mm overlaps already exist in the source reference/rig. This is explicitly not a claim of universal positive full-body-reference clearance. The independent reviewer accepted the small tuck based on actual exported outer fit, preserved anatomy and sound posed surface shape.

`validation/rear_trousertuck_review.json` checks the separately accepted rear against these exact trousers with both weight fields quantized to254 units. All135 movement frames have zero outer crossing faces and maximum exposed sampled depth is zero across140 cases. Existing fixed-pose tuck contacts remain under the separate rear owner's documented allowance. Root's final integrated export and engine review remain required.
