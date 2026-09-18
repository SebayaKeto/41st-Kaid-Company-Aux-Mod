// Called via remoteExecCall ["BUZZ_fnc_resyncBoxServer", 2] from the
// "Open ATRT Inventory" action, right when a player clicks it.
// Runs on the server only. Re-broadcasts supplyBox + its cargo so the
// requesting client gets an authoritative refresh instead of relying on
// whatever the original createVehicle-time broadcast happened to deliver —
// a setVariable/addMagazineCargoGlobal fired in the same frame as the box's
// own creation can race that object's network replication and be silently
// dropped for a client that hadn't registered the object yet. Since the
// player can only click this action on an object they already know about,
// re-syncing at click time is far more reliable than a fixed-delay resync.
params ["_atrt"];
if (isNull _atrt) exitWith {};

private _box = _atrt getVariable ["supplyBox", objNull];
if (isNull _box) exitWith {};

// Re-assert the attachment/hide state, not just the variable+cargo — confirmed
// via Zeus's editable-object list that the box can end up sitting at world origin
// ("Debug Corner") on some clients, meaning the original attachTo call itself
// didn't reach every machine. Both commands are idempotent.
_box attachTo [_atrt, [0, 0, 0]];
_box hideObjectGlobal true;
_atrt setVariable ["supplyBox", _box, true];

private _cargo  = getMagazineCargo _box;
private _magIdx = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
private _count  = if (_magIdx < 0) then { 0 } else { (_cargo select 1) select _magIdx };
clearMagazineCargoGlobal _box;
if (_count > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _count]; };
