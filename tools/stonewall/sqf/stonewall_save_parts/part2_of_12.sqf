localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "[""Stonewall: Zeus or admin only.""] call _reply;
};
private _lock = localNamespace getVariable [""stonewall_busy"", []];
if (_lock isEqualType [] && {count _lock == 2} && {diag_tickTime - (_lock select 1) < 900}) exitWith {
diag_log format [""STONEWALL: save %1 is still running - request from owner %2 ignored"", _lock select 0, _req];
[""Stonewall: a save is already running - wait for its confirmation.""] call _reply;
};
private _lockId = str diag_tickTime + str random 1e6;
localNamespace setVariable [""stonewall_busy"", [_lockId, diag_tickTime]];
[""Stonewall: save started on the server - the confirmation follows when it is done.""] call _reply;
private _args = if (isNil ""_this"") then { [] } else { if (_this isEqualType []) then { _this } else { [] } };
private _opts = missionNamespace getVariable [""stonewall_opts"", createHashMap];
"];
