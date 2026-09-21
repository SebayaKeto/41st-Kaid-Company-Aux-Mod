// One bounded tactical scheduler on each AI owner. Native FSMs stay enabled.
// The separate opt-in sight aid requires short-range, unobstructed visual contact.
if (hasInterface && {!isServer}) exitWith {};
if (missionNamespace getVariable ["FST_HC_combatSchedulerStarted", false]) exitWith {};
missionNamespace setVariable ["FST_HC_combatSchedulerStarted", true];
FST_HC_CombatGroups = [];
BURNS_PlayerPositions = [];
BURNS_Players = [];
FST_HC_CombatCursor = 0;
FST_HC_CombatNextScan = time + random 2;
FST_HC_CombatUpdates = 0;
FST_HC_CombatMaxTickMs = 0;
[{
    if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled", true]) exitWith {};
    private _started = diag_tickTime;
    if (time >= FST_HC_CombatNextScan) then {
        FST_HC_CombatNextScan = time + 5;
        BURNS_Players = allPlayers select {
            alive _x && {!(_x isKindOf "HeadlessClient_F")}
        };
        BURNS_PlayerPositions = BURNS_Players apply {getPosWorld (vehicle _x)};
        FST_HC_CombatGroups = allGroups select {
            local _x && {side _x != civilian} && {count units _x > 0}
        };
    };
    private _count = count FST_HC_CombatGroups;
    for "_i" from 1 to (2 min _count) do {
        FST_HC_CombatCursor = FST_HC_CombatCursor mod _count;
        private _group = FST_HC_CombatGroups select FST_HC_CombatCursor;
        FST_HC_CombatCursor = FST_HC_CombatCursor + 1;
        if (isNull _group || {!local _group}) then {continue};
        // Check urgency BEFORE the due-time guard, so a distant deadline cannot
        // hold a group at slow frequency once players or known enemies approach.
        // Keep the same two-groups-per-tick budget on each owner.
        if ((_group getVariable ["BURNS_scheduleOwner", -1]) != clientOwner) then {
            _group setVariable ["BURNS_scheduleOwner", clientOwner];
            _group setVariable ["BURNS_lastTaskTick", -1];
            _group setVariable ["FST_HC_taskNext", -1];
        };
        private _interval = [_group, BURNS_PlayerPositions] call FST_HCSpawn_fnc_burnsTaskInterval;
        private _last = _group getVariable ["BURNS_lastTaskTick", -1];
        private _next = _group getVariable ["FST_HC_taskNext", -1];
        if (_last >= 0) then {_next = _next min (_last + _interval)};
        _group setVariable ["BURNS_currentInterval", _interval];
        if (time < _next) then {continue};
        _group setVariable ["BURNS_lastTaskTick", time];
        _group setVariable ["FST_HC_taskNext", time + _interval + random 2];
        [_group] call FST_HCSpawn_fnc_burnsApplyRole;
        [_group] call FST_HCSpawn_fnc_combatTaskTick;
        FST_HC_CombatUpdates = FST_HC_CombatUpdates + 1;
    };
    FST_HC_CombatMaxTickMs = FST_HC_CombatMaxTickMs max ((diag_tickTime - _started) * 1000);
}, 0.5, []] call CBA_fnc_addPerFrameHandler;
[] call FST_HCSpawn_fnc_initVisibility;
[] call FST_HCSpawn_fnc_initSuppression;
