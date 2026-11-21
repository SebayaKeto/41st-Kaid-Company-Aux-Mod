/*
    BUZZ_fnc_zvAddContextMenu
    Adds to the ZEN Zeus right-click menu:
        Show Trooper Details > 50 m / 100 m / 250 m / 1 km / 2.5 km / Clear
*/
private _parent = [
    "BUZZ_zv_details", "Show Trooper Details",
    "\a3\ui_f\data\igui\cfg\simpletasks\types\scout_ca.paa",
    {}, { true }
] call zen_context_menu_fnc_createAction;
[_parent, [], 0] call zen_context_menu_fnc_addAction;

private _radii = [50, 100, 250, 1000, 2500];
{
    private _label = if (_x >= 1000) then { format ["%1 km", _x / 1000] } else { format ["%1 m", _x] };
    private _child = [
        format ["BUZZ_zv_r%1", _x], _label, "",
        {
            params ["_position", "", "", "", "", "", "_radius"];
            [_position, _radius] call BUZZ_fnc_zvSelect;
        },
        { true }, _x
    ] call zen_context_menu_fnc_createAction;
    [_child, ["BUZZ_zv_details"], 100 - _forEachIndex] call zen_context_menu_fnc_addAction;   // keep smallest first
} forEach _radii;

// Every player on the server, yourself included. Live list: players who
// join or respawn later are picked up automatically.
private _all = [
    "BUZZ_zv_all", "All players", "",
    {
        BUZZ_zv_trackAll = true;
        BUZZ_zv_tracked = [];
        BUZZ_zv_nextRefresh = 0;
        ["Trooper details: all players"] call zen_common_fnc_showMessage;
    },
    { true }
] call zen_context_menu_fnc_createAction;
[_all, ["BUZZ_zv_details"], 50] call zen_context_menu_fnc_addAction;

private _clear = [
    "BUZZ_zv_clear", "Clear", "",
    {
        BUZZ_zv_trackAll = false;
        BUZZ_zv_tracked = [];
        BUZZ_zv_cache = [];
        ["Trooper details cleared"] call zen_common_fnc_showMessage;
    },
    { BUZZ_zv_trackAll || { BUZZ_zv_tracked isNotEqualTo [] } }
] call zen_context_menu_fnc_createAction;
[_clear, ["BUZZ_zv_details"], 0] call zen_context_menu_fnc_addAction;
