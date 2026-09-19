// =============================================================================
//  ARCHIVED — crosshair.sqf v1 (static screen-centre reticle)
//  Replaced by crosshair.sqf v2 which uses weaponDirection + worldToScreen
//  to dynamically track actual weapon aim rather than sitting at a fixed
//  screen-centre position.
//
//  To restore: copy this file's content over crosshair.sqf.
// =============================================================================

// =============================================================================
//  BUZZ AT-RT — crosshair.sqf
//  Star Wars corner-bracket targeting reticle at screen centre.
//  For a man-class unit the weapon converges to the aim point = screen centre,
//  so static screen-centre is exactly where bullets land — and it correctly
//  tracks terrain because screen centre is always on whatever you look at.
//  Works during alt-look.  Toggled by BUZZ_crosshairOn (Toggle Crosshair).
//  _this = [_atrt, _rider]
// =============================================================================
disableSerialization;
params ["_atrt", "_rider"];

sleep 0.5;
if (!(player isEqualTo _rider)) exitWith {};

private _disp = findDisplay 46;
if (isNull _disp) exitWith {};

private _col = [0.35, 0.85, 1.00, 0.92]; // Republic cyan-blue
private _off = [-1, -1, 0.001, 0.001];   // off-screen hiding position

// ── Geometry ──────────────────────────────────────────────────────────────────
// Layout:
//   ─┐   ┌─
//     │   │
//         ·
//     │   │
//   ─┘   └─
//
// _cg   = gap from screen centre to the inner corner of each bracket
// _armH = horizontal arm length (extends outward from corner)
// _armV = vertical arm length (extends inward toward dot from corner)
// V bars overlap H bars by _thkH*0.5 at the join so the corner looks flush.

private _cg   = safeZoneW * 0.007;
private _armH = safeZoneW * 0.009;
private _armV = safeZoneH * 0.011;
private _thkH = safeZoneH * 0.003;
private _thkV = safeZoneW * 0.002;
private _dotW = safeZoneW * 0.0022;
private _dotH = safeZoneH * 0.003;

private _cx = safeZoneX + safeZoneW * 0.5;
private _cy = safeZoneY + safeZoneH * 0.5;

// Top-Left  ─┐
private _posHTL = [_cx - _cg - _armH,       _cy - _cg - _thkH * 0.5, _armH, _thkH];
private _posVTL = [_cx - _cg - _thkV * 0.5, _cy - _cg - _thkH * 0.5, _thkV, _armV + _thkH * 0.5];
// Top-Right  ┌─
private _posHTR = [_cx + _cg,                _cy - _cg - _thkH * 0.5, _armH, _thkH];
private _posVTR = [_cx + _cg - _thkV * 0.5, _cy - _cg - _thkH * 0.5, _thkV, _armV + _thkH * 0.5];
// Bottom-Left  ─┘
private _posHBL = [_cx - _cg - _armH,       _cy + _cg - _thkH * 0.5, _armH, _thkH];
private _posVBL = [_cx - _cg - _thkV * 0.5, _cy + _cg - _armV,       _thkV, _armV + _thkH * 0.5];
// Bottom-Right  └─
private _posHBR = [_cx + _cg,                _cy + _cg - _thkH * 0.5, _armH, _thkH];
private _posVBR = [_cx + _cg - _thkV * 0.5, _cy + _cg - _armV,       _thkV, _armV + _thkH * 0.5];
// Centre dot
private _posDot = [_cx - _dotW * 0.5,        _cy - _dotH * 0.5,       _dotW, _dotH];

// ── Controls ──────────────────────────────────────────────────────────────────
private _hTL = _disp ctrlCreate ["RscText", -1];
private _vTL = _disp ctrlCreate ["RscText", -1];
private _hTR = _disp ctrlCreate ["RscText", -1];
private _vTR = _disp ctrlCreate ["RscText", -1];
private _hBL = _disp ctrlCreate ["RscText", -1];
private _vBL = _disp ctrlCreate ["RscText", -1];
private _hBR = _disp ctrlCreate ["RscText", -1];
private _vBR = _disp ctrlCreate ["RscText", -1];
private _dot = _disp ctrlCreate ["RscText", -1];

private _all = [_hTL, _vTL, _hTR, _vTR, _hBL, _vBL, _hBR, _vBR, _dot];

// Set colour (queued), then commit each control at its target position so the
// colour and position are applied together.  Then move everything off-screen.
{ _x ctrlSetText ""; _x ctrlSetBackgroundColor _col } forEach _all;

_hTL ctrlSetPosition _posHTL; _hTL ctrlCommit 0;
_vTL ctrlSetPosition _posVTL; _vTL ctrlCommit 0;
_hTR ctrlSetPosition _posHTR; _hTR ctrlCommit 0;
_vTR ctrlSetPosition _posVTR; _vTR ctrlCommit 0;
_hBL ctrlSetPosition _posHBL; _hBL ctrlCommit 0;
_vBL ctrlSetPosition _posVBL; _vBL ctrlCommit 0;
_hBR ctrlSetPosition _posHBR; _hBR ctrlCommit 0;
_vBR ctrlSetPosition _posVBR; _vBR ctrlCommit 0;
_dot ctrlSetPosition _posDot; _dot ctrlCommit 0;

{ _x ctrlSetPosition _off; _x ctrlCommit 0 } forEach _all;

// ── Loop ──────────────────────────────────────────────────────────────────────
private _visible = false;

while { player isEqualTo (_atrt getVariable ["rider", objNull]) && alive _atrt } do {
    private _on = (_atrt getVariable ["BUZZ_crosshairOn", false]);
    if (_on != _visible) then {
        _visible = _on;
        if (_on) then {
            _hTL ctrlSetPosition _posHTL; _hTL ctrlCommit 0;
            _vTL ctrlSetPosition _posVTL; _vTL ctrlCommit 0;
            _hTR ctrlSetPosition _posHTR; _hTR ctrlCommit 0;
            _vTR ctrlSetPosition _posVTR; _vTR ctrlCommit 0;
            _hBL ctrlSetPosition _posHBL; _hBL ctrlCommit 0;
            _vBL ctrlSetPosition _posVBL; _vBL ctrlCommit 0;
            _hBR ctrlSetPosition _posHBR; _hBR ctrlCommit 0;
            _vBR ctrlSetPosition _posVBR; _vBR ctrlCommit 0;
            _dot ctrlSetPosition _posDot; _dot ctrlCommit 0;
        } else {
            { _x ctrlSetPosition _off; _x ctrlCommit 0 } forEach _all;
        };
    };
    sleep 0.05;
};

// ── Cleanup ────────────────────────────────────────────────────────────────────
{ ctrlDelete _x } forEach _all;
_atrt setVariable ["BUZZ_crosshairOn", false];
