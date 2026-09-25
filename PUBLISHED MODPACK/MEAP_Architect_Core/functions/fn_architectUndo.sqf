private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (
	count _state == 0
	|| {_state getOrDefault ["actionPending", false]}
	|| {(_state get "mode") isEqualTo "EDIT"}
) exitWith {};

_state set ["actionPending", true];
_state set ["pendingAction", "UNDO"];
["UNDO", player, _state get "token", []] remoteExecCall ["MEAP_fnc_architectServerAction", 2];