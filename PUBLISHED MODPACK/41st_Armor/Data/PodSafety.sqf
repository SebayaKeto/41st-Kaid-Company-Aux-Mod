// Bounded pod anchor selection. Keep the master array intact for cleanup.
FST_fnc_nextPodAnchor = {
    params [["_anchors",[]], ["_remaining",[]]];
    if (!(_anchors isEqualType []) || {!(_remaining isEqualType [])}) exitWith {[]};
    private _live=_anchors select {_x isEqualType objNull && {!isNull _x}};
    _remaining=_remaining select {_x in _live};
    if (count _remaining==0) then {_remaining=+_live};
    if (count _remaining==0) exitWith {[]};
    private _anchor=_remaining deleteAt floor random count _remaining;
    [_anchor,_remaining]
};
FST_fnc_validPodPosition = {
    params [["_position",[]]];
    _position isEqualType [] && {count _position==3} && {
        (_position findIf {!(_x isEqualType 0) || {!finite _x}})<0
    }
};
FST_fnc_podGroundASL = {
    params [["_anchor",objNull]];
    if (!(_anchor isEqualType objNull) || {isNull _anchor}) exitWith {[]};
    private _p=getPosATL _anchor;
    // Dispenser's public contract is ASL; caller starts at local terrain level.
    ATLToASL [_p select 0,_p select 1,0]
};
