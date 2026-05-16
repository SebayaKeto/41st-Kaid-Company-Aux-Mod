// FST_HCSpawn_fnc_processTransfers
// Server-side. Spawned loop that processes the transfer queue in batches.
// Batched and throttled to avoid Zeus/object locality spikes.

if (!isServer) exitWith {};

// When idle, poll cheaply. When work exists, drain immediately and only throttle
// BETWEEN batches. The previous version pre-slept FST_HC_TransferInterval before
// every check, adding 3s of latency to every batch even with a full queue.
while {true} do {
    if (count FST_HC_TransferQueue == 0 || {count FST_HC_Array == 0} || {FST_HC_EmergencyMode}) then {
        sleep 1;
    } else {
        FST_HC_Transferring = true;

        private _batchSize = FST_HC_TransferBatchSize min count FST_HC_TransferQueue;
        private _batch = FST_HC_TransferQueue select [0, _batchSize];
        FST_HC_TransferQueue = FST_HC_TransferQueue select [_batchSize, (count FST_HC_TransferQueue - _batchSize) max 0];

        {
            private _grp = _x;

            if (isNull _grp) then { continue };
            _grp setVariable ["FST_HC_pendingTransfer", nil];
            _grp setVariable ["FST_HC_interceptQueued", nil, true];

            if (count units _grp == 0) then { continue };
            if (isPlayer leader _grp) then { continue };

            if (count (_grp getVariable ["FST_HC_tracked", []]) > 0) then { continue };
            if ([_grp] call FST_HCSpawn_fnc_isBlacklisted) then { continue };

            [_grp] call FST_HCSpawn_fnc_transferGroup;

            sleep 0.25;
        } forEach _batch;

        FST_HC_Transferring = false;

        // Throttle between batches, not before them.
        sleep FST_HC_TransferInterval;
    };
};
