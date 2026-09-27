// FST_stonewall_fnc_awaitReply
// Client-side. After a Zeus module sends a request to the server, tell Zeus if no answer arrives in time
// (a mission CfgRemoteExec whitelist can block the request silently).
// The reply time lives in localNamespace, so another machine's publicVariable cannot touch it.
// Arguments: 0: what was requested <STRING>, 1: timeout s <NUMBER>, 2: advice shown on timeout <STRING>

params [["_what", "", [""]], ["_timeout", 20, [0]], ["_advice", "", [""]]];
localNamespace setVariable ["FST_stonewall_lastReply", -1];
[_what, _timeout, _advice] spawn {
    params ["_what", "_timeout", "_advice"];
    private _t = diag_tickTime;
    waitUntil { sleep 1; (localNamespace getVariable ["FST_stonewall_lastReply", -1]) > 0 || {diag_tickTime - _t > _timeout} };
    if ((localNamespace getVariable ["FST_stonewall_lastReply", -1]) < 0) then {
        systemChat format ["Stonewall: no answer from the server for '%1' after %2 s. %3", _what, _timeout, _advice];
    };
};
