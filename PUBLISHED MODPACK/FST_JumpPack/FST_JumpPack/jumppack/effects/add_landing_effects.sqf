#include "\a3\editor_f\Data\Scripts\dikCodes.h"

params [
	["_unit", player, [player]]
];

_pulse_nade = "DBA_jumppack_blue_pulse_ammo" createVehicle (getPos player);
_pulse_nade setDamage 1;

_volume = 3;
_dist = 30;

// Use cached landing sound (no config lookup)
private _soundPaths = player getVariable ["FST_jumppack_cachedSoundLand", []];
if (count _soundPaths > 0) then {
	_sound_path_landing = selectRandom _soundPaths;
	playSound3D [_sound_path_landing, _unit, false, getPosASL _unit, _volume, 1, _dist];
};
