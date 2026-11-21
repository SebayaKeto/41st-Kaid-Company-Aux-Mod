/*
    BUZZ_ZeusVision — XEH preInit
    CBA settings (Addon Options > BUZZ Zeus Vision).
*/

// Client: each Zeus can turn tags off or resize them for themselves.
[
    "BUZZ_ZeusVision_enabled", "CHECKBOX",
    ["Show trooper details", "Draw trooper detail tags in Zeus."],
    "BUZZ Zeus Vision", true, 0
] call CBA_fnc_addSetting;

[
    "BUZZ_ZeusVision_textSize", "SLIDER",
    ["Tag text size", "Size of the trooper detail text."],
    "BUZZ Zeus Vision", [0.02, 0.06, 0.035, 3], 0
] call CBA_fnc_addSetting;

[
    "BUZZ_ZeusVision_medical", "CHECKBOX",
    ["Show ACE medical", "Add wounds, heart rate, bleeding and unconscious/cardiac arrest lines to trooper tags (needs ACE medical)."],
    "BUZZ Zeus Vision", true, 0
] call CBA_fnc_addSetting;

[
    "BUZZ_ZeusVision_debug", "CHECKBOX",
    ["Debug: show my ammo counts", "Print your own [loaded, spare] counts, full amount and colour state (0 Green, 1 Yellow, 2 Red, 3 Black) to system chat whenever they change."],
    "BUZZ Zeus Vision", false, 0
] call CBA_fnc_addSetting;

// Client: zone size for the "Show troopers in zone" keybind
// (Configure > Controls > Configure Addons > BUZZ Zeus Vision).
[
    "BUZZ_ZeusVision_keyRadius", "SLIDER",
    ["Keybind zone radius (m)", "Players within this many metres of the mouse cursor get tagged when you press the 'Show troopers in zone' key in Zeus."],
    "BUZZ Zeus Vision", [10, 2500, 50, 0], 0
] call CBA_fnc_addSetting;

// Global (server-synced): every player must grade ammo the same way.
// Green = at least this % of full; Yellow = at least the yellow %;
// Red = anything above 0; Black = empty.
[
    "BUZZ_ZeusVision_greenAt", "SLIDER",
    ["Green at (% of full)", "Ammo at or above this % of the starting load shows Green."],
    "BUZZ Zeus Vision", [1, 100, 67, 0], 1
] call CBA_fnc_addSetting;

[
    "BUZZ_ZeusVision_yellowAt", "SLIDER",
    ["Yellow at (% of full)", "Ammo at or above this % (and below Green) shows Yellow. Below it but above 0 shows Red."],
    "BUZZ Zeus Vision", [1, 100, 34, 0], 1
] call CBA_fnc_addSetting;
