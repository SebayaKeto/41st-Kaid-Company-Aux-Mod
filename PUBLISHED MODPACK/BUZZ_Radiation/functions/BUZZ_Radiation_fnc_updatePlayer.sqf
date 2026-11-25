// Player update
private _hasDevice = alive player && {!isNull objectParent player || {[player, BUZZ_Radiation_monitorList] call BUZZ_Radiation_fnc_hasItem}};

[_hasDevice] call BUZZ_Radiation_fnc_updateMonitor;

if (_hasDevice && {BUZZ_Radiation_monitorClicks}) then {
    // Monitor panel check
    private _panelOpen = ["left", "right"] findIf {"buzz_radiation" in toLower str (infoPanel _x)} > -1;
    if (!_panelOpen) exitWith {};
    (player getVariable ["BUZZ_Radiation_exposure", [-1, false, false]]) params ["_tier", "_safe", "_decon"];
    if (!_safe && {!_decon} && {_tier >= 0}) then {
        // Geiger clicks
        private _cls = format ["BUZZ_Radiation_geiger_%1", _tier];
        playSoundUI [_cls, BUZZ_Radiation_monitorClickVolume];
        // Clicks for nearby players
        private _near = if (!isNull objectParent player) then {[]} else {
            allPlayers select {_x != player && {_x distance player <= BUZZ_Radiation_monitorClickRange + 5}}
        };
        if (_near isNotEqualTo []) then {["BUZZ_Radiation_say3D", [player, _cls, BUZZ_Radiation_monitorClickRange, 1], _near] call CBA_fnc_targetEvent};
    };
};
