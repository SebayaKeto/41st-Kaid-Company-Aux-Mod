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

private _group = createGroup [EAST, true];
_group deleteGroupWhenEmpty true;

{
    _x params ["_pos", "_class"];

    private _unit = _group createUnit [_class, _pos, [], 0, "NONE"];
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

_group setBehaviourStrong "COMBAT";
_group setCombatMode "RED";

// Register Zeus editability on the server, not on the HC.
private _editableObjects = units _group;
if (count _editableObjects > 0) then {
    if (isServer) then {
        { _x addCuratorEditableObjects [_editableObjects, true]; } forEach allCurators;
    } else {
        ["FST_HC_evt_addEditableObjects", [_editableObjects]] call CBA_fnc_serverEvent;
    };
};

// Track on server
if (_isOnHC) then {
    ["FST_HC_evt_trackGroup", [_group, _hcIndex, true]] call CBA_fnc_serverEvent;
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
