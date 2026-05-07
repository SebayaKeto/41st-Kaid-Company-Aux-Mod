// Mission-level hard disable. Set this false in CBA Addon Options for ops
// where jump packs are not being used. It prevents client runtime hooks from
// being registered in postInit while leaving backpack classes available.
[
	"FST_jumppack_enabled",
	"CHECKBOX",
	["Enable FST JumpPack", "Disable for ops with no jump packs. Requires mission restart. Stops runtime keybind/loadout/arsenal/PFH bootstrap."],
	["41st Elite Corps", "JumpPack"],
	true,
	1,
	{},
	true
] call CBA_fnc_addSetting;


//jumppack
	["FST_JumpPack\jumppack\add_arsenal_handlers.sqf","FST_jumppack_fnc_add_arsenal_handlers"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\add_cba_per_frame.sqf","FST_jumppack_fnc_add_cba_per_frame"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\add_cba_player_loadout_EH.sqf","FST_jumppack_fnc_add_cba_player_loadout_EH"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\add_particle_effects.sqf","FST_jumppack_fnc_add_particle_effects"] call CBA_fnc_compileFunction;

	["FST_JumpPack\jumppack\arsenal_closed.sqf","FST_jumppack_fnc_arsenal_closed"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\arsenal_opened.sqf","FST_jumppack_fnc_arsenal_opened"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\decide_jump.sqf","FST_jumppack_fnc_decide_jump"] call CBA_fnc_compileFunction;

	["FST_JumpPack\jumppack\get_energy_capacity.sqf","FST_jumppack_fnc_get_energy_capacity"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\get_recharge_rate.sqf","FST_jumppack_fnc_get_recharge_rate"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\handle_loadout_change.sqf","FST_jumppack_fnc_handle_loadout_change"] call CBA_fnc_compileFunction;

	["FST_JumpPack\jumppack\init.sqf","FST_jumppack_fnc_init"] call CBA_fnc_compileFunction;

	["FST_JumpPack\jumppack\is_jumppack.sqf","FST_jumppack_fnc_is_jumppack"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\jump.sqf","FST_jumppack_fnc_jump"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\keybinds.sqf","FST_jumppack_fnc_keybinds"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\memeify_test.sqf","FST_jumppack_fnc_memeify_test"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\remove_effects.sqf","FST_jumppack_fnc_remove_effects"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\set_jumptype.sqf","FST_jumppack_fnc_set_jumptype"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\show_current_energy.sqf","FST_jumppack_fnc_show_current_energy"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\show_energy_recharge.sqf","FST_jumppack_fnc_show_energy_recharge"] call CBA_fnc_compileFunction;

	//effects
	["FST_JumpPack\jumppack\effects\add_landing_effects.sqf","FST_jumppack_fnc_add_landing_effects"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\effects\effect_jt_21.sqf","FST_jumppack_effect_fnc_jt_21"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\effects\effect_pathfinder.sqf","FST_jumppack_effect_fnc_pathfinder"] call CBA_fnc_compileFunction;
	["FST_JumpPack\jumppack\effects\effect_none.sqf","FST_jumppack_effect_fnc_none"] call CBA_fnc_compileFunction;

//per frame eh
["FST_JumpPack\per_frame_EH.sqf","FST_fnc_per_frame_EH"] call CBA_fnc_compileFunction;
["FST_JumpPack\per_frame_EH_stop.sqf","FST_fnc_per_frame_EH_stop"] call CBA_fnc_compileFunction;
