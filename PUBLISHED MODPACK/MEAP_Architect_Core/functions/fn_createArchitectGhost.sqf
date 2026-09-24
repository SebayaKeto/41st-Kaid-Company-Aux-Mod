params [["_className", "", [""]]];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
private _oldGhost = _state getOrDefault ["ghost", objNull];
if (!isNull _oldGhost) then
{
    deleteVehicle _oldGhost;
};

if (_className isEqualTo "") exitWith
{
    _state set ["ghost", objNull];
    _state set ["previewActive", false];
    _state set ["snapCategory", ""];
    _state set ["compatibleSnapSlots", []];
    objNull
};

private _ghost = createVehicleLocal [_className, [0, 0, 1000], [], 0, "CAN_COLLIDE"];
if (isNull _ghost) exitWith
{
    _state set ["ghost", objNull];
    _state set ["previewActive", false];
    objNull
};
_ghost enableSimulation false;
_ghost allowDamage false;
_ghost hideObject true;
_state set ["ghost", _ghost];
_state set ["previewActive", true];

private _snapCategory = [_className] call MEAP_fnc_getSnapCategory;
private _memoryNames = (_ghost selectionNames "Memory") apply {toLower _x};
if (!("meap_snappoint_bottom" in _memoryNames)) then {_snapCategory = "";};
_state set ["snapCategory", _snapCategory];
_state set ["compatibleSnapSlots", []];
_state set ["nextSnapSlotScan", 0];
_state set ["snapPoint", ""];
if ((_state getOrDefault ["snapSide", ""]) isEqualTo "Slot" && {_snapCategory isEqualTo ""}) then
{
    _state set ["snapSide", ""];
};
private _display = _state getOrDefault ["display", displayNull];
if (!isNull _display) then
{
    private _snapSide = _state getOrDefault ["snapSide", ""];
    (_display displayCtrl 8817) ctrlSetText format ["SNAP %1", [toUpper _snapSide, "OFF"] select (_snapSide isEqualTo "")];
};
_ghost