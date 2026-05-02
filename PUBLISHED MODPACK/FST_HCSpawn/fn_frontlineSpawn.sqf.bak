// FST_HCSpawn_fnc_frontlineSpawn
// Server-side. Spawns waves of droids at a position and sends them to assault
// toward the nearest bluefor units. Designed for Zeus to click behind a ridge
// or out of player sight — droids spawn and immediately push.
//
// Arguments:
//   0: POSITION — spawn origin (behind cover, out of player sight)
//   1: STRING   — template key
//   2: NUMBER   — number of groups to spawn
//   3: NUMBER   — delay between waves (seconds)
//   4: NUMBER   — assault radius (how far to search for targets)
//   5: NUMBER   — requesting client owner ID (for feedback)

if (!isServer) exitWith {};

params ["_pos", "_templateKey", "_waveCount", "_waveDelay", "_assaultRadius", "_callerID"];

private _template = FST_HC_Templates getOrDefault [_templateKey, []];
if (count _template == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Frontline: unknown template '%1'", _templateKey];
};

_template params ["_side", "_unitClasses", "_desc"];

// AI cap check
private _totalUnits = count _unitClasses * _waveCount;
private _cap = FST_HC_AICap;
if (_cap > 0) then {
    private _current = 0;
    { _current = _current + _x; } forEach FST_HC_UnitCounts;
    if (_current + _totalUnits > _cap) exitWith {
        format ["[FST] AI cap — frontline blocked (%1 + %2 > %3)", _current, _totalUnits, _cap]
            remoteExec ["systemChat", _callerID];
    };
};

format ["[FST] Frontline: %1x %2 — waves every %3s", _waveCount, _desc, _waveDelay]
    remoteExec ["systemChat", _callerID];

diag_log format ["[FST_HCSpawn] Frontline: %1x '%2' at %3, radius %4, delay %5s", _waveCount, _templateKey, _pos, _assaultRadius, _waveDelay];

// Staggered wave dispatch
[_pos, _side, _unitClasses, _waveCount, _waveDelay, _assaultRadius, _callerID] spawn {
    params ["_pos", "_side", "_unitClasses", "_waveCount", "_waveDelay", "_assaultRadius", "_callerID"];

    for "_wave" from 1 to _waveCount do {
        // Spawn on least-loaded HC via the normal pipeline
        [_side, _unitClasses, _pos, "assault", _assaultRadius, []] call FST_HCSpawn_fnc_spawnGroupOnTarget;

        if (_wave < _waveCount) then {
            sleep _waveDelay;
        };
    };

    format ["[FST] Frontline complete — %1 waves deployed", _waveCount]
        remoteExec ["systemChat", _callerID];
};
