// FST_HCSpawn_fnc_handleZeusOriginalDecision
// Server-side. Final authority for hidden Zeus originals during instant clone/replace.
// _accepted=false restores/clears original. _accepted=true deletes it after a short grace.
// This must run on the server because hideObjectGlobal / enableSimulationGlobal are server-exec commands.

if (!isServer) exitWith { false };

params ["_originalPayload", ["_accepted", false]];
if (count _originalPayload != 3) exitWith { false };

_originalPayload params ["_group", "_units", "_vehicle"];

private _originalObjects = [];
if (!isNull _vehicle) then {
    _originalObjects pushBackUnique _vehicle;
    { _originalObjects pushBackUnique _x; } forEach crew _vehicle;
} else {
    { _originalObjects pushBackUnique _x; } forEach _units;
};

if (!_accepted) exitWith {
    {
        if (!isNull _x) then {
            _x hideObjectGlobal false;
            _x enableSimulationGlobal true;
            _x setVariable ["FST_HC_originalSuppressed", nil, true];
            _x setVariable ["FST_skipSpawnDamage", nil, true];
        };
    } forEach _originalObjects;

    if (!isNull _group) then {
        _group setVariable ["FST_HC_interceptQueued", nil, true];
        _group setVariable ["FST_HC_pendingTransfer", nil];
    };
    false
};

// Ignore late accepts after a prior restore/rejection. Without this, an overdue
// HC/server confirmation could delete a Zeus original that the failsafe already
// restored. Only accepted clones whose originals are still suppressed may delete.
private _stillSuppressed = (_originalObjects findIf {
    !isNull _x && {_x getVariable ["FST_HC_originalSuppressed", false]}
}) >= 0;
if (!_stillSuppressed) exitWith {
    if (!isNull _group) then {
        _group setVariable ["FST_HC_interceptQueued", nil, true];
        _group setVariable ["FST_HC_pendingTransfer", nil];
    };
    if (missionNamespace getVariable ["FST_HC_DebugLogging", false]) then {
        diag_log format ["[FST_HCSpawn] Ignored late Zeus clone accept for already-restored original group %1", _group];
    };
    false
};

// Accepted: clear queue state immediately so the server failsafe/catch-all cannot
// race the 2s delete grace. The units stay marked as suppressed, so catch-all still
// ignores them until deletion.
if (!isNull _group) then {
    _group setVariable ["FST_HC_interceptQueued", nil, true];
    _group setVariable ["FST_HC_pendingTransfer", nil];
};

// Keep the old objects hidden/frozen for a brief grace before deleting. This
// reduces immediate object delete churn while still removing stale Zeus originals.
[{
    params ["_group", "_units", "_vehicle"];

    if (!isNull _vehicle) then {
        { _x setVariable ["FST_skipSpawnDamage", true, true]; } forEach crew _vehicle;
        { if (!isNull _x) then { _vehicle deleteVehicleCrew _x; }; } forEach crew _vehicle;
        if (!isNull _vehicle) then { deleteVehicle _vehicle; };
    } else {
        {
            if (!isNull _x) then {
                _x setVariable ["FST_skipSpawnDamage", true, true];
                deleteVehicle _x;
            };
        } forEach _units;
    };

    if (!isNull _group) then {
        _group deleteGroupWhenEmpty true;
    };
}, [_group, _units, _vehicle], 2] call CBA_fnc_waitAndExecute;

true
