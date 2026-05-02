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

["HC disconnected — redistributing AI"] remoteExec ["hint", -2];
diag_log format ["[FST_HCSpawn] Emergency redistribute: %1 groups to %2 remaining HCs", count _groups, count FST_HC_Array];

{
    private _grp = _x;
    if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) then { continue };

    _grp setVariable ["FST_HC_tracked", nil];
    _grp setVariable ["FST_HC_onHC", nil];
    _grp setVariable ["FST_HC_pendingTransfer", nil];
    _grp setVariable ["FST_HC_interceptQueued", nil, true];

    [_grp] call FST_HCSpawn_fnc_transferGroup;

    sleep 0.2;
} forEach _groups;

FST_HC_EmergencyMode = false;

[] call FST_HCSpawn_fnc_recountUnits;

["Emergency redistribute complete"] remoteExec ["hint", -2];
diag_log "[FST_HCSpawn] Emergency redistribute complete";
