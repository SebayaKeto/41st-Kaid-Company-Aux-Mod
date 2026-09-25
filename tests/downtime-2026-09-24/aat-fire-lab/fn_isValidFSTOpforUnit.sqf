// FST_HCSpawn_fnc_isValidFSTOpforUnit
// Returns true only for configured, spawnable FST_ OPFOR infantry classes.
// Used by Fill Garrison so clients cannot request arbitrary classnames.

params [["_class", "", [""]]];

if (_class isEqualTo "") exitWith { false };
if !((_class select [0, 4]) isEqualTo "FST_") exitWith { false };

private _cfg = configFile >> "CfgVehicles" >> _class;
if !(isClass _cfg) exitWith { false };

// CfgVehicles side value 0 = EAST/OPFOR.
if ((getNumber (_cfg >> "side")) != 0) exitWith { false };

// Keep this to infantry/man classes only. Prevents vehicles, statics, logics, crates, etc.
if !(_class isKindOf "CAManBase") exitWith { false };

// Hide abstract/internal classes, but allow curator-only units if a faction uses them.
private _scope = getNumber (_cfg >> "scope");
private _scopeCurator = getNumber (_cfg >> "scopeCurator");
if (_scope <= 0 && {_scopeCurator <= 0}) exitWith { false };

true
