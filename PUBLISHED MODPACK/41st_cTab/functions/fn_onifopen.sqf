/*
	Name: cTab_fnc_onIfOpen
	
	Author(s):
		Gundy
	
	Description:
		Handles dialog / display setup, called by "onLoad" event
	
	Parameters:
		0: Display
	
	Returns:
		BOOLEAN - TRUE
	
	Example:
		// open TAD display as main interface type
		[_dispaly] call cTab_fnc_onIfOpen;
*/

private [];

uiNamespace setVariable [cTabIfOpen select 1,_this select 0];

// Rebuild the BFT lists on open. The 30s pulse no longer rebuilds them while
// the interface is closed (perf fix in player_init.sqf), so without this the
// tablet could show empty/stale markers for up to 30s after opening.
// Deferred one frame: running updateLists INSIDE the display's onLoad chain is
// a new execution ordering (it can re-trigger updateInterface mid-load via its
// list-changed check). Next-frame is ordering-safe and visually identical.
[{call cTab_fnc_updateLists}, [], 0] call CBA_fnc_waitAndExecute;

[] call cTab_fnc_updateInterface;

cTabIfOpenStart = false;

true