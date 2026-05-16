// FST_HCSpawn_fnc_catchUntracked
// Server-side. Scans allGroups for AI groups not tracked on an HC.
// Queues them for HC transfer. Runs periodically via PFH.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {}; // no HCs, nothing to offload
if (FST_HC_EmergencyMode) exitWith {}; // do not sweep while failover is moving groups

// If the transfer queue is already backed up, let the processor drain it instead
// of doing another allGroups sweep and adding more scheduler work.
private _queueSoftLimit = (missionNamespace getVariable ["FST_HC_TransferBatchSize", 4]) * 6;
if (count FST_HC_TransferQueue >= _queueSoftLimit) exitWith {};

private _queued = 0;

{
    private _grp = _x;

    // Skip: null, empty, player groups
    if (isNull _grp) then { continue };
    if (count units _grp == 0) then { continue };
    if (isPlayer leader _grp) then { continue };

    // Skip: already tracked on HC
    if (count (_grp getVariable ["FST_HC_tracked", []]) > 0) then { continue };

    // Skip: held by Zeus
    if ((_grp getVariable ["FST_HC_heldBy", -1]) != -1) then { continue };

    // Skip: Zeus instant-clone originals currently waiting on server/HC confirmation.
    // These originals are intentionally hidden/frozen briefly; catch-all must not
    // queue them for setGroupOwner while the replacement handoff is still resolving.
    if (_grp getVariable ["FST_HC_interceptQueued", false]) then { continue };
    private _suppressedOriginal = (units _grp) findIf { !isNull _x && {_x getVariable ["FST_HC_originalSuppressed", false]} };
    if (_suppressedOriginal >= 0) then { continue };

    // Skip: already pending or already in transfer queue
    if (_grp getVariable ["FST_HC_pendingTransfer", false]) then { continue };
    if (_grp in FST_HC_TransferQueue) then { continue };

    // Skip: blacklisted (result cached on group)
    if ([_grp] call FST_HCSpawn_fnc_isBlacklisted) then { continue };

    // Skip/register: already on an HC but not tracked
    private _ownerID = groupOwner _grp;
    if (_ownerID in FST_HC_Ids) then {
        private _hcIdx = FST_HC_Ids find _ownerID;
        [_grp, _hcIdx] call FST_HCSpawn_fnc_trackGroup;
        continue;
    };

    // This group is server-owned AI — queue for transfer
    _grp setVariable ["FST_HC_pendingTransfer", true];
    FST_HC_TransferQueue pushBackUnique _grp;
    _queued = _queued + 1;
} forEach allGroups;

if (_queued > 0 && {FST_HC_DebugLogging}) then {
    diag_log format ["[FST_HCSpawn] Catch-all: queued %1 untracked groups for transfer", _queued];
};
