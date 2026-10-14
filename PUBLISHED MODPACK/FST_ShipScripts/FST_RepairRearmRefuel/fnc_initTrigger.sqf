/*
    FST_fnc_initTrigger
    Registers a trigger as a service zone. The player's action is kept attached by FST_fnc_RRR_postInit.
    Call from the trigger's On Activation: [thisTrigger] call FST_fnc_initTrigger;
*/
params ["_trigger"];

if (isNil "FST_RRR_triggers") then { FST_RRR_triggers = []; };
FST_RRR_triggers pushBackUnique _trigger;

[player] call FST_fnc_RRR_addAction;
