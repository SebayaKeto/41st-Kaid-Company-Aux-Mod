// XEH_postinit.sqf
// Client-only runtime bootstrap. Dedicated servers and headless clients have no
// player interface, so they should not register keybinds, arsenal hooks,
// loadout handlers, or a player waitUntil thread.

if (!hasInterface) exitWith {};
if !(missionNamespace getVariable ["FST_jumppack_enabled", true]) exitWith {};

// Keybinds — register immediately, no player state needed.
// These just register CBA keybind slots; the bound functions check for jumppack at call time.
call FST_jumppack_fnc_keybinds;

// Everything else needs player and backpack state, run in scheduled context.
[] spawn {
	// Wait until player is fully initialized.
	waitUntil {!isNull player && {alive player}};

	// Arsenal open/close handlers.
	[player] call FST_jumppack_fnc_add_arsenal_handlers;

	// Loadout change handler.
	call FST_jumppack_fnc_add_cba_player_loadout_EH;

	// Prime the config cache for current loadout.
	player setVariable ["FST_jumppack_backpack_class", ""];
	call FST_jumppack_fnc_handle_loadout_change;

	// Recharge/watchdog PFH is demand-started by handle_loadout_change if needed.
};
