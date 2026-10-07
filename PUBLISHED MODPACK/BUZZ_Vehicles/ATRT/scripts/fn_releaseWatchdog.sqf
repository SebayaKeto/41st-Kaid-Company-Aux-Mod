// =============================================================================
//  BUZZ AT-RT — fn_releaseWatchdog.sqf
// =============================================================================

if (!hasInterface) exitWith {};

[] spawn {
    waitUntil { !isNull (findDisplay 46) };

    // ── Force eject (Ctrl+ESC) ───────────────────────────────────────────────
    (findDisplay 46) displayAddEventHandler ["KeyDown", {
        params ["", "_k", "", "_ctrl"];
        if (_k != 1 || { !_ctrl }) exitWith { false };
        private _a = call BUZZ_fnc_findControlledAtrt;
        if (isNull _a) exitWith { false };
        [_a, true] spawn BUZZ_fnc_forceRelease;
        true
    }];

    // ── Desync watchdog ──────────────────────────────────────────────────────
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
