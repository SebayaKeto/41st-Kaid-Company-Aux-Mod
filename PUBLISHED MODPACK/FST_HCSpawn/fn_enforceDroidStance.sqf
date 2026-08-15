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

    // Per-classname verdict cache: this sweep hits every local unit every 10s
    // on the server AND each HC, and the substring scans only depend on the
    // class. Deliberately narrower than fn_isDroidUnit (B1/B2 only) so BX and
    // commando droids keep their own AI stance behavior.
    private _class = typeOf _unit;
    private _cache = missionNamespace getVariable "FST_HC_StanceClassCache";
    if (isNil "_cache") then {
        _cache = createHashMap;
        missionNamespace setVariable ["FST_HC_StanceClassCache", _cache];
    };
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

    // setUnitPos is idempotent enough for a slow PFH and still allows movement.
    // It simply prevents the unit from choosing crouch/prone stances.
    _unit setUnitPos "UP";
    _fixed = _fixed + 1;
} forEach allUnits;

_fixed
