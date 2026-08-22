params ["_vehicle", "_profile"];


_profile params ["_resourceName", "_displayName", "_runningVariable", "_zones", ["_hullHitpoint", ""], ["_systems", []]];

if (isNull _vehicle || {!hasInterface}) exitWith {};
if ((count _zones) isNotEqualTo 4 || {({(count _x) isNotEqualTo 3} count _zones) > 0}) exitWith {
    diag_log "[FST Vehicle Diagnostics] Invalid four-zone vehicle profile.";
};
if (_vehicle getVariable [_runningVariable, false]) exitWith {};

_vehicle setVariable [_runningVariable, true];

private _lowHullBorderControls = [
    [[7110, 7111, 7112, 7113], 0.16],
    [[7114, 7115, 7116, 7117], 0.28],
    [[7118, 7119, 7120, 7121], 0.45]
];
private _extensionName = "FST_SabreArmorExtension";
private _extensionEnabled = true;
private _nextExtensionUpdate = 0;
private _assessment = [100, 100, 100, 100, 100, "NOMINAL", false];
private _lastRenderedAssessment = [];
private _alertWasActive = false;
private _lastDamageReadings = [];
private _damageEventText = "";
private _damageEventUntil = 0;
private _roleControlsVisible = nil;
private _hudControlIds = [7098, 7099, 7100, 7101, 7102, 7103, 7104, 7105, 7106, 7107, 7108, 7109, 7110, 7111, 7112, 7113, 7114, 7115, 7116, 7117, 7118, 7119, 7120, 7121, 7122, 7123, 7124, 7125, 7126, 7127, 7128, 7129, 7130, 7131, 7132, 7133];
private _integrityState = {
    params ["_integrity"];

    if (_integrity <= 0) exitWith {["BREACHED", [1, 0.02, 0.02, 0.9]]};
    if (_integrity < 40) exitWith {["CRITICAL", [1, 0.16, 0.10, 0.9]]};
    if (_integrity < 70) exitWith {["DAMAGED", [1, 0.72, 0.16, 0.9]]};
    ["NOMINAL", [0.12, 0.80, 0.20, 0.9]]
};
private _isPercentage = {
    params ["_value"];
    if (_value isEqualTo "") exitWith {false};

    private _characters = toArray _value;
    ({_x < 48 || {_x > 57}} count _characters) isEqualTo 0 && {
        private _number = parseNumber _value;
        _number >= 0 && {_number <= 100}
    }
};

