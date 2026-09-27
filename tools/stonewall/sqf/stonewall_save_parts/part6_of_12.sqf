localNamespace setVariable ["stonewall_code", (localNamespace getVariable ["stonewall_code", ""]) + "private _words = _text splitString "" "";
private _r = if (count _words > 1) then { parseNumber (_words select 1) } else { 0 };
if (_kind == """" && {count _words > 1} && {toUpper (_words select 0) == ""KEEP""} && {_r > 0}) then { _kind = ""text""; };
if (_kind != """") then {
private _shape = markerShape _m;
private _size = markerSize _m;
if !(_shape in [""RECTANGLE"", ""ELLIPSE""]) then {
if (_r <= 0) then { _r = 50; };
_size = [_r, _r];
_shape = ""ELLIPSE"";
};
private _p = markerPos _m;
_areas pushBack [_m, _kind, _shape, _p#0, _p#1, _size#0, _size#1, markerDir _m, _text];
};
} forEach allMapMarkers;
{
_x params [""_m"", ""_kind"", ""_shape"", ""_x0"", ""_y0"", ""_a"", ""_b"", ""_dir"", ""_text""];
[format [""A|%1|%2|%3|%4|%5|%6|%7|%8|%9|%10"", _forEachIndex, _m call _clean, _kind, _shape,
_x0 toFixed 2, _y0 toFixed 2, _a toFixed 2, _b toFixed 2, _dir toFixed 2, _text call _clean], true] call _emit;
} forEach _areas;
"];
