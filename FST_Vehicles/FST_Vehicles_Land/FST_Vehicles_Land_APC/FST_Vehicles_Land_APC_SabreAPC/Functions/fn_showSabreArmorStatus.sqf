params ["_vehicle"];

if (isNull _vehicle || {!hasInterface}) exitWith {};
if (_vehicle getVariable ["FST_sabreArmorStatusRunning", false]) exitWith {};

_vehicle setVariable ["FST_sabreArmorStatusRunning", true];

private _indicators = [
    [7101, 7122, "HitFrontArmor"],
    [7103, 7123, "HitLSideArmor"],
    [7105, 7124, "HitRSideArmor"],
    [7107, 7125, "HitRearArmor"]
];
private _lowHullBorderControls = [
    [[7110, 7111, 7112, 7113], 0.16],
    [[7114, 7115, 7116, 7117], 0.28],
    [[7118, 7119, 7120, 7121], 0.45]
];
private _extensionName = "FST_SabreArmorExtension";
private _extensionEnabled = true;
private _nextExtensionUpdate = 0;
private _assessment = [100, 100, 100, 100, 100, "NOMINAL", false];
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

    cutRsc ["FST_SabreArmorStatus", "PLAIN", 0, false];
    waitUntil {
        uiSleep 0.05;
        !isNull (uiNamespace getVariable ["FST_SabreArmorStatus", displayNull])
    };

    private _display = uiNamespace getVariable ["FST_SabreArmorStatus", displayNull];
    while {alive _vehicle && {vehicle player isEqualTo _vehicle} && {!isNull _display}} do {
        private _damageValues = [
            (_vehicle getHitPointDamage "HitFrontArmor") max 0 min 1,
            (_vehicle getHitPointDamage "HitLSideArmor") max 0 min 1,
            (_vehicle getHitPointDamage "HitRSideArmor") max 0 min 1,
            (_vehicle getHitPointDamage "HitRearArmor") max 0 min 1,
            (damage _vehicle) max 0 min 1
        ];

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
                diag_log format ["[FST Sabre Armor] Extension response rejected; using local assessment. Response: %1", _response];
            };
        };

        if (!_extensionEnabled) then {
            _assessment = (_damageValues apply {round ((1 - _x) * 100)}) + ["LOCAL", false];
        };

        {
            _x params ["_controlId", "_valueControlId", "_hitpoint"];
            private _damageIndex = _forEachIndex;
            private _integrity = _assessment select _damageIndex;
            private _damage = 1 - (_integrity / 100);
            (_display displayCtrl _controlId) ctrlSetBackgroundColor [0.12 + (0.88 * _damage), 0.80 - (0.68 * _damage), 0.20 - (0.15 * _damage), 0.9];
            (_display displayCtrl _valueControlId) ctrlSetText format ["%1%%", _integrity];
        } forEach _indicators;

        private _vehicleDamage = 1 - ((_assessment select 4) / 100);
        (_display displayCtrl 7109) ctrlSetBackgroundColor [0.12 + (0.88 * _vehicleDamage), 0.80 - (0.68 * _vehicleDamage), 0.20 - (0.15 * _vehicleDamage), 0.9];
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

        private _isCrew = player isEqualTo driver _vehicle || {player isEqualTo gunner _vehicle} || {player isEqualTo commander _vehicle};
        private _hullDamage = (_vehicle getHitPointDamage "HitHull") max 0 min 1;
        private _alertStrength = if (_isCrew && {(_assessment select 6) || {_hullDamage > 0.4}}) then {
            0.35 + ((sin (diag_tickTime * 720) + 1) * 0.325)
        } else {
            0
        };
        {
            _x params ["_controlIds", "_opacity"];
            {
                (_display displayCtrl _x) ctrlSetBackgroundColor [1, 0.02, 0.02, _alertStrength * _opacity];
            } forEach _controlIds;
        } forEach _lowHullBorderControls;

        uiSleep 0.1;
    };

    cutText ["", "PLAIN"];
};

_vehicle setVariable ["FST_sabreArmorStatusRunning", false];