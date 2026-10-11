// FST_medOps_fnc_internalTick
// Every machine, every 2 s: drain blood from LOCAL units with internal bleeding. The drain survives bacta (ACE's full
// heal resets blood, the bleed keeps going) until a medic seals it. Stops in cardiac arrest (no circulation) and at
// ACE's bleed-out line, where ACE takes over.

{
    private _rate = _x getVariable ["FST_medOps_internal", 0];
    if (_rate > 0 && {local _x} && {alive _x} && {!(_x getVariable ["ace_medical_inCardiacArrest", false])}) then {
        private _v = _x getVariable ["ace_medical_bloodVolume", 6];
        if (_v > 3.0) then { _x setVariable ["ace_medical_bloodVolume", (_v - _rate * 2) max 3.0, true]; };
    };
} forEach allUnits;
