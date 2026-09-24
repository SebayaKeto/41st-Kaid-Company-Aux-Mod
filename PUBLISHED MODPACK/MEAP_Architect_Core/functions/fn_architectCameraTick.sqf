private _state = missionNamespace getVariable ["MEAP_Architect_cameraState", createHashMap];
if (count _state == 0 || {!alive player}) exitWith
{
    [] call MEAP_fnc_closeArchitectCamera;
};

if (
    _state getOrDefault ["actionPending", false]
    && {diag_tickTime - (_state getOrDefault ["pendingAt", diag_tickTime]) > 10}
) then
{
    private _pendingObject = _state getOrDefault ["pendingObject", objNull];
    if (!isNull _pendingObject) then
    {
        _pendingObject hideObject false;
        ["UNLOCK", player, _state get "token", [_pendingObject]] remoteExecCall ["MEAP_fnc_architectServerAction", 2];
    };
    if (_pendingObject isEqualTo (_state getOrDefault ["selected", objNull])) then
    {
        _state set ["selected", objNull];
        _state set ["mode", "PLACE"];
        private _classIndex = _state get "classIndex";
        [((_state get "classes") param [_classIndex, ""])] call MEAP_fnc_createArchitectGhost;
    };
    _state set ["actionPending", false];
    _state set ["pendingAction", ""];
    _state set ["pendingObject", objNull];
    _state set ["pendingAt", -1];
    ["The server did not respond; the construction action was cancelled."] call MEAP_fnc_architectMessage;
};

private _camera = _state get "camera";
private _display = _state get "display";
if (isNull _camera || {isNull _display}) exitWith
{
    [] call MEAP_fnc_closeArchitectCamera;
};

private _keys = _state get "keys";
private _yaw = _state get "yaw";
private _pitch = _state get "pitch";
private _turnSpeed = (missionNamespace getVariable ["MEAP_Architect_keyTurnSpeed", 70]) * diag_deltaTime;
if (_keys getOrDefault [203, false]) then {_yaw = _yaw - _turnSpeed;};
if (_keys getOrDefault [205, false]) then {_yaw = _yaw + _turnSpeed;};
if (_keys getOrDefault [200, false]) then {_pitch = (_pitch + _turnSpeed) min 85;};
if (_keys getOrDefault [208, false]) then {_pitch = (_pitch - _turnSpeed) max -85;};
_state set ["yaw", _yaw];
_state set ["pitch", _pitch];

private _direction = [sin _yaw * cos _pitch, cos _yaw * cos _pitch, sin _pitch];
private _forward = [sin _yaw, cos _yaw, 0];
private _right = [cos _yaw, -sin _yaw, 0];
private _movement = [0, 0, 0];
if (_keys getOrDefault [17, false]) then {_movement = _movement vectorAdd _forward;};
if (_keys getOrDefault [31, false]) then {_movement = _movement vectorDiff _forward;};
if (_keys getOrDefault [32, false]) then {_movement = _movement vectorAdd _right;};
if (_keys getOrDefault [30, false]) then {_movement = _movement vectorDiff _right;};

private _speed =
[
    missionNamespace getVariable ["MEAP_Architect_cameraMoveSpeed", 10],
    missionNamespace getVariable ["MEAP_Architect_cameraFastMoveSpeed", 30]
] select ((_keys getOrDefault [42, false]) || {_keys getOrDefault [54, false]});
private _position = getPosASL _camera;
if (vectorMagnitude _movement > 0) then
{
    _movement = vectorNormalized _movement vectorMultiply (_speed * diag_deltaTime);
    private _candidate = _position vectorAdd _movement;
    private _radius = _state get "radius";
    private _terrain = getTerrainHeightASL [_candidate select 0, _candidate select 1];
    _candidate set [2, ((_candidate select 2) max (_terrain + 1)) min ((getPosASL player select 2) + _radius)];
    if (_candidate distance (getPosASL player) <= _radius) then
    {
        _position = _candidate;
    };
};
_camera setPosASL _position;
private _cameraRight = [cos _yaw, -sin _yaw, 0];
private _cameraUp = _cameraRight vectorCrossProduct _direction;
_camera setVectorDirAndUp [_direction, _cameraUp];

