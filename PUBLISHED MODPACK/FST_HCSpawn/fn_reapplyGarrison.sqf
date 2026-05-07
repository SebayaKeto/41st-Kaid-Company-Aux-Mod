// FST_HCSpawn_fnc_reapplyGarrison
// Runs on HC. Waits until group is local, then re-disables PATH.
// Called via CBA event from transferGroup.
//
// Arguments:
//   0: GROUP

params ["_group"];

private _reportState = {
    params ["_state"];
    private _var = switch (_state) do {
        case "request": { "FST_HC_ReapplyGarrisonRequests" };
        case "success": { "FST_HC_ReapplyGarrisonSuccesses" };
        case "timeout": { "FST_HC_ReapplyGarrisonTimeouts" };
        case "stale": { "FST_HC_ReapplyGarrisonStale" };
        default { "" };
    };
    if (_var isEqualTo "") exitWith {};

    // Keep a local HC-side counter for HC RPT debugging, and report to the server
    // so Shift+F4/status output has useful totals.
    missionNamespace setVariable [_var, (missionNamespace getVariable [_var, 0]) + 1];
    if (!isServer) then {
        ["FST_HC_evt_reapplyGarrisonDiag", [_state]] call CBA_fnc_serverEvent;
    };
};

if (isNull _group) exitWith { ["stale"] call _reportState; };

["request"] call _reportState;

private _timeout = time + 15;

[
    {
        params ["_group", "_timeout", "_reportState"];

        isNull _group ||
        {count units _group == 0} ||
        {local _group} ||
        {time >= _timeout}
    },
    {
        params ["_group", "_timeout", "_reportState"];

        // Quietly ignore groups that were deleted, cleaned up, or emptied before
        // locality settled. These were producing scary-but-harmless timeout logs.
        if (isNull _group || {count units _group == 0}) exitWith { ["stale"] call _reportState; };

        if (!local _group) exitWith {
            ["timeout"] call _reportState;

            if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
                diag_log format [
                    "[FST_HCSpawn] reapplyGarrison skipped: group %1 did not become local before timeout. owner=%2 units=%3",
                    _group,
                    groupOwner _group,
                    count units _group
                ];
            };
        };

        {
            if (!isNull _x && {alive _x}) then {
                _x disableAI "PATH";
                _x forceSpeed 0;
            };
        } forEach units _group;

        ["success"] call _reportState;

        if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
            diag_log format ["[FST_HCSpawn] reapplyGarrison complete for %1 (%2 units)", _group, count units _group];
        };
    },
    [_group, _timeout, _reportState],
    15
] call CBA_fnc_waitUntilAndExecute;
