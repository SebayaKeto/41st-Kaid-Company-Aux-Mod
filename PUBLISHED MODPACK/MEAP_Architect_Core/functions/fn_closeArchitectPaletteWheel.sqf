private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {};

private _primarySurface = _state getOrDefault ["primarySurfaceControl", controlNull];
if (!isNull _primarySurface) then {_primarySurface ctrlShow true;};

{
    if (!isNull _x) then {ctrlDelete _x;};
} forEach (_state getOrDefault ["paletteWheelControls", []]);

_state set ["paletteWheelControls", []];
_state set ["paletteWheelEntries", []];
_state set ["paletteWheelHoverIndex", -1];
_state set ["paletteWheelHoverAt", -1];
_state set ["paletteWheelOpen", false];