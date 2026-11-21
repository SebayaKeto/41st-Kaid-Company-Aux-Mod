/*
 * ACE medical menu overview additions. Runs on the viewer's machine from the
 * ace_medical_gui_updateInjuryListGeneral event.
 *  - "Receiving Radiation Flush [m:ss]" in the IV line (everyone sees it).
 *  - "Radiation Sickness: <level>" after Pain (detection device holders only).
 */
params ["_ctrl", "_target", "_selectionN", "_entries"];
if (!BUZZ_Radiation_enabled) exitWith {};

// Flush IV: replace "No IV", or sit just before the pain line after any real IVs.
private _flush = _target getVariable ["BUZZ_Radiation_flush", []];
if (_flush isNotEqualTo []) then {
    _flush params ["_start", "", "_fastTime", "", "_slowTime"];
    private _left = (_fastTime max _slowTime) - (CBA_missionTime - _start);
    if (_left > 0) then {
        private _entry = [format ["Receiving Radiation Flush [%1]", [_left, "MM:SS"] call BIS_fnc_secondsToString], [1, 1, 1, 1]];
        private _texts = _entries apply {_x select 0};
        private _noIv = _texts find localize "STR_ACE_Medical_Treatment_Status_NoIv";
        if (_noIv > -1) then {
            _entries set [_noIv, _entry];
        } else {
            private _pain = ["Status_NoPain", "Status_MildPain", "Status_Pain", "Status_SeverePain"] apply {localize ("STR_ACE_Medical_Treatment_" + _x)};
            private _idx = _texts findIf {_x in _pain};
            if (_idx > -1) then {_entries insert [_idx, [_entry]]} else {_entries pushBack _entry};
        };
    };
};

// Radiation Sickness level.
if (!BUZZ_Radiation_medicalMenu) exitWith {};
if !([ACE_player, BUZZ_Radiation_monitorList] call BUZZ_Radiation_fnc_hasItem) exitWith {};

private _dose = _target getVariable ["BUZZ_Radiation_dose", 0];
private _level = switch (true) do {
    case (_dose > BUZZ_Radiation_menuFatal):    {["Fatal",    [1, 0, 0, 1]]};
    case (_dose > BUZZ_Radiation_menuSevere):   {["Severe",   [1, 0.33, 0, 1]]};
    case (_dose > BUZZ_Radiation_menuModerate): {["Moderate", [1, 0.67, 0, 1]]};
    case (_dose > BUZZ_Radiation_menuMinor):    {["Minor",    [1, 1, 0, 1]]};
    default                                     {["None",     [1, 1, 1, 0.33]]};
};
_level params ["_name", "_color"];
_entries pushBack [format ["Radiation Sickness: %1", _name], _color];
