#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#include "\nsm_Main\_include\macros.hpp"

params[
["_unit",player,[player]]
];

_pulse_nade= "NSM_jumppack_blue_pulse_ammo" createVehicle (getPos ace_player);//namenai_test_pulse_smok
_pulse_nade setDamage 1;

_volume=3;
_dist=30;
_unit_backpack_class=backpack _unit;
_sound_path_landing=selectRandom([(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_sound_land",[]] call BIS_fnc_returnConfigEntry);
playSound3D [_sound_path_landing, _unit,false, getPosASL _unit,_volume,1,_dist];


