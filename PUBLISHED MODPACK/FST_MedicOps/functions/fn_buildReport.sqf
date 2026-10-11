// FST_medOps_fnc_buildReport
// Server. Returns [lines <ARRAY of STRING>, medic of the op name or ""]. Score = patients x2 + revives x3 + bacta x2
// + jolts x2 + transfusions x2 + under-fire treatments + bacta mists + treatments / 4 (lives back in the fight
// count most).

if (isNil "FST_medOps_stats") then { FST_medOps_stats = createHashMap; };
private _rows = [];
{
    _y params ["_name", "_treat", "_patients", "_bacta", "_bandage", "_revive", "_fire", ["_mist", 0], ["_transf", 0], ["_jolt", 0]];
    private _score = 2 * count _patients + 3 * _revive + 2 * _bacta + 2 * _jolt + 2 * _transf + _fire + _mist + _treat / 4;
    _rows pushBack [_score, _name, count _patients, _treat, _bacta, _bandage, _revive, _fire, _mist, _transf, _jolt];
} forEach FST_medOps_stats;
_rows = [_rows, [], { _x select 0 }, "DESCEND"] call BIS_fnc_sortBy;
private _lines = _rows apply {
    _x params ["", "_name", "_pat", "_treat", "_bacta", "_band", "_rev", "_fire", "_mist", "_transf", "_jolt"];
    format ["%1: %2 patients, %3 revives, %4 jolts, %5 bacta heals, %6 transfusions, %7 bandages, %8 under fire, %9 bacta mists (%10 treatments)",
        _name, _pat, _rev, _jolt, _bacta, _transf, _band, _fire, _mist, _treat]
};
[_lines, if (_rows isEqualTo []) then { "" } else { (_rows select 0) select 1 }]
