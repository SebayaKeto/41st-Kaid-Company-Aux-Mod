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
    // HandleDisconnect — the longer this blocks, the more chance of cascading
    // desync on already-shaky connections.
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
    } forEach allGroups;

    // Remove HC from tracking
    FST_HC_Array deleteAt _hcIdx;
    FST_HC_Ids deleteAt _hcIdx;
    FST_HC_UnitCounts deleteAt _hcIdx;

    publicVariable "FST_HC_Array";
    publicVariable "FST_HC_Ids";

    if (count _orphanedGroups > 0) then {
        [_orphanedGroups] spawn FST_HCSpawn_fnc_emergencyRedistribute;
    };
};

// ============================================================
// ZEUS DISCONNECT — release held groups
// ============================================================
private _zeusGroups = [];
{
    if ((_x getVariable ["FST_HC_heldBy", -1]) == _id) then {
        _zeusGroups pushBack _x;
    };
} forEach allGroups;

if (count _zeusGroups > 0) then {
    diag_log format ["[FST_HCSpawn] Zeus disconnected: %1, releasing %2 held groups", _name, count _zeusGroups];
    {
        _x setVariable ["FST_HC_heldBy", -1, true];
        FST_HC_TransferQueue pushBackUnique _x;
    } forEach _zeusGroups;
};
