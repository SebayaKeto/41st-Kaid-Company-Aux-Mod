// FST_HCSpawn_fnc_cleanupGroups
// Server-side PFH. Two-phase despawn:
// Phase 1 -- group activates when ground players come within engagement range
// Phase 2 -- after activation, group deletes when no ground players nearby for stale timer
//
// V27: with FST_HC_DespawnOnlyManaged (default ON) only groups created by this
// addon or placed by Zeus are eligible. The catch-all also offloads editor-placed
// and mission-script AI to HCs, and those used to be despawned too.

if (!isServer) exitWith {};
if (!FST_HC_DespawnEnabled) exitWith {};

// Fresh groups have their own server-side protection in trackGroup. A new
// wave must not postpone cleanup of every old group in the mission.
if (missionNamespace getVariable ["FST_HC_FillGarrisonActive", false]) exitWith {};
private _maxGroups=(floor (missionNamespace getVariable ["FST_HC_DespawnMaxGroups",2])) max 0;
private _maxUnits=(floor (missionNamespace getVariable ["FST_HC_DespawnMaxUnits",24])) max 0;
if (_maxGroups==0 || {_maxUnits==0}) exitWith {};
private _deleteUnits=0;
private _protected={
    params ["_group"];
    (_group getVariable ["FST_HC_heldBy",-1])!=-1 ||
    {_group getVariable ["FST_HC_noDespawn",false]} ||
    {_group getVariable ["BURNS_exempt",false]} ||
    {_group getVariable ["FST_HC_pendingTransfer",false]} ||
    {_group getVariable ["FST_HC_interceptQueued",false]} ||
    {[_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup} ||
    {(units _group findIf {
        _x getVariable ["BURNS_exempt",false] || {
            private _vehicle=vehicle _x;
            _vehicle!=_x && {(crew _vehicle findIf {group _x!=_group})>=0}
        }
    })>=0}
};

private _engageRadius = FST_HC_DespawnEngageRadius;
private _despawnRadius = FST_HC_DespawnRadius;
private _staleTime = FST_HC_DespawnTimer;
private _onlyManaged = missionNamespace getVariable ["FST_HC_DespawnOnlyManaged", true];
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
if (count FST_HC_TrackedGroups == 0) exitWith {};

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

    if (_onlyManaged && {!(_grp getVariable ["FST_HC_managed", false])}) then { continue };
    // A hold/protection interrupts the continuous absence timer.
    if ([_grp] call _protected) then {_grp setVariable ["FST_HC_staleStart",-1];continue};

    private _leader = leader _grp;
    if (isNull _leader) then {continue};

    // Fresh HC-spawned groups need time for object ownership, curator editability,
    // and JIP/network identity to settle before any despawn cleanup is allowed.
    if (time < (_grp getVariable ["FST_HC_spawnProtectedUntil", -1])) then { continue };

    private _pos = getPosATL _leader;
    private _activated = _grp getVariable ["FST_HC_activated", false];
    private _searchRadius = if (_activated) then { _despawnRadius } else { _engageRadius };

    private _hasGroundPlayerNear = (_groundPlayers findIf { (_x distance2D _pos) <= _searchRadius }) >= 0;

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
                    private _size=count units _grp;
                    if (count _toDelete<_maxGroups && {_deleteUnits+_size<=_maxUnits}) then {
                        _toDelete pushBack _grp;
                        _deleteUnits=_deleteUnits+_size;
                    };
                };
            };
        } else {
            _grp setVariable ["FST_HC_staleStart", -1];
        };
    };
} forEach FST_HC_TrackedGroups;

private _cleaned = 0;
private _deleted=[];
{
    private _grp = _x;
    if (isNull _grp || {[_grp] call _protected}) then { continue };

    private _vehicles = [];
    private _looseUnits = [];

    {
        if (isNull _x) then { continue };
        _x setVariable ["FST_skipSpawnDamage", true];
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
                _x setVariable ["FST_skipSpawnDamage", true];
                _veh deleteVehicleCrew _x;
            };
        } forEach crew _veh;
        deleteVehicle _veh;
    } forEach _vehicles;

    {
        if (!isNull _x) then {
            _x setVariable ["FST_skipSpawnDamage", true];
            deleteVehicle _x;
        };
    } forEach _looseUnits;

    _grp setVariable ["FST_HC_tracked", nil];
    _grp setVariable ["FST_HC_onHC", nil];
    _cleaned = _cleaned + 1;
    _deleted pushBack _grp;
} forEach _toDelete;

if (_cleaned > 0) then {
    FST_HC_TrackedGroups = FST_HC_TrackedGroups - _deleted;
    diag_log format ["[FST_HCSpawn] Cleanup: despawned %1 groups", _cleaned];
    [] call FST_HCSpawn_fnc_recountUnits;
};
