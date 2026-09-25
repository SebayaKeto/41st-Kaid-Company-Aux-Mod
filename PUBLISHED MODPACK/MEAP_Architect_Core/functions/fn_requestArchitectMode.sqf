params [["_unit", objNull, [objNull]]];

if (!isServer || {isNull _unit} || {!isPlayer _unit}) exitWith {};
if (remoteExecutedOwner != owner _unit) exitWith {};
call MEAP_fnc_initializeArchitectState;

if !(missionNamespace getVariable ["MEAP_Architect_enabled", true]) exitWith
{
    ["Daidalos mode is disabled on this server."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];
};
if (!alive _unit) exitWith
{
    ["You must be alive to enter Daidalos mode."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];
};
if !([_unit] call MEAP_fnc_isArchitectEligible) exitWith
{
    ["Select an Engineer/EOD kit, be an ACE advanced engineer, or have a Zeus-granted Daidalos role."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];
};
private _accessSide = missionNamespace getVariable ["MEAP_Architect_accessSide", 0];
private _unitSide = switch (side group _unit) do
{
    case west: {1};
    case east: {2};
    case independent: {3};
    default {0};
};
if (_accessSide != 0 && {_unitSide != _accessSide}) exitWith
{
    ["Your side is not authorized to use Daidalos mode."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];
};
private _allowedClasses = missionNamespace getVariable ["MEAP_Architect_allowedClasses", []];
if (_allowedClasses isEqualTo []) then
{
    call MEAP_fnc_parseArchitectClassList;
    _allowedClasses = missionNamespace getVariable ["MEAP_Architect_allowedClasses", []];
};

if (_allowedClasses isEqualTo []) exitWith
{
    ["No valid construction classes are configured."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];
};

private _owner = owner _unit;
[_unit, false] call MEAP_fnc_closeArchitectMode;
private _token = format ["%1:%2:%3", _owner, diag_tickTime, floor random 1000000];
MEAP_Architect_sessions set [str _owner, [_unit, _token]];
// Kept on the server only; used by revocation/death/disconnect cleanup.
_unit setVariable ["MEAP_Architect_serverCloseToken", _token];
private _key = [_unit] call MEAP_fnc_getArchitectKey;
private _blueprints = [];
{
    private _blueprint = MEAP_Architect_blueprints get _x;
    _blueprint params ["_name", "_source", "_ownerKey"];
    if (_source isEqualTo "CONFIG" || {_ownerKey isEqualTo _key} || {(admin _owner) > 0}) then
    {
        _blueprints pushBack [_x, _name];
    };
} forEach keys MEAP_Architect_blueprints;

private _budgetEnabled = missionNamespace getVariable ["MEAP_Architect_budgetEnabled", true];
private _currencyName = missionNamespace getVariable ["MEAP_Architect_currencyName", "Republic Credits"];
private _availableFunds = -1;
if (_budgetEnabled) then
{
    private _fundingMode = missionNamespace getVariable ["MEAP_Architect_budgetFundingMode", 0];
    if (_fundingMode == 2) then
    {
        private _resolvedFob = [getPosASL _unit] call MEAP_fnc_getArchitectFob;
        _resolvedFob params ["_fobKey", "_fob"];
        if (_fobKey isNotEqualTo "") then {_availableFunds = _fob select 1;};
    }
    else
    {
        if (_fundingMode == 1) then
        {
            private _currencyClasses = [];
            private _serialized = missionNamespace getVariable ["MEAP_Architect_inventoryCurrencyClasses", "[]"];
            if (!isNil {_currencyClasses = parseSimpleArray _serialized} && {_currencyClasses isEqualType []}) then
            {
                _currencyClasses = _currencyClasses select {_x isEqualType ""};
            };
            private _inventory = magazines _unit;
            _inventory append items _unit;
            _availableFunds = ({_x in _currencyClasses} count _inventory) * (missionNamespace getVariable ["MEAP_Architect_inventoryCurrencyValue", 1]);
        }
        else
        {
            _availableFunds = MEAP_Architect_budgetBalances getOrDefault [_key, missionNamespace getVariable ["MEAP_Architect_startingBudget", 100]];
            MEAP_Architect_budgetBalances set [_key, _availableFunds];
        };
    };
};

["Daidalos session accepted. Opening camera..."] remoteExecCall ["MEAP_fnc_architectMessage", _unit];

[
    +_allowedClasses,
    missionNamespace getVariable ["MEAP_Architect_maxDistance", 50],
    _token,
    _budgetEnabled,
    _currencyName,
    _availableFunds,
    _blueprints
] remoteExecCall ["MEAP_fnc_openArchitectMode", _unit];
