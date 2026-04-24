// FST_HCSpawn_fnc_debugToggle
// Client-side. Toggles debug draw. Restricted to admin or Zeus.

if (!hasInterface) exitWith {};

// Check permissions
private _isAdmin = serverCommandAvailable "#kick";
private _isZeus = !isNull (getAssignedCuratorLogic player);

if (!_isAdmin && !_isZeus) exitWith {
    systemChat "[FST] Debug: admin or Zeus only.";
};

private _current = missionNamespace getVariable ["FST_HC_Debugging", false];
[!_current] call FST_HCSpawn_fnc_debugDraw;
