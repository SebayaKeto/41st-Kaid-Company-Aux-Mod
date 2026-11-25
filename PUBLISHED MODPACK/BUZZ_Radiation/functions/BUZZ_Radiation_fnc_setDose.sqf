// Sets a unit's absorbed dose
params [["_unit", objNull, [objNull]], ["_dose", 0, [0]], ["_sickRate", -1, [0]]];
if (isNull _unit) exitWith {};
if (!local _unit) exitWith {["BUZZ_Radiation_setDoseLocal", [_unit, _dose, _sickRate], _unit] call CBA_fnc_targetEvent};
_dose = 0 max _dose min 100;
_unit setVariable ["BUZZ_Radiation_dose", _dose, true];
_unit setVariable ["BUZZ_Radiation_dosePub", _dose];
if (_sickRate >= 0) then {_unit setVariable ["BUZZ_Radiation_sickRate", _sickRate, true]};
if (_dose <= 0) then {
    _unit setVariable ["BUZZ_Radiation_sickRate", 0, true];
    _unit setVariable ["BUZZ_Radiation_treatedUntil", -1, true];
};
