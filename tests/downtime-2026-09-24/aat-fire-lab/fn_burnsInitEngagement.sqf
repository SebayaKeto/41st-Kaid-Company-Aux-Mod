// One shared bounded service; no PFH or target scan for every rifleman.
if (hasInterface && {!isServer}) exitWith {};
if (missionNamespace getVariable ["BURNS_engagementStarted",false]) exitWith {};
BURNS_engagementStarted=true;
BURNS_FireJobs=[];
BURNS_EngagementCursor=0;
BURNS_EngagementMaxMs=0;
BURNS_EngagementQueries=0;
[{
    private _started=diag_tickTime;
    // Jobs stay on this owner; stale jobs only release their own local handlers.
    for "_i" from 1 to (4 min count BURNS_FireJobs) do {
        private _entry=BURNS_FireJobs deleteAt 0;
        _entry params ["_group","_unit","_eh","_deadline"];
        if (!isNull _group) then {
            private _job=_group getVariable ["BURNS_pointFire",[]];
            // A cancelled entry must never service/requeue its replacement.
            if (count _job!=10 || {(_job select 0)!=_unit} || {(_job select 9)!=_eh} || {(_job select 3)!=_deadline}) then {continue};
            [_group] call FST_HCSpawn_fnc_burnsPointFire;
            if (count (_group getVariable ["BURNS_pointFire",[]])>0) then {BURNS_FireJobs pushBack _entry};
        } else {
            // Keep the unit reference even if Zeus deletes/merges its group.
            if (!isNull _unit) then {
                _unit removeEventHandler ["Fired",_eh];
                private _lease=_unit getVariable ["BURNS_pointFireLease",[]];
                if (local _unit && {count _lease==4} && {(_lease select 0)==clientOwner} && {(_lease select 3)==_deadline}) then {
                    if (abs getForcedSpeed _unit<0.01) then {_unit forceSpeed (_lease select 2)};
                    _unit setVariable ["BURNS_pointFireLease",nil,true];
                };
            };
        };
    };
    private _groups=missionNamespace getVariable ["FST_HC_CombatGroups",[]];
    private _count=count _groups;
    for "_i" from 1 to (4 min _count) do {
        if (_i>1 && {diag_tickTime-_started>0.002}) exitWith {};
        BURNS_EngagementCursor=BURNS_EngagementCursor mod _count;
        private _g=_groups select BURNS_EngagementCursor;
        BURNS_EngagementCursor=BURNS_EngagementCursor+1;
        if (isNull _g || {!local _g}) then {continue};
        // Recover temporary local commands after ownership transfer, before
        // testing eligibility. This also handles a task disabled on the new HC.
        {
            private _u=_x;
            private _lease=_u getVariable ["BURNS_pointFireLease",[]];
            if (local _u && {count _lease==4} && {(_lease select 0)!=clientOwner || {time>(_lease select 1)}}) then {
                if (abs getForcedSpeed _u<0.01) then {_u forceSpeed (_lease select 2)};
                _u setVariable ["BURNS_pointFireLease",nil,true];
                if (!([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)) then {_u doWatch objNull};
            };
        } forEach units _g;
        private _v=vehicle leader _g;
        private _pulse=_v getVariable ["BURNS_armorPulse",[]];
        if (local _v && {count _pulse==8} && {(_pulse select 6)!=clientOwner || {time>(_pulse select 7)}}) then {[_v,_pulse select 0] call FST_HCSpawn_fnc_burnsArmorPulseEnd};
        // The gait helper must also see disabled/exempt states to release its gait.
        if (true) then {
            private _creatures=units _g select {_x isKindOf "JMSEF_animals_varren_o"};
            if (count _creatures>0) then {
                private _c=(_g getVariable ["BURNS_climbCursor",0]) mod count _creatures;
                [_creatures select _c] call FST_HCSpawn_fnc_burnsGulantharSlope;
                _g setVariable ["BURNS_climbCursor",_c+1];
            };
        };
        if !(missionNamespace getVariable ["FST_HC_CombatTasksEnabled",true]) then {continue};
        if (time<(_g getVariable ["BURNS_engagementNext",-1]) || {!([_g] call FST_HCSpawn_fnc_burnsEngagementAllowed)}) then {continue};
        private _armor=_v isKindOf "FST_AAT";
        _g setVariable ["BURNS_engagementNext",time+(if (_armor) then {0.5} else {2})];
        if (!_armor) then {[_g] call FST_HCSpawn_fnc_burnsReaction};
        if (!_armor && {!([_g,true] call FST_HCSpawn_fnc_burnsB1Eligible)}) then {continue};
        if (!_armor && {count BURNS_FireJobs>=16 || {count (_g getVariable ["BURNS_pointFire",[]])>0}}) then {continue};
        private _range=if (_armor) then {500} else {250};
        if (fog>=0.4 && {missionNamespace getVariable ["BURNS_LowVisibilityAssist",false]}) then {_range=_range min (missionNamespace getVariable ["BURNS_VisibleContactRange",125])};
        private _contacts=(leader _g) nearTargets _range;
        BURNS_EngagementQueries=BURNS_EngagementQueries+1;
        if (_armor) then {[_g,_contacts] call FST_HCSpawn_fnc_burnsArmorAssist} else {[_g,_contacts] call FST_HCSpawn_fnc_burnsAcquirePointFire};
    };
    BURNS_EngagementMaxMs=BURNS_EngagementMaxMs max ((diag_tickTime-_started)*1000);
},0.1,[]] call CBA_fnc_addPerFrameHandler;
