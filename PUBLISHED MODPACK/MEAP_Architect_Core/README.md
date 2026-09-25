# MEAP Daidalos

Named for Daidalos, the master builder of Greek mythology, MEAP Daidalos is a standalone restricted construction camera. It does not assign a curator module, open the Zeus interface, or register the player as Zeus, so using Daidalos mode does not ping existing Zeus operators.

## Eligibility

A player is eligible when either condition is true:

- ACE is loaded, reports the unit as an advanced engineer (`ACE_IsEngineer >= 2`), and **Allow Advanced Engineers** is enabled.
- A Zeus attaches **Assign MEAP Daidalos** to the player.

**Revoke MEAP Daidalos** removes the explicit role. Explicit assignments are stored by player UID on the server and restored after respawn. Neither module removes ACE advanced engineer eligibility. ACE is optional: without it, use the Zeus assignment module and the CBA keybind to open Daidalos. FOB deposit and funds actions are added to the standard Arma action menu when ACE is unavailable.

## Opening The Camera

Eligible players can use ACE **Self Interactions > Open Daidalos Mode** when ACE is loaded, or the dedicated CBA keybind **MEAP > Open Daidalos Mode**. The default keybind is `Ctrl+Shift+B` and can be changed independently in CBA Controls.

The **Close** button or `Escape` closes the camera. Existing construction objects remain in the mission.

While the camera is open, a green wireframe sphere shows the complete three-dimensional construction radius around the player's unit. The sphere is rendered only on that Daidalos client's machine, creates no networked helper objects, and is invisible to every other player and Zeus operator.

## Camera Controls

### Camera And Movement

| Control | Result |
| --- | --- |
| Arrow keys | Rotate the camera. |
| `W` / `S` | Move camera forward / backward. |
| `A` / `D` | Strafe camera left / right. |
| Hold `Shift` | Increase camera movement speed. |
| `Escape` or **Close** | Close Daidalos mode. |

The camera is keyboard-controlled. Client-local CBA settings under **MEAP > Daidalos Camera** adjust **Keyboard Turn Speed**, **Camera Move Speed**, and **Camera Fast Move Speed** without changing the server construction radius or validation rules.

### Construction

| Control | Result |
| --- | --- |
| **Filter** | Filter available individual objects and saved/imported builds by display name or internal ID. |
| Preset list | Select an individual object or a saved/imported build. The active row is highlighted; rows are labeled `[OBJECT]` or `[BUILD]`. The filter and list retain keyboard focus for normal navigation and text entry. |
| Left click | Commit the active edit. Otherwise, select an eligible Daidalos object under the cursor for editing, or place the selected object or build when aiming at terrain or an ineligible object. |
| **Place** or `Enter` | Create the selected object or place the selected build at the valid preview, or commit the active edit. |
| `B` | Toggle draft mode for new placements. Drafts consume normal resources and remain visible only to their builder. |
| `P` | Publish the targeted or selected draft so it is visible to every player. |
| **Edit** | Select the targeted eligible object and replace it with a local movable preview. |
| **Delete** or `Delete` | Delete the selected allowed Daidalos class under the crosshair within the Daidalos radius. |
| **Undo** or `Ctrl+Z` | Reverse the latest accepted create, edit, or delete within the configured undo window. |
| **Rotate** arrows or `R` | Rotate the preview by the current rotation increment. |
| `Shift+R` | Rotate the preview in the opposite direction. |
| `Y` | Select the class of the most recently created Daidalos object. |
| **ROT** | Cycle rotation increments: 1, 5, 15, and 45 degrees. |
| **Grid** or `G` | Cycle world-space grid increments: Off, 0.1 m, 0.5 m, 1 m, and 5 m. |
| **Align** or `T` | Toggle alignment of the preview to the placement surface. |
| **Z-** / **Z+** or `Page Down` / `Page Up` | Lower / raise the preview by the configured vertical increment. |
| `Home` | Reset vertical offset to zero. |
| `C` | Save nearby Daidalos-built objects around the targeted object as a server-session build. |
| `V` | Cycle the available saved and imported builds, clear any filter, then reveal and highlight the selected `[BUILD]` row in the preset list. |
| `Space` | Place the selected build at the valid preview position. This remains a shortcut for **Place** or `Enter` when a build is selected. |

### Snapping And Overlays

