// FST_HCSpawn_fnc_processTransfers
// Server-side. Spawned loop that processes the transfer queue in batches.
// Replaces ZHC's serial sleep-per-group approach with batched processing.

if (!isServer) exitWith {};

while {true} do {
    // Wait until there's work and HCs are available
    waitUntil {
        sleep FST_HC_TransferInterval;
        count FST_HC_TransferQueue > 0 && count FST_HC_Array > 0 && !FST_HC_EmergencyMode
    };

    FST_HC_Transferring = true;

    // Pull a batch
    private _batchSize = FST_HC_TransferBatchSize min count FST_HC_TransferQueue;
    private _batch = FST_HC_TransferQueue select [0, _batchSize];
    FST_HC_TransferQueue deleteRange [0, _batchSize];

    {
        if (isNull _x || {count units _x == 0} || {isPlayer leader _x}) then { continue };

        // Skip if already on an HC
        if (_x in FST_HC_GroupMap) then { continue };

        [_x] call FST_HCSpawn_fnc_transferGroup;

        sleep 0.3; // brief pause between individual transfers within batch
    } forEach _batch;

    FST_HC_Transferring = false;
};
