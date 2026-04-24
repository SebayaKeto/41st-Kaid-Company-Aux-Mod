// FST_HCSpawn_fnc_statusReport
// Server-side. Generates a status report and sends it to the requesting client.
// Can be called via remoteExec or directly on server.
//
// Arguments:
//   0: NUMBER — client ID to send report to (-2 for all)

params [["_target", -2]];

if (!isServer) exitWith {
    // Client requesting — ask server
    [clientOwner] remoteExecCall ["FST_HCSpawn_fnc_statusReport", 2];
};

// Build report
private _lines = ["[FST HC Status]"];

if (count FST_HC_Array == 0) then {
    _lines pushBack "  No HCs connected — AI on server";
} else {
    {
        private _hcId = FST_HC_Ids select _forEachIndex;
        private _units = FST_HC_UnitCounts select _forEachIndex;

        // Count groups on this HC
        private _grpCount = 0;
        { if ((_y select 0) == _forEachIndex) then { _grpCount = _grpCount + 1; }; } forEach FST_HC_GroupMap;

        _lines pushBack format ["  HC%1 (owner %2): %3 units, %4 groups", _forEachIndex + 1, _hcId, _units, _grpCount];
    } forEach FST_HC_Array;
};

// Zeus held count
private _zeusCount = count FST_HC_ZeusHeld;
if (_zeusCount > 0) then {
    _lines pushBack format ["  Zeus held: %1 groups", _zeusCount];
};

// Transfer queue
if (count FST_HC_TransferQueue > 0) then {
    _lines pushBack format ["  Transfer queue: %1 pending", count FST_HC_TransferQueue];
};

// Total tracked
_lines pushBack format ["  Total tracked: %1 groups", count FST_HC_GroupMap];

// Send each line
{
    _x remoteExec ["systemChat", _target];
} forEach _lines;
