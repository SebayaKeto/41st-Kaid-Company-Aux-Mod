// One owner-local scheduler. Idle role upkeep cannot consume tactical capacity.
params [["_allowClient",false]];
if (hasInterface && {!isServer} && {!_allowClient}) exitWith {};
if (missionNamespace getVariable ["FST_HC_combatSchedulerStarted",false]) exitWith {};
FST_HC_combatSchedulerStarted=true;
FST_HC_CombatGroups=[];
BURNS_ActiveGroups=[];
BURNS_DueGroups=[];
BURNS_PlayerPositions=[];
BURNS_Players=[];
BURNS_DownedPlayers=[];
FST_HC_CombatCursor=0;
BURNS_ActiveCursor=0;
FST_HC_CombatNextScan=0;
FST_HC_CombatUpdates=0;
FST_HC_CombatMaxTickMs=0;
BURNS_MaxServiceGap=0;
BURNS_MaxDueLateness=0;
[{
    private _started=diag_tickTime;
    private _enabled=missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true];
    if (time>=FST_HC_CombatNextScan) then {
        FST_HC_CombatNextScan=time+1;
        BURNS_Players=allPlayers select {alive _x && {!(_x isKindOf "HeadlessClient_F")}};
        BURNS_DownedPlayers=BURNS_Players select {[_x] call FST_HCSpawn_fnc_burnsIsDown};
        BURNS_PlayerPositions=BURNS_Players apply {getPosWorld (vehicle _x)};
        // Cheap membership discovery, no prop scans or per-unit task loops.
        FST_HC_CombatGroups=allGroups select {local _x && {side _x!=civilian} && {count units _x>0} && {(!hasInterface || {isServer}) || {count (([_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3}}};
        BURNS_ActiveGroups=FST_HC_CombatGroups select {count (([_x,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3};
    };
    // Inspect cheap due metadata in bounded slices. Not-due visits never spend
    // the expensive-work allowance. FIFO admission prevents urgent starvation.
    private _count=count BURNS_ActiveGroups;
    private _contactChecks=0;
    for "_i" from 1 to (64 min _count) do {
        BURNS_ActiveCursor=BURNS_ActiveCursor mod _count;
        private _g=BURNS_ActiveGroups select BURNS_ActiveCursor;
        BURNS_ActiveCursor=BURNS_ActiveCursor+1;
        if (isNull _g || {!local _g}) then {continue};
        if ((_g getVariable ["BURNS_scheduleOwner",-1])!=clientOwner) then {
            _g setVariable ["BURNS_scheduleOwner",clientOwner];
            _g setVariable ["BURNS_lastTaskTick",-1];
            _g setVariable ["FST_HC_taskNext",-1];
            _g setVariable ["BURNS_localAdvanceFormation",nil];
            _g setVariable ["BURNS_localDeployFrame",nil];
            _g setVariable ["BURNS_advanceRoster",nil];
            // Recover our issued goals, NOT arbitrary current engine goals:
            // an external order may have replaced ours during the handoff.
            { _x params ["_unit","_goal"];if (local _unit) then {_unit setVariable ["BURNS_formationGoal",+_goal]} } forEach (_g getVariable ["BURNS_advanceOrders",[]]);
        };
        // A column must not wait for its five-second movement tick after
        // native AI detects contact. Read existing knowledge only, at most one
        // query per travelling group per second and four queries per callback.
        if (_enabled && {_contactChecks<4} && {(_g getVariable ["BURNS_localAdvanceFormation",""])=="COLUMN"} && {time>=(_g getVariable ["BURNS_contactProbeNext",-1])}) then {
            _contactChecks=_contactChecks+1;
            _g setVariable ["BURNS_contactProbeNext",time+1];
            private _lead=leader _g;
            if (!isNull _lead && {alive _lead}) then {
                private _known=_lead findNearestEnemy _lead;
                if (!isNull _known && {_lead distance2D _known<500}) then {_g setVariable ["FST_HC_taskNext",-1]};
            };
        };
        private _next=_g getVariable ["FST_HC_taskNext",-1];
        if (time<(_g getVariable ["BURNS_deployUntil",-1])) then {_next=_next min ((_g getVariable ["BURNS_lastTaskTick",-1])+1)};
        if (time>=_next && {!(_g in BURNS_DueGroups)}) then {BURNS_DueGroups pushBack _g};
    };
    // A soft 2ms budget: a single indivisible SQF task can exceed it. Record
    // actual duration and lateness instead of claiming a hard timing guarantee.
    for "_i" from 1 to (8 min count BURNS_DueGroups) do {
        if (_i>1 && {diag_tickTime-_started>=0.002}) exitWith {};
        private _g=BURNS_DueGroups deleteAt 0;
        if (isNull _g || {!local _g}) then {continue};
        private _last=_g getVariable ["BURNS_lastTaskTick",-1];
        private _due=_g getVariable ["FST_HC_taskNext",time];
        if (_last>=0) then {BURNS_MaxServiceGap=BURNS_MaxServiceGap max (time-_last)};
        if (_due>=0) then {BURNS_MaxDueLateness=BURNS_MaxDueLateness max (time-_due)};
        if (_enabled) then {[_g] call FST_HCSpawn_fnc_combatTaskTick} else {[_g] call FST_HCSpawn_fnc_burnsSuspendTask};
        private _requested=_g getVariable ["FST_HC_taskNext",-1];
        private _interval=if (time<(_g getVariable ["BURNS_deployUntil",-1])) then {1} else {[_g,BURNS_PlayerPositions] call FST_HCSpawn_fnc_burnsTaskInterval};
        _g setVariable ["BURNS_currentInterval",_interval];
        _g setVariable ["BURNS_lastTaskTick",time];
        private _next=time+_interval;
        if (_requested!=_due && {_requested>time}) then {_next=_next min _requested};
        _g setVariable ["FST_HC_taskNext",_next];
        FST_HC_CombatUpdates=FST_HC_CombatUpdates+1;
    };
    // Independent cheap role/guard upkeep, capped at four visits per callback.
    // It runs even when disabled, so old handlers and movement cannot persist.
    _count=count FST_HC_CombatGroups;
    for "_i" from 1 to (4 min _count) do {
        if (_i>1 && {diag_tickTime-_started>=0.003}) exitWith {};
        FST_HC_CombatCursor=FST_HC_CombatCursor mod _count;
        private _g=FST_HC_CombatGroups select FST_HC_CombatCursor;
        FST_HC_CombatCursor=FST_HC_CombatCursor+1;
        if (isNull _g || {!local _g} || {time<(_g getVariable ["BURNS_roleNext",-1])}) then {continue};
        _g setVariable ["BURNS_roleNext",time+5];
        if (count (([_g,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3) then {
            private _interval=[_g,BURNS_PlayerPositions] call FST_HCSpawn_fnc_burnsTaskInterval;
            private _next=(_g getVariable ["FST_HC_taskNext",-1]) min ((_g getVariable ["BURNS_lastTaskTick",-1])+_interval);
            _g setVariable ["FST_HC_taskNext",_next];
        };
        if !([_g] call FST_HCSpawn_fnc_burnsB1Eligible) then {
            if (!isNil {_g getVariable "BURNS_advanceRoster"} || {(units _g findIf {!isNil {_x getVariable "BURNS_advanceSpeed"}})>=0}) then {[_g] call FST_HCSpawn_fnc_burnsReleaseAdvance};
            {
                if (!local _x) then {continue};
                private _hook=_x getVariable ["BURNS_b1DangerHook",-1];
                if (_hook>=0) then {_x removeEventHandler ["Hit",_hook];_x setVariable ["BURNS_b1DangerHook",nil]};
                private _fireHook=_x getVariable ["BURNS_b1NearbyFireHook",-1];
                if (_fireHook>=0) then {_x removeEventHandler ["FiredNear",_fireHook];_x setVariable ["BURNS_b1NearbyFireHook",nil]};
            } forEach units _g;
        };
        if (_enabled) then {[_g] call FST_HCSpawn_fnc_burnsApplyRole} else {
            if (count (([_g,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))==3) then {[_g] call FST_HCSpawn_fnc_burnsSuspendTask};
            [_g] call FST_HCSpawn_fnc_burnsRestoreGroupRole;
        };
    };
    FST_HC_CombatMaxTickMs=FST_HC_CombatMaxTickMs max ((diag_tickTime-_started)*1000);
},0.05,[]] call CBA_fnc_addPerFrameHandler;
[] call FST_HCSpawn_fnc_initVisibility;
[] call FST_HCSpawn_fnc_initSuppression;
[] call FST_HCSpawn_fnc_burnsInitEngagement;
