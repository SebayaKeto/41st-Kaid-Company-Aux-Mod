// =============================================================================
//  ARCHIVED — crosshair.sqf v2 (weaponDirection + worldToScreen dynamic tracking)
// =============================================================================

disableSerialization;
params ["_atrt", "_rider"];

sleep 0.5;
if (!(player isEqualTo _rider)) exitWith {};

private _disp = findDisplay 46;
if (isNull _disp) exitWith {};

private _col = [0.35, 0.85, 1.00, 0.92]; // Republic cyan-blue

private _cg   = safeZoneW * 0.007;
private _armH = safeZoneW * 0.009;
private _armV = safeZoneH * 0.011;
private _thkH = safeZoneH * 0.003;
private _thkV = safeZoneW * 0.002;
private _dotW = safeZoneW * 0.0022;
private _dotH = safeZoneH * 0.003;

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

{ _x ctrlSetText ""; _x ctrlSetBackgroundColor _col } forEach _all;

private _fnDraw = {
    params ["_cx", "_cy"];
    _hTL ctrlSetPosition [_cx - _cg - _armH,       _cy - _cg - _thkH * 0.5, _armH, _thkH];
    _vTL ctrlSetPosition [_cx - _cg - _thkV * 0.5, _cy - _cg - _thkH * 0.5, _thkV, _armV + _thkH * 0.5];
    _hTR ctrlSetPosition [_cx + _cg,                _cy - _cg - _thkH * 0.5, _armH, _thkH];
    _vTR ctrlSetPosition [_cx + _cg - _thkV * 0.5, _cy - _cg - _thkH * 0.5, _thkV, _armV + _thkH * 0.5];
    _hBL ctrlSetPosition [_cx - _cg - _armH,       _cy + _cg - _thkH * 0.5, _armH, _thkH];
    _vBL ctrlSetPosition [_cx - _cg - _thkV * 0.5, _cy + _cg - _armV,       _thkV, _armV + _thkH * 0.5];
    _hBR ctrlSetPosition [_cx + _cg,                _cy + _cg - _thkH * 0.5, _armH, _thkH];
    _vBR ctrlSetPosition [_cx + _cg - _thkV * 0.5, _cy + _cg - _armV,       _thkV, _armV + _thkH * 0.5];
    _dot ctrlSetPosition [_cx - _dotW * 0.5,        _cy - _dotH * 0.5,       _dotW, _dotH];
    { _x ctrlCommit 0 } forEach _all;
};

[safeZoneX + safeZoneW * 0.5, safeZoneY + safeZoneH * 0.5] call _fnDraw;

while { player isEqualTo (_atrt getVariable ["rider", objNull]) && alive _atrt } do {
    private _cx = safeZoneX + safeZoneW * 0.5;
    private _cy = safeZoneY + safeZoneH * 0.5;
    private _wpn = currentWeapon _atrt;
    if (_wpn != "") then {
        private _sp = worldToScreen (eyePos _atrt vectorAdd ((_atrt weaponDirection _wpn) vectorMultiply 1000));
        if (count _sp == 2) then {
            _cx = safeZoneX + (_sp select 0) * safeZoneW;
            _cy = safeZoneY + (_sp select 1) * safeZoneH;
        };
    };
    [_cx, _cy] call _fnDraw;
    sleep 0.05;
};

{ ctrlDelete _x } forEach _all;
_atrt setVariable ["BUZZ_crosshairOn", false];
