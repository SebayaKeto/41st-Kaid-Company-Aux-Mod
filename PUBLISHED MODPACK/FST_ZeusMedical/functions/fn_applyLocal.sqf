// FST_zeusMed_fnc_applyLocal
// Runs where the unit is local (CBA target event "FST_zeusMed_apply").
// Arguments: 0: unit, 1: action <STRING>, 2: action args, 3: Zeus client owner for feedback <NUMBER>
//   "wound"    [[damage, bodyPart, damageType], ...]   -> ace_medical_fnc_addDamageToUnit per hit
//   "blood"    litres                                  -> ace_medical_bloodVolume
//   "pain"     target pain 0..1                        -> ace_medical_fnc_adjustPainLevel (by the difference)
//   "knockout" minimum seconds                         -> ace_medical_fnc_setUnconscious
//   "arrest"   nil                                     -> ACE event ace_medical_FatalVitals (cardiac arrest)
//   "scenario" index                                   -> FST_zeusMed_fnc_scenarios

params ["_unit", "_action", "_args", ["_zeus", -1]];

private _reply = {
    params ["_msg"];
    diag_log text format ["FST_zeusMed: %1 | %2 (%3) | zeus owner %4", _msg, name _unit, typeOf _unit, _zeus];
    if (_zeus > 0) then { ["FST_zeusMed_feedback", [_msg], _zeus] call CBA_fnc_ownerEvent; };
};

if (isNull _unit || {!alive _unit}) exitWith { ["41st Medical: unit gone or dead, nothing applied"] call _reply; };
if (!local _unit) exitWith {
    // locality moved while the event was in flight (HC transfer): forward it to the new owner
    ["FST_zeusMed_apply", _this, _unit] call CBA_fnc_targetEvent;
};
if !(missionNamespace getVariable ["FST_zeusMed_enabled", true]) exitWith { ["41st Medical: disabled (FST_zeusMed_enabled)"] call _reply; };

if (!(_unit getVariable ["ace_medical_medicalActivity", missionNamespace getVariable ["ace_medical_const_medicalActivity", true]])) then {
    ["ace_medical_activateMedical", _unit] call CBA_fnc_localEvent;
};

switch (_action) do {
    case "wound": {
        private _n = 0;
        {
            _x params ["_damage", "_part", "_type"];
            if ([_unit, _damage, _part, _type, objNull, [], true] call ace_medical_fnc_addDamageToUnit) then { _n = _n + 1; };
        } forEach _args;
        [format ["41st Medical: %1 of %2 wound(s) applied", _n, count _args]] call _reply;
    };
    case "blood": {
        private _litres = (_args max 0) min 6;
        if (_unit getVariable ["FST_zeusMed_plotArmor", false]) then { _litres = _litres max FST_zeusMed_bloodFloor; };
        _unit setVariable ["ace_medical_bloodVolume", _litres, true];
        [format ["41st Medical: blood volume set to %1 L%2", _litres,
            ["", " (Plot Armor floor)"] select (_litres > ((_args max 0) min 6))]] call _reply;
    };
    case "pain": {
        private _now = _unit getVariable ["ace_medical_pain", 0];
        [_unit, ((_args max 0) min 1) - _now] call ace_medical_fnc_adjustPainLevel;
        [format ["41st Medical: pain %1 -> %2", _now toFixed 2, (_args max 0) min 1]] call _reply;
    };
    case "knockout": {
        [_unit, true, _args, false] call ace_medical_fnc_setUnconscious;
        [format ["41st Medical: knocked out (at least %1 s)", _args]] call _reply;
    };
    case "arrest": {
        ["ace_medical_FatalVitals", _unit] call CBA_fnc_localEvent;
        ["41st Medical: cardiac arrest triggered"] call _reply;
    };
    case "scenario": {
        private _label = [_unit, _args] call FST_zeusMed_fnc_scenarios;
        [format ["41st Medical: scenario applied - %1", _label]] call _reply;
    };
    default { [format ["41st Medical: unknown action %1", _action]] call _reply; };
};
