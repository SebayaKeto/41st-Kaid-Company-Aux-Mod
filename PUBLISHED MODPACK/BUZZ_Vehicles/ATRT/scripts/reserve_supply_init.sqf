// =============================================================================
//  BUZZ AT-RT — reserve_supply_init.sqf
//  Called via class EventHandlers { init = "..."; } in config.cpp.
//  Standalone placeable prop holding 9x BUZZ_ATRT_T15ReserveMag for any AT-RT rider
//  to draw reserve ammo from. Unlike the AT-RT itself (a Man-class unit with no
//  native cargo hold, hence the attached invisible box in ATRT\scripts\init.sqf),
//  this crate's base class already has a working cargo inventory, so the
//  magazines just live directly in it — open with the default Gear interaction.
// =============================================================================

private _prop = _this;

if (isServer) then {
    clearWeaponCargoGlobal   _prop;
    clearMagazineCargoGlobal _prop;
    clearItemCargoGlobal     _prop;
    clearBackpackCargoGlobal _prop;
    _prop addMagazineCargoGlobal ["BUZZ_ATRT_T15ReserveMag", 16];

    // Re-broadcast after a delay in case a client still missed the cargo
    // broadcast above — same JIP-safety concern documented throughout this
    // addon (see ATRT\scripts\init.sqf and fn_resyncBoxServer.sqf).
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
