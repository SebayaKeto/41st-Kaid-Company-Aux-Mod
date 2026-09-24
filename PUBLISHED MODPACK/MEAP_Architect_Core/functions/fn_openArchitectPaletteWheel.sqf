params [["_continueHierarchy", false, [true]]];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {_state getOrDefault ["actionPending", false]}) exitWith {};

if (!_continueHierarchy) then
{
    _state set ["paletteFilter", ""];
    private _filterControl = _state getOrDefault ["paletteFilterControl", controlNull];
    if (!isNull _filterControl) then {_filterControl ctrlSetText "";};
};

call MEAP_fnc_closeArchitectPaletteWheel;
[] call MEAP_fnc_refreshArchitectPalette;
