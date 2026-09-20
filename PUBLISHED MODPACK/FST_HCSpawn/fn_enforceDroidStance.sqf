// FST_HCSpawn_fnc_enforceDroidStance
// Server/HC-local stance keeper for B1/B2 droids: battle droids never crouch or
// go prone. This is the only stance system in the modpack (FST_DroidStance was
// retired and folded in here), so it has to match what that addon did:
//
// - LAMBS and the vanilla FSM set stances with setUnitPos ("DOWN"/"MIDDLE"),
//   so the unitPos rule alone says nothing about what the droid is doing.
//   Decide on the real posture (stance) and re-force UP whenever it is not
//   STAND, plus setUnitPosWeak so the AI's own weak request cannot win.
// - Most stance changes show up as animation changes, so each local droid gets
//   an AnimChanged handler that re-forces immediately instead of waiting for
//   the next sweep. Hooked once per machine (non-broadcast variable) and
//   re-hooked by the sweep after a locality transfer.
// - B2s additionally get the LAMBS opt-outs and the COVER/SUPPRESSION/
//   AUTOCOMBAT AI features disabled (arguments-local, so reapplied per owner).
//
// V27.1 (2026-09-20): the first V27 cut skipped any unit whose unitPos was not
// AUTO, which meant a droid LAMBS had once put prone was never touched again.
// Reported in-game as B1s crawling and crouching.

if (hasInterface && {!isServer}) exitWith {0};
if !(missionNamespace getVariable ["FST_HC_DroidStanceEnabled", true]) exitWith {0};

private _cache = missionNamespace getVariable "FST_HC_StanceClassCache";
if (isNil "_cache") then {
    _cache = createHashMap;
    missionNamespace setVariable ["FST_HC_StanceClassCache", _cache];
};

private _forceUp = {
    params ["_unit"];
    _unit setUnitPos "UP";
    _unit setUnitPosWeak "UP";
};

private _fixed = 0;
{
    private _unit = _x;
    if (!local _unit) then { continue };
    if (!alive _unit) then { continue };
    if (isPlayer _unit) then { continue };
    if !((side _unit) isEqualTo east) then { continue };

    // Per-classname verdict cache: 0 = not ours, 1 = B1, 2 = B2. Deliberately
    // narrower than fn_isDroidUnit so BX and commando droids keep their own
    // AI stance behaviour.
    private _class = typeOf _unit;
    private _kind = _cache get _class;
    if (isNil "_kind") then {
        private _lc = toLowerANSI _class;
        _kind = 0;
        if (((_lc find "fst_droid_b1") >= 0) || {(_lc find "fst_b1") >= 0}) then { _kind = 1; };
        if (((_lc find "fst_droid_b2") >= 0) || {(_lc find "fst_b2") >= 0}) then { _kind = 2; };
        _cache set [_class, _kind];
    };
    if (_kind == 0) then { continue };
    if !((vehicle _unit) isEqualTo _unit) then { continue };

    // One-time per-machine hook. Object EHs live on the machine that added
    // them, so after an HC transfer the new owner hooks again (its own flag).
    if !(_unit getVariable ["FST_HC_stanceHooked", false]) then {
        _unit setVariable ["FST_HC_stanceHooked", true];
        _unit addEventHandler ["AnimChanged", {
            params ["_unit"];
            if (!local _unit || {!alive _unit}) exitWith {};
            if ((stance _unit) != "STAND" || {(unitPos _unit) != "UP"}) then {
                _unit setUnitPos "UP";
                _unit setUnitPosWeak "UP";
            };
        }];
        if (_kind == 2) then {
            // LAMBS opt-outs are broadcast once so they survive owner changes.
            if !(_unit getVariable ["lambs_danger_disableAI", false]) then {
                _unit setVariable ["lambs_danger_disableAI", true, true];
            };
            private _grp = group _unit;
            if (!isNull _grp && {!(_grp getVariable ["lambs_danger_disableGroupAI", false])}) then {
                _grp setVariable ["lambs_danger_disablegroupAI", true, true];
                _grp setVariable ["lambs_danger_disableGroupAI", true, true];
            };
        };
        [_unit] call _forceUp;
        _fixed = _fixed + 1;
    };

    if (_kind == 2) then {
        // Arguments-local, so re-applied on every owner; cheap no-ops when set.
        _unit disableAI "AUTOCOMBAT";
        _unit disableAI "COVER";
        _unit disableAI "SUPPRESSION";
    };

    if ((stance _unit) != "STAND" || {(unitPos _unit) != "UP"}) then {
        [_unit] call _forceUp;
        _fixed = _fixed + 1;
    };
} forEach allUnits;

_fixed
