// FST_HCSpawn_fnc_statusReport
// Server-side. Generates a status report.

params [["_target", -2]];

if (!isServer) exitWith {
    ["FST_HC_evt_statusReport", [clientOwner]] call CBA_fnc_serverEvent;
};

private _lines = ["[FST HC Status]"];

if (count FST_HC_Array == 0) then {
    _lines pushBack "  No HCs connected — AI on server";
} else {
    // Count groups per HC
    private _grpCounts = [];
    _grpCounts resize (count FST_HC_Array);
    { _grpCounts set [_forEachIndex, 0]; } forEach _grpCounts;

    private _heldCount = 0;

    {
        private _data = _x getVariable ["FST_HC_tracked", []];
        if (count _data > 0) then {
            private _idx = _data select 0;
            if (_idx >= 0 && _idx < count _grpCounts) then {
                _grpCounts set [_idx, (_grpCounts select _idx) + 1];
            };
        };
        if ((_x getVariable ["FST_HC_heldBy", -1]) != -1) then {
            _heldCount = _heldCount + 1;
        };
    } forEach allGroups;

    {
        private _hcId = FST_HC_Ids select _forEachIndex;
        private _units = FST_HC_UnitCounts select _forEachIndex;
        private _grps = _grpCounts select _forEachIndex;
        _lines pushBack format ["  HC%1 (owner %2): %3 units, %4 groups", _forEachIndex + 1, _hcId, _units, _grps];
    } forEach FST_HC_Array;

    if (_heldCount > 0) then {
        _lines pushBack format ["  Zeus held: %1 groups", _heldCount];
    };
};

if (count FST_HC_TransferQueue > 0) then {
    _lines pushBack format ["  Transfer queue: %1 pending", count FST_HC_TransferQueue];
};

_lines pushBack format ["  Total tracked: %1 groups", FST_HC_TrackedCount];

{ _x remoteExec ["systemChat", _target]; } forEach _lines;
