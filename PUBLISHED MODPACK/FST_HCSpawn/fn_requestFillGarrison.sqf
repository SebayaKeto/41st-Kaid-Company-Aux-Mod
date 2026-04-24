// FST_HCSpawn_fnc_requestFillGarrison
// Server-side. Scans buildings, splits positions into groups of 12,
// and distributes each group to a different HC via the load balancer.
//
// Arguments:
//   0: POSITION — center
//   1: NUMBER   — scan radius
//   2: NUMBER   — density (0.0-1.0)
//   3: NUMBER   — B2 ratio (0.0-1.0)

if (!isServer) exitWith {};

params ["_center", "_radius", "_density", "_b2Ratio"];

// --- Scan buildings for garrison positions ---
private _buildings = nearestObjects [_center, ["House", "Building"], _radius];
private _allPositions = [];

{
    private _building = _x;
    private _i = 0;
    private _pos = _building buildingPos _i;
    while { !(_pos isEqualTo [0,0,0]) } do {
        _allPositions pushBack _pos;
        _i = _i + 1;
        _pos = _building buildingPos _i;
    };
} forEach _buildings;

if (count _allPositions == 0) exitWith {
    "[FST] No building positions found." remoteExec ["systemChat", -2];
};

// --- Apply density filter ---
_allPositions = _allPositions call BIS_fnc_arrayShuffle;
private _fillCount = ceil (count _allPositions * _density) max 1;

// AI cap check
if (!([_fillCount] call FST_HCSpawn_fnc_canSpawn)) exitWith {
    "[FST] AI cap reached — fill garrison blocked." remoteExec ["systemChat", -2];
};

private _positions = _allPositions select [0, _fillCount];

// --- Assign unit classes to each position ---
private _b1Pool = ["FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5",
    "FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_E5","FST_Droid_B1_AR"];
private _b2Pool = ["FST_B2","FST_B2","FST_B2_TL"];

private _assignments = [];  // [[pos, class], [pos, class], ...]
{
    private _class = if (random 1 < _b2Ratio) then { selectRandom _b2Pool } else { selectRandom _b1Pool };
    _assignments pushBack [_x, _class];
} forEach _positions;

// --- Split into batches of 12 and distribute across HCs ---
private _totalSpawned = count _assignments;
private _batchCount = 0;

for "_i" from 0 to (count _assignments - 1) step 12 do {
    private _batch = _assignments select [_i, 12 min (count _assignments - _i)];

    // Pick target HC — pre-increment so next batch goes elsewhere
    private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
    private _isOnHC = _targetId != 2;
    private _hcIndex = if (_isOnHC) then { FST_HC_Ids find _targetId } else { -1 };

    if (_hcIndex >= 0 && _hcIndex < count FST_HC_UnitCounts) then {
        FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + count _batch];
    };

    // Send batch to target
    [_batch, _isOnHC, _targetId, _hcIndex] remoteExecCall ["FST_HCSpawn_fnc_fillGarrison", _targetId];
    _batchCount = _batchCount + 1;
};

private _msg = format ["[FST] Garrisoned %1 droids, %2 buildings, %3 groups across HCs",
    _totalSpawned, count _buildings, _batchCount];
_msg remoteExec ["systemChat", -2];
diag_log _msg;
