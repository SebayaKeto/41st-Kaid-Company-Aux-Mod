#include "\x\cba\addons\main\script_macros_common.hpp"

params ["_unit"];

if (isPlayer _unit && {[_unit] call ace_medical_status_fnc_isUnconscious}) then {
    [_unit, ["TFAR_canSpeak", false, true]] remoteExec ["setVariable", _unit];
} else {
    [_unit, ["TFAR_canSpeak", true, true]] remoteExec ["setVariable", _unit];
};