while {alive _vehicle} do {
    waitUntil {
        uiSleep 0.25;
        vehicle player isEqualTo _vehicle || {!alive _vehicle}
    };

    if (!alive _vehicle) exitWith {};

    cutRsc [_resourceName, "PLAIN", 0, false];
    waitUntil {
        uiSleep 0.05;
        !alive _vehicle || {vehicle player isNotEqualTo _vehicle} || {!isNull (uiNamespace getVariable [_displayName, displayNull])}
    };

    private _display = uiNamespace getVariable [_displayName, displayNull];
    while {alive _vehicle && {vehicle player isEqualTo _vehicle} && {!isNull _display}} do {
        private _isCrew = player isEqualTo driver _vehicle || {player isEqualTo gunner _vehicle} || {player isEqualTo commander _vehicle};
        if (isNil "_roleControlsVisible" || {_isCrew isNotEqualTo _roleControlsVisible}) then {
            {
                (_display displayCtrl _x) ctrlShow _isCrew;
            } forEach _hudControlIds;
            _roleControlsVisible = _isCrew;
        };

        if (!_isCrew) then {
            uiSleep 0.5;
            continue;
        };

        private _damageValues = (_zones apply {
            _x params ["_controlId", "_valueControlId", "_hitpoint"];
            (_vehicle getHitPointDamage _hitpoint) max 0 min 1
        }) + [(damage _vehicle) max 0 min 1];
        private _systemReadings = _systems apply {
            _x params ["_systemName", "_controlId", "_components"];
            private _integrities = _components apply {
                _x params ["_componentName", "_hitpoint"];
                round ((1 - ((_vehicle getHitPointDamage _hitpoint) max 0 min 1)) * 100)
            };
            [_systemName, _controlId, _components apply {_x select 0}, _integrities]
        };

        private _damageReadings = [
            ["FRONT ARMOR", _damageValues select 0],
            ["LEFT ARMOR", _damageValues select 1],
            ["RIGHT ARMOR", _damageValues select 2],
            ["REAR ARMOR", _damageValues select 3],
            ["HULL", _damageValues select 4]
        ];
        {
            _x params ["_systemName", "_controlId", "_componentNames", "_integrities"];
            {
                _damageReadings pushBack [format ["%1 %2", _systemName, _componentNames select _forEachIndex], 1 - (_x / 100)];
            } forEach _integrities;
        } forEach _systemReadings;

        if !(_lastDamageReadings isEqualTo []) then {
            private _largestIncrease = 0;
            private _impactName = "";
            {
                private _previousDamage = (_lastDamageReadings select _forEachIndex) select 1;
                private _increase = (_x select 1) - _previousDamage;
                if (_increase > _largestIncrease) then {
                    _largestIncrease = _increase;
                    _impactName = _x select 0;
                };
            } forEach _damageReadings;
            if (_largestIncrease >= 0.03) then {
                _damageEventText = format ["IMPACT: %1 -%2%%", _impactName, round (_largestIncrease * 100)];
                _damageEventUntil = diag_tickTime + 3;
            };
        };
        _lastDamageReadings = +_damageReadings;

        if (_extensionEnabled && {diag_tickTime >= _nextExtensionUpdate}) then {
            _nextExtensionUpdate = diag_tickTime + 0.5;
            private _response = _extensionName callExtension ["assess-v1", _damageValues apply {str _x}];
            private _parts = _response splitString "|";
            private _isValidResponse = (count _parts) isEqualTo 8
                && {(_parts select 0) isEqualTo "v1"}
                && {({[_x] call _isPercentage} count (_parts select [1, 5])) isEqualTo 5}
                && {(_parts select 6) in ["NOMINAL", "DEGRADED", "CRITICAL"]}
                && {(_parts select 7) in ["0", "1"]};

            if (_isValidResponse) then {
                _assessment = (_parts select [1, 5]) apply {parseNumber _x};
                _assessment pushBack (_parts select 6);
                _assessment pushBack ((_parts select 7) isEqualTo "1");
            } else {
                _extensionEnabled = false;
                diag_log format ["[FST Vehicle Diagnostics] Extension response rejected; using local assessment. Response: %1", _response];
            };
        };

        if (!_extensionEnabled) then {
            _assessment = (_damageValues apply {round ((1 - _x) * 100)}) + ["LOCAL", false];
        };

        private _priority = ["NO DAMAGE", 100];
        {
            private _integrity = round ((1 - (_x select 1)) * 100);
            if (_integrity < (_priority select 1)) then {
                _priority = [_x select 0, _integrity];
            };
        } forEach _damageReadings;
        private _priorityState = [_priority select 1] call _integrityState;
        private _priorityText = if (diag_tickTime < _damageEventUntil) then {
            _damageEventText
        } else {
            format ["PRIORITY: %1 // %2", _priority select 0, _priorityState select 0]
        };
        private _repairText = if ((_priority select 1) >= 70) then {
            "REPAIR: NOT REQUIRED"
        } else {
            if ((_priority select 1) >= 40) then {
                format ["FIELD REPAIR: %1 // %2%%", _priority select 0, _priority select 1]
            } else {
                format ["RETURN TO SERVICE: %1 // %2%%", _priority select 0, _priority select 1]
            }
        };
        private _crewRole = if (player isEqualTo driver _vehicle) then {
            "DRIVER"
        } else {
            if (player isEqualTo gunner _vehicle) then {"GUNNER"} else {"COMMANDER"}
        };
        private _roleFocus = switch (_crewRole) do {
            case "DRIVER": {"MOBILITY + HULL"};
            case "GUNNER": {"WEAPONS + FRONT"};
            default {"FULL SYSTEMS"};
        };
        private _renderedAssessment = _assessment + (_systemReadings apply {_x select 3}) + [_priorityText, _repairText, _crewRole, _roleFocus];
        if !(_renderedAssessment isEqualTo _lastRenderedAssessment) then {
            {
                _x params ["_controlId", "_valueControlId", "_hitpoint"];
                private _integrity = _assessment select _forEachIndex;
                private _zoneState = [_integrity] call _integrityState;
                (_display displayCtrl _controlId) ctrlSetBackgroundColor (_zoneState select 1);
                (_display displayCtrl _valueControlId) ctrlSetText format ["%1%%", _integrity];
            } forEach _zones;

            private _hullState = [_assessment select 4] call _integrityState;
            (_display displayCtrl 7109) ctrlSetBackgroundColor (_hullState select 1);
            (_display displayCtrl 7126) ctrlSetText format ["%1%%", _assessment select 4];

            private _condition = _assessment select 5;
            private _conditionColor = switch (_condition) do {
                case "NOMINAL": {[0.42, 1, 0.62, 1]};
                case "DEGRADED": {[1, 0.72, 0.16, 1]};
                case "CRITICAL": {[1, 0.16, 0.10, 1]};
                default {[0.68, 0.75, 0.8, 1]};
            };
            (_display displayCtrl 7127) ctrlSetText _condition;
            (_display displayCtrl 7127) ctrlSetTextColor _conditionColor;

            {
                _x params ["_systemName", "_controlId", "_componentNames", "_integrities"];
                private _systemText = _systemName;
                {
                    _systemText = _systemText + format ["  %1 %2%%", _componentNames select _forEachIndex, _x];
                } forEach _integrities;
                private _systemState = [(selectMin _integrities)] call _integrityState;
                (_display displayCtrl _controlId) ctrlSetText _systemText;
                (_display displayCtrl _controlId) ctrlSetTextColor (_systemState select 1);
            } forEach _systemReadings;

            (_display displayCtrl 7128) ctrlSetText _priorityText;
            (_display displayCtrl 7128) ctrlSetTextColor (_priorityState select 1);
            (_display displayCtrl 7129) ctrlSetText _repairText;
            (_display displayCtrl 7129) ctrlSetTextColor (_priorityState select 1);
            (_display displayCtrl 7133) ctrlSetText format ["CREW ROLE: %1 // %2", _crewRole, _roleFocus];
            _lastRenderedAssessment = _renderedAssessment;
        };

        private _hullDamage = if (_hullHitpoint isEqualTo "") then {
            1 - ((_assessment select 4) / 100)
        } else {
            (_vehicle getHitPointDamage _hullHitpoint) max 0 min 1
        };
        private _alertActive = _isCrew && {(_assessment select 6) || {_hullDamage > 0.4}};
        private _alertStrength = if (_alertActive) then {
            0.35 + ((sin (diag_tickTime * 720) + 1) * 0.325)
        } else {
            0
        };
        if (_alertActive || {_alertWasActive}) then {
            {
                _x params ["_controlIds", "_opacity"];
                {
                    (_display displayCtrl _x) ctrlSetBackgroundColor [1, 0.02, 0.02, _alertStrength * _opacity];
                } forEach _controlIds;
            } forEach _lowHullBorderControls;
        };
        _alertWasActive = _alertActive;

        uiSleep 0.15;
    };

    cutText ["", "PLAIN"];
    if (isNull _display && {alive _vehicle && {vehicle player isEqualTo _vehicle}}) then {
        uiSleep 0.25;
    };
};

_vehicle setVariable [_runningVariable, false];