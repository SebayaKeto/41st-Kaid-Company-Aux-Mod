/*
    BUZZ_fnc_zvResetBaseline
    Forget what "full" ammo is for the local player; the next publish tick
    snapshots their current load as the new full. Call on the player's
    machine after a kit is applied (kit menu integration).
*/
player setVariable ["BUZZ_zv_baseline", nil];
