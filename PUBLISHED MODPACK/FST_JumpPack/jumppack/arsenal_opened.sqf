params [
	["_unit", player, [player]]
];

if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};

// Local-only: only the local recharge PFH reads this flag.
_unit setVariable ["FST_do_energy_recharge", false];
