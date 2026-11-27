// Changes a zone's tier mid-mission
params [["_zone", objNull, [objNull]], ["_tier", 1, [0, ""]]];
if (isNull _zone) exitWith {};
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
_zone setVariable ["BUZZ_Radiation_tier", (round _tier) max -2 min 2, netId _zone != "0:0"];
