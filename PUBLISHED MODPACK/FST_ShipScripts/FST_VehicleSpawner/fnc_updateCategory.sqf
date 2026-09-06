/*
    FST_fnc_updateCategory
*/
private _display     = uiNamespace getVariable ["GUI_Display", displayNull];
private _catCombo    = _display displayCtrl 9982;
private _selIdx      = lbCurSel _catCombo;
private _catList     = missionNamespace getVariable ["GUI_CategoryList", []];
if (_selIdx < 0 || _selIdx >= count _catList) exitWith {};
private _entry       = _catList select _selIdx;
uiNamespace setVariable ["GUI_ActiveListVar", _entry select 1];
call FST_fnc_removePreviewVehicle;
private _searchBox   = _display displayCtrl 9985;
_searchBox ctrlSetText "";
call FST_fnc_populateVehicleList;
