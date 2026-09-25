params [
    ["_classes", [], [[]]],
    ["_radius", 50, [0]],
    ["_token", "", [""]],
    ["_budgetEnabled", false, [true]],
    ["_currencyName", "Republic Credits", [""]],
    ["_availableFunds", -1, [0]],
    ["_blueprints", [], [[]]]
];

if (!hasInterface) exitWith {};
if (isRemoteExecuted && {remoteExecutedOwner != 2}) exitWith {};
if (_classes isEqualTo [] || {_token isEqualTo ""}) exitWith
{
    ["Daidalos received an invalid camera session."] call MEAP_fnc_architectMessage;
    [player, false] remoteExecCall ["MEAP_fnc_closeArchitectMode", 2];
};
if (missionNamespace getVariable ["MEAP_Architect_cameraOpen", false]) then
{
    [false] call MEAP_fnc_closeArchitectCamera;
};

disableSerialization;
private _display = findDisplay 46 createDisplay "RscDisplayEmpty";
if (isNull _display) exitWith
{
    ["Daidalos could not create its camera display."] call MEAP_fnc_architectMessage;
    [player, false] remoteExecCall ["MEAP_fnc_closeArchitectMode", 2];
};

private _startPosition = eyePos player vectorAdd [0, 0, 5];
private _camera = "camera" camCreate (ASLToAGL _startPosition);
_camera setPosASL _startPosition;
private _yaw = getDirVisual player;
private _pitch = -20;
private _direction = [sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch];
private _right = [cos _yaw, -sin _yaw, 0];
private _up = _right vectorCrossProduct _direction;
_camera setVectorDirAndUp [_direction, _up];
_camera camSetFov 0.7;
_camera camCommit 0;
_camera cameraEffect ["INTERNAL", "BACK"];
showCinemaBorder false;

private _panelLeft = safeZoneX + safeZoneW - 0.4;
private _contentLeft = _panelLeft + 0.015;
private _contentWidth = 0.35;

private _primarySurface = _display ctrlCreate ["RscText", 8799];
_primarySurface ctrlSetText "";
_primarySurface ctrlSetTextColor [0, 0, 0, 0];
_primarySurface ctrlSetBackgroundColor [0, 0, 0, 0];
_primarySurface ctrlSetPosition [safeZoneX, safeZoneY, safeZoneW - 0.4, safeZoneH];
_primarySurface ctrlCommit 0;
_primarySurface ctrlAddEventHandler ["MouseButtonDown", {
    params ["", "_button"];
    if (_button isEqualTo 0) exitWith {call MEAP_fnc_architectPrimaryAction; true};
    false
}];

private _panel = _display ctrlCreate ["RscText", 8800];
_panel ctrlSetBackgroundColor [0.03, 0.04, 0.04, 0.88];
_panel ctrlSetPosition [_panelLeft, safeZoneY + 0.06, 0.38, 0.85];
_panel ctrlCommit 0;

private _title = _display ctrlCreate ["RscText", 8801];
_title ctrlSetText "MEAP DAIDALOS";
_title ctrlSetTextColor [0.74, 0.9, 0.78, 1];
_title ctrlSetPosition [_contentLeft, safeZoneY + 0.075, _contentWidth, 0.035];
_title ctrlCommit 0;

private _filterLabel = _display ctrlCreate ["RscText", 8826];
_filterLabel ctrlSetText "FILTER OBJECTS / GROUPS";
_filterLabel ctrlSetTextColor [0.74, 0.9, 0.78, 0.9];
_filterLabel ctrlSetPosition [_contentLeft, safeZoneY + 0.115, _contentWidth, 0.022];
_filterLabel ctrlCommit 0;

private _search = _display ctrlCreate ["RscEdit", 8823];
_search ctrlSetText "";
_search ctrlSetTooltip "Filter available objects and groups";
_search ctrlSetPosition [_contentLeft, safeZoneY + 0.137, _contentWidth, 0.03];
_search ctrlCommit 0;

private _paletteSurface = _display ctrlCreate ["RscText", 8802];
_paletteSurface ctrlSetBackgroundColor [0.01, 0.02, 0.01, 0.72];
_paletteSurface ctrlSetPosition [_contentLeft, safeZoneY + 0.173, _contentWidth, 0.222];
_paletteSurface ctrlCommit 0;

