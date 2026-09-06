// Loads + caches the current map's cached tree position data, if any
// Returns [] gracefully if this map has no data file — see README.md

if (!isNil "UMBARA_MapDataCache") exitWith {UMBARA_MapDataCache};

private _path = format ["umbara_trees\data\%1.sqf", toLower worldName];
private _raw = preprocessFileLineNumbers _path;

if (_raw == "") exitWith {UMBARA_MapDataCache = []; UMBARA_MapDataCache};

private _data = call compile _raw;
if (isNil "_data" || {!(_data isEqualType [])}) exitWith {UMBARA_MapDataCache = []; UMBARA_MapDataCache};

UMBARA_MapDataCache = _data;
UMBARA_MapDataCache
