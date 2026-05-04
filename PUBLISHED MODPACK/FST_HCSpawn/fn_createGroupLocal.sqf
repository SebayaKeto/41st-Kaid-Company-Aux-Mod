// FST_HCSpawn_fnc_createGroupLocal
// Runs on target (HC or server). Creates units, applies behavior, registers.

params ["_side", "_unitClasses", "_pos", "_behavior", "_radius", "_vehData", "_isOnHC", "_targetId", "_hcIndex", ["_unitData", []], ["_sourceOwner", -1]];

// Ensure ground-level position
_pos = [_pos select 0, _pos select 1, 0];

private _group = createGroup [_side, true];
if (isNull _group) exitWith {
    diag_log format ["[FST_HCSpawn] createGroupLocal failed: createGroup returned grpNull for side %1 behavior %2 at %3", _side, _behavior, _pos];
};
private _editableObjects = [];

if (count _vehData > 0) then {
    private _vehType = _vehData select 0;
    private _vehPos = _vehData select 1;
    private _vehDir = if (count _vehData > 2) then { _vehData select 2 } else { 0 };
    private _vehUp = if (count _vehData > 3) then { _vehData select 3 } else { [0,0,1] };

    private _veh = _vehType createVehicle _vehPos;
    if (isNull _veh) exitWith {
        diag_log format ["[FST_HCSpawn] Vehicle clone failed: createVehicle returned null for %1", _vehType];
    };
    _veh setPosATL _vehPos;
    _veh setDir _vehDir;
    _veh setVectorUp _vehUp;
    createVehicleCrew _veh;

    // crew _veh is empty for ~1 frame after createVehicleCrew on a dedicated
    // server/HC. joinSilent + setVariable on an empty crew silently does
    // nothing, leaving the group with zero units when the rest of the function
    // tries to track/edit it. Sleep past the frame.
    sleep 0.1;

    (crew _veh) joinSilent _group;
    {
        _x setVariable ["FST_HC_created", true, true];
        _x setVariable ["FST_HC_spawnSettlingUntil", time + 10, true];
        _x setVariable ["FST_spawnDamageDeferUntilLocal", true, true];
    } forEach crew _veh;
    _editableObjects pushBack _veh;
} else {
    if (count _unitData > 0) then {
        {
            _x params ["_class", ["_rel", [0,0,0]], ["_dir", 0], ["_rank", "PRIVATE"], ["_skill", 0.5], ["_unitPos", "AUTO"]];
            private _spawnPos = _pos vectorAdd _rel;
            private _unit = _group createUnit [_class, _spawnPos, [], 0, "CAN_COLLIDE"];
            if (isNull _unit) then {
                diag_log format ["[FST_HCSpawn] Unit clone failed: createUnit returned null for %1", _class];
                continue;
            };
            _unit setVariable ["FST_HC_created", true, true];
            _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10, true];
            _unit setVariable ["FST_spawnDamageDeferUntilLocal", true, true];
            _unit setPosATL _spawnPos;
            _unit setDir _dir;
            _unit setRank _rank;
            _unit setSkill _skill;
            if (_unitPos != "AUTO") then { _unit setUnitPos _unitPos; };
            if (count _x > 6) then {
                private _loadout = _x select 6;
                if (count _loadout > 0) then { _unit setUnitLoadout _loadout; };
            };
            if (_forEachIndex == 0) then { _group selectLeader _unit; };
        } forEach _unitData;
    } else {
        {
            private _offset = [(_pos select 0) + random 10 - 5, (_pos select 1) + random 10 - 5, 0];
            private _unit = _group createUnit [_x, _offset, [], 0, "NONE"];
            if (isNull _unit) then {
                diag_log format ["[FST_HCSpawn] Unit spawn failed: createUnit returned null for %1", _x];
                continue;
            };
            _unit setVariable ["FST_HC_created", true, true];
            _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10, true];
            _unit setVariable ["FST_spawnDamageDeferUntilLocal", true, true];
            if (_forEachIndex == 0) then { _group selectLeader _unit; };
        } forEach _unitClasses;
    };
};

if (count units _group == 0) exitWith {
    if (FST_HC_DebugLogging) then {
        diag_log format ["[FST_HCSpawn] createGroupLocal produced empty group for behavior %1 at %2; deleting empty group", _behavior, _pos];
    };
    deleteGroup _group;
};

_editableObjects append units _group;

