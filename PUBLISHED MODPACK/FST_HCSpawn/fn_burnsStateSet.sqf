// A tombstone distinguishes an intentional clear from an uncached field.
params ["_space","_args"];
private _key=_args select 0;
if (_space isEqualType grpNull && {local _space} && {_key in ["FST_HC_combatTask","BURNS_movementRevision","FST_HC_taskWaypoint","FST_HC_taskLastOrder","BURNS_rushTarget","BURNS_rushState","BURNS_huntLeg","BURNS_huntPhase","BURNS_patrol"]}) then {
    if (isNil {_space getVariable "BURNS_taskStateLocalHook"}) then {
        private _hook=_space addEventHandler ["Local",{
            params ["_group","_isLocal"];
            _group setVariable ["BURNS_ownerTaskState",nil];
            _group setVariable ["BURNS_publishedTaskState",nil];
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
// Repeated scheduler visits must not re-broadcast an unchanged task value.
// Update the owner cache above even when the network write can be omitted.
private _present=!isNil {_args select 1};
private _hadValue=!isNil {_space getVariable _key};
private _same=_present==_hadValue;
if (_same && {_present}) then {_same=(_space getVariable _key) isEqualTo (_args select 1)};
private _public=(_args param [2,false]) isEqualTo true;
private _published=_space getVariable ["BURNS_publishedTaskState",createHashMap];
private _snapshot=if (_present) then {[true,_args select 1]} else {[false]};
// Remember an independent snapshot of the last publication. Comparing only
// getVariable would miss arrays changed in place or a prior local-only write.
if (_public && {_same} && {(_published getOrDefault [_key,[]]) isEqualTo _snapshot}) exitWith {
    BURNS_StateWritesSkipped=(missionNamespace getVariable ["BURNS_StateWritesSkipped",0])+1;
};
if (_public) then {
    _published set [_key,+_snapshot];
    _space setVariable ["BURNS_publishedTaskState",_published];
};
_space setVariable _args
