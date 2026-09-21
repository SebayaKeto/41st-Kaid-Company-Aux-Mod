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

// Check the engine's actual HC entity/owner before accepting registration.
if (!(_hcObj isKindOf "HeadlessClient_F") || {owner _hcObj != _hcId}) exitWith {
    diag_log format ["[FST_HCSpawn][AUTH] Rejected HC entity/owner mismatch: %1 / %2", _hcObj, _hcId];
};
// Stable mission slot, independent of connection order and array compaction.
private _slot = _hcObj getVariable ["FST_HC_slot", -1];
private _varName = toUpperANSI (vehicleVarName _hcObj);
if (_slot < 1 && {_varName in ["HC1","HC2","HC3","HC4","HC5","HC6","HC7","HC8"]}) then {
    _slot = parseNumber (_varName select [2]);
};
private _otherSlots = (FST_HC_Array - [_hcObj]) apply { _x getVariable ["FST_HC_slot", -1] };
if (_slot in _otherSlots) exitWith {
    diag_log format ["[FST_HCSpawn][WARN] Duplicate HC mission slot %1; registration refused", _slot];
};
if (_slot < 1) then {
    _slot = 1;
    while {_slot in _otherSlots} do { _slot = _slot + 1; };
    diag_log format ["[FST_HCSpawn][WARN] Unnamed HC assigned fallback slot %1. Name mission entities HC1..HC4 for stable roles.", _slot];
};
_hcObj setVariable ["FST_HC_slot", _slot, true];

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
private _label = format ["HC%1", _slot];
["FST_HC_evt_startFpsMonitor", [_label, 10, _slot], _hcId] call CBA_fnc_ownerEvent;

// Don't broadcast a hint to all players on every HC registration. With 2 HCs
// connecting 1-3s apart at op start, players were getting two stacked hints
// during loading. RPT log is sufficient for operator visibility.
diag_log format ["[FST_HCSpawn] HC%1 connected (owner %2)", _slot, _hcId];
