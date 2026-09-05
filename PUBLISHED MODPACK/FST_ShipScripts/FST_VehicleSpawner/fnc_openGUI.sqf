/*
    FST_fnc_openGUI
    Opens the Aircraft Spawn GUI dialog, initializing the vehicle/pad data on first use.
    Call with: call FST_fnc_openGUI;
*/
if (isNil {missionNamespace getVariable "GUI_PadList"}) then {
    call FST_fnc_initVehicleData;
};

private _padList      = missionNamespace getVariable ["GUI_PadList", []];
private _categoryList = missionNamespace getVariable ["GUI_CategoryList", []];
private _padCache     = missionNamespace getVariable ["GUI_PadCache", []];

createDialog "AircraftSpawnGUI";
uiSleep 0.1;

private _display    = findDisplay 9900;
private _padCombo   = _display displayCtrl 9951;
private _catCombo   = _display displayCtrl 9982;
private _listbox    = _display displayCtrl 9910;
private _searchBox  = _display displayCtrl 9985;

uiNamespace setVariable ["GUI_Display",  _display];
uiNamespace setVariable ["GUI_PadList",  _padList];
uiNamespace setVariable ["GUI_PadCache", _padCache];
{
    private _label = (_padList select _forEachIndex) select 0;
    if (isNull _x) then { _label = format ["%1  [NOT PLACED]", _label]; };
    _padCombo lbAdd _label;
    _padCombo lbSetValue [_forEachIndex, _forEachIndex];
} forEach _padCache;

{
    _catCombo lbAdd (_x select 0);
    _catCombo lbSetValue [_forEachIndex, _forEachIndex];
} forEach _categoryList;

private _playerPos  = getPosATL player;
private _closestIdx = 0;
private _closestDst = 1e10;
{
    if (!isNull _x) then {
        private _dst = _playerPos distance2D (getPosATL _x);
        if (_dst < _closestDst) then {
            _closestDst = _dst;
            _closestIdx = _forEachIndex;
        };
    };
} forEach _padCache;
_padCombo lbSetCurSel _closestIdx;
_catCombo  lbSetCurSel 0;

call FST_fnc_populateVehicleList;

_padCombo  ctrlAddEventHandler ["LBSelChanged", { call FST_fnc_updatePadCamera; }];
_catCombo  ctrlAddEventHandler ["LBSelChanged", { call FST_fnc_updateCategory; }];
_listbox   ctrlAddEventHandler ["LBSelChanged", { call FST_fnc_updateSelection; }];
_searchBox ctrlAddEventHandler ["KeyUp",        { call FST_fnc_populateVehicleList; }];

_display displayAddEventHandler ["Unload", { call FST_fnc_destroyPadCamera; }];

call FST_fnc_updatePadCamera;
