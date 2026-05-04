
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
private _v_hat = getCameraViewDirection _unit;
if (!(_use_dir)) then
{
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
	(_unit) setVelocity
	[
		((_v_hat select 0) * (_f_velo)),
		((_v_hat select 1) * (_f_velo)),
		((_v_hat select 2) * (_f_velo)) + (_v_velo / 2)
	];
};

_jump_id = _unit getVariable ["FST_jumppack_jump_id", 0];
_jump_id = _jump_id + 1;
_unit setVariable ["FST_jumppack_jump_id", _jump_id];

// Use cached sound paths
private _soundPaths = player getVariable ["FST_jumppack_cachedSoundIgnite", []];
if (count _soundPaths > 0) then {
	_volume = 3;
	_dist = 30;
	_sound_path_start = selectRandom _soundPaths;
	playSound3D [_sound_path_start, _unit, false, getPosASL _unit, _volume, 1, _dist];
};

_unit setVariable ["FST_jumppack_last_jumptime", time];

// ── In-flight damage protection ──────────────────────────────────────────────
// HandleDamage EH that blocks fall damage and halves combat damage.
//
// RACE CONDITION FIX (v2):
// The old code stored the EH ID in a shared variable. If player jumped again
// mid-air, the new jump overwrote the stored ID. When the old jump's cleanup
// ran, it read the shared variable and removed the WRONG EH — orphaning the
// old one permanently. That orphaned EH kept setting ace_medical_allowDamage
// to false on every damage event, making the player permanently invulnerable.
//
// Fix: Each jump cleans up the previous jump's EH BEFORE adding its own.
// On landing, if a newer jump has taken over (diffJumpId), we skip cleanup
// entirely — the newer jump already removed our EH and owns all state.
// The cleanup uses the LOCAL _protectEH variable, not the shared one.

// ── Clean up any existing EH from a previous jump ───────────────────────────
private _existingEH = _unit getVariable ["FST_jumppack_protectEH", -1];
if (_existingEH >= 0) then {
	_unit removeEventHandler ["HandleDamage", _existingEH];
	_unit setVariable ["FST_jumppack_protectEH", -1];
};

// Block ACE's auto-processing (our EH calls ACE manually with modified damage).
// Mark ownership first so the recharge PFH watchdog can safely restore this if cleanup ever fails.
_unit setVariable ["FST_jumppack_damageOverrideActive", true];
_unit setVariable ["ace_medical_allowDamage", false, true];

// Make sure the watchdog/recharge PFH is running for this jump. This is idempotent
// and protects against edge cases where the pack was equipped after the idle PFH stopped.
call FST_fnc_per_frame_EH;

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

	// Combat damage — reduce the incoming delta
	private _delta = _damage - _oldDamage;
	private _mult = _unit getVariable ["FST_jumppack_cachedAirDamageMult", 0.5];
	private _reducedDamage = _oldDamage + (_delta * _mult);

	// Route reduced damage through ACE Medical.
	// If the ACE call errors, allowDamage stays true — safe direction (full damage, not invulnerable).
	private _aceResult = _reducedDamage;
	_unit setVariable ["ace_medical_allowDamage", true];
	_aceResult = [_unit, _selection, _reducedDamage, _shooter, _ammo, _hitPartIndex, _instigator, _hitPoint] call ace_medical_engine_fnc_handleDamage;
	_unit setVariable ["ace_medical_allowDamage", false];

	_aceResult
}];

// Store EH ID (so the NEXT jump can clean it up if we're still mid-air)
_unit setVariable ["FST_jumppack_protectEH", _protectEH];

// Effects
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

// If unit deleted, nothing to clean up
if (_unit isEqualTo objNull) exitWith {};

// If a NEWER jump has taken over, it already removed our EH and owns all state.
// Do NOT touch ace_medical_allowDamage or protectEH — the new jump needs them.
if (_jump_id != (_unit getVariable ["FST_jumppack_jump_id", -1])) exitWith {};

// We are the active jump — do full cleanup.
// Remove our EH using the LOCAL variable (safe from overwrite by other jumps)
_unit removeEventHandler ["HandleDamage", _protectEH];
_unit setVariable ["FST_jumppack_protectEH", -1];

// Restore ACE damage processing
_unit setVariable ["FST_jumppack_damageOverrideActive", false];
_unit setVariable ["ace_medical_allowDamage", true, true];

// If dead, stop here
if (!(alive _unit)) exitWith {};

// If in water, wait until velocity low
if ((surfaceIsWater getPos _unit) && (getPosASL _unit select 2 < 0)) then
{
	waitUntil
	{
		((vectorMagnitude (velocity _unit)) < 3)
	};
};

// Landed — kill velocity to prevent engine fall-damage calc
_unit setVariable ["FST_jumppack_last_jumptime", time];
(_unit) setVelocity [0,0,0];

_unit call FST_jumppack_fnc_remove_effects;