// Register Zeus editability on the server, not on the HC.
if (count _editableObjects > 0) then {
    if (isServer) then {
        { _x addCuratorEditableObjects [_editableObjects, true]; } forEach allCurators;
    } else {
        ["FST_HC_evt_addEditableObjects", [_editableObjects]] call CBA_fnc_serverEvent;
    };
};

// Apply behavior after settling
[{
    params ["_group", "_behavior", "_radius", "_pos"];
    if (isNull _group || {count units _group == 0}) exitWith {};

    switch (_behavior) do {
        case "garrison": {
            private _buildings = nearestObjects [_pos, ["House", "Building"], _radius];
            private _priorityPositions = [];
            private _buildingPositions = [];

            // 3AS garrison points (hand-placed — highest priority)
            private _3asPoints = _pos nearObjects ["3as_GarrisonPoint", _radius];
            { _priorityPositions pushBack (getPosATL _x); } forEach _3asPoints;

            // CBA building positions (hand-placed — high priority)
            private _cbaPoints = _pos nearObjects ["CBA_BuildingPos", _radius];
            { _priorityPositions pushBack (getPosATL _x); } forEach _cbaPoints;

            // Standard buildingPos (fill remainder)
            {
                private _bldg = _x;
                private _i = 0;
                private _bp = _bldg buildingPos _i;
                while { !(_bp isEqualTo [0,0,0]) } do {
                    _buildingPositions pushBack _bp;
                    _i = _i + 1;
                    _bp = _bldg buildingPos _i;
                };
            } forEach _buildings;

            _buildingPositions = _buildingPositions call BIS_fnc_arrayShuffle;
            private _bldgPositionsRaw = _priorityPositions + _buildingPositions;
            private _bldgPositions = _bldgPositionsRaw select { [_x] call FST_HCSpawn_fnc_isSafeGarrisonPos };
            private _rejectedGarrisonPositions = (count _bldgPositionsRaw) - (count _bldgPositions);
            if (_rejectedGarrisonPositions > 0 && {FST_HC_DebugLogging}) then {
                diag_log format ["[FST_HCSpawn] Garrison behavior skipped %1 unsafe/floating/over-water positions near %2", _rejectedGarrisonPositions, _pos];
            };
            private _units = units _group;
            {
                if (_forEachIndex < count _bldgPositions) then {
                    private _bPos = _bldgPositions select _forEachIndex;
                    _x setPosATL _bPos;
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
            _group enableDynamicSimulation true;

            // Cleanup floating/unsafe positions after 10s
            [{
                params ["_grp"];
                if (isNull _grp) exitWith {};
                private _toDelete = [];
                {
                    private _ap = _x getVariable ["FST_HC_assignedPos", []];
                    if (count _ap == 0) then { continue };
                    if ((abs ((getPosATL _x select 2) - (_ap select 2)) > 1) || {!([_ap] call FST_HCSpawn_fnc_isSafeGarrisonPos)}) then {
                        _toDelete pushBack _x;
                    };
                } forEach units _grp;
                { _x setVariable ["FST_skipSpawnDamage", true, true]; deleteVehicle _x; } forEach _toDelete;
                if (count _toDelete > 0) then {
                    if (FST_HC_DebugLogging) then {
                        diag_log format ["[FST_HCSpawn] Garrison cleanup: removed %1 floating/unsafe droids", count _toDelete];
                    };
                    if (!isServer) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; } else { [] call FST_HCSpawn_fnc_recountUnits; };
                };
            }, [_group], 10] call CBA_fnc_waitAndExecute;
        };
        case "assault": {
            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";
            [_group, _pos, _radius] call lambs_wp_fnc_taskRush;
        };
        case "hunt": {
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
            _group enableDynamicSimulation true;
        };
        case "none": {};
    };
}, [_group, _behavior, _radius, _pos], 1] call CBA_fnc_waitAndExecute;

// Dynamic simulation only for mobile groups
if (_behavior in ["patrol", "hunt"]) then {
    _group enableDynamicSimulation true;
};

// Track on server
if (_isOnHC) then {
    private _preCounted = true;
    if ((count _unitData == 0) && {count _vehData > 0}) then { _preCounted = false; };
    ["FST_HC_evt_trackGroup", [_group, _hcIndex, _preCounted]] call CBA_fnc_serverEvent;
};

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Created group %1: %2 units, %3", _group, count units _group, _behavior];
};
