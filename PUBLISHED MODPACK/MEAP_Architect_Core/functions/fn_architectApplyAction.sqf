private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (
    count _state == 0
    || {_state getOrDefault ["actionPending", false]}
) exitWith {};

private _mode = _state get "mode";
if (!(_mode isEqualTo "EDIT") && {isNull (_state getOrDefault ["ghost", objNull])}) exitWith {};
if !(_state getOrDefault ["previewValid", false]) exitWith {};

private _position = _state get "previewPosition";
private _vectors = _state get "previewVectors";
private _token = _state get "token";
private _snapTarget = _state getOrDefault ["snapTarget", objNull];
private _snapSide = _state get "snapSide";
private _snapPoint = _state getOrDefault ["snapPoint", ""];

if (_mode isEqualTo "EDIT") then
{
    private _selected = _state getOrDefault ["selected", objNull];
    if (isNull _selected) exitWith {};
    _state set ["actionPending", true];
    _state set ["pendingAction", "EDIT"];
    _state set ["pendingObject", _selected];
    _state set ["pendingAt", diag_tickTime];
    ["EDIT", player, _token, [_selected, _position, _vectors, _snapTarget, _snapSide, _snapPoint]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
}
else
{
    if ((_state getOrDefault ["selectionType", "OBJECT"]) isEqualTo "BUILD") exitWith
    {
        ["PLACE"] call MEAP_fnc_architectBlueprintAction;
    };
    private _classIndex = _state get "classIndex";
    private _className = (_state get "classes") param [_classIndex, ""];
    if !(_state getOrDefault ["canAfford", true]) exitWith
    {
        private _currencyName = _state getOrDefault ["currencyName", "Republic Credits"];
        private _cost = _state getOrDefault ["selectedBuildCost", 0];
        [format ["Not enough %1 for this object (%2 required).", _currencyName, _cost]] call MEAP_fnc_architectMessage;
    };
    _state set ["actionPending", true];
    _state set ["pendingAction", "CREATE"];
    _state set ["pendingAt", diag_tickTime];
    ["CREATE", player, _token, [_className, _position, _vectors, _snapTarget, _snapSide, _snapPoint, _state getOrDefault ["draftMode", false]]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
};