params [
    ["_action", "", [""]],
    ["_unit", objNull, [objNull]],
    ["_heart", objNull, [objNull]]
];

if (!isServer || {isNull _unit} || {!isPlayer _unit} || {remoteExecutedOwner != owner _unit}) exitWith {};
call MEAP_fnc_initializeArchitectState;

private _sender = remoteExecutedOwner;
private _sendMessage =
{
    params ["_message"];
    [_message] remoteExecCall ["MEAP_fnc_architectMessage", _sender];
};

private _heartClass = missionNamespace getVariable ["MEAP_Architect_fobHeartClass", ""];
private _range = missionNamespace getVariable ["MEAP_Architect_fobInteractionRange", 5];
if (
    _heartClass isEqualTo ""
    || {isNull _heart}
    || {!alive _heart}
    || {typeOf _heart isNotEqualTo _heartClass}
    || {_unit distance _heart > _range}
) exitWith
{
    ["Move closer to an active Daidalos FOB heart."] call _sendMessage;
};

private _fobKey = netId _heart;
private _fob = MEAP_Architect_fobs getOrDefault [_fobKey, []];
if (_fob isEqualTo []) exitWith
{
    ["This FOB heart is still being established."] call _sendMessage;
};

private _normalizedAction = toUpper _action;
if (_normalizedAction isEqualTo "STATUS") exitWith
{
    private _stock = [_heart] call MEAP_fnc_economyGetStock;
    [format ["FOB %1: %2 | Economy: Credits %3, Lumber %4, Stone %5, Supplies %6.", missionNamespace getVariable ["MEAP_Architect_currencyName", "Republic Credits"], _fob select 1, _stock select 0, _stock select 1, _stock select 2, _stock select 3]] call _sendMessage;
};
if (_normalizedAction isEqualTo "PROCESS") exitWith
{
    if !(missionNamespace getVariable ["MEAP_Economy_enabled", true]) exitWith { ["MEAP Economy is disabled."] call _sendMessage; };
    private _recipes = [];
    private _serializedRecipes = missionNamespace getVariable ["MEAP_Architect_fobMaterialRecipes", "[]"];
    if (isNil {_recipes = parseSimpleArray _serializedRecipes} || {!(_recipes isEqualType [])}) exitWith { ["FOB material recipes are not configured correctly."] call _sendMessage; };
    private _stock = [_heart] call MEAP_fnc_economyGetStock;
    private _resourceTypes = ["Credits", "Lumber", "Stone", "Supplies"];
    private _processed = [];
    {
        if (_x isEqualTypeParams ["", 0, "", 0]) then
        {
            _x params ["_inputType", "_inputAmount", "_outputType", "_outputAmount"];
            private _inputIndex = _resourceTypes find _inputType;
            private _outputIndex = _resourceTypes find _outputType;
            if (_inputIndex >= 0 && {_outputIndex >= 0} && {_inputAmount > 0} && {_outputAmount > 0}) then
            {
                private _batches = floor ((_stock select _inputIndex) / _inputAmount);
                if (_batches > 0) then
                {
                    _stock set [_inputIndex, (_stock select _inputIndex) - (_batches * _inputAmount)];
                    _stock set [_outputIndex, (_stock select _outputIndex) + (_batches * _outputAmount)];
                    _processed pushBack format ["%1 %2 -> %3 %4", _batches * _inputAmount, _inputType, _batches * _outputAmount, _outputType];
                };
            };
        };
    } forEach _recipes;
    if (_processed isEqualTo []) exitWith { ["The FOB does not have enough Economy materials for a configured recipe."] call _sendMessage; };
    [_heart, _stock] call MEAP_fnc_economySetStock;
    ["PROCESS", _unit, _heart, format ["%1", _processed joinString "; "]] call MEAP_fnc_architectRecordAudit;
    [format ["FOB processed: %1.", _processed joinString "; "]] call _sendMessage;
};
if (_normalizedAction isNotEqualTo "DEPOSIT") exitWith {};

private _serialized = missionNamespace getVariable ["MEAP_Architect_fobDepositValues", "[]"];
private _depositValues = [];
if (isNil {_depositValues = parseSimpleArray _serialized} || {!(_depositValues isEqualType [])}) exitWith
{
    ["FOB deposit values are not configured correctly."] call _sendMessage;
};

private _deposited = 0;
{
    if (_x isEqualTypeParams ["", 0]) then
    {
        _x params ["_currencyClass", "_value"];
        private _isMagazine = isClass (configFile >> "CfgMagazines" >> _currencyClass);
        private _owned = if (_isMagazine) then {magazines _unit} else {items _unit};
        private _ownedCount = {_x isEqualTo _currencyClass} count _owned;
        if (_ownedCount > 0 && {_value > 0}) then
        {
            for "_index" from 1 to _ownedCount do
            {
                if (_isMagazine) then {_unit removeMagazine _currencyClass;} else {_unit removeItem _currencyClass;};
            };
            _deposited = _deposited + (_ownedCount * _value);
        };
    };
} forEach _depositValues;

if (_deposited <= 0) exitWith
{
    ["You are not carrying any configured FOB currency."] call _sendMessage;
};

_fob set [1, (_fob select 1) + _deposited];
MEAP_Architect_fobs set [_fobKey, _fob];
[format ["Deposited %1 %2. FOB balance: %3.", _deposited, missionNamespace getVariable ["MEAP_Architect_currencyName", "Republic Credits"], _fob select 1]] call _sendMessage;
