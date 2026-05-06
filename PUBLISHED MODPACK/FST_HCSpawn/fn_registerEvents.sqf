// FST_HCSpawn_fnc_registerEvents
// Registers all CBA custom events for server ↔ HC ↔ client communication.
// All inter-machine communication via CBA events.
// Called on ALL machines (server, HC, clients) from postInit.

// ============================================================
// SERVER-SIDE EVENTS (fired from clients/HCs, handled on server)
// ============================================================
if (isServer) then {

    // HC registration
    ["FST_HC_evt_registerHC", {
        _this call FST_HCSpawn_fnc_registerHC;
    }] call CBA_fnc_addEventHandler;

    // Group tracking (from HC after creating a group)
    ["FST_HC_evt_trackGroup", {
        _this call FST_HCSpawn_fnc_trackGroup;
    }] call CBA_fnc_addEventHandler;

    // Spawn request (from Zeus client)
    ["FST_HC_evt_spawn", {
        _this call FST_HCSpawn_fnc_spawnGroupOnTarget;
    }] call CBA_fnc_addEventHandler;

    // Zeus placed group handoff. Keeps the original group and transfers ownership instead of cloning.
    ["FST_HC_evt_queueZeusGroup", {
        _this call FST_HCSpawn_fnc_queueZeusGroup;
    }] call CBA_fnc_addEventHandler;

    // Register HC-created objects as editable by Zeus on the server.
    ["FST_HC_evt_addEditableObjects", {
        params [["_objects", []]];
        private _valid = _objects select { !isNull _x };
        if (count _valid == 0) exitWith {};
        { _x addCuratorEditableObjects [_valid, true]; } forEach allCurators;
    }] call CBA_fnc_addEventHandler;

    // Quick spawn template (from Zeus client) — resolves template inline
    ["FST_HC_evt_quickSpawn", {
        params ["_pos", "_templateKey", "_behavior", ["_radius", -1]];
        private _template = FST_HC_Templates getOrDefault [_templateKey, []];
        if (count _template == 0) exitWith {
            diag_log format ["[FST_HCSpawn] Unknown template '%1'", _templateKey];
        };
        _template params ["_side", "_unitClasses", "_desc"];
        [_side, _unitClasses, _pos, _behavior, _radius, []] call FST_HCSpawn_fnc_spawnGroupOnTarget;
    }] call CBA_fnc_addEventHandler;

    // Fill garrison request (from Zeus client)
    ["FST_HC_evt_fillGarrison", {
        _this call FST_HCSpawn_fnc_requestFillGarrison;
    }] call CBA_fnc_addEventHandler;

    // Frontline assault (from Zeus client)
    ["FST_HC_evt_frontline", {
        _this call FST_HCSpawn_fnc_frontlineSpawn;
    }] call CBA_fnc_addEventHandler;

    // QRF (from Zeus client)
    ["FST_HC_evt_qrf", {
        _this call FST_HCSpawn_fnc_qrfSpawn;
    }] call CBA_fnc_addEventHandler;

    // Zeus hold/release (from Zeus client)
    ["FST_HC_evt_zeusHold", {
        _this call FST_HCSpawn_fnc_zeusHold;
    }] call CBA_fnc_addEventHandler;

    // Status report request (from any client)
    ["FST_HC_evt_statusReport", {
        _this call FST_HCSpawn_fnc_statusReport;
    }] call CBA_fnc_addEventHandler;

    // Force immediate recount after HC-side cleanup deletes spawned units.
    ["FST_HC_evt_recountUnits", {
        [] call FST_HCSpawn_fnc_recountUnits;
    }] call CBA_fnc_addEventHandler;

    // Debug snapshot request (from Zeus/admin client)
    ["FST_HC_evt_debugSnapshotRequest", {
        _this call FST_HCSpawn_fnc_requestDebugSnapshot;
    }] call CBA_fnc_addEventHandler;
};

// ============================================================
// HC / CLIENT EVENTS (fired from server, handled on HC or Zeus)
// ============================================================

// Create group locally (received by specific HC via ownerEvent)
// Spawned because the function uses `sleep` past the createVehicleCrew race frame.
["FST_HC_evt_createGroupLocal", {
    _this spawn FST_HCSpawn_fnc_createGroupLocal;
}] call CBA_fnc_addEventHandler;

