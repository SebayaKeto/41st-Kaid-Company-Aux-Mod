params [["_unit", objNull, [objNull]]];

if (!isServer || {isNull _unit} || {!isPlayer _unit}) exitWith {false};

private _isAdvancedEngineer =
    (missionNamespace getVariable ["MEAP_Architect_allowAdvancedEngineers", true])
    && {!isNil "ace_common_fnc_isEngineer"}
    && {[_unit, 2] call ace_common_fnc_isEngineer};

private _key = [_unit] call MEAP_fnc_getArchitectKey;
private _grants = missionNamespace getVariable ["MEAP_Architect_grants", createHashMap];
private _hasArchitectGrant = _grants getOrDefault [_key, false];

_isAdvancedEngineer || {_hasArchitectGrant}