private _ghost = _state getOrDefault ["ghost", objNull];
private _previewActive = _state getOrDefault ["previewActive", false] && {!isNull _ghost};
private _snapCategory = _state getOrDefault ["snapCategory", ""];
if (_snapCategory isNotEqualTo "" && {diag_tickTime >= (_state getOrDefault ["nextSnapSlotScan", 0])}) then
{
    private _compatibleSlots = [];
    private _selected = _state getOrDefault ["selected", objNull];
    private _scanRadius = ((_state get "radius") min 100) max 25;
    private _nearbyObjects = nearestObjects [ASLToAGL _position, [], _scanRadius];
    {
        private _slotTarget = _x;
        if (
            _slotTarget isNotEqualTo _ghost
            && {_slotTarget isNotEqualTo _selected}
            && {typeOf _slotTarget in (_state get "classes")}
            && {(getPosASL _slotTarget) distance (getPosASL player) <= (_state get "radius")}
        ) then
        {
            {
                _compatibleSlots pushBack [_slotTarget, _x];
            } forEach ([_slotTarget, _snapCategory] call MEAP_fnc_getCompatibleSnapPoints);
        };
    } forEach _nearbyObjects;
    _state set ["compatibleSnapSlots", _compatibleSlots];
    _state set ["nextSnapSlotScan", diag_tickTime + 0.5];
};
if (_snapCategory isEqualTo "") then {_state set ["compatibleSnapSlots", []];};

private _rayEnd = _position vectorAdd (_direction vectorMultiply (((_state get "radius") * 2) min 500));
private _hits = lineIntersectsSurfaces [_position, _rayEnd, _ghost, player, true, 1, "GEOM", "NONE"];
if (_state getOrDefault ["ignoreObjects", false]) then
{
    _hits = _hits select
    {
        _x params ["", "", "_hitObject", "_parentObject"];
        isNull _hitObject && {isNull _parentObject}
    };
};
private _valid = _hits isNotEqualTo [];
private _target = objNull;
_state set ["snapPoint", ""];

if (_valid) then
{
    (_hits select 0) params ["_hitPosition", "_surfaceNormal", "_hitObject", "_parentObject"];
    _state set ["rawPreviewPosition", _hitPosition];
    _target = [_hitObject, _parentObject] select !isNull _parentObject;
    private _placementPosition = +_hitPosition;
    private _gridSize = _state get "gridSize";
    if (_gridSize > 0) then
    {
        _placementPosition = _placementPosition apply {round (_x / _gridSize) * _gridSize};
    };
    _placementPosition set [2, (_placementPosition select 2) + (_state get "verticalOffset")];
    _valid = _placementPosition distance (getPosASL player) <= (_state get "radius");

    if (_valid && {!isNull _ghost}) then
    {
        private _rotation = _state get "rotation";
        private _heading = [sin _rotation, cos _rotation, 0];
        private _objectUp = [[0, 0, 1], vectorNormalized _surfaceNormal] select (_state get "surfaceAlign");
        private _side = _objectUp vectorCrossProduct _heading;
        if (vectorMagnitude _side < 0.01) then {_side = [1, 0, 0];};
        private _objectDirection = vectorNormalized (_side vectorCrossProduct _objectUp);
        _ghost hideObject false;
        _ghost setVectorDirAndUp [_objectDirection, _objectUp];
        _ghost setPosASL _placementPosition;

        private _snapSide = _state get "snapSide";
        private _snapTarget = objNull;
        if (_snapSide isNotEqualTo "") then
        {
            private _selected = _state getOrDefault ["selected", objNull];
            private _sourcePoint = "";
            private _targetPoint = "";
            private _canSnap = !isNull _target && {_target isNotEqualTo _selected};
            if (_canSnap && {_snapSide isEqualTo "Slot"}) then
            {
                private _points = [_target, _snapCategory] call MEAP_fnc_getCompatibleSnapPoints;
                private _nearestDistance = 1e10;
                {
                    private _pointDistance = (_target modelToWorldVisual (_target selectionPosition [_x, "Memory"])) distance (ASLToAGL _hitPosition);
                    if (_pointDistance < _nearestDistance) then
                    {
                        _nearestDistance = _pointDistance;
                        _targetPoint = _x;
                    };
                } forEach _points;
                _sourcePoint = "MEAP_SnapPoint_Bottom";
                _canSnap = _targetPoint isNotEqualTo "";
            }
            else
            {
                private _sourceSide = [_snapSide] call MEAP_fnc_oppositeSide;
                _sourcePoint = [_sourceSide] call MEAP_fnc_pointNameFromSide;
                _targetPoint = [_snapSide] call MEAP_fnc_pointNameFromSide;
                _canSnap = _canSnap
                    && {[_ghost] call MEAP_fnc_isSnappable}
                    && {[_target] call MEAP_fnc_isSnappable};
            };
            if (_canSnap) then
            {
                _canSnap = [_ghost, _target, _sourcePoint, _targetPoint] call MEAP_fnc_applySnapTransform;
            };
            if (_canSnap) then
            {
                _placementPosition = getPosASL _ghost;
                _objectDirection = vectorDir _ghost;
                _objectUp = vectorUp _ghost;
                _snapTarget = _target;
                _state set ["snapPoint", _targetPoint];
                _valid = _placementPosition distance (getPosASL player) <= (_state get "radius");
            }
            else
            {
                _valid = false;
            };
        };

        _state set ["snapTarget", _snapTarget];
        _state set ["previewPosition", _placementPosition];
        _state set ["previewVectors", [_objectDirection, _objectUp]];
        _state set ["previewDistance", _placementPosition distance (getPosASL player)];
    };
}
else
{
    _state set ["rawPreviewPosition", []];
    _state set ["snapTarget", objNull];
    _state set ["previewPosition", []];
    _state set ["previewVectors", []];
    _state set ["previewDistance", 0];
};

