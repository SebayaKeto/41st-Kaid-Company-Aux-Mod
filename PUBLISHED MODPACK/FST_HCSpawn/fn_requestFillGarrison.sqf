// FST_HCSpawn_fnc_requestFillGarrison
// Server-side. Scans buildings, limits the fill to a safe budget,
// splits positions into small batches, and distributes each batch to an HC.
//
// Safety goals:
// - Never let Fill Garrison run indefinitely in the background.
// - Never allow one click to queue an unbounded number of AI.
// - Avoid overlapping Fill Garrison jobs.
// - Keep large bases usable by filling a capped sample instead of every slot.
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

// ============================================================
// HARD SAFETY SETTINGS
// ============================================================
// These are CBA settings from preInit, but missionNamespace defaults let this
// function survive if an old CBA profile has not saved the new values yet.

private _maxUnits = missionNamespace getVariable ["FST_HC_FillGarrisonMaxUnits", 120];
private _maxDuration = missionNamespace getVariable ["FST_HC_FillGarrisonMaxDuration", 90];
private _maxScanPositions = missionNamespace getVariable ["FST_HC_FillGarrisonMaxScanPositions", 900];
private _singleActive = missionNamespace getVariable ["FST_HC_FillGarrisonSingleActive", true];
private _cooldown = missionNamespace getVariable ["FST_HC_FillGarrisonCooldown", 10];

_maxUnits = round ((_maxUnits max 24) min 120);
_maxDuration = (_maxDuration max 30) min 120;
_maxScanPositions = round ((_maxScanPositions max _maxUnits) min 2400);
_cooldown = (_cooldown max 0) min 60;

private _blockWithoutHC = missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true];
if (_blockWithoutHC && {count FST_HC_Array == 0}) exitWith {
    "[FST] Fill Garrison blocked: no headless clients are connected." remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison blocked with no HCs connected. caller=%1 center=%2 radius=%3", _callerID, _center, _radius];
};

// Clamp user-facing values and validate client-provided classnames server-side.
_radius = (_radius max 25) min 500;
_density = (_density max 0.1) min 1;
_b2Ratio = (_b2Ratio max 0) min 1;

// Garrison dispatch throttle. These can be overridden from CBA/debug/server init.
private _batchSize = missionNamespace getVariable ["FST_HC_FillGarrisonBatchSize", 8];
private _batchDelay = missionNamespace getVariable ["FST_HC_FillGarrisonBatchDelay", 1.25];
_batchSize = round ((_batchSize max 4) min 8);
_batchDelay = (_batchDelay max 0.5) min 2.5;

private _now = time;
private _existingActive = missionNamespace getVariable ["FST_HC_FillGarrisonActive", false];
private _existingDeadline = missionNamespace getVariable ["FST_HC_FillGarrisonDeadline", -1];
private _nextAllowed = missionNamespace getVariable ["FST_HC_FillGarrisonNextAllowed", -1];

// Clear stale active state if a previous job somehow died without cleanup.
if (_existingActive && {_now >= _existingDeadline}) then {
    missionNamespace setVariable ["FST_HC_FillGarrisonActive", false, true];
    missionNamespace setVariable ["FST_HC_FillGarrisonDeadline", -1, true];
    _existingActive = false;
    diag_log format ["[FST_HCSpawn] Fill Garrison stale active state cleared at %1", _center];
};

if (_singleActive && {_existingActive}) exitWith {
    private _remaining = ceil ((_existingDeadline - _now) max 0);
    private _msg = format ["[FST] Fill Garrison blocked: another fill is still running. Hard timeout in %1s.", _remaining];
    _msg remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison request blocked while active. caller=%1 center=%2 remaining=%3", _callerID, _center, _remaining];
};

if (_singleActive && {_now < _nextAllowed}) exitWith {
    private _remaining = ceil ((_nextAllowed - _now) max 0);
    private _msg = format ["[FST] Fill Garrison cooling down. Try again in %1s.", _remaining];
    _msg remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison request blocked by cooldown. caller=%1 center=%2 remaining=%3", _callerID, _center, _remaining];
};

