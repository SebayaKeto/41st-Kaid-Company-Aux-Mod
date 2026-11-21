/*
    BUZZ_fnc_zvDraw
    Draw3D mission event handler (local to each Zeus). Draws the tags only
    while the Zeus interface is open and someone is tracked.
*/
if (isNull curatorCamera || { !BUZZ_ZeusVision_enabled } || { !BUZZ_zv_trackAll && { BUZZ_zv_tracked isEqualTo [] } }) exitWith {};

if (diag_tickTime >= BUZZ_zv_nextRefresh) then {
    BUZZ_zv_nextRefresh = diag_tickTime + 0.5;
    call BUZZ_fnc_zvRefreshCache;
};

private _camPos = positionCameraToWorld [0, 0, 0];
private _size = BUZZ_ZeusVision_textSize;

{
    _x params ["_unit", "_lines"];
    if (!isNull _unit) then {
        private _base = _unit modelToWorldVisual [0, 0, 2.1];
        // Spacing grows with distance so lines keep the same gap on screen.
        private _step = (_camPos distance _base) * _size * 0.75;
        private _count = count _lines;
        {
            _x params ["_text", "_colour"];
            drawIcon3D ["", _colour, _base vectorAdd [0, 0, (_count - 1 - _forEachIndex) * _step], 0, 0, 0, _text, 2, _size, "RobotoCondensedBold", "center"];
        } forEach _lines;
    };
} forEach BUZZ_zv_cache;
