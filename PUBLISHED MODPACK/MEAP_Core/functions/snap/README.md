# MEAP object snapping

The ACE interaction system can snap one `House_F` object to another by pairing named points in each model's Memory LOD.

Supported memory-selection names:

- `MEAP_SnapPoint_Left`
- `MEAP_SnapPoint_Right`
- `MEAP_SnapPoint_Front`
- `MEAP_SnapPoint_Back`
- `MEAP_SnapPoint_Top`
- `MEAP_SnapPoint_Bottom`

Each selection should contain one memory vertex. A point may be positioned at model origin; point existence is determined by selection name rather than position.

## Categorized Daidalos slots

A construction source can opt into a categorized slot size in `CfgVehicles`:

```cpp
MEAP_SW_snapCategory = "Small";
```

Accepted values are case-sensitive: `Barrier`, `Tiny`, `Small`, `Medium`, and `Large`. The source model must also contain `MEAP_SnapPoint_Bottom`, which is used as its placement anchor.

Target models expose compatible slots with the category in the memory-selection name:

- `MEAP_SnapPoint_Barrier`
- `MEAP_SnapPoint_Tiny`
- `MEAP_SnapPoint_Small`
- `MEAP_SnapPoint_Medium`
- `MEAP_SnapPoint_Large`

A target can provide multiple slots in one category by adding an underscore suffix, for example `MEAP_SnapPoint_Small_1`, `MEAP_SnapPoint_Small_2`, and `MEAP_SnapPoint_Small_Roof`. Every selection must contain one memory vertex.

When a categorized source is selected in Daidalos, all compatible slots on nearby allowed construction objects are highlighted. `Snap Slot` uses the compatible point nearest the crosshair hit. The server reads the source category from `CfgVehicles`, validates the exact target selection, and reapplies the transform independently.

The matching Eden subcategories are:

- `MEAP_SW_Subcategory_BuildingPieces_Barriers`
- `MEAP_SW_Subcategory_BuildingPieces_Tiny`
- `MEAP_SW_Subcategory_BuildingPieces_Small`
- `MEAP_SW_Subcategory_BuildingPieces_Medium`
- `MEAP_SW_Subcategory_BuildingPieces_Large`

## Interaction flow

1. ACE interact with an object and choose **Set Snap Source**.
2. ACE interact with a different target object.
3. Choose **Snap Source To Left**, **Right**, **Front**, **Back**, **Top**, or **Bottom**.
4. Use **Clear Snap Source** when the selection is no longer needed.

Only sides for which both required memory selections exist are shown. Target Left pairs with source Right, target Front pairs with source Back, and target Top pairs with source Bottom.

The source inherits the target's heading, then moves until the paired points coincide. Pitch and bank are intentionally preserved rather than copied. The source must be local to the machine performing the snap; editor-placed server-local objects therefore cannot currently be moved by a multiplayer client.