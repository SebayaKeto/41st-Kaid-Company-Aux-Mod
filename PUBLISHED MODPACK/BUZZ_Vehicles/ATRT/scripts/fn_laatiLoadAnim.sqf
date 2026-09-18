// Server only — runs the AT-RT loading animation so all clients see it.
// BUZZ_packing on the AT-RT is the shared signal: client HUD watches it,
// ESC on the client sets it false (broadcast), server exits the animation.
// params: [_atrt, _laati, _hp, _cell, _reserves, _skipAnim]
params ["_atrt", "_laati", "_hp", "_cell", "_reserves", "_skipAnim"];

[_atrt, _laati, _hp, _cell, _reserves, _skipAnim] spawn {
    params ["_atrt", "_laati", "_hp", "_cell", "_reserves", "_skipAnim"];
    private _overallStart = time;

    if (_skipAnim) then {
        // ── Ramp already in use: hold until HUD countdown ends or ESC ─────────
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
        // ── Full animation: ramp open → walk → slide in → hide → ramp close ──
        _laati setVariable ["BUZZ_animating", true, true];

        // Open ramp (animPeriod = 2 s).
        _laati animateSource ["ramp", 1, true];

        // Phase 1: AT-RT walks to ramp entrance.
        // Timeout raised to 4 s and unitReady added so the walk completes even
        // when the AT-RT is parked further away (e.g. after a full deploy walk).
        _atrt allowDamage false;
        _atrt doMove (_laati modelToWorldVisual [0, -9.5, 0]);
        sleep 0.1;  // let doMove propagate to AI queue before unitReady is checked
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

        // Phase 2: attach and slide into cargo bay over ~3 s.
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

        // AT-RT is inside — hide it and close the ramp.
        _atrt hideObjectGlobal true;
        _laati animateSource ["ramp", 0, true];
        _laati setVariable ["BUZZ_animating", false, true];

        // Wait out any remaining HUD countdown time (animation takes ~4.2 s of the 5 s).
        private _remaining = 5 - (time - _overallStart);
        if (_remaining > 0) then { sleep _remaining; };

        // Signal client HUD to close, then hand off to pack function.
        _atrt setVariable ["BUZZ_packing", false, true];
        [_hp, _cell, _reserves, _atrt, _laati] call BUZZ_fnc_laatiLoadServer;
    };
};
