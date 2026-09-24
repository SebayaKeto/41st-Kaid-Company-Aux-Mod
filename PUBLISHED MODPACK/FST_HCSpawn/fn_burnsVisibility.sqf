// Server-authorized, explicit selected-player diagnostic/recovery action.
// No periodic blanket unhide: mission concealment remains under mission control.
params ["_unit",["_refresh",false],["_networkId",""],["_serverClass",""]];
if (isRemoteExecuted && {remoteExecutedOwner!=2}) exitWith {};
if (!isRemoteExecuted && {!isServer}) exitWith {};
if (isNull _unit) exitWith {diag_log format ["[BURNS_PLAYER_VISIBILITY_MISSING] observer=%1 unit=%2 class=%3 refresh=%4",clientOwner,_networkId,_serverClass,_refresh]};
if (!isPlayer _unit || {_unit isKindOf "HeadlessClient_F"}) exitWith {};
diag_log format ["[BURNS_PLAYER_VISIBILITY] observer=%1 unit=%2 class=%3 uniform=%4 hidden=%5 simulation=%6 model=%7 refresh=%8",clientOwner,netId _unit,typeOf _unit,uniform _unit,isObjectHidden _unit,simulationEnabled _unit,getModelInfo _unit,_refresh];
if (_refresh) then {_unit hideObject false};
