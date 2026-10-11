// FST_zeusMed_fnc_plotArmorRestore
// Undo the while-down damage-threshold raise (plotArmorTick), restoring any mission-set value exactly.
// Arguments: 0: unit

params ["_unit"];
private _prev = _unit getVariable "FST_zeusMed_paPrevThreshold";
if (isNil "_prev") exitWith {};
if (_prev isEqualTo []) then {
    _unit setVariable ["ace_medical_damageThreshold", nil, true];
} else {
    _unit setVariable ["ace_medical_damageThreshold", _prev select 0, true];
};
_unit setVariable ["FST_zeusMed_paPrevThreshold", nil, true];
