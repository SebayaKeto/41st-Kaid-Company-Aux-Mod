// =============================================================================
//  BUZZ AT-RT — pack_hud.sqf
//  Progress overlay for AT-RT packing and unpacking operations.
//  Same layout as repair_hud.sqf. ESC cancels by clearing BUZZ_packing on the
//  subject. No partial progress — the operation either completes or is aborted.
//  _this = [subject, caller, duration, title]
//    subject  = AT-RT (repack) or crate (unpack) — carries BUZZ_packing flag
//    caller   = player performing the operation
//    duration = seconds (30 pack / 20 unpack)
//    title    = header text shown on the panel
// =============================================================================
disableSerialization;
params ["_subject", "_caller", "_duration", "_title", ["_varName", "BUZZ_packing"]];

if (!(player isEqualTo _caller)) exitWith {};

private _disp = findDisplay 46;
if (isNull _disp) exitWith {};

// ─── Colour palette (matches main HUD and repair_hud) ─────────────────────────
private _colBg      = [0.030, 0.050, 0.095, 0.920];
private _colHdrBg   = [0.055, 0.085, 0.155, 0.950];
private _colAcctBrt = [0.435, 0.740, 1.000, 1.000];
private _colHdr     = [0.920, 0.950, 1.000, 1.000];
private _colSub     = [0.430, 0.650, 0.870, 0.750];
private _colLbl     = [0.530, 0.710, 0.910, 0.850];
private _colTrk     = [0.045, 0.075, 0.130, 1.000];
private _colGreen   = [0.100, 0.850, 0.250, 1.000];
private _colNone    = [0, 0, 0, 0];

// ─── Panel anchor — centred, lower third ──────────────────────────────────────
private _pw  = safeZoneW * 0.240;
private _px  = safeZoneX + (safeZoneW - _pw) * 0.5;
private _py  = safeZoneY + safeZoneH * 0.720;
private _px2 = _px + _pw;
private _cx  = _px + safeZoneW * 0.010;
private _cw  = _pw - safeZoneW * 0.020;

// ─── Row heights ──────────────────────────────────────────────────────────────
private _hAcct = safeZoneH * 0.0025;
private _hHdr  = safeZoneH * 0.0430;
private _hDiv  = safeZoneH * 0.0012;
private _hBar  = safeZoneH * 0.0220;
private _hInfo = safeZoneH * 0.0380;
private _hHint = safeZoneH * 0.0310;

private _fHdr  = safeZoneH * 0.0200;
private _fInfo = safeZoneH * 0.0175;
private _fHint = safeZoneH * 0.0140;

// ─── Spacing ──────────────────────────────────────────────────────────────────
private _padO = safeZoneH * 0.0025;
private _padI = safeZoneH * 0.0015;

// ─── Y positions ──────────────────────────────────────────────────────────────
private _yAT   = _py;
private _yHdr  = _yAT  + _hAcct + _padO;
private _yDv1  = _yHdr + _hHdr  + _padI;
private _yBar  = _yDv1 + _hDiv  + _padI;
private _yInfo = _yBar + _hBar  + _padI;
private _yHint = _yInfo + _hInfo + _padI;
private _yAB   = _yHint + _hHint + _padO;
private _ph    = (_yAB + _hAcct) - _py;

// ─── Corner dimensions ────────────────────────────────────────────────────────
private _crnW  = safeZoneW * 0.0180;
private _crnH  = safeZoneH * 0.0170;
private _crnTH = safeZoneH * 0.0025;
private _crnTW = safeZoneW * 0.0025;

// ─── Info row column split ────────────────────────────────────────────────────
private _cPctW  = _cw * 0.45;
private _cTimeX = _cx + _cPctW;
private _cTimeW = _cw * 0.55;

// Post-update ArmA 3 clips glyph tops against the control's own top edge —
// text now renders anchored toward the bottom of its box instead of centred,
// so every text (not background/divider) control needs extra room added
// ABOVE its nominal box, with the bottom edge left where the layout put it.
private _txtPad = safeZoneH * 0.014;

