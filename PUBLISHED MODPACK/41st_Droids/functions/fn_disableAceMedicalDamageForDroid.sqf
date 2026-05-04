/*
    FST_fnc_disableAceMedicalDamageForDroid

    V9_B1_METAL_IMPACTS

    Goals:
    - Keep ACE loaded for players and organics.
    - Stop ACE Medical from handling damage/wounds/bleeding on FST droids.
    - Remove ONLY ACE Medical's stored HandleDamage EH, not other HandleDamage EHs.
    - Preserve the V2 armor/TTK tuning.
    - Support Legion biology by relying on uniform config flags set in config.cpp.
*/

params [["_unit", objNull, [objNull]]];
if (isNull _unit) exitWith {false};

private _type = typeOf _unit;
private _cfg = configOf _unit;
private _uniformCfg = configFile >> "CfgWeapons" >> (uniform _unit);

// IMPORTANT: first term must be a Boolean. Later terms may be lazy code blocks.
// V6 accidentally started this expression with a code block, causing "Type code, expected Bool".
private _isDroid =
    (("droid" in toLowerANSI _type) || {"FST_BX" in _type} || {"FST_B2" in _type})
    || {(getNumber (_cfg >> "JLTS_isDroid")) == 1}
    || {(getNumber (_cfg >> "ls_isDroid")) == 1}
    || {(getNumber (_cfg >> "TAS_isDroid")) == 1}
    || {(getNumber (_uniformCfg >> "JLTS_isDroid")) == 1}
    || {(getNumber (_uniformCfg >> "ls_isDroid")) == 1}
    || {(getNumber (_uniformCfg >> "TAS_isDroid")) == 1};

if (!_isDroid) exitWith {false};

private _fnc_clean = {
    params [["_unit", objNull, [objNull]]];
    if (isNull _unit) exitWith {false};

    // Remove ACE Medical's specific HandleDamage EH only.
    private _eh = _unit getVariable ["ace_medical_HandleDamageEHID", -1];
    if (_eh isEqualType 0 && {_eh >= 0}) then {
        _unit removeEventHandler ["HandleDamage", _eh];
        _unit setVariable ["ace_medical_HandleDamageEHID", nil, false];

        if (missionNamespace getVariable ["FST_debug_noAceDroidDamage", false]) then {
            diag_log format [
                "[FST_Droids_V8] Removed ACE medical HandleDamage EH from %1 EH=%2",
                typeOf _unit,
                _eh
            ];
        };
    };

    // Failsafe: if ACE already touched the unit before the EH was removed, clear medical state.
    // These are local-only on purpose. We only call this on droid classes through XEH/Hit/Local.
    _unit setVariable ["ace_medical_openWounds", createHashMap, false];
    _unit setVariable ["ace_medical_bandagedWounds", createHashMap, false];
    _unit setVariable ["ace_medical_stitchedWounds", createHashMap, false];
    _unit setVariable ["ace_medical_internalWounds", createHashMap, false];
    _unit setVariable ["ace_medical_woundBleeding", 0, false];
    _unit setVariable ["ace_medical_isBleeding", false, false];
    _unit setVariable ["ace_medical_bloodVolume", 6, false];
    _unit setVariable ["ace_medical_pain", 0, false];
    _unit setVariable ["ace_medical_painSuppress", 0, false];
    _unit setVariable ["ace_medical_hasPain", false, false];
    _unit setVariable ["ace_medical_fractures", [0,0,0,0,0,0], false];

    // Vanilla Arma blood trail guard. BI command controls how long an injured unit leaves a blood trail.
    _unit setBleedingRemaining 0;

    true
};

[_unit] call _fnc_clean;

// Do not let vanilla hit bleeding/trails persist. This is event-driven, not per-frame.
if !(_unit getVariable ["FST_noBleedHitEH", false]) then {
    _unit setVariable ["FST_noBleedHitEH", true, false];
    _unit addEventHandler ["Hit", {
        params ["_unit"];
        if (isNull _unit) exitWith {};
        _unit setBleedingRemaining 0;
        _unit setVariable ["ace_medical_woundBleeding", 0, false];
        _unit setVariable ["ace_medical_isBleeding", false, false];
        _unit setVariable ["ace_medical_openWounds", createHashMap, false];
    }];
};

// ACE/CBA/LS can attach just after InitPost depending on load/order. These are one-shot delayed checks.
{
    [{
        params ["_args"];
        _args params ["_unit", "_fnc_clean"];
        if (!isNull _unit) then { [_unit] call _fnc_clean; };
    }, [_unit, _fnc_clean], _x] call CBA_fnc_waitAndExecute;
} forEach [0.1, 0.5, 1.5, 3.0];

true
