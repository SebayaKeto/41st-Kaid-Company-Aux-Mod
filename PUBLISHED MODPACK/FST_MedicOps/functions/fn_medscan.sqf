// FST_medOps_fnc_medscan
// Medscanner readout for a unit (reads ACE's broadcast vars). Returns structured text; [unit, true] call ... shows it.
// Recommends the field-medicine item per wound type: deep -> Coagulant Foam, surface -> Kolto Wrap, burns/crush ->
// Synthflesh Sheet.

params ["_u", ["_show", false]];
private _sev = [_u] call FST_medOps_fnc_severity;
private _blood = _u getVariable ["ace_medical_bloodVolume", 6];
private _hr = round (_u getVariable ["ace_medical_heartRate", 80]);
private _bp = _u getVariable ["ace_medical_bloodPressure", [80, 120]];
private _bleed = _u getVariable ["ace_medical_woundBleeding", 0];
private _internal = (_u getVariable ["FST_medOps_internal", 0]) > 0;
private _names = missionNamespace getVariable ["ace_medical_damage_woundClassNames", []];
private _item = createHashMapFromArray [
    ["Avulsion", "Coagulant Foam"], ["VelocityWound", "Coagulant Foam"], ["PunctureWound", "Coagulant Foam"],
    ["Laceration", "Kolto Wrap / Foam"], ["Abrasion", "Kolto Wrap"], ["Cut", "Kolto Wrap"],
    ["ThermalBurn", "Synthflesh Sheet"], ["Crush", "Synthflesh Sheet"], ["Contusion", "-"]
];
private _parts = ["Head", "Torso", "Left arm", "Right arm", "Left leg", "Right leg"];
private _lines = [];
{
    private _part = _x;
    private _idx = ["head", "body", "leftarm", "rightarm", "leftleg", "rightleg"] find _part;
    private _byType = createHashMap;
    { _x params ["_cid", "_amt"]; if (_amt > 0) then { private _t = _names param [floor (_cid / 10), "?"]; _byType set [_t, (_byType getOrDefault [_t, 0]) + _amt]; }; } forEach _y;
    if (count _byType > 0) then {
        private _desc = [];
        { _desc pushBack format ["%1 %2 (%3)", ceil _y, _x, _item getOrDefault [_x, "-"]]; } forEach _byType;
        _lines pushBack format ["<t color='#9fb4c8'>%1:</t> %2", _parts select _idx, _desc joinString ", "];
    };
} forEach (_u getVariable ["ace_medical_openWounds", createHashMap]);
private _text = format [
    "<t size='1.15'>Medscan: %1</t><br/><t color='%2'>%3</t><br/>Blood %4 L | HR %5 | BP %6/%7 | bleeding %8<br/>%9%10",
    name _u, _sev select 4, _sev select 1, _blood toFixed 1, _hr, round (_bp select 1), round (_bp select 0),
    ["none", "<t color='#ffb030'>YES</t>"] select (_bleed > 0),
    ["", "<t color='#ff6060'>INTERNAL BLEEDING: seal with Coagulant Foam (medic, torso)</t><br/>"] select _internal,
    if (_lines isEqualTo []) then { "No open wounds" } else { _lines joinString "<br/>" }
];
if (_show) then { hint parseText _text; };
_text
