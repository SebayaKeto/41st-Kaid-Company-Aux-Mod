// FST_HCSpawn_fnc_cleanupDeadGroups
// Server/HC-local. Frees Arma side group slots by deleting OPFOR groups that have
// had zero alive units for a safe grace period on the machine where the group is local.
//
// V19 keeps dead-group cleanup manual-only by default and enforces locality.
// The automatic path is intentionally slow; manual cleanup can be requested
// during lulls when group slots need to be freed.
// This sweeper is:
// - interval-limited on automatic calls
// - age-gated unless explicitly forced
// - capped per pass
// - extra conservative with FST-tracked groups
// - disabled during emergency HC redistribution
//
// Arguments:
//   0: BOOL   — force/manual cleanup. Bypasses interval and can bypass age if overrides are 0.
//   1: NUMBER — optional max deletions override; -1 uses setting
//   2: NUMBER — optional untracked dead-age override; -1 uses setting
//   3: NUMBER — optional tracked dead-age override; -1 uses setting
//
// Returns:
//   NUMBER — groups deleted

if (hasInterface && {!isServer}) exitWith {0};

params [
    ["_force", false, [false]],
    ["_maxOverride", -1, [0]],
    ["_minAgeOverride", -1, [0]],
    ["_trackedAgeOverride", -1, [0]]
];

if (!(missionNamespace getVariable ["FST_HC_DeadGroupCleanupEnabled", true]) && {!_force}) exitWith {0};

// Do not delete groups while ownership is being redistributed after an HC loss.
// This is exactly when object ownership and network state are most fragile.
if (missionNamespace getVariable ["FST_HC_EmergencyMode", false]) exitWith {0};

private _now = time;
private _interval = missionNamespace getVariable ["FST_HC_DeadGroupCleanupInterval", 1200];
_interval = (_interval max 300) min 1800;

private _last = missionNamespace getVariable ["FST_HC_LastDeadGroupCleanup", 0];
if (!_force && {(_now - _last) < _interval}) exitWith {0};
missionNamespace setVariable ["FST_HC_LastDeadGroupCleanup", _now];

private _minAge = if (_minAgeOverride >= 0) then {_minAgeOverride} else {missionNamespace getVariable ["FST_HC_DeadGroupCleanupMinAge", 300]};
private _trackedMinAge = if (_trackedAgeOverride >= 0) then {_trackedAgeOverride} else {missionNamespace getVariable ["FST_HC_DeadTrackedGroupCleanupMinAge", 900]};
private _maxDeletes = if (_maxOverride >= 0) then {_maxOverride} else {missionNamespace getVariable ["FST_HC_DeadGroupCleanupMaxPerPass", 25]};

_minAge = (_minAge max 0) min 1800;
_trackedMinAge = (_trackedMinAge max _minAge) min 3600;
_maxDeletes = round ((_maxDeletes max 1) min 300);

// Protect against older saved CBA profiles from V12/V13 keeping aggressive values.
// Manual/forced calls can still use explicit overrides.
if (!_force) then {
    _minAge = _minAge max 300;
    _trackedMinAge = _trackedMinAge max 900;
    _maxDeletes = _maxDeletes min 25;
};

if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };

private _deleted = 0;
private _trackedRemoved = 0;
private _tracked = +FST_HC_TrackedGroups;
private _stillTracked = [];

{
    private _grp = _x;
    if (isNull _grp) then { continue };

    // deleteGroup is local-effect for groups; only the machine owning the group
    // should attempt to delete it. Server-side manual cleanup separately asks
    // each registered HC to run this function locally.
    if !(local _grp) then { continue };

    if !((side _grp) isEqualTo east) then { continue };

    // Never touch player groups.
    private _units = units _grp;
    if ((_units findIf { isPlayer _x }) >= 0) then { continue };

    private _aliveCount = { alive _x } count _units;
    if (_aliveCount > 0) then {
        _grp setVariable ["FST_HC_deadSince", nil];
        continue;
    };

    // Freshly spawned or intercepted groups can briefly report strange states.
    // Never let dead-group cleanup race Zeus clone handoff or spawn settling.
    if (_grp getVariable ["FST_HC_interceptQueued", false]) then { continue };
    if (_grp getVariable ["FST_HC_originalSuppressed", false]) then { continue };
    if ((_grp getVariable ["FST_HC_spawnProtectedUntil", 0]) > _now) then { continue };

    private _isTracked = _grp in _tracked;
    private _requiredAge = if (_isTracked) then {_trackedMinAge} else {_minAge};
    private _deadSince = _grp getVariable ["FST_HC_deadSince", -1];
    if (_deadSince < 0) then {
        _deadSince = if (_force) then {_now - _requiredAge} else {_now};
        _grp setVariable ["FST_HC_deadSince", _deadSince];
        if (!_force) then { continue };
    };

    if ((_now - _deadSince) < _requiredAge) then { continue };

    if (_deleted >= _maxDeletes) then { continue };

    if (_isTracked) then {
        _trackedRemoved = _trackedRemoved + 1;
    };

    _grp setVariable ["FST_HC_tracked", nil];
    _grp setVariable ["FST_HC_onHC", nil];
    _grp setVariable ["FST_HC_heldBy", nil];
    _grp setVariable ["FST_HC_deadSince", nil];

    deleteGroup _grp;
    _deleted = _deleted + 1;
} forEach allGroups;

// Compact the tracking cache after any pass, but do not force-delete anything
// else here. Null/empty/dead tracked groups will age out safely on later passes.
{
    private _grp = _x;
    if (!isNull _grp && {{alive _x} count units _grp > 0}) then {
        _stillTracked pushBackUnique _grp;
    };
} forEach _tracked;
FST_HC_TrackedGroups = _stillTracked;

if (_deleted > 0) then {
    diag_log format ["[FST_HCSpawn] Dead group cleanup: deleted %1 OPFOR groups (%2 tracked, max=%3, force=%4, owner=%5).", _deleted, _trackedRemoved, _maxDeletes, _force, clientOwner];
};

_deleted
