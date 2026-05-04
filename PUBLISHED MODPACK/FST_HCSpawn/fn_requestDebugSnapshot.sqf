// FST_HCSpawn_fnc_requestDebugSnapshot
// Server-side. Builds a server-confirmed ownership snapshot for the client debug draw.
// This avoids clients guessing locality with owner/groupOwner locally.
// Arguments:
//   0: NUMBER - target client owner ID

if (!isServer) exitWith {};

params [["_target", -2]];

private _snapshot = [];
private _hcIds = +(missionNamespace getVariable ["FST_HC_Ids", []]);

{
    private _grp = _x;
    if (isNull _grp) then { continue };
    if (count units _grp == 0) then { continue };
    if (isPlayer leader _grp) then { continue };

    private _ownerID = groupOwner _grp;
    private _hcIndex = _hcIds find _ownerID;
    private _heldBy = _grp getVariable ["FST_HC_heldBy", -1];
    private _pending = _grp getVariable ["FST_HC_pendingTransfer", false];
    private _tracked = count (_grp getVariable ["FST_HC_tracked", []]) > 0;

    private _state = "server";
    private _label = "Server";

    if (_hcIndex >= 0) then {
        _state = "hc";
        _label = format ["HC%1", _hcIndex + 1];
    };
    if (_pending) then {
        _state = "pending";
        _label = "Pending HC";
    };
    if (_heldBy != -1) then {
        _state = "zeus";
        _label = format ["Zeus %1", _heldBy];
    };

    _snapshot pushBack [_grp, _label, _state, _ownerID, count units _grp, _tracked, _pending, _heldBy];
} forEach allGroups;

[
    "FST_HC_evt_debugSnapshot",
    [
        _snapshot,
        diag_tickTime,
        +_hcIds,
        +(missionNamespace getVariable ["FST_HC_UnitCounts", []]),
        count (missionNamespace getVariable ["FST_HC_TransferQueue", []]),
        missionNamespace getVariable ["FST_HC_TransferSuccesses", 0],
        missionNamespace getVariable ["FST_HC_TransferFailures", 0],
        missionNamespace getVariable ["FST_HC_ZeusInstantCloneRequests", 0],
        missionNamespace getVariable ["FST_HC_ZeusImmediateFallbacks", 0],
        missionNamespace getVariable ["FST_HC_ZeusLegacyFallbacksUsed", 0]
    ],
    _target
] call CBA_fnc_ownerEvent;
