// =============================================================================
//  BUZZ AT-RT — hud.sqf
//  Horizontal two-row layout: header HP bar + three-column stat strip.
//  Top-right placement, overlaying the default ArmA 3 HUD.
//  Retains L-bracket corners and cascading scan lines from previous design.
//  _this = [_atrt, _rider]
// =============================================================================

disableSerialization;
params ["_atrt", "_rider"];

sleep 0.5;
if (!(player isEqualTo _rider)) exitWith {};

private _disp = findDisplay 46;
if (isNull _disp) exitWith {};

// ─── Color palette ────────────────────────────────────────────────────────────
private _colBg      = [0.030, 0.050, 0.095, 0.900];
private _colHdrBg   = [0.040, 0.065, 0.120, 0.960];
private _colAcct    = [0.310, 0.640, 1.000, 0.850];
private _colAcctBrt = [0.435, 0.740, 1.000, 1.000];
private _colHdr     = [0.920, 0.950, 1.000, 1.000];
private _colSub     = [0.430, 0.650, 0.870, 0.750];
private _colLbl     = [0.530, 0.710, 0.910, 0.850];
private _colAmber   = [0.900, 0.650, 0.000, 1.000];
private _colRed     = [0.850, 0.150, 0.100, 1.000];
private _colTrk     = [0.025, 0.040, 0.085, 1.000];
private _colGreen   = [0.100, 0.850, 0.250, 1.000];
private _colYellow  = [0.950, 0.850, 0.000, 1.000];
private _colOrange  = [0.950, 0.450, 0.050, 1.000];
private _colScan1   = [0.310, 0.640, 1.000, 0.080];
private _colScan2   = [0.435, 0.740, 1.000, 0.100];
private _colScan3   = [0.220, 0.500, 0.900, 0.060];
private _colScan4   = [0.550, 0.800, 1.000, 0.120];
private _colScan5   = [0.380, 0.680, 0.950, 0.070];
private _colNone    = [0, 0, 0, 0];

// ─── Panel anchor — top-right ─────────────────────────────────────────────────
private _pw  = safeZoneW * 0.265;
private _px  = safeZoneX + safeZoneW - _pw - safeZoneW * 0.008;
private _py  = safeZoneY + safeZoneH * 0.007;
private _px2 = _px + _pw;

// ─── Row heights ──────────────────────────────────────────────────────────────
// RULE: control height >= 2× font height (ArmA 3 descender clipping).
private _hAcct = safeZoneH * 0.0025; // top/bottom accent lines     (no text)
private _hHdr  = safeZoneH * 0.0540; // header row                  font 0.0240 (ratio 2.25×)
private _hDiv  = safeZoneH * 0.0012; // horizontal divider          (no text)
private _hLbl  = safeZoneH * 0.0280; // SPEED / AMMO / JUMP labels  font 0.0130 (ratio 2.15×)
private _hVal  = safeZoneH * 0.0600; // large numeric values        font 0.0280 (ratio 2.14×)
private _hUnit = safeZoneH * 0.0210; // km/h / Reserves sub-labels  font 0.0105 (ratio 2.00×)

private _fHdr  = safeZoneH * 0.0240;
private _fLbl  = safeZoneH * 0.0130;
private _fVal  = safeZoneH * 0.0280;
private _fUnit = safeZoneH * 0.0105;

// ─── Spacing ──────────────────────────────────────────────────────────────────
private _padO = safeZoneH * 0.0025;
private _padI = safeZoneH * 0.0015;
private _padX = safeZoneW * 0.0055; // inner horizontal text margin

// ─── Corner L-bracket dimensions ─────────────────────────────────────────────
private _crnW  = safeZoneW * 0.0160;
private _crnH  = safeZoneH * 0.0160;
private _crnTH = safeZoneH * 0.0025;
private _crnTW = safeZoneW * 0.0020;

// ─── Y positions ──────────────────────────────────────────────────────────────
private _yAT   = _py;
private _yHdr  = _yAT   + _hAcct + _padO;
private _yDivH = _yHdr  + _hHdr  + _padI;
private _yLbl  = _yDivH + _hDiv + _padI;
// Position each row so its text starts _colGap below the previous row's text.
// Controls overlap positionally but all have transparent backgrounds — no visual issue.
// Formula: next_text_top = curr_text_bottom + _colGap
//          _yNext = _yCurr + (_hCurr + _fCurr) * 0.5 + _colGap - (_hNext - _fNext) * 0.5
private _colGap = safeZoneH * 0.005;

