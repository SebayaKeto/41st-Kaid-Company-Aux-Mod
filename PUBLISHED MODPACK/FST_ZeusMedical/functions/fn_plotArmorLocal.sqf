// FST_zeusMed_fnc_plotArmorLocal
// Runs where the unit is local (CBA target event "FST_zeusMed_plotArmor"); also called directly by spawnCasualty.
// Plot Armor = the unit can be wounded and knocked down but should not die while it is on:
//   - ace_medical_deathBlocked: no "execution" death from a fatal injury during cardiac arrest
//   - ace_medical_statemachine_AIUnconsciousness (unit override): AI stay unconscious instead of dying
//   - plotArmorTick, every second: while down, per-unit damage threshold raised (no sum-of-trauma fatal roll);
//     cardiac-arrest timer held full
//   - postInit fast handler, every 0.2 s: blood floor 3.7 L (ACE: < 3.6 L Class IV = cardiac arrest) and heart rate
//     kept inside 45-190 while down (ACE: < 20 / > 220, or < 30 by chance, = cardiac arrest)
// Limits: an AI can still die from a fatal injury BEFORE it is downed (fatalInjuriesAI), and an AI that still reaches
// cardiac arrest dies at once while the server's ACE "AI unconsciousness" setting is off (players survive: CPR).
// Arguments: 0: unit, 1: on <BOOL>, 2: Zeus owner for feedback <NUMBER>

params ["_unit", "_on", ["_zeus", -1]];
if (isNull _unit) exitWith {};
if (!local _unit) exitWith { ["FST_zeusMed_plotArmor", _this, _unit] call CBA_fnc_targetEvent; };

_unit setVariable ["FST_zeusMed_plotArmor", _on, true];
if (_on) then {
    // join the fast list now, not at the next 1 s tick
    FST_zeusMed_armoredLocal pushBackUnique _unit;
    if ((_unit getVariable ["ace_medical_bloodVolume", 6]) < FST_zeusMed_bloodFloor) then {
        _unit setVariable ["ace_medical_bloodVolume", FST_zeusMed_bloodFloor, true];
    };
} else {
    FST_zeusMed_armoredLocal = FST_zeusMed_armoredLocal - [_unit];
    [_unit] call FST_zeusMed_fnc_plotArmorRestore;
};
_unit setVariable ["ace_medical_deathBlocked", _on];
_unit setVariable ["ace_medical_statemachine_AIUnconsciousness", [nil, true] select _on];
private _msg = format ["41st Medical: Plot Armor %1 - %2", ["OFF", "ON"] select _on, name _unit];
diag_log text format ["FST_zeusMed: %1 | zeus owner %2", _msg, _zeus];
if (_zeus > 0) then { ["FST_zeusMed_feedback", [_msg], _zeus] call CBA_fnc_ownerEvent; };
