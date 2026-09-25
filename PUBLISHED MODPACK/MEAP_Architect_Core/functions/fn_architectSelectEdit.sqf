private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {_state getOrDefault ["actionPending", false]}) exitWith {};

private _target = _state getOrDefault ["target", objNull];
if (isNull _target) exitWith {};

private _selected = _state getOrDefault ["selected", objNull];
if (!isNull _selected) then
{
    _selected hideObject false;
    ["UNLOCK", player, _state get "token", [_selected]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
    _state set ["selected", objNull];
};

_state set ["actionPending", true];
_state set ["pendingAction", "LOCK"];
_state set ["pendingObject", _target];
_state set ["pendingAt", diag_tickTime];
["LOCK", player, _state get "token", [_target]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];