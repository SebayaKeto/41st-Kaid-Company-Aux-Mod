// FST_HCSpawn_fnc_quickSpawnAtPos
// Server-side. Resolves template and routes to spawn pipeline.

if (!isServer) exitWith {};

params ["_pos", "_templateKey", "_behavior", ["_radius", -1]];

private _template = FST_HC_Templates getOrDefault [_templateKey, []];
if (count _template == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Unknown template '%1'", _templateKey];
};

_template params ["_side", "_unitClasses", "_desc"];

[_side, _unitClasses, _pos, _behavior, _radius, []] call FST_HCSpawn_fnc_spawnGroupOnTarget;
