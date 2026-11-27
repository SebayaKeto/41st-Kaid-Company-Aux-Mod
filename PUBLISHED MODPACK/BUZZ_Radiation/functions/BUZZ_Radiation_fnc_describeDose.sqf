// Dose label and colour
params [["_dose", 0]];
switch (true) do {
    case (_dose < 1):  {["CLEAN",    "#59ffd9", [0.35, 1, 0.85, 1]]};
    case (_dose < 25): {["LOW",      "#9dff59", [0.62, 1, 0.35, 1]]};
    case (_dose < 50): {["MODERATE", "#ffe359", [1, 0.89, 0.35, 1]]};
    case (_dose < 75): {["SEVERE",   "#ff9a3c", [1, 0.6, 0.24, 1]]};
    default            {["CRITICAL", "#ff3c3c", [1, 0.24, 0.24, 1]]};
}
