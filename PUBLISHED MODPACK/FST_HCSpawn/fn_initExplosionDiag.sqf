// FST_HCSpawn_fnc_initExplosionDiag
// Local automatic explosion blackbox for the dedicated server and headless clients.

if (!(isServer || {!hasInterface})) exitWith {};
if !(missionNamespace getVariable ["FST_HC_ExplosionDiagEnabled", true]) exitWith {
    diag_log "[FST_EXPDIAG][disabled] Automatic explosion diagnostics disabled by CBA setting.";
};
if (missionNamespace getVariable ["FST_HC_EXPDIAG_running", false]) exitWith {};
missionNamespace setVariable ["FST_HC_EXPDIAG_running", true];

private _machineLabel = if (isServer) then {"Server"} else {format ["HC owner %1", clientOwner]};
missionNamespace setVariable ["FST_HC_EXPDIAG_machineLabel", _machineLabel];
missionNamespace setVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap];
missionNamespace setVariable ["FST_HC_EXPDIAG_firedTotal", 0];
missionNamespace setVariable ["FST_HC_EXPDIAG_explosionEvents", 0];
missionNamespace setVariable ["FST_HC_EXPDIAG_explosionDamageTotal", 0];
missionNamespace setVariable ["FST_HC_EXPDIAG_killedUnits", 0];
missionNamespace setVariable ["FST_HC_EXPDIAG_recentAmmo", []];
missionNamespace setVariable ["FST_HC_EXPDIAG_recentExplosions", []];
missionNamespace setVariable ["FST_HC_EXPDIAG_recentDeaths", []];
missionNamespace setVariable ["FST_HC_EXPDIAG_lastImmediateLog", -9999];

["AllVehicles", "fired", {
    params ["_unit", "_weapon", "_muzzle", "_mode", "_ammo", "_magazine", "_projectile", "_vehicle"];

    if (isNull _unit) exitWith {};
    if (!local _unit) exitWith {};
    if (_ammo isEqualTo "") exitWith {};

    private _cfg = configFile >> "CfgAmmo" >> _ammo;
    if !(isClass _cfg) exitWith {};

    private _hit = getNumber (_cfg >> "hit");
    private _indirectHit = getNumber (_cfg >> "indirectHit");
    private _indirectRange = getNumber (_cfg >> "indirectHitRange");
    private _explosive = getNumber (_cfg >> "explosive");

    if ((_indirectHit > 0) || {_indirectRange > 0} || {_explosive > 0}) then {
        private _fired = missionNamespace getVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap];
        _fired set [_ammo, (_fired getOrDefault [_ammo, 0]) + 1];
        missionNamespace setVariable ["FST_HC_EXPDIAG_firedTotal", (missionNamespace getVariable ["FST_HC_EXPDIAG_firedTotal", 0]) + 1];

        private _recentLimit = missionNamespace getVariable ["FST_HC_ExplosionDiagRecentLimit", 40];
        private _recent = missionNamespace getVariable ["FST_HC_EXPDIAG_recentAmmo", []];
        _recent pushBack [
            round diag_tickTime,
            typeOf _unit,
            str (side group _unit),
            _weapon,
            _magazine,
            _ammo,
            _hit,
            _indirectHit,
            _indirectRange,
            _explosive,
            getText (_cfg >> "simulation"),
            getText (_cfg >> "explosionEffects"),
            getText (_cfg >> "craterEffects"),
            getPosATL _unit
        ];
        while {count _recent > _recentLimit} do {_recent deleteAt 0;};
    };
}] call CBA_fnc_addClassEventHandler;

