#include "\a3\editor_f\Data\Scripts\dikCodes.h"
// Keybinds — REWRITE: call instead of spawn for decide_jump and set_jumptype
// Neither function uses sleep/waitUntil (decide_jump spawns jump.sqf internally).
// Saves 3 scheduled thread creations per keypress.

["41st Elite Corps","Jump",["Jump","Press to Jump"],{
	[player] call FST_jumppack_fnc_decide_jump;
},"",[DIK_Y, [false, true, false]],false] call cba_fnc_addKeybind;

["41st Elite Corps","Cycle jump type left",["Cycle jump type left","Cycle jump type left"],{
	[player, -1] call FST_jumppack_fnc_set_jumptype;
},"",[DIK_G, [false, true, false]],false] call cba_fnc_addKeybind;

["41st Elite Corps","Cycle jump type right",["Cycle jump type right","Cycle jump type right"],{
	[player, 1] call FST_jumppack_fnc_set_jumptype;
},"",[DIK_J, [false, true, false]],false] call cba_fnc_addKeybind;
