// FST_HCSpawn_fnc_createGroupLocal
// Runs on target (HC or server). Creates units, applies behavior, registers.

params ["_side", "_unitClasses", "_pos", "_behavior", "_radius", "_vehData", "_isOnHC", "_targetId", "_hcIndex"];

// Ensure ground-level position
_pos = [_pos select 0, _pos select 1, 0];

private _group = createGroup [_side, true];

if (count _vehData > 0) then {
    private _veh = (_vehData select 0) createVehicle (_vehData select 1);
    createVehicleCrew _veh;
    (crew _veh) joinSilent _group;
    { _x addCuratorEditableObjects [[_veh], true]; } forEach allCurators;
} else {
    {
        private _offset = [(_pos select 0) + random 10 - 5, (_pos select 1) + random 10 - 5, 0];
        private _unit = _group createUnit [_x, _offset, [], 0, "NONE"];
        if (_forEachIndex == 0) then { _group selectLeader _unit; };
    } forEach _unitClasses;
};

// Apply behavior after settling
[{
    params ["_group", "_behavior", "_radius", "_pos"];
    if (isNull _group || {count units _group == 0}) exitWith {};

    switch (_behavior) do {
        case "garrison": {
            private _buildings = nearestObjects [_pos, ["House", "Building"], _radius];
            private _bldgPositions = [];

            // Standard buildingPos
            {
                private _bldg = _x;
                private _i = 0;
                private _bp = _bldg buildingPos _i;
                while { !(_bp isEqualTo [0,0,0]) } do {
                    _bldgPositions pushBack _bp;
                    _i = _i + 1;
                    _bp = _bldg buildingPos _i;
                };
            } forEach _buildings;

            // 3AS garrison points
            private _3asPoints = nearestObjects [_pos, ["3as_GarrisonPoint"], _radius];
            { _bldgPositions pushBack (getPosATL _x); } forEach _3asPoints;

            // CBA building positions
            private _cbaPoints = nearestObjects [_pos, ["CBA_BuildingPos"], _radius];
            { _bldgPositions pushBack (getPosATL _x); } forEach _cbaPoints;

            _bldgPositions = _bldgPositions call BIS_fnc_arrayShuffle;
            private _units = units _group;
            {
                if (_forEachIndex < count _bldgPositions) then {
                    private _bPos = _bldgPositions select _forEachIndex;
                    _x setPos _bPos;
                    _x setVariable ["FST_HC_assignedPos", _bPos];
                    _x disableAI "PATH";
                    _x setUnitPos "UP";
                    doStop _x;
                    _x setFormDir (random 360);
                } else {
                    _x disableAI "PATH";
                    _x setUnitPos "UP";
                    doStop _x;
                };
            } forEach _units;

            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";

            // Cleanup floaters after 3s
            [{
                params ["_grp"];
                if (isNull _grp) exitWith {};
                private _toDelete = [];
                {
                    private _ap = _x getVariable ["FST_HC_assignedPos", []];
                    if (count _ap == 0) then { continue };
                    if (abs ((getPosATL _x select 2) - (_ap select 2)) > 1) then {
                        _toDelete pushBack _x;
                    };
                } forEach units _grp;
                { deleteVehicle _x; } forEach _toDelete;
                if (count _toDelete > 0) then {
                    diag_log format ["[FST_HCSpawn] Garrison cleanup: removed %1 floating droids", count _toDelete];
                };
            }, [_group], 3] call CBA_fnc_waitAndExecute;
        };
        case "assault": {
            // LAMBS assault — droids attack nearest known enemies
            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";
            [_group, _pos, _radius] call lambs_wp_fnc_taskRush;
        };
        case "hunt": {
            // LAMBS hunt — droids advance searching for enemies
            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";
            [_group, _pos, _radius] call lambs_wp_fnc_taskHunt;
        };
        case "patrol":  {
            [_group, _pos, _radius] call lambs_wp_fnc_taskPatrol;
        };
        case "static": {
            _group setBehaviourStrong "COMBAT";
            { _x setUnitPos "UP"; doStop _x; } forEach units _group;
        };
        case "none": {};
    };
}, [_group, _behavior, _radius, _pos], 1] call CBA_fnc_waitAndExecute;

// Add to curators
{ _x addCuratorEditableObjects [units _group, true]; } forEach allCurators;

// Dynamic simulation only for mobile groups
if (_behavior in ["patrol", "hunt"]) then {
    _group enableDynamicSimulation true;
};

// Track on server
if (_isOnHC) then {
    ["FST_HC_evt_trackGroup", [_group, _hcIndex]] call CBA_fnc_serverEvent;
};

diag_log format ["[FST_HCSpawn] Created group %1: %2 units, %3", _group, count units _group, _behavior];
