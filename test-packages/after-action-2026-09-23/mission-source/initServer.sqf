setMissionOptions createHashMapFromArray [["AIThinkOnlyLocal", true]];

private _val = getMissionOptions get "AIThinkOnlyLocal";
diag_log format ["[CHECK] AIThinkOnlyLocal = %1", _val];

missionNamespace setVariable ["fnc_serverSpawnVehicle", {
    params ["_className", "_pos", "_dir", "_storeKey"];
    private _vehicle = _className createVehicle _pos;
    _vehicle setDir _dir;
    _vehicle setPosATL _pos;
    // Broadcast the vehicle reference to all clients so pad tracking stays in sync
    missionNamespace setVariable [_storeKey, _vehicle, true];
}];

// ===== KAID Umbara V4.1: auto-run the environment block once the mission is up (same as Server Exec, no Zeus action needed) =====
// Re-running it later from Server Exec ([] execVM "KAID_UmbaraV41.sqf";) is safe: it replaces its own JIP message and the guard/audio loops restart.
[] spawn {
    sleep 15;
    if !(missionNamespace getVariable ["KAID_UmbaraV41_AutoRan", false]) then {
        missionNamespace setVariable ["KAID_UmbaraV41_AutoRan", true];
        diag_log "KAID: auto-running KAID_UmbaraV41.sqf from initServer";
        [] execVM "KAID_UmbaraV41.sqf";
    };
};

// Enroll idle foot AI; active QRF/BURNS groups and vehicles stay awake.
[] execVM "KAID_DynamicSimulation.sqf";

// Isolated Daara candidate bootstrap.
call compile preprocessFileLineNumbers "DI\bootstrap.sqf";
