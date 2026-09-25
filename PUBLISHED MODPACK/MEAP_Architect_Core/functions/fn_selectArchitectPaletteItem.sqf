params [["_className", "", [""]]];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (
    count _state == 0
    || {_state getOrDefault ["actionPending", false]}
    || {_state getOrDefault ["paletteRefreshing", false]}
) exitWith {false};

if (_className isEqualTo "") exitWith {false};

private _classes = _state getOrDefault ["classes", []];
private _classIndex = _classes find _className;
if (_classIndex < 0) exitWith {false};

private _selected = _state getOrDefault ["selected", objNull];
if (!isNull _selected) then
{
    _selected hideObject false;
    ["UNLOCK", player, _state get "token", [_selected]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
    _state set ["selected", objNull];
};

_state set ["classIndex", _classIndex];
_state set ["selectionType", "OBJECT"];
_state set ["selectedBlueprintId", ""];
_state set ["paletteRevealSelection", true];
_state set ["mode", "PLACE"];
private _ghost = [_className] call MEAP_fnc_createArchitectGhost;
if (isNull _ghost) exitWith
{
    [format ["Daidalos could not create a preview for %1.", _className]] call MEAP_fnc_architectMessage;
    false
};
[] call MEAP_fnc_refreshArchitectPalette;
true