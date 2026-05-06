// FST_HCSpawn_fnc_fpsMonitor
// Runs on the local machine (server or HC).
// Creates a map marker showing FPS and local unit count.
// Color-coded: green (30+), yellow (20-30), orange (10-20), red (<10).
//
// Arguments:
//   0: STRING  — label (e.g. "Server", "HC1")
//   1: NUMBER  — refresh interval seconds (default 10)
//   2: NUMBER  — vertical position index (0 = bottom, 1 = above, etc.)

params ["_label", ["_interval", 10], ["_posIndex", 0]];

private _spacing = worldSize * 0.016;
private _markerName = format ["FST_fps_%1", _label];

// Clean up old marker if exists
deleteMarker _markerName;

private _marker = createMarker [_markerName, [worldSize - _spacing, _spacing + (_spacing * _posIndex)]];
_marker setMarkerType "mil_start";
_marker setMarkerSize [0.7, 0.7];

[{
    params ["_args"];
    _args params ["_marker", "_label"];

    private _fps = diag_fps;
    private _localUnits = { local _x } count allUnits;

    private _color = "ColorGREEN";
    if (_fps < 30) then { _color = "ColorYELLOW"; };
    if (_fps < 20) then { _color = "ColorORANGE"; };
    if (_fps < 10) then { _color = "ColorRED"; };

    _marker setMarkerColor _color;
    _marker setMarkerText format ["%1: %2 fps | %3 local AI", _label, round (_fps * 10) / 10, _localUnits];

}, _interval, [_marker, _label]] call CBA_fnc_addPerFrameHandler;

diag_log format ["[FST_HCSpawn] FPS monitor started: %1 (interval %2s)", _label, _interval];