// ─── Create controls ─────────────────────────────────────────────────────────
private _cBG    = _disp ctrlCreate ["RscText", -1];
private _cHdrBg = _disp ctrlCreate ["RscText", -1];
private _cAT    = _disp ctrlCreate ["RscText", -1];
private _cAB    = _disp ctrlCreate ["RscText", -1];
private _cHdr   = _disp ctrlCreate ["RscText", -1];
private _cDv1   = _disp ctrlCreate ["RscText", -1];
private _cTrk   = _disp ctrlCreate ["RscText", -1];
private _cFil   = _disp ctrlCreate ["RscText", -1];
private _cPct   = _disp ctrlCreate ["RscText", -1];
private _cTime  = _disp ctrlCreate ["RscText", -1];
private _cHint  = _disp ctrlCreate ["RscText", -1];
private _cTL_H  = _disp ctrlCreate ["RscText", -1];
private _cTL_V  = _disp ctrlCreate ["RscText", -1];
private _cTR_H  = _disp ctrlCreate ["RscText", -1];
private _cTR_V  = _disp ctrlCreate ["RscText", -1];
private _cBL_H  = _disp ctrlCreate ["RscText", -1];
private _cBL_V  = _disp ctrlCreate ["RscText", -1];
private _cBR_H  = _disp ctrlCreate ["RscText", -1];
private _cBR_V  = _disp ctrlCreate ["RscText", -1];

// ─── Positions ────────────────────────────────────────────────────────────────
_cBG    ctrlSetPosition [_px,           _py,                _pw,     _ph         ]; _cBG    ctrlCommit 0;
_cHdrBg ctrlSetPosition [_px,           _py,                _pw,     _yDv1 - _py ]; _cHdrBg ctrlCommit 0;
_cAT    ctrlSetPosition [_px,           _yAT,               _pw,     _hAcct      ]; _cAT    ctrlCommit 0;
_cAB    ctrlSetPosition [_px,           _yAB,               _pw,     _hAcct      ]; _cAB    ctrlCommit 0;
_cHdr   ctrlSetPosition [_cx,           _yHdr  - _txtPad,   _cw,     _hHdr  + _txtPad]; _cHdr   ctrlCommit 0;
_cDv1   ctrlSetPosition [_cx,           _yDv1,              _cw,     _hDiv       ]; _cDv1   ctrlCommit 0;
_cTrk   ctrlSetPosition [_cx,           _yBar,              _cw,     _hBar       ]; _cTrk   ctrlCommit 0;
_cFil   ctrlSetPosition [_cx,           _yBar,              0.001,   _hBar       ]; _cFil   ctrlCommit 0;
_cPct   ctrlSetPosition [_cx,           _yInfo - _txtPad,   _cPctW,  _hInfo + _txtPad]; _cPct   ctrlCommit 0;
_cTime  ctrlSetPosition [_cTimeX,       _yInfo - _txtPad,   _cTimeW, _hInfo + _txtPad]; _cTime  ctrlCommit 0;
_cHint  ctrlSetPosition [_cx,           _yHint - _txtPad,   _cw,     _hHint + _txtPad]; _cHint  ctrlCommit 0;

_cTL_H  ctrlSetPosition [_px,           _py,                _crnW,   _crnTH      ]; _cTL_H  ctrlCommit 0;
_cTL_V  ctrlSetPosition [_px,           _py,                _crnTW,  _crnH       ]; _cTL_V  ctrlCommit 0;
_cTR_H  ctrlSetPosition [_px2 - _crnW,  _py,                _crnW,   _crnTH      ]; _cTR_H  ctrlCommit 0;
_cTR_V  ctrlSetPosition [_px2 - _crnTW, _py,                _crnTW,  _crnH       ]; _cTR_V  ctrlCommit 0;
_cBL_H  ctrlSetPosition [_px,           _py + _ph - _crnTH, _crnW,   _crnTH      ]; _cBL_H  ctrlCommit 0;
_cBL_V  ctrlSetPosition [_px,           _py + _ph - _crnH,  _crnTW,  _crnH       ]; _cBL_V  ctrlCommit 0;
_cBR_H  ctrlSetPosition [_px2 - _crnW,  _py + _ph - _crnTH, _crnW,   _crnTH      ]; _cBR_H  ctrlCommit 0;
_cBR_V  ctrlSetPosition [_px2 - _crnTW, _py + _ph - _crnH,  _crnTW,  _crnH       ]; _cBR_V  ctrlCommit 0;

