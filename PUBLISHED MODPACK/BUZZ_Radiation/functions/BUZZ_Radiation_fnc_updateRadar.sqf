// Direction ring of the Radiation Monitor panel
private _displays = (uiNamespace getVariable ["BUZZ_Radiation_monitorDisplays", []]) select {!isNull _x};
if (_displays isEqualTo []) exitWith {};

private _hasDevice = alive player && {!isNull objectParent player || {[player, BUZZ_Radiation_monitorList] call BUZZ_Radiation_fnc_hasItem}};

private _gw = ((safezoneW / safezoneH) min 1.2) / 40;
private _gh = ((safezoneW / safezoneH) min 1.2) / 1.2 / 25;
// Aspect ratio correction
private _res = getResolution;
private _xScale = (safezoneW / safezoneH) / ((_res select 0) / (_res select 1));

private _samples = [];
if (_hasDevice) then {
    private _view = getCameraViewDirection player;
    private _heading = (_view select 0) atan2 (_view select 1);
    private _origin = getPosATLVisual player;
    {
        private _range = _x;
        for "_i" from 0 to 15 do {
            _samples pushBack ([_origin getPos [_range, _heading + _i * 22.5]] call BUZZ_Radiation_fnc_sampleTier);
        };
    } forEach [10, 20, 30, 40];
};

private _colours = [
    [1, 1, 1, 0.15],
    [0.9, 0.8, 0.2, 1],
    [0.85, 0.5, 0, 1],
    [0.85, 0.1, 0.1, 1],
    [0.2, 0.85, 0.3, 1]
];

{
    private _d = _x;
    private _panelW = (ctrlPosition (_d displayCtrl 1000)) select 2;
    private _cx = _panelW / 2;
    private _cy = 3.6 * _gh;
    private _dotH = 0.32 * _gh;
    private _dotW = _dotH * _xScale;

    // Backing disc
    private _discR = 2.85 * _gh;
    private _disc = _d displayCtrl 2100;
    _disc ctrlSetPosition [_cx - _discR * _xScale, _cy - _discR, 2 * _discR * _xScale, 2 * _discR];
    _disc ctrlCommit 0;
    private _coneL = 2.6 * _gh;
    private _cone = _d displayCtrl 2101;
    _cone ctrlSetPosition [_cx - _coneL * _xScale / 2, _cy - _coneL, _coneL * _xScale, _coneL];
    _cone ctrlSetTextColor [0, 0.85, 1, [0, 0.5] select _hasDevice];
    _cone ctrlCommit 0;
    private _edge = _d displayCtrl 2102;
    _edge ctrlSetPosition (ctrlPosition _cone);
    _edge ctrlSetTextColor [0, 0.85, 1, [0, 1] select _hasDevice];
    _edge ctrlCommit 0;

    for "_i" from 0 to 64 do {
        private _ctrl = _d displayCtrl (2000 + _i);
        if (_i == 64) then {
            // Centre marker
            _ctrl ctrlSetPosition [_cx - _dotW / 2, _cy - _dotH / 2, _dotW, _dotH];
            _ctrl ctrlSetTextColor [1, 1, 1, [0.15, 0.9] select _hasDevice];
        } else {
            private _ring = floor (_i / 16);
            private _angle = (_i mod 16) * 22.5;
            private _r = [0.9, 1.4, 1.9, 2.4] select _ring;
            private _x0 = _cx + (sin _angle) * _r * _gh * _xScale;
            private _y0 = _cy - (cos _angle) * _r * _gh;
            _ctrl ctrlSetPosition [_x0 - _dotW / 2, _y0 - _dotH / 2, _dotW, _dotH];
            private _tier = if (_hasDevice) then {_samples select _i} else {-1};
            private _col = +(_colours select (_tier + 1));
            if (_tier in [0, 1, 2]) then {_col set [3, 0.55 + random 0.45]};
            _ctrl ctrlSetTextColor _col;
        };
        _ctrl ctrlCommit 0;
    };
} forEach _displays;
