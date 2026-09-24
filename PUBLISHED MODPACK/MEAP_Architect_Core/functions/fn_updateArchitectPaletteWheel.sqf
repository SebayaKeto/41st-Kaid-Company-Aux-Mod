private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {};

if (_state getOrDefault ["paletteWheelOpen", false]) then
{
    call MEAP_fnc_closeArchitectPaletteWheel;
};