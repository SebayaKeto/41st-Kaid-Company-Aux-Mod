// =============================================================================
//  BUZZ AT-RT — reserve_supply_init.sqf
// =============================================================================

private _prop = _this;

if (isServer) then {
    clearWeaponCargoGlobal   _prop;
    clearMagazineCargoGlobal _prop;
    clearItemCargoGlobal     _prop;
    clearBackpackCargoGlobal _prop;
    _prop addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", 16];

    // Cargo re-broadcast
    [_prop] spawn {
        params ["_p"];
        sleep 2;
        if (isNull _p) exitWith {};
        private _cargo  = getMagazineCargo _p;
        private _magIdx = (_cargo select 0) find "BUZZ_ATRT_T15ReserveMag";
        private _count  = if (_magIdx < 0) then { 0 } else { (_cargo select 1) select _magIdx };
        if (_count <= 0) then { _p addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", 16]; };
    };
};
