// FST_medOps_fnc_severity
// Any machine (reads ACE's broadcast vars). Returns [rank, label, colour RGBA, mapColour, html colour].

params ["_u"];
switch (true) do {
    case (_u getVariable ["ace_medical_inCardiacArrest", false]): { [4, "CARDIAC ARREST", [0.78, 0.35, 1, 1], "ColorPink", "#c759ff"] };
    case (_u getVariable ["ACE_isUnconscious", false]): { [3, "UNCONSCIOUS", [1, 0.25, 0.2, 1], "ColorRed", "#ff4033"] };
    case ((_u getVariable ["ace_medical_woundBleeding", 0]) > 0): { [2, "BLEEDING", [1, 0.65, 0.1, 1], "ColorOrange", "#ffa61a"] };
    default { [1, "WOUNDED", [0.35, 0.85, 1, 1], "ColorBlue", "#59d9ff"] };
}
