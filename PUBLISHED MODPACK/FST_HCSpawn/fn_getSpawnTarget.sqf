// FST_HCSpawn_fnc_getSpawnTarget
// Server-side. Returns the owner ID of the least-loaded HC.
// Falls back to 2 (server) if no HCs connected.
//
// Returns: NUMBER — owner ID

if (!isServer) exitWith { 2 };

if (count FST_HC_Array == 0) exitWith { 2 };

// Find least loaded by bookkeeping counts — no allUnits scan
private _minIdx = 0;
private _minCount = FST_HC_UnitCounts select 0;

{
    if (_x < _minCount) then {
        _minIdx = _forEachIndex;
        _minCount = _x;
    };
} forEach FST_HC_UnitCounts;

FST_HC_Ids select _minIdx
