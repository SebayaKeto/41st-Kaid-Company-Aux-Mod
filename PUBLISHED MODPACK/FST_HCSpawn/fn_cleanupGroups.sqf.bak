// FST_HCSpawn_fnc_cleanupGroups
// Server-side PFH. Two-phase despawn:
// Phase 1 — group activates when ground players come within engagement range
// Phase 2 — after activation, group deletes when no ground players nearby for stale timer

if (!isServer) exitWith {};
if (!FST_HC_DespawnEnabled) exitWith {};

// Do not run despawn cleanup while heavy spawn/JIP-sensitive work has just happened.
// Deleting freshly networked HC-owned groups during/just after Fill Garrison was
// producing object-not-found churn and desync spikes.
if (missionNamespace getVariable ["FST_HC_FillGarrisonActive", false]) exitWith {};
private _cleanupGrace = missionNamespace getVariable ["FST_HC_CleanupPostSpawnGrace", 60];
private _lastHeavySpawn = missionNamespace getVariable ["FST_HC_LastHeavySpawnTime", -9999];
if ((time - _lastHeavySpawn) < _cleanupGrace) exitWith {};

private _engageRadius = FST_HC_DespawnEngageRadius;
private _despawnRadius = FST_HC_DespawnRadius;
private _staleTime = FST_HC_DespawnTimer;
private _toDelete = [];
if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };

// Keep the tracking cache clean. Previously grpNull/empty groups could stay in
// FST_HC_TrackedGroups because the delete loop skipped null groups before
// removing them from the cache.
private _beforeCompact = count FST_HC_TrackedGroups;
FST_HC_TrackedGroups = FST_HC_TrackedGroups select { !isNull _x && {count units _x > 0} };
if (FST_HC_DebugLogging && {_beforeCompact != count FST_HC_TrackedGroups}) then {
    diag_log format ["[FST_HCSpawn] Cleanup compacted tracked group cache: %1 -> %2", _beforeCompact, count FST_HC_TrackedGroups];
};

// Build this once per cleanup tick. With 150 players and many groups this is
// cheaper and steadier than running nearEntities around every AI group.
private _groundPlayers = ([] call CBA_fnc_players) select {
    alive _x &&
    {!(vehicle _x isKindOf "Air")}
};

{
    private _grp = _x;
    private _data = _grp getVariable ["FST_HC_tracked", []];
    if (count _data == 0) then { continue };

    if (isNull _grp || {count units _grp == 0}) then {
        _toDelete pushBackUnique _grp;
        continue;
    };

    private _leader = leader _grp;
    if (isNull _leader) then {
        _toDelete pushBackUnique _grp;
        continue;
    };

    // Fresh HC-spawned groups need time for object ownership, curator editability,
    // and JIP/network identity to settle before any despawn cleanup is allowed.
    if (time < (_grp getVariable ["FST_HC_spawnProtectedUntil", -1])) then { continue };

    private _pos = getPosATL _leader;
    private _activated = _grp getVariable ["FST_HC_activated", false];
    private _searchRadius = if (_activated) then { _despawnRadius } else { _engageRadius };

    private _hasGroundPlayerNear = (_groundPlayers findIf { alive _x && {(_x distance2D _pos) <= _searchRadius} }) >= 0;

    if (!_activated && {_hasGroundPlayerNear}) then {
        _grp setVariable ["FST_HC_activated", true];
        _activated = true;
    };

    if (_activated) then {
        if (!_hasGroundPlayerNear) then {
            private _staleStart = _grp getVariable ["FST_HC_staleStart", -1];
            if (_staleStart < 0) then {
                _grp setVariable ["FST_HC_staleStart", time];
            } else {
                if ((time - _staleStart) >= _staleTime) then {
                    _toDelete pushBackUnique _grp;
                };
            };
        } else {
            _grp setVariable ["FST_HC_staleStart", -1];
        };
    };
} forEach +FST_HC_TrackedGroups;

private _cleaned = 0;
{
    private _grp = _x;
    if (isNull _grp) then { continue };

    private _vehicles = [];
    private _looseUnits = [];

    {
        if (isNull _x) then { continue };
        _x setVariable ["FST_skipSpawnDamage", true, true];
        private _veh = vehicle _x;
        if (!isNull _veh && {_veh != _x}) then {
            _vehicles pushBackUnique _veh;
        } else {
            _looseUnits pushBackUnique _x;
        };
    } forEach units _grp;

    // Delete vehicle crews using the vehicle-safe command first, then the vehicles.
    {
        private _veh = _x;
        if (isNull _veh) then { continue };
        {
            if (!isNull _x) then {
                _x setVariable ["FST_skipSpawnDamage", true, true];
                _veh deleteVehicleCrew _x;
            };
        } forEach crew _veh;
        deleteVehicle _veh;
    } forEach _vehicles;

    {
        if (!isNull _x) then {
            _x setVariable ["FST_skipSpawnDamage", true, true];
            deleteVehicle _x;
        };
    } forEach _looseUnits;

    _grp setVariable ["FST_HC_tracked", nil];
    _grp setVariable ["FST_HC_onHC", nil];
    FST_HC_TrackedGroups = FST_HC_TrackedGroups - [_grp];
    _cleaned = _cleaned + 1;
} forEach _toDelete;

if (_cleaned > 0) then {
    diag_log format ["[FST_HCSpawn] Cleanup: despawned %1 groups", _cleaned];
    [] call FST_HCSpawn_fnc_recountUnits;
};
