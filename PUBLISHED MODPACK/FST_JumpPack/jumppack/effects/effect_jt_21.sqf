#include "\a3\editor_f\Data\Scripts\dikCodes.h"

params ["_unit", "_effect_position_list"];

if (isNull _unit) exitWith {};

// Track only the effects created by this jump. Older versions called
// remove_effects after sleep, which could delete effects from a newer mid-air
// jump. This keeps repeated 15-second / aircraft-exit jumps safer and cheaper.
private _createdItems = [];
private _allItems = _unit getVariable ["FST_jumppack_effects", []];

{
	private _backpackObj = unitBackpack _unit;
	private _effectPositionData = _x;
	private _memPoint = _effectPositionData select 0;
	private _offset = _effectPositionData select 1;

	if (_memPoint isEqualTo "spine3") then {
		_backpackObj = _unit;
	};

	private _fireEffect = "#particlesource" createVehicle (getPosASL _unit);
	_fireEffect setParticleClass "DBA_cloudlet_jumppack_fire_blue";

	private _sparkEffect = "#particlesource" createVehicle (getPosASL _unit);
	_sparkEffect setParticleClass "DBA_cloudlet_jumppack_spark";

	private _smokeTrailEffect = "#particlesource" createVehicle (getPosASL _unit);
	_smokeTrailEffect setParticleClass "DBA_cloudlet_jumppack_smoke";

	private _light = "#lightpoint" createVehicle (getPosASL _unit);
	_light setLightAmbient [0, 0, 0];
	_light setLightColor [.15, 0.45, 1];
	_light setLightBrightness 1;

	_light attachTo [_backpackObj, _offset, _memPoint];
	_smokeTrailEffect attachTo [_backpackObj, _offset, _memPoint];
	_sparkEffect attachTo [_backpackObj, _offset, _memPoint];
	_fireEffect attachTo [_backpackObj, _offset, _memPoint];

	_createdItems append [_light, _smokeTrailEffect, _sparkEffect, _fireEffect];
} forEach _effect_position_list;

if ((count _createdItems) == 0) exitWith {};

_allItems append _createdItems;
_unit setVariable ["FST_jumppack_effects", _allItems];

sleep 1;

{
	if (!isNull _x) then {
		detach _x;
		deleteVehicle _x;
	};
} forEach _createdItems;

if (!isNull _unit) then {
	private _remaining = (_unit getVariable ["FST_jumppack_effects", []]) - _createdItems;
	_unit setVariable ["FST_jumppack_effects", _remaining];
};
