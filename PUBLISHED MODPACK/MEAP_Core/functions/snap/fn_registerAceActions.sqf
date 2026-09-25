if (!hasInterface) exitWith {};
if (isDedicated) exitWith {};

[
    "House_F",
    0,
    ["ACE_MainActions"],
    [
        "MEAP_Snap_SetSource",
        "Set Snap Source",
        "",
        {
            [_target, _player] call MEAP_fnc_setSnapSource;
        },
        {
            [_target] call MEAP_fnc_isSnappable
        }
    ] call ace_interact_menu_fnc_createAction
] call ace_interact_menu_fnc_addActionToClass;

[
    "House_F",
    0,
    ["ACE_MainActions"],
    [
        "MEAP_Snap_ClearSource",
        "Clear Snap Source",
        "",
        {
            _player setVariable ["MEAP_snapSource", objNull, false];
            ["MEAP: Snap source cleared."] call CBA_fnc_notify;
        },
        {
            !isNull (_player getVariable ["MEAP_snapSource", objNull])
        }
    ] call ace_interact_menu_fnc_createAction
] call ace_interact_menu_fnc_addActionToClass;

{
    private _side = _x;
    private _actionId = format ["MEAP_Snap_To_%1", _side];
    private _actionLabel = format ["Snap Source To %1", _side];

    [
        "House_F",
        0,
        ["ACE_MainActions"],
        [
            _actionId,
            _actionLabel,
            "",
            {
                params ["_target", "_player", "_side"];
                [_target, _player, _side] call MEAP_fnc_snapSourceToTarget;
            },
            {
                params ["_target", "_player", "_side"];

                private _source = _player getVariable ["MEAP_snapSource", objNull];
                if (isNull _source || {_source isEqualTo _target}) exitWith {false};

                private _targetPointName = [_side] call MEAP_fnc_pointNameFromSide;
                private _sourceSide = [_side] call MEAP_fnc_oppositeSide;
                private _sourcePointName = [_sourceSide] call MEAP_fnc_pointNameFromSide;

                if (_targetPointName isEqualTo "" || {_sourcePointName isEqualTo ""}) exitWith {false};

                private _targetSelections = (_target selectionNames "Memory") apply {toLower _x};
                private _sourceSelections = (_source selectionNames "Memory") apply {toLower _x};

                ((toLower _targetPointName) in _targetSelections) &&
                {(toLower _sourcePointName) in _sourceSelections}
            },
            {},
            _side
        ] call ace_interact_menu_fnc_createAction
    ] call ace_interact_menu_fnc_addActionToClass;
} forEach ["Left", "Right", "Front", "Back", "Top", "Bottom"];
