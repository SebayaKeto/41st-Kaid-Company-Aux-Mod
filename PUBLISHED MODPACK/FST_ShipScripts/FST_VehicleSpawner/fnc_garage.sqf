/*
    FST_fnc_garage
    Bound to the dialog's RECALL TO HANGAR button.
*/
private _display   = uiNamespace getVariable ["GUI_Display", displayNull];
private _statusLbl = _display displayCtrl 9856;
private _combo     = _display displayCtrl 9951;
private _selIdx    = lbCurSel _combo;
private _padList   = uiNamespace getVariable ["GUI_PadList", []];

if (_selIdx < 0 || _selIdx >= count _padList) exitWith {
    [_statusLbl, "> ERROR: NO TARGET PAD SELECTED.", [0.95, 0.80, 0.15, 1.0]] call FST_fnc_setStatus;
};

private _varName = (_padList select _selIdx) select 1;
private _padName = _combo lbText _selIdx;
private _pad     = (uiNamespace getVariable ["GUI_PadCache", []]) select _selIdx;

if (isNull _pad) exitWith {
    [_statusLbl, format ["> ERROR: PAD OBJECT '%1' NOT FOUND.", _varName], [0.95, 0.30, 0.30, 1.0]] call FST_fnc_setStatus;
};

// A vehicle may have been deployed from a different pad and flown/landed here,
// so search every pad's tracked vehicle for whichever one is actually near
// the selected pad rather than requiring it to match this pad's own key.
private _tracked      = objNull;
private _storeKey     = "";
private _bestDistance = 1e10;

{
    private _key  = format ["GUI_PadVehicle_%1", _x select 1];
    private _veh  = missionNamespace getVariable [_key, objNull];
    if (!isNull _veh && { alive _veh }) then {
        private _dist = _veh distance2D _pad;
        if (_dist <= 30 && { _dist < _bestDistance }) then {
            _tracked      = _veh;
            _storeKey     = _key;
            _bestDistance = _dist;
        };
    };
} forEach _padList;

if (isNull _tracked) exitWith {
    [_statusLbl, format ["> NO TRACKED UNIT WITHIN 30M OF %1.", _padName], [0.95, 0.80, 0.15, 1.0]] call FST_fnc_setStatus;
};

if (count crew _tracked > 0) exitWith {
    [_statusLbl, "> RECALL DENIED — EVACUATE ALL CREW FIRST.", [0.95, 0.55, 0.10, 1.0]] call FST_fnc_setStatus;
};

// isEngineOn isn't reliable on objects with no engine simulation at all
// (crates, static weapons/mortars in this same spawn list) — it can read
// as "on" by default rather than false, wrongly blocking their recall.
// Only enforce the power-down requirement on things that can actually
// have an engine.
private _hasEngine = _tracked isKindOf "Air" || _tracked isKindOf "LandVehicle" || _tracked isKindOf "Ship";
if (_hasEngine && { isEngineOn _tracked }) exitWith {
    [_statusLbl, "> RECALL DENIED — POWER DOWN ENGINE FIRST.", [0.95, 0.55, 0.10, 1.0]] call FST_fnc_setStatus;
};

missionNamespace setVariable [_storeKey, objNull];
[_tracked] remoteExec ["FST_fnc_recallVehicleServer", 2];
[_statusLbl, format ["> UNIT RECALLED FROM %1.", _padName], [0.20, 0.90, 0.30, 1.0]] call FST_fnc_setStatus;
