# Maldova's Daidalos engineering tool

Daidalos is included in the Aux through six MEAP addons. It gives eligible players a restricted construction camera with local previews, grid placement, editing, deletion, undo, drafts and reusable builds. Maldova is the original author. The imported archive SHA-256 is `282ec78520acecaa34d6a0926c218c8a5401bfcdffc72309afa8160828206a41`.

**Use grid placement in this release.** All 11 custom palette entries in the supplied archive lack a Memory LOD and snap anchors. The tool's snapping feature therefore needs updated models from Maldova; it is not working or qualified with these assets. Unsupported snapping is rejected without moving the object. Do not enable a snap mode when building with these models.

## Give an engineer access

- An **ACE advanced engineer (level 2)** is eligible by default. Ordinary engineer level 1 alone is insufficient.
- Alternatively, Zeus places **MEAP → Assign MEAP Daidalos** on a player. Use **Revoke MEAP Daidalos** to remove that explicit grant. Grants follow the player's UID through respawn during the mission. Revoking a grant does not remove eligibility from the separate advanced-engineer setting.
- Open **ACE Self Interactions → Open Daidalos Mode**, or press **Ctrl+Shift+B**. The binding is configurable under **CBA Controls → MEAP**. This does not make the player a Zeus or open the Zeus interface.

## Build

Choose a preset in the palette and aim at a valid position. Press **Enter / Place** to place it. Left-click selects an editable object or places the active preview. Use **WASD** to move the camera, arrows to turn, and Shift for faster movement. **Escape / Close** exits.

| Key | Action |
|---|---|
| R / Shift+R | Rotate forward / backward |
| G | Cycle grid spacing |
| F / Shift+F | Cycle snapping options; leave off with the supplied models |
| T | Toggle surface alignment |
| Page Up / Page Down; Home | Raise / lower; reset vertical offset |
| Delete | Delete the eligible targeted construction |
| Ctrl+Z | Undo the last accepted action |
| B; P | Toggle private draft placement; publish the targeted draft |
| C | Capture nearby owned construction as a saved build |
| V | Cycle available saved/imported builds |
| Space | Place the selected build |

These shortcuts follow the shipped handler, correcting the original README's older M/C/V blueprint mapping. The filter now accepts WASD and arrow keys as ordinary text-entry/navigation keys while it has focus.

## Mission settings

Use **CBA Addon Options → MEAP → Daidalos**. Original defaults are preserved: enabled, advanced-engineer access, **50 m** construction radius, **100 objects** per builder, **100 Republic Credits** starting budget, **120-second** undo window and the bundled construction palette. The budget can be disabled or adjusted for a mission. These credits are the tool's server-held balance by default, not the Aux's physical credit items.

The bundled palette has 21 entries, including custom stone/duracrete barriers, floor and pillar pieces, Republic FOB wall joints, and vanilla fortifications. Additional exact prop class names can be configured in Allowed Construction Classes.

The author's **Allow Unowned Object Maintenance** default is enabled: eligible users may edit/delete whitelisted mission or Zeus objects within their radius. Disable it in **Daidalos Permissions** for builder-owned construction only. Other builders' owned objects remain protected. Side access, object limits, budget and placement slope are also configurable.

Saved builds, grants, budgets and draft objects are mission-session data; this integration does not add restart persistence. Shared FOB funding is optional and requires the mission maker to configure a FOB heart class. Ordinary construction works without that setup.

## Installation and limits

Load the updated Aux on **server, HCs and every player**, then start a new mission/server session. No additional standalone `@MEAP` is needed. Only Core, Economy, SW Core, SW Props, SW Structures and Architect are included; the archive's unrelated AI, ammo overrides, droids, effects and TRELLIS addons are excluded.

The accompanying installer verifies checksums and refuses to change an Aux copy used by a running local Arma process. It does not edit FASTER, start/stop servers or alter Training. Restart and client distribution must be coordinated after the package is installed.

The dedicated-server fixture verifies addon startup and real rejection of headless-client open/forged-close requests. Because Arma reports a headless sender as zero, construction logic is also exercised through test-only copies with the graphical-player sender value simulated; production open/action authentication checks are unchanged. It cannot verify camera rendering, mouse interactions, client visual assets or ACE menu appearance on this GPU-less server; a graphical client still needs a brief in-game acceptance check.

## Maintainer notes

Four dependency/asset PBOs are unchanged from Maldova's archive. Core and Architect source are retained beside their built PBOs. Changes fix snap-point queries to explicitly use the model's Memory LOD, correct filter keyboard focus, require the active session token for server-initiated cleanup (including revocation, death and disconnect), and correct control documentation. The close check prevents a caller from closing another builder's session merely by sending a true server-initiated flag. Original names, function prefixes and asset paths are preserved.

Snap-point lookup follows [Bohemia's selectionNames documentation](https://community.bistudio.com/wiki/selectionNames): the original unary query reads the first visual LOD, whereas the author's documented snap anchors belong in Memory. The supplied models do not yet contain them. Undo covers individual object creation, editing and deletion; placing a multi-object saved build does not create a grouped undo action.

## Five-minute graphical acceptance check

On the updated server and matching player Aux, assign Daidalos to an engineer. Open it, type a word containing WASD into the filter, place two barriers using the grid, move one, undo, and delete it. Have another player confirm the objects are visible. Place a draft and confirm only its builder sees the preview, then publish it. Capture a small build with C, reopen, select with V and place with Space. Close the camera and confirm normal movement returns. Finally revoke an explicitly granted, non-advanced-engineer player and confirm the camera closes. This is the remaining client-side check before an operation.
