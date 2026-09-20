// FST_HCSpawn_fnc_qrfBuildLocal
// Builds a QRF (infantry squads + transport + escorts, waypoints, dismount
// watcher) on the machine it runs on. V28: fn_qrfSpawn validates on the server
// and then sends this to the vehicle HC as an ownerEvent, so the convoy is born
// on its final owner and never changes locality while moving. With no vehicle
// HC it still runs on the server and hands groups over as before.
//
// Must be spawned (uses sleep).
//
// Arguments: [_spawnPos, _destination, _side, _unitClasses, _squadCount,
//             _vehClass, _vehCapacity, _escortClass, _escortCount, _isAir, _callerID]

params ["_spawnPos", "_destination", "_side", "_unitClasses", "_squadCount",
        "_vehClass", "_vehCapacity", "_escortClass", "_escortCount", "_isAir", "_callerID"];

private _onHC = !isServer;
private _myOwner = clientOwner;

// Zeus editability must be registered on the server. From an HC, send netIds
// once they exist (a fresh object has an empty netId for a frame or two).
private _registerEditable = {
    params ["_objects"];
    _objects = _objects select { !isNull _x };
    if (count _objects == 0) exitWith {};
    if (isServer) then {
        { _x addCuratorEditableObjects [_objects, true]; } forEach allCurators;
    } else {
        private _ids = (_objects apply { netId _x }) select { !(_x isEqualTo "") };
        if (count _ids > 0) then {
            ["FST_HC_evt_addEditableObjects", [_ids]] call CBA_fnc_serverEvent;
        };
    };
};

// Hand a finished group to the HC manager. On the server that is a transfer;
// on an HC the group is already where it should be, so just track it.
private _handoff = {
    params ["_grp"];
    if (isNull _grp || {count units _grp == 0}) exitWith {};
    if (isServer) then {
        [_grp] call FST_HCSpawn_fnc_transferGroup;
    } else {
        // preCounted: fn_qrfSpawn already added an estimate for this QRF to the
        // HC's balancing count; the periodic recount trues it up.
        ["FST_HC_evt_trackGroup", [netId _grp, -1, true, 0, 90, _myOwner]] call CBA_fnc_serverEvent;
    };
};

// Dismounted infantry does not belong on the vehicle HC. Ask the server to move
// it to an infantry HC through the normal (now safe: on foot) transfer path.
private _rebalance = {
    params ["_grp"];
    if (isNull _grp || {count units _grp == 0}) exitWith {};
    if (isServer) then {
        [_grp] call FST_HCSpawn_fnc_transferGroup;
    } else {
        if (FST_HC_DebugLogging) then { diag_log format ["[FST_HCSpawn] QRF passengers %1 dismounted, asking server to re-home (netId %2)", _grp, netId _grp]; };
        ["FST_HC_evt_requeueGroup", [netId _grp]] call CBA_fnc_serverEvent;
    };
};

private _newGroup = {
    private _grp = createGroup [_side, true];
    _grp deleteGroupWhenEmpty true;
    _grp setVariable ["FST_HC_managed", true, true]; // addon-created: despawn-eligible (server reads this)
    _grp setVariable ["FST_HC_spawnProtectedUntil", time + 90];
    _grp
};

// --- Create infantry squads ---
private _allInfantry = [];
private _infantryGroups = [];

for "_i" from 1 to _squadCount do {
    private _grp = call _newGroup;
    {
        private _offset = [(_spawnPos select 0) + random 6 - 3, (_spawnPos select 1) + random 6 - 3, 0];
        private _unit = _grp createUnit [_x, _offset, [], 0, "NONE"];
        if (isNull _unit) then {
            diag_log format ["[FST_HCSpawn] QRF infantry createUnit failed for %1", _x];
            continue;
        };
        _unit setVariable ["FST_HC_created", true];
        _unit setVariable ["FST_HC_spawnSettlingUntil", time + 10];
        if (_forEachIndex == 0) then { _grp selectLeader _unit; };
        _allInfantry pushBack _unit;
    } forEach _unitClasses;
    _infantryGroups pushBack _grp;
    sleep 0.3;
};
sleep 0.5;
[_allInfantry] call _registerEditable;

