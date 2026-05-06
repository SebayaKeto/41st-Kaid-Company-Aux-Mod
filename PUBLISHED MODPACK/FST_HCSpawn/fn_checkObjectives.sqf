// FST_HCSpawn_fnc_checkObjectives
// Server-side. PFH checking player proximity to objectives.
// Efficiency pass: build player list once, then check marker distances.
// This avoids a nearEntities CAManBase sweep per objective once AI counts are high.

if (!isServer) exitWith {};

[{
    private _dist = FST_HC_TriggerActivationDist;
    private _players = ([] call CBA_fnc_players) select { alive _x };

    if (count _players == 0) exitWith {};

    {
        _x params ["_marker", "_radius", "_spawnDefs"];
        if (_marker in FST_HC_ObjectivesFired) then { continue };

        private _pos = getMarkerPos _marker;
        private _nearIdx = _players findIf { (_x distance2D _pos) <= _dist };

        if (_nearIdx >= 0) then {
            FST_HC_ObjectivesFired pushBack _marker;
            diag_log format ["[FST_HCSpawn] Objective '%1' triggered — %2 groups", _marker, count _spawnDefs];

            [_spawnDefs, _pos, _radius] spawn {
                params ["_defs", "_pos", "_radius"];
                {
                    _x params ["_key","_bhv"];
                    private _template = FST_HC_Templates getOrDefault [_key, []];
                    if (count _template > 0) then {
                        _template params ["_side", "_unitClasses"];
                        [_side, _unitClasses, _pos, _bhv, _radius, []] call FST_HCSpawn_fnc_spawnGroupOnTarget;
                    };
                    sleep 0.5;
                } forEach _defs;
            };
        };
    } forEach FST_HC_Objectives;
// 5s interval. This now scales with players x objectives, not AI x objectives.
}, 5, []] call CBA_fnc_addPerFrameHandler;
