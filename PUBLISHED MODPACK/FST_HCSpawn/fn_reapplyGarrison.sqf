// FST_HCSpawn_fnc_reapplyGarrison
// Runs on HC. Waits until group is local, then re-disables PATH.
// Called via CBA event from transferGroup.
//
// Arguments:
//   0: GROUP

params ["_group"];

// Wait until local or timeout
private _timeout = time + 15;

[{
    params ["_group", "_timeout"];
    isNull _group || local _group || time >= _timeout
}, {
    params ["_group", "_timeout"];
    if (time >= _timeout) exitWith {
        diag_log format ["[FST_HCSpawn] reapplyGarrison timed out for %1", _group];
    };
    if (isNull _group || {!local _group}) exitWith {};

    {
        _x disableAI "PATH";
        _x forceSpeed 0;
        // Reassert stance on the new owner. Like disableAI, setUnitPos is
        // arguments-local and its effect does not reliably survive setGroupOwner,
        // so garrisoned droids were dropping back to AUTO (prone/crouch) after
        // transfer to an HC.
        _x setUnitPos "UP";
    } forEach units _group;
}, [_group, _timeout], 15] call CBA_fnc_waitUntilAndExecute;
