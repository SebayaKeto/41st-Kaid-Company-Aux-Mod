// FST_HCSpawn_fnc_createGroupLocal
// Runs on target (HC or server). Creates units, applies behavior, registers.

if (!canSuspend) exitWith {_this spawn FST_HCSpawn_fnc_createGroupLocal};

params ["_side", "_unitClasses", "_pos", "_behavior", "_radius", "_vehData", "_isOnHC", "_targetId", "_hcIndex", ["_unitData", []], ["_sourceOwner", -1], ["_originalPayload", []], ["_heavyTicket", []]];

private _isZeusClone = (_sourceOwner > 2) && {count _originalPayload == 3};
private _buildDeadline=time+(if (_isZeusClone) then {4} else {30});
if (count _heavyTicket==2) then {_buildDeadline=_buildDeadline min (_heavyTicket select 1)};
private _sendZeusCloneDecision = {
    params ["_accepted"];
    if (_isZeusClone) then {
        if (isServer) then {
            [_originalPayload, _accepted] call FST_HCSpawn_fnc_handleZeusOriginalDecision;
        } else {
            ["FST_HC_evt_zeusOriginalDecisionServer", [_originalPayload, _accepted]] call CBA_fnc_serverEvent;
        };
    };
};

// A delayed request must not create heavy units after its reservation expires.
if (count _heavyTicket==2 && {time>=(_heavyTicket select 1)}) exitWith {
    [false] call _sendZeusCloneDecision;
    ["FST_heavyAck",[_heavyTicket,clientOwner,[]]] call CBA_fnc_serverEvent;
};

private _heavyClasses=if (count _vehData>0) then {[_vehData select 0]} else {if (count _unitData>0) then {_unitData apply {_x select 0}} else {_unitClasses}};
if ((_heavyClasses findIf {([_x] call FST_HCSpawn_fnc_heavyKind)>=0})>=0 && {_heavyTicket isEqualTo []}) exitWith {
    [false] call _sendZeusCloneDecision;
    diag_log "[FST_PERF] Unreserved heavy group rejected";
};

// Ensure ground-level position
_pos = [_pos select 0, _pos select 1, 0];

private _group = createGroup [_side, true];
// Engine-side removal of the empty group container once every member is dead
// and deleted. Dead-group auto-cleanup is manual-only in this build, so without
// this, wiped template/QRF/frontline groups linger as empty group objects for
// the whole op (allGroups growth + scheduler load). fn_fillGarrison already
// does the same.
_group deleteGroupWhenEmpty true;
_group setVariable ["FST_HC_spawnProtectedUntil", time + 90];
// Addon-created: eligible for despawn cleanup (server reads this).
_group setVariable ["FST_HC_managed", true, true];
private _editableObjects = [];

