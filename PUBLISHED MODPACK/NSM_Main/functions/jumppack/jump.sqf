#include "\nsm_Main\_include\macros.hpp"

params
[
	["_unit",player,[player]],
	["_f_velo",0,[0]],
	["_v_velo",0,[0]],
	["_dir_angle",0,[0]],
	["_use_dir",false,[false]]
];

_unit_backpack_class=backpack _unit;
_has_jumppack=_unit_backpack_class call NSM_jumppack_fnc_is_jumppack;

//check if unit has jumppack
if(!_has_jumppack) exitwith{};

//set jump velo
_v_hat=getCameraViewDirection _unit;
if(!(_use_dir)) then 
{
	//non directional jump
	_v_hat=vectorDir _unit;
	_v_hat = [_v_hat, _dir_angle] call BIS_fnc_rotateVector2D;
	(_unit) setVelocity 
	[
		((_v_hat select 0) *(_f_velo)),
		((_v_hat select 1) *(_f_velo)),
		(_v_velo)
	]; 	
}
else
{
	//directional jump
	_vertical_sign=(_v_hat select 2)/(abs (_v_hat select 2));
	(_unit) setVelocity 
	[
		((_v_hat select 0) *(_f_velo)),
		((_v_hat select 1) *(_f_velo)),
		((_v_hat select 2) *(_f_velo))+(_v_velo/2)
	]; 	
};

_jump_id=_unit getVariable ["NSM_jumppack_jump_id",0];//random [0, 210000 , 420000];
//this jumps id
_jump_id=_jump_id+1;
_unit setVariable ["NSM_jumppack_jump_id",_jump_id,true];
//ace_player sideChat format ["T:%1 -- ID: %2",time,_jump_id];

_volume=3;
_dist=30;
_sound_path_start=selectRandom([(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_sound_ignite",[]] call BIS_fnc_returnConfigEntry);
playSound3D [_sound_path_start, _unit,false, getPosASL _unit,_volume,1,_dist];

// _unit allowDamage false;
_unit setVariable ["ace_medical_allowDamage", false,true];
_unit setVariable ["NSM_jumppack_isJumping", true,true];
_unit setVariable ["NSM_jumppack_last_jumptime", time,true];
_damage = damage _unit;


_effect_script_name = [(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_jump_effect_script","NSM_jumppack_effect_fnc_jt_21"] call BIS_fnc_returnConfigEntry;
_effect_positions = [(configFile >> "CfgVehicles" >> _unit_backpack_class),"NSM_jumppack_effect_points",[["spine3",[0,-0.3,-0.1]]]] call BIS_fnc_returnConfigEntry;

[_unit, _effect_positions] spawn (call (compile _effect_script_name));

//w8 till landed
sleep 0.1;
waitUntil 
{
	//used to prevent death on land
	_unit setVariable ["ace_medical_allowDamage", false,true];
	_isOnGround=(isTouchingGround (vehicle _unit));
	_isInWater=((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0));
	_isDed=!(alive _unit);
	_diffJumpId=(_jump_id !=(_unit getVariable ["NSM_jumppack_jump_id",-1]));
	_isBigNull=_unit isEqualTo objNull;
	(_isOnGround || _isInWater || _isDed || _diffJumpId || _isBigNull)//(vectorMagnitude (velocity _unit))<.1
};
//after landing or exiting wait until

//if unit not exists, rip.
if((_unit isEqualTo objNull)) exitwith
{
	//leave ,f,but remember to remove effects
};

//if ded
if(!(alive _unit)) exitwith {
	_unit setVariable ["ace_medical_allowDamage", true,true];
	// _unit allowDamage true;
	_unit setVariable ["NSM_jumppack_isJumping", false,true];
};

//if another jump happened, exist this script
if(_jump_id !=(_unit getVariable ["NSM_jumppack_jump_id",-1])) exitwith{
};

//if in water,w8 untill velocity low then 3m/s (handles 2 and 3rd condition of waituntill)
if((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0) ) then 
{
	waitUntil
	{
		(( vectorMagnitude  (velocity  _unit)) < 3)
	};
};

//from here out it means we in land
_unit setVariable ["NSM_jumppack_last_jumptime", time,true];
_unit setDamage _damage;



(_unit) setVelocity [0,0,0];
sleep 1;

// _unit allowDamage true;
_unit setVariable ["ace_medical_allowDamage", true,true];
_unit setVariable ["NSM_jumppack_isJumping", false,true];
_unit spawn NSM_jumppack_fnc_remove_effects;
