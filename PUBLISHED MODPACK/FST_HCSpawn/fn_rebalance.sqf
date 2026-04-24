// FST_HCSpawn_fnc_rebalance
// Server-side. Moves groups from the most-loaded HC to the least-loaded
// until the difference is below threshold.

if (!isServer) exitWith {};
if (count FST_HC_Array < 2) exitWith {};
if (FST_HC_EmergencyMode) exitWith {};

// Fresh recount before rebalancing
[] call FST_HCSpawn_fnc_recountUnits;

// Find most and least loaded
private _maxIdx = 0; private _maxCount = FST_HC_UnitCounts select 0;
private _minIdx = 0; private _minCount = FST_HC_UnitCounts select 0;

{
    if (_x > _maxCount) then { _maxIdx = _forEachIndex; _maxCount = _x; };
    if (_x < _minCount) then { _minIdx = _forEachIndex; _minCount = _x; };
} forEach FST_HC_UnitCounts;

private _diff = _maxCount - _minCount;

if (_diff < FST_HC_RebalanceThreshold) exitWith {
    diag_log format ["[FST_HCSpawn] Rebalance: diff %1 below threshold %2 — balanced", _diff, FST_HC_RebalanceThreshold];
};

diag_log format ["[FST_HCSpawn] Rebalancing: HC%1 has %2, HC%3 has %4, diff %5", _maxIdx, _maxCount, _minIdx, _minCount, _diff];

// Find groups on the overloaded HC that could move — collect first, modify later
private _toMove = [];
private _targetId = FST_HC_Ids select _minIdx;

{
    private _grp = _x;
    private _data = _y;
    if ((_data select 0) == _maxIdx) then {
        private _grpSize = count units _grp;
        if (_grpSize <= _diff / 2 && _grpSize > 0 && !isNull _grp) then {
            _toMove pushBack _grp;
            _diff = _diff - _grpSize * 2;
            if (_diff < FST_HC_RebalanceThreshold) then { break };
        };
    };
} forEach FST_HC_GroupMap;

// Now apply moves outside the forEach
private _moved = 0;
{
    private _grp = _x;
    FST_HC_GroupMap deleteAt _grp;

    private _isGarrisoned = !(leader _grp checkAIFeature "PATH");
    _grp setGroupOwner _targetId;
    [_grp, _minIdx] call FST_HCSpawn_fnc_trackGroup;

    if (_isGarrisoned) then {
        [_grp] remoteExecCall ["FST_HCSpawn_fnc_reapplyGarrison", _targetId];
    };

    _moved = _moved + 1;
} forEach _toMove;

// Recount after moves
[] call FST_HCSpawn_fnc_recountUnits;
diag_log format ["[FST_HCSpawn] Rebalance complete: moved %1 groups", _moved];
