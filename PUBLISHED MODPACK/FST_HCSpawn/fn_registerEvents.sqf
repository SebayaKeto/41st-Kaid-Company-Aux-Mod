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

    // Group tracking (from HC after creating a group). HCs send group netIds so
    // the server can retry if the group object has not resolved yet.
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
        _this call FST_HCSpawn_fnc_addEditableObjects;
    }] call CBA_fnc_addEventHandler;

    // Server-authoritative cleanup/restore of original Zeus-placed groups after instant clone validation.
    ["FST_HC_evt_zeusOriginalDecisionServer", {
        _this call FST_HCSpawn_fnc_handleZeusOriginalDecision;
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


    // Manual/rare dead-group maintenance cleanup (from Zeus/admin client).
    ["FST_HC_evt_manualDeadGroupCleanup", {
        _this call FST_HCSpawn_fnc_requestDeadGroupCleanup;
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



// Local dead-group cleanup request. deleteGroup is locality-sensitive, so the server
// uses this ownerEvent to make each HC clean only its own local dead groups.
["FST_HC_evt_cleanupDeadGroupsLocal", {
    private _deleted = _this call FST_HCSpawn_fnc_cleanupDeadGroups;
    if (_deleted > 0) then {
        ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent;
    };
}] call CBA_fnc_addEventHandler;

// Start FPS monitor on a target machine without direct remoteExec of an addon function.
["FST_HC_evt_startFpsMonitor", {
    _this call FST_HCSpawn_fnc_fpsMonitor;
}] call CBA_fnc_addEventHandler;

// Create group locally (received by specific HC via ownerEvent)
// Spawned because the function uses `sleep` past the createVehicleCrew race frame.
["FST_HC_evt_createGroupLocal", {
    _this spawn FST_HCSpawn_fnc_createGroupLocal;
}] call CBA_fnc_addEventHandler;


// Delete a rejected HC clone locally on the owner machine after the server restores the original.
["FST_HC_evt_deleteRejectedClone", {
    params ["_groupRef"];
    private _grp = grpNull;
    if (_groupRef isEqualType grpNull) then {
        _grp = _groupRef;
    } else {
        if (_groupRef isEqualType "") then {
            _grp = groupFromNetId _groupRef;
        };
    };
    if (isNull _grp) exitWith {
        ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent;
    };
    {
        if (!isNull _x) then {
            _x setVariable ["FST_skipSpawnDamage", true, true];
            deleteVehicle _x;
        };
    } forEach units _grp;
    deleteGroup _grp;
    ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;

// Loadout restore after locality transfer (received by target HC via ownerEvent)
["FST_HC_evt_restoreLoadout", {
    params ["_payload"];
    [{
        params ["_payload"];
        {
            _x params ["_unit", "_loadout"];
            if (!isNull _unit && {local _unit} && {count _loadout > 0} && {uniform _unit == ""}) then {
                _unit setUnitLoadout _loadout;
            };
        } forEach _payload;
    }, [_payload], 1] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;


// Legacy compatibility only. v5 moved Zeus-original hide/restore/delete to the server
// because hideObjectGlobal / enableSimulationGlobal are server-exec commands.
["FST_HC_evt_zeusOriginalDecision", {
    // Intentionally no-op; retained so old queued events do not error during hot testing.
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
