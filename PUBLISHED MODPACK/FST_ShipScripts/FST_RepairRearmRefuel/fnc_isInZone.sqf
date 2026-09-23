/*
    FST_fnc_RRR_isInZone
    Returns true if a position is inside any registered service zone.
*/
params ["_pos"];

(FST_RRR_triggers findIf {
    private _area = triggerArea _x;
    (_pos distance2D (getPosATL _x)) < ((_area select 0) max (_area select 1))
}) != -1
