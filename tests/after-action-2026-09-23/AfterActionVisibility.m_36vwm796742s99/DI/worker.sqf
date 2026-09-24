DI_workerActions = createHashMap;
DI_workerOrderRevisions = createHashMap;
DI_workerOrderResults = createHashMap;
DI_fnc_workerHooks = {
    waitUntil {sleep 1;!isNil "CBA_fnc_addEventHandler"};
    ["BURNS_order",{
        params ["_mode","_group","_pos","_radius","_options","_caller"];
        if (isNull _group || {!local _group} || {_caller <= 2} || {_group getVariable ["DI_operation",""] == ""}) exitWith {};
        // Relinquish immediately on the owning machine, before a delayed DI order.
        _group setVariable ["DI_humanUntil",serverTime+120,true];
        _group setVariable ["DI_lease",1+(_group getVariable ["DI_lease",1]),true];
        [_group,clientOwner,_caller] remoteExecCall ["DI_fnc_humanOrderReport",2];
    }] call CBA_fnc_addEventHandler;
};
DI_fnc_workerHeartbeat = {
    waitUntil {sleep 1;clientOwner > 2};
    ["HEARTBEAT_STARTED",[clientOwner]] call DI_fnc_log;
    while {true} do {
        [clientOwner,diag_fps,DI_version] remoteExecCall ["DI_fnc_heartbeat",2];
        sleep 10;
    };
};
DI_fnc_workerSpawn = {
    if (!isRemoteExecuted || {remoteExecutedOwner != 2}) exitWith {};
    params ["_op","_id","_nonce","_generation","_template","_pos","_objective","_owner"];
    if (hasInterface || {_owner != clientOwner} || {_op != (missionNamespace getVariable ["DI_operation",""])}) exitWith {};
    private _existing = DI_workerActions getOrDefault [_id,[]];
    if (count _existing > 0 && {_existing select 1 != "awaiting_grant"}) exitWith {
        [_op,_id,_nonce,clientOwner,_existing select 0,_existing select 1] remoteExecCall ["DI_fnc_spawnAck",2];
    };
    DI_workerActions set [_id,[grpNull,"awaiting_grant"]];
    [_op,_id,_nonce,clientOwner] remoteExecCall ["DI_fnc_spawnGrant",2];
};
DI_fnc_workerCreate = {
    if (!isRemoteExecuted || {remoteExecutedOwner != 2}) exitWith {};
    params ["_op","_id","_nonce","_generation","_template","_pos","_objective","_owner","_expires","_readyAtGrant","_diagnostic"];
    if (_owner != clientOwner || {_op != (missionNamespace getVariable ["DI_operation",""])}) exitWith {};
    if (hasInterface) exitWith {};
    private _existing = DI_workerActions getOrDefault [_id,[]];
    if (count _existing > 0 && {_existing select 1 != "awaiting_grant"}) exitWith {
        [_op,_id,_nonce,clientOwner,_existing select 0,_existing select 1] remoteExecCall ["DI_fnc_spawnAck",2];
    };
    DI_workerActions set [_id,[grpNull,"reserved"]];
    private _humans = [] call DI_fnc_humans;
    private _readyNow = {alive _x && {!([_x] call DI_fnc_unconscious)} &&
        {!((vehicle _x) isKindOf "Air")} && {!([getPosASL _x,350] call DI_fnc_nearBase)}} count _humans;
    if (serverTime > _expires || {diag_fps < DI_minWorkerFPS} ||
        {!([_pos,_humans] call DI_fnc_positionClear)} ||
        {!(_diagnostic && {DI_testMode}) && {_readyNow < _readyAtGrant || {_readyNow == 0}}} ||
        {_generation != (missionNamespace getVariable ["DI_generation",-1]) ||
        {(missionNamespace getVariable ["DI_mode","shadow"]) != "active"} ||
        {(missionNamespace getVariable ["DI_phase","briefing"]) != "active"}}) exitWith {
        DI_workerActions set [_id,[grpNull,"cancelled_before_create"]];
        [_op,_id,_nonce,clientOwner,grpNull,"cancelled_before_create"] remoteExecCall ["DI_fnc_spawnAck",2];
    };
    private _t = FST_HC_Templates getOrDefault [_template,[]];
    if (count _t < 2 || {((_t select 1) findIf {!isClass (configFile >> "CfgVehicles" >> _x)}) >= 0}) exitWith {
        DI_workerActions set [_id,[grpNull,"invalid_template"]];
        [_op,_id,_nonce,clientOwner,grpNull,"invalid_template"] remoteExecCall ["DI_fnc_spawnAck",2];
    };
    // Instrumented frozen creation helper preserves BURNS/WebKnight ownership behavior.
    private _diAction = [_op,_id,_nonce,_objective];
    private _group = [_t select 0,_t select 1,_pos,"none",120,[],true,clientOwner,-1,[],-1,[]] call DI_fnc_createGroupLocal;
    if (isNil "_group" || {!(_group isEqualType grpNull)} || {isNull _group}) then {_group = grpNull};
    private _status = if (isNull _group) then {"creation_failed"} else {"created"};
    DI_workerActions set [_id,[_group,_status]];
    [_op,_id,_nonce,clientOwner,_group,_status] remoteExecCall ["DI_fnc_spawnAck",2];
    // Exact-identity retransmission tolerates group-reference replication delay.
    // This never retries creation; server acknowledgement is idempotent.
    [_op,_id,_nonce,_group,_status] spawn {
        params ["_op","_id","_nonce","_group","_status"];
        for "_retry" from 1 to 6 do {
            sleep 5;
            [_op,_id,_nonce,clientOwner,_group,_status] remoteExecCall ["DI_fnc_spawnAck",2];
        };
    };
    ["WORKER_SPAWN",[_id,_template,_status,if (isNull _group) then {0} else {count units _group}]] call DI_fnc_log;
};
DI_fnc_workerOrder = {
    if (!isRemoteExecuted || {remoteExecutedOwner != 2}) exitWith {};
    params ["_op","_group","_lease","_revision","_intent","_target","_radius"];
    if (_op != (missionNamespace getVariable ["DI_operation",""]) || {isNull _group} || {!local _group}) exitWith {};
    if !([_group] call DI_fnc_groupControllable) exitWith {};
    if (_group getVariable ["DI_humanUntil",0] > serverTime ||
        {_group getVariable ["DI_lease",0] != _lease} ||
        {(_group getVariable ["FST_HC_heldBy",-1]) != -1} ||
        {(units _group findIf {[_x] call DI_fnc_isPlayerControlledUnit}) >= 0}) exitWith {};
    private _key = netId _group;
    private _lastRevision = DI_workerOrderRevisions getOrDefault [_key,-1];
    if (_revision <= _lastRevision) exitWith {
        if (_revision == _lastRevision) then {
            [_op,_group,clientOwner,_revision,DI_workerOrderResults getOrDefault [_key,false]] remoteExecCall ["DI_fnc_orderAck",2];
        };
    };
    DI_workerOrderRevisions set [_key,_revision];
    private _ok = false;
    if (_intent == "stop") then {
        _ok = [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
    } else {
        if ((missionNamespace getVariable ["DI_mode","shadow"]) == "active" &&
            {(missionNamespace getVariable ["DI_phase","briefing"]) == "active"}) then {
            _group setVariable ["BURNS_taskOptions",[false,true,false],true];
            _ok = [_intent,_group,_target,_radius,[false,true,false]] call FST_HCSpawn_fnc_burnsCommand;
        };
    };
    ["WORKER_ORDER",[_key,_revision,_intent,_ok]] call DI_fnc_log;
    DI_workerOrderResults set [_key,_ok];
    [_op,_group,clientOwner,_revision,_ok] remoteExecCall ["DI_fnc_orderAck",2];
};
