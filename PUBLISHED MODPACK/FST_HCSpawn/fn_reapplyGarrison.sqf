// FST_HCSpawn_fnc_reapplyGarrison
// Runs on HC. Waits until group is local, then re-disables PATH.
// Called via CBA event from transferGroup.
//
// Arguments:
//   0: GROUP

params ["_group"];

// Wait until local (15s timeout). Timeout code is the 5th argument of
// CBA_fnc_waitUntilAndExecute; the statement only runs when the condition is met.
[
    {
        params ["_group"];
        isNull _group || {local _group}
    },
    {
        params ["_group"];
        if (isNull _group) exitWith {};

        {
            if (([_x] call FST_HCSpawn_fnc_burnsRole) == "webknight") then {continue};
            _x disableAI "PATH";
            // Reassert stance on the new owner. Like disableAI, setUnitPos is
            // arguments-local and its effect does not reliably survive setGroupOwner,
            // so garrisoned droids were dropping back to AUTO (prone/crouch) after
            // transfer to an HC.
            // V27: forceSpeed 0 removed. PATH disabled already pins the unit, and
            // forceSpeed was never reverted, leaving units frozen if Zeus later
            // re-enabled movement.
            if (([_x] call FST_HCSpawn_fnc_burnsRole) == "b1") then {_x setUnitPos "UP"};
        } forEach units _group;
    },
    [_group],
    15,
    {
        params ["_group"];
        diag_log format ["[FST_HCSpawn] reapplyGarrison timed out for %1", _group];
    }
] call CBA_fnc_waitUntilAndExecute;
