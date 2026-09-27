// FST_Stonewall preInit: CBA settings (Options > Addon Options > 41st Stonewall)

[
    "FST_stonewall_trackBuilt", "CHECKBOX",
    ["Tag objects built during the mission", "Server: objects created after the mission starts are tagged 'built' so a Stonewall save can tell them from editor objects."],
    ["41st Stonewall", "Detection"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_stonewall_zenAreas", "CHECKBOX",
    ["Zen area markers are keep areas", "Every Zeus-drawn Zen area marker counts as a Stonewall keep area. Turn off if Zeus uses area markers for other things; then use the Stonewall Keep Area module or 'KEEP 80 name' markers."],
    ["41st Stonewall", "Keep areas"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_stonewall_daidalosVars", "EDITBOX",
    ["Daidalos object variables", "Comma-separated object variable names that mark an object as built with Daidalos."],
    ["41st Stonewall", "Detection"], "", 1
] call CBA_fnc_addSetting;