private _paletteRows = [];
private _paletteRowHeight = 0.02775;
for "_rowIndex" from 0 to 7 do
{
    private _row = _display ctrlCreate ["RscButton", 8830 + _rowIndex];
    _row ctrlSetTextColor [0.88, 0.96, 0.88, 1];
    _row ctrlSetFontHeight 0.019;
    _row ctrlSetTooltip "Select object for placement";
    _row ctrlSetPosition [_contentLeft, safeZoneY + 0.173 + (_rowIndex * _paletteRowHeight), _contentWidth - 0.04, _paletteRowHeight - 0.001];
    _row ctrlCommit 0;
    _row ctrlAddEventHandler ["ButtonClick", {
        params ["_control"];
        private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
        if (count _state == 0) exitWith {};
        private _rowIndex = (ctrlIDC _control) - 8830;
        private _entry = (_state getOrDefault ["paletteVisibleEntries", []]) param [_rowIndex, []];
        if (_entry isEqualTo []) exitWith {};
        _entry params ["_entryType", "_identifier"];
        switch _entryType do
        {
            case "OBJECT": {[_identifier] call MEAP_fnc_selectArchitectPaletteItem;};
            case "BUILD": {["SELECT", _identifier] call MEAP_fnc_architectBlueprintAction;};
        };
    }];
    _row ctrlAddEventHandler ["MouseZChanged", {
        params ["", "_scroll"];
        if (_scroll != 0) then {[-_scroll] call MEAP_fnc_refreshArchitectPalette;};
    }];
    _paletteRows pushBack _row;
};

private _paletteScrollUp = _display ctrlCreate ["RscButton", 8840];
_paletteScrollUp ctrlSetText "^";
_paletteScrollUp ctrlSetTooltip "Show previous objects";
_paletteScrollUp ctrlSetPosition [_contentLeft + _contentWidth - 0.035, safeZoneY + 0.173, 0.035, 0.108];
_paletteScrollUp ctrlCommit 0;
_paletteScrollUp ctrlAddEventHandler ["ButtonClick", {[-1] call MEAP_fnc_refreshArchitectPalette;}];

private _paletteScrollDown = _display ctrlCreate ["RscButton", 8841];
_paletteScrollDown ctrlSetText "v";
_paletteScrollDown ctrlSetTooltip "Show next objects";
_paletteScrollDown ctrlSetPosition [_contentLeft + _contentWidth - 0.035, safeZoneY + 0.287, 0.035, 0.108];
_paletteScrollDown ctrlCommit 0;
_paletteScrollDown ctrlAddEventHandler ["ButtonClick", {[1] call MEAP_fnc_refreshArchitectPalette;}];

private _place = _display ctrlCreate ["RscButton", 8803];
_place ctrlSetText "PLACE";
_place ctrlSetPosition [_contentLeft, safeZoneY + 0.405, 0.11, 0.04];
_place ctrlCommit 0;

private _clearPreview = _display ctrlCreate ["RscButton", 8842];
_clearPreview ctrlSetText "CLEAR";
_clearPreview ctrlSetTooltip "Remove the placement preview";
_clearPreview ctrlSetPosition [_contentLeft + 0.12, safeZoneY + 0.405, 0.11, 0.04];
_clearPreview ctrlCommit 0;

private _edit = _display ctrlCreate ["RscButton", 8804];
_edit ctrlSetText "EDIT";
_edit ctrlSetPosition [_contentLeft + 0.24, safeZoneY + 0.405, 0.11, 0.04];
_edit ctrlCommit 0;

private _delete = _display ctrlCreate ["RscButton", 8805];
_delete ctrlSetText "DELETE";
_delete ctrlSetPosition [_contentLeft, safeZoneY + 0.455, 0.105, 0.04];
_delete ctrlCommit 0;

private _undo = _display ctrlCreate ["RscButton", 8816];
_undo ctrlSetText "UNDO";
_undo ctrlSetPosition [_contentLeft + 0.115, safeZoneY + 0.455, 0.105, 0.04];
_undo ctrlCommit 0;

private _rotateLeft = _display ctrlCreate ["RscButton", 8806];
_rotateLeft ctrlSetText "<";
_rotateLeft ctrlSetPosition [_contentLeft + 0.23, safeZoneY + 0.455, 0.055, 0.04];
_rotateLeft ctrlCommit 0;

