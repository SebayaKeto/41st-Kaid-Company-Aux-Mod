FST_HKD Core - Settings

This README documents the mission-configurable settings for the HKD Drop System.

Settings (CBA)
- `FST_HKD -> Droppable Objects` (editbox): comma-separated list of class names that the drop modules allow. Default:
  `FST_HKD_Blocker_Blank,FST_HKD_Blocker_CIS,FST_HKD_Blocker_HKD`

- `FST_HKD -> Default Drop Object` (editbox): classname used by modules/dialog as the initially selected object. Must be one of the Droppable Objects.
  Default: `FST_HKD_Blocker_Blank`

- `FST_HKD -> Default Drop Altitude` (number): default altitude (meters) for drops. Default: `1000`

- `FST_HKD -> Default Drop Radius` (number): default radius (meters) for radius-based drops. Default: `100`

- `FST_HKD -> Default Drop Count` (number): default number of objects for radius drops. Default: `10`

How mission makers use these
1. In the Eden mission editor, open `Mission > Module Options` (requires CBA installed and enabled UI for settings).
2. Find `FST_HKD` settings and edit the values before starting the mission.

Runtime behavior
- The modules read the CBA settings at runtime and use them as defaults.
- The drop dialog populates the available object list from the `Droppable Objects` setting and pre-selects the `Default Drop Object` into the Selected list.

Notes
- If a module's attribute has been manually set in the editor (Module attributes), that attribute value takes precedence over the CBA default.
- The scripts validate that the module-chosen classname is included in the droppable list and will fall back to the CBA default if not.
- Runtime hints: when the dialog opens or a module runs, the scripts will display a hint if any configured classname is missing from the addon config or if the CBA default is invalid. This helps mission makers spot typos or missing addons.

Performance tips
- Spawn batching: the radius module already staggers thruster/init calls using `spawn` and `sleep (random 2)` to spread CPU usage across frames. Keep heavy particle/sound effects optional (`Enable_Thrusters`) to reduce spike load.
- Limit object count and radius: large counts inside small areas increase collision/physics overhead. Recommend keeping default `DefaultDropCount` to modest values for multiplayer.
- Pre-validate class lists (done): the code filters invalid classnames before spawning to avoid wasted createVehicle calls.
- If you expect many simultaneous drops, consider queuing spawns over multiple frames or using a server-side scheduler script to spread work.
