// Triggered when a crew member activates "Deploy AT-RT" from inside the LAAT/i.
// Deploys the oldest loaded AT-RT (FIFO).
// params: [_laati, _caller, _actionId]
params ["_laati", "_caller"];

private _crates = _laati getVariable ["BUZZ_laatiCrates", []];
if (count _crates == 0) exitWith { hint "Deploy: no AT-RT loaded."; };
if (_laati getVariable ["BUZZ_deploying", false]) exitWith {};

// Find the turret path the caller is occupying (true = include FFV seats)
private _callerPath = [];
{
    if ((_laati turretUnit _x) isEqualTo _caller) then { _callerPath = _x; };
} forEach (allTurrets [_laati, true]);

if (count _callerPath == 0) exitWith { hint "Deploy: could not find your seat."; };

// FFV (Firing From Vehicle) seats are in allTurrets [_, true] but NOT in
// allTurrets [_, false].  Ramp gunners are the only FFV positions on the LAAT/i,
// so a path absent from the non-FFV list means the caller is in a ramp gunner seat.
if (_callerPath in (allTurrets [_laati, false])) exitWith {
    hint "Deploy: must be in a Ramp Gunner seat.";
};

private _crate    = _crates select 0;
private _skipAnim = _laati getVariable ["BUZZ_animating", false];

_laati setVariable ["BUZZ_deploying", true, true];

// Local-only flag (not publicVariable'd) so the HUD on THIS machine tracks
// this player's own mount completion rather than the server's animation-done
// signal on _laati. Those two used to be conflated: the server clears
// BUZZ_deploying as soon as its ramp/walk sequence finishes, which can be
// well before this client's own watcher below actually detects and mounts
// the AT-RT (especially over real network latency to a dedicated server) —
// the loading bar would vanish while the player was still waiting to be
// teleported. Gating the HUD on this instead keeps it open until the mount
// (or the watcher's timeout) actually happens.
_caller setVariable ["BUZZ_deployWait", true];
[_caller, _caller, 6, "DEPLOYING AT-RT", "BUZZ_deployWait"] execVM "\BUZZ_Vehicles\ATRT\scripts\pack_hud.sqf";

// ── Mount handoff ──────────────────────────────────────────────────────────────
// Earlier versions relayed an identifier from the server back to this specific
// client (first via owner-ID remoteExec, then via a broadcast variable) so this
// script could recognise "its" AT-RT and mount it. Both were unreliable for
// connected (non-host) clients. This drops the relay entirely: this script
// already knows which LAAT/i it's deploying from, so it snapshots the nearby
// AT-RTs before requesting the deploy, then watches for the one new AT-RT that
// shows up near that same LAAT/i afterward — using nothing but plain object
// presence (nearestObjects) and attachment state (attachedTo), both fundamental,
// always-reliable engine mechanisms, not a custom sync channel that can silently
// fail to reach one specific machine.
//
// The search is anchored to the LAAT/i's position AT THIS MOMENT (_deployPos),
// not to the LAAT/i object itself. On a dedicated server the new AT-RT can take
// a long time to replicate to this client, and the LAAT/i is typically flown
// away right after dropping it — searching relative to the LAAT/i's *current*
// position would then search around empty air and could permanently miss the
// AT-RT once it drifts outside the radius. A fixed point plus a generous radius
// and timeout means slow replication only delays the mount, it never loses it.
private _deployPos = getPosATL _laati;
private _before = nearestObjects [_deployPos, ["BUZZ_ATRT"], 150];

[_laati, _crate, _skipAnim] remoteExecCall ["BUZZ_fnc_laatiDeployServer", 2];

[_deployPos, _before, _caller] spawn {
    params ["_deployPos", "_before", "_caller"];

    private _atrt    = objNull;
    private _timeout = time + 90;
    waitUntil {
        sleep 0.1;
        if (isNull _atrt) then {
            private _new = (nearestObjects [_deployPos, ["BUZZ_ATRT"], 150]) - _before;
            if (count _new > 0) then { _atrt = _new select 0; };
        };
        // Wait for detach too: the server keeps the AT-RT attached (and hidden,
        // for the full-animation case) inside the LAAT/i until the ramp/walk
        // sequence reaches the point where it's actually ready to be mounted —
        // detach happens at exactly that moment in fn_laatiDeployServer.sqf.
        (!isNull _atrt && { isNull (attachedTo _atrt) }) || time > _timeout
    };
    if (isNull _atrt || { !isNull (attachedTo _atrt) }) exitWith {
        _caller setVariable ["BUZZ_deployWait", false];
    };

    [_atrt] call BUZZ_fnc_laatiAutoMount;
    _caller setVariable ["BUZZ_deployWait", false];
};
