// A tombstone distinguishes an intentional clear from an uncached field.
params ["_space","_args"];
private _key=_args select 0;
if (_space isEqualType grpNull && {local _space} && {_key in ["FST_HC_combatTask","BURNS_movementRevision","FST_HC_taskWaypoint","FST_HC_taskLastOrder","BURNS_rushTarget","BURNS_rushState","BURNS_huntLeg","BURNS_huntPhase","BURNS_patrol"]}) then {
    if (isNil {_space getVariable "BURNS_taskStateLocalHook"}) then {
        private _hook=_space addEventHandler ["Local",{
            params ["_group","_isLocal"];
            _group setVariable ["BURNS_ownerTaskState",nil];
            _group setVariable ["BURNS_taskStateEpoch",(_group getVariable ["BURNS_taskStateEpoch",0])+1];
            _group setVariable ["BURNS_scheduleOwner",nil];
            {_x setVariable ["BURNS_moveCleanupToken",nil]} forEach units _group;
        }];
        _space setVariable ["BURNS_taskStateLocalHook",_hook];
    };
    private _cache=_space getVariable ["BURNS_ownerTaskState",createHashMap];
    private _row=[false];
    if (!isNil {_args select 1}) then {_row=[true,_args select 1]};
    _cache set [_key,_row];
    _space setVariable ["BURNS_ownerTaskState",_cache];
};
_space setVariable _args
