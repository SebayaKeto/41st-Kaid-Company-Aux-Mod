// FST_HCSpawn_fnc_getSpawnTarget
// Server-side. Returns the owner ID of the least-loaded HC.
// Falls back to 2 (server) if no valid HCs are connected.
//
// Returns: NUMBER — owner ID

if (!isServer) exitWith { 2 };

if (count FST_HC_Array == 0 || {count FST_HC_Ids == 0}) exitWith { 2 };

// Guard against transient registration/disconnect drift.
private _validIndexes = [];
{
    private _hcObj = _x;
    private _hcId = if (_forEachIndex < count FST_HC_Ids) then { FST_HC_Ids select _forEachIndex } else { -1 };
    if (!isNull _hcObj && {_hcId > 2}) then {
        _validIndexes pushBack _forEachIndex;
    };
} forEach FST_HC_Array;

if (count _validIndexes == 0) exitWith { 2 };

// Ensure counts exists for every HC before select.
while {count FST_HC_UnitCounts < count FST_HC_Ids} do {
    FST_HC_UnitCounts pushBack 0;
};

private _minIdx = _validIndexes select 0;
private _minCount = FST_HC_UnitCounts select _minIdx;

{
    private _count = FST_HC_UnitCounts select _x;
    if (_count < _minCount) then {
        _minIdx = _x;
        _minCount = _count;
    };
} forEach _validIndexes;

FST_HC_Ids select _minIdx
