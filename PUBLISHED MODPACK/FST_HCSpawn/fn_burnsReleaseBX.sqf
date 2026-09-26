// Restore only values still owned by our task, including after HC transfer.
params ["_group"];
{
    private _u=_x;
    private _saved=_u getVariable ["BURNS_bxOwned",[]];
    if (local _u && {count _saved==4}) then {
        _saved params ["_stance","_fire","_path","_writtenStance"];
        _u setVariable ["BURNS_bxReleasedStance",[_stance,_writtenStance],true];
        if (unitPos _u==_writtenStance) then {_u setUnitPos _stance};
        if (!(_u checkAIFeature "FIREWEAPON") && {_fire}) then {_u enableAI "FIREWEAPON"};
        if (!(_u checkAIFeature "PATH") && {_path} && {_u getVariable ["BURNS_bxPath",false]}) then {_u enableAI "PATH"};
        private _goal=_u getVariable ["BURNS_bxGoal",[]];
        private _expected=expectedDestination _u;
        if (count _goal>0 && {currentCommand _u=="MOVE"} && {(_expected select 0) distance2D _goal<2} && {_u checkAIFeature "PATH"} && {!([_u] call FST_HCSpawn_fnc_isPlayerControlledUnit)}) then {_u doMove getPosATL _u};
        _u doWatch objNull;
        _u setVariable ["BURNS_bxOwned",nil,true];
        _u setVariable ["BURNS_bxPath",nil,true];
        _u setVariable ["BURNS_bxGoal",nil];
        // Old-owner stance replication can arrive just after the new owner
        // releases a task. Two bounded checks reconcile only this release.
        private _token=format ["%1:%2",clientOwner,diag_tickTime];
        _u setVariable ["BURNS_bxReleaseToken",_token,true];
        {
            [{
                params ["_u","_stance","_written","_token","_last"];
                if (isNull _u || {!local _u} || {(_u getVariable ["BURNS_bxReleaseToken",""])!=_token}) exitWith {};
                private _task=([group _u,["FST_HC_combatTask",[]]] call FST_HCSpawn_fnc_burnsStateGet) param [0,""];
                if (isNil {_u getVariable "BURNS_bxOwned"} && {!(_task in ["ambush","creep","cqb"])} && {unitPos _u==_written}) then {_u setUnitPos _stance};
                if (_last) then {_u setVariable ["BURNS_bxReleaseToken",nil,true]};
            },[_u,_stance,_writtenStance,_token,_x==2],_x] call CBA_fnc_waitAndExecute;
        } forEach [0.5,2];
    };
} forEach units _group;
private _mode=_group getVariable ["BURNS_bxMode",[]];
if (count _mode==2 && {combatMode _group==(_mode select 1)}) then {_group setCombatMode (_mode select 0)};
if (!isNil {_group getVariable "BURNS_bxMode"}) then {_group setVariable ["BURNS_bxMode",nil,true]};
if (!isNil {_group getVariable "BURNS_ambushTriggered"}) then {_group setVariable ["BURNS_ambushTriggered",nil,true]};
