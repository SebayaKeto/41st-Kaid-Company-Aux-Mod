// FST_medOps_fnc_joltTick
// Every machine, every 2 s, for LOCAL jolted units: when the 90 s run out, a patient who was stabilised in the
// meantime (bleeding stopped and stable vitals, e.g. bandaged or bacta'd) is fine; otherwise they crash:
// knocked out for at least 60 s with extra pain. Bacta's full heal also clears the jolt (no crash).

{
    private _until = _x getVariable ["FST_medOps_jolt", -1];
    if (_until > 0 && {local _x} && {CBA_missionTime >= _until}) then {
        _x setVariable ["FST_medOps_jolt", -1, true];
        if (alive _x) then {
            private _stable = ((_x getVariable ["ace_medical_woundBleeding", 0]) == 0) && {[_x] call ace_medical_status_fnc_hasStableVitals};
            if (_stable) then {
                if (hasInterface && {_x == player}) then { titleText ["<t color='#9fe0a0'>The jolt wears off. You were patched up in time.</t>", "PLAIN DOWN", 0.5, true, true]; };
            } else {
                [_x, 0.5] call ace_medical_fnc_adjustPainLevel;
                [_x, true, 60, false] call ace_medical_fnc_setUnconscious;
                if (hasInterface && {_x == player}) then { titleText ["<t color='#ff7060'>You crash.</t>", "PLAIN", 0.4, true, true]; };
                diag_log text format ["FST_medOps: adrenal crash | %1", name _x];
            };
        };
    };
} forEach allUnits;