// Post-update ArmA 3 clips glyph tops against the control's own top edge —
// text now renders anchored toward the bottom of its box instead of centred,
// so every text (not background/divider) control needs extra room added
// ABOVE its nominal box, with the bottom edge left where the layout put it.
private _txtPad = safeZoneH * 0.014;
private _yVal  = _yLbl + (_hLbl + _fLbl) * 0.5 + _colGap - (_hVal - _fVal) * 0.5;
// Value row's actual (bottom-anchored) text sits _txtPad lower than this
// centred-text formula assumes — added directly here so Unit doesn't overlap it.
private _yUnit = _yVal + (_hVal + _fVal) * 0.5 + _colGap - (_hUnit - _fUnit) * 0.5 + _txtPad;
private _yAB   = _yUnit + _hUnit + _padO;
private _ph    = (_yAB  + _hAcct) - _py;

// ─── Scan line range — stats area only ────────────────────────────────────────
private _scanRange = _yAB - _yDivH;
private _s1Spd = 0.035 + random 0.085; private _s1Pha = random 1.0; private _s1H = safeZoneH * (0.0012 + random 0.0038);
private _s2Spd = 0.035 + random 0.085; private _s2Pha = random 1.0; private _s2H = safeZoneH * (0.0012 + random 0.0038);
private _s3Spd = 0.035 + random 0.085; private _s3Pha = random 1.0; private _s3H = safeZoneH * (0.0012 + random 0.0038);
private _s4Spd = 0.035 + random 0.085; private _s4Pha = random 1.0; private _s4H = safeZoneH * (0.0012 + random 0.0038);
private _s5Spd = 0.035 + random 0.085; private _s5Pha = random 1.0; private _s5H = safeZoneH * (0.0012 + random 0.0038);

// ─── Header layout — "AT-RT UNIT" block + HP fill area ────────────────────────
// Title block occupies left 24% of panel; HP bar fills the remaining 76%.
private _titleW = _pw * 0.240;
private _hpX   = _px  + _titleW;
private _hpW   = _pw  - _titleW;

// ─── Stats column layout — three equal columns separated by 1px dividers ──────
private _divW  = safeZoneW * 0.0010;
private _colW  = (_pw - 2 * _divW) / 3;
private _col1X = _px;
private _col2X = _col1X + _colW + _divW;
private _col3X = _col2X + _colW + _divW;

// Height of the entire stats strip (from divider bottom to bottom accent top).
private _statH = _yAB - (_yDivH + _hDiv);

// ─── Supply box reference ─────────────────────────────────────────────────────
private _box = _atrt getVariable ["supplyBox", objNull];

// ─── Create controls (z-order: first created = deepest layer) ─────────────────
// Panel backgrounds
private _cBG       = _disp ctrlCreate ["RscText", -1]; // full panel
private _cHdrBg    = _disp ctrlCreate ["RscText", -1]; // title block (dark)
private _cHpTrk    = _disp ctrlCreate ["RscText", -1]; // HP track area (dark)
private _cHpFil    = _disp ctrlCreate ["RscText", -1]; // HP fill (green, variable)

// Structural lines
private _cTitleDiv = _disp ctrlCreate ["RscText", -1]; // accent: title | hp area
private _cDivH     = _disp ctrlCreate ["RscText", -1]; // accent: header | stats

// L-bracket corners
private _cTL_H  = _disp ctrlCreate ["RscText", -1];
private _cTL_V  = _disp ctrlCreate ["RscText", -1];
private _cTR_H  = _disp ctrlCreate ["RscText", -1];
private _cTR_V  = _disp ctrlCreate ["RscText", -1];
private _cBL_H  = _disp ctrlCreate ["RscText", -1];
private _cBL_V  = _disp ctrlCreate ["RscText", -1];
private _cBR_H  = _disp ctrlCreate ["RscText", -1];
private _cBR_V  = _disp ctrlCreate ["RscText", -1];

// Top and bottom accent bars
private _cAT = _disp ctrlCreate ["RscText", -1];
private _cAB = _disp ctrlCreate ["RscText", -1];

