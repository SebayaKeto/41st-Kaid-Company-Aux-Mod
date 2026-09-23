// New owner: restore only the individual holds captured on the previous owner.
// No leader-wide inference and no unconditional stance changes.
params ["_group","_snapshot","_target"];
_snapshot params ["_previousOwner","_serial","_rows"];
[
    {
        params ["_group","_serial","_rows","_target"];
        isNull _group || {local _group && {(_group getVariable ["FST_HC_stateSerial",-1])>=_serial} && {(_rows findIf {private _unit=_x select 0;!isNull _unit && {group _unit==_group} && {!local _unit}})<0}}
    },
    {
        params ["_group","_serial","_rows","_target"];
        // groupOwner is server-only; local plus clientOwner validate this owner.
        if (isNull _group || {!local _group} || {clientOwner!=_target} || {(_group getVariable ["FST_HC_stateSerial",-1])!=_serial}) exitWith {};
        if ([_group] call FST_HCSpawn_fnc_isProtectedVehicleGroup) exitWith {};
        {
            _x params ["_unit","_path","_move","_burnsOwned","_revision"];
            if (isNull _unit || {!local _unit} || {group _unit!=_group} || {([_unit] call FST_HCSpawn_fnc_isPlayerControlledUnit)} || {([_unit] call FST_HCSpawn_fnc_burnsRole)=="webknight"}) then {continue};
            // A newer Stop/task owns the BURNS hold decision. External holds
            // remain external and are not released by a BURNS task change.
            private _sameBurnsHold=!_burnsOwned || {(_unit getVariable ["BURNS_ownsPath",false]) && {(([_group,["BURNS_movementRevision",0]] call FST_HCSpawn_fnc_burnsStateGet))==_revision}};
            if (!_path && {_sameBurnsHold}) then {_unit disableAI "PATH"};
            if (!_move) then {_unit disableAI "MOVE"};
        } forEach _rows;
    },
    [_group,_serial,_rows,_target],15,
    {params ["_group"];diag_log format ["[FST_HCSpawn] Per-unit movement restore timed out for %1",_group]}
] call CBA_fnc_waitUntilAndExecute;
