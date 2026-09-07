/*
    FST_fnc_spawnVehicle
*/
private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
private _statusLbl   = _display displayCtrl 9856;
private _className   = uiNamespace getVariable ["GUI_SelectedClass", ""];
private _displayName = uiNamespace getVariable ["GUI_SelectedName",  ""];

if (_className == "") exitWith {
    [_statusLbl, "> ERROR: NO UNIT SELECTED.", [0.95, 0.30, 0.30, 1.0]] call FST_fnc_setStatus;
};

private _pad = call FST_fnc_getSelectedPad;

if (isNull _pad) exitWith {
    private _combo   = _display displayCtrl 9951;
    private _selIdx  = lbCurSel _combo;
    private _padList = uiNamespace getVariable ["GUI_PadList", []];
    private _varName = if (_selIdx >= 0) then { (_padList select _selIdx) select 1 } else { "unknown" };
    [_statusLbl, format ["> ERROR: PAD OBJECT '%1' NOT FOUND.", _varName], [0.95, 0.30, 0.30, 1.0]] call FST_fnc_setStatus;
};

if !([_pad, _statusLbl] call FST_fnc_isPadClear) exitWith {};

private _pos     = getPosATL _pad;
private _dir     = getDir _pad;

private _combo   = _display displayCtrl 9951;
private _selIdx  = lbCurSel _combo;
private _padList = uiNamespace getVariable ["GUI_PadList", []];
private _varName = (_padList select _selIdx) select 1;
private _padName = _combo lbText _selIdx;

call FST_fnc_removePreviewVehicle;
[_className, _pos, _dir, format ["GUI_PadVehicle_%1", _varName]] remoteExec ["FST_fnc_serverSpawnVehicle", 2];
[_statusLbl, format ["> DEPLOYED: %1 ON %2.", _displayName, _padName], [0.20, 0.90, 0.30, 1.0]] call FST_fnc_setStatus;