// Header text — created after fills so they render above the HP fill.
private _cTitle  = _disp ctrlCreate ["RscText", -1]; // "AT-RT UNIT"
private _cHpLbl  = _disp ctrlCreate ["RscText", -1]; // "HULL INTEGRITY"
private _cPct    = _disp ctrlCreate ["RscText", -1]; // "100%"

// Stat column vertical dividers
private _cVDiv1  = _disp ctrlCreate ["RscText", -1]; // SPEED | AMMO
private _cVDiv2  = _disp ctrlCreate ["RscText", -1]; // AMMO  | JUMP

// Stat column labels (top row)
private _cSpdLbl  = _disp ctrlCreate ["RscText", -1];
private _cAmmoLbl = _disp ctrlCreate ["RscText", -1];
private _cJmpLbl  = _disp ctrlCreate ["RscText", -1];

// Stat column values (large, middle row)
private _cSpd  = _disp ctrlCreate ["RscText", -1];
private _cAmmo = _disp ctrlCreate ["RscText", -1];
private _cJmp  = _disp ctrlCreate ["RscText", -1];

// Stat column units (small, bottom row) — JUMP has no sub-label.
private _cSpdU  = _disp ctrlCreate ["RscText", -1];
private _cAmmoU = _disp ctrlCreate ["RscText", -1];

// Scan lines — created last so they render above all static elements.
private _cScan1 = _disp ctrlCreate ["RscText", -1];
private _cScan2 = _disp ctrlCreate ["RscText", -1];
private _cScan3 = _disp ctrlCreate ["RscText", -1];
private _cScan4 = _disp ctrlCreate ["RscText", -1];
private _cScan5 = _disp ctrlCreate ["RscText", -1];

// ─── Positions ────────────────────────────────────────────────────────────────
_cBG       ctrlSetPosition [_px,                _py,                 _pw,               _ph         ]; _cBG       ctrlCommit 0;
_cHdrBg    ctrlSetPosition [_px,                _yHdr,               _titleW,           _hHdr       ]; _cHdrBg    ctrlCommit 0;
_cHpTrk    ctrlSetPosition [_hpX,               _yHdr,               _hpW,              _hHdr       ]; _cHpTrk    ctrlCommit 0;
_cHpFil    ctrlSetPosition [_hpX,               _yHdr,               _hpW,              _hHdr       ]; _cHpFil    ctrlCommit 0;
_cTitleDiv ctrlSetPosition [_hpX - _divW,       _yHdr,               _divW,             _hHdr       ]; _cTitleDiv ctrlCommit 0;
_cDivH     ctrlSetPosition [_px,                _yDivH,              _pw,               _hDiv       ]; _cDivH     ctrlCommit 0;

_cTL_H     ctrlSetPosition [_px,                _py,                 _crnW,             _crnTH      ]; _cTL_H     ctrlCommit 0;
_cTL_V     ctrlSetPosition [_px,                _py,                 _crnTW,            _crnH       ]; _cTL_V     ctrlCommit 0;
_cTR_H     ctrlSetPosition [_px2 - _crnW,       _py,                 _crnW,             _crnTH      ]; _cTR_H     ctrlCommit 0;
_cTR_V     ctrlSetPosition [_px2 - _crnTW,      _py,                 _crnTW,            _crnH       ]; _cTR_V     ctrlCommit 0;
_cBL_H     ctrlSetPosition [_px,                _py + _ph - _crnTH,  _crnW,             _crnTH      ]; _cBL_H     ctrlCommit 0;
_cBL_V     ctrlSetPosition [_px,                _py + _ph - _crnH,   _crnTW,            _crnH       ]; _cBL_V     ctrlCommit 0;
_cBR_H     ctrlSetPosition [_px2 - _crnW,       _py + _ph - _crnTH,  _crnW,             _crnTH      ]; _cBR_H     ctrlCommit 0;
_cBR_V     ctrlSetPosition [_px2 - _crnTW,      _py + _ph - _crnH,   _crnTW,            _crnH       ]; _cBR_V     ctrlCommit 0;

_cAT       ctrlSetPosition [_px,                _yAT,                _pw,               _hAcct      ]; _cAT       ctrlCommit 0;
_cAB       ctrlSetPosition [_px,                _yAB,                _pw,               _hAcct      ]; _cAB       ctrlCommit 0;