private _rotateRight = _display ctrlCreate ["RscButton", 8807];
_rotateRight ctrlSetText ">";
_rotateRight ctrlSetPosition [_contentLeft + 0.295, safeZoneY + 0.455, 0.055, 0.04];
_rotateRight ctrlCommit 0;

private _grid = _display ctrlCreate ["RscButton", 8811];
_grid ctrlSetPosition [_contentLeft, safeZoneY + 0.505, 0.17, 0.04];
_grid ctrlCommit 0;

private _rotationStep = _display ctrlCreate ["RscButton", 8812];
_rotationStep ctrlSetPosition [_contentLeft + 0.18, safeZoneY + 0.505, 0.17, 0.04];
_rotationStep ctrlCommit 0;

private _align = _display ctrlCreate ["RscButton", 8813];
_align ctrlSetPosition [_contentLeft, safeZoneY + 0.555, 0.17, 0.04];
_align ctrlCommit 0;

private _offsetDown = _display ctrlCreate ["RscButton", 8814];
_offsetDown ctrlSetText "LOWER";
_offsetDown ctrlSetPosition [_contentLeft + 0.18, safeZoneY + 0.555, 0.08, 0.04];
_offsetDown ctrlCommit 0;

private _offsetUp = _display ctrlCreate ["RscButton", 8815];
_offsetUp ctrlSetText "RAISE";
_offsetUp ctrlSetPosition [_contentLeft + 0.27, safeZoneY + 0.555, 0.08, 0.04];
_offsetUp ctrlCommit 0;

private _ignoreObjects = _display ctrlCreate ["RscButton", 8822];
_ignoreObjects ctrlSetText "IGNORE OBJECTS OFF";
_ignoreObjects ctrlSetPosition [_contentLeft, safeZoneY + 0.605, _contentWidth, 0.04];
_ignoreObjects ctrlCommit 0;

private _snap = _display ctrlCreate ["RscButton", 8817];
_snap ctrlSetText "SNAP OFF";
_snap ctrlSetPosition [_contentLeft, safeZoneY + 0.655, _contentWidth, 0.04];
_snap ctrlCommit 0;

private _guides = _display ctrlCreate ["RscButton", 8818];
_guides ctrlSetText "GUIDES ON";
_guides ctrlSetPosition [_contentLeft, safeZoneY + 0.705, 0.17, 0.04];
_guides ctrlCommit 0;

private _labels = _display ctrlCreate ["RscButton", 8819];
_labels ctrlSetText "LABELS ON";
_labels ctrlSetPosition [_contentLeft + 0.18, safeZoneY + 0.705, 0.17, 0.04];
_labels ctrlCommit 0;

private _addZone = _display ctrlCreate ["RscButton", 8820];
_addZone ctrlSetText "ADD ZONE";
_addZone ctrlSetPosition [_contentLeft, safeZoneY + 0.755, 0.17, 0.04];
_addZone ctrlCommit 0;

private _clearZones = _display ctrlCreate ["RscButton", 8821];
_clearZones ctrlSetText "CLEAR ZONES";
_clearZones ctrlSetPosition [_contentLeft + 0.18, safeZoneY + 0.755, 0.17, 0.04];
_clearZones ctrlCommit 0;

private _status = _display ctrlCreate ["RscStructuredText", 8809];
_status ctrlSetStructuredText parseText "PLACE";
_status ctrlSetTextColor [0.74, 0.9, 0.78, 1];
_status ctrlSetPosition [_contentLeft, safeZoneY + 0.795, _contentWidth, 0.065];
_status ctrlCommit 0;

private _close = _display ctrlCreate ["RscButton", 8808];
_close ctrlSetText "CLOSE";
_close ctrlSetPosition [_contentLeft, safeZoneY + 0.865, _contentWidth, 0.04];
_close ctrlCommit 0;

private _crosshair = _display ctrlCreate ["RscText", 8810];
_crosshair ctrlSetText "+";
_crosshair ctrlSetTextColor [1, 1, 1, 0.9];
_crosshair ctrlSetPosition [safeZoneX + safeZoneW * 0.5 - 0.01, safeZoneY + safeZoneH * 0.5 - 0.02, 0.03, 0.04];
_crosshair ctrlCommit 0;

