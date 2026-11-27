// Registers a radiation zone on THIS machine
params [
    ["_zone", objNull, [objNull]],
    ["_tier", 1, [0, ""]],
    ["_areas", [], [[], "", objNull]],
    ["_condition", "true", ["", {}]]
];
if (isNull _zone) exitWith {objNull};

if (_tier isEqualType "") then {
    _tier = switch (toUpper _tier) do {
        case "SAFE": {-2};
        case "DECON";
        case "DECONTAMINATION": {-1};
        case "BACKGROUND": {0};
        case "DANGEROUS": {1};
        case "LETHAL": {2};
        default {parseNumber _tier};
    };
};
_tier = (round _tier) max -2 min 2;

if !(_areas isEqualType []) then {_areas = [_areas]};
// Single area array
if (count _areas > 0 && {(_areas select 0) isEqualType [] && {count _areas >= 3} && {(_areas select 1) isEqualType 0}}) then {_areas = [_areas]};
if (_areas isEqualTo []) then {_areas = [_zone]};

if (_condition isEqualType "") then {
    _condition = if (_condition == "") then {{true}} else {compile _condition};
};

_zone setVariable ["BUZZ_Radiation_tier", _tier];
_zone setVariable ["BUZZ_Radiation_areas", _areas];
_zone setVariable ["BUZZ_Radiation_condition", _condition];
if (isNil {_zone getVariable "BUZZ_Radiation_active"}) then {_zone setVariable ["BUZZ_Radiation_active", true]};

BUZZ_Radiation_zones pushBackUnique _zone;
_zone
