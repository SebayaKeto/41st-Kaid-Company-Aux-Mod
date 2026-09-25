params [
    ["_action", "", [""]],
    ["_unit", objNull, [objNull]],
    ["_token", "", [""]],
    ["_payload", [], [[]]]
];

if (!isServer || {isNull _unit} || {!isPlayer _unit}) exitWith {};
private _sender = remoteExecutedOwner;
if (_sender != owner _unit) exitWith {};
call MEAP_fnc_initializeArchitectState;

private _session = MEAP_Architect_sessions getOrDefault [str _sender, []];
if !(_session isEqualTypeParams [objNull, ""]) exitWith {};
_session params ["_sessionUnit", "_sessionToken"];
if (
    _sessionUnit isNotEqualTo _unit
    || {_sessionToken isNotEqualTo _token}
    || {!alive _unit}
    || {!([_unit] call MEAP_fnc_isArchitectEligible)}
    || {!(missionNamespace getVariable ["MEAP_Architect_enabled", true])}
) exitWith {};

private _radius = missionNamespace getVariable ["MEAP_Architect_maxDistance", 50];
private _key = [_unit] call MEAP_fnc_getArchitectKey;
private _budgetEnabled = missionNamespace getVariable ["MEAP_Architect_budgetEnabled", true];
private _fundingMode = missionNamespace getVariable ["MEAP_Architect_budgetFundingMode", 0];
private _currencyName = missionNamespace getVariable ["MEAP_Architect_currencyName", "Republic Credits"];
private _inventoryCurrencyClasses = [];
private _inventorySerialized = missionNamespace getVariable ["MEAP_Architect_inventoryCurrencyClasses", "[]"];
if (!isNil {_inventoryCurrencyClasses = parseSimpleArray _inventorySerialized} && {_inventoryCurrencyClasses isEqualType []}) then
{
    _inventoryCurrencyClasses = _inventoryCurrencyClasses select {_x isEqualType ""};
}
else
{
    _inventoryCurrencyClasses = [];
};
private _inventoryValue = missionNamespace getVariable ["MEAP_Architect_inventoryCurrencyValue", 1];
private _getAvailableFunds =
{
    if (!_budgetEnabled) exitWith {-1};
    if (_fundingMode == 2) exitWith {-1};
    if (_fundingMode != 1) exitWith
    {
        private _balance = MEAP_Architect_budgetBalances getOrDefault [_key, -1];
        if (_balance < 0) then
        {
            _balance = missionNamespace getVariable ["MEAP_Architect_startingBudget", 100];
            MEAP_Architect_budgetBalances set [_key, _balance];
        };
        _balance
    };

    private _inventory = magazines _unit;
    _inventory append items _unit;
    ({_x in _inventoryCurrencyClasses} count _inventory) * _inventoryValue
};
private _spendFunds =
{
    params ["_cost"];
    if (!_budgetEnabled || {_cost <= 0}) exitWith {true};
    private _available = call _getAvailableFunds;
    if (_available < _cost) exitWith {false};

    if (_fundingMode != 1) exitWith
    {
        MEAP_Architect_budgetBalances set [_key, _available - _cost];
        true
    };

    private _itemsNeeded = ceil (_cost / _inventoryValue);
    {
        if (_itemsNeeded <= 0) exitWith {};
        private _currencyClass = _x;
        private _isMagazine = isClass (configFile >> "CfgMagazines" >> _currencyClass);
        private _owned = if (_isMagazine) then {magazines _unit} else {items _unit};
        private _ownedCount = {_x isEqualTo _currencyClass} count _owned;
        for "_index" from 1 to (_ownedCount min _itemsNeeded) do
        {
            if (_isMagazine) then {_unit removeMagazine _currencyClass;} else {_unit removeItem _currencyClass;};
            _itemsNeeded = _itemsNeeded - 1;
        };
    } forEach _inventoryCurrencyClasses;

    _itemsNeeded <= 0
};
private _refundFunds =
{
    params ["_builderKey", "_cost"];
    if (!_budgetEnabled || {_fundingMode != 0} || {_builderKey isEqualTo ""} || {_cost <= 0}) exitWith {};
    private _balance = MEAP_Architect_budgetBalances getOrDefault [_builderKey, missionNamespace getVariable ["MEAP_Architect_startingBudget", 100]];
    MEAP_Architect_budgetBalances set [_builderKey, _balance + _cost];
};
private _reverseRefundFunds =
{
    params ["_builderKey", "_cost"];
    if (!_budgetEnabled || {_fundingMode != 0} || {_builderKey isEqualTo ""} || {_cost <= 0}) exitWith {true};
    private _balance = MEAP_Architect_budgetBalances getOrDefault [_builderKey, missionNamespace getVariable ["MEAP_Architect_startingBudget", 100]];
    if (_balance < _cost) exitWith {false};
    MEAP_Architect_budgetBalances set [_builderKey, _balance - _cost];
    true
};
private _refundFobFunds =
{
    params ["_fobKey", "_cost"];
    if (!_budgetEnabled || {_fundingMode != 2} || {_fobKey isEqualTo ""} || {_cost <= 0}) exitWith {};
    private _fob = MEAP_Architect_fobs getOrDefault [_fobKey, []];
    if (_fob isNotEqualTo []) then
    {
        _fob set [1, (_fob select 1) + _cost];
        MEAP_Architect_fobs set [_fobKey, _fob];
    };
};
private _reverseFobRefund =
{
    params ["_fobKey", "_cost"];
    if (!_budgetEnabled || {_fundingMode != 2} || {_fobKey isEqualTo ""} || {_cost <= 0}) exitWith {true};
    private _fob = MEAP_Architect_fobs getOrDefault [_fobKey, []];
    if (_fob isEqualTo [] || {(_fob param [1, -1]) < _cost}) exitWith {false};
    _fob set [1, (_fob select 1) - _cost];
    MEAP_Architect_fobs set [_fobKey, _fob];
    true
};
private _getResultFunds =
{
    if (!_budgetEnabled || {_fundingMode != 2}) exitWith {call _getAvailableFunds};
    private _resolvedFob = [getPosASL _unit] call MEAP_fnc_getArchitectFob;
    _resolvedFob params ["_fobKey", "_fob"];
    if (_fobKey isEqualTo "") exitWith {-1};
    _fob select 1
};
private _sendResult =
{
    params ["_resultAction", "_success", ["_object", objNull], "_message"];
    [_resultAction, _success, _object, _message, call _getResultFunds] remoteExecCall ["MEAP_fnc_architectActionResult", _sender];
};
private _lockKey = {params ["_object"]; netId _object};
private _releaseLock =
{
    params ["_object"];
    private _objectKey = [_object] call _lockKey;
    private _lock = MEAP_Architect_editLocks getOrDefault [_objectKey, []];
    if (
        _lock isEqualTypeParams [objNull, ""]
        && {(_lock select 0) isEqualTo _unit}
        && {(_lock select 1) isEqualTo _token}
    ) then
    {
        MEAP_Architect_editLocks deleteAt _objectKey;
    };
};
private _attachAccounting =
{
    params ["_object", "_builderKey", ["_buildCost", 0], ["_fobKey", ""]];
    if (_builderKey isEqualTo "") exitWith {};
    _object setVariable ["MEAP_Architect_constructedBy", _builderKey, true];
    _object setVariable ["MEAP_Architect_buildCost", _buildCost, true];
    if (_fobKey isNotEqualTo "") then {_object setVariable ["MEAP_Architect_fobKey", _fobKey, true];};
    _object addEventHandler ["Deleted", {
        params ["_object"];
        private _builderKey = _object getVariable ["MEAP_Architect_constructedBy", ""];
        if (_builderKey isNotEqualTo "") then
        {
            private _builderCount = MEAP_Architect_objectCounts getOrDefault [_builderKey, 1];
            MEAP_Architect_objectCounts set [_builderKey, (_builderCount - 1) max 0];
        };
    }];
};
private _recordHistory =
{
    params ["_entry"];
    private _history = MEAP_Architect_history getOrDefault [_key, []];
    _history pushBack _entry;
    private _depth = missionNamespace getVariable ["MEAP_Architect_historyDepth", 25];
    while {count _history > _depth} do {_history deleteAt 0;};
    MEAP_Architect_history set [_key, _history];
};
private _getHistoryId =
{
    params ["_object"];
    private _historyId = _object getVariable ["MEAP_Architect_historyId", ""];
    if (_historyId isEqualTo "") then
    {
        _historyId = format ["%1:%2:%3", _key, diag_tickTime, floor random 1000000];
        _object setVariable ["MEAP_Architect_historyId", _historyId, true];
    };
    _historyId
};
private _applySnap =
{
    params ["_source", "_target", "_mode", "_requestedTargetPoint"];
    if (_mode isEqualTo "") exitWith {true};
    if (
        isNull _source
        || {isNull _target}
        || {_source isEqualTo _target}
        || {(getPosASL _target) distance (getPosASL _unit) > _radius}
    ) exitWith {false};

    private _sourcePoint = "";
    private _targetPoint = "";
    if (_mode isEqualTo "Slot") then
    {
        private _category = [_source] call MEAP_fnc_getSnapCategory;
        private _compatiblePoints = [_target, _category] call MEAP_fnc_getCompatibleSnapPoints;
        if (
            _category isEqualTo ""
            || {!(typeOf _target in MEAP_Architect_allowedClasses)}
            || {!(_requestedTargetPoint in _compatiblePoints)}
        ) exitWith {false};
        _sourcePoint = "MEAP_SnapPoint_Bottom";
        _targetPoint = _requestedTargetPoint;
    }
    else
    {
        if (
            !(_mode in ["Left", "Right", "Front", "Back", "Top", "Bottom"])
            || {!([_source] call MEAP_fnc_isSnappable)}
            || {!([_target] call MEAP_fnc_isSnappable)}
        ) exitWith {false};
        private _sourceSide = [_mode] call MEAP_fnc_oppositeSide;
        _sourcePoint = [_sourceSide] call MEAP_fnc_pointNameFromSide;
        _targetPoint = [_mode] call MEAP_fnc_pointNameFromSide;
    };
    if (_sourcePoint isEqualTo "" || {_targetPoint isEqualTo ""}) exitWith {false};

    [_source, _target, _sourcePoint, _targetPoint] call MEAP_fnc_applySnapTransform
};
private _validateTransform =
{
    params ["_position", "_vectors"];
    if !(_position isEqualTypeParams [0, 0, 0]) exitWith {false};
    if !(_vectors isEqualTypeParams [[0, 0, 0], [0, 0, 0]]) exitWith {false};

    private _numbers = +_position;
    _numbers append (_vectors select 0);
    _numbers append (_vectors select 1);
    if (_numbers findIf {!finite _x} != -1) exitWith {false};

    private _direction = _vectors select 0;
    private _up = _vectors select 1;
    (abs (vectorMagnitude _direction - 1) < 0.05)
    && {abs (vectorMagnitude _up - 1) < 0.05}
    && {abs (_direction vectorDotProduct _up) < 0.05}
};
private _validatePlacementSlope =
{
    params ["_vectors"];
    private _up = _vectors select 1;
    private _slope = acos ((_up vectorDotProduct [0, 0, 1]) max -1 min 1);
    _slope <= (missionNamespace getVariable ["MEAP_Architect_maxPlacementSlope", 45])
};

