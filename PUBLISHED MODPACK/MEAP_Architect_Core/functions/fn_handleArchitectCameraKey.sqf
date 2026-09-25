params ["_event", ["_pressed", true, [true]]];
_event params ["", "_key", "_shift", "_control", "_alt"];

private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0) exitWith {false};

if (_pressed && {_key == 1}) exitWith
{
    [] call MEAP_fnc_closeArchitectCamera;
    true
};

private _keys = _state get "keys";
private _focusedControl = focusedCtrl (_state get "display");
// Text-entry focus owns every key, including WASD and arrows.
if (
    !isNull _focusedControl
    && {(ctrlIDC _focusedControl) isEqualTo 8823}
) exitWith
{
    _keys set [_key, false];
    false
};
_keys set [_key, _pressed];

if (_pressed) then
{
    switch (_key) do
    {
        case 28: {call MEAP_fnc_architectApplyAction;};
        case 211: {call MEAP_fnc_architectDeleteAction;};
        case 19:
        {
            private _direction = [-1, 1] select !_shift;
            _state set ["rotation", (_state get "rotation") + ((_state get "rotationStep") * _direction)];
        };
        case 34:
        {
            private _steps = [0, 0.1, 0.5, 1, 5];
            private _index = ((_steps find (_state get "gridSize")) + 1) mod count _steps;
            _state set ["gridSize", _steps select _index];
            private _control = (_state get "display") displayCtrl 8811;
            private _value = _state get "gridSize";
            _control ctrlSetText format ["GRID %1", [format ["%1m", _value], "OFF"] select (_value <= 0)];
        };
        case 35:
        {
            private _visible = !(_state get "guidesVisible");
            _state set ["guidesVisible", _visible];
            ((_state get "display") displayCtrl 8818) ctrlSetText format ["GUIDES %1", ["OFF", "ON"] select _visible];
        };
        case 36: {call MEAP_fnc_addArchitectZone;};
        case 37: {call MEAP_fnc_clearArchitectZones;};
        case 38:
        {
            private _visible = !(_state get "labelsVisible");
            _state set ["labelsVisible", _visible];
            ((_state get "display") displayCtrl 8819) ctrlSetText format ["LABELS %1", ["OFF", "ON"] select _visible];
        };
        case 20:
        {
            private _enabled = !(_state get "surfaceAlign");
            _state set ["surfaceAlign", _enabled];
            ((_state get "display") displayCtrl 8813) ctrlSetText format ["ALIGN %1", ["OFF", "ON"] select _enabled];
        };
        case 23:
        {
            private _enabled = !(_state get "ignoreObjects");
            _state set ["ignoreObjects", _enabled];
            ((_state get "display") displayCtrl 8822) ctrlSetText format ["IGNORE OBJECTS %1", ["OFF", "ON"] select _enabled];
        };
        case 46: {["CAPTURE"] call MEAP_fnc_architectBlueprintAction;};
        case 47: {["CYCLE"] call MEAP_fnc_architectBlueprintAction;};
        case 57: {["PLACE"] call MEAP_fnc_architectBlueprintAction;};
        case 48:
        {
            private _enabled = !(_state getOrDefault ["draftMode", false]);
            _state set ["draftMode", _enabled];
            [format ["Draft mode %1.", ["disabled", "enabled"] select _enabled]] call MEAP_fnc_architectMessage;
        };
        case 25: {call MEAP_fnc_architectPublishAction;};
        case 33:
        {
            private _sides = ["", "Left", "Right", "Front", "Back", "Top", "Bottom"];
            if ((_state getOrDefault ["snapCategory", ""]) isNotEqualTo "") then {_sides pushBack "Slot";};
            private _step = [-1, 1] select !_shift;
            private _index = ((_sides find (_state get "snapSide")) + _step) mod count _sides;
            if (_index < 0) then {_index = count _sides - 1;};
            private _side = _sides select _index;
            _state set ["snapSide", _side];
            _state set ["snapTarget", objNull];
            _state set ["snapPoint", ""];
            ((_state get "display") displayCtrl 8817) ctrlSetText format ["SNAP %1", [toUpper _side, "OFF"] select (_side isEqualTo "")];
        };
        case 44:
        {
            if (_control) then {call MEAP_fnc_architectUndo;};
        };
        case 21:
        {
            private _lastCreated = _state getOrDefault ["lastCreatedObject", objNull];
            if (!isNull _lastCreated) then
            {
                private _className = typeOf _lastCreated;
                _state set ["paletteFilter", ""];
                private _filterControl = _state getOrDefault ["paletteFilterControl", controlNull];
                if (!isNull _filterControl) then {_filterControl ctrlSetText "";};
                _state set ["paletteScrollIndex", 0];
                [] call MEAP_fnc_refreshArchitectPalette;
                [_className] call MEAP_fnc_selectArchitectPaletteItem;
            };
        };
        case 199: {_state set ["verticalOffset", 0];};
        case 201: {_state set ["verticalOffset", (_state get "verticalOffset") + (_state get "verticalStep")];};
        case 209: {_state set ["verticalOffset", (_state get "verticalOffset") - (_state get "verticalStep")];};
    };
};

_key in [1, 17, 19, 20, 21, 23, 25, 28, 30, 31, 32, 33, 34, 35, 36, 37, 38, 42, 44, 46, 47, 48, 54, 57, 199, 200, 201, 203, 205, 208, 209, 211]