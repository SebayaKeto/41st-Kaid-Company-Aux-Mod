// FST_HCSpawn_fnc_checkObjectives
// Server-side. PFH checking player proximity to objectives.

if (!isServer) exitWith {};

[{
    private _dist = FST_HC_TriggerActivationDist;

    {
        _x params ["_marker", "_radius", "_spawnDefs"];
        if (_marker in FST_HC_ObjectivesFired) then { continue };

        private _pos = getMarkerPos _marker;
        private _near = _pos nearEntities ["CAManBase", _dist];
        _near = _near select { isPlayer _x && alive _x };

        if (count _near > 0) then {
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
}, 3, []] call CBA_fnc_addPerFrameHandler;
