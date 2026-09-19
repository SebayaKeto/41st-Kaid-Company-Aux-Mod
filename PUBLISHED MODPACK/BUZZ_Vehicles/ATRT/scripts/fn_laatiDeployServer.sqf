// Server only — unpacks the AT-RT and runs the ramp/walk/mount sequence.
// Called immediately on button press (no client-side countdown wait).
// The deploying client detects and mounts its own AT-RT independently (see
// fn_laatiDeployAction.sqf) by watching for it to appear and detach — this
// function doesn't need to know or report back who requested the deploy.
// params: [_laati, _crate, _skipAnim]
params ["_laati", "_crate", "_skipAnim"];

if (isNull _crate) exitWith { _laati setVariable ["BUZZ_deploying", false, true]; };

// Atomic claim: remove the crate from the manifest as the very first operation.
// SQF yields only at sleep/waitUntil so these lines cannot be interleaved with a
// concurrent deploy call — if two players trigger Deploy simultaneously, the first
// call to reach this point removes the crate and proceeds; the second sees it is no
// longer in the list and exits before any AT-RT is spawned.
private _crates = _laati getVariable ["BUZZ_laatiCrates", []];
if !(_crate in _crates) exitWith { _laati setVariable ["BUZZ_deploying", false, true]; };
_crates = _crates - [_crate];
_laati setVariable ["BUZZ_laatiCrates", _crates, true];

private _hp       = _crate getVariable ["BUZZ_packed_hp",       1.0];
private _cell     = _crate getVariable ["BUZZ_packed_cell",     300];
private _reserves = _crate getVariable ["BUZZ_packed_reserves",   3];

[_crate, _laati, objNull, [], false] call ace_cargo_fnc_unloadItem;
deleteVehicle _crate;

// Spawn AT-RT inside cargo bay, attached to LAAT/i so it rides with it.
// Hidden until ramp is open. No doMove is pending so AI won't fight the attachment.
private _group = createGroup WEST;
private _atrt  = _group createUnit ["BUZZ_ATRT", getPos _laati, [], 0, "NONE"];
_atrt setDir ((getDir _laati + 180) % 360);
_atrt attachTo [_laati, [0, -2.5, 0]];
_atrt hideObjectGlobal true;
_atrt allowDamage false;

if (_skipAnim) then {
    // ── No animation: place at ramp exit and mount immediately ────────────────
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
    // ── Full animation: ramp opens → slide out → walk clear → mount → ramp closes ─
    _laati setVariable ["BUZZ_animating", true, true];

    [_atrt, _laati, _hp, _cell, _reserves] spawn {
        params ["_atrt", "_laati", "_hp", "_cell", "_reserves"];

        // Restore stats concurrently while animation plays.
        [_atrt, _hp, _cell, _reserves] spawn {
            params ["_atrt", "_hp", "_cell", "_reserves"];
            waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) };
            _atrt setVariable ["BUZZ_hp",        _hp,   true];
            _atrt setVariable ["BUZZ_powerCell", _cell, true];
            private _box = _atrt getVariable ["supplyBox", objNull];
            clearMagazineCargoGlobal _box;
            if (_reserves > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _reserves]; };
        };

        // Open ramp — AT-RT is hidden inside cargo bay during this phase.
        _laati animateSource ["ramp", 1, true];
        sleep 2.0;  // animPeriod = 2 s

        // Reveal AT-RT inside cargo bay now that the ramp is open.
        _atrt hideObjectGlobal false;

        // Slide from cargo bay to ramp exit — mirror of the loading slide.
        // Z=0 throughout keeps the AT-RT above the open ramp door (Z≈-1.5).
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
            _atrt setDir _deployDir;  // attachTo resets heading each tick — re-apply every iteration
            sleep 0.1;
        };

        // Detach at ramp exit and walk clear. This is the signal the deploying
        // client's own watcher is waiting on (attachedTo _atrt becomes null) —
        // see fn_laatiDeployAction.sqf.
        detach _atrt;
        _atrt setDir _deployDir;
        private _walkTarget = _laati modelToWorld [0, -16, 0];
        _atrt doMove _walkTarget;
        _atrt allowDamage true;

        // Don't wait for unitReady (it only flips once the AI fully settles, which
        // added several idle seconds after the loading bar finished) — the walker
        // is clear of the ramp once it's near the target, or after 0.5 s at most.
        private _walkStart = time;
        waitUntil { sleep 0.1; (_atrt distance2D _walkTarget) < 3 || time - _walkStart > 0.5 };

        // Run-out finished: tell the deploying client it's now safe to teleport
        // its player onto the AT-RT. Broadcast on the AT-RT itself (an object that
        // client already tracks) — see the watcher in fn_laatiDeployAction.sqf.
        _atrt setVariable ["BUZZ_deployReady", true, true];

        sleep 0.5;
        _laati animateSource ["ramp", 0, true];
        _laati setVariable ["BUZZ_animating", false, true];
        _laati setVariable ["BUZZ_deploying", false, true];
    };
};
