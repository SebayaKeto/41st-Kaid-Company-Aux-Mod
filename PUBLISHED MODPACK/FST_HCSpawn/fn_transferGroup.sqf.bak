// FST_HCSpawn_fnc_transferGroup
// Server-side. Transfers a single group to the least-loaded HC.
// Handles garrison detection, loadout preservation, and tracking.
//
// Arguments:
//   0: GROUP
// Returns: BOOL - true if already on/confirmed moved to an HC

if (!isServer) exitWith { false };

params ["_group"];

if (isNull _group) exitWith { false };
if (count units _group == 0) exitWith { false };
if (isPlayer leader _group) exitWith { false };
if (count FST_HC_Array == 0) exitWith { false };
if ([_group] call FST_HCSpawn_fnc_isBlacklisted) exitWith { false };

private _leader = leader _group;
private _units = units _group;
private _vehicle = vehicle _leader;

// Already owned by one of our HCs — just track it.
private _currentOwner = groupOwner _group;
if (_currentOwner in FST_HC_Ids) exitWith {
    private _idx = FST_HC_Ids find _currentOwner;
    [_group, _idx, false] call FST_HCSpawn_fnc_trackGroup;
    true
};

// Pick target HC.
private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
private _hcIndex = FST_HC_Ids find _targetId;
if (_hcIndex < 0) exitWith { false };

// Detect garrison state before locality changes.
private _isGarrisoned = !(_leader checkAIFeature "PATH");

// Save loadouts. Mandatory because locality changes can strip/alter custom gear on some modded units.
{ _x setVariable ["FST_HC_savedLoadout", getUnitLoadout _x]; } forEach _units;

// Lock crewed vehicle briefly during transfer.
if (!isNull _vehicle && {_vehicle != _leader}) then { _vehicle lock true; };

private _beforeOwner = groupOwner _group;
private _moved = _group setGroupOwner _targetId;
private _afterOwner = groupOwner _group;

// setGroupOwner may return false if the engine refuses the locality change.
// Treat either a true return OR confirmed owner match as success, because some
// edge cases report false even though ownership has already settled by the check.
if (!_moved && {_afterOwner != _targetId}) exitWith {
    if (!isNull _vehicle && {_vehicle != _leader}) then { _vehicle lock false; };
    FST_HC_TransferFailures = (missionNamespace getVariable ["FST_HC_TransferFailures", 0]) + 1;
    if (FST_HC_DebugLogging) then {
        diag_log format ["[FST_HCSpawn] setGroupOwner failed for %1 to owner %2. Before: %3 After: %4", _group, _targetId, _beforeOwner, _afterOwner];
    };
    false
};

FST_HC_TransferSuccesses = (missionNamespace getVariable ["FST_HC_TransferSuccesses", 0]) + 1;

// Dynamic simulation only for mobile groups.
if (!_isGarrisoned) then {
    _group enableDynamicSimulation true;
};

// Track. This is not a pre-counted HC-created group, so allow trackGroup to add
// the units into the balancing count immediately.
[_group, _hcIndex, false] call FST_HCSpawn_fnc_trackGroup;

// Reapply garrison on the machine that now owns the group.
if (_isGarrisoned) then {
    ["FST_HC_evt_reapplyGarrison", [_group], _targetId] call CBA_fnc_ownerEvent;
};

// Restore loadouts on the machine that NOW owns the group. Running this on the
// server (where the units are no longer local) silently fails — setUnitLoadout
// is an effects-local command. Send the payload to the target owner; the HC
// handler waits a beat for locality to settle before applying.
private _payload = [];
{
    private _lo = _x getVariable ["FST_HC_savedLoadout", []];
    if (count _lo > 0) then { _payload pushBack [_x, _lo]; };
} forEach _units;
if (count _payload > 0) then {
    ["FST_HC_evt_restoreLoadout", [_payload], _targetId] call CBA_fnc_ownerEvent;
};

// Unlock vehicle.
if (!isNull _vehicle && {_vehicle != _leader}) then {
    [{ params ["_v"]; if (!isNull _v) then { _v lock false; }; }, [_vehicle], 0.5] call CBA_fnc_waitAndExecute;
};

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Transferred %1 (%2 units) to HC index %3 owner %4. Before owner: %5", _group, count units _group, _hcIndex, _targetId, _beforeOwner];
};

true
