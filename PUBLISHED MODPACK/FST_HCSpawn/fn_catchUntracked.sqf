// FST_HCSpawn_fnc_catchUntracked
// Server-side. Scans allGroups for AI groups not in our hashmap.
// Queues them for HC transfer. Runs periodically via PFH.
// Cost: O(allGroups) with O(1) hashmap lookups — fast even at scale.

if (!isServer) exitWith {};
if (count FST_HC_Array == 0) exitWith {}; // no HCs, nothing to offload

private _queued = 0;

{
    private _grp = _x;

    // Skip: player groups, empty, null
    if (isPlayer leader _grp) then { continue };
    if (isNull _grp) then { continue };
    if (count units _grp == 0) then { continue };

    // Skip: already tracked on HC (O(1))
    if (_grp in FST_HC_GroupMap) then { continue };

    // Skip: held by Zeus (O(1))
    if (_grp in FST_HC_ZeusHeld) then { continue };

    // Skip: already in transfer queue
    if (_grp in FST_HC_TransferQueue) then { continue };

    // Skip: blacklisted (result cached on group)
    if ([_grp] call FST_HCSpawn_fnc_isBlacklisted) then { continue };

    // Skip: already on an HC (owned by one of our HC IDs)
    private _ownerID = owner leader _grp;
    if (_ownerID in FST_HC_Ids) then {
        // It's on an HC but not tracked — register it
        private _hcIdx = FST_HC_Ids find _ownerID;
        [_grp, _hcIdx] call FST_HCSpawn_fnc_trackGroup;
        continue;
    };

    // This group is server-owned AI — queue for transfer
    FST_HC_TransferQueue pushBack _grp;
    _queued = _queued + 1;
} forEach allGroups;

if (_queued > 0) then {
    diag_log format ["[FST_HCSpawn] Catch-all: queued %1 untracked groups for transfer", _queued];
};
