// add_cba_per_frame.sqf
// Energy recharge tick. Runs every 0.25s via CBA timer only while needed.
// Demand-start/stop rules:
//   - active while the player has a jump pack, or
//   - active while a jump-created damage override needs watchdog cleanup.
// If neither is true, it removes its own PFH so non-jump-pack players carry no
// persistent recharge/watchdog timer during an op.

params ["_args", "_id"];

private _unit = player;
if (_unit isEqualTo objNull) exitWith {};

// Damage safety watchdog — deliberately lives in the existing 0.25s PFH so we
// do not add another loop/callback per jump. This only touches the damage state
// if this addon marked itself as owning the temporary ACE override.
if (_unit getVariable ["FST_jumppack_damageOverrideActive", false]) then {
	private _protectEH = _unit getVariable ["FST_jumppack_protectEH", -1];
	private _shouldRestore = false;

	if (_protectEH < 0) then {
		// No EH exists anymore, so there is no valid reason for our ACE override to remain.
		_shouldRestore = true;
	} else {
		private _isOnGround = isTouchingGround (vehicle _unit);
		private _isInWater = ((surfaceIsWater getPos _unit) && {(getPosASL _unit select 2) < 0});
		private _isInVehicle = !(isNull objectParent _unit);
		private _isDead = !(alive _unit);

		// Do NOT use a time limit here. Players may jump from aircraft and remain airborne
		// for a long time, then jump again before landing. Only restore once the flight
		// state is actually over or invalid.
		_shouldRestore = (_isOnGround || {_isInWater || {_isInVehicle || {_isDead}}});
	};

	if (_shouldRestore) then {
		if (_protectEH >= 0) then {
			_unit removeEventHandler ["HandleDamage", _protectEH];
		};
		_unit setVariable ["FST_jumppack_protectEH", -1];
		_unit setVariable ["FST_jumppack_damageOverrideActive", false];
		_unit setVariable ["ace_medical_allowDamage", true, true];

		if (alive _unit) then {
			_unit call FST_jumppack_fnc_remove_effects;
		};
	};
};

// If there is no jump pack and no active damage override, stop this PFH. This
// is the key idle-efficiency guard: no one wearing a pack = no recharge loop.
if !(_unit getVariable ["FST_jumppack_hasJumppack", false]) exitWith {
	if !(_unit getVariable ["FST_jumppack_damageOverrideActive", false]) then {
		call FST_fnc_per_frame_EH_stop;
	};
};

// Dead check after the watchdog, so a death during flight cannot leave ACE damage disabled.
if !(alive _unit) exitWith {};

// Arsenal pause check
if !(_unit getVariable ["FST_do_energy_recharge", true]) exitWith {};

// Read cached config values (set by handle_loadout_change, zero config lookups)
private _rechargeRate   = _unit getVariable ["FST_jumppack_cachedRecharge", -1];
private _energyCapacity = _unit getVariable ["FST_jumppack_cachedCapacity", -1];
if (_rechargeRate < 0 || _energyCapacity < 0) exitWith {};

private _backpackObj = unitBackpack _unit;
if (_backpackObj isEqualTo objNull) exitWith {};

// Time delta calculation
private _lastCallTime = _unit getVariable ["FST_jumppack_last_call_time", time];
if (typeName _lastCallTime isEqualTo "BOOL") then {
	_lastCallTime = time;
};
private _dt = time - _lastCallTime;

// Calculate new energy
private _currEnergy = _backpackObj getVariable ["FST_jumppack_energy", 0];
private _newEnergy  = (_currEnergy + _rechargeRate * _dt) min _energyCapacity;

// Update timer locally (no one else needs this)
_unit setVariable ["FST_jumppack_last_call_time", time];

// If already full / unchanged, do nothing else. This keeps fully-charged jump-pack
// wearers from doing variable writes and HUD threshold checks 4 times per second.
if (_newEnergy isEqualTo _currEnergy) exitWith {};

// Update energy locally (no network broadcast on every tick)
_backpackObj setVariable ["FST_jumppack_energy", _newEnergy];

// HUD: only show when crossing a 12.5% threshold (called, not spawned)
[_currEnergy, _newEnergy, _energyCapacity] call FST_jumppack_fnc_show_energy_recharge;

// Broadcast energy only when we hit full charge (other clients rarely need this)
if (_newEnergy >= _energyCapacity && _currEnergy < _energyCapacity) then {
	_backpackObj setVariable ["FST_jumppack_energy", _energyCapacity, true];
};