// Loadout restore after locality transfer (received by target HC via ownerEvent)
["FST_HC_evt_restoreLoadout", {
    params ["_payload"];
    [{
        params ["_payload"];
        {
            _x params ["_unit", "_loadout", ["_class", ""]];
            if (_class isEqualTo "" && {!isNull _unit}) then { _class = typeOf _unit; };
            if (!isNull _unit && {local _unit} && {count _loadout > 0}) then {
                private _needsRestore = (uniform _unit isEqualTo "") ||
                    {(primaryWeapon _unit isEqualTo "") && {secondaryWeapon _unit isEqualTo ""} && {handgunWeapon _unit isEqualTo ""}};
                if (_needsRestore) then {
                    [_unit, _loadout, _class, "setGroupOwner/restoreLoadout"] call FST_HCSpawn_fnc_applyUnitLoadoutSafe;
                };
            };
        } forEach _payload;
    }, [_payload], 1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;


// Zeus instant clone original cleanup decision. Received by the Zeus client that
// placed the original group. If rejected, the original remains and only markers clear.
["FST_HC_evt_zeusOriginalDecision", {
    params ["_originalPayload", "_accepted"];
    _originalPayload params ["_group", "_units", "_vehicle"];

    if (!_accepted) exitWith {
        if (!isNull _group) then {
            _group setVariable ["FST_HC_interceptQueued", nil, true];
            _group setVariable ["FST_HC_pendingTransfer", nil];
        };
    };

    private _deleteDelay = missionNamespace getVariable ["FST_HC_ZeusOriginalDeleteDelay", 2.0];
    private _hideFirst = missionNamespace getVariable ["FST_HC_ZeusHideOriginalBeforeDelete", true];

    private _objectsToSuppress = [];
    if (!isNull _vehicle) then {
        _objectsToSuppress pushBack _vehicle;
        _objectsToSuppress append (crew _vehicle);
    } else {
        _objectsToSuppress = _units select { !isNull _x };
    };

    {
        if (!isNull _x) then {
            _x setVariable ["FST_skipSpawnDamage", true, true];

            // The HC clone has already been accepted. Suppress the short-lived Zeus
            // original immediately, but do not delete it until the engine has had a
            // moment to finish processing create/sync messages for that network ID.
            if (_hideFirst) then {
                if (_x isKindOf "CAManBase") then { _x disableAI "ALL"; };
                _x enableSimulationGlobal false;
                _x hideObjectGlobal true;
            };
        };
    } forEach _objectsToSuppress;

    if (!isNull _group) then {
        _group deleteGroupWhenEmpty true;
        _group setVariable ["FST_HC_interceptQueued", nil, true];
        _group setVariable ["FST_HC_pendingTransfer", nil];
    };

    [{
        params ["_group", "_units", "_vehicle"];

        if (!isNull _vehicle) then {
            { _x setVariable ["FST_skipSpawnDamage", true, true]; } forEach crew _vehicle;
            { _vehicle deleteVehicleCrew _x; } forEach crew _vehicle;
            deleteVehicle _vehicle;
        } else {
            {
                if (!isNull _x) then {
                    _x setVariable ["FST_skipSpawnDamage", true, true];
                    deleteVehicle _x;
                };
            } forEach _units;
        };

        if (!isNull _group) then {
            _group deleteGroupWhenEmpty true;
        };
    }, [_group, _units, _vehicle], _deleteDelay] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

// Fill garrison batch (received by specific HC via ownerEvent)
["FST_HC_evt_fillBatch", {
    _this call FST_HCSpawn_fnc_fillGarrison;
}] call CBA_fnc_addEventHandler;

// Reapply garrison after transfer (received by specific HC via ownerEvent)
["FST_HC_evt_reapplyGarrison", {
    _this call FST_HCSpawn_fnc_reapplyGarrison;
}] call CBA_fnc_addEventHandler;

// Debug ownership snapshot (received by Zeus/admin client via ownerEvent)
["FST_HC_evt_debugSnapshot", {
    params ["_snapshot", "_serverTick", "_hcIds", "_unitCounts", "_queueCount", "_successes", "_failures", "_zeusInstantClones", "_zeusFallbacks", "_legacyFallbacks"];
    missionNamespace setVariable ["FST_HC_DebugSnapshot", _snapshot];
    missionNamespace setVariable ["FST_HC_DebugServerTick", _serverTick];
    missionNamespace setVariable ["FST_HC_DebugHCIds", _hcIds];
    missionNamespace setVariable ["FST_HC_DebugUnitCounts", _unitCounts];
    missionNamespace setVariable ["FST_HC_DebugQueueCount", _queueCount];
    missionNamespace setVariable ["FST_HC_DebugTransferSuccesses", _successes];
    missionNamespace setVariable ["FST_HC_DebugTransferFailures", _failures];
    missionNamespace setVariable ["FST_HC_DebugZeusInstantClones", _zeusInstantClones];
    missionNamespace setVariable ["FST_HC_DebugZeusFallbacks", _zeusFallbacks];
    missionNamespace setVariable ["FST_HC_DebugLegacyFallbacks", _legacyFallbacks];
}] call CBA_fnc_addEventHandler;

diag_log "[FST_HCSpawn] CBA events registered";
