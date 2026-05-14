// FST_HCSpawn_fnc_trackGroup
// Server-side. Marks a group as tracked and updates bookkeeping.
// Arguments:
//   0: GROUP
//   1: NUMBER - HC index
//   2: BOOL   - true if FST_HC_UnitCounts was already pre-incremented

if (!isServer) exitWith {};

params ["_group", ["_hcIndex", -1], ["_preCounted", false], ["_attempt", 0], ["_protectionSeconds", 30]];

private _groupRef = _group;
if (_group isEqualType "") then {
    _group = groupFromNetId _group;
};

if (isNull _group) exitWith {
    if (_attempt < 10) then {
        [{
            params ["_groupRef", "_hcIndex", "_preCounted", "_attempt", "_protectionSeconds"];
            [_groupRef, _hcIndex, _preCounted, _attempt + 1, _protectionSeconds] call FST_HCSpawn_fnc_trackGroup;
        }, [_groupRef, _hcIndex, _preCounted, _attempt, _protectionSeconds], 0.5] call CBA_fnc_waitAndExecute;
    } else {
        diag_log format ["[FST_HCSpawn] TrackGroup failed: unresolved group ref %1 for HC index %2", _groupRef, _hcIndex];
        [] call FST_HCSpawn_fnc_recountUnits;
    };
};
if (_hcIndex < 0 || {_hcIndex >= count FST_HC_Ids}) exitWith {};

private _unitCount = count units _group;
if (_unitCount == 0) exitWith {};

if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };
FST_HC_TrackedGroups pushBackUnique _group;

private _existing = _group getVariable ["FST_HC_tracked", []];
private _wasTracked = count _existing > 0;
private _oldIdx = if (_wasTracked) then { _existing select 0 } else { -1 };
private _oldCount = if (_wasTracked) then { _existing select 1 } else { 0 };

// Mark as tracked. Keep this server-local in normal play; debug snapshot is requested on demand.
_group setVariable ["FST_HC_tracked", [_hcIndex, _unitCount]];
_group setVariable ["FST_HC_onHC", _hcIndex];
_group setVariable ["FST_HC_pendingTransfer", nil];
_group setVariable ["FST_HC_interceptQueued", nil, true];
if ((_group getVariable ["FST_HC_spawnProtectedUntil", -1]) < time) then {
    _group setVariable ["FST_HC_spawnProtectedUntil", time + (_protectionSeconds max 0)];
};

if (!_wasTracked) then {
    FST_HC_TrackedCount = FST_HC_TrackedCount + 1;
    if (!_preCounted) then {
        FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _unitCount];
    };
} else {
    // If a tracked group moved between HCs, correct the live balancing counts.
    if (_oldIdx != _hcIndex) then {
        if (_oldIdx >= 0 && {_oldIdx < count FST_HC_UnitCounts}) then {
            FST_HC_UnitCounts set [_oldIdx, ((FST_HC_UnitCounts select _oldIdx) - _oldCount) max 0];
        };
        if (!_preCounted) then {
            FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _unitCount];
        };
    } else {
        // Same HC, unit count changed. Reconcile without waiting for the 30s recount.
        if (!_preCounted) then {
            FST_HC_UnitCounts set [_hcIndex, ((FST_HC_UnitCounts select _hcIndex) - _oldCount + _unitCount) max 0];
        };
    };
};
