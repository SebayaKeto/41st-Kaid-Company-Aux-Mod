// FST_HCSpawn_fnc_canSpawn
// Server-side. Checks if spawning is allowed based on the AI cap.
// Returns true if under cap or cap is disabled (0).
//
// Arguments:
//   0: NUMBER — number of units about to be spawned
// Returns: BOOL

if (!isServer) exitWith { true };

params [["_newUnits", 0]];

private _cap = FST_HC_AICap;

// 0 = no cap
if (_cap <= 0) exitWith { true };

// Count current total across all HCs + server-owned
private _total = 0;
{ _total = _total + _x; } forEach FST_HC_UnitCounts;

if (_total + _newUnits > _cap) exitWith {
    diag_log format ["[FST_HCSpawn] AI cap reached: %1 + %2 would exceed cap of %3", _total, _newUnits, _cap];
    false
};

true
