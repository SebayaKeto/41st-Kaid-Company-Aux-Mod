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

if (!isServer) exitWith {};

params ["_center", "_radius", "_density", "_b2Ratio", ["_callerID", -2]];

// --- Scan all garrison positions ---
private _buildings = nearestObjects [_center, ["House", "Building"], _radius];
private _allPositions = [];

// Standard buildingPos
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

// 3AS garrison points
private _3asPoints = nearestObjects [_center, ["3as_GarrisonPoint"], _radius];
{ _allPositions pushBack (getPosATL _x); } forEach _3asPoints;

// CBA building positions
private _cbaPoints = nearestObjects [_center, ["CBA_BuildingPos"], _radius];
{ _allPositions pushBack (getPosATL _x); } forEach _cbaPoints;

if (count _allPositions == 0) exitWith {
    "[FST] No garrison positions found." remoteExec ["systemChat", _callerID];
};

// --- Density filter ---
_allPositions = _allPositions call BIS_fnc_arrayShuffle;
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
    private _class = if (random 1 < _b2Ratio) then { selectRandom _b2Pool } else { selectRandom _b1Pool };
    _assignments pushBack [_x, _class];
} forEach _positions;

// --- Staggered dispatch ---
[_assignments, _buildings, _callerID] spawn {
    params ["_assignments", "_buildings", "_callerID"];
    private _batchCount = 0;

    for "_i" from 0 to (count _assignments - 1) step 12 do {
        private _batch = _assignments select [_i, 12 min (count _assignments - _i)];

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

        sleep 0.3;
    };

    private _msg = format ["[FST] Garrisoned %1 droids, %2 buildings, %3 groups",
        count _assignments, count _buildings, _batchCount];
    _msg remoteExec ["systemChat", _callerID];
    diag_log _msg;
};
