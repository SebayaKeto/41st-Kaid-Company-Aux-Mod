// FST_HCSpawn_fnc_emergencyRedistribute
// Server-side. Called when an HC disconnects.
// Redistributes orphaned groups across remaining HCs.

if (!isServer) exitWith {};

params ["_groups"];

if (count FST_HC_Array == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Emergency: no HCs remaining — %1 groups on server", count _groups];
    ["HC disconnected. No HCs remaining — AI on server."] remoteExec ["hint", -2];
};

FST_HC_EmergencyMode = true;

// Watchdog: if this spawn dies before reaching the cleanup at the end (broken
// modded unit during loadout save, etc.) the EmergencyMode flag would stay
// true and processTransfers would be locked forever. Force-clear after a
// generous deadline regardless of how the body exits.
private _watchdogDeadline = time + 120;
[{
    params ["_deadline"];
    if (FST_HC_EmergencyMode && {time >= _deadline}) then {
        FST_HC_EmergencyMode = false;
        diag_log "[FST_HCSpawn] Emergency watchdog: force-cleared FST_HC_EmergencyMode after deadline";
    };
}, [_watchdogDeadline], 130] call CBA_fnc_waitAndExecute;

private _redistributeDelay = missionNamespace getVariable ["FST_HC_EmergencyRedistributeDelay", 1.0];
_redistributeDelay = (_redistributeDelay max 0.2) min 2;
private _movedCount = 0;

["HC disconnected — redistributing AI"] remoteExec ["hint", -2];
diag_log format ["[FST_HCSpawn] Emergency redistribute: %1 groups to %2 remaining HCs", count _groups, count FST_HC_Array];

{
    private _grp = _x;
    if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) then { continue };

    _grp setVariable ["FST_HC_tracked", nil];
    _grp setVariable ["FST_HC_onHC", nil];
    _grp setVariable ["FST_HC_pendingTransfer", nil];
    _grp setVariable ["FST_HC_interceptQueued", nil, true];

    private _ok = [_grp] call FST_HCSpawn_fnc_transferGroup;
    if (_ok) then { _movedCount = _movedCount + 1; };

    if ((_movedCount > 0) && {(_movedCount mod 10) == 0}) then {
        [] call FST_HCSpawn_fnc_recountUnits;
    };

    sleep _redistributeDelay;
} forEach _groups;

FST_HC_EmergencyMode = false;

[] call FST_HCSpawn_fnc_recountUnits;

["Emergency redistribute complete"] remoteExec ["hint", -2];
diag_log format ["[FST_HCSpawn] Emergency redistribute complete. moved=%1 delay=%2", _movedCount, _redistributeDelay];