// Title text — left-aligned with inner horizontal margin. Y/H padded per
// _txtPad above (see comment) — bottom edge unchanged, room added above.
_cTitle    ctrlSetPosition [_px + _padX,          _yHdr  - _txtPad,   _titleW - _padX,   _hHdr  + _txtPad]; _cTitle    ctrlCommit 0;
// HP label — left-aligned just inside the fill area.
_cHpLbl    ctrlSetPosition [_hpX + _padX,         _yHdr  - _txtPad,   _hpW * 0.60,       _hHdr  + _txtPad]; _cHpLbl    ctrlCommit 0;
// Percentage — narrow control anchored to the right edge so left-aligned text sits flush right.
private _pctW = safeZoneW * 0.044;
_cPct      ctrlSetPosition [_px2 - _pctW - _padX, _yHdr  - _txtPad,   _pctW,             _hHdr  + _txtPad]; _cPct      ctrlCommit 0;

_cVDiv1    ctrlSetPosition [_col1X + _colW,      _yDivH + _hDiv,      _divW,             _statH      ]; _cVDiv1    ctrlCommit 0;
_cVDiv2    ctrlSetPosition [_col2X + _colW,      _yDivH + _hDiv,      _divW,             _statH      ]; _cVDiv2    ctrlCommit 0;

_cSpdLbl   ctrlSetPosition [_col1X,             _yLbl  - _txtPad,    _colW,             _hLbl  + _txtPad]; _cSpdLbl   ctrlCommit 0;
_cAmmoLbl  ctrlSetPosition [_col2X,             _yLbl  - _txtPad,    _colW,             _hLbl  + _txtPad]; _cAmmoLbl  ctrlCommit 0;
_cJmpLbl   ctrlSetPosition [_col3X,             _yLbl  - _txtPad,    _colW,             _hLbl  + _txtPad]; _cJmpLbl   ctrlCommit 0;

_cSpd      ctrlSetPosition [_col1X,             _yVal  - _txtPad,    _colW,             _hVal  + _txtPad]; _cSpd      ctrlCommit 0;
_cAmmo     ctrlSetPosition [_col2X,             _yVal  - _txtPad,    _colW,             _hVal  + _txtPad]; _cAmmo     ctrlCommit 0;
_cJmp      ctrlSetPosition [_col3X,             _yVal  - _txtPad,    _colW,             _hVal  + _txtPad]; _cJmp      ctrlCommit 0;

_cSpdU     ctrlSetPosition [_col1X,             _yUnit - _txtPad,    _colW,             _hUnit + _txtPad]; _cSpdU     ctrlCommit 0;
_cAmmoU    ctrlSetPosition [_col2X,             _yUnit - _txtPad,    _colW,             _hUnit + _txtPad]; _cAmmoU    ctrlCommit 0;

// Scan lines: initial positions spread by randomised phase.
_cScan1 ctrlSetPosition [_px, _yDivH + _s1Pha * _scanRange, _pw, _s1H]; _cScan1 ctrlCommit 0;
_cScan2 ctrlSetPosition [_px, _yDivH + _s2Pha * _scanRange, _pw, _s2H]; _cScan2 ctrlCommit 0;
_cScan3 ctrlSetPosition [_px, _yDivH + _s3Pha * _scanRange, _pw, _s3H]; _cScan3 ctrlCommit 0;
_cScan4 ctrlSetPosition [_px, _yDivH + _s4Pha * _scanRange, _pw, _s4H]; _cScan4 ctrlCommit 0;
_cScan5 ctrlSetPosition [_px, _yDivH + _s5Pha * _scanRange, _pw, _s5H]; _cScan5 ctrlCommit 0;

