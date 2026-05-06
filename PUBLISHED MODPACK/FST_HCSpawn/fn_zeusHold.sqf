// FST_HCSpawn_fnc_zeusHold
// CLIENT (no args): reads curator selection, sends hold/release via serverEvent.
// SERVER (4 args): [group, zeusOwnerID, holdBool, zeusOwnerID] — executes transfer.

// ============================================================
// SERVER PATH
// ============================================================
if (isServer && {count _this == 4}) exitWith {
    params ["_grp", "_zeusId", "_hold", "_zeusIdForEvent"];

    if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) exitWith {};

    if (_hold) then {
        // HOLD: pull from HC to Zeus client.
        _grp setVariable ["FST_HC_tracked", nil];
        _grp setVariable ["FST_HC_onHC", nil];
        _grp setVariable ["FST_HC_pendingTransfer", nil];
        _grp setVariable ["FST_HC_interceptQueued", nil, true];

        private _isGarrisoned = !(leader _grp checkAIFeature "PATH");
        private _moved = _grp setGroupOwner _zeusId;
        if (!_moved && {groupOwner _grp != _zeusId}) exitWith {
            _grp setVariable ["FST_HC_heldBy", -1, true];
            if (FST_HC_DebugLogging) then {
                diag_log format ["[FST_HCSpawn] Zeus hold failed: %1 to owner %2", _grp, _zeusId];
            };
        };

        if (_isGarrisoned) then {
            ["FST_HC_evt_reapplyGarrison", [_grp], _zeusId] call CBA_fnc_ownerEvent;
        };

        _grp setVariable ["FST_HC_heldBy", _zeusId, true];
        if (FST_HC_DebugLogging) then { diag_log format ["[FST_HCSpawn] Zeus %1 holding group %2", _zeusId, _grp]; };
    } else {
        // RELEASE: send back to transfer queue.
        _grp setVariable ["FST_HC_heldBy", -1, true];
        _grp setVariable ["FST_HC_pendingTransfer", true];
        FST_HC_TransferQueue pushBackUnique _grp;
        if (FST_HC_DebugLogging) then { diag_log format ["[FST_HCSpawn] Zeus %1 released group %2", _zeusId, _grp]; };
    };
};

// Server (no interface) reaching this point with non-4-arg input would silently
// fall into the client path. Guard explicitly.
if (!hasInterface) exitWith {};

// ============================================================
// CLIENT PATH
// ============================================================
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

    private _heldBy = _grp getVariable ["FST_HC_heldBy", -1];

    if (_heldBy == _who) then {
        _grp setVariable ["FST_HC_heldBy", -1, true];
        ["FST_HC_evt_zeusHold", [_grp, _who, false, _who]] call CBA_fnc_serverEvent;
        _released = _released + 1;
    } else {
        if (_heldBy != -1) then {
            _skipped = _skipped + 1;
        } else {
            _grp setVariable ["FST_HC_heldBy", _who, true];
            ["FST_HC_evt_zeusHold", [_grp, _who, true, _who]] call CBA_fnc_serverEvent;
            _held = _held + 1;
        };
    };
} forEach _selected;

if (_held > 0) then { systemChat format ["[FST] Holding %1 groups.", _held]; };
if (_released > 0) then { systemChat format ["[FST] Released %1 groups.", _released]; };
if (_skipped > 0) then { systemChat format ["[FST] %1 skipped (player/other Zeus).", _skipped]; };
