/*
    FST_fnc_RRR_isInZone
    Returns true if _pos is inside any known repair/rearm/refuel trigger zone.
    Checked live against FST_RRR_triggers instead of a cached per-player
    position, so it stays correct across respawns and multiple pads.
    params ["_pos"]
*/
params ["_pos"];

(FST_RRR_triggers findIf {
    private _area = triggerArea _x;
    (_pos distance2D (getPosATL _x)) < ((_area select 0) max (_area select 1))
}) != -1
