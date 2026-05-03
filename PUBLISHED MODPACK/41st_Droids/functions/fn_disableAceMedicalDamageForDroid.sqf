/*
    FST_fnc_disableAceMedicalDamageForDroid

    Removes only ACE Medical Engine's stored HandleDamage EH from FST droids.
    This keeps vanilla Arma damage and preserves other mods' HandleDamage EHs.

    ACE stores its medical HandleDamage EH ID on the unit as:
        ace_medical_HandleDamageEHID

    This function intentionally does NOT use removeAllEventHandlers.
*/

params [["_unit", objNull, [objNull]]];

if (isNull _unit) exitWith {false};

private _fnc_removeAceMedicalEH = {
    params [["_unit", objNull, [objNull]]];

    if (isNull _unit) exitWith {false};

    private _eh = _unit getVariable ["ace_medical_HandleDamageEHID", -1];

    if (_eh isEqualType 0 && {_eh >= 0}) then {
        _unit removeEventHandler ["HandleDamage", _eh];
        _unit setVariable ["ace_medical_HandleDamageEHID", nil];

        if (missionNamespace getVariable ["FST_debug_noAceDroidDamage", false]) then {
            diag_log format [
                "[FST] Removed ACE medical HandleDamage EH from %1 (%2). EH=%3 local=%4 owner=%5",
                typeOf _unit,
                _unit,
                _eh,
                local _unit,
                owner _unit
            ];
        };

        true
    } else {
        false
    };
};

// Immediate attempt. On many dynamically spawned units ACE has already attached the EH by InitPost.
[_unit] call _fnc_removeAceMedicalEH;

// One-shot retries cover dynamic spawn/init/locality timing without permanent loops.
{
    [{
        params ["_unit", "_fnc_removeAceMedicalEH"];
        [_unit] call _fnc_removeAceMedicalEH;
    }, [_unit, _fnc_removeAceMedicalEH], _x] call CBA_fnc_waitAndExecute;
} forEach [0.1, 0.5, 1.5];

true
