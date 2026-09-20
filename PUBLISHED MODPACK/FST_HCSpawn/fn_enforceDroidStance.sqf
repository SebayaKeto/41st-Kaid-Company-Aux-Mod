// FST_HCSpawn_fnc_enforceDroidStance
// Server/HC-local low-frequency stance keeper for B1/B2 droids.
// Prevents LAMBS/AI from leaving battle droids prone without interrupting movement.
// No doStop, no waypoint changes, no remoteExec.
//
// V27 performance/behavior:
// - Cheapest filters run first (local, alive) so remote units cost one check.
// - Only units whose stance rule is still AUTO are touched. Units already forced
//   UP by an earlier pass, by garrison/clone code, or deliberately set to another
//   stance by Zeus are skipped. This removes ~N setUnitPos calls per pass and
//   stops the keeper from overriding stances Zeus chose on purpose.

if (hasInterface && {!isServer}) exitWith {0};
if !(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) exitWith {0};

private _cache = missionNamespace getVariable "FST_HC_StanceClassCache";
if (isNil "_cache") then {
    _cache = createHashMap;
    missionNamespace setVariable ["FST_HC_StanceClassCache", _cache];
};

private _fixed = 0;
{
    private _unit = _x;
    if (!local _unit) then { continue };
    if (!alive _unit) then { continue };
    if (isPlayer _unit) then { continue };
    if !((side _unit) isEqualTo east) then { continue };

    // Per-classname verdict cache: this sweep hits every local unit every 10s
    // on the server AND each HC, and the substring scans only depend on the
    // class. Deliberately narrower than fn_isDroidUnit (B1/B2 only) so BX and
    // commando droids keep their own AI stance behavior.
    private _class = typeOf _unit;
    private _isDroid = _cache get _class;
    if (isNil "_isDroid") then {
        private _lc = toLowerANSI _class;
        _isDroid =
            ((_lc find "fst_droid_b1") >= 0) ||
            ((_lc find "fst_droid_b2") >= 0) ||
            ((_lc find "fst_b1") >= 0) ||
            ((_lc find "fst_b2") >= 0);
        _cache set [_class, _isDroid];
    };
    if (!_isDroid) then { continue };

    if !((vehicle _unit) isEqualTo _unit) then { continue };
    if ((unitPos _unit) != "AUTO") then { continue };

    // Forces standing but still allows movement: it only stops the unit from
    // choosing crouch/prone stances on its own.
    _unit setUnitPos "UP";
    _fixed = _fixed + 1;
} forEach allUnits;

_fixed
