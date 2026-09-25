private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {_state getOrDefault ["actionPending", false]}) exitWith {};

private _target = _state getOrDefault ["selected", objNull];
if (isNull _target) then
{
    _target = _state getOrDefault ["target", objNull];
};
if (isNull _target) exitWith {};

_state set ["actionPending", true];
_state set ["pendingAction", "DELETE"];
_state set ["pendingObject", _target];
_state set ["pendingAt", diag_tickTime];
["DELETE", player, _state get "token", [_target]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
