/*
 * ACE "Scan For Radiation" callback (runs on the medic's machine).
 */
params ["_medic", "_patient"];
private _dose = _patient getVariable ["BUZZ_Radiation_dose", 0];
private _treatLeft = (_patient getVariable ["BUZZ_Radiation_treatedUntil", -1]) - CBA_missionTime;
([_dose] call BUZZ_Radiation_fnc_describeDose) params ["_sev", "_col"];

private _text = format [
    "<t size='1.1'>Radiation scan: %1</t><br/><t color='%2' size='1.3'>%3</t><br/>Absorbed dose: %4%5",
    name _patient, _col, _sev, round _dose, "%"
];
if (_treatLeft > 0) then {
    _text = _text + format ["<br/><t color='#59b4ff'>Iodine active: %1</t>", [_treatLeft, "MM:SS"] call BIS_fnc_secondsToString];
};
hintSilent parseText _text;
