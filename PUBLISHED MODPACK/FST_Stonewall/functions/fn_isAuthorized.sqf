// FST_stonewall_fnc_isAuthorized
// Server-side. May the sender of the current remoteExec act? Uses remoteExecutedOwner, never a claimed ID.
// Zeus/admin check. NOTE (engine probe 27 Sep, Arma 2.22): a remoteExecCall from another machine can arrive with
// isRemoteExecuted=false and remoteExecutedOwner=0, which looks exactly like a server-local call and is allowed.
// So this check stops honest misuse and gives feedback; it is not a security boundary (under the default
// CfgRemoteExec a client that can run scripts can remoteExec any command anyway).
// Arguments: 0: context label <STRING>
// Returns: [allowed <BOOL>, requester owner <NUMBER> (2 = server-local)]

params [["_context", "", [""]]];
if (!isServer) exitWith { [false, -1] };
if (!isRemoteExecuted) exitWith { [true, 2] };
private _req = remoteExecutedOwner;
if (_req <= 2) exitWith { [true, _req] };
private _ok = (admin _req) == 2 ||   // logged-in admin (not voted)
    {(allCurators findIf {
    private _u = getAssignedCuratorUnit _x;
    !isNull _u && {owner _u == _req}
}) >= 0};
if (!_ok) then {
    diag_log format ["STONEWALL: rejected %1 request from owner %2 (not a curator or admin)", _context, _req];
    ["FST_stonewall_done", ["Stonewall: Zeus or admin only."], _req] call CBA_fnc_ownerEvent;
};
[_ok, _req]
