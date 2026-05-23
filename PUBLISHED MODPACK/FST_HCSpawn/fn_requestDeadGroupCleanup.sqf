// FST_HCSpawn_fnc_requestDeadGroupCleanup
// Server-side/manual maintenance entry point. Intended for Zeus/admin use during
// a lull, not as a combat-time automatic sweeper. The server cleans local groups
// and also asks each HC to clean its own local dead groups.
//
// Arguments:
//   0: NUMBER — max groups to delete this request, default 150
//   1: NUMBER — untracked dead-age override, default 0 for manual maintenance
//   2: NUMBER — tracked dead-age override, default 60 for extra caution
//   3: NUMBER — requesting client owner ID, optional for feedback

if (!isServer) exitWith {};

params [
    ["_maxDeletes", 150, [0]],
    ["_minAge", 0, [0]],
    ["_trackedMinAge", 60, [0]],
    ["_callerID", -2, [0]]
];

_maxDeletes = round ((_maxDeletes max 1) min 300);
_minAge = (_minAge max 0) min 1800;
_trackedMinAge = (_trackedMinAge max _minAge) min 3600;

private _deleted = [true, _maxDeletes, _minAge, _trackedMinAge] call FST_HCSpawn_fnc_cleanupDeadGroups;
if (_deleted > 0) then {
    [] call FST_HCSpawn_fnc_recountUnits;
};

private _hcCount = 0;
{
    ["FST_HC_evt_cleanupDeadGroupsLocal", [true, _maxDeletes, _minAge, _trackedMinAge], _x] call CBA_fnc_ownerEvent;
    _hcCount = _hcCount + 1;
} forEach FST_HC_Ids;

diag_log format ["[FST_HCSpawn] Manual dead group cleanup requested. serverDeleted=%1 hcRequests=%2 max=%3 minAge=%4 trackedMinAge=%5 caller=%6", _deleted, _hcCount, _maxDeletes, _minAge, _trackedMinAge, _callerID];

if (_callerID != 0) then {
    format ["[FST] Dead group cleanup: deleted %1 server-local groups; requested cleanup on %2 HCs.", _deleted, _hcCount] remoteExec ["systemChat", _callerID];
};

_deleted