private _jobId = (missionNamespace getVariable ["FST_HC_FillGarrisonJobId", 0]) + 1;
private _deadline = _now + _maxDuration;
missionNamespace setVariable ["FST_HC_FillGarrisonJobId", _jobId, true];
missionNamespace setVariable ["FST_HC_FillGarrisonActive", true, true];
missionNamespace setVariable ["FST_HC_FillGarrisonDeadline", _deadline, true];

private _clearJob = {
    params ["_jobId", ["_cooldown", 0]];
    if ((missionNamespace getVariable ["FST_HC_FillGarrisonJobId", -1]) isEqualTo _jobId) then {
        missionNamespace setVariable ["FST_HC_FillGarrisonActive", false, true];
        missionNamespace setVariable ["FST_HC_FillGarrisonDeadline", -1, true];
        missionNamespace setVariable ["FST_HC_FillGarrisonNextAllowed", time + _cooldown, true];
        missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time, true];
    };
};

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

// ============================================================
// SCAN POSITIONS WITH A CANDIDATE CAP
// ============================================================

private _scanStart = diag_tickTime;
private _buildings = nearestObjects [_center, ["House", "Building"], _radius];
private _priorityPositions = [];
private _buildingPositions = [];
private _scanLimited = false;

// 3AS garrison points (hand-placed — highest priority)
private _3asPoints = _center nearObjects ["3as_GarrisonPoint", _radius];
{
    if (count _priorityPositions >= _maxScanPositions) exitWith { _scanLimited = true; };
    _priorityPositions pushBack (getPosATL _x);
} forEach _3asPoints;

// CBA building positions (hand-placed — high priority)
if (!_scanLimited) then {
    private _cbaPoints = _center nearObjects ["CBA_BuildingPos", _radius];
    {
        if ((count _priorityPositions) >= _maxScanPositions) exitWith { _scanLimited = true; };
        _priorityPositions pushBack (getPosATL _x);
    } forEach _cbaPoints;
};

// Standard buildingPos (auto-generated — fill remainder)
if (!_scanLimited) then {
    {
        if ((count _priorityPositions + count _buildingPositions) >= _maxScanPositions) exitWith { _scanLimited = true; };

        private _building = _x;
        private _i = 0;
        private _pos = _building buildingPos _i;
        while {
            !(_pos isEqualTo [0,0,0]) &&
            {(count _priorityPositions + count _buildingPositions) < _maxScanPositions}
        } do {
            _buildingPositions pushBack _pos;
            _i = _i + 1;
            _pos = _building buildingPos _i;
        };
    } forEach _buildings;
};

// Shuffle only buildingPos — hand-placed points keep their order
_buildingPositions = _buildingPositions call BIS_fnc_arrayShuffle;

// Combine: priority first, then shuffled buildingPos
private _allPositionsRaw = _priorityPositions + _buildingPositions;
private _rawPositionCount = count _allPositionsRaw;

// Filter unsafe over-water/floating positions before we create anything.
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
    [_jobId, _cooldown] call _clearJob;
};

// ============================================================
// DENSITY + HARD UNIT CAP + AI CAP
// ============================================================

private _requestedFillCount = ceil (count _allPositions * _density) max 1;
private _fillCount = _requestedFillCount min _maxUnits;
private _trimReasons = [];

if (_requestedFillCount > _fillCount) then {
    _trimReasons pushBack format ["unit cap %1/%2", _fillCount, _requestedFillCount];
};

if (_scanLimited) then {
    _trimReasons pushBack format ["scan cap %1 candidates", _maxScanPositions];
};

// AI cap check. Truncate to available budget instead of silently exceeding.
private _capAbort = false;
private _cap = FST_HC_AICap;
if (_cap > 0) then {
    private _total = 0;
    { _total = _total + _x; } forEach FST_HC_UnitCounts;

    private _available = _cap - _total;
    if (_available <= 0) then {
        _capAbort = true;
    } else {
        if (_fillCount > _available) then {
            _fillCount = _available;
            _trimReasons pushBack format ["AI cap available %1/%2", _available, _cap];
        };
    };
};