["CAManBase", "explosion", {
    params ["_unit", "_damage"];

    if (isNull _unit) exitWith {};
    if (!local _unit) exitWith {};

    private _events = (missionNamespace getVariable ["FST_HC_EXPDIAG_explosionEvents", 0]) + 1;
    private _total = (missionNamespace getVariable ["FST_HC_EXPDIAG_explosionDamageTotal", 0]) + _damage;
    missionNamespace setVariable ["FST_HC_EXPDIAG_explosionEvents", _events];
    missionNamespace setVariable ["FST_HC_EXPDIAG_explosionDamageTotal", _total];

    private _recentLimit = missionNamespace getVariable ["FST_HC_ExplosionDiagRecentLimit", 40];
    private _recent = missionNamespace getVariable ["FST_HC_EXPDIAG_recentExplosions", []];
    _recent pushBack [round diag_tickTime, typeOf _unit, str (side group _unit), _damage, getPosATL _unit];
    while {count _recent > _recentLimit} do {_recent deleteAt 0;};

    private _threshold = missionNamespace getVariable ["FST_HC_ExplosionDiagExplosionSpikeThreshold", 75];
    private _cooldown = missionNamespace getVariable ["FST_HC_ExplosionDiagImmediateCooldown", 5];
    private _last = missionNamespace getVariable ["FST_HC_EXPDIAG_lastImmediateLog", -9999];
    if ((_events >= _threshold) && {(diag_tickTime - _last) >= _cooldown}) then {
        missionNamespace setVariable ["FST_HC_EXPDIAG_lastImmediateLog", diag_tickTime];
        diag_log format [
            "[FST_EXPDIAG][immediate_explosion_spike] machine=%1 time=%2 fps=%3 fpsMin=%4 explosionEvents=%5 explosionDamageTotal=%6 killedUnits=%7 firedTotal=%8 localAI=%9 localGroups=%10 firedAmmo=%11 recentAmmo=%12 recentExplosions=%13 recentDeaths=%14",
            missionNamespace getVariable ["FST_HC_EXPDIAG_machineLabel", "unknown"],
            diag_tickTime,
            diag_fps,
            diag_fpsMin,
            _events,
            _total,
            missionNamespace getVariable ["FST_HC_EXPDIAG_killedUnits", 0],
            missionNamespace getVariable ["FST_HC_EXPDIAG_firedTotal", 0],
            {local _x && {!isPlayer _x}} count allUnits,
            {local leader _x} count allGroups,
            missionNamespace getVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap],
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentAmmo", []],
            _recent,
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentDeaths", []]
        ];
    };
}] call CBA_fnc_addClassEventHandler;

["CAManBase", "killed", {
    params ["_unit", "_killer", "_instigator", "_useEffects"];

    if (isNull _unit) exitWith {};
    if (!local _unit) exitWith {};

    private _killed = (missionNamespace getVariable ["FST_HC_EXPDIAG_killedUnits", 0]) + 1;
    missionNamespace setVariable ["FST_HC_EXPDIAG_killedUnits", _killed];

    private _killerType = if (isNull _killer) then {""} else {typeOf _killer};
    private _instigatorType = if (isNull _instigator) then {""} else {typeOf _instigator};
    private _recentLimit = missionNamespace getVariable ["FST_HC_ExplosionDiagRecentLimit", 40];
    private _recent = missionNamespace getVariable ["FST_HC_EXPDIAG_recentDeaths", []];
    _recent pushBack [round diag_tickTime, typeOf _unit, str (side group _unit), _killerType, _instigatorType, getPosATL _unit];
    while {count _recent > _recentLimit} do {_recent deleteAt 0;};

    private _threshold = missionNamespace getVariable ["FST_HC_ExplosionDiagKilledSpikeThreshold", 20];
    private _cooldown = missionNamespace getVariable ["FST_HC_ExplosionDiagImmediateCooldown", 5];
    private _last = missionNamespace getVariable ["FST_HC_EXPDIAG_lastImmediateLog", -9999];
    if ((_killed >= _threshold) && {(diag_tickTime - _last) >= _cooldown}) then {
        missionNamespace setVariable ["FST_HC_EXPDIAG_lastImmediateLog", diag_tickTime];
        diag_log format [
            "[FST_EXPDIAG][immediate_killed_spike] machine=%1 time=%2 fps=%3 fpsMin=%4 explosionEvents=%5 explosionDamageTotal=%6 killedUnits=%7 firedTotal=%8 localAI=%9 localGroups=%10 firedAmmo=%11 recentAmmo=%12 recentExplosions=%13 recentDeaths=%14",
            missionNamespace getVariable ["FST_HC_EXPDIAG_machineLabel", "unknown"],
            diag_tickTime,
            diag_fps,
            diag_fpsMin,
            missionNamespace getVariable ["FST_HC_EXPDIAG_explosionEvents", 0],
            missionNamespace getVariable ["FST_HC_EXPDIAG_explosionDamageTotal", 0],
            _killed,
            missionNamespace getVariable ["FST_HC_EXPDIAG_firedTotal", 0],
            {local _x && {!isPlayer _x}} count allUnits,
            {local leader _x} count allGroups,
            missionNamespace getVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap],
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentAmmo", []],
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentExplosions", []],
            _recent
        ];
    };
}] call CBA_fnc_addClassEventHandler;

