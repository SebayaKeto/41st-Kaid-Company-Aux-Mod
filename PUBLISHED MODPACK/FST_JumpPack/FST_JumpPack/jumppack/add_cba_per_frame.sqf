
// add_cba_per_frame.sqf
// REWRITE: Energy recharge tick. Runs every 0.25s via CBA timer (was every frame via spawn).
// Changes:
//   - Uses cached config values from handle_loadout_change (no config tree walks)
//   - Called, not spawned (no scheduler thread creation)
//   - Energy stored locally, only broadcast when crossing 12.5% threshold or hitting full
//   - last_call_time is local-only (no other client needs it)
//   - show_energy_recharge called, not spawned

params ["_args", "_id"];

private _unit = player;

// Dead/null check
if (!(alive _unit) || (_unit isEqualTo objNull)) exitWith {};

// Fast cached check: does this player have a jumppack?
if !(player getVariable ["FST_jumppack_hasJumppack", false]) exitWith {};

// Arsenal pause check
if !(player getVariable ["FST_do_energy_recharge", true]) exitWith {};

// Read cached config values (set by handle_loadout_change, zero config lookups)
private _rechargeRate   = player getVariable ["FST_jumppack_cachedRecharge", -1];
private _energyCapacity = player getVariable ["FST_jumppack_cachedCapacity", -1];
if (_rechargeRate < 0 || _energyCapacity < 0) exitWith {};

// Time delta calculation
private _lastCallTime = player getVariable ["FST_jumppack_last_call_time", time];
if (typeName _lastCallTime isEqualTo "BOOL") then {
	_lastCallTime = time;
};
private _dt = time - _lastCallTime;

// Calculate new energy
private _currEnergy = (unitBackpack _unit) getVariable ["FST_jumppack_energy", 0];
private _newEnergy  = (_currEnergy + _rechargeRate * _dt) min _energyCapacity;

// Update energy locally (no network broadcast on every tick)
(unitBackpack _unit) setVariable ["FST_jumppack_energy", _newEnergy];

// Update timer locally (no one else needs this)
player setVariable ["FST_jumppack_last_call_time", time];

// HUD: only show when crossing a 12.5% threshold (called, not spawned)
[_currEnergy, _newEnergy, _energyCapacity] call FST_jumppack_fnc_show_energy_recharge;

// Broadcast energy only when we hit full charge (other clients rarely need this)
if (_newEnergy >= _energyCapacity && _currEnergy < _energyCapacity) then {
	(unitBackpack _unit) setVariable ["FST_jumppack_energy", _energyCapacity, true];
};
