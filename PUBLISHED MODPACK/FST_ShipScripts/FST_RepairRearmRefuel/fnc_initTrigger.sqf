/*
    FST_fnc_initTrigger
    Registers a trigger as a repair/rearm/refuel zone and makes sure the
    local player has the service action attached.
    Call from the trigger's "On Activation" field: [thisTrigger] call FST_fnc_initTrigger;

    The action's visibility condition (FST_fnc_RRR_checkCondition) is checked
    live against FST_RRR_triggers rather than a cached position, so once a
    trigger is registered here it stays correct regardless of how many pads
    exist or whether that trigger's own "On Activation" ever fires again.

    Getting the action back onto a respawned unit still needs something to
    call FST_fnc_RRR_addAction on the new unit. That's handled two ways so
    neither one being unreliable can cause the reported "missing after
    respawn" bug: a CBA PlayerChanged hook (fires immediately on respawn),
    backed by a slow watcher loop that self-heals within a few seconds even
    if the event hook never fires for some reason.
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
