#include "\a3\editor_f\Data\Scripts\dikCodes.h"
#include "\nsm_Main\_include\macros.hpp" // my config macro lib

params["_unit","_effect_position_list"];

{ 	
	_backpackObj = unitBackpack ace_player;
	_effect_position_data=_x;
	_mem_point=_effect_position_data select 0;
	_offset=_effect_position_data select 1;

	if(_mem_point isEqualTo "spine3") then {
		_backpackObj = _unit;
	};
	

	_blueFireEffect = "#particlesource" createVehicle (getPosASL _unit);  
	_blueFireEffect setParticleClass "NSM_cloudlet_jumppack_fire_blue"; 

	_blueSparkEffect = "#particlesource" createVehicle (getPosASL _unit);  
	_blueSparkEffect setParticleClass "NSM_cloudlet_jumppack_spark";

	_smokeTrailEffect = "#particlesource" createVehicle (getPosASL _unit);  
	_smokeTrailEffect setParticleClass "NSM_cloudlet_jumppack_smoke";

	_THEBLUELIGHT = "#lightpoint" createVehicle (getPosASL _unit);  
	_THEBLUELIGHT setLightAmbient [0, 0, 0];  
	_THEBLUELIGHT setLightColor [.15, 0.45, 1];  
	_THEBLUELIGHT setLightBrightness 1;

	//_THELIGHT setLightColor [1, 0.45, 0.15];  
	//_THELIGHT setLightBrightness 1;
	_THEBLUELIGHT attachto [_backpackObj, _offset,_mem_point];
	_smokeTrailEffect attachTo [_backpackObj, _offset,_mem_point];
	_blueSparkEffect attachTo [_backpackObj, _offset,_mem_point];
	_blueFireEffect attachTo [_backpackObj, _offset,_mem_point]; //[0, -.3, -.1]	

	_attached_items=_unit getVariable ["NSM_jumppack_effects",[]];

	_attached_items pushBack _THEBLUELIGHT;
	_attached_items pushBack _smokeTrailEffect;
	_attached_items pushBack _blueSparkEffect;
	_attached_items pushBack _blueFireEffect;

	_unit setVariable ["NSM_jumppack_effects",_attached_items,true];

} forEach _effect_position_list;

sleep 1;

_unit call NSM_jumppack_fnc_remove_effects;
