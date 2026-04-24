// FST_HCSpawn_fnc_cleanupGroups
// Server-side PFH. Two-phase despawn:
//
// Phase 1 — ACTIVATION: A group becomes "activated" when non-air players
//           have been within engagement range. Until then, the group is
//           untouchable — it will never despawn.
//
// Phase 2 — STALE TIMER: Once activated, if no ground players are within
//           the despawn radius for the full stale timer duration (default
//           10 minutes), the group is deleted.
//
// This ensures droids waiting at an untouched objective are never cleaned
// up, but droids left behind after a fight are eventually removed.

if (!isServer) exitWith {};
if (!FST_HC_DespawnEnabled) exitWith {};

private _engageRadius = FST_HC_DespawnEngageRadius;
private _despawnRadius = FST_HC_DespawnRadius;
private _staleTime = FST_HC_DespawnTimer;
private _toDelete = [];

{
    private _grp = _x;
    private _data = _y;

    // Clean up dead/empty groups from the hashmap
    if (isNull _grp || {count units _grp == 0}) then {
        _toDelete pushBack _grp;
        continue;
    };

    private _leader = leader _grp;
    private _pos = getPosATL _leader;
    private _activated = _grp getVariable ["FST_HC_activated", false];

    // --- Find nearby ground players (exclude air vehicles) ---
    // Non-activated groups only need the smaller engagement radius check
    // Activated groups need the full despawn radius
    private _searchRadius = if (_activated) then { _despawnRadius } else { _engageRadius };
    private _nearAll = _pos nearEntities ["CAManBase", _searchRadius];
    private _groundPlayers = _nearAll select {
        isPlayer _x
        && alive _x
        && !(vehicle _x isKindOf "Air")
    };

    // --- Phase 1: Check for activation ---
    if (!_activated) then {
        // nearEntities already searched at _engageRadius for non-activated groups
        if (count _groundPlayers > 0) then {
            _grp setVariable ["FST_HC_activated", true];
            _activated = true;
        };
    };

    // --- Phase 2: Stale timer (only for activated groups) ---
    if (_activated) then {
        // nearEntities already searched at _despawnRadius for activated groups
        if (count _groundPlayers == 0) then {
            // No ground players — start or continue stale timer
            private _staleStart = _grp getVariable ["FST_HC_staleStart", -1];

            if (_staleStart < 0) then {
                _grp setVariable ["FST_HC_staleStart", time];
            } else {
                if (time - _staleStart >= _staleTime) then {
                    _toDelete pushBack _grp;
                };
            };
        } else {
            // Ground players present — reset timer
            _grp setVariable ["FST_HC_staleStart", -1];
        };
    };

} forEach FST_HC_GroupMap;

// Delete outside forEach
private _cleaned = 0;
{
    if (!isNull _x && {count units _x > 0}) then {
        {
            private _veh = vehicle _x;
            if (_veh != _x) then { deleteVehicle _veh; };
            deleteVehicle _x;
        } forEach units _x;
        _cleaned = _cleaned + 1;
    };

    FST_HC_GroupMap deleteAt _x;
} forEach _toDelete;

if (_cleaned > 0) then {
    diag_log format ["[FST_HCSpawn] Cleanup: despawned %1 activated groups (stale %2s)", _cleaned, _staleTime];
    [] call FST_HCSpawn_fnc_recountUnits;
};
