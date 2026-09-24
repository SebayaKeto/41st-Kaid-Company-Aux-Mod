
params [["_notifyServer", true, [true]]];

if (isRemoteExecuted && {remoteExecutedOwner != 2}) exitWith {};
if (!hasInterface || {!(missionNamespace getVariable ["MEAP_Architect_cameraOpen", false])}) exitWith {};

MEAP_Architect_cameraOpen = false;
private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
call MEAP_fnc_closeArchitectPaletteWheel;
private _selected = _state getOrDefault ["selected", objNull];
if (!isNull _selected) then
{
    _selected hideObject false;
};

private _ghost = _state getOrDefault ["ghost", objNull];
if (!isNull _ghost) then
{
    deleteVehicle _ghost;
};

private _camera = _state getOrDefault ["camera", objNull];
if (!isNull _camera) then
{
    _camera cameraEffect ["TERMINATE", "BACK"];
    camDestroy _camera;
};

private _pfh = missionNamespace getVariable ["MEAP_Architect_cameraPFH", -1];
if (_pfh >= 0) then
{
    [_pfh] call CBA_fnc_removePerFrameHandler;
};

private _radiusDrawHandler = missionNamespace getVariable ["MEAP_Architect_radiusDrawHandler", -1];
if (_radiusDrawHandler >= 0) then
{
    removeMissionEventHandler ["Draw3D", _radiusDrawHandler];
};

private _display = _state getOrDefault ["display", displayNull];
if (!isNull _display) then
{
    _display closeDisplay 2;
};

private _token = _state getOrDefault ["token", ""];
if (_notifyServer && {_token isNotEqualTo ""} && {!isNull player}) then
{
    [player, false] remoteExecCall ["MEAP_fnc_closeArchitectMode", 2];
};

MEAP_Architect_cameraPFH = -1;
MEAP_Architect_radiusDrawHandler = -1;
MEAP_Architect_cameraState = nil;