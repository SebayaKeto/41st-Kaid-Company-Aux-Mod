#include "\nsm_Main\_include\macros.hpp"

params
[
	["_unit",player,[player]]
];
_unit_backpack_class=backpack _unit;
_effect_script_name =[(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_jump_effect_script",""] call BIS_fnc_returnConfigEntry;
_effect_position =[(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_effect_points",[]] call BIS_fnc_returnConfigEntry;

//if no script or no positions, GG
if(_effect_script_name isEqualTo '') exitWith {};
if(count _effect_position ==0) exitWith {};

[_unit,_effect_position] spawn (call compile _effect_script_name);