| Control | Result |
| --- | --- |
| **Snap** or `F` | Cycle snap targets: Off, Left, Right, Front, Back, Top, Bottom, and Slot when the preset supports categorized snapping. |
| `Shift+F` | Cycle snap targets in reverse. |
| **Guides** or `H` | Show or hide the local placement grid and MEAP memory-point names. |
| **Labels** or `L` | Show or hide local target names and distances. |
| **Add Zone** or `J` | Add a temporary local construction-zone sphere at a valid preview position. Maximum: eight zones. |
| **Clear Zones** or `K` | Remove all temporary local construction zones. |

The status display reports placement validity, player distance, heading, grid size, surface alignment, vertical offset, and the remaining build currency when budgets are enabled. When the selected preset costs more than the last server-confirmed balance, the preview bounding box turns red, the status reports insufficient funds, and **Place** is disabled; the server still independently validates every charge. Default precision values can be changed under **MEAP > Daidalos Camera** in CBA Addon Options.

Valid previews have a green Daidalos-only bounding box. Editable targets are outlined in blue, selected edit targets are outlined in yellow, and invalid hit positions use a red marker. The radius sphere also changes to red when the current hit is outside its boundary. These overlays are local `Draw3D` visuals and are never replicated to other clients.

## Server Settings

The settings are under **MEAP > Daidalos** in CBA Addon Options:


- **Enable Daidalos Mode** controls the complete feature.
- **Allow Advanced Engineers** enables ACE advanced engineer eligibility.
- **Allowed Construction Classes** accepts exact `CfgVehicles` class names either as a serialized array, such as `["MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort"]`, or as a comma-, semicolon-, or newline-delimited pasted list. The server normalizes both forms.
- **Include Bundled Construction Classes** merges the shipped MEAP Props/Structures and vanilla presets with a persisted custom list. Leave it enabled to ensure updated bundled classes appear after a mod update; disable it only for a strict custom-only list.
- **Daidalos Radius** is a three-dimensional boundary for the camera, placement, editing, and deletion around the player's unit. Its default is `50 m`.
- **Maximum Objects Per Daidalos User** limits active accepted objects per player UID.
- **Maximum Placement Slope** limits the steepest terrain-aligned orientation accepted by the server. Set it to `90` for unrestricted orientation.
- **Action Cooldown** is the server-enforced delay between construction mutations from one client.
- **Undo Window** and **Undo History Depth** define how long and how many accepted construction operations can be reversed by their initiating builder.

### Permissions And Audit

The settings under **MEAP > Daidalos Permissions** are server-synchronized and apply before any real object mutation:

- **Construction Access Side** restricts Daidalos sessions to Any Side, BLUFOR, OPFOR, or Independent. It does not replace the normal Daidalos eligibility requirement.
- **Owners May Maintain** lets the original Daidalos builder edit, delete, and publish their objects. Server administrators retain this access regardless of the setting.
- **Allow Unowned Object Maintenance** controls whether eligible builders may edit or delete legacy, Zeus, and mission objects that have no Daidalos ownership data. Leave it enabled to preserve the previous permissive workflow; disable it for owner-only base management.
- **Audit History Depth** retains the latest accepted create, edit, delete, and draft-publish records in the server-session audit trail. Audit data is not written to disk and is cleared when the mission/server session ends.

### Draft Construction

Draft mode is a builder-only staging workflow. Toggle it with `B` before placing an object. The server creates the real object, applies the usual whitelist, radius, object-limit, and budget checks, then hides it globally; the initiating client reveals it locally for review. Drafts remain ordinary Daidalos objects for ownership, deletion, refund, and undo purposes, so they cannot bypass resource or object limits.

Aim at a draft and press `P` to publish it. The server verifies that the object is nearby and that the player is its owner or a server administrator, clears the draft marker, and reveals it to all players. Publishing does not charge a second cost. Drafts are session-scoped and do not persist through a restart.

### Saved Builds And Imported Compositions

Daidalos can place a reusable build from either source below. Both sources use the same server-side whitelist, radius, permissions, object-limit, funding, FOB, and audit checks.

- **Saved build:** Aim at one of your Daidalos-built objects and press `C`. The server captures your nearby Daidalos objects within **MEAP > Daidalos Blueprints > Build Capture Radius** and stores their relative positions and headings as `Saved Build N`. Reopen Daidalos after saving to load the new build into the local selector. Saved builds are private to their creator, remain available only for the current mission session, and are lost when the server/mission restarts.
- **Imported composition:** Add a class under `CfgGroups >> West >> MEAP_Daidalos` in the Architect addon or a dependent addon. This `West` path is a required Daidalos registry location, not a player-side restriction; **Construction Access Side** still controls who may use Daidalos. Imported compositions are available whenever their addon is loaded and are visible to all authorized Daidalos users.

