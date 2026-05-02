// FST_HCSpawn_fnc_emergencyRedistribute
// Server-side. Called when an HC disconnects.
// Redistributes orphaned groups across remaining HCs.
// If no HCs remain, groups stay on server (engine handles this automatically
// when the owning client disconnects — ownership reverts to server).
//
// Arguments:
//   0: ARRAY of GROUPs — orphaned groups

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
    if (isNull _grp || {count units _grp == 0}) then { continue };

    private _isGarrisoned = !(leader _grp checkAIFeature "PATH");

    // Pick least loaded
    private _targetId = [] call FST_HCSpawn_fnc_getSpawnTarget;
    private _hcIndex = FST_HC_Ids find _targetId;

    // Save loadouts
    if (FST_HC_PreserveLoadouts) then {
        { _x setVariable ["FST_HC_savedLoadout", getUnitLoadout _x]; } forEach units _grp;
    };

    // Transfer
    _grp setGroupOwner _targetId;
    [_grp, _hcIndex] call FST_HCSpawn_fnc_trackGroup;

    // Reapply garrison
    if (_isGarrisoned) then {
        ["FST_HC_evt_reapplyGarrison", [_grp], _targetId] call CBA_fnc_ownerEvent;
    };

    // Restore loadouts
    if (FST_HC_PreserveLoadouts) then {
        private _units = units _grp;
        [{
            params ["_units"];
            { if (uniform _x == "") then { _x setUnitLoadout (_x getVariable ["FST_HC_savedLoadout", typeOf _x]); }; } forEach _units;
        }, [_units], 1] call CBA_fnc_waitAndExecute;
    };

    sleep 0.2; // stagger to avoid overload
} forEach _groups;

FST_HC_EmergencyMode = false;

// Recount
[] call FST_HCSpawn_fnc_recountUnits;

["Emergency redistribute complete"] remoteExec ["hint", -2];
diag_log "[FST_HCSpawn] Emergency redistribute complete";
