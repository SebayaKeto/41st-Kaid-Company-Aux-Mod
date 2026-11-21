/*
 * Which active zones contain the unit.
 * Returns [highest radiation tier (-1 = none), inSafeZone, inDeconZone]
 */
params ["_unit", "_zones"];
private _tier = -1;
private _safe = false;
private _decon = false;
{
    private _zoneTier = _x getVariable ["BUZZ_Radiation_tier", 1];
    if (((_x getVariable ["BUZZ_Radiation_areas", []]) findIf {_unit inArea _x}) > -1) then {
        switch (_zoneTier) do {
            case -2: {_safe = true};
            case -1: {_decon = true};
            default {_tier = _tier max _zoneTier};
        };
    };
} forEach _zones;
[_tier, _safe, _decon]
