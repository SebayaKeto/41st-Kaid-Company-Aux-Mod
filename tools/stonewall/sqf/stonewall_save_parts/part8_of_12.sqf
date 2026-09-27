localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "if (_t select [0, 1] == ""#"") exitWith { _skipped = _skipped + 1; };
if !(isClass (configFile >> ""CfgVehicles"" >> _t)) exitWith { _skipped = _skipped + 1; };
if (_skipKinds findIf { _o isKindOf _x } >= 0) exitWith { _skipped = _skipped + 1; };
if (getNumber (configFile >> ""CfgVehicles"" >> _t >> ""scope"") < 1) exitWith { _skipped = _skipped + 1; };
if (!isNull attachedTo _o || {!isNull ropeAttachedTo _o} || {!(crew _o isEqualTo [])}) exitWith { _attached = _attached + 1; };
private _pos = getPosWorld _o;
private _in = [];
{
_x params ["""", """", ""_shape"", ""_x0"", ""_y0"", ""_a"", ""_b"", ""_dir""];
if (_pos inArea [[_x0, _y0], _a + _margin, _b + _margin, _dir, _shape == ""RECTANGLE""]) then { _in pushBack _forEachIndex; };
} forEach _areas;
if (_scope == ""areas"" && {_in isEqualTo []}) exitWith {};
private _src = ""unknown"";
call {
"];
