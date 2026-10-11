// FST_ZeusMedical preInit: CBA settings (Options > Addon Options > 41st Zeus Medical)

[
    "FST_zeusMed_enabled", "CHECKBOX",
    ["Zeus medical modules enabled", "Kill switch. Off: the 41st Medical modules refuse to act (already-applied effects stay; Plot Armor keeps running until toggled off)."],
    ["41st Zeus Medical", ""], true, 1
] call CBA_fnc_addSetting;

[
    "FST_zeusMed_spawnClass", "EDITBOX",
    ["Wounded trooper class", "Unit class created by 'Spawn Wounded Trooper'."],
    ["41st Zeus Medical", ""], "FST_Trooper_P2_DC15S", 1
] call CBA_fnc_addSetting;