// --- ON FOOT ---
if (_vehClass == "") exitWith {
    private _footConvoyGrp = grpNull;
    if (_escortCount > 0) then {
        // Escorts present -- march together at matched pace
        _footConvoyGrp = call _newGroup;
        private _escorts = [];
        for "_e" from 1 to _escortCount do {
            private _escOffset = [(_spawnPos select 0) + 15 * _e, (_spawnPos select 1), 0];
            private _esc = createVehicle [_escortClass, _escOffset, [], 5, "NONE"];
            createVehicleCrew _esc;
            sleep 0.1;  // wait past createVehicleCrew race frame before reading crew
            (crew _esc) joinSilent _footConvoyGrp;
            _escorts pushBack _esc;
        };
        sleep 0.5;
        [_escorts + units _footConvoyGrp] call _registerEditable;

        // Escorts at LIMITED so they don't outrun infantry
        private _wp = _footConvoyGrp addWaypoint [_destination, 50];
        _wp setWaypointType "MOVE";
        _wp setWaypointBehaviour "COMBAT";
        _wp setWaypointCombatMode "RED";
        _wp setWaypointSpeed "LIMITED";

        // Hold at destination -- provide fire support
        private _wpHold = _footConvoyGrp addWaypoint [_destination, 30];
        _wpHold setWaypointType "HOLD";
        _wpHold setWaypointBehaviour "COMBAT";
        _wpHold setWaypointCombatMode "RED";

        // Infantry advances at same pace via waypoints, then assaults on arrival
        {
            _x setBehaviourStrong "AWARE";
            _x setCombatMode "RED";
            _x setSpeedMode "NORMAL";

            private _wpInf = _x addWaypoint [_destination, 30];
            _wpInf setWaypointType "MOVE";
            _wpInf setWaypointBehaviour "AWARE";
            _wpInf setWaypointSpeed "NORMAL";

            // On completion -- switch to assault
            _wpInf setWaypointStatements ["true",
                "group this setBehaviourStrong 'COMBAT'; [group this, 200, 15, [], getPos this, false] spawn lambs_wp_fnc_taskRush;"
            ];
        } forEach _infantryGroups;
    } else {
        // No escorts -- just rush straight in
        {
            _x setBehaviourStrong "COMBAT";
            _x setCombatMode "RED";
            [_x, 200, 15, [], _destination, false] spawn lambs_wp_fnc_taskRush;
        } forEach _infantryGroups;
    };

    // Foot infantry goes to an infantry HC; escorts stay with this machine's manager.
    { [_x] call _rebalance; sleep 0.2; } forEach _infantryGroups;
    if (_escortCount > 0 && {!isNull _footConvoyGrp}) then { [_footConvoyGrp] call _handoff; };

    private _escText = if (_escortCount > 0) then { format [" + %1 escorts", _escortCount] } else { "" };
    format ["[FST] QRF deployed -- %1 squads on foot%2", _squadCount, _escText] remoteExec ["systemChat", _callerID];
};

// --- MOUNTED: single convoy group for ALL vehicles ---
private _convoyGrp = call _newGroup;
private _allVehicles = [];

// Create transport
private _vehSpawnPos = if (_isAir) then {
    [_spawnPos select 0, _spawnPos select 1, 100]
} else {
    +_spawnPos
};

private _transport = createVehicle [_vehClass, _vehSpawnPos, [], 0, "NONE"];
createVehicleCrew _transport;
sleep 0.1;  // wait past createVehicleCrew race frame before reading crew
(crew _transport) joinSilent _convoyGrp;
_allVehicles pushBack _transport;

sleep 0.2;

