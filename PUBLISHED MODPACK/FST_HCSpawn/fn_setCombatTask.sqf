// Public, arguments local: [group, "hunt"|"assault"|"stop", objectiveATL, radius].
// Stores intent on the group so the new owner can resume after an HC transfer.
params ["_group", ["_mode", "stop"], ["_pos", []], ["_radius", 500]];
if (isNull _group || {!local _group}) exitWith {false};
if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {false};
{[_x,_mode=="stop"] call FST_HCSpawn_fnc_burnsReleaseBXCharge} forEach units _group;
[_group] call FST_HCSpawn_fnc_burnsReleaseB2Line;
[_group] call FST_HCSpawn_fnc_burnsReleaseBX;
// Clear our temporary aiming before accepting a newer task.
[_group] call FST_HCSpawn_fnc_burnsReleasePointFire;
// Used only to prevent a delayed locality restore reviving an older BURNS hold.
if (_mode=="stop" || {_mode in ["hunt","assault","rush","ambush","creep","retreat","garrison","camp","defend","cqb"] && {missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]} && {!(_group getVariable ["BURNS_exempt",false])}}) then {
    ([_group,["BURNS_movementRevision",(([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet))+1,true]] call FST_HCSpawn_fnc_burnsStateSet);
};
if (_mode == "stop") exitWith {
    if ((units _group findIf {_x isKindOf "JMSEF_animals_varren_o"})>=0) then {_group setVariable ["BURNS_creatureTaskIntent","stop",true]};
    if ((units _group findIf {_x isKindOf "WBK_LS_B2"})>=0) then {_group setVariable ["BURNS_b2TaskIntent","stop",true]};
    {if (local _x && {_x getVariable ["BURNS_b2AutoCombatOff",false]}) then {_x enableAI "AUTOCOMBAT";_x setVariable ["BURNS_b2AutoCombatOff",nil]}} forEach units _group;
{_group setVariable [_x,nil,true]} forEach ["BURNS_sectionToken","BURNS_sectionPlan","BURNS_sectionContact"];
{[_x] call FST_HCSpawn_fnc_burnsArmorSectionDriver} forEach units _group;

    for "_i" from (count waypoints _group-1) to 0 step -1 do {
        if (waypointDescription [_group,_i]=="BURNS patrol") then {deleteWaypoint [_group,_i]};
    };
    ([_group,["BURNS_patrol",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_rushState",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_rushTarget",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["BURNS_huntLeg",nil,true]] call FST_HCSpawn_fnc_burnsStateSet);
    [_group] call FST_HCSpawn_fnc_burnsReleaseAdvance;
    {
        _x setVariable ["BURNS_stationProgress",nil];
        private _stationUnit=_x;
        {if (!isNil {_stationUnit getVariable _x}) then {_stationUnit setVariable [_x,nil,true]}} forEach ["BURNS_stationFallback","BURNS_stationOriginal"];
        if (local _x && {_x getVariable ["BURNS_ownsPath",false]} && {([_x] call FST_HCSpawn_fnc_burnsRole)!="webknight"}) then {
            _x enableAI "PATH";
            _x setVariable ["BURNS_ownsPath",nil,true];
            private _slots=_group getVariable ["BURNS_stationSlots",[]];
            private _stationIndex=_slots findIf {(_x select 0)==_stationUnit};
            private _slot=if (_stationIndex>=0) then {(_slots select _stationIndex) select 1} else {getPosATL _stationUnit};
            private _token=(_stationUnit getVariable ["BURNS_cleanupSerial",0])+1;
            _stationUnit setVariable ["BURNS_cleanupSerial",_token];
            _stationUnit setVariable ["BURNS_moveCleanupToken",_token];
            [FST_HCSpawn_fnc_burnsReleaseStation,[_stationUnit,+_slot,_token],0.1] call CBA_fnc_waitAndExecute;
        };
    } forEach units _group;
    {_group setVariable [_x,nil,true]} forEach ["BURNS_stationSlots","BURNS_stationStatus","BURNS_cqbRoute","BURNS_cqbIndex","BURNS_cqbDeadline","BURNS_cqbSkipped","BURNS_cqbStatus","BURNS_holdReleased"];
    ([_group,["FST_HC_combatTask", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    if (_group getVariable ["BURNS_ownsKeepActive", false]) then {
        _group setVariable ["FST_HC_keepActive", nil, true];
        _group setVariable ["BURNS_ownsKeepActive", nil, true];
    };
    [_group,false] call FST_HCSpawn_fnc_burnsSimulation;
    private _index = ([_group,["FST_HC_taskWaypoint", -1]] call FST_HCSpawn_fnc_burnsStateGet);
    if (_index >= 0 && {_index < count waypoints _group} && {waypointDescription [_group,_index] == "FST HC combat"}) then {
        deleteWaypoint [_group,_index];
    };
    ([_group,["FST_HC_taskWaypoint", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    ([_group,["FST_HC_taskLastOrder", nil, true]] call FST_HCSpawn_fnc_burnsStateSet);
    true
};
if !(_mode in ["hunt", "assault", "rush", "ambush","ambush", "creep", "retreat", "garrison", "camp", "defend", "cqb"]) exitWith {false};
if (!(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) || {_group getVariable ["BURNS_exempt",false]}) exitWith {false};
// Public calls can replace tasks too. Release old holds and routes exactly as
// the Zeus broker does, including when only the task's destination changes.
if (count (([_group,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet))>0 || {!isNil {([_group,"BURNS_patrol"] call FST_HCSpawn_fnc_burnsStateGet)}}) then {
    [_group,"stop"] call FST_HCSpawn_fnc_setCombatTask;
};
{_x setVariable ["BURNS_moveCleanupToken",nil]} forEach units _group;
if (count _pos < 2) then { _pos = getPosATL leader _group; };
_radius = (_radius max 15) min 3000;
if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled", true]) exitWith {false};
if !(_group getVariable ["FST_HC_keepActive", false]) then {
    _group setVariable ["BURNS_ownsKeepActive", true, true];
};
{
    if (local _x && {([_x] call FST_HCSpawn_fnc_burnsRole)!="webknight"} && {_x getVariable ["FST_HC_ownsPath",false] || {!isNil {_x getVariable "FST_HC_assignedPos"}}}) then {
        _x enableAI "PATH";
        _x setVariable ["FST_HC_ownsPath",nil,true];
        _x setVariable ["FST_HC_assignedPos",nil,true];
        _x doFollow leader _group;
    };
} forEach units _group;
[_group,true] call FST_HCSpawn_fnc_burnsSimulation;
if ((units _group findIf {_x isKindOf "JMSEF_animals_varren_o"})>=0) then {_group setVariable ["BURNS_creatureTaskIntent",_mode,true]};
if ((units _group findIf {_x isKindOf "WBK_LS_B2"})>=0) then {_group setVariable ["BURNS_b2TaskIntent",_mode,true]};
// B2/BX receive ordinary mission movement; their combat remains WebKnight's.
if ((units _group findIf {([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight"}) >= 0 && {!(_mode in ["ambush","creep","cqb"] && {(units _group findIf {alive _x && {!(_x isKindOf "WBK_LS_BX")}})<0})}) exitWith {
    private _index = ([_group,["FST_HC_taskWaypoint", -1]] call FST_HCSpawn_fnc_burnsStateGet);
    private _wp = if (_index >= 0 && {_index < count waypoints _group} && {waypointDescription [_group,_index] == "FST HC combat"}) then {
        [_group,_index]
    } else {
        _group addWaypoint [_pos, 20]
    };
    _wp setWaypointPosition [_pos,20];
    _wp setWaypointDescription "FST HC combat";
    _wp setWaypointType "MOVE";
    _wp setWaypointSpeed "NORMAL";
    if ((units _group findIf {_x isKindOf "WBK_LS_B2"})>=0 && {_mode in ["assault","rush","hunt"]}) then {
        // B2s walk in and fire on the move. In COMBAT behaviour they halted and
        // traded fire at 300 m (~0.2 m/s closing in engine tests, 3 Oct).
        _wp setWaypointSpeed "NORMAL";
        _wp setWaypointBehaviour "AWARE";
        _wp setWaypointCombatMode "YELLOW";
        _group setBehaviourStrong "AWARE";
        _group setCombatMode "YELLOW";
        // B2s only (a mixed group's B1/BX/humans keep their own behaviour). Native AUTOCOMBAT flips
        // the squad back to COMBAT on first contact, which made B2s stop and trade fire.
        {if (local _x && {_x isKindOf "WBK_LS_B2"}) then {_x disableAI "AUTOCOMBAT";_x forceWalk true;_x setVariable ["BURNS_b2AutoCombatOff",true]}} forEach units _group;
        // Move-fire rhythm (engine tests 3 Oct: B2s close ~1.3 m/s unopposed but ~0.3 m/s
        // once they stop to aim). Every 2 s tick: 3 ticks walking with targeting off, then 2
        // ticks firing. Rush/hunt follow the live rush target. Zeus waypoints/holds win.
        if (isNil {_group getVariable "BURNS_b2MovePFH"}) then {
            diag_log format ["[BURNS_B2_RHYTHM_START] %1 mode=%2 owner=%3",_group,_mode,clientOwner];
            _group setVariable ["BURNS_b2MovePFH",[{
                params ["_args","_id"];
                _args params ["_g"];
                private _b2s=if (isNull _g) then {[]} else {units _g select {alive _x && {_x isKindOf "WBK_LS_B2"}}};
                private _wpNow=if (isNull _g) then {-1} else {currentWaypoint _g};
                private _manual=_wpNow>0 && {_wpNow<count waypoints _g} && {!(waypointDescription [_g,_wpNow] in ["FST HC combat","BURNS patrol"])};
                if (isNull _g || {!local _g} || {count _b2s==0} || {_manual} || {(_g getVariable ["FST_HC_heldBy",-1])!=-1} || {!((_g getVariable ["BURNS_b2TaskIntent",""]) in ["assault","rush","hunt"])}) exitWith {
                    [_id] call CBA_fnc_removePerFrameHandler;
                    if (!isNull _g) then {
                        _g setVariable ["BURNS_b2MovePFH",nil];
                        // Hand control back: targeting on, and drop the rhythm's last doMove.
                        {if (local _x && {alive _x}) then {_x enableAI "TARGET";_x enableAI "AUTOTARGET";_x doFollow leader _g}} forEach _b2s;
                    };
                };
                private _n=(_g getVariable ["BURNS_b2Beat",0])+1;
                _g setVariable ["BURNS_b2Beat",_n];
                private _fire=(_n mod 5)>=3;
                private _goal=[];
                if ((_g getVariable ["BURNS_b2TaskIntent",""]) in ["rush","hunt"]) then {
                    private _t=[_g] call FST_HCSpawn_fnc_burnsRushTarget;
                    if (!isNull _t) then {_goal=getPosATL (vehicle _t)};
                };
                if (count _goal<2) then {
                    private _wi=([_g,["FST_HC_taskWaypoint",-1]] call FST_HCSpawn_fnc_burnsStateGet);
                    if (_wi>=0 && {_wi<count waypoints _g}) then {_goal=waypointPosition [_g,_wi]};
                };
                // Close in to about 25 m, then stop the rhythm's walking and let them fight.
                private _arrived=count _goal<2 || {(leader _g) distance2D _goal<25};
                if ((missionNamespace getVariable ["BURNS_B2Debug",false]) && {_n mod 5==0}) then {diag_log format ["[BURNS_B2_RHYTHM] %1 intent=%2 goal=%3 leaderDist=%4 arrived=%5",_g,_g getVariable ["BURNS_b2TaskIntent",""],_goal,round ((leader _g) distance2D _goal),_arrived]};
                {
                    if (local _x) then {
                        if (_fire || {_arrived}) then {
                            if !(_x checkAIFeature "TARGET") then {_x enableAI "TARGET";_x enableAI "AUTOTARGET"};
                        } else {
                            if (_x checkAIFeature "TARGET") then {_x disableAI "TARGET";_x disableAI "AUTOTARGET"};
                            // Re-path only when idle or heading somewhere stale, not every tick.
                            if (_x distance2D _goal>15 && {unitReady _x || {((expectedDestination _x) select 0) distance2D _goal>20}}) then {_x doMove (_goal getPos [random 12,random 360])};
                        };
                    };
                } forEach _b2s;
            },2,[_group]] call CBA_fnc_addPerFrameHandler];
        };
    };
    _group setCurrentWaypoint _wp;
    ([_group,["FST_HC_taskWaypoint", _wp select 1, true]] call FST_HCSpawn_fnc_burnsStateSet);
    _group setVariable ["FST_HC_keepActive", true, true];
    true
};
([_group,["FST_HC_combatTask", [_mode, +_pos, _radius], true]] call FST_HCSpawn_fnc_burnsStateSet);
if (isNil "FST_HC_CombatGroups") then {[true] call FST_HCSpawn_fnc_initCombatTasks};
FST_HC_CombatGroups pushBackUnique _group;
BURNS_ActiveGroups pushBackUnique _group;
if (_mode in ["rush","hunt","creep"]) then {
    BURNS_Players=allPlayers select {alive _x && {!(_x isKindOf "HeadlessClient_F")}};
    BURNS_PlayerPositions=BURNS_Players apply {getPosWorld (vehicle _x)};
};
_group setVariable ["FST_HC_keepActive", true, true];
_group setVariable ["FST_HC_taskNext", time + random 2];
([_group,["FST_HC_taskLastOrder", [], true]] call FST_HCSpawn_fnc_burnsStateSet);
if (_mode in ["garrison","camp","defend","cqb"]) then {
    private _wp=_group addWaypoint [_pos,0];
    _wp setWaypointDescription "FST HC combat";
    _wp setWaypointType "MOVE";
    _group setCurrentWaypoint _wp;
    ([_group,["FST_HC_taskWaypoint",_wp select 1,true]] call FST_HCSpawn_fnc_burnsStateSet);
};
[_group] call FST_HCSpawn_fnc_burnsApplyRole;
[_group] call FST_HCSpawn_fnc_combatTaskTick;
true
