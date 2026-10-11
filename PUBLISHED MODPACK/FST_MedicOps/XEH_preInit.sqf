// FST_MedicOps preInit: CBA settings (Options > Addon Options > 41st Medic Ops)

[
    "FST_medOps_beacons", "CHECKBOX",
    ["Casualty beacons", "Downed players and players who use 'Call Medic' show up on medics' screens and maps."],
    ["41st Medic Ops", "Beacons"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_autoCall", "CHECKBOX",
    ["Downed players call automatically", "A player who goes unconscious calls a medic without doing anything."],
    ["41st Medic Ops", "Beacons"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_range", "SLIDER",
    ["Beacon range (m)", "How far away medics see casualty markers."],
    ["41st Medic Ops", "Beacons"], [50, 1500, 500, 0], 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_whoSees", "LIST",
    ["Who sees casualty markers", "Medics only keeps the HUD the medic's tool."],
    ["41st Medic Ops", "Beacons"], [[0, 1], ["Medics only", "Everyone"], 0], 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_report", "CHECKBOX",
    ["Medic report", "Track each medic's saves and show a report (Zeus module) and log it at mission end."],
    ["41st Medic Ops", "Report"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_mist", "CHECKBOX",
    ["Bacta Mist effect", "Off: Bacta Mist grenades are plain teal smoke."],
    ["41st Medic Ops", "Bacta Mist"], true, 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_bactaCharges", "SLIDER",
    ["Bacta charges per tank", "0 = unlimited (today). Above 0: each bacta heal spends a charge; Bacta Cartridges reload the tank. Medics must choose who gets bacta."],
    ["41st Medic Ops", "Consumable bacta"], [0, 20, 0, 0], 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_bactaPerCartridge", "SLIDER",
    ["Charges per Bacta Cartridge", "How many charges one cartridge restores."],
    ["41st Medic Ops", "Consumable bacta"], [1, 10, 4, 0], 1
] call CBA_fnc_addSetting;

[
    "FST_medOps_internalChance", "SLIDER",
    ["Internal bleeding chance (%)", "Chance a heavy torso hit (0.3+) on a player starts hidden internal bleeding: a slow blood loss that bacta does not fix. Found by checking vitals or with a Medscanner; a medic seals it (torso, Coagulant Foam or cauterizer). 0 = off."],
    ["41st Medic Ops", "Internal bleeding"], [0, 100, 25, 0], 1
] call CBA_fnc_addSetting;
