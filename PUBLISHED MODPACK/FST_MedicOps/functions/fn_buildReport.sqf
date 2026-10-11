// FST_medOps_fnc_buildReport
// Server. Returns [lines <ARRAY of STRING>, medic of the op name or ""]. Score = patients x2 + revives x3 + bacta x2
// + under-fire treatments + bacta mists + treatments / 4 (patients and revives count most: lives back in the fight).

if (isNil "FST_medOps_stats") then { FST_medOps_stats = createHashMap; };
private _rows = [];
{
    _y params ["_name", "_treat", "_patients", "_bacta", "_bandage", "_revive", "_fire", ["_mist", 0]];
    private _score = 2 * count _patients + 3 * _revive + 2 * _bacta + _fire + _mist + _treat / 4;
    _rows pushBack [_score, _name, count _patients, _treat, _bacta, _bandage, _revive, _fire, _mist];
} forEach FST_medOps_stats;
_rows = [_rows, [], { _x select 0 }, "DESCEND"] call BIS_fnc_sortBy;
private _lines = _rows apply {
    _x params ["", "_name", "_pat", "_treat", "_bacta", "_band", "_rev", "_fire", "_mist"];
    format ["%1: %2 patients, %3 revives, %4 bacta heals, %5 bandages, %6 treatments under fire, %7 bacta mists (%8 treatments)",
        _name, _pat, _rev, _bacta, _band, _fire, _mist, _treat]
};
[_lines, if (_rows isEqualTo []) then { "" } else { (_rows select 0) select 1 }]
