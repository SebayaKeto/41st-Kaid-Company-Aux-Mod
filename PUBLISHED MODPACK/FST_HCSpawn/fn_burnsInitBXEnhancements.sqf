if (missionNamespace getVariable ["BURNS_bxEnhancementsStarted",false]) exitWith {};
BURNS_bxEnhancementsStarted=true;
BURNS_bxRoster=[];
BURNS_bxCursor=0;
["FST_BX","InitPost",{
    params ["_u"];
    if (local _u) then {BURNS_bxRoster pushBackUnique _u};
    _u addEventHandler ["Local",{params ["_u","_local"];if (_local) then {BURNS_bxRoster pushBackUnique _u}}];
    _u addEventHandler ["AnimStateChanged",{
        params ["_u","_anim"];
        if (!local _u) exitWith {};
        [_u,false,_anim] call FST_HCSpawn_fnc_burnsBXMobility;
        if ((toLower _anim) in ["bx_droid_sword_pre","bx_droid_sword","bx_droid_kick"]) then {
            _u setVariable ["BURNS_bxMeleeNext",time+2.2];
        };
    }];
},true,[],true] call CBA_fnc_addClassEventHandler;
// WebKnight removes per-unit Killed and animation handlers during death.
addMissionEventHandler ["EntityKilled",{
    params ["_u"];
    if (local _u && {_u isKindOf "FST_BX"}) then {
        [_u,true] call FST_HCSpawn_fnc_burnsBXMobility;
        [_u] call FST_HCSpawn_fnc_burnsReleaseBXCharge;
    };
}];
addMissionEventHandler ["EntityDeleted",{
    params ["_u"];
    private _owned=_u getVariable ["BURNS_bxSpeedOwned",[]];
    if (local _u && {count _owned>0}) then {remoteExec ["",_owned select 1]};
}];
[{
    private _budget=diag_tickTime+0.002;
    for "_i" from 1 to (8 min count BURNS_bxRoster) do {
        if (diag_tickTime>_budget) exitWith {};
        if (BURNS_bxCursor>=count BURNS_bxRoster) then {BURNS_bxCursor=0};
        private _u=BURNS_bxRoster select BURNS_bxCursor;
        if (isNull _u || {!local _u} || {!alive _u}) then {
            if (!isNull _u && {local _u}) then {[_u,true] call FST_HCSpawn_fnc_burnsBXMobility;[_u] call FST_HCSpawn_fnc_burnsReleaseBXCharge};
            BURNS_bxRoster deleteAt BURNS_bxCursor;
        } else {
            BURNS_bxCursor=BURNS_bxCursor+1;
            [_u] call FST_HCSpawn_fnc_burnsBXMobility;
            if (time>=(_u getVariable ["BURNS_bxMeleeScan",-1])) then {
                _u setVariable ["BURNS_bxMeleeScan",time+0.35];
                [_u] call FST_HCSpawn_fnc_burnsBXMelee;
            };
        };
    };
},0.05] call CBA_fnc_addPerFrameHandler;
