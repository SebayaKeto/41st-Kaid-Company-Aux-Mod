// FST_HCSpawn_fnc_handleDisconnect
// Server-side. HandleDisconnect mission EH.

if (!isServer) exitWith {};

params ["_unit", "_id", "_uid", "_name"];

// ============================================================
// HC DISCONNECT
// ============================================================
private _hcIdx = FST_HC_Array find _unit;
if (_hcIdx == -1) then { _hcIdx = FST_HC_Ids find _id; };
if (_hcIdx != -1) exitWith {
    diag_log format ["[FST_HCSpawn] HC disconnected: %1 (%2)", _name, _unit];

    // Single pass: collect orphans (groups on the disconnecting HC) and
    // reindex remaining groups (decrement hcIndex for groups above the removed
    // HC). Two passes used to be visible at scale during the unscheduled
    // HandleDisconnect -- the longer this blocks, the more chance of cascading
    // desync on already-shaky connections.
    if (isNil "FST_HC_TrackedGroups") then { FST_HC_TrackedGroups = []; };
    private _orphanedGroups = [];
    {
        private _data = _x getVariable ["FST_HC_tracked", []];
        if (count _data == 0) then { continue };

        private _oldIdx = _data select 0;
        if (_oldIdx == _hcIdx) then {
            _orphanedGroups pushBack _x;
            _x setVariable ["FST_HC_tracked", nil];
            _x setVariable ["FST_HC_onHC", nil];
        } else {
            if (_oldIdx > _hcIdx) then {
                _x setVariable ["FST_HC_tracked", [_oldIdx - 1, _data select 1]];
                _x setVariable ["FST_HC_onHC", _oldIdx - 1];
            };
        };
    } forEach +FST_HC_TrackedGroups;

    // Remove HC from tracking
    FST_HC_Array deleteAt _hcIdx;
    FST_HC_Ids deleteAt _hcIdx;
    FST_HC_UnitCounts deleteAt _hcIdx;
    FST_HC_TrackedGroups = FST_HC_TrackedGroups - _orphanedGroups;

    publicVariable "FST_HC_Array";
    publicVariable "FST_HC_Ids";

    // V27: safe mode is its own deadline instead of borrowing FST_HC_EmergencyMode.
    // emergencyRedistribute clears EmergencyMode when it finishes, which used to
    // end the safe-mode window early; a stacked disconnect simply extends this.
    private _safeModeSeconds = missionNamespace getVariable ["FST_HC_HCDisconnectSafeModeSeconds", 120];
    if (_safeModeSeconds > 0) then {
        FST_HC_SafeModeUntil = (missionNamespace getVariable ["FST_HC_SafeModeUntil", -1]) max (time + _safeModeSeconds);
        missionNamespace setVariable ["FST_HC_LastHCDisconnectTime", time];
        diag_log format ["[FST_HCSpawn] HC disconnect safe mode active for %1s; transfers/catch-all paused.", _safeModeSeconds];
    };

    private _redistribute = missionNamespace getVariable ["FST_HC_RedistributeOnHCDisconnect", false];
    if ((count _orphanedGroups > 0) && {_redistribute}) then {
        [_orphanedGroups] spawn FST_HCSpawn_fnc_emergencyRedistribute;
    } else {
        if (count _orphanedGroups > 0) then {
            diag_log format ["[FST_HCSpawn] HC disconnected: emergency redistribution disabled. Cleared tracking for %1 orphaned groups; leaving engine/server to settle locality.", count _orphanedGroups];
            ["HC disconnected. Emergency redistribution disabled; AI locality settling on server."] remoteExec ["hint", -2];
            [] call FST_HCSpawn_fnc_recountUnits;
        };
    };
};

// ============================================================
// ZEUS DISCONNECT -- release held groups
// ============================================================
// V27: uses the server-side held-group cache instead of scanning allGroups on
// every player disconnect (150 players leaving at op end = 150 full scans).
if (isNil "FST_HC_HeldGroups") then { FST_HC_HeldGroups = []; };
if (count FST_HC_HeldGroups == 0) exitWith {};

FST_HC_HeldGroups = FST_HC_HeldGroups select { !isNull _x };
private _zeusGroups = FST_HC_HeldGroups select { (_x getVariable ["FST_HC_heldBy", -1]) == _id };

if (count _zeusGroups > 0) then {
    diag_log format ["[FST_HCSpawn] Zeus disconnected: %1, releasing %2 held groups", _name, count _zeusGroups];
    {
        _x setVariable ["FST_HC_heldBy", -1, true];
        _x setVariable ["FST_HC_pendingTransfer", true];
        FST_HC_TransferQueue pushBackUnique _x;
    } forEach _zeusGroups;
    FST_HC_HeldGroups = FST_HC_HeldGroups - _zeusGroups;
};
