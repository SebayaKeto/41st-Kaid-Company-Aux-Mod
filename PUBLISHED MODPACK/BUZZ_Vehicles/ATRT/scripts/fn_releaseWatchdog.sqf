// =============================================================================
//  BUZZ AT-RT — fn_releaseWatchdog.sqf
//  postInit, once per client. Installs the Ctrl+ESC force eject and a
//  background check that frees the player if they're still controlling an
//  AT-RT they're no longer riding (camera on the body, input on the walker).
// =============================================================================

if (!hasInterface) exitWith {};

[] spawn {
    waitUntil { !isNull (findDisplay 46) };

    // ── Force eject (Ctrl+ESC) ───────────────────────────────────────────────
    // Installed once for the whole mission, not per mount, and finds the walker
    // from the engine's remote-control link — so it still works after a failed
    // dismount has already cleared the rider variables.
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["", "_k", "", "_ctrl"];
        if (_k != 1 || { !_ctrl }) exitWith { false };
        private _a = call BUZZ_fnc_findControlledAtrt;
        if (isNull _a) exitWith { false };
        [_a, true] spawn BUZZ_fnc_forceRelease;
        true
    }];

    // ── Desync watchdog ──────────────────────────────────────────────────────
    // Every 0.5 s: if the player controls an AT-RT but isn't its rider, or the
    // camera isn't on it, or it's dead — for two checks in a row — release it.
    // Skipped while Zeus is open (the curator camera replaces cameraOn).
    private _strikes = 0;
    while { true } do {
        sleep 0.5;
        private _a = objNull;
        {
            if ((remoteControlled _x) isEqualTo player) exitWith { _a = _x; };
        } forEach (entities [["BUZZ_ATRT"], [], false, false]);

        private _desync = !isNull _a
            && { isNull curatorCamera }
            && { time >= (missionNamespace getVariable ["BUZZ_releaseUntil", -1]) }
            && {
                !alive _a
                || { !((_a getVariable ["rider", objNull]) isEqualTo player) }
                || { !(cameraOn isEqualTo _a) }
            };

        _strikes = if (_desync) then { _strikes + 1 } else { 0 };
        if (_strikes >= 2) then {
            _strikes = 0;
            [_a, false] call BUZZ_fnc_forceRelease;
        };
    };
};
