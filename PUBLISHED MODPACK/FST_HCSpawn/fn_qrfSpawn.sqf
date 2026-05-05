// FST_HCSpawn_fnc_qrfSpawn
// Server-side. Spawns a QRF convoy — transport(s) + escorts in one group
// so they move together as a column. Infantry dismounts and assaults on arrival.
//
// Arguments:
//   0: POSITION — destination
//   1: STRING   — infantry template key
//   2: NUMBER   — number of squads
//   3: STRING   — transport type: "foot", "PAC", "SAC", "MTT", "HMP"
//   4: STRING   — escort type: "none", "AAT", "N99"
//   5: NUMBER   — escort count
//   6: NUMBER   — requesting client owner ID

if (!isServer) exitWith {};

params ["_destination", "_templateKey", "_squadCount", "_transportType", "_escortType", "_escortCount", "_callerID"];

// Resolve template
private _template = FST_HC_Templates getOrDefault [_templateKey, []];
if (count _template == 0) exitWith {
    format ["[FST] QRF: unknown template '%1'", _templateKey] remoteExec ["systemChat", _callerID];
};
_template params ["_side", "_unitClasses", "_desc"];

// Transport class + capacity
private _transportData = switch (toUpper _transportType) do {
    case "PAC": { ["FST_PAC_41st", 24] };
    case "SAC": { ["FST_SAC_41st", 12] };
    case "MTT": { ["FST_MTT", 48] };
    case "HMP": { ["FST_HMP_Transport", 24] };
    default    { ["", 0] };
};
_transportData params ["_vehClass", "_vehCapacity"];

// Escort class
private _escortClass = switch (toUpper _escortType) do {
    case "AAT": { "FST_AAT" };
    case "N99": { "FST_N99" };
    default    { "" };
};
if (_escortClass == "") then { _escortCount = 0; };

private _isAir = toUpper _transportType == "HMP";

// Validate vehicle classes before createVehicle. Missing/renamed classes should
// fail cleanly instead of throwing script/config noise during an op.
if (_vehClass != "" && {!isClass (configFile >> "CfgVehicles" >> _vehClass)}) exitWith {
    format ["[FST] QRF blocked: missing transport class %1", _vehClass] remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] QRF blocked: missing transport class %1", _vehClass];
};
if (_escortCount > 0 && {_escortClass != ""} && {!isClass (configFile >> "CfgVehicles" >> _escortClass)}) exitWith {
    format ["[FST] QRF blocked: missing escort class %1", _escortClass] remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] QRF blocked: missing escort class %1", _escortClass];
};

// Heavy module safety.
if ((missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true]) && {count FST_HC_Array == 0}) exitWith {
    "[FST] QRF blocked: no headless clients are connected." remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] QRF blocked with no HCs. template=%1 squads=%2 transport=%3", _templateKey, _squadCount, _transportType];
};

// AI cap check — use a real function exit.
private _totalInfantry = count _unitClasses * _squadCount;

// Prevent half-loaded mounted QRFs. The UI labels suggest SAC=1 squad, PAC=2,
// MTT=4, etc., but the squad slider still permits invalid combinations. If we
// allow that, leftover infantry dismount instantly and the convoy logic trips.
if (_vehClass != "" && {_vehCapacity > 0} && {_totalInfantry > _vehCapacity}) exitWith {
    format ["[FST] QRF blocked: %1 infantry will not fit in %2 capacity %3. Reduce squads or use a bigger transport.", _totalInfantry, _transportType, _vehCapacity] remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] QRF blocked by transport capacity. infantry=%1 transport=%2 capacity=%3", _totalInfantry, _transportType, _vehCapacity];
};