[{
    private _machine = missionNamespace getVariable ["FST_HC_EXPDIAG_machineLabel", "unknown"];
    private _fired = missionNamespace getVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap];
    private _firedTotal = missionNamespace getVariable ["FST_HC_EXPDIAG_firedTotal", 0];
    private _explosionEvents = missionNamespace getVariable ["FST_HC_EXPDIAG_explosionEvents", 0];
    private _explosionDamageTotal = missionNamespace getVariable ["FST_HC_EXPDIAG_explosionDamageTotal", 0];
    private _killed = missionNamespace getVariable ["FST_HC_EXPDIAG_killedUnits", 0];
    private _lowFps = missionNamespace getVariable ["FST_HC_ExplosionDiagLogBelowFPS", 15];

    if ((_explosionEvents > 0) || {_killed > 0} || {_firedTotal > 0} || {diag_fps < _lowFps}) then {
        diag_log format [
            "[FST_EXPDIAG][summary] machine=%1 time=%2 fps=%3 fpsMin=%4 localAI=%5 localGroups=%6 firedTotal=%7 firedAmmo=%8 explosionEvents=%9 explosionDamageTotal=%10 killedUnits=%11 recentAmmo=%12 recentExplosions=%13 recentDeaths=%14",
            _machine,
            diag_tickTime,
            diag_fps,
            diag_fpsMin,
            {local _x && {!isPlayer _x}} count allUnits,
            {local leader _x} count allGroups,
            _firedTotal,
            _fired,
            _explosionEvents,
            _explosionDamageTotal,
            _killed,
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentAmmo", []],
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentExplosions", []],
            missionNamespace getVariable ["FST_HC_EXPDIAG_recentDeaths", []]
        ];
    };

    missionNamespace setVariable ["FST_HC_EXPDIAG_firedAmmo", createHashMap];
    missionNamespace setVariable ["FST_HC_EXPDIAG_firedTotal", 0];
    missionNamespace setVariable ["FST_HC_EXPDIAG_explosionEvents", 0];
    missionNamespace setVariable ["FST_HC_EXPDIAG_explosionDamageTotal", 0];
    missionNamespace setVariable ["FST_HC_EXPDIAG_killedUnits", 0];
    missionNamespace setVariable ["FST_HC_EXPDIAG_recentAmmo", []];
    missionNamespace setVariable ["FST_HC_EXPDIAG_recentExplosions", []];
    missionNamespace setVariable ["FST_HC_EXPDIAG_recentDeaths", []];
}, missionNamespace getVariable ["FST_HC_ExplosionDiagInterval", 10], []] call CBA_fnc_addPerFrameHandler;

diag_log format ["[FST_EXPDIAG][started] machine=%1 interval=%2 explosionSpikeThreshold=%3 killedSpikeThreshold=%4", _machineLabel, missionNamespace getVariable ["FST_HC_ExplosionDiagInterval", 10], missionNamespace getVariable ["FST_HC_ExplosionDiagExplosionSpikeThreshold", 75], missionNamespace getVariable ["FST_HC_ExplosionDiagKilledSpikeThreshold", 20]];
