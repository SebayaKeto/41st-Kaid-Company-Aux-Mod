// FST_HCSpawn_fnc_spawnGroupOnTarget
// Server-side. Routes spawn request to least-loaded HC or server.

if (!isServer) exitWith {};

params ["_side", "_unitClasses", "_pos", ["_behavior", "garrison"], ["_radius", -1], ["_vehData", []], ["_unitData", []], ["_sourceOwner", -1], ["_originalPayload", []]];

private _isValidatedZeusClone = (_sourceOwner > 2) && {count _originalPayload == 3};
private _clearOriginal = {
    params ["_accepted"];
    if (_isValidatedZeusClone) then {
        [_originalPayload, _accepted] call FST_HCSpawn_fnc_handleZeusOriginalDecision;
    };
};

// AI cap check — keep this as an actual function exit, not a nested exitWith.
private _spawnCountForCap = if (count _unitData > 0) then { count _unitData } else { count _unitClasses };
private _capBlocked = false;
private _cap = missionNamespace getVariable ["FST_HC_AICap", 0];
if (_cap > 0 && {_spawnCountForCap > 0}) then {
    private _total = 0;
    { _total = _total + _x; } forEach FST_HC_UnitCounts;
    if ((_total + _spawnCountForCap) > _cap) then {
        _capBlocked = true;
        private _targetMsg = if (_sourceOwner > 2) then { _sourceOwner } else { -2 };
        format ["[FST] AI cap reached — spawn blocked (%1 + %2 > %3).", _total, _spawnCountForCap, _cap] remoteExec ["systemChat", _targetMsg];
        diag_log format ["[FST_HCSpawn] Spawn blocked by AI cap. total=%1 requested=%2 cap=%3 behavior=%4", _total, _spawnCountForCap, _cap, _behavior];
    };
};
if (_capBlocked) exitWith { [false] call _clearOriginal; };

if (_radius < 0) then {
    _radius = switch (_behavior) do {
        case "garrison": { FST_HC_GarrisonRadius };
        case "patrol":   { FST_HC_PatrolRadius };
        default          { 100 };
    };
};

private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
private _isOnHC = _targetId != 2;
private _hcIndex = if (_isOnHC) then { FST_HC_Ids find _targetId } else { -1 };

// For instant Zeus clone/replace, never delete the original if HCs disappeared
// between the client click and server validation. Leave the original group alive.
if (_isValidatedZeusClone && {!_isOnHC}) exitWith {
    "[FST] Zeus instant clone blocked: no HC available. Original group left in place." remoteExec ["systemChat", _sourceOwner];
    diag_log format ["[FST_HCSpawn] Zeus instant clone blocked: no HC available for original %1", _originalPayload select 0];
    [false] call _clearOriginal;
};

// Pre-increment unit counts so the NEXT call to getSpawnTarget
// sees this HC as loaded. Prevents rapid-fire all going to HC1.
// Periodic recountUnits corrects any drift from actual tracked groups.
private _spawnCount = if (count _unitData > 0) then { count _unitData } else { count _unitClasses };
if (_spawnCount == 0 && {count _vehData > 0}) then { _spawnCount = -1; }; // vehicle crew count is unknown until HC creates it

if (_hcIndex >= 0 && _hcIndex < count FST_HC_UnitCounts && {_spawnCount > 0}) then {
    FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _spawnCount];
};

// Server-authoritative suppression of the original Zeus group.
// Do this only after cap/HC validation succeeds. The original is restored by
// handleZeusOriginalDecision if the HC clone later fails.
if (_isValidatedZeusClone) then {
    _originalPayload params ["_origGroup", "_origUnits", "_origVehicle"];

    // Server is authoritative once it accepts the instant-clone request.
    // Reassert this marker here so a slow serverEvent cannot be invalidated by
    // the client-side 8s failsafe clearing its earlier local/public marker.
    if (!isNull _origGroup) then {
        _origGroup setVariable ["FST_HC_interceptQueued", true, true];
    };

    private _origObjects = [];
    if (!isNull _origVehicle) then {
        _origObjects pushBackUnique _origVehicle;
        { _origObjects pushBackUnique _x; } forEach crew _origVehicle;
    } else {
        { _origObjects pushBackUnique _x; } forEach _origUnits;
    };

    {
        if (!isNull _x) then {
            _x setVariable ["FST_HC_originalSuppressed", true, true];
            _x setVariable ["FST_skipSpawnDamage", true, true];
            _x hideObjectGlobal true;
            _x enableSimulationGlobal false;
        };
    } forEach _origObjects;

    // Server-side failsafe: if the HC/server confirmation path never resolves,
    // restore the hidden original instead of leaving invisible frozen AI behind.
    [{
        params ["_payload"];
        _payload params ["_grp", "_u", "_v"];
        if (!isNull _grp && {_grp getVariable ["FST_HC_interceptQueued", false]}) then {
            [_payload, false] call FST_HCSpawn_fnc_handleZeusOriginalDecision;
            diag_log format ["[FST_HCSpawn] Zeus instant clone server failsafe restored original group %1", _grp];
        };
    }, [_originalPayload], 12] call CBA_fnc_waitAndExecute;
};

private _args = [_side, _unitClasses, _pos, _behavior, _radius, _vehData, _isOnHC, _targetId, _hcIndex, _unitData, _sourceOwner, _originalPayload];
missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time, true];

if (count _unitData > 0 || {count _vehData > 0}) then {
    FST_HC_ZeusInstantCloneRequests = (missionNamespace getVariable ["FST_HC_ZeusInstantCloneRequests", 0]) + 1;
};

if (_isOnHC) then {
    private _hcId = FST_HC_Ids select _hcIndex;
    ["FST_HC_evt_createGroupLocal", _args, _hcId] call CBA_fnc_ownerEvent;
} else {
    // Spawned because createGroupLocal uses sleep past the createVehicleCrew frame.
    _args spawn FST_HCSpawn_fnc_createGroupLocal;
};

// Do NOT accept/delete the original here for validated Zeus instant clones.
// The target HC confirms success from fn_createGroupLocal after replacement units
// exist and editable registration has been queued. Premature acceptance was leaving
// stale curator/object references, especially for single-unit placements.
