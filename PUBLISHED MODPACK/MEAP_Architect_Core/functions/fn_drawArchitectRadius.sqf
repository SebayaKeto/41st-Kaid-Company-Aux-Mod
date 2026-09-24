private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (!(missionNamespace getVariable ["MEAP_Architect_cameraOpen", false]) || {count _state == 0}) exitWith {};

private _radius = _state getOrDefault ["radius", 0];
if (_radius <= 0 || {isNull player}) exitWith {};

private _centerASL = getPosASL player;
private _segments = 64;
private _step = 360 / _segments;
private _previewPosition = _state getOrDefault ["rawPreviewPosition", []];
private _previewValid = _state getOrDefault ["previewValid", false];
private _color = [[0.95, 0.28, 0.22, 0.72], [0.25, 0.95, 0.55, 0.72]] select (_previewPosition isEqualTo [] || {_previewValid});
private _rings =
[
    [[1, 0, 0], [0, 1, 0]],
    [[1, 0, 0], [0, 0, 1]],
    [[0, 1, 0], [0, 0, 1]]
];

{
    _x params ["_firstAxis", "_secondAxis"];
    private _previousASL = _centerASL vectorAdd (_firstAxis vectorMultiply _radius);

    for "_segment" from 1 to _segments do
    {
        private _angle = _segment * _step;
        private _nextASL = _centerASL
            vectorAdd (_firstAxis vectorMultiply (_radius * cos _angle))
            vectorAdd (_secondAxis vectorMultiply (_radius * sin _angle));

        drawLine3D [ASLToAGL _previousASL, ASLToAGL _nextASL, _color];
        _previousASL = _nextASL;
    };
} forEach _rings;

private _drawBounds =
{
    params ["_object", "_boundsColor"];
    if (isNull _object) exitWith {};

    (boundingBoxReal _object) params ["_minimum", "_maximum"];
    _minimum params ["_minX", "_minY", "_minZ"];
    _maximum params ["_maxX", "_maxY", "_maxZ"];
    private _corners =
    [
        [_minX, _minY, _minZ], [_maxX, _minY, _minZ],
        [_maxX, _maxY, _minZ], [_minX, _maxY, _minZ],
        [_minX, _minY, _maxZ], [_maxX, _minY, _maxZ],
        [_maxX, _maxY, _maxZ], [_minX, _maxY, _maxZ]
    ];
    private _edges =
    [
        [0, 1], [1, 2], [2, 3], [3, 0],
        [4, 5], [5, 6], [6, 7], [7, 4],
        [0, 4], [1, 5], [2, 6], [3, 7]
    ];
    {
        _x params ["_startIndex", "_endIndex"];
        drawLine3D
        [
            _object modelToWorldVisual (_corners select _startIndex),
            _object modelToWorldVisual (_corners select _endIndex),
            _boundsColor
        ];
    } forEach _edges;
};

private _ghost = _state getOrDefault ["ghost", objNull];
if (_previewValid && {!isNull _ghost}) then
{
    private _previewColor = [[1, 0.18, 0.12, 0.95], [0.25, 1, 0.42, 0.95]] select (_state getOrDefault ["canAfford", true]);
    [_ghost, _previewColor] call _drawBounds;
};

private _target = _state getOrDefault ["target", objNull];
if (!isNull _target) then
{
    private _targetColor = [[0.25, 0.8, 1, 0.95], [1, 0.82, 0.2, 0.95]] select (_target isEqualTo (_state getOrDefault ["selected", objNull]));
    [_target, _targetColor] call _drawBounds;
};

if (!_previewValid && {_previewPosition isEqualTypeParams [0, 0, 0]}) then
{
    private _center = ASLToAGL _previewPosition;
    private _size = 1.5;
    private _invalidColor = [1, 0.18, 0.12, 0.95];
    drawLine3D [_center vectorAdd [-_size, 0, 0], _center vectorAdd [_size, 0, 0], _invalidColor];
    drawLine3D [_center vectorAdd [0, -_size, 0], _center vectorAdd [0, _size, 0], _invalidColor];
    drawLine3D [_center vectorAdd [0, 0, -_size], _center vectorAdd [0, 0, _size], _invalidColor];
};

