params [
    ["_action", "", [""]],
    ["_buildId", "", [""]]
];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {_state getOrDefault ["actionPending", false]}) exitWith {};

private _normalizedAction = toUpper _action;
if (_normalizedAction isEqualTo "CAPTURE") exitWith
{
    private _target = _state getOrDefault ["selected", objNull];
    if (isNull _target) then {_target = _state getOrDefault ["target", objNull];};
    if (isNull _target) exitWith {["Target one of your Daidalos objects to save a build."] call MEAP_fnc_architectMessage;};
    _state set ["actionPending", true];
    _state set ["pendingAction", "CAPTURE"];
    _state set ["pendingAt", diag_tickTime];
    ["CAPTURE", player, _state get "token", [_target]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
};

private _blueprints = _state getOrDefault ["blueprints", []];
if (_blueprints isEqualTo []) exitWith {["No Daidalos builds are available."] call MEAP_fnc_architectMessage;};
if (_normalizedAction in ["CYCLE", "SELECT"]) exitWith
{
    private _index = if (_normalizedAction isEqualTo "CYCLE") then
    {
        ((_state getOrDefault ["blueprintIndex", 0]) + 1) mod count _blueprints
    }
    else
    {
        _blueprints findIf {(_x param [0, ""]) isEqualTo _buildId}
    };
    if (_index < 0) exitWith {["That Daidalos build is unavailable."] call MEAP_fnc_architectMessage;};
    if (_normalizedAction isEqualTo "CYCLE") then
    {
        _state set ["paletteFilter", ""];
        private _filterControl = _state getOrDefault ["paletteFilterControl", controlNull];
        if (!isNull _filterControl) then {_filterControl ctrlSetText "";};
    };
    private _selected = _state getOrDefault ["selected", objNull];
    if (!isNull _selected) then
    {
        _selected hideObject false;
        ["UNLOCK", player, _state get "token", [_selected]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
        _state set ["selected", objNull];
    };
    _state set ["blueprintIndex", _index];
    (_blueprints select _index) params ["_id", "_name"];
    _state set ["selectionType", "BUILD"];
    _state set ["selectedBlueprintId", _id];
    _state set ["paletteRevealSelection", true];
    _state set ["mode", "PLACE"];
    [] call MEAP_fnc_refreshArchitectPalette;
    [format ["Selected build: %1", _name]] call MEAP_fnc_architectMessage;
};
if (_normalizedAction isEqualTo "PLACE") then
{
    if !(_state getOrDefault ["previewValid", false]) exitWith {};
    private _blueprint = _blueprints select (_state getOrDefault ["blueprintIndex", 0]);
    _blueprint params ["_id"];
    _state set ["actionPending", true];
    _state set ["pendingAction", "PLACEBLUEPRINT"];
    _state set ["pendingAt", diag_tickTime];
    ["PLACEBLUEPRINT", player, _state get "token", [_id, _state get "previewPosition", _state get "rotation", false]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
};
