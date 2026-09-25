params
[
    ["_action", "", [""]],
    ["_success", false, [true]],
    ["_object", objNull, [objNull]],
    ["_message", "", [""]],
    ["_availableFunds", -1, [0]]
];

if (isRemoteExecuted && {remoteExecutedOwner != 2}) exitWith {};
if (!hasInterface) exitWith {};

if (_message isNotEqualTo "") then
{
    [_message] call MEAP_fnc_architectMessage;
};

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {};

if (_availableFunds >= 0) then {_state set ["availableFunds", _availableFunds];};

_state set ["actionPending", false];
_state set ["pendingAction", ""];
_state set ["pendingObject", objNull];
_state set ["pendingAt", -1];

switch (toUpper _action) do
{
    case "LOCK":
    {
        if (_success && {!isNull _object}) then
        {
            private _selected = _state getOrDefault ["selected", objNull];
            if (!isNull _selected) then {_selected hideObject false;};
            _object hideObject true;
            _state set ["selected", _object];
            _state set ["mode", "EDIT"];
            _state set ["rotation", getDir _object];
            [typeOf _object] call MEAP_fnc_createArchitectGhost;
        };
    };
    case "CREATE":
    {
        if (_success) then
        {
            _state set ["lastCreatedObject", _object];
            if (_object getVariable ["MEAP_Architect_draft", false]) then {_object hideObject false;};
        };
    };
    case "EDIT":
    {
        if (_success) then
        {
            private _selected = _state getOrDefault ["selected", objNull];
            if (!isNull _selected) then {_selected hideObject false;};
            _state set ["selected", objNull];
            _state set ["mode", "PLACE"];
            private _classIndex = _state get "classIndex";
            [((_state get "classes") param [_classIndex, ""])] call MEAP_fnc_createArchitectGhost;
        };
    };
    case "DELETE":
    {
        if (_success) then
        {
            private _selected = _state getOrDefault ["selected", objNull];
            if (!isNull _selected) then {_selected hideObject false;};
            _state set ["selected", objNull];
            _state set ["target", objNull];
            _state set ["mode", "PLACE"];
            private _classIndex = _state get "classIndex";
            [((_state get "classes") param [_classIndex, ""])] call MEAP_fnc_createArchitectGhost;
        };
    };
};