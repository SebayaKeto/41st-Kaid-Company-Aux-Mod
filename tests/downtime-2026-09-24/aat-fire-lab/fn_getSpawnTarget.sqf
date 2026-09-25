// FST_HCSpawn_fnc_getSpawnTarget
// Server-side. Returns the owner ID of the HC that should receive a spawn or
// transfer. Falls back to 2 (server) if no valid HCs are connected.
//
// Arguments (V28):
//   0: STRING - "infantry" (default) or "vehicle"
//
// "infantry": least-loaded HC. When a dedicated vehicle HC is configured and
//   FST_HC_VehicleHCExclusive is on, that HC is left out as long as at least
//   one other HC is available.
// "vehicle": the dedicated vehicle HC when it is connected, otherwise the
//   least-loaded HC (same rules as infantry, so nothing breaks with 3 HCs).
//
// Returns: NUMBER -- owner ID

if (!isServer) exitWith { 2 };

params [["_kind", "infantry"], ["_requested", 0]];
_requested = _requested max 0;

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

// V28: dedicated vehicle HC.
private _vehHC = [] call FST_HCSpawn_fnc_getVehicleHC;
_vehHC params ["_vehId", "_vehIdx"];
if (_kind == "vehicle" && {_vehIdx >= 0} && {_vehIdx in _validIndexes}) then { _validIndexes = [_vehIdx]; };
if (_kind != "vehicle" && {_vehIdx >= 0} && {missionNamespace getVariable ["FST_HC_VehicleHCExclusive", true]}) then {
    private _others = _validIndexes - [_vehIdx];
    if (count _others > 0) then { _validIndexes = _others; };
};

private _softCap = missionNamespace getVariable ["FST_HC_PerHCSoftCap", 0];
if (_softCap > 0 && {missionNamespace getVariable ["FST_HC_BlockSpawnWhenAllHCSoftCapped", false]}) then {
    private _belowCap = _validIndexes select { ((FST_HC_UnitCounts select _x) < _softCap) && {((FST_HC_UnitCounts select _x) + _requested) <= _softCap} };
    if (count _belowCap > 0) then {
        _validIndexes = _belowCap;
    } else {
        // Throttled: this is called per transfer attempt / per spawn, and while
        // capped it used to write one EMERGENCY line per call.
        private _last = missionNamespace getVariable ["FST_HC_SoftCapLastLog", -999];
        if ((time - _last) >= 30) then {
            missionNamespace setVariable ["FST_HC_SoftCapLastLog", time];
            diag_log format ["[FST_HCSpawn][EMERGENCY] All HCs are over soft cap %1. Blocking new HC targets instead of overloading. counts=%2 ids=%3", _softCap, FST_HC_UnitCounts, FST_HC_Ids];
        };
        _validIndexes = [];
    };
};
if (count _validIndexes == 0) exitWith { 2 };

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
