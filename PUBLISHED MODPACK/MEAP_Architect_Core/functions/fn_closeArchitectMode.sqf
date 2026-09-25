params [
    ["_unit", objNull, [objNull]],
    ["_serverInitiated", false, [false]],
    ["_serverToken", "", [""]]
];

if (!isServer || {isNull _unit}) exitWith {};
// Headless remote calls can report owner zero and isRemoteExecuted=false.
// Server cleanup therefore requires the active session token, not just a flag.
if (_serverInitiated && {(_serverToken isEqualTo "") || {_serverToken isNotEqualTo (_unit getVariable ["MEAP_Architect_serverCloseToken", ""])}}) exitWith {};
if (!_serverInitiated && {remoteExecutedOwner != owner _unit}) exitWith {};
call MEAP_fnc_initializeArchitectState;

private _sessionKey = "";
{
    if ((_y select 0) isEqualTo _unit) exitWith
    {
        _sessionKey = _x;
    };
} forEach MEAP_Architect_sessions;
if (_sessionKey isNotEqualTo "") then
{
    MEAP_Architect_sessions deleteAt _sessionKey;
};
_unit setVariable ["MEAP_Architect_serverCloseToken", nil];

private _releasedLocks = [];
{
    if ((_y select 0) isEqualTo _unit) then
    {
        _releasedLocks pushBack _x;
    };
} forEach MEAP_Architect_editLocks;
{
    MEAP_Architect_editLocks deleteAt _x;
} forEach _releasedLocks;

if (_serverInitiated) then
{
    [] remoteExecCall ["MEAP_fnc_closeArchitectCamera", owner _unit];
};
