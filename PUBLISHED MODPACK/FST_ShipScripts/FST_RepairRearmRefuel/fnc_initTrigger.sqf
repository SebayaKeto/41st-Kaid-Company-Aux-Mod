/*
    FST_fnc_initTrigger
    Registers a trigger as a service zone and keeps the player's action attached.
    Call from the trigger's On Activation: [thisTrigger] call FST_fnc_initTrigger;
*/
params ["_trigger"];

if (isNil "FST_RRR_triggers") then { FST_RRR_triggers = []; };
FST_RRR_triggers pushBackUnique _trigger;

if (isNil "FST_RRR_playerHooksAdded") then {
    FST_RRR_playerHooksAdded = true;

    ["PlayerChanged", {
        params ["_newUnit"];
        [_newUnit] call FST_fnc_RRR_addAction;
    }] call CBA_fnc_addPlayerEventHandler;

    [] spawn {
        while {true} do {
            [player] call FST_fnc_RRR_addAction;
            sleep 5;
        };
    };
};

[player] call FST_fnc_RRR_addAction;