if (!_valid && {!isNull _ghost}) then {_ghost hideObject true;};

private _classes = _state get "classes";
private _targetAllowed = !isNull _target
    && {typeOf _target in _classes}
    && {(getPosASL _target) distance (getPosASL player) <= (_state get "radius")};
_state set ["target", [_target, objNull] select !_targetAllowed];
private _previewReady = _valid && _previewActive;
_state set ["previewValid", _previewReady];

private _mode = _state get "mode";
private _selectionType = _state getOrDefault ["selectionType", "OBJECT"];
private _selectedBuildCost = 0;
private _canAfford = true;
if (!(_mode isEqualTo "EDIT") && {!(_selectionType isEqualTo "BUILD")} && {_previewActive} && {_state getOrDefault ["budgetEnabled", false]}) then
{
    private _classIndex = _state get "classIndex";
    private _className = (_state get "classes") param [_classIndex, ""];
    _selectedBuildCost = [_className] call MEAP_fnc_getArchitectBuildCost;
    _canAfford = (_state getOrDefault ["availableFunds", 0]) >= _selectedBuildCost;
};
_state set ["selectedBuildCost", _selectedBuildCost];
_state set ["canAfford", _canAfford];

private _placeControl = _state getOrDefault ["placeControl", controlNull];
if (!isNull _placeControl) then
{
    _placeControl ctrlEnable (_previewReady && {_canAfford} && {!(_state getOrDefault ["actionPending", false])});
    _placeControl ctrlSetTooltip format ["Place selected %1", ["object", "build"] select (_selectionType isEqualTo "BUILD")];
};

private _status = _state get "statusControl";
private _distance = _state getOrDefault ["previewDistance", 0];
private _grid = _state get "gridSize";
private _offset = _state get "verticalOffset";
private _ignoreObjects = _state getOrDefault ["ignoreObjects", false];
private _statusColor = ["#ff6b6b", "#8ee6a8"] select (_previewReady && {_canAfford});
private _previewState = if (!_previewActive) then {"SELECT OBJECT"} else { ["INVALID", "INSUFFICIENT FUNDS", "READY"] select ([!_previewReady, _previewReady && {!_canAfford}] find true) };
private _budgetText = "";
if (_state getOrDefault ["budgetEnabled", false]) then
{
    private _funds = _state getOrDefault ["availableFunds", 0];
    private _costText = ["", format [" | Cost: %1", _selectedBuildCost]] select (!(_mode isEqualTo "EDIT") && {!(_selectionType isEqualTo "BUILD")});
    private _fobUnavailable = (missionNamespace getVariable ["MEAP_Architect_budgetFundingMode", 0]) == 2 && {_funds < 0};
    private _shortfallText = ["", [" | INSUFFICIENT FUNDS", " | NO ACTIVE FOB"] select _fobUnavailable] select (!_canAfford);
    private _fundText = [str _funds, "NO ACTIVE FOB"] select _fobUnavailable;
    _budgetText = format ["<br/><t size='0.8'>%1: %2%3%4</t>", _state getOrDefault ["currencyName", "Republic Credits"], _fundText, _costText, _shortfallText];
};
_status ctrlSetStructuredText parseText format
[
    "<t color='%1'>%2 | %3 | %4m | %5 deg</t><br/><t size='0.8'>Grid %6 | Align %7 | Z %8m | Objects %9 | Snap %10</t>%11",
    _statusColor,
    _mode,
    _previewState,
    (_distance toFixed 1),
    (round (_state get "rotation")) mod 360,
    [format ["%1m", _grid], "OFF"] select (_grid <= 0),
    ["OFF", "ON"] select (_state get "surfaceAlign"),
    _offset toFixed 2,
    ["ON", "IGNORED"] select _ignoreObjects,
    [toUpper (_state get "snapSide"), "OFF"] select ((_state get "snapSide") isEqualTo ""),
    _budgetText
];