// LAAT/i loading animation (server)
params ["_atrt", "_laati", "_hp", "_cell", "_reserves", "_skipAnim"];

[_atrt, _laati, _hp, _cell, _reserves, _skipAnim] spawn {
    params ["_atrt", "_laati", "_hp", "_cell", "_reserves", "_skipAnim"];
    private _overallStart = time;

    if (_skipAnim) then {
        // ── Ramp already in use ───────────────────────────────────────────────
        waitUntil {
            !alive _atrt ||
            !(_atrt getVariable ["BUZZ_packing", false]) ||
            time - _overallStart >= 5
        };
        private _timedOut = alive _atrt && (_atrt getVariable ["BUZZ_packing", false]);
        _atrt setVariable ["BUZZ_packing", false, true];
        if (_timedOut) then {
            [_hp, _cell, _reserves, _atrt, _laati] call BUZZ_fnc_laatiLoadServer;
        };
    } else {
        // ── Full animation ───────────────────────────────────────────────────
        _laati setVariable ["BUZZ_animating", true, true];

        // Open ramp
        _laati animateSource ["ramp", 1, true];

        // Phase 1: walk to ramp
        _atrt allowDamage false;
        _atrt doMove (_laati modelToWorldVisual [0, -9.5, 0]);
        sleep 0.1;
        private _walkStart = time;
        waitUntil {
            !(_atrt getVariable ["BUZZ_packing", false]) ||
            !alive _atrt ||
            unitReady _atrt ||
            time - _walkStart >= 4.0
        };

        if (!(_atrt getVariable ["BUZZ_packing", false]) || !alive _atrt) exitWith {
            _atrt allowDamage true;
            _laati animateSource ["ramp", 0, true];
            _laati setVariable ["BUZZ_animating", false, true];
            _atrt setVariable ["BUZZ_packing", false, true];
        };

        // Phase 2: slide into cargo bay
        _atrt disableAI "ALL";
        private _startOff = [0, -7.5, -1.5];
        private _endOff   = [0, -2.5,  0.0];
        _atrt attachTo [_laati, _startOff];

        private _slideLen   = 3.0;
        private _slideStart = time;
        private _t = 0;
        while { _t < 1 && (_atrt getVariable ["BUZZ_packing", false]) && alive _atrt } do {
            _t = ((time - _slideStart) / _slideLen) min 1;
            private _oy = (_startOff select 1) + _t * ((_endOff select 1) - (_startOff select 1));
            private _oz = (_startOff select 2) + _t * ((_endOff select 2) - (_startOff select 2));
            _atrt attachTo [_laati, [0, _oy, _oz]];
            sleep 0.1;
        };

        if (!(_atrt getVariable ["BUZZ_packing", false]) || !alive _atrt) exitWith {
            detach _atrt;
            _atrt allowDamage true;
            _atrt enableAI "ALL";
            _laati animateSource ["ramp", 0, true];
            _laati setVariable ["BUZZ_animating", false, true];
            _atrt setVariable ["BUZZ_packing", false, true];
        };

        // Hide and close ramp
        _atrt hideObjectGlobal true;
        _laati animateSource ["ramp", 0, true];
        _laati setVariable ["BUZZ_animating", false, true];

        // Countdown remainder
        private _remaining = 5 - (time - _overallStart);
        if (_remaining > 0) then { sleep _remaining; };

        // HUD close and pack
        _atrt setVariable ["BUZZ_packing", false, true];
        [_hp, _cell, _reserves, _atrt, _laati] call BUZZ_fnc_laatiLoadServer;
    };
};
