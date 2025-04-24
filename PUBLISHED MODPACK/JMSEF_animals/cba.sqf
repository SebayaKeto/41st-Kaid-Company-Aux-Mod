//varren_distance_max = 1500;
//varren_distance_agro = 100;
//varren_distance_hunt = 1400;

//varren_attack_damageMan = 0.5;
//varren_attack_reachMan = 5;
//varren_attack_timeout = 0.1;
//varren_attack_psychChance = 0.1;
//varren_attack_psychDuration = 15;
//varren_attack_psychTimeout = 3;

varren_sound_ambient = [
    ["dev_growl1", 5, 300, [0.5,0.8,1]],  //-- Sound, duration, distance, pitch
    ["dev_growl2", 5, 300, [0.5,0.8,1]]
];

["varren_distance_max", "SLIDER", ["Max Distance", "Max distance to search for enemies."], "Necroplague - Stalker", [0, 10000, 1500], false, {}] call CBA_fnc_addSetting;
["varren_distance_hunt", "SLIDER", ["Hunt Distance", "Max distance to hunt for enemies."], "Necroplague - Stalker", [0, 10000, 1400], false, {}] call CBA_fnc_addSetting;
["varren_distance_agro", "SLIDER", ["Agro Distance", "Max distance to agro om enemies."], "Necroplague - Stalker", [0, 10000, 100], false, {}] call CBA_fnc_addSetting;
["varren_distance_roam", "SLIDER", ["Roam Distance", "Max distance to roam when idle."], "Necroplague - Stalker", [0, 10000, 75], false, {}] call CBA_fnc_addSetting;

["varren_attack_reachMan", "SLIDER", ["Melee Reach", "How close he has to be to hit a man."], "Necroplague - Stalker", [0, 15, 5], false, {}] call CBA_fnc_addSetting;
["varren_attack_damageMan", "SLIDER", ["Melee Damage", "How much damage he does to a man on each hit."], "Necroplague - Stalker", [0, 5, 0.5], false, {}] call CBA_fnc_addSetting;
["varren_attack_reachVeh", "SLIDER", ["Vehicle Reach", "How close he has to be to hit a vehicle."], "Necroplague - Stalker", [0, 15, 8], false, {}] call CBA_fnc_addSetting;
["varren_attack_damageVeh", "SLIDER", ["Vehicle Damage", "How much damage he does to a vehicle on each hit."], "Necroplague - Stalker", [0, 5, 0.01], false, {}] call CBA_fnc_addSetting;
["varren_attack_launchVeh", "EDITBOX", ["Vehicle Launch", "Velocity to launch vehicle with."], "Necroplague - Stalker", '[0,1,1]', false, {varren_attack_launchVeh = call compile varren_attack_launchVeh}
] call CBA_fnc_addSetting;
["varren_attack_timeout", "SLIDER", ["Attack Timeout", "How often he can use attack."], "Necroplague - Stalker", [0, 10, 0.5], false, {}] call CBA_fnc_addSetting;

["varren_attack_psychChance", "SLIDER", ["Psych Chance", "Probability that he will knock out players who are alone."], "Necroplague - Stalker", [0, 1, 0.1], false, {}] call CBA_fnc_addSetting;
["varren_attack_psychDuration", "SLIDER", ["Psych Duration", "How long the player will be unconscious after psych attack."], "Necroplague - Stalker", [0, 120, 15], false, {}] call CBA_fnc_addSetting;
["varren_attack_psychTimeout", "SLIDER", ["Psych Timeout", "How often he can use psych attack."], "Necroplague - Stalker", [0, 360, 30], false, {}] call CBA_fnc_addSetting;

["varren_health", "SLIDER", ["Health Modifier", "Bigger value makes unit stronger."], "Necroplague - Stalker", [0.01, 1, 0.11], false, {}] call CBA_fnc_addSetting;