// Create escorts -- all crews join the same convoy group
for "_e" from 1 to _escortCount do {
    private _escOffset = if (_isAir) then {
        [(_spawnPos select 0) + 40 * _e, (_spawnPos select 1) + 40 * _e, 100]
    } else {
        // Stagger behind and to the side of the transport for column formation
        [(_spawnPos select 0) - 15 * _e, (_spawnPos select 1) + 10 * _e, 0]
    };

    private _esc = createVehicle [_escortClass, _escOffset, [], 5, "NONE"];
    createVehicleCrew _esc;
    sleep 0.1;  // wait past createVehicleCrew race frame before reading crew
    (crew _esc) joinSilent _convoyGrp;
    _allVehicles pushBack _esc;

    sleep 0.1;
};

sleep 0.5;
[_allVehicles + units _convoyGrp] call _registerEditable;

// Load infantry into transport
{
    if (_transport emptyPositions "cargo" > 0) then {
        _x moveInCargo _transport;
    };
} forEach _allInfantry;

// --- Send convoy to destination ---
// All vehicles are in _convoyGrp -- Arma keeps them in column formation
private _wpDest = _convoyGrp addWaypoint [_destination, 30];
_wpDest setWaypointType "TR UNLOAD";
_wpDest setWaypointBehaviour "CARELESS";
_wpDest setWaypointSpeed "FULL";

// After unload: convoy holds position (escorts provide fire support)
private _wpHold = _convoyGrp addWaypoint [_destination, 50];
_wpHold setWaypointType "HOLD";
_wpHold setWaypointBehaviour "COMBAT";
_wpHold setWaypointCombatMode "RED";

// Track the convoy right away so the server's counts include it. It is
// already on its final owner when this runs on the vehicle HC.
[_convoyGrp] call _handoff;

// Monitor for dismount -- switch infantry to assault and move it to an infantry HC.
// V28: moveInCargo assigns the passengers to the transport, and a TR UNLOAD
// waypoint only ejects cargo that is NOT assigned, so the old convoy stopped at
// the destination with everyone still aboard. Kick them out ourselves once the
// transport has arrived (or died).
[{
    params ["_args", "_handle"];
    _args params ["_allInfantry", "_infantryGroups", "_transport", "_destination", "_rebalance", "_state"];

    // Wait until EVERY living passenger is out (or the transport is gone): a
    // group with its leader still aboard counts as mounted and would be refused.
    private _stillIn = _allInfantry findIf { alive _x && {vehicle _x != _x} };
    if (_stillIn != -1 && alive _transport) exitWith {
        private _arrived = (_transport distance2D _destination) < 120 && {(vectorMagnitude velocity _transport) < 2};
        if (_arrived && {!(_state select 0)}) then {
            _state set [0, true];
            {
                if (alive _x && {vehicle _x == _transport}) then {
                    unassignVehicle _x;
                    [_x] orderGetIn false;
                    _x action ["Eject", _transport];
                };
            } forEach _allInfantry;
            { _x leaveVehicle _transport; } forEach _infantryGroups;
        };
    };

    [_handle] call CBA_fnc_removePerFrameHandler;

    {
        if (count units _x > 0) then {
            _x setBehaviourStrong "COMBAT";
            _x setCombatMode "RED";
            [_x, 200, 15, [], _destination, false] spawn lambs_wp_fnc_taskRush;
            [_x] call _rebalance;
        };
    } forEach _infantryGroups;

}, 2, [_allInfantry, _infantryGroups, _transport, _destination, _rebalance, [false]]] call CBA_fnc_addPerFrameHandler;

// Passengers ride on the convoy's owner until they dismount; track them so the
// counts are right meanwhile.
{ [_x] call _handoff; } forEach _infantryGroups;

format ["[FST] QRF convoy en route -- %1 squads + %2 vehicles%3",
    _squadCount, count _allVehicles, if (_onHC) then { " (built on vehicle HC)" } else { "" }] remoteExec ["systemChat", _callerID];
