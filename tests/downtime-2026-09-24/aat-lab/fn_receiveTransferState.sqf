// Server: accept only the still-pending request for this group's current owner.
if (!isServer) exitWith {};
params ["_group","_serial","_owner","_rows"];
if (isNull _group) exitWith {};
private _pending=_group getVariable ["FST_HC_stateRequest",[]];
if (count _pending!=4 || {(_pending select 0)!=_serial} || {(_pending select 1)!=_owner}) exitWith {};
_pending params ["_expectedSerial","_expectedOwner","_kind","_args"];
_group setVariable ["FST_HC_stateRequest",nil];
_group setVariable ["FST_HC_pendingTransfer",nil];
if (count _rows==0 || {groupOwner _group!=_owner} || {(_group getVariable ["FST_HC_stateSerial",-1])!=_serial}) exitWith {
    if (_kind=="hold" && {(_group getVariable ["FST_HC_heldBy",-1])==(_args select 0)}) then {_group setVariable ["FST_HC_heldBy",-1,true]};
    _group setVariable ["FST_HC_interceptQueued",nil,true];
    diag_log format ["[FST_HCSpawn] Movement snapshot expired or locality changed; group %1 left in place",_group];
};
private _snapshot=[_owner,_serial,_rows];
if (_kind=="transfer") then {
    _args params ["_force","_rehome"];
    if (_rehome) then {_group setVariable ["FST_HC_rehome",true]};
    [_group,_force,_snapshot] call FST_HCSpawn_fnc_transferGroup;
};
if (_kind=="hold") then {
    _args params ["_zeusId","_zeusIdForEvent"];
    if ((_group getVariable ["FST_HC_heldBy",-1])!=_zeusId) exitWith {};
    [_group,_zeusId,true,_zeusIdForEvent,_snapshot] call FST_HCSpawn_fnc_zeusHold;
};
