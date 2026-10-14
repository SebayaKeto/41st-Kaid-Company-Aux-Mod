/*
    FST_fnc_RRR_postInit
    Client postInit (via CBA XEH). Keeps the service action attached to the player
    across respawns and unit switches, independent of any trigger activating.
*/
if (!hasInterface) exitWith {};

if (isNil "FST_RRR_triggers") then { FST_RRR_triggers = []; };

["unit", {
    params ["_newUnit"];
    [_newUnit] call FST_fnc_RRR_addAction;
}, true] call CBA_fnc_addPlayerEventHandler;

[] spawn {
    while {true} do {
        [player] call FST_fnc_RRR_addAction;
        sleep 5;
    };
};
