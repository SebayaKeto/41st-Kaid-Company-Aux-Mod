// FST_medOps_fnc_casualtyTick
// Local player, every 3 s: clear a call that is no longer needed.
//   "down"   -> cleared once conscious again and out of cardiac arrest (they can call again if still hurt)
//   "called" -> cleared once no longer injured (bandaged and healed)
//   any call -> cleared after 15 minutes

if (!hasInterface || {isNull player}) exitWith {};
private _call = player getVariable "FST_medOps_call";
if (isNil "_call") exitWith {};
_call params ["_reason", "_since"];
private _clear = switch (true) do {
    case (!alive player): { true };
    case (CBA_missionTime - _since > 900): { true };
    case (_reason == "down"): {
        !(player getVariable ["ACE_isUnconscious", false]) && {!(player getVariable ["ace_medical_inCardiacArrest", false])}
    };
    default { !([player] call ace_medical_fnc_isInjured) };
};
if (_clear) then { [player, false] call FST_medOps_fnc_setCall; };