private _capBlocked = false;
private _cap = missionNamespace getVariable ["FST_HC_AICap", 0];
if (_cap > 0) then {
    private _current = 0;
    { _current = _current + _x; } forEach FST_HC_UnitCounts;
    if ((_current + _totalInfantry) > _cap) then {
        _capBlocked = true;
        format ["[FST] AI cap — QRF blocked (%1 + %2 > %3).", _current, _totalInfantry, _cap] remoteExec ["systemChat", _callerID];
        diag_log format ["[FST_HCSpawn] QRF blocked by AI cap. current=%1 requested=%2 cap=%3", _current, _totalInfantry, _cap];
    };
};
if (_capBlocked) exitWith {};

// --- Find spawn point ---
private _spawnDist = 500 + random 300;
private _spawnPos = [0,0,0];

if (_isAir) then {
    _spawnPos = _destination getPos [_spawnDist, random 360];
} else {
    private _found = false;
    for "_attempt" from 0 to 7 do {
        private _searchPos = _destination getPos [_spawnDist, _attempt * 45];
        private _roads = _searchPos nearRoads 300;
        if (count _roads > 0) exitWith {
            _spawnPos = getPos (_roads select 0);
            _found = true;
        };
    };
    if (!_found) then {
        _spawnPos = _destination getPos [_spawnDist, random 360];
    };
};
_spawnPos = [_spawnPos select 0, _spawnPos select 1, 0];

private _escortText = if (_escortCount > 0) then { format [" + %1x %2", _escortCount, _escortType] } else { "" };
format ["[FST] QRF: %1x %2 via %3%4, %5m out",
    _squadCount, _desc, _transportType, _escortText, round (_spawnPos distance2D _destination)]
    remoteExec ["systemChat", _callerID];

diag_log format ["[FST_HCSpawn] QRF: %1x '%2', transport %3, %4x %5 escort, spawn %6 → dest %7",
    _squadCount, _templateKey, _transportType, _escortCount, _escortType, _spawnPos, _destination];

