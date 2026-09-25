// FST_HCSpawn_fnc_checkObjectives
// Server-side. PFH checking player proximity to objectives.
// Efficiency pass: build player list once, then check marker distances.
// This avoids a nearEntities CAManBase sweep per objective once AI counts are high.
//
// V27: an objective is only marked as fired once at least one of its groups was
// actually dispatched. Before, it was marked before spawning, and if the spawn
// router blocked (HCs still connecting, all HCs soft-capped) the objective was
// silently lost for the rest of the op. Blocked objectives now retry every 30s.

if (!isServer) exitWith {};

missionNamespace setVariable ["FST_HC_ObjectivesDispatching", []];
missionNamespace setVariable ["FST_HC_ObjectiveNextTry", createHashMap];

[{
    // Nothing registered, or everything already fired: skip the player build.
    if (count FST_HC_Objectives == 0) exitWith {};
    if (count FST_HC_ObjectivesFired >= count FST_HC_Objectives) exitWith {};

    private _dist = FST_HC_TriggerActivationDist;
    private _players = ([] call CBA_fnc_players) select { alive _x };
    if (count _players == 0) exitWith {};

    private _dispatching = missionNamespace getVariable ["FST_HC_ObjectivesDispatching", []];
    private _nextTry = missionNamespace getVariable ["FST_HC_ObjectiveNextTry", createHashMap];

    {
        _x params ["_marker", "_radius", "_spawnDefs"];
        if (_marker in FST_HC_ObjectivesFired) then { continue };
        if (_marker in _dispatching) then { continue };
        if (time < (_nextTry getOrDefault [_marker, -1])) then { continue };

        private _pos = getMarkerPos _marker;
        private _nearIdx = _players findIf { (_x distance2D _pos) <= _dist };

        if (_nearIdx >= 0) then {
            _dispatching pushBack _marker;
            diag_log format ["[FST_HCSpawn] Objective '%1' triggered -- %2 groups", _marker, count _spawnDefs];

            [_spawnDefs, _pos, _radius, _marker] spawn {
                params ["_defs", "_pos", "_radius", "_marker"];
                private _dispatched = 0;
                {
                    _x params ["_key","_bhv"];
                    private _template = FST_HC_Templates getOrDefault [_key, []];
                    if (count _template > 0) then {
                        _template params ["_side", "_unitClasses"];
                        if ([_side, _unitClasses, _pos, _bhv, _radius, []] call FST_HCSpawn_fnc_spawnGroupOnTarget) then {
                            _dispatched = _dispatched + 1;
                            missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time];
                        };
                    };
                    sleep 0.5;
                } forEach _defs;

                private _list = missionNamespace getVariable ["FST_HC_ObjectivesDispatching", []];
                missionNamespace setVariable ["FST_HC_ObjectivesDispatching", _list - [_marker]];

                if (_dispatched > 0) then {
                    FST_HC_ObjectivesFired pushBackUnique _marker;
                    if (_dispatched < count _defs) then {
                        diag_log format ["[FST_HCSpawn] Objective '%1' partially spawned: %2/%3 groups (cap/HC limits)", _marker, _dispatched, count _defs];
                    };
                } else {
                    (missionNamespace getVariable ["FST_HC_ObjectiveNextTry", createHashMap]) set [_marker, time + 30];
                    diag_log format ["[FST_HCSpawn] Objective '%1' could not spawn (no usable HC / cap). Retrying in 30s.", _marker];
                };
            };
        };
    } forEach FST_HC_Objectives;
// 5s interval. This scales with players x objectives, not AI x objectives.
}, 5, []] call CBA_fnc_addPerFrameHandler;
