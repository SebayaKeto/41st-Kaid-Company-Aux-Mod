#include "\a3\editor_f\Data\Scripts\dikCodes.h"

params["_unit","_effect_position_list"];

// Collect all effects, broadcast once at the end (was broadcasting per-point)
private _attached_items = _unit getVariable ["FST_jumppack_effects",[]];

{
	_backpackObj = unitBackpack player;
	_effect_position_data=_x;
	_mem_point=_effect_position_data select 0;
	_offset=_effect_position_data select 1;

	if(_mem_point isEqualTo "spine3") then {
		_backpackObj = _unit;
	};

	_redFireEffect = "#particlesource" createVehicle (getPosASL _unit);
	_redFireEffect setParticleClass "DBA_cloudlet_jumppack_fire_red";

	_redSparkEffect = "#particlesource" createVehicle (getPosASL _unit);
	_redSparkEffect setParticleClass "DBA_cloudlet_jumppack_spark_red";

	_smokeTrailEffect = "#particlesource" createVehicle (getPosASL _unit);
	_smokeTrailEffect setParticleClass "DBA_cloudlet_jumppack_smoke";

	_THEREDLIGHT = "#lightpoint" createVehicle (getPosASL _unit);
	_THEREDLIGHT setLightAmbient [0, 0, 0];
	_THEREDLIGHT setLightColor [1, 0.45, .15];
	_THEREDLIGHT setLightBrightness 1;

	_THEREDLIGHT attachto [_backpackObj, _offset,_mem_point];
	_smokeTrailEffect attachTo [_backpackObj, _offset,_mem_point];
	_redSparkEffect attachTo [_backpackObj, _offset,_mem_point];
	_redFireEffect attachTo [_backpackObj, _offset,_mem_point];

	_attached_items pushBack _THEREDLIGHT;
	_attached_items pushBack _smokeTrailEffect;
	_attached_items pushBack _redSparkEffect;
	_attached_items pushBack _redFireEffect;

} forEach _effect_position_list;

// Single broadcast after all points processed (was inside forEach)
_unit setVariable ["FST_jumppack_effects",_attached_items,true];

sleep 1;

_unit call FST_jumppack_fnc_remove_effects;
