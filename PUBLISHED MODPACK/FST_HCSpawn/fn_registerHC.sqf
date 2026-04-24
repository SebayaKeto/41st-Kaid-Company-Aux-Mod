// FST_HCSpawn_fnc_registerHC
// Server-side. Called by an HC via remoteExecCall.
// Registers the HC in the tracking arrays.
//
// Arguments:
//   0: OBJECT — HC player object
//   1: NUMBER — HC clientOwner ID

if (!isServer) exitWith {};

params ["_hcObj", "_hcId"];

// Check if already registered (reconnection)
private _existingIdx = FST_HC_Array find _hcObj;
if (_existingIdx != -1) then {
    // Reconnecting — update the client ID
    FST_HC_Ids set [_existingIdx, _hcId];
    diag_log format ["[FST_HCSpawn] HC reconnected: %1 (owner %2, index %3)", _hcObj, _hcId, _existingIdx];
} else {
    // New HC
    FST_HC_Array pushBack _hcObj;
    FST_HC_Ids pushBack _hcId;
    FST_HC_UnitCounts pushBack 0;
    diag_log format ["[FST_HCSpawn] HC registered: %1 (owner %2, index %3)", _hcObj, _hcId, count FST_HC_Array - 1];
};

// Broadcast to all clients
publicVariable "FST_HC_Array";
publicVariable "FST_HC_Ids";

// Tell the HC its index so FPS marker labels correctly
private _hcIndex = FST_HC_Array find _hcObj;
[_hcIndex] remoteExecCall ["FST_HCSpawn_fnc_setHCIndex", _hcId];

["FST HC Connected"] remoteExec ["hint", -2];
