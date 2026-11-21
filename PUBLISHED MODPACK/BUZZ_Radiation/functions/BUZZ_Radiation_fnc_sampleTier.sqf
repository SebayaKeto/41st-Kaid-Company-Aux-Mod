/*
 * Radiation tier at a position from the active zones on this machine.
 * Returns -1 (none, or inside a safe zone), 0, 1 or 2, or 3 inside a decontamination zone.
 */
params ["_pos"];
private _tier = -1;
private _shielded = false;
private _decon = false;
{
    private _zoneTier = _x getVariable ["BUZZ_Radiation_tier", 1];
    if (((_x getVariable ["BUZZ_Radiation_areas", []]) findIf {_pos inArea _x}) > -1) then {
        if (_zoneTier == -1) then {_decon = true};
        if (_zoneTier < 0) then {_shielded = true} else {_tier = _tier max _zoneTier};
    };
} forEach (missionNamespace getVariable ["BUZZ_Radiation_activeZones", []]);
if (_decon) exitWith {3};
[_tier, -1] select _shielded
