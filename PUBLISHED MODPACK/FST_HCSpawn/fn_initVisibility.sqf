// Optional mission-specific compensation for player-visible grading in darkness.
// Off by default. Never changes normal-map spotting distance or human/B2/BX AI.
if (hasInterface && {!isServer}) exitWith {};
if (missionNamespace getVariable ["BURNS_visibilityStarted",false]) exitWith {};
BURNS_visibilityStarted=true;
BURNS_VisibilityCursor=0;
BURNS_VisibilityChecks=0;
BURNS_VisibilityMaxMs=0;
[{
    if !(missionNamespace getVariable ["BURNS_LowVisibilityAssist",false]) exitWith {};
    if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) exitWith {};
    // Also disengage when the mission's weather clears; no persistent sight cap.
    if (fog<0.4) exitWith {};
    private _started=diag_tickTime;
    private _count=count FST_HC_CombatGroups;
    private _range=missionNamespace getVariable ["BURNS_VisibleContactRange",125];
    for "_i" from 1 to (4 min _count) do {
        BURNS_VisibilityCursor=BURNS_VisibilityCursor mod _count;
        private _g=FST_HC_CombatGroups select BURNS_VisibilityCursor;
        BURNS_VisibilityCursor=BURNS_VisibilityCursor+1;
        if (isNull _g || {!local _g} || {_g getVariable ["BURNS_exempt",false]} || {(_g getVariable ["FST_HC_heldBy",-1])!=-1}) then {continue};
        if ([_g] call FST_HCSpawn_fnc_isProtectedVehicleGroup) then {continue};
        private _leader=leader _g;
        if (!alive _leader || {!simulationEnabled _leader} || {(units _g findIf {([_x] call FST_HCSpawn_fnc_isPlayerControlledUnit)})>=0}) then {continue};
        if ((units _g findIf {([_x] call FST_HCSpawn_fnc_burnsRole)=="webknight"})>=0) then {continue};
        private _observers=(units _g) select {
            alive _x && {local _x} && {!(_x getVariable ["BURNS_exempt",false])} &&
            {([_x] call FST_HCSpawn_fnc_burnsRole)=="b1"} &&
            {vehicle _x==_x || {(vehicle _x) isKindOf "StaticWeapon"}}
        };
        if (count _observers==0) then {continue};
        private _candidate=objNull;
        private _distance=1e12;
        {
            if (!alive _x || {captive _x} || {(side _g) getFriend (side group _x)>=0.6}) then {continue};
            private _d=_leader distance _x;
            if (_d<_distance && {_d<=_range+20} && {_leader knowsAbout _x<1.5}) then {_distance=_d;_candidate=_x};
        } forEach BURNS_Players;
        if (isNull _candidate) then {_g setVariable ["BURNS_visualCandidate",nil];continue};
        private _observerIndex=(_g getVariable ["BURNS_visualObserver",0]) mod count _observers;
        _g setVariable ["BURNS_visualObserver",_observerIndex+1];
        private _pair=[_observers select 0];
        _pair pushBackUnique (_observers select _observerIndex);
        private _seen=false;
        {
            BURNS_VisibilityChecks=BURNS_VisibilityChecks+1;
            if ([_x,_candidate,_range] call FST_HCSpawn_fnc_burnsVisibleContact) exitWith {_seen=true};
        } forEach _pair;
        if (!_seen) then {_g setVariable ["BURNS_visualCandidate",nil];continue};
        private _previous=_g getVariable ["BURNS_visualCandidate",[objNull,time]];
        if ((_previous select 0)==_candidate && {time-(_previous select 1)>=0.5}) then {
            _g reveal [_candidate,1.5];
            _g setVariable ["FST_HC_taskNext",time];
            _g setVariable ["BURNS_visualCandidate",nil];
        } else {
            if ((_previous select 0)!=_candidate) then {_g setVariable ["BURNS_visualCandidate",[_candidate,time]]};
        };
        if (diag_tickTime-_started>0.002) exitWith {};
    };
    BURNS_VisibilityMaxMs=BURNS_VisibilityMaxMs max ((diag_tickTime-_started)*1000);
},0.25,[]] call CBA_fnc_addPerFrameHandler;
