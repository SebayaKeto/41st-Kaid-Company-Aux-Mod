// FST_zeusMed_fnc_plotArmorTick
// Every machine, every second: keep Plot Armor working on units local to it (see plotArmorLocal).
// Also refreshes FST_zeusMed_armoredLocal, which the fast (0.2 s) vitals handler in postInit walks.
// NOTE (engine test 10 Oct): never block ACE damage (ace_medical_allowDamage false) here. If ACE decides the unit dies,
// its setDead kills via hit-point damage; blocking it leaves an alive unit in ACE's "Dead" state (ACE #8803).
// While down we raise the per-unit damage threshold instead: ACE's sum-of-trauma fatal roll scales with it, and the
// knock-down use of the same threshold no longer matters once the unit is unconscious.

private _armored = [];
{
    if (local _x && {_x getVariable ["FST_zeusMed_plotArmor", false]}) then {
        _armored pushBack _x;
        // re-assert the local-only flags (lost on locality change)
        _x setVariable ["ace_medical_deathBlocked", true];
        _x setVariable ["ace_medical_statemachine_AIUnconsciousness", true];
        if (_x getVariable ["ACE_isUnconscious", false]) then {
            if (isNil { _x getVariable "FST_zeusMed_paPrevThreshold" }) then {
                // remember any mission-set threshold as [value] or [] so it can be restored exactly
                private _prev = _x getVariable "ace_medical_damageThreshold";
                _x setVariable ["FST_zeusMed_paPrevThreshold", [[], [_prev]] select !isNil "_prev", true];
                _x setVariable ["ace_medical_damageThreshold", 1000, true];
            };
        } else {
            [_x] call FST_zeusMed_fnc_plotArmorRestore;
        };
        if (_x getVariable ["ace_medical_inCardiacArrest", false]) then {
            _x setVariable ["ace_medical_statemachine_cardiacArrestTimeLeft",
                missionNamespace getVariable ["ace_medical_statemachine_cardiacArrestTime", 300]];
        };
    };
} forEach allUnits;
FST_zeusMed_armoredLocal = _armored;
