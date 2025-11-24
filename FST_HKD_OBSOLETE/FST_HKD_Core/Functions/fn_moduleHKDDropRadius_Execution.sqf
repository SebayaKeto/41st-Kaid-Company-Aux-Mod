params ["_logic", "_classList"];


// Retrieve settings from Module Attributes (fallback to CBA settings)
private _count = _logic getVariable ["Drop_Count", missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropcount", 10]];
private _radius = _logic getVariable ["Drop_Radius", missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropradius", 100]];
private _altitude = _logic getVariable ["Drop_Altitude", missionNamespace getVariable ["cba_settings_fst_hkd_defaultdropaltitude", 1000]];
private _randomDir = _logic getVariable ["Random_Dir", true];
private _compassDir = _logic getVariable ["Compass_Dir", 0];
private _useThrusters = _logic getVariable ["Enable_Thrusters", true];

// Validate incoming class list and filter invalid entries
private _validClassList = [];
private _invalidClassList = [];
{
    if ((configFile >> "CfgVehicles" >> _x) isNotEqualTo "") then { _validClassList pushBack _x; } else { _invalidClassList pushBack _x; };
} forEach _classList;

if ((count _validClassList) == 0) then {
    hint "HKD Drop (Radius): No valid droppable classes provided — aborting drop.";
    deleteVehicle _logic;
    exitWith {};
};

if ((count _invalidClassList) > 0) then {
    hint format ["HKD Drop (Radius): %1 invalid classname(s) ignored: %2", count _invalidClassList, _invalidClassList];
};

private _centerPos = getPos _logic;

// Instead of shipping the full queue to the server, send a small seed + valid class list
private _validClassListForServer = _validClassList;
private _seed = floor (random 1000000000);

// Determine the activating player (should be the client that opened the dialog). If _units were passed use them, otherwise assume local 'player'.
private _activator = player;
if (!isNil "_logic") then {
    // try to find a player associated with the module via missionNamespace variable set earlier
    private _maybe = missionNamespace getVariable ['HKD_Current_Drop_Module_Activator', objNull];
    if (!isNull _maybe && isPlayer _maybe) then { _activator = _maybe; };
};

// Determine batching strategy to spread load (can be tuned via CBA settings)
private _cba_batch = missionNamespace getVariable ["cba_settings_fst_hkd_spawnbatchsize", 0];
private _cba_sleep = missionNamespace getVariable ["cba_settings_fst_hkd_spawnsleepinterval", 0.15];

private _batchSize = 1;
if (_cba_batch > 0) then { _batchSize = _cba_batch; } else {
    if (_count > 80) then { _batchSize = 6; } else { if (_count > 40) then { _batchSize = 4; } else { if (_count > 20) then { _batchSize = 2; } } };
};
private _sleepBetweenBatches = _cba_sleep; // seconds

// Hand off heavy spawning to the server to keep client performance stable
private _totalToSpawn = _count;
// Store current module so client-side Cancel can refer to it (broadcast)
missionNamespace setVariable ['HKD_Current_Drop_Module', _logic, true];

// RemoteExec the server-side execution (server function will drive spawning and update the initiating client)
[_logic, _validClassListForServer, _seed, _batchSize, _sleepBetweenBatches, _centerPos, _altitude, _radius, _randomDir, _compassDir, _useThrusters, _totalToSpawn, _activator] remoteExecCall ["HKD_fnc_serverHKDDropExecution", 2];

// Client will receive updates via remoteExec calls from the server; this script's job is done
exitWith {};