if (count _vehData > 0) then {
    // V28 extended form (from fn_spawnVehicleOnTarget):
    // [class, pos, dir, up, flying, skill, engineOn, combatMode, behaviour, target, tag]
    // The 4-element form is the Zeus instant-clone path and is unchanged.
    _vehData params ["_vehType", "_vehPos", ["_vehDir", 0], ["_vehUp", [0,0,1]], ["_flying", false], ["_crewSkill", -1], ["_engineOn", true], ["_combatMode", ""], ["_aiBehaviour", ""], ["_vehTarget", []], ["_tag", ""]];
    private _extended = count _vehData > 4;

    if !([_buildDeadline] call FST_HCSpawn_fnc_spawnPace) exitWith {};
    private _veh = if (_flying) then {
        createVehicle [_vehType, _vehPos, [], 0, "FLY"]
    } else {
        _vehType createVehicle _vehPos
    };
    if (isNull _veh) exitWith {
        diag_log format ["[FST_HCSpawn] Vehicle clone failed: createVehicle returned null for %1", _vehType];
        [false] call _sendZeusCloneDecision;
        if (_isOnHC) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; };
    };
    _veh setPosATL _vehPos;
    _veh setDir _vehDir;
    _veh setVectorUp _vehUp;
    if (_flying) then {
        _veh setVelocity ((vectorDir _veh) vectorMultiply 60);
    };
    createVehicleCrew _veh;

    // crew _veh is empty for ~1 frame after createVehicleCrew on a dedicated
    // server/HC. joinSilent + setVariable on an empty crew silently does
    // nothing, leaving the group with zero units when the rest of the function
    // tries to track/edit it. Sleep past the frame.
    sleep 0.1;

    (crew _veh) joinSilent _group;
    {
        _x setVariable ["FST_HC_created", true];
        _x setVariable ["FST_HC_spawnSettlingUntil", time + 10];
        _x setVariable ["FST_spawnDamageDeferUntilLocal", true];
        [_x] call FST_HCSpawn_fnc_emergencyStabilizeDroid;
        if (_crewSkill >= 0) then { _x setSkill _crewSkill; };
    } forEach crew _veh;
    if (_extended) then {
        _veh engineOn _engineOn;
        if (_combatMode != "") then { _group setCombatMode _combatMode; };
        if (_aiBehaviour != "") then { _group setBehaviourStrong _aiBehaviour; };
        if (count _vehTarget > 0) then { _group setVariable ["FST_HC_vehTarget", _vehTarget]; };
        if (_tag != "") then { _group setVariable ["FST_HC_spawnTag", _tag, true]; };
        _group setVariable ["FST_HC_vehicleGroup", true];
    };
    _editableObjects pushBack _veh;
} else {
    if (count _unitData > 0) then {
        {
            _x params ["_class", ["_rel", [0,0,0]], ["_dir", 0], ["_rank", "PRIVATE"], ["_skill", 0.5], ["_unitPos", "AUTO"]];
            private _spawnPos = _pos vectorAdd _rel;
            if !([_buildDeadline] call FST_HCSpawn_fnc_spawnPace) exitWith {};
            private _unit = _group createUnit [_class, _spawnPos, [], 0, "CAN_COLLIDE"];
            if (isNull _unit) then {
                diag_log format ["[FST_HCSpawn] Unit clone failed: createUnit returned null for %1", _class];
                continue;
            };
            // Local markers only; nothing on other machines reads them.
            _unit setVariable ["FST_HC_created", true];
            _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10];
            _unit setVariable ["FST_spawnDamageDeferUntilLocal", true];
            [_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid;
            _unit setPosATL _spawnPos;
            _unit setDir _dir;
            _unit setRank _rank;
            _unit setSkill _skill;
            if (_unitPos != "AUTO" && {([_unit] call FST_HCSpawn_fnc_burnsRole) != "webknight"}) then { _unit setUnitPos _unitPos; };
            if (count _x > 6) then {
                private _loadout = _x select 6;
                if (count _loadout > 0) then { [_unit, _loadout, _class, "instant clone"] call FST_HCSpawn_fnc_applyUnitLoadoutSafe; };
            };
            if (_forEachIndex == 0) then { _group selectLeader _unit; };
        } forEach _unitData;
    } else {
        {
            private _offset = [(_pos select 0) + random 10 - 5, (_pos select 1) + random 10 - 5, 0];
            if !([_buildDeadline] call FST_HCSpawn_fnc_spawnPace) exitWith {};
            private _unit = _group createUnit [_x, _offset, [], 0, "NONE"];
            if (isNull _unit) then {
                diag_log format ["[FST_HCSpawn] Unit spawn failed: createUnit returned null for %1", _x];
                continue;
            };
            // Local markers only; nothing on other machines reads them.
            _unit setVariable ["FST_HC_created", true];
            _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10];
            _unit setVariable ["FST_spawnDamageDeferUntilLocal", true];
            [_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid;
            if (_forEachIndex == 0) then { _group selectLeader _unit; };
        } forEach _unitClasses;
    };
};

_editableObjects append units _group;
if !(_heavyTicket isEqualTo []) then {
    ["FST_heavyAck",[_heavyTicket,clientOwner,_editableObjects]] call CBA_fnc_serverEvent;
};
[_group] call FST_HCSpawn_fnc_emergencyStabilizeGroup;

private _createdUnitCount = count units _group;
private _expectedReplacementUnits = if (count _unitData > 0) then { count _unitData } else { count _unitClasses };

// If an HC creation path produced no units, restore the original Zeus placement
// instead of letting the source client delete it. This must happen BEFORE Zeus
// editable registration/acceptance; a vehicle with no crew could otherwise
// register the vehicle and approve deletion before we reject the empty group.
if (_createdUnitCount == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Created group %1 had zero units. Rejecting clone/track request. behavior=%2", _group, _behavior];
    [false] call _sendZeusCloneDecision;
    if (_isOnHC) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; };
    deleteGroup _group;
};

// Instant Zeus clone/replace should be all-or-nothing. If one unit class fails to
// create, restore the original instead of deleting a full Zeus group and leaving a
// partial HC clone behind. Module/server spawns may still tolerate partial classes.
if (_isZeusClone && {_expectedReplacementUnits > 0} && {_createdUnitCount < _expectedReplacementUnits}) exitWith {
    diag_log format ["[FST_HCSpawn] Zeus clone rejected: partial group created %1/%2 units. behavior=%3 group=%4", _createdUnitCount, _expectedReplacementUnits, _behavior, _group];
    [false] call _sendZeusCloneDecision;
    {
        if (!isNull _x) then {
            _x setVariable ["FST_skipSpawnDamage", true];
            deleteVehicle _x;
        };
    } forEach units _group;
    if (_isOnHC) then { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; };
    deleteGroup _group;
};

