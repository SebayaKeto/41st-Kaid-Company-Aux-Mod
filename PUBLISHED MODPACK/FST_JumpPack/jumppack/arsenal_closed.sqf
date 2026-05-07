params [
	["_unit", player, [player]]
];

if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};

// Always resume the local recharge flag on close if it had been paused.
_unit setVariable ["FST_do_energy_recharge", true];

private _before = _unit getVariable ["FST_jumppack_arsenalBackpackBefore", backpack _unit];
private _now = backpack _unit;
private _hadJumppack = _unit getVariable ["FST_jumppack_hasJumppack", false];
private _damageOverride = _unit getVariable ["FST_jumppack_damageOverrideActive", false];

// Fast no-op path for normal infantry: if they had no jump pack, have no active
// damage override, and their backpack did not change in Arsenal, do not force a
// cache refresh or PFH check. This is the common no-jump-pack-op case.
if (!_hadJumppack && {!_damageOverride} && {_before isEqualTo _now}) exitWith {};

// Arsenal may have changed the backpack — re-prime the config cache.
_unit setVariable ["FST_jumppack_backpack_class", ""];
call FST_jumppack_fnc_handle_loadout_change;

// Use cached jumppack check.
if !(_unit getVariable ["FST_jumppack_hasJumppack", false]) exitWith {};

// Preserve original behavior: closing Arsenal refills an equipped jump pack.
private _energyCapacity = _unit getVariable ["FST_jumppack_cachedCapacity", -1];
if (_energyCapacity < 0) exitWith {};

private _backpackObj = unitBackpack _unit;
if (_backpackObj isEqualTo objNull) exitWith {};

// Set energy to full and broadcast once; this is a meaningful state change.
_backpackObj setVariable ["FST_jumppack_energy", _energyCapacity, true];
[_energyCapacity, _energyCapacity] call FST_jumppack_fnc_show_current_energy;
