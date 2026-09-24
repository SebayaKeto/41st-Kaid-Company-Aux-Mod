private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {};

_state set ["zones", []];
["Private construction zones cleared."] call MEAP_fnc_architectMessage;