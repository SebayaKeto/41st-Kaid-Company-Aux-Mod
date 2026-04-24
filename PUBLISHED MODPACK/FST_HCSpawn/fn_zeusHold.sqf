// FST_HCSpawn_fnc_zeusHold
// Dual-purpose: Client UI (no args) or Server transfer (with args).
//
// CLIENT (no args): reads curator selection, sends hold/release requests to server.
// SERVER (3 args): [group, zeusOwnerID, holdBool] — executes the actual transfer.

// ============================================================
// SERVER PATH — called via remoteExecCall
// ============================================================
if (isServer && {count _this == 3}) exitWith {
    params ["_grp", "_zeusId", "_hold"];

    if (_hold) then {
        // HOLD: pull group from HC to Zeus
        // Untrack from HC
        private _data = FST_HC_GroupMap getOrDefault [_grp, []];
        FST_HC_GroupMap deleteAt _grp;

        // Detect garrison
        private _isGarrisoned = !(leader _grp checkAIFeature "PATH");

        // Transfer ownership to Zeus client
        _grp setGroupOwner _zeusId;

        // Reapply garrison on Zeus machine
        if (_isGarrisoned) then {
            [_grp] remoteExecCall ["FST_HCSpawn_fnc_reapplyGarrison", _zeusId];
        };

        // Mark as held
        FST_HC_ZeusHeld set [_grp, _zeusId];
        _grp setVariable ["FST_HC_heldBy", _zeusId, true];

        diag_log format ["[FST_HCSpawn] Zeus %1 holding group %2", _zeusId, _grp];
    } else {
        // RELEASE: send group back to transfer queue
        FST_HC_ZeusHeld deleteAt _grp;
        _grp setVariable ["FST_HC_heldBy", -1, true];
        FST_HC_TransferQueue pushBackUnique _grp;

        diag_log format ["[FST_HCSpawn] Zeus %1 released group %2", _zeusId, _grp];
    };
};

// ============================================================
// CLIENT PATH — Zeus keybind handler
// ============================================================
if (!hasInterface) exitWith {};
if (!FST_HC_ZeusHoldEnabled) exitWith { systemChat "[FST] Zeus hold is disabled."; };

private _curator = getAssignedCuratorLogic player;
if (isNull _curator) exitWith {};

private _selected = curatorSelected select 1;
if (count _selected == 0) exitWith {
    systemChat "[FST] Select groups first (Ctrl+click).";
};

private _held = 0;
private _released = 0;
private _skipped = 0;
private _who = clientOwner;

{
    private _grp = _x;
    if (isNull _grp || {isPlayer leader _grp}) then { _skipped = _skipped + 1; continue };

    // Check if this group is currently held (check local copy of the hashmap)
    // We use a variable set by the server for reliable checking
    private _heldBy = _grp getVariable ["FST_HC_heldBy", -1];

    if (_heldBy == _who) then {
        // Already held by us — release
        _grp setVariable ["FST_HC_heldBy", -1, true];
        [_grp, _who, false] remoteExecCall ["FST_HCSpawn_fnc_zeusHold", 2];
        _released = _released + 1;
    } else {
        if (_heldBy != -1) then {
            _skipped = _skipped + 1; // held by another Zeus
        } else {
            // Hold it
            _grp setVariable ["FST_HC_heldBy", _who, true];
            [_grp, _who, true] remoteExecCall ["FST_HCSpawn_fnc_zeusHold", 2];
            _held = _held + 1;
        };
    };
} forEach _selected;

if (_held > 0) then { systemChat format ["[FST] Holding %1 groups.", _held]; };
if (_released > 0) then { systemChat format ["[FST] Released %1 groups.", _released]; };
if (_skipped > 0) then { systemChat format ["[FST] %1 skipped (player/other Zeus).", _skipped]; };
