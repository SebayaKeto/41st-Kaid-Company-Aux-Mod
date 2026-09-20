// FST_HCSpawn_fnc_frontlineSpawn
// Server-side. Spawns waves of droids at a position and sends them to assault
// toward the nearest bluefor units. Designed for Zeus to click behind a ridge
// or out of player sight -- droids spawn and immediately push.
//
// Arguments:
//   0: POSITION -- spawn origin (behind cover, out of player sight)
//   1: STRING   -- template key
//   2: NUMBER   -- number of groups to spawn
//   3: NUMBER   -- delay between waves (seconds)
//   4: NUMBER   -- assault radius (how far to search for targets)
//   5: NUMBER   -- requesting client owner ID (for feedback)

if (!isServer) exitWith {};

params ["_pos", "_templateKey", "_waveCount", "_waveDelay", "_assaultRadius", "_callerID"];

private _template = FST_HC_Templates getOrDefault [_templateKey, []];
if (count _template == 0) exitWith {
    diag_log format ["[FST_HCSpawn] Frontline: unknown template '%1'", _templateKey];
};

_template params ["_side", "_unitClasses", "_desc"];

// V14: no automatic dead-group cleanup in heavy spawn paths. Run manual/rare maintenance cleanup during lulls.

// Heavy module safety.
if ((missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true]) && {count FST_HC_Array == 0}) exitWith {
    "[FST] Frontline blocked: no headless clients are connected." remoteExec ["systemChat", _callerID];
    diag_log format ["[FST_HCSpawn] Frontline blocked with no HCs. template=%1 waves=%2", _templateKey, _waveCount];
};

// AI cap check -- use a real function exit.
private _totalUnits = count _unitClasses * _waveCount;
private _capBlocked = false;
private _cap = missionNamespace getVariable ["FST_HC_AICap", 0];
if (_cap > 0) then {
    private _current = 0;
    { _current = _current + _x; } forEach FST_HC_UnitCounts;
    if ((_current + _totalUnits) > _cap) then {
        _capBlocked = true;
        format ["[FST] AI cap -- frontline blocked (%1 + %2 > %3)", _current, _totalUnits, _cap]
            remoteExec ["systemChat", _callerID];
        diag_log format ["[FST_HCSpawn] Frontline blocked by AI cap. current=%1 requested=%2 cap=%3", _current, _totalUnits, _cap];
    };
};
if (_capBlocked) exitWith {};

format ["[FST] Frontline: %1x %2 -- waves every %3s", _waveCount, _desc, _waveDelay]
    remoteExec ["systemChat", _callerID];

diag_log format ["[FST_HCSpawn] Frontline: %1x '%2' at %3, radius %4, delay %5s", _waveCount, _templateKey, _pos, _assaultRadius, _waveDelay];

// Heavy spawn: hold off despawn cleanup while waves land.
missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time];

// Staggered wave dispatch
[_pos, _side, _unitClasses, _waveCount, _waveDelay, _assaultRadius, _callerID] spawn {
    params ["_pos", "_side", "_unitClasses", "_waveCount", "_waveDelay", "_assaultRadius", "_callerID"];

    private _deployed = 0;
    for "_wave" from 1 to _waveCount do {
        // Spawn on least-loaded HC via the normal pipeline. _callerID is passed as
        // the source owner so cap / no-HC feedback reaches the requesting Zeus.
        private _ok = [_side, _unitClasses, _pos, "assault", _assaultRadius, [], [], _callerID] call FST_HCSpawn_fnc_spawnGroupOnTarget;
        if (!_ok) exitWith {
            diag_log format ["[FST_HCSpawn] Frontline stopped at wave %1/%2: spawn blocked", _wave, _waveCount];
        };
        _deployed = _deployed + 1;
        missionNamespace setVariable ["FST_HC_LastHeavySpawnTime", time];

        if (_wave < _waveCount) then {
            sleep _waveDelay;
        };
    };

    private _msg = if (_deployed == _waveCount) then {
        format ["[FST] Frontline complete -- %1 waves deployed", _deployed]
    } else {
        format ["[FST] Frontline stopped -- %1/%2 waves deployed (cap or no usable HC)", _deployed, _waveCount]
    };
    _msg remoteExec ["systemChat", _callerID];
};
