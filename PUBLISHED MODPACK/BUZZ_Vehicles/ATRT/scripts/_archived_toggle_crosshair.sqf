// =============================================================================
//  ARCHIVED — Toggle Crosshair action
// =============================================================================

// ── TOGGLE CROSSHAIR ─────────────────────────────────────────────────────────
_v addAction [
    "Toggle Crosshair",
    {
        params ["_atrt", "_caller"];
        // Caller guard
        if (hasInterface) then {
            private _newState = !(_atrt getVariable ["BUZZ_crosshairOn", false]);
            _atrt setVariable ["BUZZ_crosshairOn", _newState];
            hintSilent (if (_newState) then { "Crosshair: ON" } else { "Crosshair: OFF" });
        };
    },
    [],
    0,
    false,
    true,
    "",
    "!isNil { _this getVariable 'rider' } && { local (_this getVariable ['rider', objNull]) }",
    4,
    false,
    "",
    ""
];
