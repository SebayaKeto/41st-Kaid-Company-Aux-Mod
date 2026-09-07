/*
    FST_fnc_getSelectedPad
    Returns the pad object currently selected in the pad combo box.
*/
private _display  = uiNamespace getVariable ["GUI_Display", displayNull];
private _combo    = _display displayCtrl 9951;
private _selIdx   = lbCurSel _combo;
private _padCache = uiNamespace getVariable ["GUI_PadCache", []];
if (_selIdx < 0 || _selIdx >= count _padCache) exitWith { objNull };
_padCache select _selIdx
