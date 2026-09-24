// Server: request an owner-local movement snapshot before changing locality.
// true means accepted/pending, so callers must not clone a pending group.
if (!isServer) exitWith {false};
params ["_group","_kind","_args"];
if (isNull _group) exitWith {false};
private _pending=_group getVariable ["FST_HC_stateRequest",[]];
if (count _pending>0 && {(_pending select 2)==_kind} && {(_pending select 3) isEqualTo _args}) exitWith {true};
private _serial=(_group getVariable ["FST_HC_stateSerial",0])+1;
private _owner=groupOwner _group;
_group setVariable ["FST_HC_stateSerial",_serial,true];
_group setVariable ["FST_HC_stateRequest",[_serial,_owner,_kind,_args]];
["FST_HC_evt_captureTransferState",[_group,_serial,_owner],_owner] call CBA_fnc_ownerEvent;
// Bounded timeout: never perform a transfer using missing/default state.
[{
    params ["_group","_serial","_owner"];
    [_group,_serial,_owner,[]] call FST_HCSpawn_fnc_receiveTransferState;
},[_group,_serial,_owner],10] call CBA_fnc_waitAndExecute;
true
