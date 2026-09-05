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

private _preview      = uiNamespace getVariable ["GUI_PreviewVehicle", objNull];
private _nearVehicles = (getPosASL _pad) nearEntities [["LandVehicle", "Air", "Ship"], 10];
_nearVehicles = _nearVehicles select { alive _x && _x != _preview };

if (count _nearVehicles == 0) exitWith {
    [_statusLbl, format ["> NO UNITS DETECTED WITHIN 10M OF %1.", _padName], [0.95, 0.80, 0.15, 1.0]] call FST_fnc_setStatus;
};

private _stored      = 0;
private _crewBlocked = 0;

{
    if (count crew _x > 0) then {
        _crewBlocked = _crewBlocked + 1;
    } else {
        private _storeKey = format ["GUI_PadVehicle_%1", _varName];
        private _tracked  = missionNamespace getVariable [_storeKey, objNull];
        if (!isNull _tracked && { _tracked == _x }) then {
            missionNamespace setVariable [_storeKey, objNull];
        };
        _x remoteExec ["deleteVehicle", 2];
        _stored = _stored + 1;
    };
} forEach _nearVehicles;

if (_stored > 0 && _crewBlocked == 0) then {
    [_statusLbl, format ["> %1 UNIT(S) RECALLED FROM %2.", _stored, _padName], [0.20, 0.90, 0.30, 1.0]] call FST_fnc_setStatus;
};
if (_stored > 0 && _crewBlocked > 0) then {
    [_statusLbl, format ["> %1 RECALLED. %2 SKIPPED — CREW STILL ABOARD.", _stored, _crewBlocked], [0.95, 0.75, 0.15, 1.0]] call FST_fnc_setStatus;
};
if (_stored == 0 && _crewBlocked > 0) then {
    [_statusLbl, "> RECALL DENIED — EVACUATE ALL CREW FIRST.", [0.95, 0.55, 0.10, 1.0]] call FST_fnc_setStatus;
};
