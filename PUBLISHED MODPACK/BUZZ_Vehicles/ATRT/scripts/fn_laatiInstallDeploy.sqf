// Install Deploy AT-RT action
params ["_l"];

if (_l getVariable ["BUZZ_deployInstalledLocal", false]) exitWith {};
_l setVariable ["BUZZ_deployInstalledLocal", true];

// Periodic re-install
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
            // Action condition
            "(_this in crew _target) && {(((_target getVariable ['ace_cargo_loaded', []]) findIf {_x isEqualType objNull && {_x isKindOf 'BUZZ_ATRT_TransportCrate'}}) > -1) || {((_target getVariable ['BUZZ_laatiCrates', []]) findIf {(_x getVariable ['BUZZ_laatiStowed', objNull]) isEqualTo _target}) > -1}}",
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