#### Imported Composition Format

Each direct child of `MEAP_Daidalos` is one selectable build. Its class name is an internal identifier, and its optional `name` is the label shown in the build selector. Each nested unit class that supplies a valid `vehicle` and `position[]` becomes one object in that build. `Unit0`, `Unit1`, and similar names are conventional only; any unique config class names work.

- `vehicle` is required and names the object class to create. It must also appear in **Allowed Construction Classes**.
- `position[]` is required and contains three local offsets in meters: `[right, forward, up]` from the build preview pivot. Daidalos rotates the horizontal offsets with the preview heading before placement.
- `azimut` is optional and is Arma's `CfgGroups` field name for an object's horizontal heading. It is a relative angle in degrees: `0` preserves the build preview heading, while `90` turns the object 90 degrees clockwise from it. If omitted, it defaults to `0`.
- A unit class may inherit from another unit class. In the example below, `Unit1: Unit0` inherits `vehicle` and `azimut`, then changes only `position[]`.

Use `V` to select a build and `Space` to place it at the current preview. The server validates every entry and the total object count and cost before creating the first object. A composition with an invalid class, an out-of-radius object, insufficient funds, an unavailable FOB, or a limit violation is rejected as a whole; it never creates a partial build. Blueprint batches publish immediately and do not use per-object draft mode.

Example imported composition:

```cpp
class CfgGroups
{
	class West
	{
		class MEAP_Daidalos
		{
			class MyBarrierPair
			{
				name = "My Barrier Pair";
				class Unit0
				{
					vehicle = "MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort";
					position[] = {-2, 0, 0};
					azimut = 0;
				};
				class Unit1: Unit0
				{
					position[] = {2, 0, 0};
				};
			};
		};
	};
};
```

All referenced `vehicle` classes must also be allowed Daidalos construction classes. The default addon includes **Duracrete Barrier Pair** as a working example. **Maximum Blueprint Objects** limits each captured or imported build; its default is `30`.

### Build Budget

The default Daidalos budget is enabled and is named **Republic Credits**. Each player receives a server-held starting balance of `100`; the preset list shows an object's cost in brackets and the camera status shows the remaining balance. Creating an object spends its configured cost and editing is free. In the default server-budget mode, deleting a Daidalos-built object refunds its original cost to its builder, and undoing a create also refunds the cost.

The settings under **MEAP > Daidalos Budget** are server-synchronized:

- **Enable Build Budget** disables all construction charging when off.
- **Currency Name** changes the visible name from Republic Credits to any mission-specific term.
- **Funding Source** chooses between the default per-player **Server Budget** and **Player Inventory**.
- **Starting Budget** sets the initial server-held balance for a player. Existing balances are retained until the server restarts.
- **Inventory Currency Classes** accepts a serialized array of item and/or magazine class names, such as `["MyMod_CreditChip"]`.
- **Inventory Currency Value** is the number of currency units represented by each configured inventory item.
- **Default Object Cost** applies to allowed classes not present in **Object Costs**.
- **Object Costs** accepts serialized `[class name, cost]` pairs that override the default.

Inventory funding consumes the required configured items or magazines after placement validation succeeds. It does not refund items for delete or undo because inventories can be full or unavailable when a refund is due.

The default costs keep small panels at `1`, pedestals at `2`, stone barriers at `3`, duracrete barriers at `5`, building floors at `6`, wall joints at `8`, concrete-base wall joints at `10`, large H-barriers at `20`, and cargo towers at `30`. For example:

```sqf
[
	["MEAP_SW_Structures_RepublicFOBBB_WallJoint_ConcreteBase", 10],
	["Land_Cargo_Tower_V1_F", 30]
]
```

### Shared FOB Pool

Set **Funding Source** to **FOB Pool** to require new Daidalos construction to be inside the radius of an active FOB heart and paid from that heart's shared balance. The custom heart object is configured with **MEAP > Daidalos FOB > FOB Heart Class**; it is intentionally blank by default until the custom object is available. Every heart is discovered server-side and receives its own shared balance.

Players can use ACE's **Deposit FOB Currency** interaction on an active heart, or the standard Arma action menu when ACE is unavailable, to deposit all carried currency items or magazines declared in **FOB Deposit Values**. This setting uses serialized `[class name, value]` pairs, for example:

```sqf
[
	["MyMod_CreditChip", 1],
	["MyMod_CreditBar", 25]
]
```