private _paletteEntries = [];
{
    private _className = _x;
    private _config = configFile >> "CfgVehicles" >> _className;
    private _displayName = getText (_config >> "displayName");
    if (_displayName isEqualTo "") then {_displayName = _className;};
    private _cost = if (_budgetEnabled) then {[_className] call MEAP_fnc_getArchitectBuildCost} else {0};
    _paletteEntries pushBack ["OBJECT", _className, _displayName, _cost];
} forEach _classes;
{
    _x params ["_id", "_name"];
    _paletteEntries pushBack ["BUILD", _id, _name, 0];
} forEach _blueprints;

MEAP_Architect_cameraState = createHashMapFromArray
[
    ["camera", _camera],
    ["display", _display],
    ["classes", _classes],
    ["paletteEntries", _paletteEntries],
    ["primarySurfaceControl", _primarySurface],
    ["paletteControl", _paletteSurface],
    ["paletteRows", _paletteRows],
    ["paletteVisibleEntries", []],
    ["paletteScrollIndex", 0],
    ["paletteFilterControl", _search],
    ["paletteFilter", ""],
    ["paletteRefreshing", false],
    ["paletteRevealSelection", false],
    ["paletteWheelMode", false],
    ["paletteWheelOpen", false],
    ["paletteWheelControls", []],
    ["paletteWheelEntries", []],
    ["paletteWheelHoverIndex", -1],
    ["paletteWheelHoverAt", -1],
    ["radius", _radius],
    ["token", _token],
    ["placeControl", _place],
    ["budgetEnabled", _budgetEnabled],
    ["currencyName", _currencyName],
    ["availableFunds", _availableFunds],
    ["blueprints", _blueprints],
    ["blueprintIndex", 0],
    ["selectionType", "OBJECT"],
    ["selectedBlueprintId", ""],
    ["canAfford", true],
    ["selectedBuildCost", 0],
    ["draftMode", false],
    ["keys", createHashMap],
    ["yaw", _yaw],
    ["pitch", _pitch],
    ["rotation", 0],
    ["gridSize", missionNamespace getVariable ["MEAP_Architect_gridSize", 0.5]],
    ["rotationStep", missionNamespace getVariable ["MEAP_Architect_rotationStep", 15]],
    ["surfaceAlign", missionNamespace getVariable ["MEAP_Architect_surfaceAlign", true]],
    ["snapSide", ""],
    ["snapTarget", objNull],
    ["snapPoint", ""],
    ["snapCategory", ""],
    ["compatibleSnapSlots", []],
    ["nextSnapSlotScan", 0],
    ["guidesVisible", true],
    ["labelsVisible", true],
    ["zones", []],
    ["zoneCounter", 0],
    ["verticalOffset", 0],
    ["verticalStep", missionNamespace getVariable ["MEAP_Architect_verticalStep", 0.1]],
    ["ignoreObjects", false],
    ["classIndex", 0],
    ["mode", "PLACE"],
    ["target", objNull],
    ["selected", objNull],
    ["actionPending", false],
    ["pendingAction", ""],
    ["pendingObject", objNull],
    ["pendingAt", -1],
    ["mouseLook", false],
    ["previewValid", false],
    ["previewPosition", []],
    ["previewVectors", []],
    ["previewActive", false],
    ["statusControl", _status]
];
MEAP_Architect_cameraOpen = true;

[] call MEAP_fnc_refreshArchitectPalette;

private _gridSize = MEAP_Architect_cameraState get "gridSize";
_grid ctrlSetText format ["GRID %1", [format ["%1m", _gridSize], "OFF"] select (_gridSize <= 0)];
_rotationStep ctrlSetText format ["ROT %1", MEAP_Architect_cameraState get "rotationStep"];
_align ctrlSetText format ["ALIGN %1", ["OFF", "ON"] select (MEAP_Architect_cameraState get "surfaceAlign")];

private _oldRadiusDrawHandler = missionNamespace getVariable ["MEAP_Architect_radiusDrawHandler", -1];
if (_oldRadiusDrawHandler >= 0) then
{
    removeMissionEventHandler ["Draw3D", _oldRadiusDrawHandler];
};
MEAP_Architect_radiusDrawHandler = addMissionEventHandler ["Draw3D", {
    call MEAP_fnc_drawArchitectRadius;
}];

