// FST_HCSpawn_fnc_enforceDroidStance
// Server/HC-local low-frequency stance keeper for B1/B2 droids.
// Prevents LAMBS/AI from leaving battle droids prone without interrupting movement.
// No doStop, no waypoint changes, no remoteExec.

if (hasInterface && {!isServer}) exitWith {0};
if !(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) exitWith {0};

private _fixed = 0;
{
    private _unit = _x;
    if (isNull _unit) then { continue };
    if (!alive _unit) then { continue };
    if !(local _unit) then { continue };
    if (isPlayer _unit) then { continue };
    if !(side group _unit isEqualTo east) then { continue };
    if !(vehicle _unit isEqualTo _unit) then { continue };

    private _class = toLowerANSI (typeOf _unit);
    private _isDroid =
        ((_class find "fst_droid_b1") >= 0) ||
        ((_class find "fst_droid_b2") >= 0) ||
        ((_class find "fst_b1") >= 0) ||
        ((_class find "fst_b2") >= 0);

    if (!_isDroid) then { continue };

    // setUnitPos is idempotent enough for a slow PFH and still allows movement.
    // It simply prevents the unit from choosing crouch/prone stances.
    _unit setUnitPos "UP";
    _fixed = _fixed + 1;
} forEach allUnits;

_fixed