**View FOB Funds** reports the heart's current shared balance. **FOB Starting Funds**, **FOB Radius**, and **FOB Interaction Range** configure establishment and use. Placed objects paid by a pool retain their owning heart ID; deleting one refunds that same pool.

### FOB Material Processing

Once **FOB Heart Class** is configured and an active heart is discovered, it is also registered as a MEAP Economy stockpile. Use **Process FOB Materials** through ACE or the standard action menu to apply every affordable configured recipe to that heart's Economy stock. The default recipes convert `2 Stone` into `1 Supplies`, `2 Lumber` into `1 Supplies`, and `5 Credits` into `1 Supplies`.

**FOB Material Recipes** accepts serialized `[input resource, input amount, output resource, output amount]` entries. Resource names are `Credits`, `Lumber`, `Stone`, and `Supplies`. For example, the following converts stored Stone into Lumber and Supplies:

```sqf
[["Stone",3,"Lumber",1],["Stone",2,"Supplies",1]]
```

Processing is server-authoritative, requires the player to be within the configured FOB interaction range, honors the MEAP Economy enabled setting, updates stock through `MEAP_fnc_economySetStock`, and records an entry in the Daidalos audit trail.

If a heart is destroyed or removed, its Daidalos-built objects wait for **FOB Decay Delay**, then disappear one at a time at **FOB Decay Interval**. A newly established active heart inside the configured FOB radius reclaims nearby marked objects before they disappear. The decay worker only considers objects created by Daidalos and marked with a FOB heart ID; it never deletes ordinary mission, player, Zeus, or non-Daidalos objects.

Example class setting:

```sqf
["MEAP_SW_Props_Common_DuracreteBarrierOne_NoFiringPort","MEAP_SW_Structures_Desert_BP_Floor_ONE"]
```

CBA server settings can force these values and use the normal CBA settings import/export workflow. Invalid classes, hidden classes, units, vehicles, and static weapons are discarded when the server parses the list. Duplicate class names are removed. The default list includes MEAP Props/Structures plus vanilla sandbag fences, H-barriers, concrete barriers, cargo buildings, and scaffolding. If a configured list resolves empty, Daidalos falls back to that validated vanilla set. The server RPT logs both rejected and accepted classes as `[MEAP Daidalos]` entries.

## Enforcement

The server authorizes each camera session and matches every request to its network owner before eligibility is checked. The client creates only a local preview; all real placement, editing, and deletion is performed and validated by the server against the exact class list, eligibility, radius, and object limit.

Create, edit, delete, and draft-publish requests receive an explicit server result. The server throttles mutation requests and grants an exclusive edit lock before the client hides or moves an object. Another Daidalos user cannot edit or delete that object until the lock is committed, released, or its owning session closes. Ownership and legacy-object policy are evaluated server-side for lock, edit, delete, and publish operations.

Undo history is retained on the server per Daidalos user. Deleted objects are reconstructed with their original class, transform, and builder accounting; stale or unsafe inverse operations are rejected rather than applied.

Directional snap mode pairs the selected target side with the opposite `MEAP_SnapPoint_*` point on the preview. Classes can also declare `MEAP_SW_snapCategory` as `Barrier`, `Tiny`, `Small`, `Medium`, or `Large`; their model uses `MEAP_SnapPoint_Bottom` as the source anchor. Matching target points use `MEAP_SnapPoint_<Category>` or indexed names such as `MEAP_SnapPoint_Small_1`.

When a categorized source is selected, compatible slots on nearby allowed construction objects glow green. Slot mode chooses the compatible point nearest the crosshair hit, and the active point turns yellow. The local ghost shows the result, but the server independently derives the source category, validates the exact target memory selection, and reapplies the transform to the real object before accepting it.

Guides, labels, and up to eight named construction-zone spheres exist only in the active camera state and are drawn only on that Daidalos client's machine. They create no mission objects, are invisible to players and Zeus, and are discarded when the camera closes. The default zone radius is configurable under **MEAP > Daidalos Camera**.

Daidalos mode can place, edit, and delete whitelisted objects inside the configured radius around the player's unit. The camera itself is also constrained to that radius. Objects outside the radius or outside the whitelist cannot be selected or mutated.

Any public `CfgVehicles` class can be configured for Daidalos. The configured class whitelist is the server-side safety boundary: only explicitly listed classes may be created, selected, edited, deleted, captured, or restored. Vehicle, unit, weapon, and scripted classes can have gameplay side effects, so restrict the list to classes appropriate for your mission.