private _normalizedAction = toUpper _action;
if (MEAP_Architect_allowedClasses isEqualTo []) exitWith
{
    [_normalizedAction, false, objNull, "Construction classes are not initialized."] call _sendResult;
};
private _mutationAction = _normalizedAction in ["CREATE", "EDIT", "DELETE", "UNDO", "CAPTURE", "PLACEBLUEPRINT"];
private _now = diag_tickTime;
private _lastAction = MEAP_Architect_actionTimes getOrDefault [str _sender, -1000];
private _cooldown = missionNamespace getVariable ["MEAP_Architect_actionCooldown", 0.2];
if (_mutationAction && {_now - _lastAction < _cooldown}) exitWith
{
    [_normalizedAction, false, objNull, "Please wait before performing another construction action."] call _sendResult;
};
if (_mutationAction) then {MEAP_Architect_actionTimes set [str _sender, _now];};

switch (_normalizedAction) do
{
    case "LOCK":
    {
        _payload params [["_object", objNull, [objNull]]];
        if (
            isNull _object
            || {!(typeOf _object in MEAP_Architect_allowedClasses)}
            || {(getPosASL _object) distance (getPosASL _unit) > _radius}
            || {!([_unit, _object, "LOCK"] call MEAP_fnc_architectAuthorizeObject)}
        ) exitWith
        {
            ["LOCK", false, _object, "That object cannot be edited."] call _sendResult;
        };

        private _objectKey = [_object] call _lockKey;
        private _lock = MEAP_Architect_editLocks getOrDefault [_objectKey, []];
        if (
            _lock isNotEqualTo []
            && {!((_lock select 0) isEqualTo _unit && {(_lock select 1) isEqualTo _token})}
        ) exitWith
        {
            ["LOCK", false, _object, "Another Daidalos user is editing that object."] call _sendResult;
        };

        MEAP_Architect_editLocks set [_objectKey, [_unit, _token]];
        ["LOCK", true, _object, "Object locked for editing."] call _sendResult;
    };
    case "UNLOCK":
    {
        _payload params [["_object", objNull, [objNull]]];
        if (!isNull _object) then {[_object] call _releaseLock;};
        ["UNLOCK", true, _object, ""] call _sendResult;
    };
    case "CAPTURE":
    {
        _payload params [["_root", objNull, [objNull]]];
        if (
            isNull _root
            || {!([_unit, _root, "CAPTURE"] call MEAP_fnc_architectAuthorizeObject)}
            || {(_root getVariable ["MEAP_Architect_constructedBy", ""]) isNotEqualTo _key}
            || {(getPosASL _root) distance (getPosASL _unit) > _radius}
        ) exitWith {["CAPTURE", false, _root, "Target one of your nearby Daidalos objects to save a build."] call _sendResult;};

        private _captureRadius = missionNamespace getVariable ["MEAP_Architect_blueprintCaptureRadius", 15];
        private _maxEntries = missionNamespace getVariable ["MEAP_Architect_maxBlueprintObjects", 30];
        private _rootPosition = getPosASL _root;
        private _rootHeading = getDir _root;
        private _right = [cos _rootHeading, -sin _rootHeading, 0];
        private _forward = [sin _rootHeading, cos _rootHeading, 0];
        private _entries = [];
        {
            private _object = _x;
            if ((_object getVariable ["MEAP_Architect_constructedBy", ""]) isEqualTo _key) then
            {
                private _delta = (getPosASL _object) vectorDiff _rootPosition;
                _entries pushBack [typeOf _object, [_delta vectorDotProduct _right, _delta vectorDotProduct _forward, _delta select 2], (getDir _object) - _rootHeading];
            };
        } forEach (nearestObjects [ASLToAGL _rootPosition, [], _captureRadius]);
        if (_entries isEqualTo [] || {count _entries > _maxEntries}) exitWith
        {
            ["CAPTURE", false, _root, format ["A build must contain between 1 and %1 owned Daidalos objects.", _maxEntries]] call _sendResult;
        };
        private _counter = (MEAP_Architect_blueprintCounters getOrDefault [_key, 0]) + 1;
        MEAP_Architect_blueprintCounters set [_key, _counter];
        private _id = format ["USR:%1:%2", _key, _counter];
        private _name = format ["Saved Build %1", _counter];
        MEAP_Architect_blueprints set [_id, [_name, "SAVED", _key, _entries]];
        ["CAPTURE", _unit, _root, format ["name=%1; objects=%2", _name, count _entries]] call MEAP_fnc_architectRecordAudit;
        ["CAPTURE", true, _root, format ["Saved %1 with %2 objects. Reopen Daidalos to place it.", _name, count _entries]] call _sendResult;
    };
    case "PLACEBLUEPRINT":
    {
        _payload params [["_id", "", [""]], ["_origin", [], [[]], 3], ["_heading", 0, [0]], ["_draft", false, [true]]];
        private _blueprint = MEAP_Architect_blueprints getOrDefault [_id, []];
        if (_blueprint isEqualTo []) exitWith {["PLACEBLUEPRINT", false, objNull, "That saved build is unavailable."] call _sendResult;};
        _blueprint params ["_name", "_source", "_ownerKey", "_entries"];
        if (_source isNotEqualTo "CONFIG" && {_ownerKey isNotEqualTo _key} && {(admin _sender) <= 0}) exitWith {["PLACEBLUEPRINT", false, objNull, "You are not authorized to place that build."] call _sendResult;};
        private _maxEntries = missionNamespace getVariable ["MEAP_Architect_maxBlueprintObjects", 30];
        private _count = MEAP_Architect_objectCounts getOrDefault [_key, 0];
        if (!(_origin isEqualTypeParams [0, 0, 0]) || {_origin distance (getPosASL _unit) > _radius} || {_entries isEqualTo []} || {count _entries > _maxEntries} || {_count + count _entries > missionNamespace getVariable ["MEAP_Architect_maxObjects", 100]}) exitWith {["PLACEBLUEPRINT", false, objNull, "The build exceeds placement limits or is outside the Daidalos radius."] call _sendResult;};
        private _right = [cos _heading, -sin _heading, 0];
        private _forward = [sin _heading, cos _heading, 0];
        private _totalCost = 0;
        private _placements = [];
        private _validEntries = true;
        {
            _x params ["_className", "_offset", "_relativeHeading"];
            private _position = _origin vectorAdd (_right vectorMultiply (_offset select 0)) vectorAdd (_forward vectorMultiply (_offset select 1)) vectorAdd [0, 0, _offset select 2];
            if (!(_className in MEAP_Architect_allowedClasses) || {_position distance (getPosASL _unit) > _radius}) then
            {
                _validEntries = false;
            }
            else
            {
                _placements pushBack [_className, _position, _heading + _relativeHeading];
                _totalCost = _totalCost + ([_className] call MEAP_fnc_getArchitectBuildCost);
            };
        } forEach _entries;
        private _fobKey = "";
        private _fob = [];
        if (_budgetEnabled && {_fundingMode == 2}) then
        {
            private _resolvedFob = [_origin] call MEAP_fnc_getArchitectFob;
            _resolvedFob params ["_fobKey", "_fob"];
        };
        if (_placements isEqualTo [] || {!_validEntries} || {call _getAvailableFunds >= 0 && {call _getAvailableFunds < _totalCost}} || {_budgetEnabled && {_fundingMode == 2} && {(_fobKey isEqualTo "") || {(_fob select 1) < _totalCost}}}) exitWith {["PLACEBLUEPRINT", false, objNull, "The build contains invalid objects or cannot be funded."] call _sendResult;};
        if (_budgetEnabled && {_fundingMode == 2}) then
        {
            _fob set [1, (_fob select 1) - _totalCost];
            MEAP_Architect_fobs set [_fobKey, _fob];
        }
        else
        {
            if !([_totalCost] call _spendFunds) exitWith {["PLACEBLUEPRINT", false, objNull, "The build could not be funded."] call _sendResult;};
        };
        private _created = [];
        {
            _x params ["_className", "_position", "_objectHeading"];
            private _object = createVehicle [_className, ASLToAGL _position, [], 0, "CAN_COLLIDE"];
            _object setDir _objectHeading;
            _object setPosASL _position;
            [_object, _key, [_className] call MEAP_fnc_getArchitectBuildCost, _fobKey] call _attachAccounting;
            if (_draft) then {_object setVariable ["MEAP_Architect_draft", true, true]; _object hideObjectGlobal true;};
            _created pushBack _object;
        } forEach _placements;
        MEAP_Architect_objectCounts set [_key, _count + count _created];
        ["PLACEBLUEPRINT", _unit, _created select 0, format ["build=%1; objects=%2; cost=%3", _name, count _created, _totalCost]] call MEAP_fnc_architectRecordAudit;
        ["PLACEBLUEPRINT", true, _created select 0, format ["Placed %1 (%2 objects, %3 %4).", _name, count _created, _totalCost, _currencyName]] call _sendResult;
    };
    case "CREATE":
    {
        _payload params [
            ["_className", "", [""]],
            ["_position", [], [[]], 3],
            ["_vectors", [], [[]], 2],
            ["_snapTarget", objNull, [objNull]],
            ["_snapSide", "", [""]],
            ["_snapPoint", "", [""]],
            ["_draft", false, [true]]
        ];
        private _count = MEAP_Architect_objectCounts getOrDefault [_key, 0];
        private _maxObjects = missionNamespace getVariable ["MEAP_Architect_maxObjects", 100];
        private _buildCost = [_className] call MEAP_fnc_getArchitectBuildCost;
        private _fobKey = "";
        private _fob = [];
        if (_budgetEnabled && {_fundingMode == 2}) then
        {
            private _resolvedFob = [_position] call MEAP_fnc_getArchitectFob;
            _resolvedFob params ["_fobKey", "_fob"];
        };
        if (
            !(_className in MEAP_Architect_allowedClasses)
            || {!([_position, _vectors] call _validateTransform)}
            || {!([_vectors] call _validatePlacementSlope)}
            || {_position distance (getPosASL _unit) > _radius}
            || {_count >= _maxObjects}
            || {call _getAvailableFunds >= 0 && {call _getAvailableFunds < _buildCost}}
            || {_budgetEnabled && {_fundingMode == 2} && {_fobKey isEqualTo ""}}
            || {_budgetEnabled && {_fundingMode == 2} && {_fobKey isNotEqualTo ""} && {(_fob select 1) < _buildCost}}
        ) exitWith
        {
            private _reason = "Construction request rejected by the server.";
            if (_budgetEnabled && {_fundingMode == 2}) then
            {
                _reason = [format ["No active FOB heart is within %1m of this placement.", missionNamespace getVariable ["MEAP_Architect_fobRadius", 250]], format ["The FOB needs %1 %2 for this object.", _buildCost, _currencyName]] select (_fobKey isNotEqualTo "");
            };
            if (call _getAvailableFunds >= 0 && {call _getAvailableFunds < _buildCost}) then
            {
                _reason = format ["Not enough %1 for this object (%2 required).", _currencyName, _buildCost];
            };
            ["CREATE", false, objNull, _reason] call _sendResult;
        };

        private _object = createVehicle [_className, ASLToAGL _position, [], 0, "CAN_COLLIDE"];
        _object setVectorDirAndUp _vectors;
        _object setPosASL _position;
        if (!([_object, _snapTarget, _snapSide, _snapPoint] call _applySnap)) exitWith
        {
            deleteVehicle _object;
            ["CREATE", false, objNull, "The requested memory-point snap is not valid."] call _sendResult;
        };
        private _finalPosition = getPosASL _object;
        private _finalVectors = [vectorDir _object, vectorUp _object];
        if !([_finalVectors] call _validatePlacementSlope) exitWith
        {
            deleteVehicle _object;
            ["CREATE", false, objNull, "The snapped object exceeds the maximum placement slope."] call _sendResult;
        };
        if (_finalPosition distance (getPosASL _unit) > _radius) exitWith
        {
            deleteVehicle _object;
            ["CREATE", false, objNull, "The snapped object would be outside the Daidalos radius."] call _sendResult;
        };
        if (_budgetEnabled && {_fundingMode == 2}) then
        {
            _fob set [1, (_fob select 1) - _buildCost];
            MEAP_Architect_fobs set [_fobKey, _fob];
        };
        if !(_fundingMode == 2 || {[_buildCost] call _spendFunds}) exitWith
        {
            deleteVehicle _object;
            ["CREATE", false, objNull, format ["Not enough %1 for this object (%2 required).", _currencyName, _buildCost]] call _sendResult;
        };
        [_object, _key, _buildCost, _fobKey] call _attachAccounting;
        if (_draft) then
        {
            _object setVariable ["MEAP_Architect_draft", true, true];
            _object setVariable ["MEAP_Architect_draftOwner", _key, true];
            _object hideObjectGlobal true;
        };
        MEAP_Architect_objectCounts set [_key, _count + 1];
        private _historyId = [_object] call _getHistoryId;
        [["CREATE", _object, _className, _finalPosition, _finalVectors, _key, diag_tickTime, _historyId, _buildCost]] call _recordHistory;
        ["CREATE", _unit, _object, format ["cost=%1; fob=%2; draft=%3", _buildCost, _fobKey, _draft]] call MEAP_fnc_architectRecordAudit;
        ["CREATE", true, _object, [format ["Object placed for %1 %2 (%3/%4).", _buildCost, _currencyName, _count + 1, _maxObjects], "Draft created. Press P while targeting it to publish."] select _draft] call _sendResult;
    };
    case "PUBLISH":
    {
        _payload params [["_object", objNull, [objNull]]];
        if (
            isNull _object
            || {!(_object getVariable ["MEAP_Architect_draft", false])}
            || {!([_unit, _object, "PUBLISH"] call MEAP_fnc_architectAuthorizeObject)}
            || {(getPosASL _object) distance (getPosASL _unit) > _radius}
        ) exitWith
        {
            ["PUBLISH", false, _object, "Only your nearby Daidalos drafts can be published."] call _sendResult;
        };
        _object setVariable ["MEAP_Architect_draft", false, true];
        _object setVariable ["MEAP_Architect_draftOwner", "", true];
        _object hideObjectGlobal false;
        ["PUBLISH", _unit, _object, ""] call MEAP_fnc_architectRecordAudit;
        ["PUBLISH", true, _object, "Draft published."] call _sendResult;
    };
    case "EDIT":
    {
        _payload params [
            ["_object", objNull, [objNull]],
            ["_position", [], [[]], 3],
            ["_vectors", [], [[]], 2],
            ["_snapTarget", objNull, [objNull]],
            ["_snapSide", "", [""]],
            ["_snapPoint", "", [""]]
        ];
        private _lock = MEAP_Architect_editLocks getOrDefault [[_object] call _lockKey, []];
        if (
            isNull _object
            || {!(typeOf _object in MEAP_Architect_allowedClasses)}
            || {(getPosASL _object) distance (getPosASL _unit) > _radius}
            || {!([_position, _vectors] call _validateTransform)}
            || {!([_vectors] call _validatePlacementSlope)}
            || {_position distance (getPosASL _unit) > _radius}
            || {!(_lock isEqualTypeParams [objNull, ""])}
            || {(_lock select 0) isNotEqualTo _unit}
            || {(_lock select 1) isNotEqualTo _token}
            || {!([_unit, _object, "EDIT"] call MEAP_fnc_architectAuthorizeObject)}
        ) exitWith
        {
            ["EDIT", false, _object, "Edit request rejected by the server."] call _sendResult;
        };

        private _oldPosition = getPosASL _object;
        private _oldVectors = [vectorDir _object, vectorUp _object];
        private _builderKey = _object getVariable ["MEAP_Architect_constructedBy", ""];
        private _historyId = [_object] call _getHistoryId;
        private _buildCost = _object getVariable ["MEAP_Architect_buildCost", [typeOf _object] call MEAP_fnc_getArchitectBuildCost];
        private _fobKey = _object getVariable ["MEAP_Architect_fobKey", ""];
        _object setVectorDirAndUp _vectors;
        _object setPosASL _position;
        if (!([_object, _snapTarget, _snapSide, _snapPoint] call _applySnap)) exitWith
        {
            _object setVectorDirAndUp _oldVectors;
            _object setPosASL _oldPosition;
            ["EDIT", false, _object, "The requested memory-point snap is not valid."] call _sendResult;
        };
        if !([[vectorDir _object, vectorUp _object]] call _validatePlacementSlope) exitWith
        {
            _object setVectorDirAndUp _oldVectors;
            _object setPosASL _oldPosition;
            ["EDIT", false, _object, "The snapped object exceeds the maximum placement slope."] call _sendResult;
        };
        if ((getPosASL _object) distance (getPosASL _unit) > _radius) exitWith
        {
            _object setVectorDirAndUp _oldVectors;
            _object setPosASL _oldPosition;
            ["EDIT", false, _object, "The snapped object would be outside the Daidalos radius."] call _sendResult;
        };
        [["EDIT", _object, typeOf _object, _oldPosition, _oldVectors, _builderKey, diag_tickTime, _historyId, _buildCost, _fobKey]] call _recordHistory;
        [_object] call _releaseLock;
        ["EDIT", _unit, _object, ""] call MEAP_fnc_architectRecordAudit;
        ["EDIT", true, _object, "Object edit committed."] call _sendResult;
    };
    case "DELETE":
    {
        _payload params [["_object", objNull, [objNull]]];
        private _lock = MEAP_Architect_editLocks getOrDefault [[_object] call _lockKey, []];
        private _lockedByAnother = _lock isNotEqualTo []
            && {!((_lock select 0) isEqualTo _unit && {(_lock select 1) isEqualTo _token})};
        if (
            isNull _object
            || {!(typeOf _object in MEAP_Architect_allowedClasses)}
            || {(getPosASL _object) distance (getPosASL _unit) > _radius}
            || {_lockedByAnother}
            || {!([_unit, _object, "DELETE"] call MEAP_fnc_architectAuthorizeObject)}
        ) exitWith
        {
            ["DELETE", false, _object, ["Delete request rejected by the server.", "Another Daidalos user is editing that object."] select _lockedByAnother] call _sendResult;
        };

        private _className = typeOf _object;
        private _oldPosition = getPosASL _object;
        private _oldVectors = [vectorDir _object, vectorUp _object];
        private _builderKey = _object getVariable ["MEAP_Architect_constructedBy", ""];
        private _historyId = [_object] call _getHistoryId;
        private _buildCost = _object getVariable ["MEAP_Architect_buildCost", [typeOf _object] call MEAP_fnc_getArchitectBuildCost];
        private _fobKey = _object getVariable ["MEAP_Architect_fobKey", ""];
        [_object] call _releaseLock;
        deleteVehicle _object;
        [_builderKey, _buildCost] call _refundFunds;
        [_fobKey, _buildCost] call _refundFobFunds;
        [["DELETE", objNull, _className, _oldPosition, _oldVectors, _builderKey, diag_tickTime, _historyId, _buildCost, _fobKey]] call _recordHistory;
        ["DELETE", _unit, objNull, format ["class=%1; cost=%2; fob=%3", _className, _buildCost, _fobKey]] call MEAP_fnc_architectRecordAudit;
        ["DELETE", true, objNull, ["Object deleted.", format ["Object deleted; %1 %2 refunded.", _buildCost, _currencyName]] select (_budgetEnabled && {_fundingMode != 1} && {_builderKey isNotEqualTo ""})] call _sendResult;
    };
    case "UNDO":
    {
        private _history = MEAP_Architect_history getOrDefault [_key, []];
        if (_history isEqualTo []) exitWith
        {
            ["UNDO", false, objNull, "There is no construction action to undo."] call _sendResult;
        };

        private _entry = _history select (count _history - 1);
        _entry params ["_historyAction", "_object", "_className", "_position", "_vectors", "_builderKey", "_recordedAt", "_historyId", ["_buildCost", 0], ["_fobKey", ""]];
        private _undoWindow = missionNamespace getVariable ["MEAP_Architect_undoWindow", 120];
        if (diag_tickTime - _recordedAt > _undoWindow) exitWith
        {
            _history deleteAt (count _history - 1);
            MEAP_Architect_history set [_key, _history];
            ["UNDO", false, objNull, "The latest construction action is outside the undo window."] call _sendResult;
        };

        private _undoSucceeded = false;
        private _resultObject = _object;
    private _undoFailureMessage = "The latest construction action can no longer be restored safely.";
        switch (_historyAction) do
        {
            case "CREATE":
            {
                if (!isNull _object && {(getPosASL _object) distance (getPosASL _unit) <= _radius}) then
                {
                    private _lock = MEAP_Architect_editLocks getOrDefault [[_object] call _lockKey, []];
                    if (_lock isEqualTo [] || {(_lock select 0) isEqualTo _unit}) then
                    {
                        private _fobKey = _object getVariable ["MEAP_Architect_fobKey", ""];
                        [_object] call _releaseLock;
                        deleteVehicle _object;
                        [_builderKey, _buildCost] call _refundFunds;
                        [_fobKey, _buildCost] call _refundFobFunds;
                        _resultObject = objNull;
                        _undoSucceeded = true;
                    };
                };
            };
            case "EDIT":
            {
                if (!isNull _object && {_position distance (getPosASL _unit) <= _radius}) then
                {
                    private _lock = MEAP_Architect_editLocks getOrDefault [[_object] call _lockKey, []];
                    if (_lock isEqualTo [] || {(_lock select 0) isEqualTo _unit}) then
                    {
                        _object setVectorDirAndUp _vectors;
                        _object setPosASL _position;
                        _undoSucceeded = true;
                    };
                };
            };
            case "DELETE":
            {
                private _builderCount = MEAP_Architect_objectCounts getOrDefault [_builderKey, 0];
                private _maxObjects = missionNamespace getVariable ["MEAP_Architect_maxObjects", 100];
                if (
                    isClass (configFile >> "CfgVehicles" >> _className)
                    && {_className in MEAP_Architect_allowedClasses}
                    && {_position distance (getPosASL _unit) <= _radius}
                    && {(_builderKey isEqualTo "") || {_builderCount < _maxObjects}}
                    && {[_position, _vectors] call _validateTransform}
                    && {[_vectors] call _validatePlacementSlope}
                ) then
                {
                    private _refundReversed = [_builderKey, _buildCost] call _reverseRefundFunds;
                    if (_refundReversed) then
                    {
                        _refundReversed = [_fobKey, _buildCost] call _reverseFobRefund;
                    };
                    if (!_refundReversed) then
                    {
                        _undoFailureMessage = "The delete refund has already been spent and cannot be reversed.";
                    }
                    else
                    {
                        _resultObject = createVehicle [_className, ASLToAGL _position, [], 0, "CAN_COLLIDE"];
                        if (isNull _resultObject) then
                        {
                            [_builderKey, _buildCost] call _refundFunds;
                            [_fobKey, _buildCost] call _refundFobFunds;
                            _undoFailureMessage = "The deleted object could not be restored.";
                        }
                        else
                        {
                            _resultObject setVectorDirAndUp _vectors;
                            _resultObject setPosASL _position;
                            _resultObject setVariable ["MEAP_Architect_historyId", _historyId, true];
                            if (_builderKey isNotEqualTo "") then
                            {
                                [_resultObject, _builderKey, _buildCost, _fobKey] call _attachAccounting;
                                MEAP_Architect_objectCounts set [_builderKey, _builderCount + 1];
                            };
                            {
                                if ((_x param [7, ""]) isEqualTo _historyId) then
                                {
                                    _x set [1, _resultObject];
                                };
                            } forEach _history;
                            _undoSucceeded = true;
                        };
                    };
                };
            };
        };

        if (!_undoSucceeded) exitWith
        {
            ["UNDO", false, _resultObject, _undoFailureMessage] call _sendResult;
        };

        _history deleteAt (count _history - 1);
        MEAP_Architect_history set [_key, _history];
        ["UNDO", true, _resultObject, format ["Undid %1.", toLower _historyAction]] call _sendResult;
    };
    default
    {
        [_normalizedAction, false, objNull, "Unknown construction action."] call _sendResult;
    };
};