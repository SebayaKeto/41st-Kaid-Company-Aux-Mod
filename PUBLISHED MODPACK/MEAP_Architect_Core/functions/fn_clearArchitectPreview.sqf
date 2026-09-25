private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {_state getOrDefault ["actionPending", false]}) exitWith {};

private _selected = _state getOrDefault ["selected", objNull];
if (!isNull _selected) then
{
    _selected hideObject false;
    ["UNLOCK", player, _state get "token", [_selected]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
    _state set ["selected", objNull];
};

[""] call MEAP_fnc_createArchitectGhost;
_state set ["classIndex", -1];
_state set ["mode", "PLACE"];
_state set ["previewActive", false];
_state set ["previewValid", false];
_state set ["previewPosition", []];
_state set ["previewVectors", []];
_state set ["previewDistance", 0];
_state set ["rawPreviewPosition", []];
_state set ["snapTarget", objNull];
_state set ["snapPoint", ""];
_state set ["target", objNull];
[] call MEAP_fnc_refreshArchitectPalette;