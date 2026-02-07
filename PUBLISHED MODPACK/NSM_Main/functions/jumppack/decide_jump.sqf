#include "\nsm_Main\_include\macros.hpp"

params["_unit"];
_unitBackpackClass=backpack _unit;
_has_jumppack=_unitBackpackClass call NSM_jumppack_fnc_is_jumppack;

//if no jumppack,no jump
if(!_has_jumppack) exitwith
{
	
	[
		format["<t color='#FF0000'>You dont have a jumppack.</t>"],
		format["<t color='#FF0000'>ArE YoU StUpId MaTey YoU DoNTY HaBE a JumPPacK OwO???.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

//if captive no jump
if( (_unit getVariable ["ace_captives_ishandcuffed",false])) exitwith
{
	[
		format["<t color='#FF0000'>Cant jump while captured.</t>"],
		format["<t color='#FF0000'>Bitch, where u tryna go.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

//if underwater or on water,no jump.
if((eyePos _unit select 2 < 0) ||(underwater _unit) || ((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0))) exitWIth 
{
	[
		format["<t color='#FF0000'>No water jumping.</t>"],
		format["<t color='#FF0000'>Water is too warm :) OwO.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

//If in vehicle,no jump
if (!(isNull objectParent _unit))exitWith 
{	
	[
		format["<t color='#FF0000'>No jumping in vehicle,</t>"],
		format["<t color='#FF0000'>Seatbelt on.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

//if spamming,no jump. This is to prevent the issue of where u jump as soon as u land adn then die.
_last_jumptime=_unit getVariable ["NSM_jumppack_last_jumptime",0];
// if(((time-_last_jumptime)<.5)) exitWith 
// {
// 	[format["<t color='#FF0000'>No Spam Jumping</t>"], ""] call ace_common_fnc_displayTextPicture;
// };
_jumppack_data=[(configFile >> "CfgVehicles" >> _unitBackpackClass),"NSM_jumppack_jump_types",[]] call BIS_fnc_returnConfigEntry;

//If no jumppack data,no jump
if((count _jumppack_data) ==0) exitWith 
{
	[format["<t color='#FF0000'>Script Hab Stroke # Type 1 :(</t>"], ""] call ace_common_fnc_displayTextPicture;
};

//If not enough energy,no jump
_jumppack_jump_index=(unitBackpack _unit) getVariable["NSM_jumppack_selected_jump",0];
_current_energy=(unitBackpack _unit) getVariable["NSM_jumppack_energy",0];
_selected_jump=_jumppack_data select _jumppack_jump_index;
_cost=(_selected_jump select 1) select 2;
if(_cost>_current_energy ) exitwith 
{
	[
		format["<t color='#FF0000'>Not Enough Energy</t>"],
		format["<t color='#FF0000'>Not Enough V-Bucks.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

_jump_movement_data=_selected_jump select 1;
//get the forward velo,verticle velo and angle of jump
_velo_data=[_jump_movement_data select 0,_jump_movement_data select 1,_jump_movement_data select 3];
_prone_flag=_jump_movement_data select 5;
_directonal_flag=_jump_movement_data select 4;

//If cant prone jump,no jump EDIT: has to be disabled cause phase through floor exploit F
_can_prone_jump=(_prone_flag==1);
_can_directional_jump=(_directonal_flag==1);
if ((stance _unit == "PRONE") && !_can_prone_jump) exitWith 
{
	[
		format["<t color='#FF0000'>No prone jump selected.</t>"],
		format["<t color='#FF0000'>No Grasshopper mode.</t>"],
		.2
	]call NSM_jumppack_fnc_memeify_test;
};

_new_consumed_energy=_current_energy-_cost;
(unitBackpack _unit) setVariable ["NSM_jumppack_energy",_new_consumed_energy,true];

//get energy cap and new consumed energy
_energy_capacity= _unitBackpackClass call NSM_jumppack_fnc_get_energy_capacity;
[_new_consumed_energy,_energy_capacity]  call NSM_jumppack_fnc_show_current_energy;


[_current_energy,_new_consumed_energy,_energy_capacity] spawn NSM_jumppack_fnc_show_energy_recharge;

[ace_player,
_velo_data select 0,//f velo
_velo_data select 1,//v velo
_velo_data select 2,//angle
_can_directional_jump
] 
spawn NSM_jumppack_fnc_jump