// FST_HCSpawn_fnc_initDroidCorpseCleanup
// Server/HC-local. Added 2026-08-08 after disabling the emergency droid
// bandaid's instant hideObject/fast-delete (see fn_initEmergencyDroidBandaid.sqf):
// with that off, NOTHING else in this addon deletes dead droid bodies while
// players remain engaged -- fn_cleanupDeadGroups.sqf only deletes empty group
// containers, and fn_cleanupGroups.sqf only sweeps a group (alive or dead
// members) once it has gone fully stale (no ground players nearby for
// FST_HC_DespawnTimer, default 600s) -- so corpses from a sustained firefight
// were accumulating unbounded for as long as players stayed in the area.
// This gave the reported lag after that change.
//
// This is intentionally decoupled from the emergency bandaid: it never hides
// or freezes a corpse the instant it dies. A dead droid plays out its death
// normally and stays visible. Only after a real delay does it (a) stop being
// simulated (kills ongoing ragdoll/physics cost, still visible as a static
// body) and (b) get deleted (bounds total corpse count during long fights).

if (!(isServer || {!hasInterface})) exitWith {};
if (missionNamespace getVariable ["FST_HC_DroidCorpseCleanupStarted", false]) exitWith {};
missionNamespace setVariable ["FST_HC_DroidCorpseCleanupStarted", true];

missionNamespace setVariable ["FST_HC_DroidCorpseQueue", []];

["CAManBase", "Killed", {
    params ["_unit"];
    if (isNull _unit) exitWith {};
    if !(local _unit) exitWith {};
    if !(missionNamespace getVariable ["FST_HC_DroidCorpseCleanupEnabled", true]) exitWith {};
    // Pure classifier, NOT fn_emergencyStabilizeDroid: that function returns
    // false whenever the (now default-off) bandaid setting is disabled, which
    // would silently turn this whole sweeper into dead code.
    if !([_unit] call FST_HCSpawn_fnc_isDroidUnit) exitWith {};

    _unit setVariable ["FST_HC_CorpseDeathTime", diag_tickTime, false];

    private _queue = missionNamespace getVariable ["FST_HC_DroidCorpseQueue", []];
    _queue pushBackUnique _unit;
    missionNamespace setVariable ["FST_HC_DroidCorpseQueue", _queue];
}] call CBA_fnc_addClassEventHandler;

[{
    if !(missionNamespace getVariable ["FST_HC_DroidCorpseCleanupEnabled", true]) exitWith {};

    private _queue = missionNamespace getVariable ["FST_HC_DroidCorpseQueue", []];
    if (_queue isEqualTo []) exitWith {};

    private _simOffDelay = missionNamespace getVariable ["FST_HC_DroidCorpseSimOffDelay", 8];
    private _deleteDelay = missionNamespace getVariable ["FST_HC_DroidCorpseDeleteDelay", 25];
    private _maxDelete = missionNamespace getVariable ["FST_HC_DroidCorpseDeleteMaxPerPass", 10];
    private _now = diag_tickTime;
    private _keep = [];
    private _deleted = 0;

    {
        // isNull or alive again (e.g. a respawn edge case) -- drop from the queue.
        // If it dies again, the Killed handler re-adds it fresh.
        if (isNull _x || {alive _x}) then { continue };

        private _deathTime = _x getVariable ["FST_HC_CorpseDeathTime", _now];
        private _age = _now - _deathTime;

        if (_age >= _deleteDelay && {_deleted < _maxDelete}) then {
            _x setVariable ["FST_skipSpawnDamage", true, true];
            deleteVehicle _x;
            _deleted = _deleted + 1;
        } else {
            if (_age >= _simOffDelay && {simulationEnabled _x}) then {
                _x enableSimulation false;
            };
            _keep pushBack _x;
        };
    } forEach _queue;

    missionNamespace setVariable ["FST_HC_DroidCorpseQueue", _keep];
}, 1, []] call CBA_fnc_addPerFrameHandler;

diag_log format ["[FST_HCSpawn] Droid corpse cleanup active on %1 (sim-off=%2s, delete=%3s).", profileName,
    missionNamespace getVariable ["FST_HC_DroidCorpseSimOffDelay", 8],
    missionNamespace getVariable ["FST_HC_DroidCorpseDeleteDelay", 25]];
