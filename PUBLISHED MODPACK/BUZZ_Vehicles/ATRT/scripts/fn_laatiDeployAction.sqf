// Deploy AT-RT action
params ["_laati", "_caller"];

// Crates aboard
private _aceCargo = _laati getVariable ["ace_cargo_loaded", []];
private _crates = (_laati getVariable ["BUZZ_laatiCrates", []]) select {
    !isNull _x && { _x in _aceCargo || { (_x getVariable ["BUZZ_laatiStowed", objNull]) isEqualTo _laati } }
};
{
    if (_x isEqualType objNull && { _x isKindOf "BUZZ_ATRT_TransportCrate" }) then { _crates pushBackUnique _x; };
} forEach _aceCargo;
if (count _crates == 0) exitWith { hint "Deploy: no AT-RT loaded."; };
if (_laati getVariable ["BUZZ_deploying", false]) exitWith {};

// Caller seat
private _callerPath = [];
{
    if ((_laati turretUnit _x) isEqualTo _caller) then { _callerPath = _x; };
} forEach (allTurrets [_laati, true]);

if (count _callerPath == 0) exitWith { hint "Deploy: could not find your seat."; };

// Ramp gunner check
if (_callerPath in (allTurrets [_laati, false])) exitWith {
    hint "Deploy: must be in a Ramp Gunner seat.";
};

private _crate    = _crates select 0;
private _skipAnim = _laati getVariable ["BUZZ_animating", false];

_laati setVariable ["BUZZ_deploying", true, true];

// Deploy HUD flag
_caller setVariable ["BUZZ_deployWait", true];
[_caller, _caller, 6, "DEPLOYING AT-RT", "BUZZ_deployWait"] execVM "\BUZZ_Vehicles\ATRT\scripts\pack_hud.sqf";

// ── Mount handoff ──────────────────────────────────────────────────────────────
private _deployPos = getPosATL _laati;
private _before = nearestObjects [_deployPos, ["BUZZ_ATRT"], 150];

[_laati, _crate, _skipAnim] remoteExecCall ["BUZZ_fnc_laatiDeployServer", 2];

[_deployPos, _before, _caller] spawn {
    params ["_deployPos", "_before", "_caller"];

    private _atrt     = objNull;
    private _timeout  = time + 90;
    private _detachAt = -1;
    waitUntil {
        sleep 0.1;
        if (isNull _atrt) then {
            private _new = (nearestObjects [_deployPos, ["BUZZ_ATRT"], 150]) - _before;
            if (count _new > 0) then { _atrt = _new select 0; };
        };
        // Wait for run-out
        if (!isNull _atrt && { isNull (attachedTo _atrt) } && { _detachAt < 0 }) then { _detachAt = time; };
        (_detachAt >= 0 && { (_atrt getVariable ["BUZZ_deployReady", false]) || { time - _detachAt > 4 } })
            || time > _timeout
    };
    if (isNull _atrt || { !isNull (attachedTo _atrt) }) exitWith {
        _caller setVariable ["BUZZ_deployWait", false];
    };

    [_atrt] call BUZZ_fnc_laatiAutoMount;
    _caller setVariable ["BUZZ_deployWait", false];
};
