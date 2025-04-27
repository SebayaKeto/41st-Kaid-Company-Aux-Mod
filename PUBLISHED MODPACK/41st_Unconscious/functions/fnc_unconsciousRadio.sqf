#include "\x\cba\addons\main\script_macros_common.hpp"

params ["_unit", "_volume"];

private _isUnconscious = [_unit] call ace_medical_status_fnc_isUnconscious;

if (_isUnconscious) then {
    _unit setVariable ["tf_unable_to_use_radio", true, true];
} else {
    _unit setVariable ["tf_unable_to_use_radio", false, true];
};