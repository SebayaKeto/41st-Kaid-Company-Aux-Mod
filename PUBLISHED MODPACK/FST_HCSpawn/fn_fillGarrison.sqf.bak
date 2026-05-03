// FST_HCSpawn_fnc_fillGarrison
// Runs on target (HC or server). Creates one group from a batch of
// position/class assignments. Each unit is placed at its exact buildingPos.
// After 3 seconds, any unit that drifted from its assigned position is deleted.

params ["_batch", "_isOnHC", "_targetId", "_hcIndex"];

if (count _batch == 0) exitWith {};

private _group = createGroup [EAST, true];

{
    _x params ["_pos", "_class"];

    private _unit = _group createUnit [_class, _pos, [], 0, "NONE"];
    _unit setPos _pos;
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

// Floating droid cleanup
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

        if (abs (_actualZ - _assignedZ) > 1) then {
            _toDelete pushBack _x;
        };
    } forEach units _group;

    {
        deleteVehicle _x;
        _removed = _removed + 1;
    } forEach _toDelete;

    if (_removed > 0 && {FST_HC_DebugLogging}) then {
        diag_log format ["[FST_HCSpawn] Fill garrison cleanup: removed %1 floating droids from group %2", _removed, _group];
    };
}, [_group], 3] call CBA_fnc_waitAndExecute;
