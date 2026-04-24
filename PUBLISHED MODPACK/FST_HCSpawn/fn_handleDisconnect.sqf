// FST_HCSpawn_fnc_handleDisconnect
// Server-side. HandleDisconnect mission EH handler.
// Detects if disconnecting entity is an HC or Zeus and handles accordingly.
//
// Arguments: (from HandleDisconnect EH)
//   0: OBJECT — unit
//   1: NUMBER — client ID
//   2: STRING — UID
//   3: STRING — name

if (!isServer) exitWith {};

params ["_unit", "_id", "_uid", "_name"];

// ============================================================
// HC DISCONNECT
// ============================================================
private _hcIdx = FST_HC_Array find _unit;
if (_hcIdx != -1) exitWith {
    diag_log format ["[FST_HCSpawn] HC disconnected: %1 (%2)", _name, _unit];

    // Collect all groups owned by this HC
    private _orphanedGroups = [];
    {
        private _data = _y; // [hcIndex, unitCount]
        if ((_data select 0) == _hcIdx) then {
            _orphanedGroups pushBack _x;
        };
    } forEach FST_HC_GroupMap;

    // Remove HC from tracking
    FST_HC_Array deleteAt _hcIdx;
    FST_HC_Ids deleteAt _hcIdx;
    FST_HC_UnitCounts deleteAt _hcIdx;

    // Reindex remaining groups — any group with hcIndex > _hcIdx needs decrementing
    {
        private _data = _y;
        private _oldIdx = _data select 0;
        if (_oldIdx > _hcIdx) then {
            FST_HC_GroupMap set [_x, [_oldIdx - 1, _data select 1]];
        };
    } forEach FST_HC_GroupMap;

    // Remove orphaned groups from tracking (they'll be re-registered after redistribution)
    { FST_HC_GroupMap deleteAt _x; } forEach _orphanedGroups;

    publicVariable "FST_HC_Array";
    publicVariable "FST_HC_Ids";

    // Redistribute orphaned groups
    if (count _orphanedGroups > 0) then {
        [_orphanedGroups] spawn FST_HCSpawn_fnc_emergencyRedistribute;
    };
};

// ============================================================
// ZEUS DISCONNECT — release held groups back to transfer queue
// ============================================================
private _zeusGroups = [];
{
    if (_y == _id) then {
        _zeusGroups pushBack _x;
    };
} forEach FST_HC_ZeusHeld;

if (count _zeusGroups > 0) then {
    diag_log format ["[FST_HCSpawn] Zeus disconnected: %1, releasing %2 held groups", _name, count _zeusGroups];
    {
        FST_HC_ZeusHeld deleteAt _x;
        FST_HC_TransferQueue pushBackUnique _x;
    } forEach _zeusGroups;
};
