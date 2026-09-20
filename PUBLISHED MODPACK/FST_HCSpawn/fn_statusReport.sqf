// FST_HCSpawn_fnc_statusReport
// Server-side. Generates a practical HC status report.
// If called from a client, it requests the server copy.

params [["_target", -2]];

if (!isServer) exitWith {
    ["FST_HC_evt_statusReport", [clientOwner]] call CBA_fnc_serverEvent;
};

// Refresh bookkeeping before reporting so Zeus-transfer counts are not stale.
[] call FST_HCSpawn_fnc_recountUnits;

private _lines = ["[FST HC Status]"];

private _serverOwnedAI = 0;
private _hcOwnedAI = 0;
private _serverOwnedGroups = 0;
private _hcOwnedGroups = 0;
private _heldCount = 0;
private _pendingGroups = [];
{ if (!isNull _x) then { _pendingGroups pushBackUnique _x; }; } forEach FST_HC_TransferQueue;
private _untrackedEligible = 0;

private _hcCount = count FST_HC_Array;
private _grpCounts = [];
_grpCounts resize _hcCount;
{ _grpCounts set [_forEachIndex, 0]; } forEach _grpCounts;

// V27: single allGroups pass (was two).
{
    private _grp = _x;
    if (isNull _grp || {count units _grp == 0} || {isPlayer leader _grp}) then { continue };

    private _unitCount = count units _grp;
    if ((_grp getVariable ["FST_HC_heldBy", -1]) != -1) then { _heldCount = _heldCount + 1; };
    if (_grp getVariable ["FST_HC_pendingTransfer", false]) then { _pendingGroups pushBackUnique _grp; };

    private _ownerID = groupOwner _grp;
    private _idx = FST_HC_Ids find _ownerID;
    if (_idx >= 0) then {
        _hcOwnedGroups = _hcOwnedGroups + 1;
        _hcOwnedAI = _hcOwnedAI + _unitCount;
        if (_idx < _hcCount) then { _grpCounts set [_idx, (_grpCounts select _idx) + 1]; };
    } else {
        _serverOwnedGroups = _serverOwnedGroups + 1;
        _serverOwnedAI = _serverOwnedAI + _unitCount;
        if (count (_grp getVariable ["FST_HC_tracked", []]) == 0 && {!([_grp] call FST_HCSpawn_fnc_isBlacklisted)}) then {
            _untrackedEligible = _untrackedEligible + 1;
        };
    };
} forEach allGroups;

if (_hcCount == 0) then {
    _lines pushBack "  No HCs connected -- AI will remain on server.";
} else {
    {
        private _hcId = FST_HC_Ids select _forEachIndex;
        private _units = FST_HC_UnitCounts select _forEachIndex;
        private _grps = _grpCounts select _forEachIndex;
        _lines pushBack format ["  HC%1 (owner %2): %3 AI, %4 groups", _forEachIndex + 1, _hcId, _units, _grps];
    } forEach FST_HC_Array;
};

private _safeModeLeft = ((missionNamespace getVariable ["FST_HC_SafeModeUntil", -1]) - time) max 0;

_lines pushBack format ["  HC-owned AI/groups: %1 AI, %2 groups", _hcOwnedAI, _hcOwnedGroups];
_lines pushBack format ["  Server-owned AI/groups: %1 AI, %2 groups", _serverOwnedAI, _serverOwnedGroups];
_lines pushBack format ["  Transfer queue/pending: %1", count _pendingGroups];
_lines pushBack format ["  Zeus held: %1 groups", _heldCount];
_lines pushBack format ["  Untracked eligible server groups: %1", _untrackedEligible];
_lines pushBack format ["  Total tracked: %1 groups", FST_HC_TrackedCount];
_lines pushBack format ["  Zeus mode: %1", missionNamespace getVariable ["FST_HC_ZeusMode", "instant"]];
private _vehHC = [] call FST_HCSpawn_fnc_getVehicleHC;
_lines pushBack (if ((_vehHC select 1) >= 0) then { format ["  Vehicle HC: HC%1 (owner %2)", (_vehHC select 1) + 1, _vehHC select 0] } else { "  Vehicle HC: none (vehicles use least-loaded HC)" });
if (_safeModeLeft > 0 || {FST_HC_EmergencyMode}) then {
    _lines pushBack format ["  Transfers paused: safeMode=%1s redistribute=%2", ceil _safeModeLeft, FST_HC_EmergencyMode];
};
_lines pushBack format ["  Transfers OK/Fail: %1 / %2", missionNamespace getVariable ["FST_HC_TransferSuccesses", 0], missionNamespace getVariable ["FST_HC_TransferFailures", 0]];
_lines pushBack format ["  Zeus instant clones: %1", missionNamespace getVariable ["FST_HC_ZeusInstantCloneRequests", 0]];
_lines pushBack format ["  Zeus setGroupOwner immediate/fallback: %1 / %2", missionNamespace getVariable ["FST_HC_ZeusImmediateRequests", 0], missionNamespace getVariable ["FST_HC_ZeusImmediateFallbacks", 0]];
_lines pushBack format ["  Legacy clone fallbacks used: %1", missionNamespace getVariable ["FST_HC_ZeusLegacyFallbacksUsed", 0]];

{ _x remoteExec ["systemChat", _target]; } forEach _lines;