// --- Dispatch ---
[_spawnPos, _destination, _side, _unitClasses, _squadCount,
 _vehClass, _vehCapacity, _escortClass, _escortCount, _isAir, _callerID] spawn {
    params ["_spawnPos", "_destination", "_side", "_unitClasses", "_squadCount",
            "_vehClass", "_vehCapacity", "_escortClass", "_escortCount", "_isAir", "_callerID"];

    // --- Create infantry squads ---
    private _allInfantry = [];
    private _infantryGroups = [];

    for "_i" from 1 to _squadCount do {
        private _grp = createGroup [_side, true];
        {
            private _offset = [(_spawnPos select 0) + random 6 - 3, (_spawnPos select 1) + random 6 - 3, 0];
            private _unit = _grp createUnit [_x, _offset, [], 0, "NONE"];
            if (_forEachIndex == 0) then { _grp selectLeader _unit; };
            _allInfantry pushBack _unit;
        } forEach _unitClasses;
        _infantryGroups pushBack _grp;
        { _x addCuratorEditableObjects [units _grp, true]; } forEach allCurators;
        sleep 0.3;
    };

    // --- ON FOOT ---
    if (_vehClass == "") exitWith {
        private _footConvoyGrp = grpNull;
        if (_escortCount > 0) then {
            // Escorts present — march together at matched pace
            _footConvoyGrp = createGroup [_side, true];
            for "_e" from 1 to _escortCount do {
                private _escOffset = [(_spawnPos select 0) + 15 * _e, (_spawnPos select 1), 0];
                private _esc = createVehicle [_escortClass, _escOffset, [], 5, "NONE"];
                createVehicleCrew _esc;
                sleep 0.1;  // wait past createVehicleCrew race frame before reading crew
                (crew _esc) joinSilent _footConvoyGrp;
                { _x addCuratorEditableObjects [[_esc], true]; } forEach allCurators;
            };
            { _x addCuratorEditableObjects [units _footConvoyGrp, true]; } forEach allCurators;

            // Escorts at LIMITED so they don't outrun infantry
            private _wp = _footConvoyGrp addWaypoint [_destination, 50];
            _wp setWaypointType "MOVE";
            _wp setWaypointBehaviour "COMBAT";
            _wp setWaypointCombatMode "RED";
            _wp setWaypointSpeed "LIMITED";

            // Hold at destination — provide fire support
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

                // On completion — switch to assault
                _wpInf setWaypointStatements ["true",
                    "group this setBehaviourStrong 'COMBAT'; [group this, getPos this, 200] call lambs_wp_fnc_taskRush;"
                ];
            } forEach _infantryGroups;
        } else {
            // No escorts — just rush straight in
            {
                _x setBehaviourStrong "COMBAT";
                _x setCombatMode "RED";
                [_x, _destination, 200] call lambs_wp_fnc_taskRush;
            } forEach _infantryGroups;
        };

        // QRF is created on the server because it needs coordinated waypoint/vehicle setup.
        // Once setup is complete, immediately hand AI groups to the HC manager.
        { [_x] call FST_HCSpawn_fnc_transferGroup; sleep 0.2; } forEach _infantryGroups;
        if (_escortCount > 0 && {!isNull _footConvoyGrp}) then { [_footConvoyGrp] call FST_HCSpawn_fnc_transferGroup; };

        private _escText = if (_escortCount > 0) then { format [" + %1 escorts", _escortCount] } else { "" };
        format ["[FST] QRF deployed — %1 squads on foot%2", _squadCount, _escText] remoteExec ["systemChat", _callerID];
    };

    // --- MOUNTED: single convoy group for ALL vehicles ---
    private _convoyGrp = createGroup [_side, true];
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
    { _x addCuratorEditableObjects [[_transport], true]; } forEach allCurators;

    sleep 0.2;

    // Create escorts — all crews join the same convoy group
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
        { _x addCuratorEditableObjects [[_esc], true]; } forEach allCurators;

        sleep 0.1;
    };

    // Add convoy group to curators
    { _x addCuratorEditableObjects [units _convoyGrp, true]; } forEach allCurators;

    sleep 0.5;

    // Load infantry into transport
    {
        if (_transport emptyPositions "cargo" > 0) then {
            _x moveInCargo _transport;
        };
    } forEach _allInfantry;

    // --- Send convoy to destination ---
    // All vehicles are in _convoyGrp — Arma keeps them in column formation
    private _wpDest = _convoyGrp addWaypoint [_destination, 30];
    _wpDest setWaypointType "TR UNLOAD";
    _wpDest setWaypointBehaviour "CARELESS";
    _wpDest setWaypointSpeed "FULL";

    // After unload: convoy holds position (escorts provide fire support)
    private _wpHold = _convoyGrp addWaypoint [_destination, 50];
    _wpHold setWaypointType "HOLD";
    _wpHold setWaypointBehaviour "COMBAT";
    _wpHold setWaypointCombatMode "RED";

    // Monitor for dismount — switch infantry to assault
    [{
        params ["_args", "_handle"];
        _args params ["_allInfantry", "_infantryGroups", "_transport", "_destination"];

        private _dismounted = _allInfantry findIf { vehicle _x == _x };
        if (_dismounted == -1 && alive _transport) exitWith {};

        [_handle] call CBA_fnc_removePerFrameHandler;

        {
            if (count units _x > 0) then {
                _x setBehaviourStrong "COMBAT";
                _x setCombatMode "RED";
                [_x, _destination, 200] call lambs_wp_fnc_taskRush;
                [_x] call FST_HCSpawn_fnc_transferGroup;
            };
        } forEach _infantryGroups;

    }, 2, [_allInfantry, _infantryGroups, _transport, _destination]] call CBA_fnc_addPerFrameHandler;

    // Hand the vehicle/crew convoy group to HC after all waypoints are built.
    [_convoyGrp] call FST_HCSpawn_fnc_transferGroup;

    format ["[FST] QRF convoy en route — %1 squads + %2 vehicles",
        _squadCount, count _allVehicles] remoteExec ["systemChat", _callerID];
};
