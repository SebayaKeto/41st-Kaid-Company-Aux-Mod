// Deploy AT-RT (server)
params ["_laati", "_crate", "_skipAnim"];

if (isNull _crate) exitWith { _laati setVariable ["BUZZ_deploying", false, true]; };

// Atomic claim
private _aceCargo = _laati getVariable ["ace_cargo_loaded", []];
private _fnAboard = {
    !isNull _x && { _x in _aceCargo || { (_x getVariable ["BUZZ_laatiStowed", objNull]) isEqualTo _laati } }
};
private _aboard = [_crate] findIf _fnAboard > -1;

// Manifest cleanup
private _crates = ((_laati getVariable ["BUZZ_laatiCrates", []]) - [_crate]) select _fnAboard;
_laati setVariable ["BUZZ_laatiCrates", _crates, true];

if (!_aboard || { _crate getVariable ["BUZZ_deployClaimed", false] }) exitWith {
    _laati setVariable ["BUZZ_deploying", false, true];
};
_crate setVariable ["BUZZ_deployClaimed", true];

private _hp       = _crate getVariable ["BUZZ_packed_hp",       1.0];
private _cell     = _crate getVariable ["BUZZ_packed_cell",     300];
private _reserves = _crate getVariable ["BUZZ_packed_reserves",   3];
private _class    = _crate getVariable ["BUZZ_packed_class", "BUZZ_ATRT"];

[_crate, _laati, objNull, [], false] call ace_cargo_fnc_unloadItem;
deleteVehicle _crate;

// Spawn AT-RT in cargo bay
private _group = createGroup [WEST, true];
private _atrt  = _group createUnit [_class, getPos _laati, [], 0, "NONE"];
_atrt setDir ((getDir _laati + 180) % 360);
_atrt attachTo [_laati, [0, -2.5, 0]];
_atrt hideObjectGlobal true;
_atrt allowDamage false;

if (_skipAnim) then {
    // ── No animation ──────────────────────────────────────────────────────────
    detach _atrt;
    _atrt setPosASL (AGLToASL (_laati modelToWorld [0, -9.5, 0]));
    _atrt hideObjectGlobal false;
    _atrt allowDamage true;
    _atrt enableAI "ALL";
    _atrt setVariable ["BUZZ_deployReady", true, true];   // no run-out to wait for

    [_atrt, _hp, _cell, _reserves] spawn {
        params ["_atrt", "_hp", "_cell", "_reserves"];
        waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) };
        _atrt setVariable ["BUZZ_hp",        _hp,   true];
        _atrt setVariable ["BUZZ_powerCell", _cell, true];
        private _box = _atrt getVariable ["supplyBox", objNull];
        clearMagazineCargoGlobal _box;
        if (_reserves > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _reserves]; };
    };
    _laati setVariable ["BUZZ_deploying", false, true];
} else {
    // ── Full animation ────────────────────────────────────────────────────────────
    _laati setVariable ["BUZZ_animating", true, true];

    [_atrt, _laati, _hp, _cell, _reserves] spawn {
        params ["_atrt", "_laati", "_hp", "_cell", "_reserves"];

        // Restore stats
        [_atrt, _hp, _cell, _reserves] spawn {
            params ["_atrt", "_hp", "_cell", "_reserves"];
            waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) };
            _atrt setVariable ["BUZZ_hp",        _hp,   true];
            _atrt setVariable ["BUZZ_powerCell", _cell, true];
            private _box = _atrt getVariable ["supplyBox", objNull];
            clearMagazineCargoGlobal _box;
            if (_reserves > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _reserves]; };
        };

        // Open ramp
        _laati animateSource ["ramp", 1, true];
        sleep 2.0;  // animPeriod = 2 s

        // Reveal AT-RT
        _atrt hideObjectGlobal false;

        // Slide to ramp exit
        private _startOff = [0, -2.5, 0.0];
        private _endOff   = [0, -9.5, 0.0];
        private _slideLen   = 2.5;
        private _slideStart = time;
        private _t = 0;
        private _deployDir = (getDir _laati + 180) % 360;
        while { _t < 1 } do {
            _t = ((time - _slideStart) / _slideLen) min 1;
            private _oy = (_startOff select 1) + _t * ((_endOff select 1) - (_startOff select 1));
            _atrt attachTo [_laati, [0, _oy, 0]];
            _atrt setDir _deployDir;
            sleep 0.1;
        };

        // Detach and walk clear
        detach _atrt;
        _atrt setDir _deployDir;
        private _walkTarget = _laati modelToWorld [0, -16, 0];
        _atrt doMove _walkTarget;
        _atrt allowDamage true;

        // Walk-clear wait
        private _walkStart = time;
        waitUntil { sleep 0.1; (_atrt distance2D _walkTarget) < 3 || time - _walkStart > 0.5 };

        // Deploy ready signal
        _atrt setVariable ["BUZZ_deployReady", true, true];

        sleep 0.5;
        _laati animateSource ["ramp", 0, true];
        _laati setVariable ["BUZZ_animating", false, true];
        _laati setVariable ["BUZZ_deploying", false, true];
    };
};
