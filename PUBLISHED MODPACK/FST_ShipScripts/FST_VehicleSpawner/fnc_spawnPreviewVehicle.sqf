/*
    FST_fnc_spawnPreviewVehicle
*/
if (!hasInterface) exitWith {};
call FST_fnc_removePreviewVehicle;
private _className = uiNamespace getVariable ["GUI_SelectedClass", ""];
if (_className == "") exitWith {};
private _pad = call FST_fnc_getSelectedPad;
if (isNull _pad) exitWith {};

private _pos     = getPosATL _pad;
private _preview = _className createVehicleLocal _pos;
_preview setDir (getDir _pad);
_preview setPosATL _pos;
_preview allowDamage false;
_preview enableSimulation false;
{ deleteVehicle _x } forEach crew _preview;

uiNamespace setVariable ["GUI_PreviewVehicle", _preview];
