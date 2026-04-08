// XEH_postinit.sqf
// Registers keybinds first (no dependencies), then spawns the cache/recharge
// init in scheduled context so player/backpack state is ready.

// Keybinds — register immediately, no player state needed
// These just register CBA keybind slots; the bound functions check for jumppack at call time.
call FST_jumppack_fnc_keybinds;

// Everything else needs player and backpack state, run in scheduled context
[] spawn {
	// Wait until player is fully initialized
	waitUntil {!isNull player && {alive player}};

	// Arsenal open/close handlers
	[player] call FST_jumppack_fnc_add_arsenal_handlers;

	// Loadout change handler
	call FST_jumppack_fnc_add_cba_player_loadout_EH;

	// Prime the config cache for current loadout
	player setVariable ["FST_jumppack_backpack_class", ""];
	call FST_jumppack_fnc_handle_loadout_change;

	// Start the recharge timer (0.25s interval)
	call FST_fnc_per_frame_EH;
};
