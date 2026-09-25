private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (
    count _state == 0
    || {_state getOrDefault ["actionPending", false]}
    || {_state getOrDefault ["paletteWheelOpen", false]}
) exitWith {};

if ((_state getOrDefault ["mode", "PLACE"]) isEqualTo "EDIT") exitWith
{
    call MEAP_fnc_architectApplyAction;
};

private _target = _state getOrDefault ["target", objNull];
if (!isNull _target) exitWith
{
    call MEAP_fnc_architectSelectEdit;
};

call MEAP_fnc_architectApplyAction;