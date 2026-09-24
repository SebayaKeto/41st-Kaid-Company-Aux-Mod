params [["_className", "", [""]]];

private _defaultCost = missionNamespace getVariable ["MEAP_Architect_defaultBuildCost", 5];
if (_className isEqualTo "") exitWith {_defaultCost};

private _serialized = missionNamespace getVariable ["MEAP_Architect_buildCosts", "[]"];
private _configuredCosts = [];
if (isNil {_configuredCosts = parseSimpleArray _serialized} || {!(_configuredCosts isEqualType [])}) exitWith {_defaultCost};

private _cost = _defaultCost;
{
    if (_x isEqualTypeParams ["", 0] && {(_x select 0) isEqualTo _className}) exitWith
    {
        _cost = (_x select 1) max 0;
    };
} forEach _configuredCosts;

_cost
