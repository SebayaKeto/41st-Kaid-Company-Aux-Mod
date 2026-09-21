// FST_HCSpawn_fnc_registerEvents
// Registers all CBA custom events for server <-> HC <-> client communication.
// All inter-machine communication via CBA events.
// Called on ALL machines (server, HC, clients) from postInit.
//
// V27: every client-originated request carries the client's clientOwner and the
// server validates it with FST_HCSpawn_fnc_isAuthorizedCaller (curator or admin).

// ============================================================
// SERVER-SIDE EVENTS (fired from clients/HCs, handled on server)
// ============================================================
if (isServer) then {
    ["BURNS_request", {_this call FST_HCSpawn_fnc_burnsRequest}] call CBA_fnc_addEventHandler;
    ["BURNS_rerouteOrder", {
        params ["_mode","_group","_pos","_radius","_options","_caller",["_hop",1]];
        if (isNull _group || {_hop!=1} || {!([_caller,"BURNS order retry"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {};
        private _owner=groupOwner _group;
        if (_owner<2) exitWith {};
        ["BURNS_order",[_mode,_group,_pos,_radius,_options,_caller,_hop],_owner] call CBA_fnc_ownerEvent;
    }] call CBA_fnc_addEventHandler;
    BURNS_ReinforcementGroups=[];
    ["BURNS_support", {
        params ["_source","_pos"];
        if (isNull _source || {!(_source getVariable ["BURNS_hasRadio",false])} || {time<(missionNamespace getVariable ["BURNS_supportNext",-1])}) exitWith {};
        if (time<(_source getVariable ["BURNS_supportNext",-1])) exitWith {};
        if ([_source] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
        BURNS_supportNext=time+5;
        _source setVariable ["BURNS_supportNext",time+90];
        BURNS_ReinforcementGroups=BURNS_ReinforcementGroups select {!isNull _x && {_x getVariable ["BURNS_reinforcement",false]}};
        private _sent=0;
        {
            if (_sent>=2) exitWith {};
            if (_x==_source || {side _x!=side _source} || {!alive leader _x} || {leader _x distance2D _pos>3000} || {(units _x findIf {isPlayer _x})>=0} || {time<(_x getVariable ["BURNS_supportBusy",-1])}) then {continue};
            if (_x getVariable ["BURNS_exempt",false] || {(_x getVariable ["FST_HC_heldBy",-1])!=-1}) then {continue};
            if ([_x] call FST_HCSpawn_fnc_isProtectedVehicleGroup) then {continue};
            _x setVariable ["BURNS_supportBusy",time+120];
            ["BURNS_order",["hunt",_x,_pos,500,[false,true,false],2,0],groupOwner _x] call CBA_fnc_ownerEvent;
            _sent=_sent+1;
        } forEach BURNS_ReinforcementGroups;
    }] call CBA_fnc_addEventHandler;

    // HC registration
    ["FST_HC_evt_registerHC", {
        _this call FST_HCSpawn_fnc_registerHC;
    }] call CBA_fnc_addEventHandler;

    // Group tracking (from HC after creating a group). HCs send group netIds so
    // the server can retry if the group object has not resolved yet.
    ["FST_HC_evt_trackGroup", {
        _this call FST_HCSpawn_fnc_trackGroup;
    }] call CBA_fnc_addEventHandler;

    // Spawn request (from Zeus client). Arg 7 is the claimed source owner.
    ["FST_HC_evt_spawn", {
        if !([_this param [7, -1], "spawn"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_spawnGroupOnTarget;
    }] call CBA_fnc_addEventHandler;

    // Zeus placed group handoff. Keeps the original group and transfers ownership instead of cloning.
    ["FST_HC_evt_queueZeusGroup", {
        if !([_this param [1, -1], "queueZeusGroup"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
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

    // Quick spawn template (from Zeus client) -- resolves template inline
    ["FST_HC_evt_quickSpawn", {
        params ["_pos", "_templateKey", "_behavior", ["_radius", -1], ["_callerID", -1]];
        if !([_callerID, "quickSpawn"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        private _template = FST_HC_Templates getOrDefault [_templateKey, []];
        if (count _template == 0) exitWith {
            diag_log format ["[FST_HCSpawn] Unknown template '%1'", _templateKey];
        };
        _template params ["_side", "_unitClasses", "_desc"];
        // _callerID is passed as source owner so cap/no-HC feedback reaches the Zeus.
        [_side, _unitClasses, _pos, _behavior, _radius, [], [], _callerID] call FST_HCSpawn_fnc_spawnGroupOnTarget;
    }] call CBA_fnc_addEventHandler;

    // Fill garrison request (from Zeus client)
    ["FST_HC_evt_fillGarrison", {
        if !([_this param [3, -1], "fillGarrison"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_requestFillGarrison;
    }] call CBA_fnc_addEventHandler;

    // Frontline assault (from Zeus client)
    ["FST_HC_evt_frontline", {
        if !([_this param [5, -1], "frontline"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_frontlineSpawn;
    }] call CBA_fnc_addEventHandler;

    // QRF (from Zeus client)
    ["FST_HC_evt_qrf", {
        if !([_this param [6, -1], "qrf"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_qrfSpawn;
    }] call CBA_fnc_addEventHandler;

    // V28: crewed AI vehicle spawn (from Zeus client or server script). Arg 6 is the claimed owner.
    ["FST_HC_evt_spawnVehicle", {
        if !([_this param [6, -1], "spawnVehicle"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_spawnVehicleOnTarget;
    }] call CBA_fnc_addEventHandler;

    // V28: explicit Zeus request to move a placed vehicle group to the vehicle HC.
    ["FST_HC_evt_sendToVehicleHC", {
        if !([_this param [1, -1], "sendToVehicleHC"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_sendToVehicleHC;
    }] call CBA_fnc_addEventHandler;

    // V28: an HC asks the server to move a (now dismounted) group it built off
    // the vehicle HC. Goes through the normal queue; transferGroup honours the
    // FST_HC_rehome marker only for foot groups sitting on the vehicle HC.
    ["FST_HC_evt_requeueGroup", {
        params ["_groupRef"];
        private _grp = if (_groupRef isEqualType "") then { groupFromNetId _groupRef } else { _groupRef };
        if (FST_HC_DebugLogging) then { diag_log format ["[FST_HCSpawn] Re-home request %1 -> %2 (owner %3)", _groupRef, _grp, groupOwner _grp]; };
        if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) exitWith {};
        if ((_grp getVariable ["FST_HC_heldBy", -1]) != -1) exitWith {};
        _grp setVariable ["FST_HC_rehome", true];
        _grp setVariable ["FST_HC_tracked", nil];
        _grp setVariable ["FST_HC_onHC", nil];
        // Drop it from the tracked list too, or the next recount re-marks it as
        // tracked before the transfer processor gets to it.
        if (!isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = FST_HC_TrackedGroups - [_grp]; };
        _grp setVariable ["FST_HC_pendingTransfer", true];
        FST_HC_TransferQueue pushBackUnique _grp;
    }] call CBA_fnc_addEventHandler;

    // Zeus hold/release (from Zeus client)
    ["FST_HC_evt_zeusHold", {
        if !([_this param [1, -1], "zeusHold"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_zeusHold;
    }] call CBA_fnc_addEventHandler;

    // Status report request (from Zeus/admin client)
    ["FST_HC_evt_statusReport", {
        if !([_this param [0, -1], "statusReport"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_statusReport;
    }] call CBA_fnc_addEventHandler;

    // Manual/rare dead-group maintenance cleanup (from Zeus/admin client).
    ["FST_HC_evt_manualDeadGroupCleanup", {
        if !([_this param [3, -1], "manualDeadGroupCleanup"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_requestDeadGroupCleanup;
    }] call CBA_fnc_addEventHandler;

    // Force a recount after HC-side cleanup deletes spawned units.
    // V27: debounced. Fill Garrison batches, floating-droid cleanups and clone
    // rejections can fire this several times per second; one recount 0.5s later
    // covers all of them.
    ["FST_HC_evt_recountUnits", {
        if (missionNamespace getVariable ["FST_HC_RecountScheduled", false]) exitWith {};
        missionNamespace setVariable ["FST_HC_RecountScheduled", true];
        [{
            missionNamespace setVariable ["FST_HC_RecountScheduled", false];
            [] call FST_HCSpawn_fnc_recountUnits;
        }, [], 0.5] call CBA_fnc_waitAndExecute;
    }] call CBA_fnc_addEventHandler;

    // Debug snapshot request (from Zeus/admin client)
    ["FST_HC_evt_debugSnapshotRequest", {
        if !([_this param [0, -1], "debugSnapshot"] call FST_HCSpawn_fnc_isAuthorizedCaller) exitWith {};
        _this call FST_HCSpawn_fnc_requestDebugSnapshot;
    }] call CBA_fnc_addEventHandler;
};

// ============================================================
// HC / CLIENT EVENTS (fired from server, handled on HC or Zeus)
// ============================================================

["BURNS_order", {
    params ["_mode","_group","_pos","_radius","_options","_caller",["_hop",0]];
    if (isNull _group) exitWith {};
    if (!local _group) exitWith {
        // A transfer may race dispatch. Only the server can resolve groupOwner.
        // Send one retry through it; never use owner 0 or broadcast the order.
        if (_hop<1) then {["BURNS_rerouteOrder",[_mode,_group,_pos,_radius,_options,_caller,1]] call CBA_fnc_serverEvent};
    };
    if (_mode=="artillery_fire") exitWith {[_group,_pos,_options,_caller] call FST_HCSpawn_fnc_burnsArtillery};
    private _ok=[_mode,_group,_pos,_radius,_options] call FST_HCSpawn_fnc_burnsCommand;
    if (!_ok) then {"[BURNS] Order declined: group held by Zeus, player controlled, or invalid task." remoteExec ["systemChat",_caller]};
}] call CBA_fnc_addEventHandler;
["BURNS_unitAI", {
    params ["_unit","_enabled"];
    if (!local _unit || {isPlayer _unit} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"}) exitWith {};
    if ([group _unit] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
    _unit setVariable ["BURNS_exempt",!_enabled,true];
    if (_enabled) then {[group _unit] call FST_HCSpawn_fnc_burnsApplyRole} else {
        [_unit] call FST_HCSpawn_fnc_burnsRestoreRole;
    };
}] call CBA_fnc_addEventHandler;

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
// V28: build a whole QRF on the vehicle HC (received via ownerEvent). Spawned: uses sleep.
["FST_HC_evt_qrfBuildLocal", {
    _this spawn FST_HCSpawn_fnc_qrfBuildLocal;
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
            _x setVariable ["FST_skipSpawnDamage", true];
            deleteVehicle _x;
        };
    } forEach units _grp;
    deleteGroup _grp;
    ["FST_HC_evt_recountUnits", []] call CBA_fnc_serverEvent;
}] call CBA_fnc_addEventHandler;

// Emergency droid stabilization after locality transfer or HC-side creation.
["FST_HC_evt_emergencyStabilizeGroupLocal", {
    params ["_group"];
    [{
        params ["_group"];
        if (!isNull _group) then {
            [_group] call FST_HCSpawn_fnc_emergencyStabilizeGroup;
        };
    }, [_group], 0.25] call CBA_fnc_waitAndExecute;
}] call CBA_fnc_addEventHandler;

// Loadout restore after locality transfer (received by target HC via ownerEvent).
// V27: only re-applies when the locality change actually stripped something
// (weapon, uniform, vest or backpack differs from the snapshot taken on the
// server), and routes through applyUnitLoadoutSafe so the droid empty-loadout
// guard applies here too. The old check only fired when the uniform was empty,
// which is always true for droids and never true for uniformed units.
["FST_HC_evt_restoreLoadout", {
    params ["_payload"];
    [{
        params ["_payload"];
        private _containerClass = {
            if (_this isEqualType [] && {count _this > 0}) then { _this select 0 } else { "" }
        };
        {
            _x params ["_unit", "_loadout"];
            if (isNull _unit || {!local _unit} || {!alive _unit} || {count _loadout < 6}) then { continue };

            private _stripped =
                (primaryWeapon _unit) != ((_loadout select 0) call _containerClass) ||
                {(secondaryWeapon _unit) != ((_loadout select 1) call _containerClass)} ||
                {(handgunWeapon _unit) != ((_loadout select 2) call _containerClass)} ||
                {(uniform _unit) != ((_loadout select 3) call _containerClass)} ||
                {(vest _unit) != ((_loadout select 4) call _containerClass)} ||
                {(backpack _unit) != ((_loadout select 5) call _containerClass)};

            if (_stripped) then {
                [_unit, _loadout, "", "transfer restore"] call FST_HCSpawn_fnc_applyUnitLoadoutSafe;
            } else {
                [_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid;
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
