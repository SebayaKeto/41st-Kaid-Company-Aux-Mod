// FST_HCSpawn_fnc_qrfSpawn
// Server-side. Validates a QRF request (transport(s) + escorts + infantry) and
// dispatches the build. V28: anything involving a vehicle is built on the
// dedicated vehicle HC (fn_qrfBuildLocal via ownerEvent) so the convoy is born
// on its final owner. Pure foot QRFs, or any QRF with no HC, build on the
// server as before and are handed over afterwards.
//
// Arguments:
//   0: POSITION -- destination
//   1: STRING   -- infantry template key
//   2: NUMBER   -- number of squads
//   3: STRING   -- transport type: "foot", "PAC", "SAC", "MTT", "HMP"
//   4: STRING   -- escort type: "none", "AAT", "N99"
//   5: NUMBER   -- escort count
//   6: NUMBER   -- requesting client owner ID

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

// AI cap check -- use a real function exit.
private _totalInfantry = count _unitClasses * _squadCount;
private _estimate = _totalInfantry + (if (_vehClass != "") then {2} else {0}) + (_escortCount * 3);

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
    if ((_current + _estimate) > _cap) then {
        _capBlocked = true;
        format ["[FST] AI cap -- QRF blocked (%1 + %2 > %3).", _current, _totalInfantry, _cap] remoteExec ["systemChat", _callerID];
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

diag_log format ["[FST_HCSpawn] QRF: %1x '%2', transport %3, %4x %5 escort, spawn %6 -> dest %7",
    _squadCount, _templateKey, _transportType, _escortCount, _escortType, _spawnPos, _destination];

// Treat QRF as heavy spawn work so despawn cleanup does not run during setup/transfer.
missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time];

// --- Dispatch ---
private _args = [_spawnPos, _destination, _side, _unitClasses, _squadCount,
                 _vehClass, _vehCapacity, _escortClass, _escortCount, _isAir, _callerID];

// V28: any vehicle involved -> build on the vehicle HC (or least-loaded HC when
// none is dedicated). Foot-only QRFs build on the server and transfer squads.
private _hasVehicles = (_vehClass != "") || {_escortCount > 0};
private _buildOwner = [if (_hasVehicles) then {"vehicle"} else {"infantry"}, _estimate] call FST_HCSpawn_fnc_getSpawnTarget;
if (_buildOwner == 2 && {missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true]}) exitWith {
    "[FST] QRF blocked: no eligible HC has capacity for the complete QRF." remoteExec ["systemChat", _callerID];
    diag_log "[FST_HCSpawn] QRF blocked by HC capacity; no server fallback.";
};

if (_buildOwner != 2) then {
    // Pre-count the crews + passengers so back-to-back QRFs do not all land on one HC.
    private _hcIndex = FST_HC_Ids find _buildOwner;
    if (_hcIndex >= 0 && {_hcIndex < count FST_HC_UnitCounts}) then {
        FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _estimate];
    };
    ["FST_HC_evt_qrfBuildLocal", _args, _buildOwner] call CBA_fnc_ownerEvent;
    if (FST_HC_DebugLogging) then {
        diag_log format ["[FST_HCSpawn] QRF build sent to owner %1 (HC%2)", _buildOwner, _hcIndex + 1];
    };
} else {
    _args spawn FST_HCSpawn_fnc_qrfBuildLocal;
};
