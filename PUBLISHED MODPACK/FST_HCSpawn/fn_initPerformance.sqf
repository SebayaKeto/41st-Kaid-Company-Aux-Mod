// All-machine effect registration; one five-second health sampler per owner.
if (missionNamespace getVariable ["FST_PerformanceStarted",false]) exitWith {};
FST_PerformanceStarted=true;
["FST_atrtSmoke", {[_this select 0,true] call FST_fnc_spawnATRTSmoke}] call CBA_fnc_addEventHandler;
if (isServer) then {
    FST_HeavyObjects=[]; FST_HeavyHealth=createHashMap; FST_HeavyReservations=createHashMap;
    {if (([typeOf _x] call FST_HCSpawn_fnc_heavyKind)>=0) then {FST_HeavyObjects pushBackUnique _x}} forEach (allUnits+vehicles);
    addMissionEventHandler ["EntityCreated", {
        params ["_object"];
        if (([typeOf _object] call FST_HCSpawn_fnc_heavyKind)<0) exitWith {};
        _object setVariable ["FST_heavyCreatedAt",diag_tickTime];
        FST_HeavyObjects pushBackUnique _object;
    }];
    ["FST_heavyHealth", {
        params ["_id","_fps","_blocked","_stats"];
        if (_id!=2 && {!(_id in (missionNamespace getVariable ["FST_HC_Ids",[]]))}) exitWith {};
        private _old=FST_HeavyHealth getOrDefault [str _id,[]];
        FST_HeavyHealth set [str _id,[diag_tickTime,_fps,_blocked,_stats]];
        if (_blocked && {count _old==0 || {!(_old select 2)}}) then {
            private _owners=[];
            {private _u=getAssignedCuratorUnit _x; if (!isNull _u) then {_owners pushBackUnique owner _u}} forEach allCurators;
            private _scope=if (missionNamespace getVariable ["FST_HC_PauseAllSpawnsLowFPS",false]) then {"managed AI"} else {"heavy"};
            {format ["[FST] New %1 spawns paused: owner %2 has sustained low FPS (%3).",_scope,_id,round _fps] remoteExec ["systemChat",_x]} forEach _owners;
        };
        if (diag_tickTime>=(missionNamespace getVariable [format ["FST_perfLog_%1",_id],-1])) then {
            missionNamespace setVariable [format ["FST_perfLog_%1",_id],diag_tickTime+30];
            diag_log format ["[FST_PERF] owner=%1 fps=%2 blocked=%3 [gulanthars,atrts,corpses,scripts]=%4",_id,_fps,_blocked,_stats];
        };
    }] call CBA_fnc_addEventHandler;
    ["FST_heavyAck", {
        params ["_ticket","_owner","_objects"];
        if (_ticket isEqualTo []) exitWith {};
        private _r=FST_HeavyReservations getOrDefault [_ticket select 0,[]];
        if (count _r==3 && {(_r select 2)==_owner}) then {
            // Account for creations before releasing capacity, even if the
            // engine's EntityCreated replication has not arrived yet.
            {if (!isNull _x && {([typeOf _x] call FST_HCSpawn_fnc_heavyKind)>=0}) then {FST_HeavyObjects pushBackUnique _x}} forEach _objects;
            FST_HeavyReservations deleteAt (_ticket select 0);
        };
    }] call CBA_fnc_addEventHandler;
    ["FST_heavyZeus", {_this call FST_HCSpawn_fnc_heavyZeus}] call CBA_fnc_addEventHandler;
};
if (hasInterface && {!isServer}) exitWith {};
FST_perfLow=0; FST_perfHigh=0; FST_perfBlocked=false;
[{
    private _fps=diag_fps;
    FST_perfLow=if (_fps<(missionNamespace getVariable ["FST_HC_HeavyPauseFPS",15])) then {FST_perfLow+1} else {0};
    FST_perfHigh=if (_fps>=(missionNamespace getVariable ["FST_HC_HeavyResumeFPS",25])) then {FST_perfHigh+1} else {0};
    if (FST_perfLow>=3) then {FST_perfBlocked=true};
    if (FST_perfHigh>=6) then {FST_perfBlocked=false};
    private _counts=[0,0];
    {if (local _x && {alive _x}) then {private _k=[typeOf _x] call FST_HCSpawn_fnc_heavyKind; if (_k>=0) then {_counts set [_k,(_counts select _k)+1]}}} forEach allUnits;
    _counts append [count allDeadMen,count diag_activeSQFScripts];
    ["FST_heavyHealth",[clientOwner,_fps,FST_perfBlocked,_counts]] call CBA_fnc_serverEvent;
},5,[]] call CBA_fnc_addPerFrameHandler;