_display displayAddEventHandler ["KeyDown", {[_this, true] call MEAP_fnc_handleArchitectCameraKey}];
_display displayAddEventHandler ["KeyUp", {[_this, false] call MEAP_fnc_handleArchitectCameraKey}];
_search ctrlAddEventHandler ["KeyUp", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    _state set ["paletteFilter", ctrlText _control];
    _state set ["paletteScrollIndex", 0];
    [] call MEAP_fnc_refreshArchitectPalette;
}];
_display displayAddEventHandler ["Unload", {
    if (missionNamespace getVariable ["MEAP_Architect_cameraOpen", false]) then
    {
        [] call MEAP_fnc_closeArchitectCamera;
    };
}];
_clearPreview ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_clearArchitectPreview}];
_place ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_architectApplyAction}];
_edit ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_architectSelectEdit}];
_delete ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_architectDeleteAction}];
_undo ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_architectUndo}];
_rotateLeft ctrlAddEventHandler ["ButtonClick", {
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    _state set ["rotation", (_state get "rotation") - (_state get "rotationStep")];
}];
_rotateRight ctrlAddEventHandler ["ButtonClick", {
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    _state set ["rotation", (_state get "rotation") + (_state get "rotationStep")];
}];
_grid ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _steps = [0, 0.1, 0.5, 1, 5];
    private _index = ((_steps find (_state get "gridSize")) + 1) mod count _steps;
    private _value = _steps select _index;
    _state set ["gridSize", _value];
    _control ctrlSetText format ["GRID %1", [format ["%1m", _value], "OFF"] select (_value <= 0)];
}];
_rotationStep ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _steps = [1, 5, 15, 45];
    private _index = ((_steps find (_state get "rotationStep")) + 1) mod count _steps;
    private _value = _steps select _index;
    _state set ["rotationStep", _value];
    _control ctrlSetText format ["ROT %1", _value];
}];
_align ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _enabled = !(_state get "surfaceAlign");
    _state set ["surfaceAlign", _enabled];
    _control ctrlSetText format ["ALIGN %1", ["OFF", "ON"] select _enabled];
}];
_offsetDown ctrlAddEventHandler ["ButtonClick", {
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state > 0) then {_state set ["verticalOffset", (_state get "verticalOffset") - (_state get "verticalStep")];};
}];
_offsetUp ctrlAddEventHandler ["ButtonClick", {
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state > 0) then {_state set ["verticalOffset", (_state get "verticalOffset") + (_state get "verticalStep")];};
}];
_ignoreObjects ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _enabled = !(_state get "ignoreObjects");
    _state set ["ignoreObjects", _enabled];
    _control ctrlSetText format ["IGNORE OBJECTS %1", ["OFF", "ON"] select _enabled];
}];
_snap ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _sides = ["", "Left", "Right", "Front", "Back", "Top", "Bottom"];
    if ((_state getOrDefault ["snapCategory", ""]) isNotEqualTo "") then {_sides pushBack "Slot";};
    private _index = ((_sides find (_state get "snapSide")) + 1) mod count _sides;
    private _side = _sides select _index;
    _state set ["snapSide", _side];
    _state set ["snapTarget", objNull];
    _state set ["snapPoint", ""];
    _control ctrlSetText format ["SNAP %1", [toUpper _side, "OFF"] select (_side isEqualTo "")];
}];
_guides ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _visible = !(_state get "guidesVisible");
    _state set ["guidesVisible", _visible];
    _control ctrlSetText format ["GUIDES %1", ["OFF", "ON"] select _visible];
}];
_labels ctrlAddEventHandler ["ButtonClick", {
    params ["_control"];
    private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
    if (count _state == 0) exitWith {};
    private _visible = !(_state get "labelsVisible");
    _state set ["labelsVisible", _visible];
    _control ctrlSetText format ["LABELS %1", ["OFF", "ON"] select _visible];
}];
_addZone ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_addArchitectZone}];
_clearZones ctrlAddEventHandler ["ButtonClick", {call MEAP_fnc_clearArchitectZones}];
_close ctrlAddEventHandler ["ButtonClick", {[] call MEAP_fnc_closeArchitectCamera}];

[_classes select 0] call MEAP_fnc_createArchitectGhost;
MEAP_Architect_cameraPFH = [MEAP_fnc_architectCameraTick, 0] call CBA_fnc_addPerFrameHandler;