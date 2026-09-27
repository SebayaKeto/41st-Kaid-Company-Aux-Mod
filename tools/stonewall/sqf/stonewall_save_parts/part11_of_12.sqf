localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "} forEach _objs;
[format [""E|objects=%1|in_areas=%2|areas=%3|skipped=%4|no_class=%5|attached_or_crewed=%6|seconds=%7"", _n, _nArea,
count _areas, _skipped, _noClass, _attached, (diag_tickTime - _t0) toFixed 1], true] call _emit;
private _msg = format [""Stonewall %1: saved %2 objects, %3 inside %4 keep areas. Data is in the server RPT and your RPT."",
_sid, _n, _nArea, count _areas];
if !(_owners isEqualTo []) then {
private _chunks = [];
for ""_i"" from 0 to (count _toCallers - 1) step 50 do { _chunks pushBack (_toCallers select [_i, 50]); };
{
private _owner = _x;
if (_cba) then {
{ [""FST_stonewall_log"", [_x], _owner] call CBA_fnc_ownerEvent; sleep 0.05; } forEach _chunks;
[""FST_stonewall_done"", [_msg], _owner] call CBA_fnc_ownerEvent;
} else {
{ [_x] remoteExec [""diag_log"", _owner]; if (_forEachIndex % 50 == 49) then { sleep 0.05; }; } forEach _toCallers;
"];
