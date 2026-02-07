#include "\nsm_Main\_include\macros.hpp"

params[
["_unit",player,[player]]
];

//if no jumppack,bye
_unit_backpack=backpack _unit;
_has_jumppack=_unit_backpack call NSM_jumppack_fnc_is_jumppack;
if(!_has_jumppack) exitwith{};

_energy_capacity= _unit_backpack call NSM_jumppack_fnc_get_energy_capacity;

(unitBackpack _unit) setVariable ["NSM_jumppack_energy",_energy_capacity,true];
[_energy_capacity,_energy_capacity] call NSM_jumppack_fnc_show_current_energy;
_unit setVariable ["NSM_do_energy_recharge",true,true];