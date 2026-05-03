// FST_HCSpawn_fnc_cleanupGroups
// Server-side PFH. Two-phase despawn:
// Phase 1 — group activates when ground players come within engagement range
// Phase 2 — after activation, group deletes when no ground players nearby for stale timer

if (!isServer) exitWith {};
if (!FST_HC_DespawnEnabled) exitWith {};

private _engageRadius = FST_HC_DespawnEngageRadius;
private _despawnRadius = FST_HC_DespawnRadius;
private _staleTime = FST_HC_DespawnTimer;
private _toDelete = [];

{
    private _grp = _x;
    private _data = _grp getVariable ["FST_HC_tracked", []];
    if (count _data == 0) then { continue };

    if (isNull _grp || {count units _grp == 0}) then {
        _toDelete pushBack _grp;
        continue;
    };

    private _leader = leader _grp;
    private _pos = getPosATL _leader;
    private _activated = _grp getVariable ["FST_HC_activated", false];

    private _searchRadius = if (_activated) then { _despawnRadius } else { _engageRadius };
    private _nearAll = _pos nearEntities ["CAManBase", _searchRadius];
    private _groundPlayers = _nearAll select {
        isPlayer _x && alive _x && !(vehicle _x isKindOf "Air")
    };

    if (!_activated) then {
        if (count _groundPlayers > 0) then {
            _grp setVariable ["FST_HC_activated", true];
            _activated = true;
        };
    };

    if (_activated) then {
        if (count _groundPlayers == 0) then {
            private _staleStart = _grp getVariable ["FST_HC_staleStart", -1];
            if (_staleStart < 0) then {
                _grp setVariable ["FST_HC_staleStart", time];
            } else {
                if (time - _staleStart >= _staleTime) then {
                    _toDelete pushBack _grp;
                };
            };
        } else {
            _grp setVariable ["FST_HC_staleStart", -1];
        };
    };
} forEach allGroups;

private _cleaned = 0;
{
    if (!isNull _x && {count units _x > 0}) then {
        { private _v = vehicle _x; _x setVariable ["FST_skipSpawnDamage", true, true]; if (_v != _x) then { deleteVehicle _v; }; deleteVehicle _x; } forEach units _x;
        _cleaned = _cleaned + 1;
    };
    _x setVariable ["FST_HC_tracked", nil];
    _x setVariable ["FST_HC_onHC", nil];
} forEach _toDelete;

if (_cleaned > 0) then {
    diag_log format ["[FST_HCSpawn] Cleanup: despawned %1 groups", _cleaned];
    [] call FST_HCSpawn_fnc_recountUnits;
};
