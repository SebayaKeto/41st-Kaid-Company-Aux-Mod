// FST_zeusMed_fnc_scenarios
// [] call                -> scenario list: [[label, tooltip, playersOnly], ...]
// [unit, index] call     -> applies scenario <index> to a LOCAL unit, returns its label
// Damage inputs are kept below ACE's sum-of-trauma fatal range for player threshold 0.37 (head 0.46 / body 0.56 /
// limb 0.48 before any fatal chance), so a scenario wounds and drops people; it does not roll them a death.
// Knock-outs are explicit (setUnconscious) rather than left to damage thresholds, so AI (threshold 2.0) behave too.

#define SCENARIOS [ \
    ["Blaster burns (walking wounded)", "Plasma burns to arm and torso. Stays conscious; pain, little bleeding.", false, \
        [[0.3, "LeftArm", "plasma"], [0.2, "Body", "plasma"]], -1, -1, -1, false], \
    ["Shrapnel - bleeding out", "Grenade wounds to both legs and an arm, blood at 4.0 L, knocked out. Will not wake or take bacta until bandaged and given fluids (stable needs 5.1 L).", false, \
        [[0.4, "LeftLeg", "grenade"], [0.35, "RightLeg", "grenade"], [0.25, "RightArm", "grenade"]], 4.0, -1, 20, false], \
    ["Blast survivor", "Explosive wounds to torso, leg and head, heavy pain, knocked out.", false, \
        [[0.3, "Body", "explosive"], [0.45, "LeftLeg", "explosive"], [0.15, "Head", "explosive"]], -1, 0.7, 30, false], \
    ["Head trauma", "Single head wound, out for at least 60 s.", false, \
        [[0.2, "Head", "bullet"]], -1, -1, 60, false], \
    ["Critical - cardiac arrest (players only)", "Torso and leg shrapnel, blood at 3.8 L, then cardiac arrest. CPR, then fluids before they can wake.", true, \
        [[0.3, "Body", "grenade"], [0.4, "LeftLeg", "grenade"]], 3.8, -1, -1, true] \
]

if (_this isEqualTo []) exitWith { SCENARIOS apply { _x select [0, 3] } };

params ["_unit", "_index"];
private _s = SCENARIOS param [_index, []];
if (_s isEqualTo [] || {!local _unit}) exitWith { "none" };
_s params ["_label", "", "", "_wounds", "_blood", "_pain", "_knockout", "_arrest"];

{
    _x params ["_damage", "_part", "_type"];
    [_unit, _damage, _part, _type, objNull, [], true] call ace_medical_fnc_addDamageToUnit;
} forEach _wounds;
if (_blood >= 0) then { _unit setVariable ["ace_medical_bloodVolume", _blood, true]; };
if (_pain >= 0) then { [_unit, _pain - (_unit getVariable ["ace_medical_pain", 0])] call ace_medical_fnc_adjustPainLevel; };
if (_knockout >= 0) then { [_unit, true, _knockout, false] call ace_medical_fnc_setUnconscious; };
if (_arrest) then { ["ace_medical_FatalVitals", _unit] call CBA_fnc_localEvent; };
_label
