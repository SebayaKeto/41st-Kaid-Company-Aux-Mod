if (!(isServer || {!hasInterface})) exitWith {};
if (missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidStarted", false]) exitWith {};
missionNamespace setVariable ["FST_HC_EmergencyDroidBandaidStarted", true];

if !(missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", true]) exitWith {
    diag_log "[FST_HCSpawn][EMERGENCY] Droid bandaid disabled";
};

if (missionNamespace getVariable ["FST_HC_EmergencyMuteSentences", true]) then {
    enableSentences false;
};

missionNamespace setVariable ["FST_HC_EmergencyDeadQueue", []];
missionNamespace setVariable ["FST_HC_EmergencyKillTimes", []];

["CAManBase", "InitPost", {
    params ["_unit"];
    if (!isNull _unit && {local _unit}) then {
        [_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid;
    };
}] call CBA_fnc_addClassEventHandler;

["CAManBase", "Killed", {
    params ["_unit", "_killer", "_instigator", "_useEffects"];
    if (isNull _unit) exitWith {};
    if !(local _unit) exitWith {};
    if !([_unit] call FST_HCSpawn_fnc_emergencyStabilizeDroid) exitWith {};

    private _killTimes = missionNamespace getVariable ["FST_HC_EmergencyKillTimes", []];
    _killTimes pushBack diag_tickTime;
    private _window = missionNamespace getVariable ["FST_HC_EmergencyKillWindow", 10];
    private _cutoff = diag_tickTime - _window;
    _killTimes = _killTimes select {_x >= _cutoff};
    missionNamespace setVariable ["FST_HC_EmergencyKillTimes", _killTimes];

    _unit setVariable ["FST_HC_EmergencyQueuedDeathTime", diag_tickTime, false];
    _unit hideObject true;
    _unit enableSimulation false;

    private _queue = missionNamespace getVariable ["FST_HC_EmergencyDeadQueue", []];
    _queue pushBackUnique _unit;
    missionNamespace setVariable ["FST_HC_EmergencyDeadQueue", _queue];

    if ((count _killTimes) >= (missionNamespace getVariable ["FST_HC_EmergencyKillSpikeThreshold", 12])) then {
        diag_log format ["[FST_HCSpawn][EMERGENCY][kill_storm] machine=%1 time=%2 recentDroidKills=%3 localAI=%4 localGroups=%5 fps=%6 fpsMin=%7", profileName, diag_tickTime, count _killTimes, {local _x && {!isPlayer _x}} count allUnits, {local leader _x} count allGroups, diag_fps, diag_fpsMin];
    };
}] call CBA_fnc_addClassEventHandler;

[{
    if !(missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", true]) exitWith {};
    private _maxScan = missionNamespace getVariable ["FST_HC_EmergencyDroidScanMaxPerPass", 250];
    private _done = 0;
    {
        if (_done >= _maxScan) exitWith {};
        if (local _x && {!isPlayer _x} && {alive _x}) then {
            if ([_x] call FST_HCSpawn_fnc_emergencyStabilizeDroid) then {
                _done = _done + 1;
            };
        };
    } forEach allUnits;
}, missionNamespace getVariable ["FST_HC_EmergencyDroidScanInterval", 1.5], []] call CBA_fnc_addPerFrameHandler;

[{
    if !(missionNamespace getVariable ["FST_HC_EmergencyDroidBandaidEnabled", true]) exitWith {};
    private _queue = missionNamespace getVariable ["FST_HC_EmergencyDeadQueue", []];
    if (_queue isEqualTo []) exitWith {};
    private _maxDelete = missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteMaxPerPass", 20];
    private _delay = missionNamespace getVariable ["FST_HC_EmergencyDeadDeleteDelay", 0.25];
    private _now = diag_tickTime;
    private _keep = [];
    private _deleted = 0;

    {
        if (!isNull _x) then {
            if (alive _x) then {
                _keep pushBack _x;
            } else {
                private _deathTime = _x getVariable ["FST_HC_EmergencyQueuedDeathTime", _now];
                if ((_now - _deathTime) >= _delay && {_deleted < _maxDelete}) then {
                    _x setVariable ["FST_skipSpawnDamage", true, true];
                    deleteVehicle _x;
                    _deleted = _deleted + 1;
                } else {
                    _keep pushBack _x;
                };
            };
        };
    } forEach _queue;

    missionNamespace setVariable ["FST_HC_EmergencyDeadQueue", _keep];
}, 0.25, []] call CBA_fnc_addPerFrameHandler;

diag_log format ["[FST_HCSpawn][EMERGENCY] V25 droid bandaid active on %1. HC AI stays enabled. AI radio sentences muted on server/HC=%2. Immediate droid stabilization + fast dead droid deletion enabled.", profileName, missionNamespace getVariable ["FST_HC_EmergencyMuteSentences", true]];
