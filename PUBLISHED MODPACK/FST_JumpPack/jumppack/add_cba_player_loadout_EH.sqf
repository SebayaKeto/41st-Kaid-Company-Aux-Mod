// add_cba_player_loadout_EH.sqf
// Local player loadout watcher. It is only registered on interface clients and
// only while the addon is enabled for this mission.

if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {-1};

private _existing = missionNamespace getVariable ["FST_jumppack_loadoutEH", -1];
if (_existing >= 0) exitWith {_existing};

private _id = ["loadout", FST_jumppack_fnc_handle_loadout_change] call CBA_fnc_addPlayerEventHandler;
missionNamespace setVariable ["FST_jumppack_loadoutEH", _id];
_id