// ─── Background colors ────────────────────────────────────────────────────────
_cBG       ctrlSetBackgroundColor _colBg;
_cHdrBg    ctrlSetBackgroundColor _colHdrBg;
_cHpTrk    ctrlSetBackgroundColor _colTrk;
_cHpFil    ctrlSetBackgroundColor _colGreen;
_cTitleDiv ctrlSetBackgroundColor _colAcctBrt;
_cDivH     ctrlSetBackgroundColor _colAcctBrt;
{ _x ctrlSetBackgroundColor _colAcctBrt } forEach [
    _cAT, _cAB,
    _cTL_H, _cTL_V, _cTR_H, _cTR_V,
    _cBL_H, _cBL_V, _cBR_H, _cBR_V
];
_cVDiv1 ctrlSetBackgroundColor _colAcct;
_cVDiv2 ctrlSetBackgroundColor _colAcct;
{ _x ctrlSetBackgroundColor _colNone } forEach [
    _cTitle, _cHpLbl, _cPct,
    _cSpdLbl, _cAmmoLbl, _cJmpLbl,
    _cSpd, _cAmmo, _cJmp,
    _cSpdU, _cAmmoU
];
_cScan1 ctrlSetBackgroundColor _colScan1;
_cScan2 ctrlSetBackgroundColor _colScan2;
_cScan3 ctrlSetBackgroundColor _colScan3;
_cScan4 ctrlSetBackgroundColor _colScan4;
_cScan5 ctrlSetBackgroundColor _colScan5;

// ─── Text colors ──────────────────────────────────────────────────────────────
_cTitle   ctrlSetTextColor _colHdr;
_cHpLbl   ctrlSetTextColor _colHdr;
_cPct     ctrlSetTextColor _colHdr;
_cSpdLbl  ctrlSetTextColor _colLbl;
_cAmmoLbl ctrlSetTextColor _colLbl;
_cJmpLbl  ctrlSetTextColor _colLbl;
_cSpd     ctrlSetTextColor _colHdr;
_cAmmo    ctrlSetTextColor _colHdr;
_cJmp     ctrlSetTextColor _colGreen;
_cSpdU    ctrlSetTextColor _colSub;
_cAmmoU   ctrlSetTextColor _colSub;

// ─── Fonts ────────────────────────────────────────────────────────────────────
private _fnt = "EtelkaNarrowMediumPro";
_cTitle   ctrlSetFont _fnt; _cTitle   ctrlSetFontHeight _fHdr;
_cHpLbl   ctrlSetFont _fnt; _cHpLbl   ctrlSetFontHeight _fHdr;
_cPct     ctrlSetFont _fnt; _cPct     ctrlSetFontHeight _fHdr;
_cSpdLbl  ctrlSetFont _fnt; _cSpdLbl  ctrlSetFontHeight _fLbl;
_cAmmoLbl ctrlSetFont _fnt; _cAmmoLbl ctrlSetFontHeight _fLbl;
_cJmpLbl  ctrlSetFont _fnt; _cJmpLbl  ctrlSetFontHeight _fLbl;
_cSpd     ctrlSetFont _fnt; _cSpd     ctrlSetFontHeight _fVal;
_cAmmo    ctrlSetFont _fnt; _cAmmo    ctrlSetFontHeight _fVal;
_cJmp     ctrlSetFont _fnt; _cJmp     ctrlSetFontHeight _fVal;
_cSpdU    ctrlSetFont _fnt; _cSpdU    ctrlSetFontHeight _fUnit;
_cAmmoU   ctrlSetFont _fnt; _cAmmoU   ctrlSetFontHeight _fUnit;

// ─── Static text ─────────────────────────────────────────────────────────────
_cTitle   ctrlSetText "AT-RT UNIT";
_cHpLbl   ctrlSetText "HULL INTEGRITY";
_cPct     ctrlSetText "100%";
_cSpdLbl  ctrlSetText "SPEED";
_cAmmoLbl ctrlSetText "AMMO";
_cJmpLbl  ctrlSetText "JUMP";
_cSpd     ctrlSetText "0";
_cAmmo    ctrlSetText "---";
_cJmp     ctrlSetText "READY";
_cSpdU    ctrlSetText "km/h";
_cAmmoU   ctrlSetText "x0 Reserves";