// ─── Background colours ───────────────────────────────────────────────────────
_cBG    ctrlSetBackgroundColor _colBg;
_cHdrBg ctrlSetBackgroundColor _colHdrBg;
{ _x ctrlSetBackgroundColor _colAcctBrt } forEach [
    _cAT, _cAB, _cDv1,
    _cTL_H, _cTL_V, _cTR_H, _cTR_V,
    _cBL_H, _cBL_V, _cBR_H, _cBR_V
];
_cHdr  ctrlSetBackgroundColor _colNone;
_cTrk  ctrlSetBackgroundColor _colTrk;
_cFil  ctrlSetBackgroundColor _colGreen;
_cPct  ctrlSetBackgroundColor _colNone;
_cTime ctrlSetBackgroundColor _colNone;
_cHint ctrlSetBackgroundColor _colNone;

// ─── Text colours ─────────────────────────────────────────────────────────────
_cHdr  ctrlSetTextColor _colHdr;
_cPct  ctrlSetTextColor _colGreen;
_cTime ctrlSetTextColor _colLbl;
_cHint ctrlSetTextColor _colSub;

// ─── Fonts ────────────────────────────────────────────────────────────────────
private _fnt = "EtelkaNarrowMediumPro";
_cHdr  ctrlSetFont _fnt; _cHdr  ctrlSetFontHeight _fHdr;
_cPct  ctrlSetFont _fnt; _cPct  ctrlSetFontHeight _fInfo;
_cTime ctrlSetFont _fnt; _cTime ctrlSetFontHeight _fInfo;
_cHint ctrlSetFont _fnt; _cHint ctrlSetFontHeight _fHint;

// ─── Static text ──────────────────────────────────────────────────────────────
_cHdr  ctrlSetText _title;
_cHint ctrlSetText "PRESS ESC TO CANCEL";
_cPct  ctrlSetText "0%";
_cTime ctrlSetText format ["%1s remaining", round _duration];

// ─── Escape key cancels — bake subject NetId into handler so it's accessible ──
private _subjNetId = netId _subject;
private _escEH = (findDisplay 46) displayAddEventHandler ["KeyDown", compile format [
    "params ['_d','_k']; if (_k != 1) exitWith {false}; (objectFromNetId '%1') setVariable ['%2',false,true]; true",
    _subjNetId, _varName
]];

// ─── Update loop ──────────────────────────────────────────────────────────────
private _startTime = time;

while {
    player isEqualTo _caller &&
    alive _caller &&
    (_subject getVariable [_varName, false])
} do {
    private _elapsed  = time - _startTime;
    private _progress = (_elapsed / _duration) min 1.0;
    private _secsLeft = round ((_duration - _elapsed) max 0);

    _cFil  ctrlSetPosition [_cx, _yBar, ((_cw * _progress) max 0.001), _hBar]; _cFil ctrlCommit 0;
    _cPct  ctrlSetText format ["%1%%", round (_progress * 100)];
    _cTime ctrlSetText format ["%1s remaining", _secsLeft];

    sleep 0.1;
};
(findDisplay 46) displayRemoveEventHandler ["KeyDown", _escEH];

{ ctrlDelete _x } forEach [
    _cBG, _cHdrBg,
    _cAT, _cAB, _cHdr, _cDv1,
    _cTrk, _cFil, _cPct, _cTime, _cHint,
    _cTL_H, _cTL_V, _cTR_H, _cTR_V,
    _cBL_H, _cBL_V, _cBR_H, _cBR_V
];
