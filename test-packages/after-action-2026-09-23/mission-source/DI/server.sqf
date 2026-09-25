DI_fnc_knownGroup = {
    params ["_group"];
    if (isNull _group || {_group getVariable ["DI_operation",""] != DI_operation}) exitWith {false};
    if (_group in DI_groups) exitWith {true};
    private _r = DI_actions getOrDefault [_group getVariable ["DI_action",""],createHashMap];
    count _r > 0 && {_r get "nonce" == _group getVariable ["DI_nonce",""]} &&
    {_r get "owner" == groupOwner _group} && {!(_r getOrDefault ["settled",false])}
};
DI_fnc_reconcileOrders = {
    if (!isServer || {DI_mode != "active"} || {DI_phase != "active"}) exitWith {};
    private _ready = count (([] call DI_fnc_observe) get "ready");
    if (_ready == 0 && {!DI_testMode}) exitWith {};
    {
        if (!(_x getVariable ["DI_needsOrder",false]) || {!([_x] call DI_fnc_groupControllable)} ||
            {_x getVariable ["DI_humanUntil",0] > serverTime} ||
            {_x getVariable ["FST_HC_heldBy",-1] != -1}) then {continue};
        private _o = DI_objectives getOrDefault [_x getVariable ["DI_objective",""],createHashMap];
        if (count _o > 0 && {!(_o get "complete")}) then {
            if ([_x,"defend",_o get "position",120] call DI_fnc_order) then {_x setVariable ["DI_needsOrder",false]};
        };
    } forEach DI_groups;
};
DI_fnc_heartbeat = {
    if (DI_testMode && {isNil "DI_heartbeatDebug"}) then {DI_heartbeatDebug = true;["HEARTBEAT_RECEIVED",[isServer,isRemoteExecuted,remoteExecutedOwner,_this,missionNamespace getVariable ["FST_HC_Ids",[]]]] call DI_fnc_log};
    // HC packets report origin 0 and isRemoteExecuted=false on this engine build.
    // Accept only owners already verified by BURNS against an actual HC entity.
    if (!isServer) exitWith {};
    params ["_owner","_fps","_version"];
    if !(_owner in (missionNamespace getVariable ["FST_HC_Ids",[]])) exitWith {};
    if !(remoteExecutedOwner in [0,_owner]) exitWith {};
    DI_workers set [str _owner,[time,_fps,_version]];
};
DI_fnc_spawnAck = {
    if (!isServer) exitWith {};
    params ["_op","_id","_nonce","_owner","_group","_status"];
    if (_op != DI_operation) exitWith {};
    private _record = DI_actions getOrDefault [_id,createHashMap];
    if (count _record == 0 || {_record get "nonce" != _nonce} || {_record get "owner" != _owner}) exitWith {};
    if !(_owner in (missionNamespace getVariable ["FST_HC_Ids",[]]) && {remoteExecutedOwner in [0,_owner]}) exitWith {};
    if (_record getOrDefault ["settled",false]) exitWith {};
    private _diAuthorized = true;
    if (!isNull _group) then {
        if (groupOwner _group != _owner || {_group getVariable ["DI_action",""] != _id} ||
            {_group getVariable ["DI_nonce",""] != _nonce} || {_group getVariable ["DI_operation",""] != _op}) exitWith {};
        _record set ["group",_group];
        _record set ["actualCount",count units _group];
        _record set ["state",if (count units _group == (_record get "count")) then {"created"} else {"partial_creation"}];
        _record set ["settled",true];
        DI_lastProposal = time; // Cooldown begins only after a confirmed wave.
        DI_groups pushBackUnique _group;
        // Identity/lease were initialized before creation. A delayed ACK must
        // never clear a Zeus takeover made while replication was in flight.
        _group setVariable ["DI_needsOrder",true];
        _group setVariable ["BURNS_reinforcement",false,true];
        if ((_record get "template") == "b2_team") then {DI_b2Teams = DI_b2Teams + 1} else {DI_b1Squads = DI_b1Squads + 1};
        if (DI_mode == "active" && {DI_phase == "active"} && {_record get "generation" == DI_generation}) then {
            [] call DI_fnc_reconcileOrders;
        } else {
            [_group,"stop",getPosATL leader _group,100] call DI_fnc_order;
        };
    } else {
        if (_status in ["cancelled_before_create","invalid_template","creation_failed"]) then {
            _record set ["state",_status];
            _record set ["settled",true];
            [] call FST_HCSpawn_fnc_recountUnits;
        };
    };
    ["SPAWN_ACK",[_id,_status,_record getOrDefault ["actualCount",0]]] call DI_fnc_log;
};
DI_fnc_orderAck = {
    if (!isServer) exitWith {};
    params ["_op","_group","_owner","_revision","_ok"];
    if (_op != DI_operation || {isNull _group} || {groupOwner _group != _owner}) exitWith {};
    if !(remoteExecutedOwner in [0,_owner]) exitWith {};
    if !(_group in DI_groups) exitWith {};
    _group setVariable ["DI_orderAck",[_revision,_ok,time]];
};
DI_fnc_humanOrderReport = {
    if (!isServer) exitWith {};
    params ["_group","_owner","_caller"];
    if (isNull _group || {!([_group] call DI_fnc_knownGroup)} || {groupOwner _group != _owner}) exitWith {};
    if !(_owner in (missionNamespace getVariable ["FST_HC_Ids",[]]) && {remoteExecutedOwner in [0,_owner]}) exitWith {};
    if (_caller <= 2) exitWith {};
    if !(admin _caller > 0 || {(allCurators findIf {owner getAssignedCuratorUnit _x == _caller}) >= 0}) exitWith {};
    _group setVariable ["DI_humanUntil",serverTime+120,true];
    _group setVariable ["DI_lease",1+(_group getVariable ["DI_lease",1]),true];
    _group setVariable ["DI_pendingOrder",nil];
    _group setVariable ["DI_needsOrder",false];
    ["HUMAN_TAKEOVER",[netId _group,"BURNS order",120]] call DI_fnc_log;
};
DI_fnc_order = {
    if (!isServer || {remoteExecutedOwner > 2 && {isNil "_diAuthorized"}}) exitWith {false};
    params ["_group","_intent","_target",["_radius",150]];
    if !([_group] call DI_fnc_groupControllable) exitWith {false};
    if (isNull _group || {_group getVariable ["DI_humanUntil",0] > serverTime} || {_group getVariable ["FST_HC_heldBy",-1] != -1}) exitWith {false};
    if ((units _group findIf {[_x] call DI_fnc_isPlayerControlledUnit}) >= 0) exitWith {false};
    if (_intent == "stop") then {_group setVariable ["DI_needsOrder",true]};
    private _revision = 1 + (_group getVariable ["DI_orderRevision",0]);
    _group setVariable ["DI_orderRevision",_revision];
    _group setVariable ["DI_pendingOrder",[_intent,_target,_radius,_revision,time,_group getVariable ["DI_lease",1],0]];
    [DI_operation,_group,_group getVariable ["DI_lease",1],_revision,_intent,_target,_radius]
        remoteExecCall ["DI_fnc_workerOrder",groupOwner _group];
    true
};
DI_fnc_setPhase = {
    if (!isServer || {remoteExecutedOwner > 2 && {isNil "_diAuthorized"}}) exitWith {};
    params ["_phase","_why"];
    if (DI_phase == _phase || {DI_phase == "ended"}) exitWith {};
    DI_phase = _phase;
    DI_generation = DI_generation + 1;
    publicVariable "DI_generation";
    publicVariable "DI_phase";
    if (_phase != "active") then {
        {[_x,"stop",getPosATL leader _x,100] call DI_fnc_order} forEach (DI_groups select {!isNull _x});
    };
    if (_phase == "active") then {[] call DI_fnc_reconcileOrders};
    ["PHASE",[_phase,_why]] call DI_fnc_log;
};
DI_fnc_completeObjective = {
    if (!isServer || {remoteExecutedOwner > 2 && {isNil "_diAuthorized"}}) exitWith {false};
    params ["_id"];
    if !(_id isEqualType "" && {_id in DI_objectives} && {DI_phase != "ended"}) exitWith {false};
    private _o = DI_objectives get _id;
    if !(_o get "complete") then {
        _o set ["complete",true]; _o set ["completedAt",time];
        DI_completed pushBackUnique _id;
        publicVariable "DI_completed";
        ["OBJECTIVE_COMPLETE",[_id,count DI_completed]] call DI_fnc_log;
        DI_lastReport = -30;
    };
    true
};
DI_fnc_context = {
    private _rows = [];
    {
        private _h = DI_squadHistory getOrDefault [_x,[0,false,0]];
        _rows pushBack [_x,_y select 1,_y select 2,_y select 3,_h select 0,[_x] call DI_fnc_elite];
    } forEach (DI_snapshot get "squads");
    [DI_operation,DI_stepoffTime,DI_baseline,DI_snapshot get "cohort",DI_snapshot get "unavailable",7200,_rows,1]
};
DI_fnc_command = {
    if (!isServer || {!isRemoteExecuted}) exitWith {};
    params ["_actor","_command",["_argument",""]];
    if !([_actor,remoteExecutedOwner] call DI_fnc_authorized) exitWith {};
    private _diAuthorized = true;
    if !(_command in ["active","shadow","hold","resume","stepoff","complete","status","manual","end"]) exitWith {};
    if (DI_phase == "ended" && {!(_command in ["status","end","shadow"])}) exitWith {};
    switch (_command) do {
        case "active": {
            if !([] call DI_fnc_capabilityReady) exitWith {};
            DI_mode = "active";
            DI_generation = DI_generation + 1;
            publicVariable "DI_mode";
            publicVariable "DI_generation";
            [] call DI_fnc_reconcileOrders;
        };
        case "shadow": {
            DI_mode = "shadow";
            DI_generation = DI_generation + 1;
            publicVariable "DI_mode";
            publicVariable "DI_generation";
            {[_x,"stop",getPosATL leader _x,100] call DI_fnc_order} forEach (DI_groups select {!isNull _x});
        };
        case "end": {
            DI_mode = "shadow"; publicVariable "DI_mode";
            ["ended","Zeus ended operation"] call DI_fnc_setPhase;
        };
        case "hold": {["paused","Zeus hold"] call DI_fnc_setPhase};
        case "resume": {
            if (DI_phase == "paused") then {[if (DI_stepoffTime < 0) then {"briefing"} else {"active"},"Zeus resume"] call DI_fnc_setPhase};
        };
        case "stepoff": {
            if (DI_stepoffTime < 0) then {
                DI_stepoffTime = time;
                DI_baseline = (count ([] call DI_fnc_humans)) max 1;
                ["active","Zeus confirmed step-off"] call DI_fnc_setPhase;
            };
        };
        case "complete": {
            if ([_argument] call DI_fnc_completeObjective) then {
                format ["DAARA secured: %1 (%2/15)",_argument,count DI_completed] remoteExecCall ["systemChat",owner _actor];
            };
        };
        case "manual": {
            if !(_argument isEqualType grpNull) exitWith {};
            if (isNull _argument || {!([_argument] call DI_fnc_knownGroup)}) exitWith {};
            _argument setVariable ["DI_humanUntil",serverTime+120,true];
            _argument setVariable ["DI_lease",1+(_argument getVariable ["DI_lease",1]),true];
            _argument setVariable ["DI_pendingOrder",nil];
            _argument setVariable ["DI_needsOrder",false];
            ["HUMAN_TAKEOVER",[netId _argument,120]] call DI_fnc_log;
        };
    };
    ["ADMIN",[_command,owner _actor]] call DI_fnc_log;
    (missionNamespace getVariable ["DI_statusText","Daara starting"]) remoteExecCall ["systemChat",owner _actor];
};
DI_fnc_observe = {
    if (!isServer || {remoteExecutedOwner > 2 && {isNil "_diAuthorized"}}) exitWith {createHashMap};
    private _humans = [] call DI_fnc_humans;
    private _ready = [];
    private _waiting = 0;
    private _incap = 0;
    private _transport = 0;
    private _deployed = 0;
    private _pilots = 0;
    private _cohort = 0;
    private _unavailable = 0;
    private _squads = createHashMap;
    {
        private _unit = _x;
        private _uid = getPlayerUID _unit;
        if (DI_testMode && {_uid == ""}) then {_uid = netId _unit};
        _unit setVariable ["DI_uid",_uid];
        private _entry = DI_roster getOrDefault [_uid,createHashMapFromArray [["died",false],["deployedEver",false],["pilot",false]]];
        _entry set ["lastSeen",time];
        _entry set ["unit",_unit];
        private _base = [getPosASL _unit,350] call DI_fnc_nearBase;
        private _air = (vehicle _unit) isKindOf "Air";
        private _pilot = _air && {driver vehicle _unit == _unit};
        if (!_base && {DI_stepoffTime >= 0}) then {_entry set ["deployedEver",true]};
        if (_pilot) then {_entry set ["pilot",true]};
        if (alive _unit && {!([_unit] call DI_fnc_unconscious)} && {_entry get "pilot"}) then {_pilots = _pilots + 1};
        private _state = "dead";
        if (alive _unit) then {
            if ([_unit] call DI_fnc_unconscious) then {
                _state = "incapacitated";
                if (!_base) then {_incap = _incap + 1};
            } else {
                if (_air) then {_state = "transport"; _transport = _transport + 1} else {
                    if (_base) then {
                        _state = if (_entry get "died") then {"waiting"} else {"briefing"};
                        if (_state == "waiting") then {_waiting = _waiting + 1};
                    } else {
                        _state = "ready";
                        _ready pushBack _unit;
                        _entry set ["deployedEver",true];
                        _entry set ["died",false];
                    };
                };
            };
        };
        if (!_base && {alive _unit}) then {_deployed = _deployed + 1};
        _entry set ["state",_state];
        // A deployed player remains in the cohort through death, base waiting
        // and reinsertion. Disconnects leave the live denominator immediately.
        if (_entry get "deployedEver") then {
            _cohort = _cohort + 1;
            if (_state in ["dead","incapacitated","waiting"] || {_state == "transport" && {_entry get "died"}}) then {_unavailable = _unavailable + 1};
        };
        DI_roster set [_uid,_entry];
        private _gid = groupId group _unit;
        private _s = _squads getOrDefault [_gid,[groupId group _unit,0,0,0]];
        if (_entry get "deployedEver") then {
            _s set [1,(_s select 1)+1];
            if (_state == "ready") then {_s set [2,(_s select 2)+1]};
            if (_state in ["incapacitated","dead","waiting"] || {_state == "transport" && {_entry get "died"}}) then {_s set [3,(_s select 3)+1]};
        };
        _squads set [_gid,_s];
    } forEach _humans;
    // Track distinct full-squad episodes; never count repeated polling ticks.
    {
        private _s = _y;
        private _history = DI_squadHistory getOrDefault [_x,[0,false,0]];
        if ((_s select 1) >= 2 && {(_s select 2) == 0} && {(_s select 3) >= (_s select 1)}) then {
            if !(_history select 1) then {
                if ((_history select 2) == 0) then {_history set [2,time]};
                if (time - (_history select 2) >= 15) then {
                    _history set [0,(_history select 0)+1];
                    _history set [1,true];
                    ["SQUAD_COLLAPSE",[_s select 0,_history select 0]] call DI_fnc_log;
                };
            };
        } else {
            _history set [2,0];
            if ((_s select 2) >= 2) then {_history set [1,false]};
        };
        DI_squadHistory set [_x,_history];
    } forEach _squads;
    createHashMapFromArray [["humans",_humans],["ready",_ready],["waiting",_waiting],
        ["incapacitated",_incap],["transport",_transport],["deployed",_deployed],["pilots",_pilots],["squads",_squads],["cohort",_cohort],["unavailable",_unavailable]]
};
DI_fnc_dispatchSpawn = {
    params ["_objective","_template","_pos","_count",["_diagnostic",false]];
    if (!isServer || {isRemoteExecuted && {remoteExecutedOwner != 2}} || {DI_mode != "active"} || {DI_phase != "active"}) exitWith {false};
    private _eligible = [_count] call DI_fnc_eligibleWorkers;
    if (count _eligible == 0) exitWith {false};
    private _owner = _eligible select 0;
    private _id = format ["%1:%2",DI_operation,DI_actionSequence];
    DI_actionSequence = DI_actionSequence + 1;
    private _nonce = format ["%1:%2",diag_tickTime,random 1e9];
    private _o = DI_objectives get _objective;
    DI_actions set [_id,createHashMapFromArray [["nonce",_nonce],["owner",_owner],["count",_count],
        ["state","dispatched"],["settled",false],["createdAt",time],["generation",DI_generation],
        ["template",_template],["target",_o get "position"],["objective",_objective],
        ["position",_pos],["diagnostic",DI_testMode && {_diagnostic}],["lastSent",time]]];
    private _index = FST_HC_Ids find _owner;
    if (_index >= 0) then {FST_HC_UnitCounts set [_index,(FST_HC_UnitCounts select _index)+_count]};
    [DI_operation,_id,_nonce,DI_generation,_template,_pos,_objective,_owner] remoteExecCall ["DI_fnc_workerSpawn",_owner];
    ["SPAWN_DISPATCH",[_id,_objective,_template,_count,_owner,_pos]] call DI_fnc_log;
    true
};
DI_fnc_plan = {
    if (!isServer || {remoteExecutedOwner > 2}) exitWith {};
    params ["_snapshot","_policy"];
    private _ready = _snapshot get "ready";
    private _pending = 0;
    {if !(_y getOrDefault ["settled",false]) then {_pending = _pending + (_y get "count")}} forEach DI_actions;
    private _hints = [_ready] call DI_fnc_mapHints;
    ([_ready,_hints] call DI_fnc_pressureEnemies) params ["_enemy","_engaged"];
    private _budget = _policy get "readyBudget";
    private _workers = count ([0] call DI_fnc_eligibleWorkers);
    private _rows = [];
    private _reason = "no_eligible_objective";
    if !(_policy get "infantryAllowed") exitWith {
        [if (DI_phase == "active") then {"no_ready_players"} else {"phase_" + DI_phase},_budget,count _engaged,count _enemy,_pending,_workers] call DI_fnc_directorReport;
    };
    if (time - DI_lastProposal < DI_spawnCooldown) exitWith {["cooldown",_budget,count _engaged,count _enemy,_pending,_workers] call DI_fnc_directorReport};
    if (DI_mode == "active" && {_pending > 0}) exitWith {["awaiting_spawn_ack",_budget,count _engaged,count _enemy,_pending,_workers] call DI_fnc_directorReport};
    private _ranked = [];
    {
        private _distance = 1e9; private _center = _y get "position";
        {_distance = _distance min (_x distance2D _center)} forEach _ready;
        _ranked pushBack [_distance - (if (_x in _hints) then {700} else {0}),_x];
    } forEach DI_objectives;
    _ranked sort true;
    private _prewarmed = 0;
    {
        private _g = _x;
        if (isNull _g || {{alive _x} count units _g == 0}) then {continue};
        private _pos = getPosATL leader _g;
        if ((_ready findIf {_x distance2D _pos < DI_objectiveActivationDistance}) < 0) then {_prewarmed = _prewarmed + 1};
    } forEach DI_groups;
    private _proposed = false;
    {
        if (_proposed) exitWith {};
        private _id = _x select 1; private _o = DI_objectives get _id;
        if (_o get "complete") then {continue};
        private _center = _o get "position";
        private _near = _ready select {_x distance2D _center < DI_objectiveActivationDistance};
        private _prewarm = count _near == 0;
        if (_prewarm && {_prewarmed < DI_mapPrewarmLimit}) then {_near = _hints getOrDefault [_id,[]]};
        if (count _near == 0) then {continue};
        private _strength = 0;
        {
            private _multiplier = if ([groupId group _x] call DI_fnc_elite) then {DI_eliteMultiplier} else {1};
            if ((DI_squadHistory getOrDefault [groupId group _x,[0,false,0]]) select 0 >= 2) then {_multiplier = _multiplier * 0.5};
            _strength = _strength + _multiplier;
        } forEach _near;
        private _localEnemy = {_x distance2D _center < DI_localForceRadius} count _enemy;
        private _localBudget = floor (_strength * DI_localReadyMultiplier);
        private _template = if (DI_enableB2 && {DI_b1Squads >= (DI_b2Teams + 1) * DI_b2EveryB1Squads}) then {"b2_team"} else {
            if (DI_b1Squads mod 2 == 0) then {"b1_squad_at"} else {"b1_squad"}
        };
        private _t = FST_HC_Templates getOrDefault [_template,[]];
        private _count = if (count _t > 1) then {count (_t select 1)} else {0};
        private _row = [_id,count _near,_localEnemy,_localBudget,_count,"eligible",_prewarm];
        _rows pushBack _row;
        if (_count <= 0) then {_row set [5,"missing_template"];continue};
        if (_count + _localEnemy + _pending > _localBudget) then {_row set [5,"local_capacity"];continue};
        if (_count + count _engaged + _pending > _budget) then {_row set [5,"engaged_capacity"];continue};
        if (count ([_count] call DI_fnc_eligibleWorkers) == 0) then {_row set [5,"worker_unavailable"];continue};
        private _pos = [_center,_snapshot get "humans"] call DI_fnc_safeSpawn;
        if (count _pos == 0) then {_row set [5,"no_safe_position"];continue};
        DI_lastProposalText = format ["%1: %2 (%3 units)",_o get "label",_template,_count];
        ["PROPOSAL",[DI_mode,_id,_template,_count,_strength,_localEnemy,_budget,_pos,if (_prewarm) then {"map_hint_preparation"} else {"proximity"}]] call DI_fnc_log;
        if (DI_mode == "active") then {
            _proposed = [_id,_template,_pos,_count] call DI_fnc_dispatchSpawn;
            _row set [5,if (_proposed) then {"dispatched"} else {"worker_unavailable"}];
        } else {_proposed = true;_row set [5,"shadow_only"];DI_lastProposal = time};
    } forEach _ranked;
    if (count _rows > 0) then {_reason = (_rows select (count _rows - 1)) select 5};
    if (_proposed) then {_reason = if (DI_mode == "active") then {"dispatched"} else {"shadow_only"}};
    [_reason,_budget,count _engaged,count _enemy,_pending,_workers,_rows] call DI_fnc_directorReport;
};
DI_fnc_tick = {
    if (!isServer || {remoteExecutedOwner > 2}) exitWith {};
    if (DI_testMode && {missionNamespace getVariable ["DI_testSuspend",false]}) exitWith {};
    {
        private _r = _y;
        if (!(_r getOrDefault ["settled",false]) && {time-(_r get "lastSent") >= 5} && {time-(_r get "createdAt") <= 30}) then {
            _r set ["lastSent",time];
            [DI_operation,_x,_r get "nonce",_r get "generation",_r get "template",_r get "position",_r get "objective",_r get "owner"]
                remoteExecCall ["DI_fnc_workerSpawn",_r get "owner"];
        };
    } forEach DI_actions;
    DI_snapshot = [] call DI_fnc_observe;
    private _humans = DI_snapshot get "humans";
    private _ready = count (DI_snapshot get "ready");
    private _connected = count _humans;
    if (DI_phase == "briefing" && {_connected > 0}) then {
        private _rosterIds = _humans apply {netId _x}; _rosterIds sort true;
        if !(_rosterIds isEqualTo DI_briefingRoster) then {
            DI_briefingRoster = _rosterIds; DI_rosterStableSince = time;
        };
        private _assembledNow = {alive _x && {!((vehicle _x) isKindOf "Air")} && {_x distance2D DI_base < 350}} count _humans;
        DI_assemblyPeak = DI_assemblyPeak max _assembledNow;
        // Seed at the known ship; learn the local assembly, never follow lone scouts.
        if (!DI_baseFrozen) then {
            private _assembled = _humans select {_x distance2D DI_base < 350 && {alive _x}};
            if (count _assembled >= (ceil (_connected * 0.6) max 1)) then {
                private _sx = 0; private _sy = 0; private _sz = 0;
                {_sx = _sx + ((getPosASL _x) select 0);_sy = _sy + ((getPosASL _x) select 1);_sz = _sz + ((getPosASL _x) select 2)} forEach _assembled;
                DI_base = [_sx/count _assembled,_sy/count _assembled,_sz/count _assembled];
                publicVariable "DI_base";
                if (DI_assemblyPeak >= DI_autoStepMinimum && {time - DI_rosterStableSince >= DI_assemblyPersistence}) then {DI_baseFrozen = true};
            };
        };
        private _departed = {alive _x && {!([_x] call DI_fnc_unconscious)} &&
            {_x distance2D DI_base > DI_stepoffDistance} &&
            {!((vehicle _x) isKindOf "Air") || {toLower ((assignedVehicleRole _x) param [0,""]) == "cargo"}}} count _humans;
        if ([_connected,DI_assemblyPeak,_departed,time-DI_rosterStableSince] call DI_fnc_departureEligible) then {
            if (DI_departedSince < 0) then {DI_departedSince = time};
            if (time - DI_departedSince >= DI_stepoffPersistence) then {
                DI_stepoffTime = time;DI_baseline = _connected;DI_baseFrozen = true;
                ["active","sustained substantial departure"] call DI_fnc_setPhase;
            };
        } else {DI_departedSince = -1};
    };
    if (DI_stepoffTime >= 0 && {time-DI_stepoffTime <= DI_baselineGrace}) then {
        DI_baseline = DI_baseline max _connected;
    };
    DI_deaths = DI_deaths select {_x > time - 7200};
    private _policy = [DI_phase,_ready,DI_snapshot get "waiting",_connected,count DI_deaths,DI_baseline] call DI_fnc_policy;
    private _field = DI_snapshot get "cohort";
    private _collapse = _field >= 4 && {(DI_snapshot get "unavailable") / _field >= 0.75};
    if (_collapse) then {if (DI_collapseSince < 0) then {DI_collapseSince = time}} else {DI_collapseSince = -1};
    if !(_policy get "catastrophicDeaths") then {DI_deathRecoveryLatched = false};
    if (DI_phase == "active" && {(_policy get "catastrophicDeaths" && {!DI_deathRecoveryLatched}) || {DI_collapseSince >= 0 && {time - DI_collapseSince >= 60}}}) then {
        DI_deathRecoveryLatched = _policy get "catastrophicDeaths";
        DI_recoveredSince = -1;
        ["recover","Tactical catastrophic recovery"] call DI_fnc_setPhase;
    };
    if (DI_phase == "recover") then {
        if (_ready >= ceil ((_connected max 1) * DI_recoveryReadyFraction) && {DI_snapshot get "waiting" <= 5}) then {
            if (DI_recoveredSince < 0) then {DI_recoveredSince = time};
            if (time - DI_recoveredSince >= DI_recoveryPersistence) then {["active","sustained restored readiness"] call DI_fnc_setPhase};
        } else {DI_recoveredSince = -1};
    };
    _policy = [DI_phase,_ready,DI_snapshot get "waiting",_connected,count DI_deaths,DI_baseline] call DI_fnc_policy;
    // Losses reduce admission immediately; returning/JIP players ramp it up.
    DI_pressureBudget = (DI_pressureBudget + 12 * DI_tickSeconds / 60) min (_policy get "readyBudget");
    _policy set ["readyBudget",floor DI_pressureBudget];
    if ([] call DI_fnc_capabilityReady) then {[DI_snapshot,_policy] call DI_fnc_plan} else {["capability_unavailable",0,0,0,0,0] call DI_fnc_directorReport};
    DI_groups = DI_groups select {!isNull _x};
    [] call DI_fnc_reconcileOrders;
    {
        private _pendingOrder = _x getVariable ["DI_pendingOrder",[]];
        private _ack = _x getVariable ["DI_orderAck",[-1,false,0]];
        if (count _pendingOrder == 7 && {[_x] call DI_fnc_groupControllable} && {_ack select 0 < _pendingOrder select 3} && {time-(_pendingOrder select 4) > 5} && {_pendingOrder select 6 < 4} && {_x getVariable ["DI_humanUntil",0] <= serverTime} && {_x getVariable ["DI_lease",1] == _pendingOrder select 5}) then {
            _pendingOrder params ["_intent","_target","_radius","_revision","_sent","_lease","_tries"];
            [DI_operation,_x,_lease,_revision,_intent,_target,_radius] remoteExecCall ["DI_fnc_workerOrder",groupOwner _x];
            _pendingOrder set [4,time];_pendingOrder set [6,_tries+1];
        };
        private _until = _x getVariable ["DI_humanUntil",0];
        if (_until > 0 && {serverTime >= _until} && {(_x getVariable ["FST_HC_heldBy",-1]) == -1} && {[_x] call DI_fnc_groupControllable}) then {
            _x setVariable ["DI_humanUntil",0,true];
            _x setVariable ["DI_lease",1+(_x getVariable ["DI_lease",1]),true];
            ["RECLAIM",[netId _x]] call DI_fnc_log;
            private _o = DI_objectives getOrDefault [_x getVariable ["DI_objective",""],createHashMap];
            if (DI_mode == "active" && {DI_phase == "active"} && {count _o > 0} && {!(_o get "complete")}) then {
                [_x,"defend",_o get "position",120] call DI_fnc_order;
            };
        };
    } forEach DI_groups;
    DI_statusText = format ["DAARA %1 | %2 / %3 | players %4, field ready %5, waiting %6, incap %7 | deaths %8 | objectives %9/15 | groups %10 | %11\nAir/armor modules: MANUAL, not controlled by this build.",
        DI_version,toUpper DI_mode,toUpper DI_phase,_connected,_ready,DI_snapshot get "waiting",DI_snapshot get "incapacitated",count DI_deaths,count DI_completed,count DI_groups,DI_lastProposalText];
    DI_statusText = DI_statusText + "<br/>" + DI_directorText;
    publicVariable "DI_statusText";
    if (time - DI_lastReport >= 30) then {
        DI_lastReport = time;
        ["CONTEXT",[] call DI_fnc_context] call DI_fnc_log;
        ["DIRECTOR",DI_directorTelemetry] call DI_fnc_log;
        ["STATUS",[DI_mode,DI_phase,_connected,_ready,DI_snapshot get "waiting",DI_snapshot get "incapacitated",count DI_deaths,count DI_completed,count DI_groups,diag_fps,DI_operation,+DI_completed]] call DI_fnc_log;
    };
};
DI_fnc_serverStart = {
    if (!isServer || {remoteExecutedOwner > 2} || {!isNil "DI_roster"}) exitWith {};
    DI_operation = format ["DI-%1-%2",worldName,floor random 1e8];
    DI_generation = 1; DI_mode = DI_defaultMode; DI_phase = "briefing";
    {publicVariable _x} forEach ["DI_operation","DI_generation","DI_mode","DI_phase"];
    DI_roster = createHashMap; DI_actions = createHashMap; DI_workers = createHashMap;
    DI_mapReports = createHashMap; DI_mapPositions = createHashMap; DI_pressureBudget = 0;
    DI_squadHistory = createHashMap; DI_objectives = createHashMap;
    {
        _x params ["_id","_label","_pos","_role"];
        _pos = [_pos select 0,_pos select 1,0]; // BURNS objectives are ground ATL.
        DI_objectives set [_id,createHashMapFromArray [["label",_label],["position",_pos],["role",_role],["complete",false]]];
    } forEach DI_objectiveDefinitions;
    DI_groups = []; DI_completed = []; publicVariable "DI_completed"; DI_deaths = [];
    DI_actionSequence = 1; DI_b1Squads = 0; DI_b2Teams = 0;
    DI_base = [601.80798,289.271,180.86099]; DI_baseFrozen = false;
    DI_briefingRoster = []; DI_rosterStableSince = time; DI_assemblyPeak = 0;
    DI_startTime = time; DI_stepoffTime = -1; DI_baseline = 0; DI_departedSince = -1;
    DI_collapseSince = -1; DI_recoveredSince = -1; DI_deathRecoveryLatched = false;
    DI_directorText = "Director starting"; DI_directorTelemetry = [];
    DI_lastProposal = -90; DI_lastReport = -30; DI_lastProposalText = "No proposal yet";
    addMissionEventHandler ["EntityKilled",{
        params ["_unit"];
        private _uid = _unit getVariable ["DI_uid",getPlayerUID _unit];
        if (_uid == "" || {!(_uid in DI_roster)} || {_unit getVariable ["DI_deathCounted",false]}) exitWith {};
        _unit setVariable ["DI_deathCounted",true];
        private _r = DI_roster get _uid;
        // Pre-step-off deaths do not create an operational reinsertion queue.
        // Keep the old-body dedup latch above this gate to reject late repeats.
        if (DI_stepoffTime >= 0) then {
            _r set ["died",true];
            DI_deaths pushBack time;
            ["PLAYER_DEATH",[count DI_deaths]] call DI_fnc_log;
        };
    }];
    // The engine copies the old body's variables to the respawned entity.
    // The old body's latch remains set so delayed death events stay deduplicated.
    // Re-arm only the distinct new body; do not synthesize a death or alter roster state.
    addMissionEventHandler ["EntityRespawned",{
        params ["_newUnit","_oldUnit"];
        if (isNull _newUnit || {_newUnit == _oldUnit}) exitWith {};
        _newUnit setVariable ["DI_deathCounted",false];
        private _uid = getPlayerUID _newUnit;
        if (_uid != "") then {_newUnit setVariable ["DI_uid",_uid]};
    }];
    ["SERVER_READY",[DI_operation,count DI_objectives,DI_mode]] call DI_fnc_log;
    sleep 2;
    while {true} do {call DI_fnc_tick;sleep DI_tickSeconds};
};
