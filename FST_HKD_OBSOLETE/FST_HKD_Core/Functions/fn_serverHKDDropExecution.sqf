params ["_logic","_validClassList","_seed","_batchSize","_sleepBetweenBatches","_centerPos","_altitude","_radius","_randomDir","_compassDir","_useThrusters","_totalToSpawn","_client"];

// Runs on server: rebuild queue deterministically from seed, spawn objects and push progress updates to the initiating client
private _initialTotal = _totalToSpawn;
private _spawnedSoFar = 0;

// Rebuild queue using provided seed so we don't transfer large arrays over network
private _queue = [];
setRandomSeed _seed;
for "_i" from 1 to _initialTotal do {
    _queue pushBack (selectRandom _validClassList);
};

while {count _queue > 0} do {
    // Check cancel flag on the module object (set by client via remoteExec to server)
    if ((_logic getVariable ['HKD_Spawn_Cancel', false]) == true) then {
        // notify client
        [_spawnedSoFar, _initialTotal, ( (_spawnedSoFar / max [1,_initialTotal]) * 100 ), format ['Cancelled (%1/%2)', _spawnedSoFar, _initialTotal]] remoteExecCall ["HKD_fnc_clientUpdateProgress", _client];
        // Exit the server loop cleanly
        exitWith {};
    };

    // Collect this batch
    private _toDo = [];
    for "_b" from 1 to _batchSize do {
        if ((count _queue) == 0) exitWith {};
        _toDo pushBack (_queue select 0);
        _queue deleteAt 0;
    };

    // Spawn batch
    {
        private _className = _x;
        private _randomPos = [
            (_centerPos select 0) + ((random (_radius * 2)) - _radius),
            (_centerPos select 1) + ((random (_radius * 2)) - _radius),
            _altitude + (random 200)
        ];

        private _object = createVehicle [_className, _randomPos, [], 0, "CAN_COLLIDE"];
        if (_randomDir) then { _object setDir (random 360); } else { _object setDir _compassDir; };

        // Initialize drop logic on the created object after a small randomized delay
        [_object, _useThrusters] spawn {
            sleep (random 2);
            _this call HKD_fnc_initHKDDrop;
        };

        _spawnedSoFar = _spawnedSoFar + 1;
    } forEach _toDo;

    // Send progress update to the initiating client
    private _pct = (_spawnedSoFar / _initialTotal) * 100;
    [_spawnedSoFar, _initialTotal, _pct, format ['Spawning: %1 / %2 (%3%%)', _spawnedSoFar, _initialTotal, round _pct]] remoteExecCall ["HKD_fnc_clientUpdateProgress", _client];

    sleep _sleepBetweenBatches;
};

// Final update: ensure client shows completion if not cancelled
if (!(_logic getVariable ['HKD_Spawn_Cancel', false])) then {
    [_spawnedSoFar, _initialTotal, 100, "Spawn complete."] remoteExecCall ["HKD_fnc_clientUpdateProgress", _client];
};

    // Reset cancel flag and cleanup
    _logic setVariable ['HKD_Spawn_Cancel', false, true];
    // scramble seed after done
    setRandomSeed (floor (random 1000000000));
    deleteVehicle _logic;