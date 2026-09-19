// =============================================================================
//  ARCHIVED — crosshair.sqf v2 (weaponDirection + worldToScreen dynamic tracking)
//  Replaced by engine cursorAim="gl" on BUZZ_ATRT_T15 (config.cpp).
//
//  Why it was abandoned:
//    eyePos _atrt sits at the rider's head (top of the walker body), offset
//    from the cannon muzzle.  Projecting 1000 m along weaponDirection from that
//    point gives a ray that parallels the bullet path but diverges from it at
//    normal combat ranges, causing the reticle to be visibly above/displaced
//    from actual impact.  Additionally, weaponDirection tracks the physically-
//    animated weapon arm which can lag the camera during fast turns, making the
//    crosshair appear to "drift" away from screen centre.
//
//  What replaced it:
//    Adding `cursorAim = "gl"` to BUZZ_ATRT_T15 in config.cpp lets the engine
//    draw a dynamic ballistic crosshair exactly as the 41st FST_ATRT_Weapon_Base_F
//    does.  The engine has accurate access to weapon muzzle position, initSpeed,
//    and coefGravity, so it positions the reticle precisely where the bolt lands.
//
//  To restore: copy this file's content over crosshair.sqf, re-add the execVM
//  call in init.sqf Saddle Up (after hud.sqf), and re-add BUZZ_crosshairOn sets
//  (on mount = true, on dismount/eject/death = false).
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
