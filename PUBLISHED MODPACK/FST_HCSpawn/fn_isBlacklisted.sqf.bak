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

// Parse blacklists (comma-separated)
private _badNames = FST_HC_BlacklistNames splitString ", ";
private _badTypes = FST_HC_BlacklistTypes splitString ", ";

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
