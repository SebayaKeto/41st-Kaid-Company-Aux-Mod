// handle_loadout_change.sqf
// Called by CBA "loadout" player event handler when player's loadout changes.
// Caches all jumppack config values on the player so per-tick recharge and
// jump logic never need to walk the config tree at runtime.
// Also starts/stops the recharge PFH so players without a jump pack have no
// persistent 0.25s timer running.

private _savedBackpack = player getVariable ["FST_jumppack_backpack_class", ""];
private _currentBackpack = backpack player;

// If backpack class unchanged, there is normally nothing to do. Still make sure
// the PFH exists if this player is known to have a jump pack; this is cheap and
// protects against respawn/arsenal edge cases without adding a permanent loop.
if (_savedBackpack isEqualTo _currentBackpack) exitWith {
	if (player getVariable ["FST_jumppack_hasJumppack", false]) then {
		call FST_fnc_per_frame_EH;
	};
};

// Store new backpack class
player setVariable ["FST_jumppack_backpack_class", _currentBackpack];

// Cache: is this a jumppack?
private _isJumppack = _currentBackpack call FST_jumppack_fnc_is_jumppack;
player setVariable ["FST_jumppack_hasJumppack", _isJumppack];

if (!_isJumppack) exitWith {
	// Clear cached values so stale data doesn't linger
	player setVariable ["FST_jumppack_cachedCapacity", -1];
	player setVariable ["FST_jumppack_cachedRecharge", -1];
	player setVariable ["FST_jumppack_cachedJumpTypes", []];
	player setVariable ["FST_jumppack_cachedEffectScript", ""];
	player setVariable ["FST_jumppack_cachedEffectCode", {params ["_unit","_effect_position_list"];}];
	player setVariable ["FST_jumppack_cachedEffectPositions", []];
	player setVariable ["FST_jumppack_cachedSoundIgnite", []];
	player setVariable ["FST_jumppack_cachedSoundLand", []];
	player setVariable ["FST_jumppack_cachedAirDamageMult", 0.5];

	// If the player removed/dropped the pack while airborne, keep the PFH alive
	// until the damage watchdog restores ACE damage. Otherwise stop it entirely.
	if !(player getVariable ["FST_jumppack_damageOverrideActive", false]) then {
		call FST_fnc_per_frame_EH_stop;
	};
};

// Cache all config values (these never change at runtime for a given backpack class)
private _capacity  = _currentBackpack call FST_jumppack_fnc_get_energy_capacity;
private _recharge  = _currentBackpack call FST_jumppack_fnc_get_recharge_rate;
private _jumpTypes = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_jump_types", []] call BIS_fnc_returnConfigEntry;
private _effectScript    = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_jump_effect_script", "FST_jumppack_effect_fnc_jt_21"] call BIS_fnc_returnConfigEntry;
private _effectPositions = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_effect_points", [["spine3",[0,-0.3,-0.1]]]] call BIS_fnc_returnConfigEntry;
private _soundIgnite     = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_sound_ignite", []] call BIS_fnc_returnConfigEntry;
private _soundLand       = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_sound_land", []] call BIS_fnc_returnConfigEntry;
private _airDamageMult   = [(configFile >> "CfgVehicles" >> _currentBackpack), "FST_jumppack_air_damage_mult", 0.5] call BIS_fnc_returnConfigEntry;

player setVariable ["FST_jumppack_cachedCapacity", _capacity];
player setVariable ["FST_jumppack_cachedRecharge", _recharge];
player setVariable ["FST_jumppack_cachedJumpTypes", _jumpTypes];
player setVariable ["FST_jumppack_cachedEffectScript", _effectScript];
// Pre-compile effect script once (avoids call compile on every jump)
private _effectCode = if (_effectScript isEqualTo "") then {
	{params ["_unit","_effect_position_list"];}
} else {
	call compile _effectScript
};
player setVariable ["FST_jumppack_cachedEffectCode", _effectCode];
player setVariable ["FST_jumppack_cachedEffectPositions", _effectPositions];
player setVariable ["FST_jumppack_cachedSoundIgnite", _soundIgnite];
player setVariable ["FST_jumppack_cachedSoundLand", _soundLand];
player setVariable ["FST_jumppack_cachedAirDamageMult", _airDamageMult];

// Reset recharge timer (original behavior preserved)
player setVariable ["FST_jumppack_last_call_time", time];

// Demand-start recharge/watchdog only for actual jump-pack users.
call FST_fnc_per_frame_EH;
