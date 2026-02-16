#include "\nsm_Main\_include\macros.hpp"

params["_args","_id"];

//extract data from args.
_unit=ace_player;
_frame_delay=_args select 0;
_unitBackpackClass=backpack _unit;
_time_since_last_call=_unit getVariable["NSM_jumppack_last_call_time",time];
_should_recharge = _unit getVariable ["NSM_do_energy_recharge",false];

//if ded or deleted,remove frame EH
if(!(alive _unit) || (_unit isEqualTo objNull)) exitwith{
	//[_id] call CBA_fnc_removePerFrameHandler;
};

//Incase we have to pause the timer at one point.
if(typeName _time_since_last_call isEqualTo "BOOL") then 
{
	_time_since_last_call=time;
};

//Check if this backpack is jumppack. or if we should recharge
_has_jumppack=_unitBackpackClass call NSM_jumppack_fnc_is_jumppack;
_should_recharge = _unit getVariable ["NSM_do_energy_recharge",true];
if(!_has_jumppack || !_should_recharge) exitwith{
	
};

//Get recharge value and then calculate with time difference.
_recharge_value=_unitBackpackClass call NSM_jumppack_fnc_get_recharge_rate;
if(_recharge_value<0) exitwith{
	
	
};

_energy_to_add=_recharge_value*(time-_time_since_last_call);

//Get current energy and max
_curr_energy=(unitBackpack _unit) getVariable["NSM_jumppack_energy",0];
_energy_capacity= _unitBackpackClass call NSM_jumppack_fnc_get_energy_capacity;
if(_energy_capacity<0) exitwith{
	
	
};

//Calculate total energy
_new_energy=_curr_energy+_energy_to_add;
if(_new_energy>_energy_capacity) then 
{
	_new_energy=_energy_capacity;
};

//update new energy and last rechage time
(unitBackpack _unit) setVariable["NSM_jumppack_energy",_new_energy,true];
_unit setVariable["NSM_jumppack_last_call_time",time,true];
[_curr_energy,_new_energy,_energy_capacity] spawn NSM_jumppack_fnc_show_energy_recharge;

// diag_log format ["T: %1 ID:%2 D:%3 hurt:%4",time,_unit getVariable ["NSM_jumppack_jump_id",-1],isDamageAllowed  ace_player,damage ace_player];
// ace_player sideChat format ["T: %1 ID:%2 D:%3 hurt:%4",time,_unit getVariable ["NSM_jumppack_jump_id",-1],isDamageAllowed  ace_player,damage ace_player];