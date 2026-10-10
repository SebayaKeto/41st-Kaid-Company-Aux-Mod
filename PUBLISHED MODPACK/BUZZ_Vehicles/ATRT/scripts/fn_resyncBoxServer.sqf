// Supply box resync (server)
params ["_atrt"];
if (isNull _atrt) exitWith {};

private _box = _atrt getVariable ["supplyBox", objNull];
if (isNull _box) exitWith {};

// Attachment re-assert
_box attachTo [_atrt, [0, 0, 0]];
_box hideObjectGlobal true;
_atrt setVariable ["supplyBox", _box, true];

private _cargo  = getMagazineCargo _box;
private _magIdx = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
private _count  = if (_magIdx < 0) then { 0 } else { (_cargo select 1) select _magIdx };
clearMagazineCargoGlobal _box;
if (_count > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _count]; };
