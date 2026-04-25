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
};

// ============================================================
// HC / CLIENT EVENTS (fired from server, handled on HC or Zeus)
// ============================================================

// Create group locally (received by specific HC via ownerEvent)
["FST_HC_evt_createGroupLocal", {
    _this call FST_HCSpawn_fnc_createGroupLocal;
}] call CBA_fnc_addEventHandler;

// Fill garrison batch (received by specific HC via ownerEvent)
["FST_HC_evt_fillBatch", {
    _this call FST_HCSpawn_fnc_fillGarrison;
}] call CBA_fnc_addEventHandler;

// Reapply garrison after transfer (received by specific HC via ownerEvent)
["FST_HC_evt_reapplyGarrison", {
    _this call FST_HCSpawn_fnc_reapplyGarrison;
}] call CBA_fnc_addEventHandler;

diag_log "[FST_HCSpawn] CBA events registered";
