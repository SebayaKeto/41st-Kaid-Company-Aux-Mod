/*
    BUZZ_fnc_zvColour
    Ammo state from rounds now vs. rounds when "full".

    Params: 0: rounds now <NUMBER>, 1: rounds when full <NUMBER>
    Returns: 0 Green, 1 Yellow, 2 Red, 3 Black <NUMBER>
*/
params ["_now", "_full"];
if (_now <= 0) exitWith { 3 };

private _pct = 100 * _now / (_full max 1);
if (_pct >= BUZZ_ZeusVision_greenAt) exitWith { 0 };
if (_pct >= BUZZ_ZeusVision_yellowAt) exitWith { 1 };
2
