// FST_HCSpawn_fnc_registerHC
// Server-side. Called by an HC via CBA event.
// Registers the HC in the tracking arrays.

if (!isServer) exitWith {};

params ["_hcObj", "_hcId"];

if (isNull _hcObj) exitWith {
    diag_log format ["[FST_HCSpawn] HC registration ignored: null object, owner %1", _hcId];
};
if (_hcId <= 2) exitWith {
    diag_log format ["[FST_HCSpawn] HC registration ignored: invalid owner %1 for %2", _hcId, _hcObj];
};

// Prefer owner ID for duplicate detection; object references can change after reconnects.
private _existingIdx = FST_HC_Ids find _hcId;
if (_existingIdx == -1) then { _existingIdx = FST_HC_Array find _hcObj; };

if (_existingIdx != -1) then {
    FST_HC_Array set [_existingIdx, _hcObj];
    FST_HC_Ids set [_existingIdx, _hcId];
    diag_log format ["[FST_HCSpawn] HC refreshed: %1 (owner %2, index %3)", _hcObj, _hcId, _existingIdx];
} else {
    FST_HC_Array pushBack _hcObj;
    FST_HC_Ids pushBack _hcId;
    FST_HC_UnitCounts pushBack 0;
    diag_log format ["[FST_HCSpawn] HC registered: %1 (owner %2, index %3)", _hcObj, _hcId, count FST_HC_Array - 1];
};

publicVariable "FST_HC_Array";
publicVariable "FST_HC_Ids";

private _hcIndex = FST_HC_Array find _hcObj;
private _label = format ["HC%1", _hcIndex + 1];
[_label, 10, _hcIndex + 1] remoteExec ["FST_HCSpawn_fnc_fpsMonitor", _hcId];

// Don't broadcast a hint to all players on every HC registration. With 2 HCs
// connecting 1-3s apart at op start, players were getting two stacked hints
// during loading. RPT log is sufficient for operator visibility.
diag_log format ["[FST_HCSpawn] HC%1 connected (owner %2)", _hcIndex + 1, _hcId];
