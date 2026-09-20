// FST_HCSpawn_fnc_sendToVehicleHC
// Server-side (V28). Explicit Zeus request to move a placed vehicle group onto
// the vehicle HC. Bypasses "Blacklist All Vehicles" (the Zeus asked for it) but
// never bypasses the safety check: the vehicle must be stationary, on the
// ground, and fully crewed by this group. Otherwise the Zeus is told why and
// the group stays where it is.
//
// Arguments:
//   0: GROUP
//   1: NUMBER - Zeus client owner ID
// Returns: BOOL

if (!isServer) exitWith { false };
params ["_group", ["_zeusId", -1]];

private _say = {
    params ["_msg"];
    if (_zeusId > 2) then { _msg remoteExec ["systemChat", _zeusId]; };
};

if (isNull _group || {count units _group == 0}) exitWith { ["[FST] Send to vehicle HC: empty group."] call _say; false };
if (isPlayer leader _group) exitWith { ["[FST] Send to vehicle HC: player group skipped."] call _say; false };
if ((_group getVariable ["FST_HC_heldBy", -1]) != -1) exitWith { ["[FST] Send to vehicle HC: release the Zeus hold first."] call _say; false };

private _targetId = ["vehicle"] call FST_HCSpawn_fnc_getSpawnTarget;
if (_targetId == 2) exitWith { ["[FST] Send to vehicle HC: no HC available."] call _say; false };
if (groupOwner _group == _targetId) exitWith {
    private _idx = FST_HC_Ids find _targetId;
    [_group, _idx, false] call FST_HCSpawn_fnc_trackGroup;
    [format ["[FST] %1 is already on HC%2.", _group, _idx + 1]] call _say;
    true
};

private _check = [_group] call FST_HCSpawn_fnc_isVehicleTransferSafe;
_check params ["_safe", "_reason"];
if (!_safe) exitWith {
    [format ["[FST] %1 not moved: %2. Stop it, land it, or wait for the crew to settle, then try again.", _group, _reason]] call _say;
    false
};

_group setVariable ["FST_HC_managed", true, true];
FST_HC_TransferQueue = FST_HC_TransferQueue - [_group];
_group setVariable ["FST_HC_pendingTransfer", nil];

private _ok = [_group, true] call FST_HCSpawn_fnc_transferGroup;
private _idx = FST_HC_Ids find _targetId;
if (_ok) then {
    [format ["[FST] %1 sent to vehicle HC (HC%2).", _group, _idx + 1]] call _say;
} else {
    [format ["[FST] %1: transfer to HC%2 refused by the engine, left in place.", _group, _idx + 1]] call _say;
};
_ok
