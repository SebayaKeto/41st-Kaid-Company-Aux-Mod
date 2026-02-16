#include "\nsm_Main\_include\macros.hpp"

[{
	[ace_player] spawn NSM_jumppack_fnc_add_arsenal_handlers;
	call NSM_jumppack_fnc_add_cba_player_loadout_EH;
	call NSM_fnc_per_frame_EH;

	["NSM Jumppack Mod","Jump",["Jump","Press to Jump"],{ 
		[ace_player] spawn NSM_jumppack_fnc_decide_jump;
	},"",[DIK_Y, [false, true, false]],false] call cba_fnc_addKeybind;

	["NSM Jumppack Mod","Cycle jump type left",["Cycle jump type left","Cycle jump type left"],{
		[ace_player, -1] spawn  NSM_jumppack_fnc_set_jumptype;
	},"",[DIK_G, [false, true, false]],false] call cba_fnc_addKeybind;

	["NSM Jumppack Mod","Cycle jump type right",["Cycle jump type right","Cycle jump type right"],{
		[ace_player, 1] spawn  NSM_jumppack_fnc_set_jumptype;
	},"",[DIK_J, [false, true, false]],false] call cba_fnc_addKeybind;

	[
		"NSM_COMMON_RPT_DEBUG",
		"CHECKBOX",
		"Debug Logging (to RPT)",
		["NSM Jumppack", "Debug"],
		false,
		true
	] call CBA_fnc_addSetting;

}, [], 1] call CBA_fnc_waitAndExecute;


//https://1stmeu.namenai.gg/docs/information/Namenai%20Script%20Mod/intro
NSM_JUMPPACK_DAMAGE_MAP = createHashMapFromArray
[
	["NSM_neutral_XD_1_backpack",[50,1]], // [Percent chance to take damage, damage multiplier]
	["NSM_neutral_XD_1_LTU_backpack",[50,1]],
	["NSM_neutral_XD_1_black_backpack",[50,1]],
	["NSM_neutral_XD_1_LTU_black_backpack",[50,1]]
];
NSM_JUMPPACK_DAMAGE_DEFAULT_CHANCE = 0;
NSM_JUMPPACK_DAMAGE_DEFAULT_DAMAGE = 0;