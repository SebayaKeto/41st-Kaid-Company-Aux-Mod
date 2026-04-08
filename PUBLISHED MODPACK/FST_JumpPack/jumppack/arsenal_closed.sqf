

params [
	["_unit", player, [player]]
];

// Arsenal may have changed the backpack — re-prime the config cache
player setVariable ["FST_jumppack_backpack_class", ""];
call FST_jumppack_fnc_handle_loadout_change;

// Use cached jumppack check (no config lookup)
if !(player getVariable ["FST_jumppack_hasJumppack", false]) exitWith {};

// Use cached capacity (no config lookup)
private _energyCapacity = player getVariable ["FST_jumppack_cachedCapacity", -1];
if (_energyCapacity < 0) exitWith {};

// Set energy to full and broadcast (meaningful state change)
(unitBackpack _unit) setVariable ["FST_jumppack_energy", _energyCapacity, true];
[_energyCapacity, _energyCapacity] call FST_jumppack_fnc_show_current_energy;
_unit setVariable ["FST_do_energy_recharge", true, true];
