// Refreshes the text rows of every open Radiation Monitor panel
params [["_hasDevice", false]];
private _displays = (uiNamespace getVariable ["BUZZ_Radiation_monitorDisplays", []]) select {!isNull _x};
uiNamespace setVariable ["BUZZ_Radiation_monitorDisplays", _displays];
if (_displays isEqualTo []) exitWith {};

// Vanilla HUD colours
private _text = [
    profileNamespace getVariable ["IGUI_TEXT_RGB_R", 1],
    profileNamespace getVariable ["IGUI_TEXT_RGB_G", 1],
    profileNamespace getVariable ["IGUI_TEXT_RGB_B", 1],
    profileNamespace getVariable ["IGUI_TEXT_RGB_A", 0.8]
];
private _warn = [
    profileNamespace getVariable ["IGUI_WARNING_RGB_R", 0.8],
    profileNamespace getVariable ["IGUI_WARNING_RGB_G", 0.5],
    profileNamespace getVariable ["IGUI_WARNING_RGB_B", 0],
    profileNamespace getVariable ["IGUI_WARNING_RGB_A", 0.8]
];
private _error = [
    profileNamespace getVariable ["IGUI_ERROR_RGB_R", 0.8],
    profileNamespace getVariable ["IGUI_ERROR_RGB_G", 0],
    profileNamespace getVariable ["IGUI_ERROR_RGB_B", 0],
    profileNamespace getVariable ["IGUI_ERROR_RGB_A", 0.8]
];

(player getVariable ["BUZZ_Radiation_exposure", [-1, false, false]]) params ["_tier", "_safe", "_decon"];
private _dose = player getVariable ["BUZZ_Radiation_dose", 0];
private _treatLeft = (player getVariable ["BUZZ_Radiation_treatedUntil", -1]) - CBA_missionTime;
private _gear = player getVariable ["BUZZ_Radiation_gear", 0];

{
    private _field = _x displayCtrl 1002;
    private _doseValue = _x displayCtrl 1004;
    private _bar = _x displayCtrl 1005;
    private _suit = _x displayCtrl 1006;
    private _iodine = _x displayCtrl 1007;

    if (!_hasDevice) then {
        _field ctrlSetText "NO SENSOR";
        _field ctrlSetTextColor _error;
        {_x ctrlSetText "-"; _x ctrlSetTextColor _text} forEach [_doseValue, _suit, _iodine];
        _bar progressSetPosition 0;
    } else {
        private _fieldInfo = switch (true) do {
            case (_decon):     {["DECON", [0.2, 0.85, 0.3, 1], 0.01]};
            case (_safe):      {["SHIELDED", _text, 0.01]};
            case (_tier == 0): {["BACKGROUND", _warn, 0.35]};
            case (_tier == 1): {["DANGEROUS", _warn, 48]};
            case (_tier == 2): {["LETHAL", _error, 1250]};
            default            {["NOMINAL", _text, 0.002]};
        };
        _fieldInfo params ["_label", "_col", "_base"];
        private _reading = _base * (0.9 + random 0.2);
        _field ctrlSetText format ["%1  %2 Sv/h", _label, [_reading toFixed 3, _reading toFixed 1] select (_reading >= 10)];
        _field ctrlSetTextColor _col;

        private _doseCol = switch (true) do {
            case (_dose >= 50): {_error};
            case (_dose >= 10): {_warn};
            default {_text};
        };
        _doseValue ctrlSetText format ["%1 %2  %3", round _dose, "%", ([_dose] call BUZZ_Radiation_fnc_describeDose) select 0];
        _doseValue ctrlSetTextColor _doseCol;
        _bar progressSetPosition (_dose / 100);
        _bar ctrlSetTextColor _doseCol;

        _suit ctrlSetText (["UNSEALED", "PARTIAL", "SEALED"] select _gear);
        _suit ctrlSetTextColor ([_warn, _warn, _text] select _gear);

        _iodine ctrlSetText ([ "-", [_treatLeft, "MM:SS"] call BIS_fnc_secondsToString] select (_treatLeft > 0));
        _iodine ctrlSetTextColor _text;
    };
} forEach _displays;
