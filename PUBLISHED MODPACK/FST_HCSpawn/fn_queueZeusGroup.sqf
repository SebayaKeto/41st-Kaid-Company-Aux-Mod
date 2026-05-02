// FST_HCSpawn_fnc_queueZeusGroup
// Server-side. Validates a Zeus-placed group and either transfers it immediately
// or queues it for the normal HC transfer processor.
// Arguments:
//   0: GROUP  - group placed by Zeus
//   1: NUMBER - Zeus client owner ID, optional/debug only

if (!isServer) exitWith { false };

params ["_group", ["_zeusOwner", -1]];

if (isNull _group) exitWith { false };

// If we reject the group, clear the client-visible intercept marker so Zeus is not left confused.
private _clearIntercept = {
    _group setVariable ["FST_HC_interceptQueued", nil, true];
    _group setVariable ["FST_HC_pendingTransfer", nil];
};

if (count FST_HC_Array == 0) exitWith { call _clearIntercept; false };
if (count units _group == 0) exitWith { call _clearIntercept; false };
if (isPlayer leader _group) exitWith { call _clearIntercept; false };

if ([_group] call FST_HCSpawn_fnc_isBlacklisted) exitWith { call _clearIntercept; false };

// Already tracked? Nothing to do.
if (count (_group getVariable ["FST_HC_tracked", []]) > 0) exitWith { true };

// Already on an HC but somehow not tracked yet.
private _ownerID = groupOwner _group;
if (_ownerID in FST_HC_Ids) exitWith {
    private _hcIdx = FST_HC_Ids find _ownerID;
    [_group, _hcIdx, false] call FST_HCSpawn_fnc_trackGroup;
    call _clearIntercept;
    true
};

// Avoid duplicate EH/double-click paths queueing or transferring the same group twice.
if (_group getVariable ["FST_HC_pendingTransfer", false]) exitWith { true };

_group setVariable ["FST_HC_pendingTransfer", true];

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Zeus group accepted from owner %1: %2 (%3 units), current owner %4", _zeusOwner, _group, count units _group, _ownerID];
};

// Keep the 'instant Zeus placement' feel. We do not clone/delete; we wait a tiny
// settle delay, then try setGroupOwner immediately. If the engine refuses, the
// group falls back to the normal batched queue.
if (missionNamespace getVariable ["FST_HC_ZeusImmediateTransfer", true]) then {
    FST_HC_ZeusImmediateRequests = (missionNamespace getVariable ["FST_HC_ZeusImmediateRequests", 0]) + 1;

    [{
        params ["_grp"];
        if (!isServer) exitWith {};
        if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) exitWith {
            if (!isNull _grp) then {
                _grp setVariable ["FST_HC_pendingTransfer", nil];
                _grp setVariable ["FST_HC_interceptQueued", nil, true];
            };
        };

        private _ok = [_grp] call FST_HCSpawn_fnc_transferGroup;
        if (!_ok) then {
            FST_HC_ZeusImmediateFallbacks = (missionNamespace getVariable ["FST_HC_ZeusImmediateFallbacks", 0]) + 1;

            if (missionNamespace getVariable ["FST_HC_ZeusLegacyFallback", false]) then {
                private _legacyOk = [_grp] call FST_HCSpawn_fnc_legacyRespawnGroup;
                if (!_legacyOk) then {
                    _grp setVariable ["FST_HC_pendingTransfer", true];
                    FST_HC_TransferQueue pushBackUnique _grp;
                };
            } else {
                _grp setVariable ["FST_HC_pendingTransfer", true];
                FST_HC_TransferQueue pushBackUnique _grp;
            };

            if (FST_HC_DebugLogging) then {
                diag_log format ["[FST_HCSpawn] Immediate Zeus transfer failed; fallback path handled %1", _grp];
            };
        };
    }, [_group], missionNamespace getVariable ["FST_HC_ZeusTransferSettleDelay", 0.2]] call CBA_fnc_waitAndExecute;
} else {
    FST_HC_TransferQueue pushBackUnique _group;
};

true
