/*
    FST_fnc_updateSelection
*/
private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
private _listbox     = _display displayCtrl 9910;
private _selIdx      = lbCurSel _listbox;
if (_selIdx < 0) exitWith {};
private _origIdx     = _listbox lbValue _selIdx;
private _activeVar   = uiNamespace getVariable ["GUI_ActiveListVar", "GUI_RotaryList"];
private _list        = missionNamespace getVariable [_activeVar, []];
private _entry       = _list select _origIdx;
uiNamespace setVariable ["GUI_SelectedClass", _entry select 1];
uiNamespace setVariable ["GUI_SelectedName",  _entry select 0];
private _selectedLbl = _display displayCtrl 9856;
_selectedLbl ctrlSetText format ["> %1", _entry select 0];
_selectedLbl ctrlSetTextColor [0.25, 0.95, 0.35, 1.0];
_selectedLbl ctrlCommit 0;
call FST_fnc_spawnPreviewVehicle;
