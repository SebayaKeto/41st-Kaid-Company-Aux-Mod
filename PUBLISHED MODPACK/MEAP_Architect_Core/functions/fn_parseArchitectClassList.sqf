if (!isServer) exitWith {[]};
call MEAP_fnc_initializeArchitectState;

private _parseClassList =
{
    params ["_value"];
    if (_value isEqualType []) exitWith {_value select {_x isEqualType ""}};
    if !(_value isEqualType "") exitWith {[]};

    private _parsedValue = [];
    if (!isNil {_parsedValue = parseSimpleArray _value} && {_parsedValue isEqualType []}) exitWith
    {
        _parsedValue select {_x isEqualType ""}
    };

    // Also tolerate a CBA-saved quoted list when parseSimpleArray cannot read it.
    (_value splitString "[],;""") select {_x isNotEqualTo ""}
};

private _serialized = missionNamespace getVariable ["MEAP_Architect_allowedClassList", "[]"];
private _parsed = [_serialized] call _parseClassList;

if (_parsed isEqualTo [] && {_serialized isNotEqualTo "[]"}) then
{
    diag_log "[MEAP Daidalos] The allowed class setting was empty or malformed; no custom classes were read.";
};

if (missionNamespace getVariable ["MEAP_Architect_includeDefaultClasses", true]) then
{
    private _bundled = missionNamespace getVariable ["MEAP_Architect_defaultClasses", []];
    if !(_bundled isEqualType []) then
    {
        _bundled = [_bundled] call _parseClassList;
    };
    if (_bundled isNotEqualTo []) then
    {
        _parsed append _bundled;
    };
};

private _allowed = [];
private _rejected = [];

{
    if (_x isEqualType "") then
    {
        private _class = configFile >> "CfgVehicles" >> _x;

        if (isClass _class && {getNumber (_class >> "scope") == 2}) then
        {
            _allowed pushBackUnique _x;
        }
        else
        {
            private _reason = "is not a public CfgVehicles class";
            if !(isClass _class) then {_reason = "is not registered in CfgVehicles; check that its PBO config.bin is loaded";};
            if (isClass _class && {getNumber (_class >> "scope") != 2}) then {_reason = "is not public (scope must be 2)";};
            _rejected pushBackUnique format ["%1 (%2)", _x, _reason];
        };
    }
    else
    {
        _rejected pushBackUnique str _x;
    };
} forEach _parsed;

if (_allowed isEqualTo []) then
{
    private _fallbackClasses =
    [
        "Land_BagFence_Long_F",
        "Land_BagFence_Round_F",
        "Land_BagFence_Short_F",
        "Land_HBarrier_3_F",
        "Land_HBarrier_5_F",
        "Land_CncBarrier_F",
        "Land_CncBarrierMedium_F",
        "Land_Cargo_House_V1_F",
        "Land_Cargo_Patrol_V1_F",
        "Land_Cargo_Tower_V1_F",
        "Land_Scaffolding_F"
    ];
    {
        private _fallbackConfig = configFile >> "CfgVehicles" >> _x;
        if (isClass _fallbackConfig && {getNumber (_fallbackConfig >> "scope") == 2}) then
        {
            _allowed pushBack _x;
        };
    } forEach _fallbackClasses;

    diag_log format ["[MEAP Daidalos] No configured construction class survived validation; using vanilla fallbacks: %1", _allowed];
};

MEAP_Architect_allowedClasses = _allowed;

diag_log format ["[MEAP Daidalos] Accepted construction classes: %1", _allowed
];

if (_rejected isNotEqualTo []) then
{
    diag_log format ["[MEAP Daidalos] Rejected unsafe or invalid classes: %1", _rejected];
};

private _sessions = missionNamespace getVariable ["MEAP_Architect_sessions", createHashMap];
private _sessionUnits = values _sessions apply {_x select 0};
{
    [_x, true, _x getVariable ["MEAP_Architect_serverCloseToken", ""]] call MEAP_fnc_closeArchitectMode;
} forEach _sessionUnits;

_allowed