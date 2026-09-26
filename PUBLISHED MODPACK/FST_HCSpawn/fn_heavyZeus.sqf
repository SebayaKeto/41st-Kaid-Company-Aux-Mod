// Only a fresh curator placement can be rolled back. Never sweep/delete an army.
params ["_objects", "_sourceOwner", ["_attempt",0]];
if (!isServer || {!([_sourceOwner,"heavy placement"] call FST_HCSpawn_fnc_isAuthorizedCaller)}) exitWith {};
_objects=_objects select {!isNull _x && {alive _x} && {([typeOf _x] call FST_HCSpawn_fnc_heavyKind)>=0}};
if (_objects isEqualTo []) exitWith {};
// Newly created objects can report owner 0 for one frame. Bound retries and
// preserve the authorization and owner checks when ownership becomes available.
private _pending=_objects select {(owner _x)==0 && {!(_x getVariable ["FST_heavyZeusChecked",false])}};
if (_attempt<8 && {count _pending>0}) then {
    [{_this call FST_HCSpawn_fnc_heavyZeus},[_pending,_sourceOwner,_attempt+1],0.25] call CBA_fnc_waitAndExecute;
};
private _fresh=_objects select {
    diag_tickTime-(_x getVariable ["FST_heavyCreatedAt",-1e6])<15 &&
    {!(_x getVariable ["FST_heavyZeusChecked",false])} &&
    {(owner _x)==_sourceOwner}
};
if (_fresh isEqualTo []) exitWith {};
{_x setVariable ["FST_heavyZeusChecked",true]} forEach _fresh;
private _destination=["infantry",count _fresh] call FST_HCSpawn_fnc_getSpawnTarget;
private _decision=[_fresh apply {typeOf _x},_destination,_fresh,false] call FST_HCSpawn_fnc_heavyCheck;
if (_decision select 0) exitWith {};
private _removed=0;
{
    private _u=_x;
    private _protected=[_u] call FST_HCSpawn_fnc_isPlayerControlledUnit;
    if (!isNull (_u getVariable ["FST_ATRT_rider",objNull])) then {_protected=true};
    if ((attachedObjects _u findIf {isPlayer _x})>=0 || {(crew _u findIf {[_x] call FST_HCSpawn_fnc_isPlayerControlledUnit})>=0}) then {_protected=true};
    if (!_protected && {vehicle _u==_u}) then {deleteVehicle _u; _removed=_removed+1};
} forEach _fresh;
format ["[FST] Heavy placement blocked: %1. Removed %2 newly placed AI; protected/player units retained.",_decision select 1,_removed] remoteExec ["systemChat",_sourceOwner];
diag_log format ["[FST_PERF] Zeus placement rejected owner=%1 count=%2 reason=%3",_sourceOwner,_removed,_decision select 1];
