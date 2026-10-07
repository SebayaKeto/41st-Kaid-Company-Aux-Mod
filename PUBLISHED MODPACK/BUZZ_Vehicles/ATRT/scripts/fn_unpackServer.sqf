// Unpack AT-RT (server)
params ["_pos", "_dir", "_hp", "_cell", "_reserves", "_crate", ["_class", "BUZZ_ATRT"]];
private _group = createGroup [WEST, true];
private _atrt  = _group createUnit [_class, ASLToAGL _pos, [], 0, "NONE"];
_atrt setDir _dir;
_atrt setPosASL _pos;
[_atrt, _hp, _cell, _reserves] spawn {
    params ["_atrt", "_hp", "_cell", "_reserves"];
    private _tWait = time;
    waitUntil { !isNull (_atrt getVariable ["supplyBox", objNull]) || time - _tWait > 5 };
    // Supply box fallback
    if (isNull (_atrt getVariable ["supplyBox", objNull])) then {
        private _box = "Box_NATO_Ammo_F" createVehicle (position _atrt);
        _box attachTo [_atrt, [0, 0, 0]];
        _box hideObjectGlobal true;
        clearWeaponCargoGlobal   _box;
        clearMagazineCargoGlobal _box;
        clearItemCargoGlobal     _box;
        clearBackpackCargoGlobal _box;
        _atrt setVariable ["supplyBox", _box, true];
    };
    _atrt setVariable ["BUZZ_hp",        _hp,   true];
    _atrt setVariable ["BUZZ_powerCell", _cell, true];
    private _box = _atrt getVariable ["supplyBox", objNull];
    clearMagazineCargoGlobal _box;
    if (_reserves > 0) then { _box addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", _reserves]; };
};
if (!isNull _crate) then { deleteVehicle _crate; };
