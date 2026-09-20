// FST_HCSpawn_fnc_transferGroup
// Server-side. Transfers a single group to the least-loaded HC.
// Handles garrison detection, loadout preservation, and tracking.
//
// Arguments:
//   0: GROUP
// Returns: BOOL - true if already on/confirmed moved to an HC

if (!isServer) exitWith { false };
// V28: _force (from the Zeus "Send To Vehicle HC" module) bypasses the vehicle
// blacklist, never the vehicle safety check.
params ["_group", ["_force", false]];

if (isNull _group) exitWith { false };
if (count units _group == 0) exitWith { false };
if (isPlayer leader _group) exitWith { false };
if (count FST_HC_Array == 0) exitWith { false };
if (!_force && {!(_group getVariable ["FST_HC_rehome", false])} && {[_group] call FST_HCSpawn_fnc_isBlacklisted}) exitWith { false };
// V27: Zeus-held groups are never transferred by any path.
if ((_group getVariable ["FST_HC_heldBy", -1]) != -1) exitWith { false };

private _leader = leader _group;
private _units = units _group;
private _vehicle = vehicle _leader;

// V28: mounted groups go to the vehicle HC, and only when it is safe (stopped,
// landed, whole crew in this group). Anything else is left for a later sweep.
private _isVehicleGroup = (_units findIf { vehicle _x != _x }) >= 0;
private _kind = if (_isVehicleGroup) then { "vehicle" } else { "infantry" };

// Already owned by one of our HCs -- just track it, unless this is a foot
// group being moved off the vehicle HC (dismounted QRF passengers).
private _currentOwner = groupOwner _group;
private _rehome = _group getVariable ["FST_HC_rehome", false];
_group setVariable ["FST_HC_rehome", nil];
if (_currentOwner in FST_HC_Ids) then {
    private _vehIdx = ([] call FST_HCSpawn_fnc_getVehicleHC) select 1;
    private _onVehicleHC = (_vehIdx >= 0) && {(FST_HC_Ids find _currentOwner) == _vehIdx};
    if (!(_rehome && {!_isVehicleGroup} && {_onVehicleHC} && {missionNamespace getVariable ["FST_HC_VehicleHCExclusive", true]})) then {
        _rehome = false;
    };
};
if ((_currentOwner in FST_HC_Ids) && {!_rehome}) exitWith {
    private _idx = FST_HC_Ids find _currentOwner;
    [_group, _idx, false] call FST_HCSpawn_fnc_trackGroup;
    true
};

if (_isVehicleGroup) then {
    private _check = [_group] call FST_HCSpawn_fnc_isVehicleTransferSafe;
    if !(_check select 0) then {
        if (FST_HC_DebugLogging) then {
            diag_log format ["[FST_HCSpawn] Vehicle group %1 not transferred: %2", _group, _check select 1];
        };
        _kind = "";
    };
};
if (_kind == "") exitWith { false };
if (_rehome && {FST_HC_DebugLogging}) then { diag_log format ["[FST_HCSpawn] Re-homing foot group %1 off the vehicle HC", _group]; };

// Pick target HC.
private _targetId = [_kind] call FST_HCSpawn_fnc_getSpawnTarget;
private _hcIndex = FST_HC_Ids find _targetId;
if (_hcIndex < 0) exitWith { false };
if (_targetId == _currentOwner) exitWith {
    [_group, _hcIndex, false] call FST_HCSpawn_fnc_trackGroup;
    true
};

// Detect garrison state before locality changes.
private _isGarrisoned = !(_leader checkAIFeature "PATH");

// Save loadouts. Mandatory because locality changes can strip/alter custom gear on some modded units.
{ _x setVariable ["FST_HC_savedLoadout", getUnitLoadout _x]; } forEach _units;

// Lock crewed vehicle briefly during transfer, then restore whatever lock state
// Zeus/mission had set (the old code always ended with lock false).
private _hasVehicle = !isNull _vehicle && {_vehicle != _leader};
private _prevLock = if (_hasVehicle) then { locked _vehicle } else { 0 };
if (_hasVehicle) then { _vehicle lock true; };

private _beforeOwner = groupOwner _group;
private _moved = _group setGroupOwner _targetId;
private _afterOwner = groupOwner _group;

// setGroupOwner may return false if the engine refuses the locality change.
// Treat either a true return OR confirmed owner match as success, because some
// edge cases report false even though ownership has already settled by the check.
if (!_moved && {_afterOwner != _targetId}) exitWith {
    if (_hasVehicle) then { _vehicle lock _prevLock; };
    FST_HC_TransferFailures = (missionNamespace getVariable ["FST_HC_TransferFailures", 0]) + 1;
    if (FST_HC_DebugLogging) then {
        diag_log format ["[FST_HCSpawn] setGroupOwner failed for %1 to owner %2. Before: %3 After: %4", _group, _targetId, _beforeOwner, _afterOwner];
    };
    false
};

FST_HC_TransferSuccesses = (missionNamespace getVariable ["FST_HC_TransferSuccesses", 0]) + 1;

// Dynamic simulation only for mobile groups, and only when opted in.
// This was the main freeze path: catchUntracked sweeps EVERY untracked AI group
// (editor-placed, third-party scripts, everything) through here whenever HCs are
// connected, and this call runs on the server, whose dyn-sim manager globally
// disables any flagged group with no player inside its activation distance.
if (!_isGarrisoned && {missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]}) then {
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
// server (where the units are no longer local) silently fails -- setUnitLoadout
// is an effects-local command. Send the payload to the target owner; the HC
// handler waits a beat for locality to settle and only re-applies if gear was stripped.
private _payload = [];
{
    private _lo = _x getVariable ["FST_HC_savedLoadout", []];
    if (count _lo > 0) then { _payload pushBack [_x, _lo]; };
} forEach _units;
if (count _payload > 0) then {
    ["FST_HC_evt_restoreLoadout", [_payload], _targetId] call CBA_fnc_ownerEvent;
};
// The stabilizer is a no-op when the bandaid is off; skip the network event entirely then.
if (missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", false]) then {
    ["FST_HC_evt_emergencyStabilizeGroupLocal", [_group], _targetId] call CBA_fnc_ownerEvent;
};

// Restore vehicle lock state.
if (_hasVehicle) then {
    [{ params ["_v", "_l"]; if (!isNull _v) then { _v lock _l; }; }, [_vehicle, _prevLock], 0.5] call CBA_fnc_waitAndExecute;
};

// V28: confirm every vehicle followed its crew. A crew/vehicle owner split is
// the exact failure the safety check exists to prevent; log it if it happens.
if (_isVehicleGroup) then {
    [{
        params ["_group", "_targetId"];
        if (isNull _group) exitWith {};
        private _split = [];
        {
            private _v = vehicle _x;
            if (_v != _x && {owner _v != _targetId}) then { _split pushBackUnique _v; };
        } forEach units _group;
        if (count _split > 0) then {
            diag_log format ["[FST_HCSpawn][WARN] Vehicle/crew owner split after transfer of %1 to owner %2: %3 (owners %4)", _group, _targetId, _split apply { typeOf _x }, _split apply { owner _x }];
        };
    }, [_group, _targetId], 2] call CBA_fnc_waitAndExecute;
};

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Transferred %1 (%2 units) to HC index %3 owner %4. Before owner: %5", _group, count units _group, _hcIndex, _targetId, _beforeOwner];
};

true
