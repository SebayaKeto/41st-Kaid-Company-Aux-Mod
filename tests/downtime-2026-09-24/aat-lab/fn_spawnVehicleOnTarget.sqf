// FST_HCSpawn_fnc_spawnVehicleOnTarget
// Server-side (V28). Single entry point for creating a crewed AI vehicle on the
// dedicated vehicle HC (or the least-loaded HC when there is none). The vehicle,
// its crew and its group are all created on that one machine, so nothing ever
// changes owner afterwards. Use this instead of createVehicle +
// createVehicleCrew on the server from Zeus modules and mission scripts.
//
// Arguments:
//   0: SIDE    - crew side
//   1: STRING  - vehicle classname
//   2: ARRAY   - position (ATL). Aircraft with "flying" spawn at this height.
//   3: NUMBER  - direction (default 0)
//   4: STRING  - behaviour (default "none"):
//                "none"    combat mode RED / AWARE, engine as requested, no orders
//                "hold"    stay put, combat mode RED
//                "patrol"  BURNS native waypoint patrol (ground)
//                "hunt"    BURNS approach/search around the position
//                "assault" BURNS advance toward the position
//                "move"    MOVE waypoint to the target position
//                "sad"     SEEK AND DESTROY waypoint at the target, then loiter
//                "loiter"  LOITER waypoint (aircraft) at the target
//   5: NUMBER  - radius (default -1 = per behaviour)
//   6: NUMBER  - requesting client owner ID (-1 for server scripts)
//   7: ARRAY   - options, key/value pairs, all optional:
//                ["flying", BOOL]     spawn airborne with forward velocity (aircraft)
//                ["engineOn", BOOL]   default true
//                ["skill", NUMBER]    crew skill 0..1 (default: unchanged)
//                ["target", ARRAY]    position for move/sad/loiter (default: 2)
//                ["combatMode", STR]  default "RED"
//                ["behaviour", STR]   default "AWARE"
//                ["tag", STRING]      free text stored on the group as FST_HC_spawnTag
//
// Returns: BOOL - true if dispatched.

if (!isServer) exitWith { false };

params ["_side", "_vehClass", "_pos", ["_dir", 0], ["_behavior", "none"], ["_radius", -1], ["_sourceOwner", -1], ["_opts", []]];

private _feedback = {
    params ["_msg"];
    if (_sourceOwner > 2) then { _msg remoteExec ["systemChat", _sourceOwner]; };
    diag_log format ["[FST_HCSpawn] %1", _msg];
};

if (!isClass (configFile >> "CfgVehicles" >> _vehClass)) exitWith {
    [format ["[FST] Vehicle spawn blocked: unknown class %1", _vehClass]] call _feedback;
    false
};

private _optMap = createHashMapFromArray _opts;
private _isAir = _vehClass isKindOf "Air";
private _flying = _optMap getOrDefault ["flying", _isAir];
private _engineOn = _optMap getOrDefault ["engineOn", true];
private _skill = _optMap getOrDefault ["skill", -1];
private _target = _optMap getOrDefault ["target", _pos];
private _combatMode = _optMap getOrDefault ["combatMode", "RED"];
private _aiBehaviour = _optMap getOrDefault ["behaviour", "AWARE"];
private _tag = _optMap getOrDefault ["tag", ""];

// Crew count is unknown until the HC builds it; estimate for the cap check.
private _crewEstimate = 1 + count (configProperties [configFile >> "CfgVehicles" >> _vehClass >> "Turrets", "isClass _x"]);
private _cap = missionNamespace getVariable ["FST_HC_AICap", 0];
private _capBlocked = false;
if (_cap > 0) then {
    private _total = 0;
    { _total = _total + _x; } forEach FST_HC_UnitCounts;
    if ((_total + _crewEstimate) > _cap) then {
        _capBlocked = true;
        [format ["[FST] AI cap reached -- vehicle spawn blocked (%1 + %2 > %3).", _total, _crewEstimate, _cap]] call _feedback;
    };
};
if (_capBlocked) exitWith { false };

private _targetId = ["vehicle", _crewEstimate] call FST_HCSpawn_fnc_getSpawnTarget;
private _isOnHC = _targetId != 2;
private _hcIndex = if (_isOnHC) then { FST_HC_Ids find _targetId } else { -1 };

if (!_isOnHC && {missionNamespace getVariable ["FST_HC_BlockHeavySpawnsWithoutHC", true]}) exitWith {
    [format ["[FST] Vehicle spawn blocked: no HC available for %1.", _vehClass]] call _feedback;
    false
};

if (_hcIndex >= 0 && {_hcIndex < count FST_HC_UnitCounts}) then {
    FST_HC_UnitCounts set [_hcIndex, (FST_HC_UnitCounts select _hcIndex) + _crewEstimate];
};

private _spawnPos = +_pos;
if (count _spawnPos < 3) then { _spawnPos pushBack 0; };
if (_flying && {(_spawnPos select 2) < 50}) then { _spawnPos set [2, 150]; };

// _vehData: [class, pos, dir, vectorUp, flying, skill, engineOn, combatMode, behaviour, target, tag]
private _vehData = [_vehClass, _spawnPos, _dir, [0,0,1], _flying, _skill, _engineOn, _combatMode, _aiBehaviour, _target, _tag];
private _args = [_side, [], _spawnPos, _behavior, _radius, _vehData, _isOnHC, _targetId, _hcIndex, [], _sourceOwner, []];

if (_isOnHC) then {
    ["FST_HC_evt_createGroupLocal", _args, _targetId] call CBA_fnc_ownerEvent;
} else {
    _args spawn FST_HCSpawn_fnc_createGroupLocal;
};

if (FST_HC_DebugLogging) then {
    diag_log format ["[FST_HCSpawn] Vehicle spawn %1 at %2 -> owner %3 (%4), behaviour %5", _vehClass, _spawnPos, _targetId, if (_isOnHC) then { format ["HC%1", _hcIndex + 1] } else { "server" }, _behavior];
};
true
