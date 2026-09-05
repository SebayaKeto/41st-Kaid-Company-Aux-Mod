/*
    FST_fnc_populateVehicleList
*/
private _display    = uiNamespace getVariable ["GUI_Display", displayNull];
private _listbox    = _display displayCtrl 9910;
private _searchBox  = _display displayCtrl 9985;
private _query      = toLower (ctrlText _searchBox);
private _activeVar  = uiNamespace getVariable ["GUI_ActiveListVar", "GUI_RotaryList"];
private _fullList   = missionNamespace getVariable [_activeVar, []];

lbClear _listbox;
private _idx = 0;
{
    if (_query == "" || { (toLower (_x select 0)) find _query >= 0 }) then {
        _listbox lbAdd (_x select 0);
        _listbox lbSetValue [_idx, _forEachIndex];
        _idx = _idx + 1;
    };
} forEach _fullList;
