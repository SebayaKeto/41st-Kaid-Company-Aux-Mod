#include "\nsm_Main\_include\macros.hpp"
	
params["_unit","_inc"];
_unitBackpackClass=backpack _unit;
_has_jumppack=_unitBackpackClass call NSM_jumppack_fnc_is_jumppack;
if(!_has_jumppack) exitwith{};

_jumppack_data=[(configFile >> "CfgVehicles" >> _unitBackpackClass),"NSM_jumppack_jump_types",[]] call BIS_fnc_returnConfigEntry;
_num_jumps=count _jumppack_data;
_jumppack_jump_index=(unitBackpack _unit) getVariable["NSM_jumppack_selected_jump",0];

_a=_jumppack_jump_index+_inc;
_b=_num_jumps;
_new_index=(_a - (floor(_a/_b))*_b);

(unitBackpack _unit) setVariable ["NSM_jumppack_selected_jump",_new_index,true];
//[west, "HQ"] sideChat format["%1 %2 %3",_new_index,time,[_jumppack_jump_index+_inc,_num_jumps]];

//Data for hint
_new_selected_jump=(_jumppack_data select _new_index);
_jump_name=_new_selected_jump select 0;
_jump_cost=(_new_selected_jump select 1) select 2;
hint parseText format ["name: %1 <br />Cost: <t color='#00FFFF'>%2</t><br />Current Energy:<t color='#aaff00'>%3</t>",_jump_name,_jump_cost,(unitBackpack _unit) getVariable["NSM_jumppack_energy",0]];