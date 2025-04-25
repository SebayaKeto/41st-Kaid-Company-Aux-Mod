#include "\x\cba\addons\main\script_macros_common.hpp"

params ["_unit"];

if (isPlayer _unit && {[_unit] call ace_medical_status_fnc_isUnconscious}) then {
    // Disable speaking on TFAR
    _unit setVariable ["TFAR_canSpeak", false, true];

    // Optional: set voice volume to zero
    if (_unit call TFAR_fnc_haveSWRadio) then {
        _unit call TFAR_fnc_setVoiceVolumeZero;
    };
} else {
    // Restore when conscious
    _unit setVariable ["TFAR_canSpeak", true, true];
};