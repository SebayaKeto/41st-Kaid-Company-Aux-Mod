// Called on every machine to install the Deploy AT-RT action on a LAAT/i.
// Triggered once per LAAT/i lifetime from fn_laatiLoadServer after the first AT-RT is loaded
// (broadcast is JIP-persistent, so late joiners get it installed locally too).
// params: [_laati]
params ["_l"];

// Disabled for this build — parked alongside "Load into LAAT/i" in init.sqf
// while work continues on another build. Remove this line to re-enable.
if (true) exitWith {};

// The LAAT/i is a foreign (FST) vehicle, not ours — FST's own postInit scripts may
// re-stamp its actions at any time after mission load, same threat documented in
// init.sqf for the AT-RT's own actions. Re-install periodically so "Deploy AT-RT"
// stays available even if FST's re-stamp runs after ours. Track the returned action
// ID and remove it before re-adding so this doesn't pile up duplicate menu entries.
[_l] spawn {
    params ["_l"];
    waitUntil { time > 0 };

    private _fnInstall = {
        params ["_v", "_id"];
        if (_id >= 0) then { _v removeAction _id; };
        _v addAction [
            "Deploy AT-RT",
            "\BUZZ_Vehicles\ATRT\scripts\fn_laatiDeployAction.sqf",
            [],
            1.5,
            true,
            true,
            "",
            "player in crew _this",
            6,
            false,
            "",
            ""
        ]
    };

    private _actionId = -1;
    _actionId = [_l, _actionId] call _fnInstall;
    sleep 5;
    _actionId = [_l, _actionId] call _fnInstall;
    sleep 10;
    _actionId = [_l, _actionId] call _fnInstall;
    while { alive _l } do {
        sleep 60;
        _actionId = [_l, _actionId] call _fnInstall;
    };
};
