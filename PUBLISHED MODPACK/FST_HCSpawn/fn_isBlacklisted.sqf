// FST_HCSpawn_fnc_isBlacklisted
// Server-side. Checks if a group should be excluded from HC offload.
// Caches result on the group to avoid re-checking.
//
// Arguments:
//   0: GROUP
// Returns: BOOL

params ["_group"];

// Already cached?
private _cached = _group getVariable ["FST_HC_blResult", -1];
if (_cached != -1) exitWith { _cached == 1 };

private _exempt = false;

// Player group
if (isPlayer leader _group) exitWith { true };

// Empty / null
if (isNull _group || {count units _group == 0}) exitWith { true };

// Explicitly blacklisted via variable
if (_group getVariable ["FST_HC_blacklisted", false]) exitWith {
    _group setVariable ["FST_HC_blResult", 1];
    true
};

// Vehicle blacklist
if (FST_HC_BlacklistVehicles && {vehicle leader _group != leader _group}) exitWith {
    _group setVariable ["FST_HC_blResult", 1];
    true
};

// splitString's second arg is a *set* of delimiter characters, not a delimiter
// string. Using ", " would tokenize on every space too, breaking entries that
// contain spaces. Split on comma only and trim each entry. Cache parsed settings
// so catch-all/transfer sweeps do not re-tokenize the same strings per group.
private _rawNames = missionNamespace getVariable ["FST_HC_BlacklistNames", ""];
private _rawTypes = missionNamespace getVariable ["FST_HC_BlacklistTypes", ""];
private _nameCache = missionNamespace getVariable ["FST_HC_BlacklistNamesCache", ["", []]];
private _typeCache = missionNamespace getVariable ["FST_HC_BlacklistTypesCache", ["", []]];

private _badNames = [];
if ((_nameCache select 0) isEqualTo _rawNames) then {
    _badNames = _nameCache select 1;
} else {
    _badNames = (_rawNames splitString ",") apply { _x call BIS_fnc_trimString };
    _badNames = _badNames select { _x != "" };
    missionNamespace setVariable ["FST_HC_BlacklistNamesCache", [_rawNames, _badNames]];
};

private _badTypes = [];
if ((_typeCache select 0) isEqualTo _rawTypes) then {
    _badTypes = _typeCache select 1;
} else {
    _badTypes = (_rawTypes splitString ",") apply { _x call BIS_fnc_trimString };
    _badTypes = _badTypes select { _x != "" };
    missionNamespace setVariable ["FST_HC_BlacklistTypesCache", [_rawTypes, _badTypes]];
};

// Check unit types
if (count _badTypes > 0) then {
    {
        private _type = typeOf _x;
        { if (_x in _type) exitWith { _exempt = true }; } forEach _badTypes;
        if (_exempt) exitWith {};
    } forEach units _group;
};

if (!_exempt && count _badNames > 0) then {
    private _grpName = str _group;
    { if (_x in _grpName) exitWith { _exempt = true }; } forEach _badNames;
};

// Cache result
_group setVariable ["FST_HC_blResult", [0, 1] select _exempt];

_exempt
