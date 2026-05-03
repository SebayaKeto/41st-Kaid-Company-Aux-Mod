// FST_HCSpawn_fnc_requestFillGarrison
// Server-side. Scans buildings, splits positions into groups of 12,
// distributes each group to a different HC.
//
// Arguments:
//   0: POSITION — center
//   1: NUMBER   — scan radius
//   2: NUMBER   — density (0.0-1.0)
//   3: NUMBER   — B2 ratio (0.0-1.0)
//   4: NUMBER   — requesting client owner ID
//   5: STRING   — optional B1 replacement class; empty string keeps default B1 pool

if (!isServer) exitWith {};

params ["_center", "_radius", "_density", "_b2Ratio", ["_callerID", -2], ["_b1Replacement", "", [""]]];

// Clamp user-facing values and validate client-provided classnames server-side.
_radius = (_radius max 25) min 500;
_density = (_density max 0.1) min 1;
_b2Ratio = (_b2Ratio max 0) min 1;

// Garrison dispatch throttle. These can be overridden from debug/server init.
// The old behavior was 12 units every 0.3s. That is very fast for 300+ AI fills.
private _batchSize = missionNamespace getVariable ["FST_HC_FillGarrisonBatchSize", 8];
private _batchDelay = missionNamespace getVariable ["FST_HC_FillGarrisonBatchDelay", 0.75];
_batchSize = (_batchSize max 4) min 12;
_batchDelay = (_batchDelay max 0.3) min 2;

if !(_b1Replacement isEqualTo "") then {
    if !([_b1Replacement] call FST_HCSpawn_fnc_isValidFSTOpforUnit) then {
        private _msg = format ["[FST] Fill Garrison blocked invalid B1 replacement: %1", _b1Replacement];
        _msg remoteExec ["systemChat", _callerID];
        diag_log format ["[FST_HCSpawn] %1 requested invalid Fill Garrison B1 replacement: %2", _callerID, _b1Replacement];
        _b1Replacement = "";
    };
};

// Ensure ground-level position for scanning (ZEN passes ASL)
_center = [_center select 0, _center select 1, 0];

// --- Scan all garrison positions (hand-placed first, then buildingPos) ---
private _buildings = nearestObjects [_center, ["House", "Building"], _radius];
private _priorityPositions = [];
private _buildingPositions = [];

// 3AS garrison points (hand-placed — highest priority)
private _3asPoints = _center nearObjects ["3as_GarrisonPoint", _radius];
{ _priorityPositions pushBack (getPosATL _x); } forEach _3asPoints;

// CBA building positions (hand-placed — high priority)
private _cbaPoints = _center nearObjects ["CBA_BuildingPos", _radius];
{ _priorityPositions pushBack (getPosATL _x); } forEach _cbaPoints;

// Standard buildingPos (auto-generated — fill remainder)
{
    private _building = _x;
    private _i = 0;
    private _pos = _building buildingPos _i;
    while { !(_pos isEqualTo [0,0,0]) } do {
        _buildingPositions pushBack _pos;
        _i = _i + 1;
        _pos = _building buildingPos _i;
    };
} forEach _buildings;

// Shuffle only buildingPos — hand-placed points keep their order
_buildingPositions = _buildingPositions call BIS_fnc_arrayShuffle;

// Combine: priority first, then shuffled buildingPos
private _allPositionsRaw = _priorityPositions + _buildingPositions;
private _rawPositionCount = count _allPositionsRaw;

// Filter unsafe over-water/floating positions before we create anything.
// This prevents fill garrison from spawning/deleting hundreds of units on invalid positions.
private _allPositions = _allPositionsRaw select {
    [_x] call FST_HCSpawn_fnc_isSafeGarrisonPos
};
private _rejectedWaterPositions = _rawPositionCount - count _allPositions;

if (_rejectedWaterPositions > 0) then {
    diag_log format ["[FST_HCSpawn] Fill Garrison skipped %1 unsafe/floating/over-water positions near %2", _rejectedWaterPositions, _center];
};

if (count _allPositions == 0) exitWith {
    private _msg = if (_rawPositionCount > 0) then {
        format ["[FST] No safe garrison positions found. Skipped %1 unsafe/floating/over-water positions.", _rejectedWaterPositions]
    } else {
        "[FST] No garrison positions found."
    };
    _msg remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison aborted at %1: no safe positions. raw=%2 rejected=%3", _center, _rawPositionCount, _rejectedWaterPositions];
};

// --- Density filter (cuts from the end — buildingPos trimmed first) ---
private _fillCount = ceil (count _allPositions * _density) max 1;

// AI cap check
private _cap = FST_HC_AICap;
if (_cap > 0) then {
    private _total = 0;
    { _total = _total + _x; } forEach FST_HC_UnitCounts;
    if (_total + _fillCount > _cap) exitWith {
        "[FST] AI cap reached — fill garrison blocked." remoteExec ["systemChat", _callerID];
    };
};

private _positions = _allPositions select [0, _fillCount];

// --- Assign classes ---
private _b1Pool = ["FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5",
    "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR"];
private _b2Pool = ["FST_B2","FST_B2","FST_B2_TL"];

private _assignments = [];
{
    private _class = if (random 1 < _b2Ratio) then {
        selectRandom _b2Pool
    } else {
        if (_b1Replacement isEqualTo "") then { selectRandom _b1Pool } else { _b1Replacement }
    };
    _assignments pushBack [_x, _class];
} forEach _positions;

// --- Staggered dispatch ---
[_assignments, _buildings, _callerID, _b1Replacement, _batchSize, _batchDelay] spawn {
    params ["_assignments", "_buildings", "_callerID", "_b1Replacement", "_batchSize", "_batchDelay"];
    private _batchCount = 0;

    for "_i" from 0 to (count _assignments - 1) step _batchSize do {
        private _batch = _assignments select [_i, _batchSize min (count _assignments - _i)];

        private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
        private _isOnHC = _targetId != 2;
        private _hcIndex = if (_isOnHC) then { FST_HC_Ids find _targetId } else { -1 };

        if (_hcIndex >= 0 && _hcIndex < count FST_HC_UnitCounts) then {
            FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + count _batch];
        };

        private _args = [_batch, _isOnHC, _targetId, _hcIndex];
        if (_isOnHC) then {
            private _hcId = FST_HC_Ids select _hcIndex;
            ["FST_HC_evt_fillBatch", _args, _hcId] call CBA_fnc_ownerEvent;
        } else {
            _args call FST_HCSpawn_fnc_fillGarrison;
        };
        _batchCount = _batchCount + 1;

        sleep _batchDelay;
    };

    private _replacementText = if (_b1Replacement isEqualTo "") then { "default B1 mix" } else { _b1Replacement };
    private _msg = format ["[FST] Garrisoned %1 units, %2 buildings, %3 groups — B1: %4",
        count _assignments, count _buildings, _batchCount, _replacementText];
    _msg remoteExec ["systemChat", _callerID];
    diag_log _msg;
};
