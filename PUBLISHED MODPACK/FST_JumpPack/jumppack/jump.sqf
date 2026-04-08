
params
[
	["_unit", player, [player]],
	["_f_velo", 0, [0]],
	["_v_velo", 0, [0]],
	["_dir_angle", 0, [0]],
	["_use_dir", false, [false]]
];

// Use cached jumppack check (no config lookup)
if !(player getVariable ["FST_jumppack_hasJumppack", false]) exitWith {};

// Set jump velocity
_v_hat = getCameraViewDirection _unit;
if (!(_use_dir)) then
{
	// Non-directional jump
	_v_hat = vectorDir _unit;
	_v_hat = [_v_hat, _dir_angle] call BIS_fnc_rotateVector2D;
	(_unit) setVelocity
	[
		((_v_hat select 0) * (_f_velo)),
		((_v_hat select 1) * (_f_velo)),
		(_v_velo)
	];
}
else
{
	// Directional jump
	_vertical_sign = (_v_hat select 2) / (abs (_v_hat select 2));
	(_unit) setVelocity
	[
		((_v_hat select 0) * (_f_velo)),
		((_v_hat select 1) * (_f_velo)),
		((_v_hat select 2) * (_f_velo)) + (_v_velo / 2)
	];
};

_jump_id = _unit getVariable ["FST_jumppack_jump_id", 0];
_jump_id = _jump_id + 1;
_unit setVariable ["FST_jumppack_jump_id", _jump_id, true];

// Use cached sound paths (no config lookup)
private _soundPaths = player getVariable ["FST_jumppack_cachedSoundIgnite", []];
if (count _soundPaths > 0) then {
	_volume = 3;
	_dist = 30;
	_sound_path_start = selectRandom _soundPaths;
	playSound3D [_sound_path_start, _unit, false, getPosASL _unit, _volume, 1, _dist];
};

_unit setVariable ["FST_jumppack_last_jumptime", time];
private _preFlyDamage = damage _unit;

// ── In-flight damage protection ──────────────────────────────────────────────
// Instead of full god-mode (allowDamage false), we use a HandleDamage EH that:
//   - Blocks fall damage entirely (ammo == "")
//   - Reduces combat damage by a configurable multiplier (default 50%)
//   - Properly routes reduced damage through ACE Medical's wound system
//
// How it works with ACE:
//   1. ace_medical_allowDamage is set to false → ACE's own HandleDamage EH
//      early-exits and does nothing (no wounds, returns old damage)
//   2. Our EH fires after ACE's (added later) → for combat hits, we temporarily
//      re-enable ACE, call ace_medical_engine_fnc_handleDamage with the halved
//      damage, then re-disable. ACE processes wounds at the reduced value.
//   3. Our return value is what the engine uses for structural damage.

// Block ACE's auto-processing (our EH will call it manually with modified damage)
_unit setVariable ["ace_medical_allowDamage", false, true];

// Read cached multiplier (0.5 = take 50% combat damage while airborne)
private _dmgMult = player getVariable ["FST_jumppack_cachedAirDamageMult", 0.5];

private _protectEH = _unit addEventHandler ["HandleDamage", {
	params ["_unit", "_selection", "_damage", "_shooter", "_ammo", "_hitPartIndex", "_instigator", "_hitPoint"];

	// Current damage for this hitpoint
	private _oldDamage = if (_hitPoint isEqualTo "") then {
		damage _unit
	} else {
		_unit getHitIndex _hitPartIndex
	};

	// Fall damage — block entirely
	if (_ammo isEqualTo "") exitWith { _oldDamage };

	// Combat damage — halve the incoming delta
	private _delta = _damage - _oldDamage;
	private _mult = _unit getVariable ["FST_jumppack_cachedAirDamageMult", 0.5];
	private _reducedDamage = _oldDamage + (_delta * _mult);

	// Route the reduced damage through ACE's wound system
	// (toggle allowDamage on for just this call, then back off)
	_unit setVariable ["ace_medical_allowDamage", true];
	private _aceResult = [_unit, _selection, _reducedDamage, _shooter, _ammo, _hitPartIndex, _instigator, _hitPoint] call ace_medical_engine_fnc_handleDamage;
	_unit setVariable ["ace_medical_allowDamage", false];

	_aceResult
}];

_unit setVariable ["FST_jumppack_protectEH", _protectEH];

// Use cached effect data (no config lookups, no runtime compile)
private _effectCode      = player getVariable ["FST_jumppack_cachedEffectCode", {params ["_unit","_effect_position_list"];}];
private _effectPositions = player getVariable ["FST_jumppack_cachedEffectPositions", [["spine3",[0,-0.3,-0.1]]]];

[_unit, _effectPositions] spawn _effectCode;

// Wait till landed
sleep 0.1;
waitUntil
{
	_isOnGround = (isTouchingGround (vehicle _unit));
	_isInWater = ((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0));
	_isDed = !(alive _unit);
	_diffJumpId = (_jump_id != (_unit getVariable ["FST_jumppack_jump_id", -1]));
	_isBigNull = _unit isEqualTo objNull;
	(_isOnGround || _isInWater || _isDed || _diffJumpId || _isBigNull)
};

// ── Landing / cleanup ────────────────────────────────────────────────────────

// Remove the protective EH first (all exit paths must do this)
private _ehToRemove = _unit getVariable ["FST_jumppack_protectEH", -1];
if (_ehToRemove >= 0) then {
	_unit removeEventHandler ["HandleDamage", _ehToRemove];
	_unit setVariable ["FST_jumppack_protectEH", -1];
};

// Restore ACE damage processing
_unit setVariable ["ace_medical_allowDamage", true, true];

// If unit not exists, rip.
if ((_unit isEqualTo objNull)) exitWith {};

// If dead
if (!(alive _unit)) exitWith {};

// If another jump happened, exit this script
if (_jump_id != (_unit getVariable ["FST_jumppack_jump_id", -1])) exitWith {};

// If in water, wait until velocity low
if ((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0)) then
{
	waitUntil
	{
		((vectorMagnitude (velocity _unit)) < 3)
	};
};

// Landed — kill velocity to prevent engine fall-damage calc on this frame
_unit setVariable ["FST_jumppack_last_jumptime", time, true];
(_unit) setVelocity [0,0,0];

_unit spawn FST_jumppack_fnc_remove_Effects;
