// FST_HCSpawn_fnc_catchUntracked
// Server-side. Scans allGroups for AI groups not tracked on an HC.
// Queues them for HC transfer. Runs periodically via PFH.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {}; // no HCs, nothing to offload
if (FST_HC_EmergencyMode) exitWith {}; // do not sweep while failover is moving groups
if (time < (missionNamespace getVariable ["FST_HC_SafeModeUntil", -1])) exitWith {}; // HC-disconnect safe mode

// If the transfer queue is already backed up, let the processor drain it instead
// of doing another allGroups sweep and adding more scheduler work.
private _queueSoftLimit = (missionNamespace getVariable ["FST_HC_TransferBatchSize", 4]) * 6;
if (count FST_HC_TransferQueue >= _queueSoftLimit) exitWith {};

// V27: if no HC can accept groups right now (all over the soft cap, or none
// valid), skip the whole sweep. Previously every sweep re-queued the same groups,
// the processor tried and failed each one, and they were re-queued 30s later.
if (([] call FST_HCSpawn_fnc_getSpawnTarget) == 2) exitWith {};

// Zeus mode "off" promises Zeus-placed AI are left where Zeus put them. Those
// groups are local to the Zeus client, so anything not owned by the server or an
// HC is skipped in that mode.
private _zeusOff = (missionNamespace getVariable ["FST_HC_ZeusMode", "instant"]) isEqualTo "off";

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
    // V27: the server marks the GROUP when it suppresses the original, so this no
    // longer walks every unit of every untracked group each sweep.
    if (_grp getVariable ["FST_HC_interceptQueued", false]) then { continue };
    if (_grp getVariable ["FST_HC_originalSuppressed", false]) then { continue };

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

    // Zeus mode off: leave client-owned (Zeus-placed) groups alone.
    if (_zeusOff && {_ownerID != 2}) then { continue };

    // This group is server-owned AI -- queue for transfer
    _grp setVariable ["FST_HC_pendingTransfer", true];
    FST_HC_TransferQueue pushBackUnique _grp;
    _queued = _queued + 1;
} forEach allGroups;

if (_queued > 0 && {FST_HC_DebugLogging}) then {
    diag_log format ["[FST_HCSpawn] Catch-all: queued %1 untracked groups for transfer", _queued];
};
