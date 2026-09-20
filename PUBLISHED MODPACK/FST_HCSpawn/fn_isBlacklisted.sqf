// FST_HCSpawn_fnc_isBlacklisted
// Server-side (also called on the Zeus client before an instant clone).
// Checks if a group should be excluded from HC offload.
//
// V27 changes:
// - The vehicle check is evaluated live. It used to be cached forever on the
//   group, so a squad that dismounted (or mounted) after the first check kept
//   its stale verdict.
// - The per-group verdict cache is keyed to the current blacklist strings, so
//   changing the CBA setting mid-op re-evaluates groups instead of being ignored.
// - "Blacklisted Names" now matches unit variable names (vehicleVarName), the
//   leader's vehicle variable name and the group id, as the setting text says.
//   It used to match only str(group), which is "O Alpha 1-1" style text.
// - Matching is case-insensitive.
//
// Arguments:
//   0: GROUP
// Returns: BOOL

params ["_group"];

if (isNull _group) exitWith { true };
if (isPlayer leader _group) exitWith { true };
if (count units _group == 0) exitWith { true };

// Explicitly blacklisted via variable (mission makers)
if (_group getVariable ["FST_HC_blacklisted", false]) exitWith { true };

// Vehicle blacklist -- live, never cached.
if (FST_HC_BlacklistVehicles && {vehicle leader _group != leader _group}) exitWith { true };

// splitString's second arg is a *set* of delimiter characters, not a delimiter
// string. Using ", " would tokenize on every space too, breaking entries that
// contain spaces. Split on comma only and trim each entry. Cache parsed settings
// so catch-all/transfer sweeps do not re-tokenize the same strings per group.
private _rawNames = missionNamespace getVariable ["FST_HC_BlacklistNames", ""];
private _rawTypes = missionNamespace getVariable ["FST_HC_BlacklistTypes", ""];
private _signature = _rawNames + "|" + _rawTypes;

// Per-group verdict cache: [settingsSignature, result]
private _cached = _group getVariable ["FST_HC_blResult", []];
if (_cached isEqualType [] && {count _cached == 2} && {(_cached select 0) isEqualTo _signature}) exitWith { _cached select 1 };

private _parsed = missionNamespace getVariable ["FST_HC_BlacklistParsedCache", ["", [], []]];
if !((_parsed select 0) isEqualTo _signature) then {
    private _badNames = ((toLower _rawNames) splitString ",") apply { _x call BIS_fnc_trimString };
    _badNames = _badNames select { _x != "" };
    private _badTypes = ((toLower _rawTypes) splitString ",") apply { _x call BIS_fnc_trimString };
    _badTypes = _badTypes select { _x != "" };
    _parsed = [_signature, _badNames, _badTypes];
    missionNamespace setVariable ["FST_HC_BlacklistParsedCache", _parsed];
};
_parsed params ["", "_badNames", "_badTypes"];

private _exempt = false;

// Check unit types (substring, case-insensitive)
if (count _badTypes > 0) then {
    {
        private _type = toLower typeOf _x;
        if ((_badTypes findIf { _x in _type }) >= 0) exitWith { _exempt = true; };
    } forEach units _group;
};

// Check names: unit variable names, leader vehicle variable name, group id
if (!_exempt && {count _badNames > 0}) then {
    private _candidates = [toLower groupId _group];
    {
        private _vn = vehicleVarName _x;
        if (_vn != "") then { _candidates pushBack (toLower _vn); };
    } forEach units _group;
    private _leaderVeh = vehicle leader _group;
    if (_leaderVeh != leader _group) then {
        private _vvn = vehicleVarName _leaderVeh;
        if (_vvn != "") then { _candidates pushBack (toLower _vvn); };
    };

    {
        private _name = _x;
        if ((_badNames findIf { _x in _name }) >= 0) exitWith { _exempt = true; };
    } forEach _candidates;
};

// Cache result against the current settings
_group setVariable ["FST_HC_blResult", [_signature, _exempt]];

_exempt