// Register Zeus editability on the server, not on the HC. For instant
// clone/replace, server-side editable registration is also the approval point
// for deleting the hidden Zeus original. HC-created objects may need a beat before
// netIds are usable, so HCs wait briefly and then send only non-empty netIds.
if (count _editableObjects > 0) then {
    private _expectedEditableCount = count _editableObjects;
    if (isServer) then {
        { _x addCuratorEditableObjects [_editableObjects, true]; } forEach allCurators;
        if (_isZeusClone) then {
            [_originalPayload, true] call FST_HCSpawn_fnc_handleZeusOriginalDecision;
        };
    } else {
        [_editableObjects, _originalPayload, _sourceOwner, _expectedEditableCount, _targetId, _group] spawn {
            params ["_editableObjects", "_originalPayload", "_sourceOwner", "_expectedEditableCount", "_targetId", "_group"];
            private _deadline = time + 2.5;
            private _editableNetIds = [];
            private _groupRef = "";

            waitUntil {
                _editableObjects = _editableObjects select { !isNull _x };
                _editableNetIds = (_editableObjects apply { netId _x }) select { !(_x isEqualTo "") };
                _groupRef = netId _group;
                ((count _editableNetIds) >= _expectedEditableCount && {!(_groupRef isEqualTo "")}) || {time >= _deadline}
            };

            ["FST_HC_evt_addEditableObjects", [_editableNetIds, 0, _originalPayload, _sourceOwner, _expectedEditableCount, _targetId, _groupRef]] call CBA_fnc_serverEvent;
        };
    };
};