// ─── Update loop ─────────────────────────────────────────────────────────────
while { player isEqualTo (_atrt getVariable ["rider", objNull]) && alive _atrt } do {
    private _health = _atrt getVariable ["BUZZ_hp", 1.0];

    // HP fill — shrinks from right as HP drops.
    private _fillW = (_hpW * _health) max 0.001;
    _cHpFil ctrlSetPosition [_hpX, _yHdr, _fillW, _hHdr];
    _cHpFil ctrlCommit 0;

    // HP bar and percentage color — four tiers, critical flashes at ~3 Hz.
    private _fillCol =
        if     (_health >= 0.75) then { _colGreen  }
        else { if (_health >= 0.50) then { _colYellow }
        else { if (_health >= 0.33) then { _colOrange }
        else {
            if ((floor (time * 3)) mod 2 == 0) then { _colRed } else { _colTrk }
        }}};
    _cHpFil ctrlSetBackgroundColor _fillCol;
    _cPct   ctrlSetText (str (round (_health * 100)) + "%");

    // Speed
    private _kph = round (speed _atrt);
    _cSpd ctrlSetText (str _kph);

    // Sprint speed boost via setAnimSpeedCoef — correct lever for 3AS-based walkers.
    // Walk stays at coef 1.0 (~13 km/h); sprint scaled to ~55 km/h.
    // Threshold 22 sits between walk (~13) and base sprint (~33) to detect the gait.
    _atrt setAnimSpeedCoef (if (_kph > 22) then { 1.667 } else { 1.0 });

    // Ammo — power cell counter + reserve magazine count from supply box.
    private _rounds = _atrt getVariable ["BUZZ_powerCell", 0];
    private _c = if (!isNull _box) then { getMagazineCargo _box } else { [[], []] };
    private _i = (_c select 0) find "BUZZ_ATRT_T15ReserveMag";
    private _mags = if (_i < 0) then { 0 } else { (_c select 1) select _i };
    if (_atrt getVariable ["BUZZ_reloading", false]) then {
        _cAmmo ctrlSetTextColor _colAmber;
        private _reloadStart = _atrt getVariable ["BUZZ_reloadStart", time];
        private _secsLeft = ((5 - floor (time - _reloadStart)) max 0) min 5;
        _cAmmo ctrlSetText format ["RELOAD (%1s)", _secsLeft];
    } else {
        _cAmmo ctrlSetTextColor _colHdr;
        _cAmmo ctrlSetText (str _rounds);
    };
    _cAmmoU ctrlSetText format ["x%1 Reserves", _mags];

    // Jump cooldown
    private _cdLeft = round (((_atrt getVariable ["BUZZ_jumpCooldown", 0]) - time) max 0);
    if (_cdLeft <= 0) then {
        _cJmp ctrlSetTextColor _colGreen;
        _cJmp ctrlSetText "READY";
    } else {
        _cJmp ctrlSetTextColor _colAmber;
        _cJmp ctrlSetText (str _cdLeft + "s");
    };

    // Scan lines — randomised speed and phase so they never bunch.
    _cScan1 ctrlSetPosition [_px, _yDivH + ((time * _s1Spd + _s1Pha) mod 1.0) * _scanRange, _pw, _s1H]; _cScan1 ctrlCommit 0;
    _cScan2 ctrlSetPosition [_px, _yDivH + ((time * _s2Spd + _s2Pha) mod 1.0) * _scanRange, _pw, _s2H]; _cScan2 ctrlCommit 0;
    _cScan3 ctrlSetPosition [_px, _yDivH + ((time * _s3Spd + _s3Pha) mod 1.0) * _scanRange, _pw, _s3H]; _cScan3 ctrlCommit 0;
    _cScan4 ctrlSetPosition [_px, _yDivH + ((time * _s4Spd + _s4Pha) mod 1.0) * _scanRange, _pw, _s4H]; _cScan4 ctrlCommit 0;
    _cScan5 ctrlSetPosition [_px, _yDivH + ((time * _s5Spd + _s5Pha) mod 1.0) * _scanRange, _pw, _s5H]; _cScan5 ctrlCommit 0;

    sleep 0.1;
};

_atrt setAnimSpeedCoef 1.0; // reset on dismount so next rider starts clean.

// ─── Cleanup ─────────────────────────────────────────────────────────────────
{ ctrlDelete _x } forEach [
    _cBG, _cHdrBg, _cHpTrk, _cHpFil, _cTitleDiv, _cDivH,
    _cTL_H, _cTL_V, _cTR_H, _cTR_V, _cBL_H, _cBL_V, _cBR_H, _cBR_V,
    _cAT, _cAB,
    _cTitle, _cHpLbl, _cPct,
    _cVDiv1, _cVDiv2,
    _cSpdLbl, _cAmmoLbl, _cJmpLbl,
    _cSpd, _cAmmo, _cJmp,
    _cSpdU, _cAmmoU,
    _cScan1, _cScan2, _cScan3, _cScan4, _cScan5
];