if (_state getOrDefault ["guidesVisible", true]) then
{
    private _placementPosition = _state getOrDefault ["previewPosition", []];
    if (_previewValid && {_placementPosition isEqualTypeParams [0, 0, 0]}) then
    {
        private _gridSize = (_state get "gridSize") max 0.5;
        private _extent = _gridSize * 5;
        private _guideColor = [0.35, 0.85, 1, 0.35];
        for "_index" from -5 to 5 do
        {
            private _offset = _index * _gridSize;
            private _lineOneStart = ASLToAGL (_placementPosition vectorAdd [-_extent, _offset, 0.02]);
            private _lineOneEnd = ASLToAGL (_placementPosition vectorAdd [_extent, _offset, 0.02]);
            private _lineTwoStart = ASLToAGL (_placementPosition vectorAdd [_offset, -_extent, 0.02]);
            private _lineTwoEnd = ASLToAGL (_placementPosition vectorAdd [_offset, _extent, 0.02]);
            drawLine3D [_lineOneStart, _lineOneEnd, _guideColor];
            drawLine3D [_lineTwoStart, _lineTwoEnd, _guideColor];
        };
    };

    private _snapCategory = _state getOrDefault ["snapCategory", ""];
    private _activeSnapTarget = _state getOrDefault ["snapTarget", objNull];
    private _activeSnapPoint = _state getOrDefault ["snapPoint", ""];
    {
        _x params ["_slotTarget", "_slotPoint"];
        if (!isNull _slotTarget) then
        {
            private _slotPosition = _slotTarget modelToWorldVisual (_slotTarget selectionPosition [_slotPoint, "Memory"]);
            private _isActive = _slotTarget isEqualTo _activeSnapTarget && {_slotPoint isEqualTo _activeSnapPoint};
            private _slotColor = [[0.2, 1, 0.72, 0.95], [1, 0.85, 0.18, 1]] select _isActive;
            private _slotSize = [0.3, 0.5] select _isActive;
            drawLine3D [_slotPosition vectorAdd [-_slotSize, 0, 0], _slotPosition vectorAdd [_slotSize, 0, 0], _slotColor];
            drawLine3D [_slotPosition vectorAdd [0, -_slotSize, 0], _slotPosition vectorAdd [0, _slotSize, 0], _slotColor];
            drawLine3D [_slotPosition vectorAdd [0, 0, -_slotSize], _slotPosition vectorAdd [0, 0, _slotSize], _slotColor];
            drawIcon3D
            [
                "",
                _slotColor,
                _slotPosition vectorAdd [0, 0, _slotSize + 0.15],
                0,
                0,
                0,
                format ["%1 SLOT", toUpper _snapCategory],
                1,
                [0.026, 0.034] select _isActive,
                "PuristaMedium",
                "center"
            ];
        };
    } forEach (_state getOrDefault ["compatibleSnapSlots", []]);

    private _pointNames =
    [
        "MEAP_SnapPoint_Left", "MEAP_SnapPoint_Right",
        "MEAP_SnapPoint_Front", "MEAP_SnapPoint_Back",
        "MEAP_SnapPoint_Top", "MEAP_SnapPoint_Bottom"
    ];
    {
        private _object = _x;
        if (!isNull _object) then
        {
            private _memoryNames = (_object selectionNames "Memory") apply {toLower _x};
            {
                if ((toLower _x) in _memoryNames) then
                {
                    private _pointPosition = _object modelToWorldVisual (_object selectionPosition [_x, "Memory"]);
                    drawIcon3D ["", [1, 0.72, 0.2, 0.95], _pointPosition, 0, 0, 0, _x select [15], 1, 0.028, "PuristaMedium", "center"];
                };
            } forEach _pointNames;
        };
    } forEach [_ghost, _state getOrDefault ["snapTarget", objNull]];
};

if (_state getOrDefault ["labelsVisible", true]) then
{
    {
        private _object = _x;
        if (!isNull _object) then
        {
            private _config = configFile >> "CfgVehicles" >> typeOf _object;
            private _name = getText (_config >> "displayName");
            private _distance = (getPosASL _object) distance (getPosASL player);
            private _labelPosition = ASLToAGL ((getPosASL _object) vectorAdd [0, 0, ((boundingBoxReal _object select 1) select 2) + 0.5]);
            drawIcon3D ["", [0.85, 0.95, 1, 0.95], _labelPosition, 0, 0, 0, format ["%1 | %2m", _name, _distance toFixed 1], 1, 0.032, "PuristaMedium", "center"];
        };
    } forEach [_target, _state getOrDefault ["snapTarget", objNull]];
};

{
    _x params ["_zoneCenter", "_zoneRadius", "_zoneName"];
    private _zoneColor = [0.25, 0.65, 1, 0.38];
    private _zoneSegments = 32;
    private _zoneStep = 360 / _zoneSegments;
    {
        _x params ["_firstAxis", "_secondAxis"];
        private _previousASL = _zoneCenter vectorAdd (_firstAxis vectorMultiply _zoneRadius);
        for "_segment" from 1 to _zoneSegments do
        {
            private _angle = _segment * _zoneStep;
            private _nextASL = _zoneCenter
                vectorAdd (_firstAxis vectorMultiply (_zoneRadius * cos _angle))
                vectorAdd (_secondAxis vectorMultiply (_zoneRadius * sin _angle));
            drawLine3D [ASLToAGL _previousASL, ASLToAGL _nextASL, _zoneColor];
            _previousASL = _nextASL;
        };
    } forEach _rings;
    drawIcon3D ["", [0.45, 0.8, 1, 0.95], ASLToAGL (_zoneCenter vectorAdd [0, 0, _zoneRadius]), 0, 0, 0, format ["%1 | %2m", _zoneName, _zoneRadius], 1, 0.035, "PuristaMedium", "center"];
} forEach (_state getOrDefault ["zones", []]);