// Apply behavior after settling
[{
    params ["_group", "_behavior", "_radius", "_pos"];
    if (isNull _group || {count units _group == 0}) exitWith {};

    // V28: vehicle groups never get the infantry garrison/static treatment
    // (it teleports crews into buildings). Hold instead.
    private _mounted = ((units _group) findIf { vehicle _x != _x }) >= 0;
    if (_mounted && {_behavior in ["garrison", "static"]}) then { _behavior = "hold"; };
    private _target = _group getVariable ["FST_HC_vehTarget", _pos];
    if (count _target < 2) then { _target = _pos; };

    switch (_behavior) do {
        case "hold": {
            _group setCombatMode "RED";
            _group setBehaviourStrong "COMBAT";
            { doStop _x; } forEach units _group;
        };
        case "move": {
            if (_radius < 0) then { _radius = 50; };
            private _wp = _group addWaypoint [_target, _radius];
            _wp setWaypointType "MOVE";
            _wp setWaypointBehaviour "AWARE";
            _wp setWaypointCombatMode "RED";
            _wp setWaypointSpeed "FULL";
        };
        case "sad": {
            if (_radius < 0) then { _radius = 300; };
            private _wp = _group addWaypoint [_target, _radius];
            _wp setWaypointType "SAD";
            _wp setWaypointBehaviour "COMBAT";
            _wp setWaypointCombatMode "RED";
            private _after = _group addWaypoint [_target, _radius];
            if (_mounted && {(vehicle leader _group) isKindOf "Air"}) then {
                _after setWaypointType "LOITER";
                _after setWaypointLoiterType "CIRCLE_L";
                _after setWaypointLoiterRadius (_radius max 300);
            } else {
                _after setWaypointType "HOLD";
            };
            _after setWaypointBehaviour "COMBAT";
            _after setWaypointCombatMode "RED";
        };
        case "loiter": {
            if (_radius < 0) then { _radius = 500; };
            private _wp = _group addWaypoint [_target, 0];
            _wp setWaypointType "LOITER";
            _wp setWaypointLoiterType "CIRCLE_L";
            _wp setWaypointLoiterRadius _radius;
            _wp setWaypointBehaviour "AWARE";
            _wp setWaypointCombatMode "RED";
        };
        case "garrison": {
            // Reuse the bounded cache used by BURNS building tasks. This creation
            // path runs scheduled; wait briefly for its shared scan to finish.
            private _scan = [_pos,_radius] call FST_HCSpawn_fnc_burnsPositions;
            private _scanDeadline = time + 8;
            if (canSuspend) then {
                waitUntil {sleep 0.1; _scan=[_pos,_radius] call FST_HCSpawn_fnc_burnsPositions; (_scan select 0) || {time>=_scanDeadline}};
            };
            private _bldgPositions = _scan select 1;
            private _units = units _group;
            {
                if (([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight") then {continue};
                if (_forEachIndex < count _bldgPositions) then {
                    private _bPos = _bldgPositions select _forEachIndex;
                    _x setPosATL _bPos;
                    _x setVariable ["FST_HC_assignedPos", _bPos,true];
                    _x setVariable ["FST_HC_ownsPath",true,true];
                    _x disableAI "PATH";
                    if (([_x] call FST_HCSpawn_fnc_burnsRole) == "b1") then {_x setUnitPos "UP"};
                    doStop _x;
                    _x setFormDir (random 360);
                } else {
                    _x setVariable ["FST_HC_ownsPath",true,true];
                    _x disableAI "PATH";
                    if (([_x] call FST_HCSpawn_fnc_burnsRole) == "b1") then {_x setUnitPos "UP"};
                    doStop _x;
                };
            } forEach _units;

            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";
            // Opt-in only. Note: when this runs on an HC the flag hits the HC's
            // local dyn-sim manager, which the engine keeps inert in MP; only the
            // server manager acts. Flagging would need to move server-side if the
            // feature is ever revived.
            if (missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]) then {
                if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) < 0) then {_group enableDynamicSimulation true};
            };

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
                { _x setVariable ["FST_skipSpawnDamage", true]; deleteVehicle _x; } forEach _toDelete;
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
            // B1 Assault spawns must seek an enemy, not MOVE to their own
            // spawn point while waiting for a contact they do not yet know.
            private _b1Only=(units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole)!="b1"})<0;
            [_group, ["assault","rush"] select _b1Only, _pos, _radius] call FST_HCSpawn_fnc_setCombatTask;
        };
        case "hunt": {
            _group setBehaviourStrong "COMBAT";
            _group setCombatMode "RED";
            [_group, "hunt", _pos, _radius] call FST_HCSpawn_fnc_setCombatTask;
        };
        case "patrol":  {
            [_group, _pos, _radius] call FST_HCSpawn_fnc_burnsPatrol;
        };
        case "static": {
            _group setBehaviourStrong "COMBAT";
            {
                private _role = [_x] call FST_HCSpawn_fnc_burnsRole;
                if (_role == "webknight") then {continue};
                if (_role == "b1") then {_x setUnitPos "UP"};
                doStop _x;
            } forEach units _group;
            if (missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]) then {
                if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) < 0) then {_group enableDynamicSimulation true};
            };
        };
        case "none": {};
    };
}, [_group, _behavior, _radius, _pos], if (_behavior=="assault") then {0} else {1}] call CBA_fnc_waitAndExecute;

// Dynamic simulation only for mobile groups, and only when opted in.
if ((_behavior in ["patrol", "hunt"]) && {missionNamespace getVariable ["FST_HC_EnableDynamicSimulationSystem", false]}) then {
    if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) < 0) then {_group enableDynamicSimulation true};
};

// Track on server. Wait briefly for a real group netId so the server does not
// have to resolve a just-created HC-local group from a stale/empty ref.
// Zeus instant clones are tracked only after server-side editable registration
// confirms them, so rejected clones never enter the tracked cache.
if (_isOnHC && {!_isZeusClone}) then {
    private _preCounted = true;
    if ((count _unitData == 0) && {count _vehData > 0}) then { _preCounted = false; };
    // The HC's owner ID is sent too (V27); the server resolves the index from it
    // so an HC disconnect between dispatch and track cannot mis-file the group.
    [_group, _hcIndex, _preCounted, _targetId] spawn {
        params ["_group", "_hcIndex", "_preCounted", "_targetId"];
        private _deadline = time + 2.5;
        private _groupRef = "";
        waitUntil {
            if (!isNull _group) then { _groupRef = netId _group; };
            isNull _group || {!(_groupRef isEqualTo "") || {time >= _deadline}}
        };
        if (isNull _group) exitWith { ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent; };
        if (_groupRef isEqualTo "") then { _groupRef = _group; };
        ["FST_HC_evt_trackGroup", [_groupRef, _hcIndex, _preCounted, 0, 90, _targetId]] call CBA_fnc_serverEvent;
    };
};

// Zeus instant clone confirmation is intentionally handled by the server-side
// editable-registration path above. Do not confirm from the HC; the server must
// first prove it can resolve/register the replacement objects.

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Created group %1: %2 units, %3", _group, count units _group, _behavior];
};
