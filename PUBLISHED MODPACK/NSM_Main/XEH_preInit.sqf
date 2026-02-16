#include "\nsm_Main\_include\macros.hpp"
#include "\a3\editor_f\Data\Scripts\dikCodes.h"

//jumppack
[	
	"NSM_Main\functions\jumppack\test.sqf",
    "NSM_fnc_nsm_test2"
] call CBA_fnc_compileFunction;


[
	"NSM_Main\functions\jumppack\add_arsenal_handlers.sqf",
    "NSM_jumppack_fnc_add_arsenal_handlers"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\add_cba_per_frame.sqf",
    "NSM_jumppack_fnc_add_cba_per_frame"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\add_cba_player_loadout_EH.sqf",
    "NSM_jumppack_fnc_add_cba_player_loadout_EH"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\add_particle_effects.sqf",
    "NSM_jumppack_fnc_add_particle_effects"
] call CBA_fnc_compileFunction;

[
	"NSM_Main\functions\jumppack\arsenal_closed.sqf",
    "NSM_jumppack_fnc_arsenal_closed"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\arsenal_opened.sqf",
    "NSM_jumppack_fnc_arsenal_opened"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\decide_jump.sqf",
    "NSM_jumppack_fnc_decide_jump"
] call CBA_fnc_compileFunction;

[
	"NSM_Main\functions\jumppack\get_energy_capacity.sqf",
    "NSM_jumppack_fnc_get_energy_capacity"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\get_recharge_rate.sqf",
    "NSM_jumppack_fnc_get_recharge_rate"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\handle_loadout_change.sqf",
    "NSM_jumppack_fnc_handle_loadout_change"
] call CBA_fnc_compileFunction;

[
	"NSM_Main\functions\jumppack\is_jumppack.sqf",
    "NSM_jumppack_fnc_is_jumppack"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\jump.sqf",
    "NSM_jumppack_fnc_jump"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\memeify_test.sqf",
    "NSM_jumppack_fnc_memeify_test"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\remove_effects.sqf",
    "NSM_jumppack_fnc_remove_effects"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\set_jumptype.sqf",
    "NSM_jumppack_fnc_set_jumptype"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\show_current_energy.sqf",
    "NSM_jumppack_fnc_show_current_energy"
] call CBA_fnc_compileFunction;
[
	"NSM_Main\functions\jumppack\show_energy_recharge.sqf",
    "NSM_jumppack_fnc_show_energy_recharge"
] call CBA_fnc_compileFunction;
[
	"nsm_Main\functions\jumppack\handleDamage\addHandleDamage.sqf",
    "NSM_jumppack_fnc_add_handle_damage"
] call CBA_fnc_compileFunction;
[
	"nsm_Main\functions\jumppack\handleDamage\handleDamage.sqf",
    "NSM_jumppack_fnc_handle_damage"
] call CBA_fnc_compileFunction;
[
	"nsm_Main\functions\jumppack\handleDamage\custom_ace_handleDamage.sqf",
    "NSM_jumppack_fnc_ace_handle_damage"
] call CBA_fnc_compileFunction;

//effects
["NSM_Main\functions\jumppack\effects\add_landing_effects.sqf",
    "NSM_jumppack_fnc_add_landing_effects"
] call CBA_fnc_compileFunction;

["NSM_Main\functions\jumppack\effects\effect_jt_21.sqf",
    "NSM_jumppack_effect_fnc_jt_21"
] call CBA_fnc_compileFunction;
["NSM_Main\functions\jumppack\effects\effect_none.sqf",
    "NSM_jumppack_effect_fnc_none"
] call CBA_fnc_compileFunction;

// PFH
["NSM_Main\functions\per_frame_EH.sqf",
    "NSM_fnc_per_frame_EH"
] call CBA_fnc_compileFunction;

