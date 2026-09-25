params ["_group"];
private _job=_group getVariable ["BURNS_pointFire",[]];
if (count _job==0) exitWith {};
_job params ["_unit","_target","_kind","_deadline","_revision","_wp","_wpPos","_originalSpeed","_owner","_eh"];
_group setVariable ["BURNS_pointFire",nil];
_group setVariable ["BURNS_fireAim",nil];
if (!isNull _unit) then {
    _unit removeEventHandler ["Fired",_eh];
    private _lease=_unit getVariable ["BURNS_pointFireLease",[]];
    if (count _lease==4 && {(_lease select 0)==_owner} && {(_lease select 3)==_deadline}) then {
        // Restore only our speed value, including when Zeus takes possession.
        if (local _unit && {abs getForcedSpeed _unit<0.01}) then {_unit forceSpeed _originalSpeed};
        if (local _unit && {!([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} && {
            (_group getVariable ["FST_HC_heldBy",-1])==-1
        } && {currentWaypoint _group==_wp} && {
            ([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet)==_revision
        }) then {_unit doWatch objNull};
        // An old owner must not erase a new owner's lease.
        if (local _unit) then {_unit setVariable ["BURNS_pointFireLease",nil,true]};
    };
};
if (local _group) then {_group setVariable ["FST_HC_taskNext",time];_group setVariable ["BURNS_engagementNext",time+2]};
if (_kind=="casualty" && {!isNull _target}) then {
    private _claim=_target getVariable ["BURNS_casualtyClaim",[]];
    if (count _claim==3 && {(_claim select 0)==_group} && {(_claim select 2)==_owner} && {local _group}) then {
        _target setVariable ["BURNS_casualtyClaim",nil,true];
    };
};