if (_capAbort || {_fillCount <= 0}) exitWith {
    "[FST] AI cap reached — fill garrison blocked." remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison blocked by AI cap. center=%1 requested=%2 cap=%3", _center, _requestedFillCount, _cap];
    [_jobId, _cooldown] call _clearJob;
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

private _scanMs = round ((diag_tickTime - _scanStart) * 1000);
private _trimText = if (_trimReasons isEqualTo []) then { "none" } else { _trimReasons joinString ", " };

private _startMsg = format ["[FST] Fill Garrison queued %1 units in %2m radius. Limits: %3.", count _assignments, round _radius, _trimText];
_startMsg remoteExec ["systemChat", _callerID];
diag_log format ["[FST_HCSpawn] Fill Garrison job %1 started. center=%2 radius=%3 buildings=%4 raw=%5 safe=%6 rejected=%7 queued=%8 requested=%9 scanMs=%10 limits='%11'",
    _jobId, _center, _radius, count _buildings, _rawPositionCount, count _allPositions, _rejectedWaterPositions, count _assignments, _requestedFillCount, _scanMs, _trimText
];

// ============================================================
// STAGGERED DISPATCH WITH HARD DEADLINE
// ============================================================

[_assignments, _buildings, _callerID, _b1Replacement, _batchSize, _batchDelay, _jobId, _deadline, _cooldown, _trimText] spawn {
    params ["_assignments", "_buildings", "_callerID", "_b1Replacement", "_batchSize", "_batchDelay", "_jobId", "_deadline", "_cooldown", "_trimText"];

    private _batchCount = 0;
    private _queuedUnits = 0;
    private _timedOut = false;
    private _cancelled = false;

    for "_i" from 0 to (count _assignments - 1) step _batchSize do {
        if !((missionNamespace getVariable ["FST_HC_FillGarrisonJobId", -1]) isEqualTo _jobId) exitWith {
            _cancelled = true;
        };

        if (time >= _deadline) exitWith {
            _timedOut = true;
        };

        private _batch = _assignments select [_i, _batchSize min (count _assignments - _i)];

        if ((missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true]) && {count FST_HC_Array == 0}) exitWith {
            _cancelled = true;
            diag_log format ["[FST_HCSpawn] Fill Garrison job %1 stopped because all HCs disconnected at %2/%3 units", _jobId, _queuedUnits, count _assignments];
        };

        missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time, true];

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
        _queuedUnits = _queuedUnits + count _batch;

        sleep _batchDelay;
    };

    if ((missionNamespace getVariable ["FST_HC_FillGarrisonJobId", -1]) isEqualTo _jobId) then {
        missionNamespace setVariable ["FST_HC_FillGarrisonActive", false, true];
        missionNamespace setVariable ["FST_HC_FillGarrisonDeadline", -1, true];
        missionNamespace setVariable ["FST_HC_FillGarrisonNextAllowed", time + _cooldown, true];
        missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time, true];
    };

    private _replacementText = if (_b1Replacement isEqualTo "") then { "default B1 mix" } else { _b1Replacement };
    private _endText = if (_timedOut) then {
        format ["HARD TIMEOUT at %1/%2 units", _queuedUnits, count _assignments]
    } else {
        if (_cancelled) then {
            format ["cancelled at %1/%2 units", _queuedUnits, count _assignments]
        } else {
            format ["complete: %1 units", _queuedUnits]
        }
    };

    private _msg = format ["[FST] Fill Garrison %1, %2 batches, %3 buildings — B1: %4 — limits: %5",
        _endText, _batchCount, count _buildings, _replacementText, _trimText];
    _msg remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Fill Garrison job %1 %2. batches=%3 buildings=%4 b1=%5 limits='%6'",
        _jobId, _endText, _batchCount, count _buildings, _replacementText, _trimText];
};
