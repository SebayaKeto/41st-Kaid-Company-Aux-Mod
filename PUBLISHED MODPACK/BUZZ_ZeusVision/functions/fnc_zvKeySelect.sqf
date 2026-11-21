/*
    BUZZ_fnc_zvKeySelect
    CBA keybind "Show troopers in zone". Only acts while the Zeus interface
    is open: tags every player within BUZZ_ZeusVision_keyRadius (client
    setting, default 50 m) of the point under the mouse cursor. Same as
    picking a radius from the right-click menu, so it replaces the current
    selection.

    Returns: true if handled (the key press is consumed), false otherwise.
*/
if (isNull curatorCamera) exitWith { false };

private _position = screenToWorld getMousePosition;
[_position, BUZZ_ZeusVision_keyRadius] call BUZZ_fnc_zvSelect;

true
