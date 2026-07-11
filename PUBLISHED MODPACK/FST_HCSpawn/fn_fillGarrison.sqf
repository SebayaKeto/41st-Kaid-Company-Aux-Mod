// FST_HCSpawn_fnc_fillGarrison
// Runs on target (HC or server). Creates one group from a batch of
// position/class assignments. Each unit is placed at its exact buildingPos.
// After 10 seconds, unsafe/floating units are marked and deleted.

params ["_batch", "_isOnHC", "_targetId", "_hcIndex"];

if (count _batch == 0) exitWith {};

// Last-second safety filter. requestFillGarrison already filters, but this protects
// direct event calls and stale/odd building positions on the HC itself.
private _originalBatchCount = count _batch;
_batch = _batch select { [(_x select 0)] call FST_HCSpawn_fnc_isSafeGarrisonPos };
private _rejectedHere = _originalBatchCount - count _batch;
if (_rejectedHere > 0 && {FST_HC_DebugLogging}) then {
    diag_log format ["[FST_HCSpawn] Fill batch skipped %1 unsafe/floating/over-water positions on target", _rejectedHere];
};
if (count _batch == 0) exitWith {
    if (!isServer) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; } else { [] call FST_HCSpawn_fnc_recountUnits; };
};

missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time, true];

private _group = createGroup [EAST, true];
private _requestedUnitCount = count _batch;
if (isNull _group) exitWith {
    diag_log format ["[FST_HCSpawn] Fill garrison batch failed: createGroup returned grpNull for %1 units", count _batch];
    if (!isServer) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; } else { [] call FST_HCSpawn_fnc_recountUnits; };
};
_group deleteGroupWhenEmpty true;
_group setVariable ["FST_HC_spawnProtectedUntil", time + 90];

{
    _x params ["_pos", "_class"];

    private _unit = _group createUnit [_class, _pos, [], 0, "NONE"];
    if (isNull _unit) then {
        diag_log format ["[FST_HCSpawn] Fill garrison unit failed: createUnit returned null for %1", _class];
        continue;
    };
    _unit setPosATL _pos;
    _unit setVariable ["FST_HC_created", true, true];
    _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10, true];
    _unit setVariable ["FST_spawnDamageDeferUntilLocal", true, true];
    _unit setVariable ["FST_HC_assignedPos", _pos];
    _unit disableAI "PATH";
    _unit setUnitPos "UP";
    doStop _unit;
    _unit setFormDir (random 360);

    if (_forEachIndex == 0) then { _group selectLeader _unit; };
} forEach _batch;

if (count units _group == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Fill garrison batch produced zero units from %1 assignments", count _batch];
    if (!isServer) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; } else { [] call FST_HCSpawn_fnc_recountUnits; };
    deleteGroup _group;
};

private _createdUnitCount = count units _group;
private _partialBatch = _createdUnitCount < _requestedUnitCount;
if (_partialBatch) then {
    diag_log format ["[FST_HCSpawn] Fill garrison partial batch: created %1/%2 units", _createdUnitCount, _requestedUnitCount];
    // Do NOT recount before this fresh HC group has been tracked. The server
    // pre-counted the requested batch; an early recount would wipe that reservation,
    // then trackGroup(preCounted=true) would not add the actually-created units.
    // A delayed recount is scheduled after the track request below.
};

_group setBehaviourStrong "COMBAT";
_group setCombatMode "RED";
if (missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]) then {
    _group enableDynamicSimulation true;
};

// Register Zeus editability on the server, not on the HC. Send netIds from HCs
// and let the server retry because fresh HC-spawned objects can arrive one beat late.
private _editableObjects = units _group;
if (count _editableObjects > 0) then {
    if (isServer) then {
        { _x addCuratorEditableObjects [_editableObjects, true]; } forEach allCurators;
    } else {
        [_editableObjects] spawn {
            params ["_editableObjects"];
            private _expectedEditableCount = count _editableObjects;
            private _deadline = time + 4.0;
            private _editableNetIds = [];
            waitUntil {
                _editableObjects = _editableObjects select { !isNull _x };
                _editableNetIds = (_editableObjects apply { netId _x }) select { !(_x isEqualTo "") };
                ((count _editableNetIds) >= _expectedEditableCount) || {time >= _deadline}
            };
            if ((count _editableNetIds) < _expectedEditableCount) then {
                diag_log format ["[FST_HCSpawn] Fill garrison editable registration partial: %1/%2 objects had netIds before deadline", count _editableNetIds, _expectedEditableCount];
            };
            if (count _editableNetIds > 0) then {
                ["FST_HC_evt_addEditableObjects", [_editableNetIds, 0]] call CBA_fnc_serverEvent;
            };
        };
    };
};

// Track on server. Use group netId + retry on server to avoid racing fresh HC groups.
if (_isOnHC) then {
    [_group, _hcIndex, _partialBatch] spawn {
        params ["_group", "_hcIndex", "_partialBatch"];
        private _deadline = time + 3.5;
        private _groupRef = "";
        waitUntil {
            if (!isNull _group) then { _groupRef = netId _group; };
            isNull _group || {!(_groupRef isEqualTo "") || {time >= _deadline}}
        };
        if (isNull _group) exitWith { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; };
        if (_groupRef isEqualTo "") exitWith {
            diag_log format ["[FST_HCSpawn] Fill garrison track delayed: group %1 had no netId after wait; relying on catch-all/recount", _group];
            ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent;
        };
        ["FST_HC_evt_trackGroup", [_groupRef, _hcIndex, true, 0, 90]] call CBA_fnc_serverEvent;

        // If the batch partially failed, let the server track the group first,
        // then recount so FST_HC_UnitCounts converges to the actual created count.
        if (_partialBatch) then {
            [{ ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; }, [], 1] call CBA_fnc_waitAndExecute;
        };
    };
};

// Floating/unsafe droid cleanup
[{
    params ["_group"];
    if (isNull _group) exitWith {};

    private _removed = 0;
    private _toDelete = [];

    {
        private _assigned = _x getVariable ["FST_HC_assignedPos", []];
        if (count _assigned == 0) then { continue };

        private _actualZ = (getPosATL _x) select 2;
        private _assignedZ = _assigned select 2;

        if ((abs (_actualZ - _assignedZ) > 1) || {!([_assigned] call FST_HCSpawn_fnc_isSafeGarrisonPos)}) then {
            _toDelete pushBack _x;
        };
    } forEach units _group;

    {
        _x setVariable ["FST_skipSpawnDamage", true, true];
        deleteVehicle _x;
        _removed = _removed + 1;
    } forEach _toDelete;

    if (_removed > 0) then {
        if (FST_HC_DebugLogging) then {
            diag_log format ["[FST_HCSpawn] Fill garrison cleanup: removed %1 floating/unsafe droids from group %2", _removed, _group];
        };
        // The server pre-counts fill-garrison batches before the HC creates them.
        // If this cleanup deletes units, force bookkeeping to converge immediately.
        if (!isServer) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; } else { [] call FST_HCSpawn_fnc_recountUnits; };
    };
}, [_group], 10] call CBA_fnc_waitAndExecute;
