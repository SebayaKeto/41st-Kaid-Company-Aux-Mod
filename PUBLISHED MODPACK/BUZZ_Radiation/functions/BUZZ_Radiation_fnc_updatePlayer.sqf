/*
 * Client side, once per second: Radiation Monitor panel and detector clicks.
 * The clicks only play while the Radiation Monitor is the open side panel, and they
 * are a 3D sound everyone within the click range hears.
 */
private _hasDevice = alive player && {!isNull objectParent player || {[player, BUZZ_Radiation_monitorList] call BUZZ_Radiation_fnc_hasItem}};

[_hasDevice] call BUZZ_Radiation_fnc_updateMonitor;

if (_hasDevice && {BUZZ_Radiation_monitorClicks}) then {
    // Is the Radiation Monitor the panel currently shown on the left or right? (infoPanel names the
    // active component; its display can stay loaded in the background after switching away.)
    private _panelOpen = ["left", "right"] findIf {"buzz_radiation" in toLower str (infoPanel _x)} > -1;
    if (!_panelOpen) exitWith {};
    (player getVariable ["BUZZ_Radiation_exposure", [-1, false, false]]) params ["_tier", "_safe", "_decon"];
    if (!_safe && {!_decon} && {_tier >= 0}) then {
        // The wearer hears it at full volume (2D, like the old clicks); nearby players get a 3D copy.
        private _cls = format ["BUZZ_Radiation_geiger_%1", _tier];
        playSoundUI [_cls, BUZZ_Radiation_monitorClickVolume];
        // Inside a vehicle the clicks come from its built-in panel: only the reader hears them,
        // so a full troop bay doesn't stack everyone's clicks on top of each other.
        private _near = if (!isNull objectParent player) then {[]} else {
            allPlayers select {_x != player && {_x distance player <= BUZZ_Radiation_monitorClickRange + 5}}
        };
        if (_near isNotEqualTo []) then {["BUZZ_Radiation_say3D", [player, _cls, BUZZ_Radiation_monitorClickRange, 1], _near] call CBA_fnc_targetEvent};
    };
};
