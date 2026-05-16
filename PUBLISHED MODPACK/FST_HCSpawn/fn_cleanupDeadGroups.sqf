// FST_HCSpawn_fnc_cleanupDeadGroups
// Server-side. Frees Arma side group slots by deleting OPFOR groups that have
// no living units left. This is separate from despawn cleanup: it does not
// delete live AI, bodies, vehicles, or player groups; it only deletes the group
// object once the group has zero alive members.
//
// Arguments:
//   0: BOOL — force cleanup immediately, bypass interval throttle
//
// Returns:
//   NUMBER — groups deleted

if (!isServer) exitWith {0};

params [["_force", false, [false]]];

if !(missionNamespace getVariable ["FST_HC_DeadGroupCleanupEnabled", true]) exitWith {0};

private _now = time;
private _interval = missionNamespace getVariable ["FST_HC_DeadGroupCleanupInterval", 20];
private _last = missionNamespace getVariable ["FST_HC_LastDeadGroupCleanup", -9999];
if (!_force && {(_now - _last) < _interval}) exitWith {0};
missionNamespace setVariable ["FST_HC_LastDeadGroupCleanup", _now];

if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };

private _deleted = 0;
private _trackedRemoved = 0;
private _tracked = +FST_HC_TrackedGroups;

{
    private _grp = _x;
    if (isNull _grp) then { continue };

    // Only clean OPFOR here. This avoids touching player-side groups, Zeus logic,
    // civilian ambience, and other mission systems that may expect empty groups.
    if !((side _grp) isEqualTo east) then { continue };

    private _units = units _grp;

    // Hard guard: never delete a group containing a player object, even if dead.
    if ((_units findIf { isPlayer _x }) >= 0) then { continue };

    // This intentionally matches the proven debug-console cleanup: dead units can
    // remain in a group after Munificent/drop-pod systems finish, and those dead
    // groups still consume side group slots until deleteGroup is called.
    if (({ alive _x } count _units) == 0) then {
        if (_grp in _tracked) then {
            _tracked = _tracked - [_grp];
            _trackedRemoved = _trackedRemoved + 1;
        };

        _grp setVariable ["FST_HC_tracked", nil];
        _grp setVariable ["FST_HC_onHC", nil];
        _grp setVariable ["FST_HC_heldBy", nil];
        deleteGroup _grp;
        _deleted = _deleted + 1;
    };
} forEach allGroups;

if (_trackedRemoved > 0) then {
    FST_HC_TrackedGroups = _tracked select { !isNull _x && {{alive _x} count units _x > 0} };
};

if (_deleted > 0) then {
    diag_log format ["[FST_HCSpawn] Dead group cleanup: deleted %1 empty/dead OPFOR groups (%2 tracked).", _deleted, _trackedRemoved];
};

_deleted
