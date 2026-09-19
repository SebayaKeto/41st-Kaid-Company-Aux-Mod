// =============================================================================
//  ARCHIVED — Toggle Crosshair action
//  Removed when crosshair was made always-on by default (BUZZ_crosshairOn = true
//  set in Saddle Up).  Preserved here in case a per-rider toggle is wanted later.
//
//  To restore: paste the addAction block back into the _fnInstall closure in
//  init.sqf, just before the closing `}; // end _fnInstall` line.
// =============================================================================

// ── TOGGLE CROSSHAIR ─────────────────────────────────────────────────────────
_v addAction [
    "Toggle Crosshair",
    {
        params ["_atrt", "_caller"];
        // During remoteControl, ArmA sets _caller = the controlled unit (AT-RT),
        // not the player's own character — so `player isEqualTo _caller` is always
        // false while mounted.  The action condition already ensures only the rider
        // can trigger this, so hasInterface alone is the correct guard here.
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
